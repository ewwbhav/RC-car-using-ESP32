#include <Arduino.h>

// ✅ FS-iA6 Receiver Signal Pins
#define CH1_PIN 32  // Steering input
#define CH2_PIN 33  // Throttle input

// ✅ BTS7960 Motor Driver Pins
#define LPWM_L 18  // Left Forward
#define RPWM_L 19  // Left Reverse
#define L_EN 23    // Left Enable

#define LPWM_R 21  // Right Forward
#define RPWM_R 22  // Right Reverse
#define R_EN 25    // Right Enable

// ✅ RC Signal Definitions
#define SIGNAL_CENTER 1500
#define SIGNAL_MIN 1000
#define SIGNAL_MAX 2000
#define DEAD_ZONE 50

// ✅ Steering sensitivity multiplier
#define STEERING_GAIN 1.5  // Increase to make turning sharper

void setup() {
    Serial.begin(115200);

    // Setup receiver inputs
    pinMode(CH1_PIN, INPUT);
    pinMode(CH2_PIN, INPUT);

    // Setup motor driver enables
    pinMode(L_EN, OUTPUT);
    pinMode(R_EN, OUTPUT);
    digitalWrite(L_EN, HIGH);
    digitalWrite(R_EN, HIGH);

    // Setup motor PWM pins
    pinMode(LPWM_L, OUTPUT);
    pinMode(RPWM_L, OUTPUT);
    pinMode(LPWM_R, OUTPUT);
    pinMode(RPWM_R, OUTPUT);
}

void loop() {
    // ✅ Read throttle and steering PWM signals
    int ch1 = pulseIn(CH1_PIN, HIGH, 25000); // Steering
    int ch2 = pulseIn(CH2_PIN, HIGH, 25000); // Throttle

    Serial.print("Throttle: ");
    Serial.print(ch2);
    Serial.print(" | Steering: ");
    Serial.println(ch1);

    // ✅ Convert to signed values around center
    int throttle = ch2 - SIGNAL_CENTER;
    int steering = (ch1 - SIGNAL_CENTER) * STEERING_GAIN;

    // ✅ Apply dead zone
    if (abs(throttle) < DEAD_ZONE) throttle = 0;
    if (abs(steering) < DEAD_ZONE) steering = 0;

    // ✅ Tank drive calculation
    int leftMotor = throttle + steering;
    int rightMotor = throttle - steering;

    // ✅ Limit motor values to range
    leftMotor = constrain(leftMotor, -500, 500);
    rightMotor = constrain(rightMotor, -500, 500);

    // ✅ Convert to PWM values (0–255)
    int leftPWM = map(abs(leftMotor), 0, 500, 0, 255);
    int rightPWM = map(abs(rightMotor), 0, 500, 0, 255);

    // ✅ Left Motor Control
    if (leftMotor > 0) {
        analogWrite(LPWM_L, leftPWM);
        analogWrite(RPWM_L, 0);
    } else if (leftMotor < 0) {
        analogWrite(LPWM_L, 0);
        analogWrite(RPWM_L, leftPWM);
    } else {
        analogWrite(LPWM_L, 0);
        analogWrite(RPWM_L, 0);
    }

    // ✅ Right Motor Control
    if (rightMotor > 0) {
        analogWrite(LPWM_R, rightPWM);
        analogWrite(RPWM_R, 0);
    } else if (rightMotor < 0) {
        analogWrite(LPWM_R, 0);
        analogWrite(RPWM_R, rightPWM);
    } else {
        analogWrite(LPWM_R, 0);
        analogWrite(RPWM_R, 0);
    }

    delay(10); // Small delay for stability
}
