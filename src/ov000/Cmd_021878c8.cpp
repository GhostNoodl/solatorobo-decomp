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
    s32 unk_08;
    void (*unk_0c)(void);
    s32 unk_10;
} Data021ccd50;

// Read through a plain address: the ROM has no relocation for 0x02070edc.
typedef struct {
    s32 a;
    s32 b;
} Pair02070edc;

typedef struct {
    s32 state;
    u8 pad_04[0xc];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 rd;
    s32 index;
    s32 unk_98;
    Pair02070edc unk_9c;
    u16 unk_a4;
    u16 unk_a6;
    u16 unk_a8;
} Obj021878c8;

extern Data021ccd50 data_ov000_021ccd50;

s32 func_ov000_021878c8(Obj021878c8 *self) {
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
    CmdQueue_Push((CmdQueue *)self, 0x26, 2);
    CmdQueue_Push((CmdQueue *)self, 0x21, 1);
    {
        const Pair02070edc *c = (const Pair02070edc *)0x02070edc;
        s32 a = c->a;
        s32 b = c->b;
        s32 i = self->rd;
        self->unk_9c.b = b;
        self->unk_9c.a = a;
        self->unk_98 = 0;
        self->unk_a4 = 0;
        self->unk_a6 = 0;
        self->unk_a8 = 0;
        self->kinds[i] = 0;
    }
    self->args[self->rd] = 0;
    if (++self->rd >= 0x10) {
        self->rd = 0;
    }
    self->state = 5;
    return 0;
}

}
