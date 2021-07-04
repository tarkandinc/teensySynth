#include "teensySynth.h"
#include "audioDesign.h"
#include "noteLookupTable.h"

void teensyMidiNoteOn(byte channel, byte note, byte velocity)
{
    // When a USB device with multiple virtual cables is used,
    // midi.getCable() can be used to read which of the virtual
    // MIDI cables received this message.
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Note On, ch=");
    Serial.print(channel, DEC);
    Serial.print(", note=");
    Serial.print(note, DEC);
    Serial.print(", velocity=");
    Serial.println(velocity, DEC);
#endif
    //todo: channel control
    //todo: find free sound
    byte soundNo = findFreeSound();
    if(soundNo != -1)
    {
      if(channel == 1)
      {
        mixers[soundNo].gain(0,1);
        wavetables[soundNo].playFrequency(noteToFreqConv(note), velocity);
      }
      else if(channel == 2)
      {
        mixers[soundNo].gain(1,1);
        strings[soundNo].noteOn(noteToFreqConv(note), velocity);
      }
      else {}//do nothing
      assignPlayingSound(note, channel, soundNo);
#ifdef PRINT_MIDI_MESSAGES
      Serial.print("Sound ");
      Serial.println(soundNo, DEC);    
#endif
    }
}

void teensyMidiNoteOff(byte channel, byte note, byte velocity)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Note Off, ch=");
    Serial.print(channel, DEC);
    Serial.print(", note=");
    Serial.print(note, DEC);
    Serial.print(", velocity=");
    Serial.println(velocity, DEC);
#endif
    //find which sound will be turned off
    byte soundNo = findPlayingSound(note, channel);
    if(soundNo != -1)
    {
      if(channel == 1)
      {
        wavetables[soundNo].stop();
        mixers[soundNo].gain(0,0);
      }
      else if(channel == 2)
      {
        strings[soundNo].noteOff(0);
        mixers[soundNo].gain(1,0);
      }
      else
      {}//do nothing
      stopSound(soundNo);  
    }
}

void teensyMidiControlChange(byte channel, byte control, byte value)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Control Change, ch=");
    Serial.print(channel, DEC);
    Serial.print(", control=");
    Serial.print(control, DEC);
    Serial.print(", value=");
    Serial.println(value, DEC);
#endif
}

void teensyMidiPitchChange(byte channel, int pitch)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Pitch Change, ch=");
    Serial.print(channel, DEC);
    Serial.print(", pitch=");
    Serial.println(pitch, DEC);
#endif
}

void teensyMidiAfterTouchChannel(byte channel, byte pressure)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("After Touch, ch=");
    Serial.print(channel, DEC);
    Serial.print(", pressure=");
    Serial.println(pressure, DEC);
#endif
}

void teensyMidiProgramChange(byte channel, byte program)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Program Change, ch=");
    Serial.print(channel, DEC);
    Serial.print(", program=");
    Serial.println(program, DEC);
#endif
    //not used
    //for changing instruments another input will be used
}

void teensyMidiAfterTouchPoly(byte channel, byte note, byte velocity)
{  
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("AfterTouch Change, ch=");
    Serial.print(channel, DEC);
    Serial.print(", note=");
    Serial.print(note, DEC);
    Serial.print(", velocity=");
    Serial.println(velocity, DEC);
#endif
  //not used
}

void teensyMidiSystemExclusiveChunk(const byte *data, uint16_t length, bool last)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Exclusive Chunk, data=");
    Serial.print(*data, DEC);
    Serial.print(", length=");
    Serial.print(length, DEC);
    Serial.print(", last=");
    Serial.println(last, DEC);
#endif
  //not used
}

void teensyMidiSystemExclusive(byte *data, unsigned int length)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Exclusive, data=");
    Serial.print(*data, DEC);
    Serial.print(", length=");
    Serial.println(length, DEC);
#endif
  //not used
}

void teensyMidiTimeCodeQuarterFrame(byte data)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Time Code, data=");
    Serial.println(data, DEC);
#endif
  //not used
}

void teensyMidiSongPosition(uint16_t beats)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Song position, beats=");
    Serial.println(beats, DEC);
#endif
  //not used
}

void teensyMidiSongSelect(byte songNumber)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Song select, number=");
    Serial.println(songNumber, DEC);
#endif
  //not used
}

void teensyMidiTuneRequest()
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.println("Tune request");
#endif
  //not used
}

void teensyMidiClock()
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.println("Midi clock");
#endif
  //not used
}

void teensyMidiStart()
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.println("Midi start");
#endif
  //not used
}

void teensyMidiContinue()
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.println("Midi continue");
#endif
  //not used
}

void teensyMidiStop()
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.println("Midi stop");
#endif
  //not used
}

void teensyMidiActiveSensing()
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.println("Midi activate sensing");
#endif
  //not used
}

void teensyMidiSystemReset()
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.println("Midi reset");
#endif
  //not used
}

void teensyMidiRealTimeSystem(byte realtimebyte)
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.print("Real time, time=");
    Serial.println(realtimebyte, DEC);
#endif
  //not used
}
