#include "types.h"

class Ov003Scene {
public:
    virtual void v00();
    virtual void v04();
    virtual void Start(s32 a, s32 b);
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
    virtual void Reset();
};

struct Ov003OamEntry {
    u32 y : 8;
    u32 unk_08 : 8;
    u32 x : 9;
    u32 unk_19 : 7;
    u32 attr2;
};

struct Ov003OamOffset {
    s32 y : 8;
    s32 x : 8;
};

struct Ov003OamOwner {
    u8 unk_00[0x70];
    u32 offsetWord;
};

static inline s32 Ov003_Mod2(s32 v) {
    return v % 2;
}

extern "C" {

extern u8 Task_vtbl[];
extern u8 Ov003TaskVt_021f78f4_vtbl[];
extern u8 Ov003Vt_021f78e4_vtbl[];
extern void *Heap_Alloc(u32 size);
extern void Obj021c2208_Init(void *p);

#pragma force_active on
Ov003Scene *Ov003TaskVt_021f78f4_New(void) {
    Ov003Scene *p = (Ov003Scene *)Heap_Alloc(0xcc);
    if (p != NULL) {
        *(void **)p = Task_vtbl;
        p->Reset();
        *(void **)p = Ov003TaskVt_021f78f4_vtbl;
        *(void **)((u8 *)p + 0x60) = Ov003Vt_021f78e4_vtbl;
        Obj021c2208_Init((u8 *)p + 0x60);
        p->Reset();
    }
    p->Start(0xd, 0xc8);
    return p;
}
#pragma force_active reset

void Ov003Vt_021f78e4_Dtor(void) {
}

Ov003OamEntry *Ov003Oam_Offset(Ov003OamOwner *owner, u16 *flip, Ov003OamEntry *oam, u16 *count) {
    s32 i;
    u16 f = *flip;
    u32 w = owner->offsetWord;
    s32 n = *count;
    s32 dx = (s8)(w >> 8);
    s32 dy = (s8)w;
    if (Ov003_Mod2(f) == 0) {
        dx = -dx;
    }
    if (f < 2) {
        dy = -dy;
    }
    for (i = 0; i < n; i++) {
        oam[i].x += dx;
        oam[i].y += dy;
    }
    return oam;
}

}
