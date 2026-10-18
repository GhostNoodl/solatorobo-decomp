#include "ov000/CmdObj.h"

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u8 pad_00[8];
    void (*unk_08)(void);
    void (*unk_0c)(void);
    void (*unk_10)(void);
} Data021ccd50;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
} Ov015Obj02213320;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    u8 pad_08[0xc];
    s32 unk_14;
} Ov006Obj021ec860;

typedef struct {
    u8 pad_00[0x78];
    u16 unk_78;
} Dtcm02fe1534;

extern "C" {
extern Data021ccd50 data_ov000_021ccd50;
extern Ov015Obj02213320 *data_ov015_02213320;
extern Ov006Obj021ec860 *data_ov006_021ec860;
extern Dtcm02fe1534 data_02fe1534;
extern u8 *data_02149ef0;
extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
// Overlay ids, defined by the linker script.
extern u8 OVERLAY_2_ID[];
extern u8 OVERLAY_6_ID[];
extern u8 OVERLAY_15_ID[];
void func_0204b270(void *p, s32 a, s32 b);
void func_02049564(void *p, s32 a, s32 b);
void func_ov015_021fa77c(void);
void func_ov006_021ccf8c(void);
void func_ov000_021860e0(void);
void func_ov000_021860ec(void);
void func_ov000_02186104(void);
void func_ov000_0218611c(void);
void func_ov000_02186128(void);
void func_ov000_02186140(void);

static inline void ClearCallbacks(void) {
    if (data_ov000_021ccd50.unk_0c != NULL) {
        data_ov000_021ccd50.unk_0c();
    }
    data_ov000_021ccd50.unk_0c = NULL;
    data_ov000_021ccd50.unk_08 = NULL;
    data_ov000_021ccd50.unk_10 = NULL;
}

s32 func_ov000_021862b0(CmdObj *self) {
    switch (self->unk_98) {
    case 0x1b:
        if (self->step == 0) {
            data_ov000_021ccd50.unk_0c = func_ov000_021860e0;
            data_ov000_021ccd50.unk_08 = func_ov000_021860ec;
            data_ov000_021ccd50.unk_10 = func_ov000_02186104;
            func_0204b270(data_02149ef0, (s32)OVERLAY_2_ID, 0);
            func_0204b270(data_02149ef0, (s32)OVERLAY_15_ID, 1);
            func_ov015_021fa77c();
            data_ov015_02213320->unk_04 = self->unk_a4;
            self->step++;
            return 0;
        }
        if (data_ov015_02213320->unk_0c == 4) {
            data_02fe1534.unk_78 = data_ov015_02213320->unk_08;
            ClearCallbacks();
            CmdObj_Push(self, 0x26, 0);
            CmdObj_Done(self);
        }
        break;
    case 0x1c:
        if (self->step == 0) {
            data_ov000_021ccd50.unk_0c = func_ov000_0218611c;
            data_ov000_021ccd50.unk_08 = func_ov000_02186128;
            data_ov000_021ccd50.unk_10 = func_ov000_02186140;
            func_0204b270(data_02149ef0, (s32)OVERLAY_6_ID, 0);
            func_ov006_021ccf8c();
            data_ov006_021ec860->unk_14 = self->unk_a4;
            self->step++;
            return 0;
        }
        if (data_ov006_021ec860->unk_04 == 5) {
            ClearCallbacks();
            if (self->unk_a4 == 0) {
                func_02049564(data_02097e4c, 1, 1);
                {
                    Obj02097e48 *p = data_02097e48;
                    if (p->flag) {
                        p->unk_06 = 0x8000;
                        p->unk_08 = 0x1e;
                        p->unk_02 = 0;
                    }
                }
                {
                    Obj02097e48 *p = data_02097e48;
                    p->unk_74 = 0x8000;
                    p->unk_70 = 0;
                }
                CmdObj_Push(self, 0x26, 2);
                CmdObj_Push(self, 0x21, 1);
            } else {
                CmdObj_Push(self, 0x26, 0);
            }
            CmdObj_Done(self);
        }
        break;
    }
    return 0;
}
}
