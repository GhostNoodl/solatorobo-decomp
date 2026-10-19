#include "Main/Gfx/Obj3D.h"

extern "C" {

extern int func_02043d48(void *obj);
extern s8 data_02149ef4;

void func_02051f3c(Obj3DLayer *layer, u32 v);

void func_020520fc(Obj3DRender *render) {
    GfxSys *sys;
    s32 limit;
    u32 attr;
    u32 alpha;
    Obj3DMtl *mtl;
    mtl = render->mtl;
    attr = mtl->polyAttr;
    alpha = (attr & 0x1f0000) >> 16;
    limit = data_02149ef4;
    sys = data_02097d48;
    if ((u32)limit < alpha) {
        alpha = limit;
    }
    if (alpha > 30) {
        alpha = 30;
    }
    mtl->polyAttr = (attr & 0xc0e0ffbf) | 0xc0 | (alpha << 16) | (func_02043d48(sys->unk_8b0) << 24);
}

void func_02052160(Obj3DRender *render) {
    render->callback = func_020520fc;
    render->callbackMode = 2;
}

typedef struct Obj3DAnimSlot {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ u16 idx;
    /* 0x0a */ u8 unk_0a[0x42];
} Obj3DAnimSlot; // size 0x4c

typedef struct Obj3DAnimGroup {
    /* 0x000 */ u8 unk_000[0x44];
    /* 0x044 */ Obj3DAnimSlot slots[3];
    /* 0x128 */ u8 unk_128[0x20];
} Obj3DAnimGroup; // size 0x148

typedef struct Obj3DAnim {
    /* 0x000 */ u8 unk_000[0xb8];
    /* 0x0b8 */ u32 unk_b8_0 : 9;
    /* 0x0b8 */ u32 hasExtra : 1;
    /* 0x0b8 */ u32 unk_b8_10 : 22;
    /* 0x0bc */ struct {
        /* 0x000 */ u8 unk_000[0x368];
        /* 0x368 */ Obj3DAnimSlot extra[2];
        /* 0x400 */ Obj3DAnimGroup groups[5];
    } sub;
} Obj3DAnim;

void func_0205221c(Obj3DAnim *anim, int kind, Obj3DAnimSlot *slot);

void func_02052178(Obj3DAnim *anim) {
    Obj3DAnimGroup *g;
    int i;
    int j;
    if (anim->hasExtra == 1) {
        func_0205221c(anim, 1, &anim->sub.extra[0]);
    }
    for (i = 0; i < 3; i++) {
        g = anim->sub.groups;
        for (j = 0; j < 5; j++, g++) {
            Obj3DAnimSlot *slot = &g->slots[i];
            slot->idx = j;
            func_0205221c(anim, i, slot);
        }
    }
    if (anim->hasExtra == 1) {
        func_0205221c(anim, 2, &anim->sub.extra[1]);
    }

}

s32 func_020534c4(s32 x);

s32 func_020534d4(void);

}
