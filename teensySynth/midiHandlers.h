#ifndef MIDI_HANDLERS_H
#define MIDI_HANDLERS_H

  void teensyMidiNoteOn(byte channel, byte note, byte velocity);
  void teensyMidiNoteOff(byte channel, byte note, byte velocity);
  void teensyMidiAfterTouchPoly(byte channel, byte note, byte velocity);
  void teensyMidiControlChange(byte channel, byte control, byte value);
  void teensyMidiProgramChange(byte channel, byte program);
  void teensyMidiAfterTouch(byte channel, byte pressure);
  void teensyMidiPitchChange(byte channel, int pitch);
  void teensyMidiSystemExclusiveChunk(const byte *data, uint16_t length, bool last);
  void teensyMidiSystemExclusive(byte *data, unsigned int length);
  void teensyMidiTimeCodeQuarterFrame(byte data);
  void teensyMidiSongPosition(uint16_t beats);
  void teensyMidiSongSelect(byte songNumber);
  void teensyMidiTuneRequest();
  void teensyMidiClock();
  void teensyMidiStart();
  void teensyMidiContinue();
  void teensyMidiStop();
  void teensyMidiActiveSensing();
  void teensyMidiSystemReset();
  void teensyMidiRealTimeSystem(byte realtimebyte);

#endif