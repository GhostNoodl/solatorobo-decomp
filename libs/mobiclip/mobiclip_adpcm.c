#include "types.h"

// IMA ADPCM decoder of the Mobiclip SDK.

typedef struct MoAdpcmState {
    /* 0x0 */ int predictor;
    /* 0x4 */ int index;
} MoAdpcmState;

// dsd finds no relocations to these tables, so symbols.txt names them by hand.
extern const s8 data_020826d4[16];
extern const s16 data_020826e4[89];

void func_020349dc(MoAdpcmState *state, const u8 *header) {
    int index = header[0];
    state->predictor = *(s16 *)(header + 2);
    state->index = index;
}

#define ADPCM_DECODE_NIBBLE(state, nibble)                    \
    {                                                         \
        int step = data_020826e4[(state)->index];             \
        int diff;                                             \
        (state)->index += data_020826d4[(nibble) & 7];        \
        if ((state)->index < 0) {                             \
            (state)->index = 0;                               \
        }                                                     \
        if ((state)->index > 88) {                            \
            (state)->index = 88;                              \
        }                                                     \
        diff = step >> 3;                                     \
        if ((nibble) & 4) {                                   \
            diff += step;                                     \
        }                                                     \
        if ((nibble) & 2) {                                   \
            diff += step >> 1;                                \
        }                                                     \
        if ((nibble) & 1) {                                   \
            diff += step >> 2;                                \
        }                                                     \
        if ((nibble) & 8) {                                   \
            (state)->predictor -= diff;                       \
        } else {                                              \
            (state)->predictor += diff;                       \
        }                                                     \
        if ((state)->predictor < -0x8000) {                   \
            (state)->predictor = -0x8000;                     \
        }                                                     \
        if ((state)->predictor > 0x7fff) {                    \
            (state)->predictor = 0x7fff;                      \
        }                                                     \
    }

void func_020349ec(MoAdpcmState *state, const u8 *src, int count, u32 *dst) {
    int i;
    for (i = 0; i < count; i++) {
        int nibble = src[i];
        int first;
        ADPCM_DECODE_NIBBLE(state, nibble);
        nibble >>= 4;
        first = state->predictor;
        ADPCM_DECODE_NIBBLE(state, nibble);
        *dst++ = (u16)first | (state->predictor << 16);
    }
}
