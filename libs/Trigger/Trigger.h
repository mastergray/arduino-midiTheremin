/**
 *
 *  Trigger.h - Library for creating objects that can read input from a range finder
 *
 */

#ifndef Trigger_h
#define Trigger_h

#include "Arduino.h"

class Trigger {

  public:
	Trigger(int echo, int trig);
	int getDistance();
	bool inRange(int min, int max);
  private:
  	int echoPin; 
  	int trigPin;
};

#endif
