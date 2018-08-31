#include <Arduino.h>
#include <stdint.h>

//lol we need to change these
int clockPin = 2;
int dataPin = 3;
int latchPin = 4;
int blPin = 5;
int ledPin = 6;
uint64_t data;
int d = 2000;

void writeData(uint64_t data) {
  //data = data | PAD00;
  //data = ~data;
  for (int i=0; i<d; ++i) {
    data = ~data;
    char* arr = (char*) &data;
    digitalWrite(latchPin, LOW);
    for (int i=0; i < 8; ++i) {
      char c = arr[i];
      shiftOut(dataPin, clockPin, LSBFIRST, c); 
    }
    digitalWrite(latchPin, HIGH);
    delay(1);
  }
}

void waveFor(int msec) {
  /*bool b = 1;
  for (int i=0; i<msec; ++i) {
    digitalWrite(polPin, b);
    delay(1);
    b = !b;
    }*/
  digitalWrite(blPin, HIGH);
  delay(msec);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(blPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(blPin, HIGH);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  
}
