#include <USBHost_t36.h>

USBHost teensyUsbHost;
MIDIDevice teensyMidi(teensyUsbHost);

void setup()
{
    teensyMidi.setHandleNoteOn(teensyMidiNoteOn);
    teensyMidi.setHandleNoteOff(teensyMidiNoteOff);
    teensyMidi.setHandleAfterTouchPoly(teensyMidiAfterTouchPoly);
    teensyMidi.setHandleControlChange(teensyMidiControlChange);
    teensyMidi.setHandleProgramChange(teensyMidiProgramChange);
    teensyMidi.setHandleAfterTouchChannel(teensyMidiAfterTouchChannel);
    teensyMidi.setHandlePitchChange(teensyMidiPitchChange);
  // Only one of these System Exclusive handlers will actually be
  // used.  See the comments below for the difference between them.
    teensyMidi.setHandleSystemExclusive(teensyMidiSystemExclusiveChunk);
    teensyMidi.setHandleSystemExclusive(teensyMidiSystemExclusive); 
    teensyMidi.setHandleTimeCodeQuarterFrame(teensyMidiTimeCodeQuarterFrame);
    teensyMidi.setHandleSongPosition(teensyMidiSongPosition);
    teensyMidi.setHandleSongSelect(teensyMidiSongSelect);
    teensyMidi.setHandleTuneRequest(teensyMidiTuneRequest);
    teensyMidi.setHandleClock(teensyMidiClock);
    teensyMidi.setHandleStart(teensyMidiStart);
    teensyMidi.setHandleContinue(teensyMidiContinue);
    teensyMidi.setHandleStop(teensyMidiStop);
    teensyMidi.setHandleActiveSensing(teensyMidiActiveSensing);
    teensyMidi.setHandleSystemReset(teensyMidiSystemReset);
    // This generic System Real Time handler is only used if the
    // more specific ones are not set.
    teensyMidi.setHandleRealTimeSystem(teensyMidiRealTimeSystem);
}

void loop()
{
  
}
