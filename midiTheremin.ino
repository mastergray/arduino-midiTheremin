#include <MidiInterface.h>
#include <Trigger.h>

int MIN = 0;
int MAX = 50;
int NOTE;
int octave = 0;
int sustainPin = 6;
int timePin = 0;


int note_sequence[] = {25,26,27,28,29,30,31,32, 33, 34, 35, 36,37}; 

// Synth controllers:
Trigger trig1(7, 8); // Selects note;
Trigger trig2(5, 4); // Sets octave of note

MidiInterface MIDI_synth(1); // MIDI synth data sending to channel 1

//  Sets octave from trig2:
void setOctave() {

  if (trig2.inRange(MIN, MAX)) {
  
   octave = map(trig2.getDistance(), MIN, MAX, 0, 6);
  
  }

}

boolean checkSustain() {

  if (digitalRead(sustainPin) == HIGH) {
  
    return true;
  
  }
  
  return false;

}


void setup() {

 Serial.begin(31250);
 pinMode(sustainPin, INPUT);
 pinMode(timePin,INPUT);

}


void loop() {

    delay(map(analogRead(timePin), 0, 1023, 0, 500));
      
       if (!checkSustain()) {
         
          MIDI_synth.stopNote();
        
        }  
      
     // Sets NOTE to play:
      if (trig1.inRange(MIN, MAX)) {
        
        setOctave(); 
        NOTE = map(trig1.getDistance(), MIN, MAX, 0, 11);   
        MIDI_synth.noteOn(note_sequence[NOTE] + (octave * 12), 127);
        
         
      } 
 
    

}
