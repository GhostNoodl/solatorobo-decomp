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

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void func_02049564(void *p, s32 a, s32 b);

typedef struct {
    u8 pad_00[8];
    s32 unk_08;
    void (*unk_0c)(void);
    s32 unk_10;
} Data021ccd50;

extern Data021ccd50 data_ov000_021ccd50;

s32 func_ov000_021878c8(CmdObj *self) {
    if (data_ov000_021ccd50.unk_0c != NULL) {
        data_ov000_021ccd50.unk_0c();
    }
    data_ov000_021ccd50.unk_0c = NULL;
    data_ov000_021ccd50.unk_08 = 0;
    data_ov000_021ccd50.unk_10 = 0;
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
    CmdObj_Done(self);
    return 0;
}

}
