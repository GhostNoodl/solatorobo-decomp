#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern u8 *data_ov000_021ccd54;

typedef struct {
    u8 c[3];
} Rgb0218b4b4;


typedef struct {
    u8 b0 : 5;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} Bits0218b4b4;

typedef struct {
    u16 unk_00;
    u16 unk_02;
    s16 unk_04[4];
    s16 unk_0c;
    Rgb0218b4b4 rgb;
    u8 pad_11;
    u16 unk_12, unk_14, unk_16;
    s32 unk_18, unk_1c, unk_20;
} Slot0218b4b4;

typedef struct {
    u8 pad_00[0xc];
    u16 id;
    u16 unk_0e;
    u8 pad_10[8];
    s16 unk_18[4];
    u8 pad_20[2];
    s16 unk_22;
    u8 pad_24[0x4c];
    s32 unk_70, unk_74, unk_78;
    u16 unk_7c, unk_7e, unk_80;
} Src0218b4b4;

void func_ov000_0218b4b4(u8 *self, s32 mode, Src0218b4b4 *src) {
    Slot0218b4b4 *slot = NULL;
    Slot0218b4b4 *e = (Slot0218b4b4 *)(self + 0xc);
    BOOL flag = LFLD(Bits0218b4b4, self, 0xa2).b5;
    s32 i;

    u8 *m;
    for (i = 0; i < self[0xb]; i++, e = (Slot0218b4b4 *)((u8 *)e + 0x24)) {
        if (e->unk_02 == src->id) {
            slot = e;
            break;
        }
    }
    if (slot == NULL) {
        return;
    }
    switch (mode) {
    case 0:
        slot->unk_02 = 0xffff;
        slot->unk_00 = 0xffff;
        return;
    case 2:
        if (!LFLD(Bits0218b4b4, self, 0xa2).b6) {
            flag = TRUE;
        }
    case 1:
        slot->unk_02 &= 0xf000;
        slot->unk_00 = src->unk_0e;
        if (!flag) {
            slot->unk_18 = src->unk_70;
            slot->unk_1c = src->unk_74;
            slot->unk_20 = src->unk_78;
            slot->unk_12 = src->unk_7c;
            slot->unk_14 = src->unk_7e;
            slot->unk_16 = src->unk_80;
            if (mode == 2) {
                slot->rgb = LFLD(Rgb0218b4b4, data_ov000_021ccd54, 0xd0);
            } else {
                slot->rgb = LFLD(Rgb0218b4b4, data_ov000_021ccd54, 0xca);
            }
        }
        for (i = 0; i < 4; i++) {
            slot->unk_04[i] = src->unk_18[i];
        }
        slot->unk_0c = src->unk_22;
        break;
    }
}
}
