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
    u8 pad_00[0x118];
    void *unk_118;
} Mgr021ccd30;

extern "C" {
extern s32 data_02097d78[];
extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
extern Mgr021ccd30 *data_ov000_021ccd30;
void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_02049564(void *p, s32 a, s32 b);
void func_ov000_0216f844(void *p, s32 a);

static inline BOOL IsMode0(void) {
    return data_02097d78[3] == 0 && data_02097d78[0] == 0;
}

static inline BOOL IsMode4(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 4;
    }
    return r;
}

s32 func_ov000_02188438(CmdObj *self) {
    switch (self->step) {
    case 0:
        if (IsMode0()) {
            func_0203c9e8(0x3f, -1);
            func_0203cc58(0x1e000, 1, -1);
            if (data_ov000_021ccd30->unk_118 != NULL) {
                func_ov000_0216f844(data_ov000_021ccd30->unk_118, 0);
            }
        }
        self->step++;
        return 0;
    case 1:
        if (IsMode4()) {
            CmdObj_Done(self);
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
            CmdObj_Push(self, 0x21, 0);
            return 0;
        }
        return 1;
    }
    return 0;
}
}
