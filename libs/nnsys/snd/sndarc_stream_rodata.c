// The IMA ADPCM tables of the stream decoder in sndarc_stream_3.c: the step-index change for
// each 4-bit code and the 89 quantiser step sizes. Written as asm blocks so they land in main's
// .text with the other read-only data (see libs/msl/ctype.c).

#define E2(a, b) ((a) | ((b) << 16))
#define B4(a, b, c, d) ((a) | ((b) << 8) | ((c) << 16) | ((d) << 24))

#pragma force_active on

// static const s8 IndexTable[16]
void data_0207574c(void);
// static const s16 StepTable[89]
void data_0207575c(void);

asm void data_0207574c(void) {
    dcd B4(-1 & 0xff, -1 & 0xff, -1 & 0xff, -1 & 0xff)
    dcd B4(2, 4, 6, 8)
    dcd B4(-1 & 0xff, -1 & 0xff, -1 & 0xff, -1 & 0xff)
    dcd B4(2, 4, 6, 8)
}

asm void data_0207575c(void) {
    dcd E2(7, 8)
    dcd E2(9, 10)
    dcd E2(11, 12)
    dcd E2(13, 14)
    dcd E2(16, 17)
    dcd E2(19, 21)
    dcd E2(23, 25)
    dcd E2(28, 31)
    dcd E2(34, 37)
    dcd E2(41, 45)
    dcd E2(50, 55)
    dcd E2(60, 66)
    dcd E2(73, 80)
    dcd E2(88, 97)
    dcd E2(107, 118)
    dcd E2(130, 143)
    dcd E2(157, 173)
    dcd E2(190, 209)
    dcd E2(230, 253)
    dcd E2(279, 307)
    dcd E2(337, 371)
    dcd E2(408, 449)
    dcd E2(494, 544)
    dcd E2(598, 658)
    dcd E2(724, 796)
    dcd E2(876, 963)
    dcd E2(1060, 1166)
    dcd E2(1282, 1411)
    dcd E2(1552, 1707)
    dcd E2(1878, 2066)
    dcd E2(2272, 2499)
    dcd E2(2749, 3024)
    dcd E2(3327, 3660)
    dcd E2(4026, 4428)
    dcd E2(4871, 5358)
    dcd E2(5894, 6484)
    dcd E2(7132, 7845)
    dcd E2(8630, 9493)
    dcd E2(10442, 11487)
    dcd E2(12635, 13899)
    dcd E2(15289, 16818)
    dcd E2(18500, 20350)
    dcd E2(22385, 24623)
    dcd E2(27086, 29794)
    dcd 32767 // and the padding to the next word
}

#pragma force_active reset
