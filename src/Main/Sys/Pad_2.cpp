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

u16 func_0203d434(Pad *pad, const u16 *table) {
    if (table == NULL) {
        table = data_02082864;
    }
    return table[(u16)(((u32)pad->cur >> 4) & 0xf)];
}

}
