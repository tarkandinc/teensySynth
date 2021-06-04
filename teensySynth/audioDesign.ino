#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

/* AudioSynthWavetable: Synthesize musical instruments using wavetable samples. Sample data is extracted from SoundFont2 files.
 * setInstrument(instrument);
 * amplitude(volume);
 * setFrequency(freq);
 * playFrequency(freq, amplitude);
 * stop();
 * isPlaying();
 * getEnvState();
 */
AudioSynthWavetable wavetables[5];

/* AudioSynthKarplusStrong: Synthesize a plucked string sound, such as a guitar string.
 * noteOn(frequency, velocity): Begin a new string note. Velocity can be from 0 to 1.0, indicating how hard the string is plucked.
 * noteOff(velocity): Stop the sound output.
 */
AudioSynthKarplusStrong strings[5];

/* AudioSynthToneSweep: Create a continuously varying (in frequency) sine wave
 * play(level, lowFreq, highFreq, time): Start generating frequency sweep output. The time is specified in seconds. Level is 0 to 1.0.
 * isPlaying(): Returns true (non-zero) while the output is active.
 * read(): Returns the current frequency, or zero if the output is not active.
 */
AudioSynthToneSweep tonesweeps[5];

/* AudioSynthWaveform: Create a waveform: sine, sawtooth, square, triangle, pulse, random S&H or arbitrary.
 * begin(waveform): Configure the waveform type to create.
 *                  WAVEFORM_SINE, WAVEFORM_SAWTOOTH, WAVEFORM_SAWTOOTH_REVERSE, WAVEFORM_SQUARE
 *                  WAVEFORM_TRIANGLE, WAVEFORM_TRIANGLE_VARIABLE, WAVEFORM_ARBITRARY
 *                  WAVEFORM_PULSE, WAVEFORM_SAMPLE_HOLD
 * begin(level, frequency, waveform): Output a waveform, and set the amplitude and frequency.
 * frequency(freq): Change the frequency.
 * amplitude(level): Change the amplitude. Set to 0 to turn the signal off.
 * offset(level): Add a DC offset, from -1.0 to +1.0. Useful for generating waveforms to use as control or modulation signals.
 * phase(angle): Cause the generated waveform to jump to a specific point within its cycle. Angle is from 0 to 360 degrees. 
 *               When multiple objects are configured, AudioNoInterrupts() should be used to guarantee all new settings take effect together.
 * pulseWidth(amount): Change the width (duty cycle) of the pulse.
 * arbitraryWaveform(array, maxFreq): Configure the waveform to be used with WAVEFORM_ARBITRARY. Array must be an array of 256 samples. 
 *                                    Currently, the data is used without any filtering, which can cause aliasing with frequencies above 172 Hz.
 *                                    For higher frequency output, you must bandwidth limit your waveform data. Someday, "maxFreq" will be used to do this automatically.
 */
AudioSynthWaveform waveforms[5];
AudioSynthWaveform waveformMul;

/* AudioSynthWaveformModulated: Create a waveform with modulation: sine, sawtooth, square, triangle, pulse, random S&H or arbitrary.
 * begin(waveform): Configure the waveform type to create.
 *                  WAVEFORM_SINE, WAVEFORM_SAWTOOTH, WAVEFORM_SAWTOOTH_REVERSE
 *                  WAVEFORM_SQUARE, WAVEFORM_TRIANGLE, WAVEFORM_TRIANGLE_VARIABLE
 *                  WAVEFORM_ARBITRARY, WAVEFORM_PULSE, WAVEFORM_SAMPLE_HOLD
 * begin(level, frequency, waveform): Output a waveform, and set the amplitude and base frequency.
 * frequency(freq): Change the base (unmodulated) frequency.
 * amplitude(level): Change the amplitude. Set to 0 to turn the signal off.
 * offset(level): Add a DC offset, from -1.0 to +1.0. Useful for generating waveforms to use as control or modulation signals.
 * frequencyModulation(octaves): Configure for frequency modulation mode (the default) where the input signal will adjust the frequency by a specific number of octaves (the default is 8 octaves). 
 *                               If the -1.0 to +1.0 signal represents a ±10 volt range and you wish to have control at 1 volt/octave, then configure for 10 octaves range.
 *                               The maximum modulation sensitivity is 12 octaves.
 * phaseModulation(degrees): Configure for phase modulation mode where the input signal will adjust the waveform phase angle a specific number of degrees. 
 *                           180.0 allows a full scale ±1.0 signal to span 1 full cycle of the waveform. Maximum modulation sensitivity is 9000 degrees (±25 cycles).
 * arbitraryWaveform(array, maxFreq): Configure the waveform to be used with WAVEFORM_ARBITRARY. Array must be an array of 256 samples.
 *                                    Currently, the data is used without any filtering, which can cause aliasing with frequencies above 172 Hz.
 *                                    For higher frequency output, you must bandwidth limit your waveform data. Someday, "maxFreq" will be used to do this automatically.
 */
AudioSynthWaveformModulated waveformMods[5];

/* AudioSynthWaveformPWM: Create a Pulse Width Modulated waveform, with an audio signal controlling the pulse width duty cycle.
 *                        The duty cycle is 50% when the control waveform is zero.
 *                        As the control input causes a linear changes in PWM duty cycle, from nearly 0 to 100% over -1.0 to +1.0 range.
 *                        See the notes below for minimum and maximum limitations.
 * frequency(freq): Change the frequency.
 * amplitude(level): Change the amplitude. Set to 0 to turn the signal off. 
 */
AudioSynthWaveformPWM pwms[5];

/* AudioEffectEnvelope: Modify a signal with a DAHDSR (Delay Attack Hold Decay Sustain Release) envelope.
 * noteOn(): Begin the delay to attack, or the attack phase is delay is zero.
 * noteOff(): Begin the release phase.
 * delay(milliseconds): Set the delay from noteOn to the attach phase. The default is zero, for no delay.
 * attack(milliseconds): Set the attack time. The default is 10.5 milliseconds. The maximum is 11880 milliseconds.
 * hold(milliseconds): Set the hold time. The default is 2.5 milliseconds. The maximum is 11880 milliseconds.
 * decay(milliseconds): Set the decay time. The default is 35 milliseconds. The maximum is 11880 milliseconds.
 * sustain(level): Set the sustain level. The range is 0 to 1.0. The gain will be maintained at this level after the decay phase, until noteOff() is called.
 *                 The sustain phase may last any length of time, controlled by when release() is called.
 * release(milliseconds): Set the release time. The default is 300 millisecond. The maximum is 11880 milliseconds.
 * releaseNoteOn(milliseconds): Set a quick release time to be used when a new note is started while the envelop is in any state passing the signal.
 *                              This will add latency before your new attack phase begins, so short times are recommended.
 *                              Zero may be used to completely disable this feature (never extra latency). Longer times help reduce clicks or pops.
 *                              The default is 5 millisecond.
 * isActive(): Returns true when the envelope is currently in any of its 6 phases.
 * isSustain(): Returns true when the envelope is currently in the sustain phase.
 */
AudioEffectEnvelope envelopes[5];

/* AudioMixer4: Combine up to 4 audio signals together, each with adjustable gain. All channels support signal attenuation or amplification.
 * gain(channel, level): Adjust the amplification or attenuation. "channel" must be 0 to 3. "level" may be any floating point number from 0 to 32767.0. 
 *                       1.0 passes the signal through directly. Level of 0 shuts the channel off completely.
 *                       Between 0 to 1.0 attenuates the signal, and above 1.0 amplifies it.
 *                       Negative numbers may also be used, to invert the signal.
 *                       All 4 channels have separate gain settings. 
 */
AudioMixer4 mixers[5];

AudioMixer4 finalMixers[2];

/* AudioAmplifier: Amplify or attenuate a signal, or switch it on/off.
 * gain(level): Adjust the amplification or attenuation. "level" may be any floating point number from 0 to 32767.0. 
 *              1.0 passes the signal through directly. Level of 0 shuts the channel off completely.
 *              Between 0 to 1.0 attenuates the signal, and above 1.0 amplifies it.
 *              Negative numbers may also be used, to invert the signal.
 *              Gain of 0 and 1.0 are handled efficiently as special cases.
 *              Zero discards data without processing. 1.0 passes data directly, with minimal overhead.
 *              Signal clipping can occur when any channel has gain greater than 1.0
 */
AudioAmplifier amp1;

/* AudioEffectMultiply: Multiply two signals together, useful for amplitude modulation or "voltage controlled amplification".
 * There are no functions to call from the Arduino sketch. This object simply multiplies the 2 signals to create a continuous output. 
 */
//AudioEffectMultiply multiply1;

/* The chorus effect simulates the richness of several nearly-identical sound sources (like the way a choir sounds different to a single singer).
 * It does this by sampling from a delay line, so each voice is actually the same but at a slightly different point in time. This is a type of comb filtering.
 * Chorus combines one or more samples ranging from the most recent sample back to about 50ms ago.
 * The additional samples are evenly spread through the supplied delay line, and there is no modulation.
 * If the number of voices is specified as 2, then the effect combines the current sample and the oldest sample (the last one in the delay line).
 * If the number of voices is 3 then the effect combines the most recent sample, the oldest sample and the sample in the middle of the delay line.
 * For two voices the effect can be represented as: result = (sample(0) + sample(dt))/2
 * where sample(0) represents the current sample and sample(dt) is the sample in the delay line from dt milliseconds ago.
 * begin(delayBuffer, length, n_chorus): Create a chorus by specifying the address of the delayline,
 *                                       the total number of samples in the delay line (often done as an integer multiple of AUDIO_BLOCK_SAMPLES)
 *                                       and the number of voices in the chorus including the original voice
 *                                       (so, 2 and up to get a chorus effect, although you can specify 1 if you want).
 * voices(n_chorus):Alters the number of voices in a running chorus (previously started with begin).
 */
AudioEffectChorus chorus1;

/* AudioEffectFlange: Originally, flanging was produced by playing the same signal on two synchronized reel-to-reel tape recorders and
 * making one of the reels slow down and speed up by pressing on the flange of the reel (hence the name).
 * This is a type of comb filtering, and produces a harmonically-related series of peaks and notches in the audio spectrum.
 * This flanger uses a delay line, combining the original voice with only one sample from the delay line, but the position of that sample varies sinusoidally.
 * The effect can be represented as: result = sample(0) + sample(dt + depth*sin(2*PI*Fe))
 * The value of the sine function is always a number from -1 to +1 and so the result of depth*(sin(Fe)) is always a number from -depth to +depth. 
 * Thus, the delayed sample will be selected from the range (dt-depth) to (dt+depth).
 * This selection will vary at whatever rate is specified as the frequency of the effect, Fe. Typically a low frequency (a few Hertz) is used.
 * begin(delayBuffer, length, offset, depth, delayRate): Create a flanger by specifying the address of the delayline, 
 *                                                       the total number of samples in the delay line (often done as an integer multiple of AUDIO_BLOCK_SAMPLES),
 *                                                       the offset (how far back the flanged sample is from the original voice),
 *                                                       the modulation depth (larger values give a greater variation) and the modulation frequency, in Hertz.
 * voices(offset, depth, delayRate): Alters the parameters in a running flanger (previously started with begin).
 */
AudioEffectFlange flange1;

/* AudioEffectReverb: Reverb with adjustable reverberation time. Contributed by Joao Rossi FIlho.
 * reverbTime(seconds): Sets the amount of reverberation time.
 */
AudioEffectReverb reverb1;

/* AudioEffectFreeverbStereo: High quality stereo Reverb effect, based on Freeverb by Jezar at Dreampoint.
 * Teensy 3.5 or 3.6 required to run stereo version.
 * roomsize(amount): Sets the amount of reverberant echo or apparent room size, from 0 (smallest) to 1.0 (largest).
 * damping(amount): Sets the damping factor, from 0 to 1.0. More damping causes higher frequency echo to decay,
 *                  creating a softer sound, similar to a large room filled with people or materials which absorb some sound as it travels between reflecting surfaces.
 *                  Lower damping simulates a harsher reverberant field.
 */
AudioEffectFreeverbStereo freeverbs1;

/* AudioOutputI2S: Transmit 16 bit stereo audio to the audio shield or another I2S device, using I2S master mode.
 * This object has no functions to call from the Arduino sketch. It simply streams data from its 2 input ports to the I2S hardware.
 */
AudioOutputI2S i2s1;

//Sound generating connections
AudioConnection          patchCord01(waveforms[0], 0, waveformMods[0], 1);
AudioConnection          patchCord02(waveforms[1], 0, waveformMods[1], 1);
AudioConnection          patchCord03(waveforms[2], 0, waveformMods[2], 1);
AudioConnection          patchCord04(waveforms[3], 0, waveformMods[3], 1);
AudioConnection          patchCord05(waveforms[4], 0, waveformMods[4], 1);

AudioConnection          patchCord06(tonesweeps[0], 0, waveformMods[0], 0);
AudioConnection          patchCord07(tonesweeps[1], 0, waveformMods[1], 0);
AudioConnection          patchCord08(tonesweeps[2], 0, waveformMods[2], 0);
AudioConnection          patchCord09(tonesweeps[3], 0, waveformMods[3], 0);
AudioConnection          patchCord10(tonesweeps[4], 0, waveformMods[4], 0);

AudioConnection          patchCord11(strings[0], 0, mixers[0], 1);
AudioConnection          patchCord12(strings[1], 0, mixers[1], 1);
AudioConnection          patchCord13(strings[2], 0, mixers[2], 1);
AudioConnection          patchCord14(strings[3], 0, mixers[3], 1);
AudioConnection          patchCord15(strings[4], 0, mixers[4], 1);

AudioConnection          patchCord16(wavetables[0], 0, mixers[0], 0);
AudioConnection          patchCord17(wavetables[1], 0, mixers[1], 0);
AudioConnection          patchCord18(wavetables[2], 0, mixers[2], 0);
AudioConnection          patchCord19(wavetables[3], 0, mixers[3], 0);
AudioConnection          patchCord20(wavetables[4], 0, mixers[4], 0);

AudioConnection          patchCord21(waveformMods[0], pwms[0]);
AudioConnection          patchCord22(waveformMods[1], pwms[1]);
AudioConnection          patchCord23(waveformMods[2], pwms[2]);
AudioConnection          patchCord24(waveformMods[3], pwms[3]);
AudioConnection          patchCord25(waveformMods[4], pwms[4]);

AudioConnection          patchCord26(waveformMods[0], 0, mixers[0], 2);
AudioConnection          patchCord27(waveformMods[1], 0, mixers[1], 2);
AudioConnection          patchCord28(waveformMods[2], 0, mixers[2], 2);
AudioConnection          patchCord29(waveformMods[3], 0, mixers[3], 2);
AudioConnection          patchCord30(waveformMods[4], 0, mixers[4], 2);

AudioConnection          patchCord31(pwms[0], 0, mixers[0], 3);
AudioConnection          patchCord32(pwms[1], 0, mixers[1], 3);
AudioConnection          patchCord33(pwms[2], 0, mixers[2], 3);
AudioConnection          patchCord34(pwms[3], 0, mixers[3], 3);
AudioConnection          patchCord35(pwms[4], 0, mixers[4], 3);

AudioConnection          patchCord36(mixers[0], envelopes[0]);
AudioConnection          patchCord37(mixers[1], envelopes[1]);
AudioConnection          patchCord38(mixers[2], envelopes[2]);
AudioConnection          patchCord39(mixers[3], envelopes[3]);
AudioConnection          patchCord40(mixers[4], envelopes[4]);

AudioConnection          patchCord41(envelopes[0], 0, finalMixers[0], 0);
AudioConnection          patchCord42(envelopes[1], 0, finalMixers[0], 1);
AudioConnection          patchCord43(envelopes[2], 0, finalMixers[0], 2);
AudioConnection          patchCord44(envelopes[3], 0, finalMixers[0], 3);
AudioConnection          patchCord45(envelopes[4], 0, finalMixers[1], 1);

//Final mixer connections
AudioConnection          patchCord46(finalMixers[0], 0, finalMixers[1], 0);
AudioConnection          patchCord47(finalMixers[1], amp1);
//AudioConnection          patchCord48(amp1, 0, multiply1, 0);
AudioConnection          patchCord48(amp1, 0, chorus1, 0);
//AudioConnection          patchCord49(waveformMul, 0, multiply1, 1);

//Effects conections
//AudioConnection          patchCord50(multiply1, chorus1);
AudioConnection          patchCord51(chorus1, flange1);
AudioConnection          patchCord52(flange1, reverb1);
AudioConnection          patchCord53(reverb1, freeverbs1);

//Output connections
AudioConnection          patchCord54(freeverbs1, 0, i2s1, 0);
AudioConnection          patchCord55(freeverbs1, 1, i2s1, 1);
// GUItool: end automatically generated code
