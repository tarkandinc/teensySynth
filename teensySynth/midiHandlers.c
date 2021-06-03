  #include "teensySynth.h"

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

  }

  void teensyMidiNoteOff(byte channel, byte note, byte velocity)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif

  }

  void teensyMidiAfterTouchPoly(byte channel, byte note, byte velocity)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiControlChange(byte channel, byte control, byte value)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiProgramChange(byte channel, byte program)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiAfterTouch(byte channel, byte pressure)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiPitchChange(byte channel, int pitch)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiSystemExclusiveChunk(const byte *data, uint16_t length, bool last)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiSystemExclusive(byte *data, unsigned int length)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiTimeCodeQuarterFrame(byte data)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiSongPosition(uint16_t beats)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiSongSelect(byte songNumber)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiTuneRequest()
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiClock()
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiStart()
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiContinue()
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiStop()
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiActiveSensing()
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiSystemReset()
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }

  void teensyMidiRealTimeSystem(byte realtimebyte)
  {
#ifdef PRINT_MIDI_MESSAGES

#endif
  }