#include <SD.h>
#include <stdint.h>
#include <WProgram.h>
#include "soundFont.h"
#include "samples.h"

//Sound File will be formated as
//file signature "TSSF"
//soundFontNameSize in byte
//soundFontName in soundFontNameSize * byte
//soundFont data as sample_data struct
//sampleCount in int16_t
//sampleRange in uint8_t
//sample data in sampleCount * int16_t

char fileName[] = "ASAXC";
byte nameLength = sizeof(fileName);

void setup()
{
  Serial.begin(115200);
  if(!SD.begin(BUILTIN_SDCARD))
    Serial.println("error sd");
  File sampleFile = SD.open("asaxc.tsf", FILE_WRITE);
  if(sampleFile == false)
    Serial.println("error file");
  sampleFile.write("TSSF", sizeof("TSSF"));
  sampleFile.write(nameLength);
  sampleFile.write(fileName, nameLength);
  sampleFile.write((char*)&sample, sizeof(struct sample_data));
  sampleFile.write(sampleCount*2);
  sampleFile.write((char*)&soundSample[0], sizeof(int16_t)*sampleCount*2);
  sampleFile.close();
  Serial.println("done");
  sampleFile = SD.open("asaxc.tsf", FILE_READ);
    if(sampleFile == false)
    Serial.println("error file");
  Serial.println(sampleFile.name());
  sampleFile.close();
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
