#include <Arduino.h>

#define SENSITIVITY 100

// IR PIN LEFT TO RIGHT
#define IR0 PIN_PF0
#define IR1 PIN_PF1
#define IR2 PIN_PF2
#define IR3 PIN_PF3
#define IR4 PIN_PF4
#define IR5 PIN_PF5
#define IR6 PIN_PF6
#define IR7 PIN_PF7
#define IR8 PIN_PK0
#define IR9 PIN_PK1

#define FAN PIN_PB4

// MX1208
#define MOTOR_L_A PIN_PH3
#define MOTOR_L_B PIN_PH4
#define MOTOR_R_A PIN_PH5
#define MOTOR_R_B PIN_PH6

// LEDS BOTTOM
#define LEDS PIN_PK2

#define BUTTON PIN_PK3

// 

bool run = false;

void setup() {
  pinMode(PIN_PA3, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(FAN, OUTPUT);

  pinMode(LEDS, OUTPUT);
  
  pinMode(MOTOR_L_A, OUTPUT);
  pinMode(MOTOR_L_B, OUTPUT);
  pinMode(MOTOR_R_A, OUTPUT);
  pinMode(MOTOR_R_B, OUTPUT);
  analogWrite(MOTOR_L_A, 0);
  analogWrite(MOTOR_L_B, 0);
  analogWrite(MOTOR_R_A, 0);
  analogWrite(MOTOR_R_B, 0);
  
  digitalWrite(LEDS, HIGH);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
}

void loop() {
  if (digitalRead(BUTTON)) {
    delay(300);
    run = !run;
  }
  if (run) {
    // analogWrite(FAN, 10);
    int ir4 = analogRead(IR4);
    if (ir4 < SENSITIVITY) {
      analogWrite(MOTOR_L_B, 255);
    } else {
      analogWrite(MOTOR_L_B, 0);
    }
    int ir5 = analogRead(IR5);
    if (ir5 < SENSITIVITY) {
      analogWrite(MOTOR_R_A, 255);
    } else {
      analogWrite(MOTOR_R_A, 0);
    }
  } else {
    analogWrite(FAN, 0);
  }

}