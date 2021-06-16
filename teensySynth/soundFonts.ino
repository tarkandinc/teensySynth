#include <SD.h>
#include <Audio.h>
#include <String.h>
#include "soundFonts.h"
#include "audioDesign.h"

//Sound File will be formated as
//file signature "TSSF"
//soundFontNameSize in byte
//soundFontName in soundFontNameSize * byte
//soundFont data as sample_data struct
//sampleCount in int16_t
//sampleRange in uint8_t
//sample data in sampleCount * int16_t

struct sample_data soundFont[INSTRUMENT_COUNT];
struct instrument_data instrument[INSTRUMENT_COUNT];
uint8_t sampleRange[INSTRUMENT_COUNT];
int16_t sampleCount[INSTRUMENT_COUNT];
int16_t soundSample[INSTRUMENT_COUNT][MAX_SAMPLE_COUNT];

void loadSoundFont(byte fileNo, byte sampleNo)
{
    char signature[5];
    signature[4] = 0;
    byte nameLength;
    char name[32];
    
    //navigate to file
    File rootDir = SD.open("/");
    File sampleFile;
    for(int i=-1; i<fileNo; i++)
      sampleFile = rootDir.openNextFile();
    //read soundFont data
    sampleFile.read(signature, sizeof("TSSF"));
    if(strncmp(signature,"TSSF", 4) == 0)
    {
      sampleFile.read(&nameLength, sizeof(byte));
      sampleFile.read(name, sizeof(char) * nameLength);
      sampleFile.read(&soundFont, sizeof(sample_data));
      sampleFile.read(&sampleCount, sizeof(int16_t));
      sampleFile.read(&sampleRange, sizeof(uint8_t));
      if(sampleCount[sampleNo] < MAX_SAMPLE_COUNT)
      {
        sampleFile.read(soundSample[sampleNo], sampleCount[sampleNo] * sizeof(int16_t)*2);
        soundFont[sampleNo].sample = soundSample[sampleNo];
        instrument[sampleNo].sample_count = 1;
        instrument[sampleNo].sample_note_ranges = &(sampleRange[sampleNo]);
        instrument[sampleNo].samples = &(soundFont[sampleNo]);
        for(int i=0; i<5; i++)
          wavetables[i].setInstrument((const AudioSynthWavetable::instrument_data&)(instrument[sampleNo]));
  #ifdef PRINT_MIDI_MESSAGES
        Serial.print(sampleFile.name());
        Serial.println(" loaded");
  #endif
      }
    }
    sampleFile.close();
    rootDir.close();
}
