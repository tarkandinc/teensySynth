#include <SD.h>
#include <stdint.h>
#include <WProgram.h>
#include "soundSample.h"
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
//file ens signature "TSSFEND"

char fileName[] = FILE_NAME;
byte nameLength = sizeof(fileName);

void setup()
{
  Serial.begin(115200);
  if(!SD.begin(BUILTIN_SDCARD))
    Serial.println("error sd");
  File sampleFile = SD.open(FILE_NAME, FILE_WRITE);
  if(sampleFile == false)
    Serial.println("error file");
  sampleFile.write("TSSF", sizeof("TSSF"));
  sampleFile.write(nameLength);
  sampleFile.write(fileName, nameLength);
  sampleFile.write((char*)&sample, sizeof(struct sample_data));
  sampleFile.write(sampleCount);
  sampleFile.write((char*)&soundSample[0], sizeof(int32_t)*sampleCount);
  sampleFile.write("TSSFEND", sizeof("TSSFEND"));
  sampleFile.close();

  sampleFile = SD.open(FILE_NAME, FILE_READ);
  if(sampleFile)
  {
    Serial.println("done");
    Serial.println(sampleFile.name());
  }
  else
    Serial.println("error file");
  sampleFile.close();
}

void loop() {
  // put your main code here, to run repeatedly:

}
