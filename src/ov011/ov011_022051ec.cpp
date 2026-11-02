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

extern void *data_ov000_021cac60[];
extern void *data_ov000_021cad50[];
extern void func_ov000_0215c1bc(void *a, s32 b, const char *c);
extern void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(void *p);

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
void Ov011Act7da4_State20(Ov011Act7da4 *self) {
    if (self->unk_394 != 0) {
        Ov011Bar *b;
        if (!Ov011Bar_FadeIdle()) {
            return;
        }
        if (self->unk_398 == NULL) {
            b = (Ov011Bar *)Heap_Alloc(0xe8);
            if (b != NULL) {
                *(void ***)b = data_ov000_021cac60;
                b->v28();
                *(void ***)b = data_ov000_021cad50;
                b->v28();
            }
            self->unk_398 = b;
            b->flags |= 0x10000;
            Ov011Bar_Init(self->unk_398);
            self->unk_398->flags |= 0x20000;
            self->unk_398->unk_1c = 4;
            self->unk_398->v08();
            func_ov000_0215c1bc(self->unk_398, 0x8000, (char *)MsgRes_GetString(data_02149ef8, 0x76));
            self->unk_398->unk_68 = -0x299a;
            self->unk_398->v70();
            func_ov000_02188140(data_ov000_021ccd54, 0xffff, 0, 0);
        } else {
            self->unk_398->v1c();
            self->unk_398->v20();
        }
        return;
    }
    switch (self->fsm->st) {
    case 0:
        if (((Ov011BarSnd *)ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000))->unk_16 > 1) {
            ActorSub40 *w = self->fsm;
            w->timer++;
            if (w->timer <= 900) {
                return;
            }
        }
        {
            FieldState *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = data_ov000_021ccd54;
            g->stageFlags = 1;
            func_ov000_02182590(&g->stageFlags);
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        break;
    case 1:
        if (Ov011_GameIdle()) {
            func_ov000_02198360(self->fsm, 0x21, 0);
        }
        break;
    }
}
#pragma force_active reset
}
