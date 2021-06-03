#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>


AudioSynthWaveform waveforms[5];
//AudioSynthWaveform       waveform1;      //xy=514,913
//AudioSynthWaveform       waveform2;      //xy=515.7142562866211,1124.2857131958008
//AudioSynthWaveform       waveform3;      //xy=517.1429061889648,1329.999942779541
//AudioSynthWaveform       waveform4;      //xy=520.0000076293945,1535.0000228881836
//AudioSynthWaveform       waveform5;      //xy=515.0000076293945,1743.7500267028809

AudioSynthToneSweep tonesweeps[5];
//AudioSynthToneSweep      tonesweep1;     //xy=519,872
//AudioSynthToneSweep      tonesweep2;     //xy=521.428581237793,1080.0001029968262
//AudioSynthToneSweep      tonesweep3;     //xy=524.2857208251953,1284.285831451416
//AudioSynthToneSweep      tonesweep4;     //xy=522.5000076293945,1495.0000228881836
//AudioSynthToneSweep      tonesweep5;     //xy=520.0000076293945,1702.5000247955322

AudioSynthKarplusStrong strings[5];
//AudioSynthKarplusStrong  string1;        //xy=653,845
//AudioSynthKarplusStrong  string2;        //xy=661.4285583496094,1050
//AudioSynthKarplusStrong  string3;        //xy=661.4285354614258,1258.5713720321655
//AudioSynthKarplusStrong  string4;        //xy=667.5000114440918,1466.2500219345093
//AudioSynthKarplusStrong  string5;        //xy=668.7500114440918,1673.7500247955322

AudioSynthWavetable wavetables[5];
//AudioSynthWavetable      wavetable1;     //xy=665,800
//AudioSynthWavetable      wavetable2;     //xy=669.9999694824219,1001.4286060333252
//AudioSynthWavetable      wavetable3;     //xy=672.8571815490723,1211.4286212921143
//AudioSynthWavetable      wavetable4;     //xy=677.5000114440918,1416.250020980835
//AudioSynthWavetable      wavetable5;     //xy=680.0000114440918,1626.2500247955322

AudioSynthWaveformModulated waveformMods[5];
//AudioSynthWaveformModulated waveformMod1;   //xy=682,890
//AudioSynthWaveformModulated waveformMod2;   //xy=687.1428604125977,1098.5714263916016
//AudioSynthWaveformModulated waveformMod3;   //xy=688.571460723877,1304.285779953003
//AudioSynthWaveformModulated waveformMod4;   //xy=692.5000076293945,1512.5000228881836
//AudioSynthWaveformModulated waveformMod5;   //xy=696.2500076293945,1722.5000247955322

AudioSynthWaveformPWM pwms[5];
//AudioSynthWaveformPWM    pwm1;           //xy=834,919
//AudioSynthWaveformPWM    pwm2;           //xy=841.4286003112793,1131.4285526275635
//AudioSynthWaveformPWM    pwm3;           //xy=842.8571815490723,1337.1429386138916
//AudioSynthWaveformPWM    pwm4;           //xy=842.5000152587891,1545.0000228881836
//AudioSynthWaveformPWM    pwm5;           //xy=842.5000152587891,1765.0000257492065

AudioEffectEnvelope envelopes[5];
//AudioEffectEnvelope      envelope1;      //xy=1124,856
//AudioEffectEnvelope      envelope2;      //xy=1125.7142333984375,1067.1428565979004
//AudioEffectEnvelope      envelope3;      //xy=1125.71435546875,1254
//AudioEffectEnvelope      envelope4;      //xy=1126.250015258789,1467.500020980835
//AudioEffectEnvelope      envelope5;      //xy=1133.7500190734863,1676.2500247955322

AudioMixer4 mixers[5];
//AudioMixer4              mixer1;         //xy=973,856
//AudioMixer4              mixer2;         //xy=977,1068
//AudioMixer4              mixer3;         //xy=981,1255
//AudioMixer4              mixer4;         //xy=980.0000152587891,1468.750020980835
//AudioMixer4              mixer5;         //xy=977.5000152587891,1677.5000247955322

AudioMixer4 finalMixers[2];
//AudioMixer4              mixer6;         //xy=1351.2500190734863,1063.7500190734863
//AudioMixer4              mixer7;         //xy=1473.7500190734863,1252.5000228881836

AudioAmplifier           amp1;           //xy=1648.7500267028809,1100.0000162124634
AudioSynthWaveformSine   sine1;          //xy=1654.6786193847656,1173.8214302062988
AudioEffectMultiply      multiply1;      //xy=1786.6786193847656,1145.8214302062988
AudioEffectChorus        chorus1;        //xy=1928.6786193847656,1058.8214302062988
AudioEffectFlange        flange1;        //xy=1965.6786193847656,1120.8214302062988
AudioEffectReverb        reverb1;        //xy=2008.6786193847656,1184.8214302062988
AudioEffectFreeverbStereo freeverbs1;     //xy=2071.6786193847656,1247.8214302062988
AudioOutputI2S           i2s1;           //xy=2242.6786193847656,1247.8214302062988

AudioConnection          patchCord1(waveforms[0], 0, waveformMods[0], 1);
AudioConnection          patchCord2(waveforms[1], 0, waveformMods[1], 1);
AudioConnection          patchCord4(waveforms[2], 0, waveformMods[2], 1);
AudioConnection          patchCord7(waveforms[3], 0, waveformMods[3], 1);
AudioConnection          patchCord3(waveforms[4], 0, waveformMods[4], 1);

AudioConnection          patchCord5(tonesweeps[0], 0, waveformMods[0], 0);
AudioConnection          patchCord6(tonesweeps[1], 0, waveformMods[1], 0);
AudioConnection          patchCord10(tonesweeps[2], 0, waveformMods[2], 0);
AudioConnection          patchCord9(tonesweeps[3], 0, waveformMods[3], 0);
AudioConnection          patchCord8(tonesweeps[4], 0, waveformMods[4], 0);

AudioConnection          patchCord11(strings[0], 0, mixers[0], 1);
AudioConnection          patchCord12(strings[1], 0, mixers[1], 1);
AudioConnection          patchCord13(strings[2], 0, mixers[2], 1);
AudioConnection          patchCord15(strings[3], 0, mixers[3], 1);
AudioConnection          patchCord17(strings[4], 0, mixers[4], 1);

AudioConnection          patchCord14(wavetables[0], 0, mixers[0], 0);
AudioConnection          patchCord16(wavetables[1], 0, mixers[1], 0);
AudioConnection          patchCord18(wavetables[2], 0, mixers[2], 0);
AudioConnection          patchCord19(wavetables[3], 0, mixers[3], 0);
AudioConnection          patchCord22(wavetables[4], 0, mixers[4], 0);

AudioConnection          patchCord20(waveformMods[0], pwms[0]);
AudioConnection          patchCord23(waveformMods[1], pwms[1]);
AudioConnection          patchCord25(waveformMods[2], pwms[2]);
AudioConnection          patchCord28(waveformMods[3], pwms[3]);
AudioConnection          patchCord30(waveformMods[4], pwms[4]);

AudioConnection          patchCord21(waveformMods[0], 0, mixers[0], 2);
AudioConnection          patchCord24(waveformMods[1], 0, mixers[1], 2);
AudioConnection          patchCord26(waveformMods[2], 0, mixers[2], 2);
AudioConnection          patchCord27(waveformMods[3], 0, mixers[3], 2);
AudioConnection          patchCord29(waveformMods[4], 0, mixers[4], 2);

AudioConnection          patchCord31(pwms[0], 0, mixers[0], 3);
AudioConnection          patchCord32(pwms[1], 0, mixers[1], 3);
AudioConnection          patchCord33(pwms[2], 0, mixers[2], 3);
AudioConnection          patchCord34(pwms[3], 0, mixers[3], 3);
AudioConnection          patchCord35(pwms[4], 0, mixers[4], 3);

AudioConnection          patchCord36(mixers[0], envelopes[0]);
AudioConnection          patchCord37(mixers[1], envelopes[1]);
AudioConnection          patchCord40(mixers[2], envelopes[2]);
AudioConnection          patchCord39(mixers[3], envelopes[3]);
AudioConnection          patchCord38(mixers[4], envelopes[4]);

AudioConnection          patchCord41(envelopes[0], 0, finalMixers[0], 0);
AudioConnection          patchCord42(envelopes[1], 0, finalMixers[0], 1);
AudioConnection          patchCord43(envelopes[2], 0, finalMixers[0], 2);
AudioConnection          patchCord44(envelopes[3], 0, finalMixers[0], 3);
AudioConnection          patchCord45(envelopes[4], 0, finalMixers[1], 1);

AudioConnection          patchCord46(finalMixers[0], 0, finalMixers[1], 0);
AudioConnection          patchCord47(finalMixers[1], amp1);
AudioConnection          patchCord48(amp1, 0, multiply1, 0);
AudioConnection          patchCord49(sine1, 0, multiply1, 1);
AudioConnection          patchCord50(multiply1, chorus1);
AudioConnection          patchCord51(chorus1, flange1);
AudioConnection          patchCord52(flange1, reverb1);
AudioConnection          patchCord53(reverb1, freeverbs1);
AudioConnection          patchCord54(freeverbs1, 0, i2s1, 0);
AudioConnection          patchCord55(freeverbs1, 1, i2s1, 1);
// GUItool: end automatically generated code
