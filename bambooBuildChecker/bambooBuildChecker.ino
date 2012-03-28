#include "pitches.h"

int successPin = 8;
int buildingPin = 9;
int failPin = 10;
int tonePin = 12;
int val;
boolean building = false;
int buildingState = LOW;
long previousMillis = 0;
long interval = 1000;


void setup()
{
 pinMode(successPin, OUTPUT); // sets the digital pin as output
 pinMode(buildingPin, OUTPUT); // sets the digital pin as output
 pinMode(failPin, OUTPUT); // sets the digital pin as output
 Serial.begin(9600);
 Serial.flush();
}

void loop()
{
  unsigned long currentMillis = millis();
  if (Serial.available())
  {
    val = Serial.read();
    if (val == 110) {  // n = 110 in dec
      building = 1;
      allOff();
    }
    else if (val == 109) {  //109 = m in dec
      building = 0;
      
      fail(); 
    }
    else if (val == 108) { 
      building = 0;
      succeed();     
    }
    else {
      building = 0;
      allOff();
      noTone(12);      
    } 
  }
  
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    Serial.write(building);
    if (building) {
      if (buildingState == LOW) {
        buildingState = HIGH; 
      }
      else {
        buildingState = LOW;
      }
      digitalWrite(buildingPin, buildingState);
    }
    else {
      building = 0;
    }      
  }
  
}

void fail() {
  digitalWrite(buildingPin, LOW);
  digitalWrite(successPin, LOW);
  digitalWrite(failPin, HIGH);
  tone(tonePin, NOTE_C2, 1000);
  delay(300);
  tone(tonePin, NOTE_C1
  , 1000);
}

void succeed() {
  digitalWrite(buildingPin, LOW);
  digitalWrite(successPin, HIGH);
  digitalWrite(failPin, LOW);   
}

void allOff() {
  digitalWrite(buildingPin, LOW);
  digitalWrite(successPin, LOW);
  digitalWrite(failPin, LOW);   
}
