#ifndef AUDIO_DESIGN_H
#define AUDIO_DESIGN_H

#include <Audio.h>

extern AudioSynthWavetable wavetables[5];
extern AudioSynthKarplusStrong strings[5];
extern AudioSynthToneSweep tonesweeps[5];
extern AudioSynthWaveform waveforms[5];
extern AudioSynthWaveformModulated waveformMods[5];
extern AudioSynthWaveformPWM pwms[5];
extern AudioEffectEnvelope envelopes[5];
extern AudioMixer4 mixers[5];

extern AudioMixer4 finalMixers[2];
extern AudioAmplifier amp1;
extern AudioEffectChorus chorus1;
extern AudioEffectFlange flange1;
extern AudioEffectReverb reverb1;
extern AudioEffectFreeverbStereo freeverbs1;

#endif
