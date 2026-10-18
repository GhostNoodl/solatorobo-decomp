#include "ov011/ov011.h"

class Ov011Bar {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();

    u8 unk_04[8];
    u32 flags;
    u8 unk_10[0xc];
    s32 unk_1c;
    u8 unk_20[0x28];
    u16 unk_48;
    u8 unk_4a[0xa];
    s32 unk_54;
    u8 unk_58[0x10];
    s16 unk_68;
};

struct Ov011BarSnd {
    u8 unk_00[0x16];
    u16 unk_16;
};

extern "C" {

extern int data_02097d78[];
extern void *data_ov000_021cac60[];
extern void *data_ov000_021cad50[];
extern void *data_02149ef8;
extern const char *func_0204c0e8(void *mgr, s32 id);
extern void func_ov000_0215c1bc(void *a, s32 b, const char *c);
extern void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);
extern Ov011BarSnd *func_ov000_0218e4cc(void *mgr, u16 id);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02198360(void *a, s32 b, s32 c);

static inline BOOL Ov011Bar_FadeIdle(void) {
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline void Ov011Bar_Init(Ov011Bar *b) {
    b->flags |= 8;
    b->unk_48 = 0x14a5;
    b->unk_54 = 0x1c;
}

#pragma force_active on
void func_ov011_022051ec(Ov011Actor *self) {
    if (FLD(u8, self, 0x394) != 0) {
        Ov011Bar *b;
        if (!Ov011Bar_FadeIdle()) {
            return;
        }
        if (FLD(Ov011Bar *, self, 0x398) == NULL) {
            b = (Ov011Bar *)func_0203dd9c(0xe8);
            if (b != NULL) {
                *(void ***)b = data_ov000_021cac60;
                b->v28();
                *(void ***)b = data_ov000_021cad50;
                b->v28();
            }
            FLD(Ov011Bar *, self, 0x398) = b;
            b->flags |= 0x10000;
            Ov011Bar_Init(FLD(Ov011Bar *, self, 0x398));
            FLD(Ov011Bar *, self, 0x398)->flags |= 0x20000;
            FLD(Ov011Bar *, self, 0x398)->unk_1c = 4;
            FLD(Ov011Bar *, self, 0x398)->v08();
            func_ov000_0215c1bc(FLD(Ov011Bar *, self, 0x398), 0x8000, func_0204c0e8(data_02149ef8, 0x76));
            FLD(Ov011Bar *, self, 0x398)->unk_68 = -0x299a;
            FLD(Ov011Bar *, self, 0x398)->v70();
            func_ov000_02188140(data_ov000_021ccd54, 0xffff, 0, 0);
        } else {
            FLD(Ov011Bar *, self, 0x398)->v1c();
            FLD(Ov011Bar *, self, 0x398)->v20();
        }
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        if (func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000)->unk_16 > 1) {
            Ov011Sub40 *w = self->unk_40;
            w->timer++;
            if (w->timer <= 900) {
                return;
            }
        }
        {
            Ov011Game54 *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = data_ov000_021ccd54;
            FLD(u8, g, 0xac) = 1;
            func_ov000_02182590((u8 *)g + 0xac);
            self->unk_40->state++;
            self->unk_40->timer = 0;
        }
        break;
    case 1:
        if (Ov011_GameIdle()) {
            func_ov000_02198360(self->unk_40, 0x21, 0);
        }
        break;
    }
}
#pragma force_active reset
}
