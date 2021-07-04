#include "audioDesign.h"

#define CHORUS_BLOCK_SAMPLE 1024
#define FLANGE_BLOCK_SAMPLE 1024

short chorusBuffer[CHORUS_BLOCK_SAMPLE];
short flangeBuffer[FLANGE_BLOCK_SAMPLE];

static void setupMixers(void)
{
  //mixing mixers
  for(int i=0; i<2; i++)
    for(int j=0; j<4; j++)
      finalMixers[i].gain(j, 1);
  //sound mixers, wave or synth
  for(int i=0; i<5; i++)
    for(int j=0; j<4; j++)
      mixers[i].gain(j, 0);
  //default wavetables only
  /*for(int i=0; i<5; i++)
    mixers[i].gain(0, 1);*/
}

void initAudioFunctions(void)
{
  setupMixers();
  amp1.gain(1);
  //envelopes left at default default values
  chorus1.begin(chorusBuffer, CHORUS_BLOCK_SAMPLE,1);
  flange1.begin(flangeBuffer, FLANGE_BLOCK_SAMPLE, 0, 0, 0);
  reverb1.reverbTime(0);
  freeverbs1.roomsize(0);
  freeverbs1.damping(0);
}
