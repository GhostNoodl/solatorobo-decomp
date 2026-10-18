#include "ov000/CmdQueue.h"

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
    u8 unk_08;
} Obj0214a424;

extern Obj0214a424 *data_0214a424;
BOOL func_0206c4a0(void);

static inline void Prelude(void) {
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
}

void func_ov000_02182b0c(CmdQueue *self) {
    if (func_0206c4a0()) {
        Prelude();
        CmdQueue_Push(self, 0x26, 2);
        CmdQueue_Push(self, 2, 4);
    } else {
        u8 v = data_0214a424->unk_08;
        Prelude();
        CmdQueue_Push(self, 0x26, 2);
        CmdQueue_Push(self, 2, (v << 16) | 1);
    }
}

}
