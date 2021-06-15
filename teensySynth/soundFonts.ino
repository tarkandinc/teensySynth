#include <SD.h>
#include <Audio.h>
#include "soundFonts.h"
#include "audioDesign.h"

//Sound File will be formated as
//First soundFont data as sample_data struct
//Second sampleCount in int16_t
//Third sampleRange in 
//Last sample data, size given in sampleCount

struct sample_data soundFont[INSTRUMENT_COUNT];
struct instrument_data instrument[INSTRUMENT_COUNT];
uint8_t sampleRange[INSTRUMENT_COUNT];
int16_t sampleCount[INSTRUMENT_COUNT];
int16_t soundSample[INSTRUMENT_COUNT][MAX_SAMPLE_COUNT];

void loadSoundFont(byte fileNo, byte sampleNo)
{
    if(sampleNo < INSTRUMENT_COUNT)
    {
      //navigate to file
      File rootDir = SD.open("/");
      File sampleFile;
      for(int i=0; i<fileNo; i++)
        sampleFile = rootDir.openNextFile();
      
      //read soundFont data
      sampleFile.read(&soundFont[sampleNo], sizeof(sample_data));
      sampleFile.read(&sampleCount[sampleNo], sizeof(int16_t));
      sampleFile.read(&sampleRange[sampleNo], sizeof(uint8_t));
      if(sampleCount[sampleNo] < MAX_SAMPLE_COUNT)
      {
        sampleFile.read(soundSample[sampleNo], sampleCount[sampleNo] * sizeof(int16_t));
        soundFont[sampleNo].sample = soundSample[sampleNo];
        instrument[sampleNo].sample_count = 1;
        instrument[sampleNo].sample_note_ranges = &sampleRange[sampleNo];
        instrument[sampleNo].samples = &soundFont[sampleNo];
        for(int i=0; i<5; i++)
          wavetables[i].setInstrument((const AudioSynthWavetable::instrument_data&)instrument[sampleNo]);
  #ifdef PRINT_MIDI_MESSAGES
        Serial.print(sampleFile.name());
        Serial.println(" loaded");
  #endif
      }
      sampleFile.close();
      rootDir.close();
   }
}
