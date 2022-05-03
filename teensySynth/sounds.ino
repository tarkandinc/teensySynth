#include "sounds.h"
#include "teensySynth.h"

struct sound sounds[NUMBER_OF_SOUNDS]  = { {SOUND_OFF, 0, 0},
                                           {SOUND_OFF, 0, 0},
                                           {SOUND_OFF, 0, 0},
                                           {SOUND_OFF, 0, 0},
                                           {SOUND_OFF, 0, 0} };

void checkDecaySounds(void)
{
  byte soundNo;
  for (soundNo=0; soundNo<NUMBER_OF_SOUNDS; soundNo++)
  {
#ifdef PRINT_MIDI_MESSAGES
      Serial.print("Sound ");
      Serial.print(soundNo, DEC);
      Serial.print(" ");
      Serial.print(sounds[soundNo].stat, DEC);
      Serial.print(" ");
      Serial.println(envelopes[soundNo].isActive(), DEC);
#endif
    if(/*sounds[soundNo].stat==SOUND_RELEASE &&*/ envelopes[soundNo].isActive()==false)
    {
      sounds[soundNo].stat = SOUND_OFF;
#ifdef PRINT_MIDI_MESSAGES
      Serial.print("Sound turned off ");
      Serial.println(soundNo, DEC);    
#endif
    }
  }
}

byte findFreeSound(void)
{
  byte soundNo;
  checkDecaySounds();
  for (soundNo=0; soundNo<NUMBER_OF_SOUNDS; soundNo++)
    if(sounds[soundNo].stat == SOUND_OFF)
      break;
  if(sounds[soundNo].stat == SOUND_OFF)
    return soundNo;
  else
    return -1;
}

void assignPlayingSound(byte note, byte channel, byte soundNo)
{
  sounds[soundNo].stat = SOUND_ON;
  sounds[soundNo].note = note;
  sounds[soundNo].channel = channel;
}

byte findPlayingSound(byte note, byte channel)
{
  byte soundNo = 0;
  for (soundNo=0; soundNo<NUMBER_OF_SOUNDS; soundNo++)
    if(sounds[soundNo].note == note && sounds[soundNo].channel == channel)
      break;
    if(sounds[soundNo].note == note && sounds[soundNo].channel == channel)
      return soundNo;
    else
      return -1;
}

void stopSound(byte soundNo)
{
  sounds[soundNo].stat = SOUND_RELEASE;
  //sounds[soundNo].stat = SOUND_OFF;
  sounds[soundNo].note = 0;
  sounds[soundNo].channel = 0;
}
