#ifndef SOUND_FONTS_H
#define SOUND_FONTS_H

#define MAX_SAMPLE_COUNT 65536/2
//max sample size must be 16684 in uint32

#ifdef TEENSY_3_6
#define INSTRUMENT_COUNT 1
#endif

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
  uint8_t* sample_note_ranges;
  sample_data* samples;
};

void loadSoundFont(byte fileNo, byte sampleNo);

#endif
