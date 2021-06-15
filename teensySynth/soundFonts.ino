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

struct sample_data soundFont;
struct instrument_data instrument;
uint8_t sampleRange;
int16_t sampleCount;
int16_t soundSample[MAX_SAMPLE_COUNT];

void loadSoundFont(byte fileNo)
{
    byte signature[4];
    
    //navigate to file
    File rootDir = SD.open("/");
    File sampleFile;
    for(int i=0; i<fileNo; i++)
      sampleFile = rootDir.openNextFile();
    
    //read soundFont data
    sampleFile.read(signature, sizeof("TSSF"));
    if(strcmp(signature,"TSSF") == 0)
    {
      sampleFile.read(&soundFont, sizeof(sample_data));
      sampleFile.read(&sampleCount, sizeof(int16_t));
      sampleFile.read(&sampleRange, sizeof(uint8_t));
      if(sampleCount < MAX_SAMPLE_COUNT)
      {
        sampleFile.read(soundSample, sampleCount * sizeof(int16_t));
        soundFont.sample = soundSample;
        instrument.sample_count = 1;
        instrument.sample_note_ranges = &sampleRange;
        instrument.samples = &soundFont;
        for(int i=0; i<5; i++)
          wavetables[i].setInstrument((const AudioSynthWavetable::instrument_data&)instrument);
  #ifdef PRINT_MIDI_MESSAGES
        Serial.print(sampleFile.name());
        Serial.println(" loaded");
  #endif
      }
    }
    sampleFile.close();
    rootDir.close();
}
