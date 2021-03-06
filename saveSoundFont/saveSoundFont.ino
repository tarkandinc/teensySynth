#include <SD.h>
#include <stdint.h>
#include <WProgram.h>
#include "soundFont.h"

//Sound File will be formated as
//soundFont data as sample_data struct
//sampleCount in int16_t
//sampleRange in uint8_t
//sample data in sampleCount * int32_t

//ENABLE ONLY ONE SOUND SAMPLE AT A TIME
//#include "asaxc.h"
//#include "effectk.h"
//#include "harmonica.h"
//#include "harpsicord.h"
//#include "htrumpetax.h"
//#include "nguitb.h"
//#include "organwave.h"
//#include "piano.h"
//#include "pianocx.h"
//#include "sawstackwavems.h"
//#include "slapbassc.h"
//#include "stringdx.h"
//#include "stringsg.h"
#include "synthstring.h"

struct count_range countAndRange = {SAMPLE_COUNT, RANGE};

void setup()
{
  Serial.begin(115200);
  if(!SD.begin(BUILTIN_SDCARD))
    Serial.println("error sd");
  if(SD.exists(FILE_NAME))
    SD.remove(FILE_NAME);  
  File sampleFile = SD.open(FILE_NAME, FILE_WRITE);
  if(sampleFile == false)
    Serial.println("error file");
  sampleFile.write((char*)&sample, sizeof(sample_data));
  sampleFile.write((char*)&countAndRange, sizeof(count_range));
  sampleFile.write((char*)soundSample, SAMPLE_COUNT*sizeof(uint32_t));
  sampleFile.close();

  sampleFile = SD.open(FILE_NAME, FILE_READ);
  if(sampleFile)
  {
    Serial.print("done: ");
    Serial.println(sampleFile.name());
  }
  else
    Serial.println("error file");
  sampleFile.close();
}

void loop() {
  // put your main code here, to run repeatedly:

}
