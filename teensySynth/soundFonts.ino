#include <SD.h>
#include <Audio.h>
#include "soundFonts.h"

//Sound File will be formated as
//First soundFont data as sample_data struct
//Second sampleCount in int16_t
//Third sampleRange in 
//Last sample data, size given in sampleCount

sample_data soundFont;
instrument_data instrument;
uint8_t sampleRange;
int16_t sampleCount;
int16_t soundSample[MAX_SAMPLE_COUNT];

void loadSoundFont(byte fileNo)
{
    //navigate to file
    File rootDir = SD.open("/");
    File sampleFile;
    for(int i=0; i<fileNo; i++)
      sampleFile = rootDir.openNextFile();
    
    //read soundFont data
    sampleFile.read(&soundFont, sizeof(sample_data));
    sampleFile.read(&sampleCount, sizeof(int16_t));
    sampleFile.read(&sampleRange, sizeof(uint8_t));
    if(sampleCount < MAX_SAMPLE_COUNT)
      sampleFile.read(soundSample, sampleCount * sizeof(int16_t));
    soundFont.sample = soundSample;
    instrument.sample_count = 1;
    instrument.sample_note_ranges = &sampleRange;
    instrument.samples = &soundFont;
    sampleFile.close();
    rootDir.close();
}
