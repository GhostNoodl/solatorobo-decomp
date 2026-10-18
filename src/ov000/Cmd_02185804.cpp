#include "ov000/CmdQueue.h"
#include "ov000/Vec.h"

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
    u8 pad_00[0x70];
    VecFx32 pos;
    u16 rot_x;
    u16 rot_y;
} Actor02185804;

Actor02185804 *func_ov000_0219bf90(void);
void func_020626d4(VecFx32 *pos, u16 rot);

void func_ov000_02185804(CmdQueue *self, s32 arg) {
    Actor02185804 *o = func_ov000_0219bf90();
    if (o != NULL) {
        VecFx32 v;
        v.x = o->pos.x;
        v.y = o->pos.y;
        v.z = o->pos.z;
        func_020626d4(&v, o->rot_y);
    }
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
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x15, arg);
}

}
