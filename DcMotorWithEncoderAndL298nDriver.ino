#include "Arduino.h"
#define Encoder_output_A 34  // pin2 of the Arduino
#define Encoder_output_B 35  // pin 3 of the Arduino
#define in1 25
#define in2 26

float Count_pulses = 0;
void setup() {
  Serial.begin(9600);                // activates the serial communication
  pinMode(Encoder_output_A, INPUT);  // sets the Encoder_output_A pin as the input
  pinMode(Encoder_output_B, INPUT);  // sets the Encoder_output_B pin as the input
  attachInterrupt(digitalPinToInterrupt(Encoder_output_A), DC_Motor_Encoder, RISING);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  
  if (Count_pulses > 360) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else if (Count_pulses < 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  Serial.print("Result: ");
  Serial.println(Count_pulses);
  delay(1);
}

void DC_Motor_Encoder() {
  int b = digitalRead(Encoder_output_B);
  if (b > 0) {
    Count_pulses+= 3.6;
  } else {
    Count_pulses-= 3.6;
  }
}