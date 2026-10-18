#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0x52];
    s32 unk_68;
    u8 unk_6c[4];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u8 unk_7c[0xaac];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
    u8 unk_b28_3 : 5;
} Obj0219bf90;

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Player021975b4;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
} Obj021975b4;

extern "C" {

extern Player021975b4 *data_ov000_021ccd54;
Obj0219bf90 *func_ov000_0219bf90(void);
void func_020627b4(void);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(u8 *p);
s32 func_0205b1fc(void);
VObj *func_02065f88(s32 kind, s32 *pos);
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
extern void *data_02097e4c;

void func_ov000_021974b0(Obj021975b4 *self) {
    Obj0219bf90 *p = func_ov000_0219bf90();
    func_020627b4();
    func_020627a0(self->unk_0e, self->unk_0c);
    func_020627dc(0x8002);
    {
        Player021975b4 *pl = data_ov000_021ccd54;
        pl->unk_ac = 1;
        func_ov000_02182590(&pl->unk_ac);
    }
    if (func_0205b1fc() == 1 && p != NULL && p->unk_b28_0 == 0) {
        p->unk_15 = 3;
        p->unk_b28_0 = 0;
        p->unk_b28_2 = 1;
    }
    if (p == NULL) {
        return;
    }
    {
        s32 pos[3];
        pos[0] = p->unk_70;
        pos[1] = p->unk_74;
        pos[2] = p->unk_78;
        func_02065f88(0x44f, pos)->vfunc_24(0, p->unk_68, 0);
    }
    func_02049a48(data_02097e4c, 0x88, -1, -1, -1);
}

void func_ov000_021975b4(Obj021975b4 *self) {
    Obj0219bf90 *p;
    func_020627b4();
    func_020627a0(self->unk_0e, self->unk_0c);
    func_020627dc(0x8003);
    {
        Player021975b4 *pl = data_ov000_021ccd54;
        pl->unk_ac = 1;
        func_ov000_02182590(&pl->unk_ac);
    }
    if (func_0205b1fc() != 1) {
        return;
    }
    p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    if (p->unk_b28_0 != 0) {
        return;
    }
    p->unk_15 = 3;
    p->unk_b28_0 = 0;
    p->unk_b28_2 = 1;
}

}
