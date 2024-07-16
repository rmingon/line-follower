#include <Arduino.h>

#define SENSITIVITY 254

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
#define MOTOR_R_B PIN_PH5
#define MOTOR_R_B PIN_PH6

// LEDS BOTTOM
#define LEDS PIN_PK2

// 

void setup() {
  pinMode(PIN_PA3, OUTPUT);
  pinMode(PIN_PF1, INPUT);
}

void loop() {
  int value = analogRead(PIN_PF1);
  if (value < SENSITIVITY) {
    digitalWrite(PIN_PA3, LOW);
  } else {
    digitalWrite(PIN_PA3, HIGH);
  }
}