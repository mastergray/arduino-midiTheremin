/**
 *
 *  MidiInterface.h - Library for sending MIDI data with Arduino
 *
 */

#ifndef MidiInterface_h
#define MidiInterface_h

#include "Arduino.h"

class MidiInterface {

  public:
	MidiInterface(int channelValue);
	static void init();
	int getControlChange();
	void noteOn(int noteValue, int velocity);
	void noteOff(int noteValue, int velocity);
	void controlChange(int param1, int param2);
	void stopNote();
	void sendMessage(int byte1, int byte2, int byte3);
  private:
  	int channel; 
	int getNoteOff();
	int getNoteOn();
};

#endif
