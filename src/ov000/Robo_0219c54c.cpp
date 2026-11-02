#include "types.h"
#include "Main/Res/StageCmd.h"
#include "nitro/std.h"
#include "ov000/ObjLayouts.h"


extern "C" {
extern RoboDef data_ov000_021ca398[];
extern char data_ov000_021cc5d2[];
extern char data_ov000_021cc5d9[];
void *func_0207011c(u16 id);
s32 func_020701d4(u16 id);
Param0206ef10 *func_0206ef10(u16 id);
void *Heap_Alloc(u32 size);
void *Shadow_Ctor(void *p);
void Shadow_Load(void *s);
void ResSet_SetFile(void *o, void *a, BOOL b, BOOL c, s32 d, BOOL e);

static inline void SetNames0219c54c(char *d0, char *d1, const char *a, const char *b) {
    STD_CopyString(d0, a);
    STD_CopyString(d1, b);
}

void Robo021ca458_Init(Robo021ca458 *self) {
    void *res;
    void *p;
    RoboDef *e;
    u32 kind;

    res = func_0207011c(self->kind);
    func_020701d4(self->kind);
    ResSet_SetFile(&self->res0, res, TRUE, TRUE, 1, FALSE);
    self->res0.unk_00 = 0;
    {
        const char *b = data_ov000_021cc5d2;
        const char *a = data_ov000_021cc5d9;
        if (a != NULL && b != NULL) {
            SetNames0219c54c((char *)self + 0x870, (char *)self + 0x890, a, b);
            self->res3.unk_03_1 = 1;
        }
    }
    self->res3.unk_00 = 0;
    p = Heap_Alloc(0x1c);
    if (p != NULL) {
        p = Shadow_Ctor(p);
    }
    self->unk_3c = (ActorShadow *)p;
    Shadow_Load(p);
    kind = self->unk_b22_6;
    e = &data_ov000_021ca398[kind];
    if ((u16)(kind + 0xfffe) <= 1) {
        Param0206ef10 *x = func_0206ef10(data_0214a424->bits18.unk_3 | 0x8000);
        if (x != NULL) {
            self->unk_ba4 = x;
            e = &x->def;
        }
    }
    self->unk_ba0 = (u8 *) e;
    SetNames0219c54c((char *)self + 0x460, (char *)self + 0x480, e->name[0], e->name[1]);
    self->res1.unk_03_1 = 1;
    SetNames0219c54c((char *)self + 0x49c, (char *)self + 0x4bc, e->name[2], e->name[3]);
    self->res1.unk_03_2 = 1;
    if (e->name[4] != NULL && e->name[5] != NULL) {
        SetNames0219c54c((char *)self + 0x514, (char *)self + 0x534, e->name[4], e->name[5]);
        self->res1.unk_03_4 = 1;
    }
    self->res1.unk_00 = 0;
    if (e->unk_18 == 0) {
        return;
    }
    SetNames0219c54c((char *)self + 0x5d4, (char *)self + 0x5f4, e->name[0], e->name[1]);
    self->res2.unk_03_2 = 1;
    self->res2.unk_00 = 0;
}
}
