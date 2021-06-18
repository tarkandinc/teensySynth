#define SAMPLE_COUNT 768
#define RANGE 127

#define FILE_NAME "harpsicord.tsf"

uint32_t soundSample[SAMPLE_COUNT] = {
0x00000000,0x17baf907,0x36f0b93f,0x2b4ef3e9,0xe805221c,0x26c6109c,0xb7ff253b,0xdeb0fec7,
0xebac0ad7,0x0e0d18ae,0x499ae011,0x164c14be,0x64480391,0xf0cd08d3,0x3110f62f,0xefd83335,
0x11a71e31,0x415f09ef,0xd12512d5,0x0e02e45c,0xfc81f313,0xed921725,0xe5e0071c,0x0d31eb98,
0xbe37d7fc,0xf5cf0b2a,0x61d33b54,0x11e3050b,0xdcdb244e,0xd3ac4325,0xc447aa6c,0xd48afcf2,
0x04e0fe99,0x1c20c4f0,0xfde11612,0x4194e9a7,0xda60d4c4,0x1d3ddbc6,0xdb7112d8,0xedccff21,
0x1ff4ef6e,0xbcb6f0f2,0xf598d340,0xf41ee32d,0xdea4ffb9,0xd3daeace,0x08b7e13a,0xd086c5c4,
0xef25fec7,0x59ce47ed,0x1af90bdb,0xdf5e2ada,0xccec340b,0xe36cb3ed,0xd69602e8,0x18bd0bfe,
0x302fdf01,0x0680284f,0x4d33f678,0xf836ef9c,0x279af12c,0xe94a0f63,0x06ec0f98,0x251f0200,
0xd3d7040f,0xff4af2de,0xff77f646,0xfa0102fa,0xdf70f950,0x11bef072,0xd6bac305,0xf8df0b04,
0x570e51ae,0x1f371246,0xed972e1e,0xd85442eb,0xf00bbffa,0xe39cf473,0x0137028d,0x2212dd98,
0x03da1a8f,0x3b4af565,0xf0aee892,0x3532e66d,0xdebf0f72,0xfa8104fc,0x1612f6a5,0xbabef35c,
0xf469e454,0xfe4eeaba,0xda70f029,0xd533ee54,0x1b10d804,0xc713b648,0xef070a8c,0x525052c6,
0x14891603,0xeb592a70,0xc7162bbc,0xeb1cbfe4,0xe580ef62,0x119a0fd0,0x2eeff3cb,0x0fe622e8,
0x4045022b,0xff0dfb46,0x3769e367,0xed6a07b6,0x06871115,0x1f1e042b,0xc82d00f8,0xfe490047,
0x0b16eb6d,0xf09ffae8,0xe62401f9,0x2411e0bf,0xd086b398,0xf1d8155a,0x54545275,0x15b818ca,
0xf4a83e45,0xe3ba41c8,0xfa63ba15,0xde5af82e,0x05750c81,0x1b24e3fe,0x09711fb3,0x2f7cf666,
0xf2f2e998,0x387ce38a,0xe1bb0070,0xf4c70286,0x09a4ff8b,0xb2f6e892,0xea23ed74,0xf565ed6c,
0xe725e302,0xd9dbe41f,0x1e84d666,0xc755a511,0xe7d511b1,0x4f9152ac,0x1630157e,0xe6ed39c6,
0xdaac3088,0xfb76b029,0xe49df3e4,0x17c41f1b,0x2c35f7f7,0x16652e65,0x3b1f08c3,0x05d209f2,
0x4669e330,0xfaa408df,0x08aa1062,0x14591910,0xd4ceffc8,0xf6220912,0x05f5fcca,0x02edfade,
0xedde00bb,0x22bbe865,0xdbf9b09d,0xf9b31895,0x5219598e,0x152328fb,0x0a8643c0,0xe3e84102,
0x0a77be92,0xea8af3df,0x05181ded,0x1d79ec52,0x17612730,0x2056fad4,0xfd1af8a0,0x46e0da95,
0xe3d9fffa,0xf9fe023f,0x03da03d0,0xb02be344,0xe0e2fcd9,0xf5c3e6eb,0xe6b1de19,0xdbc9e163,
0x14c8cce9,0xc55599c4,0xe9f50566,0x3c544199,0x01fb2258,0xf2f930dd,0xcb9f23ec,0xfc9fafd8,
0xea16e5bf,0x0e1e1d8d,0x24d3f7b3,0x1cb232a8,0x2e740813,0x062f17bc,0x5a03ddd0,0xf5980ebf,
0x10201a00,0x1a071a8f,0xd2db03b4,0xf4851496,0x0ff5fa6a,0x026af753,0xea67065f,0x27b1e13f,
0xdff09f33,0xeaec1537,0x4b3e5395,0x07562306,0x08e24b09,0xdf1c2c6a,0x0a06b815,0xe9d5ea2a,
0x026a16f8,0x17dde4f5,0x16a72ed6,0x18d9ef94,0xf59f02c0,0x494ede5d,0xe8c7fe6a,0x0107f980,
0xf568115b,0xb792e328,0xd9ceffd7,0xf941ee40,0xe8c7d453,0xd06aec2a,0x14a5d1ec,0xd50687c5,
0xdb8f03f1,0x406840d4,0xf87f1ead,0xf1823cdd,0xcbb11830,0x0008aa0c,0xe9d0dc6a,0x0a36179b,
0x1ffef235,0x1ad33541,0x2a10fa93,0xfb3e12f8,0x4ef7e541,0xfa170540,0x0e4e04f2,0x08362387,
0xd45ff937,0xeb3a0ceb,0x021c0325,0xfebaf425,0xeb17fe8d,0x1ed5d8a2,0xdc729ec2,0xed280680,
0x3ded4c05,0xff6629f2,0x0ad54c83,0xdb4824f7,0x09d1be9b,0xf203dffd,0xfa1a11be,0x1c6ee7e7,
0x18c52531,0x09f4e91d,0xf0b3121b,0x500cdbd8,0xe7e2f969,0x08b2fa7f,0xeb1f15c7,0xbe76e080,
0xdd57fe19,0xec69f5b3,0xe507dedd,0xdc0aec94,0x0aeec9e4,0xd6a0946c,0xe8bff5e8,0x40de3d55,
0xf1612a1d,0xfbb54474,0xcc181351,0x0118b45a,0xf98ddacf,0x0ab9169a,0x267bff3d,0x3117308f,
0x1fc9fb11,0x035a295b,0x5f30e799,0xfd130cf5,0x1e060de4,0x0d1b2f59,0xe47af824,0xebc71bde,
0x0602158f,0x0980fb04,0xea280bab,0x2479e397,0xe12ea186,0xf6370a24,0x441e476f,0xf81f3507,
0x11215984,0xe46d1ff7,0x06b2c0ec,0xf9fee977,0x0497032c,0x1fbae938,0x1afe26d6,0x0a4fe3de,
0xf4191a8f,0x4f4ae3c7,0xf1f3f935,0x0fdfff9d,0xec4b1e4f,0xd6ddd756,0xdba0066e,0xf03d057c,
0xf46ee023,0xd4e5fee8,0x0eb0d9fc,0xdc819b41,0xf2c0f99e,0x472941b2,0xec063433,0x08ec5239,
0xd4530b8f,0x0070b69e,0xfb8fe269,0x14840b85,0x203bf56d,0x2abb3626,0x1ec3ef28,0xfbfb2441,
0x5019ecc3,0xf7e50b41,0x2432fde7,0xfb2a273a,0xe794ed4c,0xe9100ddf,0xf6e90e62,0x00d2ff72,
0xe4e103f3,0x0e08e6a2,0xdbdda3e4,0xf80bfcca,0x3a8a3c73,0xea92363d,0x1750552a,0xd29f13ff,
0x0279c86f,0xff81ddcd,0x0369f0a7,0x1353ead3,0x1d3d1dfa,0x0536d127,0xf58115db,0x3e93dc35,
0xea2ffeea,0x19aaf313,0xddda1112,0xd859d65a,0xdef4fc3a,0xdb8a01a8,0xed41ee63,0xd2fff7f7,
0xfda0d843,0xd18fa07d,0xf5caf127,0x3dc538dd,0xe24835c2,0x0f61550f,0xc4bbfe2b,0xf467c938,
0x06dbd8b9,0x1055ff0b,0x1f2df79c,0x379b2b2d,0x1c9be188,0xf9f9287a,0x4f9defc4,0xfafd0aaa,
0x2a42fce0,0xf6e929fc,0xf75de6bd,0xe8210c93,0xf3e11780,0xfedd0533,0xe67c0c79,0x0488e99d,
0xdaf0af2f,0xfe85feae,0x42c0351e,0xe5db358d,0x171666a8,0xd4d60acb,0xfdeed53b,0x02a9e05f,
0x0b97ed92,0x1326eb56,0x24a91f83,0x0a2cc472,0xf3b419c1,0x3af7e1e1,0xee2cff5e,0x1e8cefad,
0xd898115e,0xe72fcfea,0xdf75f708,0xd2ea089e,0xeb1cf4c7,0xd3d2fb71,0xf16ed9ce,0xcc82ace4,
0xfc9af059,0x3f022f48,0xe0a638a4,0x0e8d5d8d,0xc8bff5a9,0xed30d1ce,0x0b0fd9bd,0x1588f829,
0x1e9df831,0x3af729bf,0x1ebcd797,0xfbec2ae1,0x4a72f1cb,0xfbc40ea4,0x3409f88e,0xf139252e,
0x048ae2d0,0xec1304cc,0xec641b89,0xfced0b1b,0xe7940feb,0xf694eabf,0xd521bce6,0x042dfdd5,
0x44e52b5a,0xe2b23895,0x17af6db6,0xd96901c6,0xf7a6dc58,0x076fe2b4,0x100ae58a,0x1142ebff,
0x25ca2077,0x0da0bbec,0xf680193e,0x343be638,0xee720428,0x286bec75,0xd25d0b4e,0xf34dceb9,
0xe3a1eeee,0xcf7b09ea,0xea11f9f2,0xd4d3fef9,0xe580d9e5,0xc4b4bb2d,0x00cff10e,0x3e042756,
0xded63c54,0x0ec26411,0xce40ed7e,0xe72ad7b1,0x0e95dea6,0x1970ee93,0x1ca5f98d,0x3a0f2aee,
0x229dcedc,0xff6d2aee,0x43a8f462,0xfb7613ab,0x3c13f70a,0xeab71ed0,0x0ccde509,0xf010fd82,
0xeb561af7,0xfcd10e9c,0xea6411e3,0xeabae99b,0xcca3cb60,0x0759fef9,0x457c23e4,0xe08f3b3d,
0x16ca74a2,0xdef9f8ee,0xf136e2aa,0x0845e9b1,0x140bde3c,0x0ef9ed4e,0x233121c4,0x12feb625,
0xfbe415f7,0x2d4de832,0xedcc0a40,0x2f7ceb1f,0xcc11060e,0xf8bed2bd,0xe7c8e93b,0xcf32098d,
0xeb59fc0a,0xd87dffdc,0xdc0dd6a3,0xbd5bc87e,0x037ff262,0x3e40204c,0xdda03ebc,0x0d7a6a08,
0xd6c4e3b3,0xe08cdce6,0x0bb2e62b,0x1b8eeb15,0x1968fbef,0x36102d50,0x2676ca41,0x051028da,
0x3e3ef4b5,0xfba81752,0x4221f611,0xe4fa193b,0x1025ea11,0xf6f1f80b,0xea6218c5,0xfe32102f,
0xee7011e8,0xe3c7e45c,0xc42ed8dc,0x09a100f5,0x45361ce4,0xe2af3d23,0x158877f1,0xea69ede8,
0xeabfe534,0x03b2f081,0x1470dea6,0x0ba3f134,0x1da123af,0x14c8b5b5,0x02211406,0x28f1e660,
0xede50e5d,0x35b8e9b9,0xc6b6007a,0xfb55d85c,0xf1b9e43d,0xcf0f0446,0xed12fd0b,0xdce0ffb6,
0xd5c0d02b,0xb64dd547,0x0405f538,0x3eb41a4b,0xdff54012,0x0d576b7d,0xe418d92d,0xdc12dc9c,
0x0699ebeb,0x1ab5ed95,0x14610054,0x2ef430cc,0x263ecb1a,0x0a5e2760,0x39f6f499,0xfbf11a64,
0x473af5d2,0xdefc12fb,0x111ff141,0x01e7f3d0,0xecb40fda,0x005e0fe1,0xf228116d,0xe055dc1e,
0xbbc4e569,0x096004c2,0x42d4184e,0xe71d3eda,0x14e977c2,0xf86be49b,0xe68de2ec,0xfed3f72d,
0x12c1e0bf,0x06d3f700,0x14e6269c,0x12a0b979,0x07e814cb,0x24d1e4e9,0xeddb1211,0x38f5eb86,
0xc028fa7f,0xfae6e1fc,0xfc12e091,0xd4ddfa7f,0xf0d2fb2d,0xe14cfe5f,0xd354c7af,0xb0a2def4,
0x0253f882,0x3d9c1638,0xe37641a3,0x0e216ac5,0xf118d0bb,0xd92ad9c9,0xff70f44b,0x18f2ef9c,
0x0f4d0542,0x250d33ca,0x2476d0a4,0x105825ca,0x35a3f3f3,0xfc261d97,0x47c7f887,0xd7e30d75,
0x0e17fcb3,0x09dbf1ad,0xf45a0680,0x05540ceb,0xf6780f36,0xe147d283,0xb641ed02,0x077e07cf,
0x3fe01523,0xed1c3ff2,0x161f74a9,0x0634dc81,0xe4a7dee5,0xf47e01e2,0x0fdae3bf,0x0288fcc0,
0x0b87281b,0x0f82bf7a,0x0e3f151e,0x21a6e2a8,0xedca14bc,0x3833efa1,0xba9df59a,0xf682ed58,
0x029ddf1c,0xdc8df2c2,0xf616f7ef,0xe5dbfbbc,0xd4e5bea4,0xabc9e562,0x00fffa60,0x3bc012f3,
0xea8a424b,0x0f38662a,0xfebfc8fe,0xd925d50d,0xf400fdd2,0x156cf479,0x0a630b25,0x19c634ac,
0x205eda56,0x1702253b,0x325cf0f5,0xfbf920e1,0x4673fbf4,0xd48d0894,0x09140623,0x10dbf11b,
0xfaeefe50,0x0a1809de,0xfa210c9d,0xe41ac915,0xb359f187,0x05d2093a,0x3d7c12c1,0xf43440f0,
0x17df6d72,0x15a6d469,0xe585d8f6,0xeb2b085a,0x0b69e9b9,0xfcae037d,0x011b29ea,0x09d6c993,
0x1260167a,0x1f52e13f,0xedb8165a,0x36e5f29c,0xb9daf2f2,0xf441f175,0x05c2df64,0xdeceef55,
0xf747f716,0xe661fb3e,0xd57fbd1c,0xab95e5d9,0x00fffa6d,0x3b8512e1,0x00004242,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,
};

struct sample_data sample = {
    (int16_t*)soundSample, // sample
    true, // LOOP
    11, // LENGTH_BITS
    (1 << (32 - 11)) * CENTS_SHIFT(-45) * 44100.0 / NOTE(82) / AUDIO_SAMPLE_RATE_EXACT + 0.5, // PER_HERTZ_PHASE_INCREMENT
    ((uint32_t)1390 - 1) << (32 - 11), // MAX_PHASE
    ((uint32_t)1386 - 1) << (32 - 11), // LOOP_PHASE_END
    (((uint32_t)1386 - 1) << (32 - 11)) - (((uint32_t)1294 - 1) << (32 - 11)), // LOOP_PHASE_LENGTH
    uint16_t(UINT16_MAX * DECIBEL_SHIFT(-31.5)), // INITIAL_ATTENUATION_SCALAR
    uint32_t(0.00 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // DELAY_COUNT
    uint32_t(6.20 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // ATTACK_COUNT
    uint32_t(240.09 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // HOLD_COUNT
    uint32_t(11993.38 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // DECAY_COUNT
    uint32_t(1053.97 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // RELEASE_COUNT
    int32_t((1.0 - DECIBEL_SHIFT(-14.9)) * UNITY_GAIN), // SUSTAIN_MULT
    uint32_t(0.00 * SAMPLES_PER_MSEC / (2 * LFO_PERIOD)), // VIBRATO_DELAY
    uint32_t(0.1 * LFO_PERIOD * (UINT32_MAX / AUDIO_SAMPLE_RATE_EXACT)), // VIBRATO_INCREMENT
    (CENTS_SHIFT(0) - 1.0) * 4, // VIBRATO_PITCH_COEFFICIENT_INITIAL
    (1.0 - CENTS_SHIFT(0)) * 4, // VIBRATO_COEFFICIENT_SECONDARY
    uint32_t(0.00 * SAMPLES_PER_MSEC / (2 * LFO_PERIOD)), // MODULATION_DELAY
    uint32_t(5.4 * LFO_PERIOD * (UINT32_MAX / AUDIO_SAMPLE_RATE_EXACT)), // MODULATION_INCREMENT
    (CENTS_SHIFT(0) - 1.0) * 4, // MODULATION_PITCH_COEFFICIENT_INITIAL
    (1.0 - CENTS_SHIFT(0)) * 4, // MODULATION_PITCH_COEFFICIENT_SECOND
    int32_t(UINT16_MAX * (DECIBEL_SHIFT(0) - 1.0)) * 4, // MODULATION_AMPLITUDE_INITIAL_GAIN
    int32_t(UINT16_MAX * (1.0 - DECIBEL_SHIFT(0))) * 4, // MODULATION_AMPLITUDE_FINAL_GAIN
};
