#ifndef SOUNDS_H
#define SOUNDS_H

enum soundStatus
{
  SOUND_OFF,
  SOUND_ON,
  SOUND_SUSTAIN,
  SOUND_DECAY
};

struct sound
{
  byte stat;
  byte note;
  byte channel;
};

extern struct sound sounds[NUMBER_OF_SOUNDS];

byte findFreeSound(void);
void assignPlayingSound(byte note, byte channel, byte soundNo);
byte findPlayingSound(byte note, byte channel);
void stopSound(byte soundNo);

 #endif
