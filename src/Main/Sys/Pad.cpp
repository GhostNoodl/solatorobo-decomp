#include "Main/Res/ResMgr.h"

extern "C" {

#define PAD_KEY_MASK 0x2fff

typedef struct Pad {
    /* 0x00 */ u8 repeatDelay;
    /* 0x01 */ u8 repeatRate;
    /* 0x02 */ u8 counters[12];
    /* 0x0e */ u16 prev;
    /* 0x10 */ u16 cur;
    /* 0x12 */ u16 trig;
    /* 0x14 */ u16 release;
    /* 0x16 */ u16 repeat;
    /* 0x18 */ u16 forced;
    /* 0x1a */ u8 useForced;
} Pad; // size 0x1c

extern Pad *data_02097dc8;
extern const u16 data_02082864[16];
extern void *func_0203dd9c(u32 size);

static inline u16 PAD_Read(void) {
    return (u16)(((*(volatile u16 *)0x4000130 | *(volatile u16 *)0x2ffffa8) ^ PAD_KEY_MASK) & PAD_KEY_MASK);
}

static inline BOOL PAD_DetectFold(void) {
    return (*(volatile u16 *)0x2ffffa8 & 0x8000) >> 15;
}

static inline u16 Pad_ReadFiltered(void) {
    u16 key = PAD_Read();
    return key & ~((key & 0x40) << 1) & ~((key & 0x20) >> 1);
}

void func_0203d1b4(void) {
    Pad *pad;
    int i;
    if (data_02097dc8 != NULL) {
        return;
    }
    data_02097dd0->cur = data_02097dd0->unk_04;
    pad = (Pad *)func_0203dd9c(sizeof(Pad));
    if (pad != NULL) {
        pad->repeatDelay = 12;
        pad->repeatRate = 6;
        for (i = 0; i < 12; i++) {
            pad->counters[i] = 0;
        }
        pad->prev = 0;
        pad->cur = Pad_ReadFiltered();
        pad->trig = 0;
        pad->release = 0;
        pad->repeat = 0;
        pad->forced = 0;
        pad->useForced = 0;
    }
    data_02097dc8 = pad;
    data_02097dd0->cur = data_02097dd0->unk_08;
}

void func_0203d298(Pad *pad) {
    u16 bit;
    int i;
    pad->prev = pad->cur;
    if (pad->useForced) {
        int j;
        pad->cur = pad->forced;
        for (j = 0; j < 12; j++) {
            pad->counters[j] = 0;
        }
        pad->useForced = 0;
    } else if (PAD_DetectFold()) {
        pad->cur = 0;
        pad->prev = 0;
    } else {
        pad->cur = Pad_ReadFiltered();
    }
    if ((pad->cur & 0xc0) == 0xc0) {
        pad->cur &= ~0xc0;
    }
    if ((pad->cur & 0x30) == 0x30) {
        pad->cur &= ~0x30;
    }
    pad->trig = pad->cur;
    pad->trig &= (u16)~pad->prev;
    pad->release = pad->prev;
    pad->release &= (u16)~pad->cur;
    pad->repeat = 0;
    for (i = 0, bit = 1; i < 12; bit <<= 1, i++) {
        if (!(pad->cur & bit)) {
            pad->counters[i] = 0;
        } else {
            u8 n = ++pad->counters[i];
            if (n >= pad->repeatDelay) {
                u8 d = n - pad->repeatDelay;
                if (d == 0 || d >= pad->repeatRate) {
                    pad->repeat |= bit;
                    pad->counters[i] = pad->repeatDelay;
                }
            } else if (n == 1) {
                pad->repeat |= bit;
            }
        }
    }
}

}
