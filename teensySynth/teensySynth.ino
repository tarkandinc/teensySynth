#include "teensySynth.h"
#include "midiHandlers.h"
#include "audioFunctions.h"
#include "soundFonts.h"
#include <USBHost_t36.h>
#include <SD.h>

USBHost teensyUsbHost;
MIDIDevice teensyMidi(teensyUsbHost);
File root;

void setup()
{
#ifdef PRINT_MIDI_MESSAGES
    Serial.begin(115200);
#endif
    // Wait 1.5 seconds before turning on USB Host.
    // If connected USB devices use too much power.
    // Teensy at least completes USB enumeration
    // which makes isolating the power issue easier.
    delay(1500);
#ifdef PRINT_MIDI_MESSAGES  
    Serial.println("USB MIDI Messages");
    delay(10);
#endif
    SD.begin();
    
    teensyMidi.setHandleNoteOn(teensyMidiNoteOn);
    teensyMidi.setHandleNoteOff(teensyMidiNoteOff);
    teensyMidi.setHandleAfterTouchPoly(teensyMidiAfterTouchPoly);
    teensyMidi.setHandleControlChange(teensyMidiControlChange);
    teensyMidi.setHandleProgramChange(teensyMidiProgramChange);
    teensyMidi.setHandleAfterTouchChannel(teensyMidiAfterTouchChannel);
    teensyMidi.setHandlePitchChange(teensyMidiPitchChange);
    // Only one of these System Exclusive handlers will actually be used.
    // See the comments below for the difference between them.
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

    initAudioFunctions();
    loadSoundFont(0);
}

void loop()
{  
    // The handler functions are called when midi1 reads data.  They
    // will not be called automatically.  You must call midi1.read()
    // regularly from loop() for midi1 to actually read incoming
    // data and run the handler functions as messages arrive.
    teensyUsbHost.Task();
    teensyMidi.read();  
}
