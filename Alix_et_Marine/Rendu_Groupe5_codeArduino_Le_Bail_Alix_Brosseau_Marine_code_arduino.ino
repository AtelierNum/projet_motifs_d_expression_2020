#include <Arduino.h>

#include "ServoEasing.h"


#include <Servo.h> // sans capteur
ServoEasing rota; // sans capteur




#include "Ultrasonic.h" // capteur 2
Ultrasonic ultrasonic(9); // capteur 2


void setup() {
  Serial.begin(9600);

  pinMode(6, OUTPUT);  // sans capteur
  rota.attach(6); // sans capteur

}


void loop() {
  
 rota.setSpeed(100);  // capteur 2
    rota.setEasingType(EASE_BOUNCE_OUT);// capteur 2

  long RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // capteur 2
  // int value = digitalRead(9);
  Serial.println(RangeInCentimeters);//capteur 2

  if (RangeInCentimeters < 80) { // capteur 2
    rota.easeTo(0); // capteur 2
   // delay(1000); // capteur 2
  }

  else {
    rota.easeTo(70); // capteur 2
    //delay(2000); // capteur 2

   // delay(100); // capteur 2
  }

}
