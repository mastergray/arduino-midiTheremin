/**
 *
 *  Trigger.cpp - Library for creating objects that can read input from a range finder
 *
 */

#include "Arduino.h"
#include "Trigger.h"

  int echoPin; // Echo pin of range finder
  int trigPin; // Trigger pin of range finder 
	
  //  CONSTRUCTOR  //
  Trigger::Trigger(int echo, int trig) {
    
    //  Intialize instance variables:
    echoPin = echo;
    trigPin = trig;
    
    //  Set pin modes:
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  
  }
  
  // Returns distance from range finder:
  int Trigger::getDistance() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
   
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
   
    digitalWrite(trigPin, LOW);
    
    return pulseIn(echoPin, HIGH) / 58.2;    

  }

  // Returns boolean for if distance detected is within a specified range
  bool Trigger::inRange(int min, int max) {

   int distance = getDistance();
   
	return distance >= min && distance <= max;

  }  


