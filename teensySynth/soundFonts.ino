#include <SD.h>
#include <Audio.h>
#include <String.h>
#include "soundFonts.h"
#include "audioDesign.h"
#include "teensySynth.h"

//Sound File will be formated as
//soundFont data as sample_data struct
//sampleCount in int16_t
//sampleRange in uint8_t
//sample data in sampleCount * int32_t

struct sample_data soundFont;
struct instrument_data instrument;
struct count_range countAndRange;
uint32_t soundSample[MAX_SAMPLE_COUNT];

void loadSoundFont(byte fileNo, byte sampleNo)
{
    //char signature[5];
    //char endSignature[8];
    //signature[4] = 0;
    //endSignature[7] = 0;
    //byte nameLength;
    //char name[32];
    
    //navigate to file
    File rootDir = SD.open("/");
    File sampleFile;
    for(int i=-1; i<fileNo; i++)
    {
      sampleFile = rootDir.openNextFile();
      if(sampleFile.isDirectory())
      {
        i--;
        continue;
      }
      if(sampleFile.name()[0] == '_' || sampleFile.name()[0] == '~')
      {
        i--;
        continue;
      }
    }
#ifdef PRINT_FILE_MESSAGES
    Serial.println(sampleFile.name());
#endif
    sampleFile.read((char*)&soundFont, sizeof(sample_data));
#ifdef PRINT_FILE_MESSAGES
    //Serial.println(soundFont.INDEX_BITS, DEC);
#endif
    sampleFile.read((char*)&countAndRange, sizeof(count_range));
#ifdef PRINT_FILE_MESSAGES
    Serial.println(countAndRange.sampleCount, DEC);
#endif
    if(countAndRange.sampleCount < MAX_SAMPLE_COUNT)
    {
      //sampleFile.read((char*)soundSample, countAndRange.sampleCount * sizeof(int16_t)*2);
      for(int i=0; i<countAndRange.sampleCount; i++)
      {
        sampleFile.read((char*)(&(soundSample[i])), sizeof(uint32_t));
#ifdef PRINT_FILE_MESSAGES        
        //Serial.println(soundSample[i], HEX);
#endif
      }
#ifdef PRINT_FILE_MESSAGES
        Serial.print(sampleFile.name());
        Serial.print(": ");        
        Serial.print(countAndRange.sampleCount, DEC);
        Serial.println(" samples loaded");
#endif      
      soundFont.sample = (uint16_t*)soundSample;
      instrument.sample_count = 1;
      instrument.sample_note_ranges = (uint8_t*)&(countAndRange.sampleRange);
      instrument.samples = &(soundFont);
      for(int i=0; i<5; i++)
        wavetables[i].setInstrument((const AudioSynthWavetable::instrument_data&)(instrument));
    }
    sampleFile.close();
    rootDir.close();
}
