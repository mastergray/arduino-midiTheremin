/**
 *
 *  MidiInterface.cpp - Library for sending MIDI data with Arduino
 *
 */

#include "Arduino.h"
#include "MidiInterface.h"

   int channel; // Channel this interface has access to (1 - 16)
  
   //	CONSTRUCTOR	//
   MidiInterface::MidiInterface(int channelValue) {
     
     channel = channelValue;
    
   }
   
   //  Configures serial port for MIDI - MUST be invoked in setup();
    void MidiInterface::init() {
     
    Serial.begin(31250);
     
   }
   
   //  Returns 'note on' value for set channel:
   int MidiInterface::getNoteOn() {
      
     return 144 + channel - 1;
   
   }
   
  //  Returns 'note off' value for set channel:
  int MidiInterface::getNoteOff() {
    
    return 128 + channel - 1;
  
  }
  
  // Returns 'control/mode change' value for set channel:
  int MidiInterface::getControlChange() {
    
    return 176 + channel - 1;
  
  }
  
  
  //  'Note On' message for given note value (21 - 108) with a given velocity (0 - 127);
  void MidiInterface::noteOn(int noteValue, int velocity) {
  
     Serial.write(getNoteOn());
     Serial.write(noteValue);
     Serial.write(velocity);
  
  }
  
  //  'Note Off' message for given note value (21 - 108) with a given velocity (0 - 127);
  void MidiInterface::noteOff(int noteValue, int velocity) {
  
     Serial.write(getNoteOff());
     Serial.write(noteValue);
     Serial.write(velocity);
  
  }
  
  // "Control change" message for given parameters:
  void MidiInterface::controlChange(int param1, int param2) {
    
    Serial.write(getControlChange());
    Serial.write(param1);
    Serial.write(param2);
    
  }
  
  //  Sends message to turn all notes off for set channel:
  void MidiInterface::stopNote() {
    
    controlChange(123, 0);
    
  }

  // Sends any three byte MIDI message:
  void MidiInterface::sendMessage(int byte1, int byte2, int byte3) {

    Serial.write(byte1);
    Serial.write(byte2);
    Serial.write(byte3);
    

  }

