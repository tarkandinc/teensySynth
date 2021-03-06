#ifndef SOUND_FONTS_H
#define SOUND_FONTS_H

#include <stdint.h>
#include <WProgram.h>

#define AUDIO_BLOCK_SAMPLES 128
#define AUDIO_SAMPLE_RATE_EXACT 44117.64706

#define CENTS_SHIFT(C) (pow(2.0, C/1200.0))
#define NOTE(N) (440.0 * pow(2.0, (N - 69) / 12.0))
#define DECIBEL_SHIFT(dB) (pow(10.0, dB/20.0))
#define UNITY_GAIN INT32_MAX // Max amplitude / no attenuation
#define DEFAULT_AMPLITUDE 90
#define SAMPLES_PER_MSEC (AUDIO_SAMPLE_RATE_EXACT/1000.0)
#define TRIANGLE_INITIAL_PHASE (-0x40000000)
#define LFO_SMOOTHNESS 3
#define LFO_PERIOD (AUDIO_BLOCK_SAMPLES/(1 << (LFO_SMOOTHNESS-1)))
#define ENVELOPE_PERIOD 8

struct sample_data
{
  // SAMPLE VALUES
  int16_t* sample;
  bool LOOP;
  int INDEX_BITS;
  float PER_HERTZ_PHASE_INCREMENT;
  uint32_t MAX_PHASE;
  uint32_t LOOP_PHASE_END;
  uint32_t LOOP_PHASE_LENGTH;
  uint16_t INITIAL_ATTENUATION_SCALAR;
  
  // VOLUME ENVELOPE VALUES
  uint32_t DELAY_COUNT;
  uint32_t ATTACK_COUNT;
  uint32_t HOLD_COUNT;
  uint32_t DECAY_COUNT;
  uint32_t RELEASE_COUNT;
  int32_t SUSTAIN_MULT;

  // VIRBRATO VALUES
  uint32_t VIBRATO_DELAY;
  uint32_t VIBRATO_INCREMENT;
  float VIBRATO_PITCH_COEFFICIENT_INITIAL;
  float VIBRATO_PITCH_COEFFICIENT_SECOND;

  // MODULATION VALUES
  uint32_t MODULATION_DELAY;
  uint32_t MODULATION_INCREMENT;
  float MODULATION_PITCH_COEFFICIENT_INITIAL;
  float MODULATION_PITCH_COEFFICIENT_SECOND;
  int32_t MODULATION_AMPLITUDE_INITIAL_GAIN;
  int32_t MODULATION_AMPLITUDE_SECOND_GAIN;
};

struct instrument_data
{
  uint8_t sample_count;
  uint8_t sample_note_ranges;
  struct sample_data* samples;
};

struct count_range
{
  int sampleCount;
  int sampleRange;  
};

#endif
