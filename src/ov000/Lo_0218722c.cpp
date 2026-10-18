#include "ov000/CmdObj.h"
#include "ov000/LoCommon.h"

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
} Ov007Obj021cfc60;

extern "C" {
extern Data021ccd50 data_ov000_021ccd50;
extern Ov007Obj021cfc60 *data_ov007_021cfc60;
void func_ov000_02187114(void);
void func_ov000_02187120(void);
void func_ov000_02187138(void);
void func_ov000_02186ed4(void);

s32 func_ov000_0218722c(CmdObj *self) {
    switch (self->step) {
    case 0:
        data_ov000_021ccd50.unk_0c = func_ov000_02187114;
        data_ov000_021ccd50.unk_08 = func_ov000_02187120;
        data_ov000_021ccd50.unk_10 = func_ov000_02187138;
        func_ov000_02186ed4();
        data_ov007_021cfc60->unk_04 = self->unk_a4;
        self->step++;
        return 0;
    case 1:
        if ((data_ov007_021cfc60->unk_08 == 6 ? TRUE : FALSE)) {
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
