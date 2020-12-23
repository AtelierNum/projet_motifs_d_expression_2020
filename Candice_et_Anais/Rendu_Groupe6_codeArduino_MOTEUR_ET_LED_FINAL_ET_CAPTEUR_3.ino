#include <Servo.h>
#include <Arduino.h>
#include "ServoEasing.h"

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
ServoEasing myservo1;
ServoEasing myservo2;
ServoEasing myservo3;

// inclure la bibliothèque fast-led
#include <FastLED.h>
#define NUM_LEDS 12 // définir le nombre de leds

CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.
float  inc = 0; // un variable que l'on va utiliser pour créer une animation.

void setup() {
  pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
 pinMode(11, OUTPUT);
 pinMode(12, OUTPUT);
  myservo1.attach(6); // préciser à notre bibliothèque qu'un servo est connecté à la pin 6
  myservo2.attach(12);
  myservo3.attach(11);

  // on initialise notre strip de led sur la pin 3
  FastLED.addLeds<NEOPIXEL, 3>(leds, NUM_LEDS);

  Serial.begin(9600); // ouvrir la connexion série
  pinMode(3, OUTPUT); // préciser que la pin 7 va être utilisée comme une entrée
  pinMode(2, INPUT);
}

void loop() {


  int value = digitalRead(2); // lire la valeur sur la pin 7 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série




  if (value == 1) {
    //myservo1.attach(6); // préciser à notre bibliothèque qu'un servo est connecté à la pin 6
    //myservo2.attach(12);
    //myservo3.attach(11);

    for (int i = 0; i < NUM_LEDS; i++) {
      // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
      leds[i] = CRGB(0, 150, 100);

    }
    FastLED.show();



    myservo1.write(110);


    myservo2.setEasingType(EASE_CIRCULAR_OUT);
    myservo3.setEasingType(EASE_CIRCULAR_OUT);
    myservo2.startEaseTo(0, 25, true);
    myservo3.startEaseTo(0, 25, true);



    delay(1500);


    myservo2.setEasingType(EASE_CIRCULAR_OUT);
    myservo3.setEasingType(EASE_CIRCULAR_OUT);
    myservo2.startEaseTo(180, 25, true);
    myservo3.startEaseTo(180, 25, true);
  delay(1500);


  }
  else {
   // myservo2.detach();
    //myservo3.detach();
    myservo1.detach();
    for (int i = 0; i < NUM_LEDS; i++) {
      // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
      leds[i] = CRGB(0, 0 , 0);

    }
    FastLED.show(); // on actualise le ruban de led


  }


}
