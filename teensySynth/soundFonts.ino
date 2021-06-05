#include <SD.h>

void loadSoundFont(byte fileNo)
{
    File root = SD.open("/");
    File soundFont;
    for(int i=0; i<fileNo; i++)
      soundFont = root.openNextFile();

    //read soundFont data

    soundFont.close();
    root.close();
}
