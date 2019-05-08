#include <Arduino.h>
#include <stdint.h>

int dataPin = 2; // DIOA
int blPin = 3; // BL
int polPin = 4; // POL
int dirPin = 6; // DIR
int clockPin = 5; // CLK
int latchPin = 7; // LE

uint64_t one = 1;
uint64_t data;
int d = 2000;

void writeData(uint64_t data) {
  char* arr = (char*) &data;
  digitalWrite(latchPin, LOW);
  for (int i=0; i < 8; ++i) {
    char c = arr[i];
    shiftOut(dataPin, clockPin, LSBFIRST, c); 
  }
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(blPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(polPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(blPin, LOW);
  digitalWrite(polPin, LOW); // INVERTING ALL OUTPUT
  digitalWrite(clockPin, LOW);
  digitalWrite(dataPin, LOW);
  digitalWrite(latchPin, HIGH);
  digitalWrite(dirPin, LOW);
  delay(1000);
  digitalWrite(blPin, HIGH);
}

int delayTime = 250;
void loop() {
  writeData(one<<43);
  delay(delayTime);
  writeData(one<<42);
  delay(delayTime);
  writeData(one<<41);
  delay(delayTime);
  writeData(one<<40);
  delay(delayTime);
  writeData(one<<41);
  delay(delayTime);
  writeData(one<<42);
  delay(delayTime);
}
