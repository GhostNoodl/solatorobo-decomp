#include "ov000/CmdObj.h"
#include "ov000/LoCommon.h"

typedef struct {
    u8 pad_00[8];
    void (*unk_08)(void);
    void (*unk_0c)(void);
    void (*unk_10)(void);
} Data021ccd50;

typedef struct {
    u8 pad_00[8];
    s32 unk_08;
} Ov002Obj021f0fa4;

extern "C" {
extern Data021ccd50 data_ov000_021ccd50;
extern Ov002Obj021f0fa4 *data_ov002_021f0fa4;
extern u8 *data_02149ef0;
// Overlay id, defined by the linker script.
extern u8 OVERLAY_2_ID[];
extern u8 *data_02097e4c;
void func_0204b270(void *p, s32 a, s32 b);
void func_ov002_021edf98(u32 arg);
void func_ov000_02187350(void);
void func_ov000_0218735c(void);
void func_ov000_02187368(void);


s32 func_ov000_02187420(CmdObj *self) {
    switch (self->step) {
    case 0: {
        func_0204b270(data_02149ef0, (s32)OVERLAY_2_ID, 0);
        func_ov002_021edf98(self->unk_a4);
        data_ov000_021ccd50.unk_0c = func_ov000_02187350;
        data_ov000_021ccd50.unk_08 = func_ov000_0218735c;
        data_ov000_021ccd50.unk_10 = func_ov000_02187368;
        self->step++;
        return 0;
    }
    case 1:
        if ((data_ov002_021f0fa4->unk_08 == 2 ? TRUE : FALSE)) {
            data_02097e4c[0x5b] = 0;
            if (data_ov000_021ccd50.unk_0c != NULL) {
                data_ov000_021ccd50.unk_0c();
            }
            data_ov000_021ccd50.unk_0c = NULL;
            data_ov000_021ccd50.unk_08 = NULL;
            data_ov000_021ccd50.unk_10 = NULL;
            CmdObj_Done(self);
        }
        break;
    }
    return 0;
}
}
