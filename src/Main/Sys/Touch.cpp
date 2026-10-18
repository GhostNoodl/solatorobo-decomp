#include "types.h"

extern "C" {

typedef struct TouchQuad {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 d;
    /* 0x04 */ u16 b;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 a;
    /* 0x0a */ u16 ad;
    /* 0x0c */ u16 ba;
    /* 0x0e */ u16 unk_0e;
    /* 0x10 */ u16 c;
    /* 0x12 */ u16 dc;
    /* 0x14 */ u16 cb;
} TouchQuad;

typedef struct Touch {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0c */ u32 unk_0c;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ u32 unk_1c;
    /* 0x20 */ u16 unk_20;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u32 unk_28;
    /* 0x2c */ u32 unk_2c;
} Touch; // size 0x30

extern Touch *data_02097dcc;
extern void TP_Init(void);
extern void TP_GetUserInfo(void *calib);
extern void TP_SetCalibrateParam(void *calib);
extern void *func_0203dec8(u32 size, int align);
extern void func_02021b9c(void);

void func_0203d45c(TouchQuad *q, u16 a, u16 b, u16 c, u16 d) {
    q->ad = (u16)(a - d) >> 1;
    q->ba = (u16)(b - a) >> 1;
    q->dc = (u16)(d - c) >> 1;
    q->cb = (u16)(c - b) >> 1;
    q->a = a;
    q->b = b;
    q->c = c;
    q->d = d;
    q->ad += d;
    q->ba += a;
    q->dc += c;
    q->cb += b;
}

void func_0203d4f8(Touch *tp) {
    tp->unk_00 = 0;
    tp->unk_04 = 12;
    tp->unk_05 = 6;
    tp->unk_06 = 0;
    tp->unk_07 = 4;
    tp->unk_08 = 8;
    tp->unk_09 = 0;
    tp->unk_0c = 0;
    tp->unk_10 = 0;
    tp->unk_14 = 0;
    tp->unk_18 = 0;
    tp->unk_1c = 0;
    tp->unk_20 = 0;
    tp->unk_22 = 0;
    tp->unk_24 = 0;
    tp->unk_26 = 3;
    tp->unk_28 = 0;
    tp->unk_2c = 0;
}

void func_0203d560(void) {
    u8 calib[8];
    Touch *tp;
    if (data_02097dcc != NULL) {
        return;
    }
    TP_Init();
    TP_GetUserInfo(calib);
    TP_SetCalibrateParam(calib);
    tp = (Touch *)func_0203dec8(sizeof(Touch), 4);
    func_0203d4f8(tp);
    data_02097dcc = tp;
}

void func_0203d5b8(void) {
    func_02021b9c();
}

}
