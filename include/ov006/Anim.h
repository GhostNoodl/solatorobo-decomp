#ifndef OV006_ANIM_H
#define OV006_ANIM_H

#include "ov006/ov006.h"
#include "Main/Gfx/FieldMsg.h"
#include "Main/Gfx/GfxMgr.h"

// A plain-struct view of TextWin (Main/Gfx/TextWin.h, 0xb8 bytes) as the overlay 6 menus use it.
typedef struct ov006_Anim {
    void *vtbl;
    u32 unk4;
    u8 unk8[0x1c];
    int unk24;
    int unk28;
    int unk2C;
    u8 unk30[4];
    u16 unk34;
    u8 unk36;
    s8 unk37;
    int unk38;
    u8 unk3C[8];
    u8 unk44[4];
    u8 unk48[4];
    int unk4C;
} ov006_Anim;

/* Owns an anim at 0x28. */
typedef struct ov006_AnimHolder {
    u8 unk0[0x28];
    ov006_Anim *unk28;
} ov006_AnimHolder;

#ifdef __cplusplus
extern "C" {
#endif

void func_0204ca14(ov006_Anim *a, int b);

#ifdef __cplusplus
}
#endif

static inline void ov006_Anim_Start(ov006_Anim *s, int a) {
    s->unk24 = a;
    s->unk4C = func_0204c4fc(s->unk28, s->unk38, s->unk24, (u32 *)s->unk44, (u32 *)s->unk48, s->unk37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = s->unk28;
}

static inline void ov006_AnimHolder_Play(ov006_AnimHolder *self, int a, int b) {
    if (self->unk28 == NULL) {
        return;
    }
    VCALL(self->unk28, 08);
    self->unk28->unk28 = 7;
    self->unk28->unk2C = b;
    self->unk28->unk34 = 0;
    ov006_Anim_Start(self->unk28, a);
    func_0204ca14(self->unk28, 0x10);
    self->unk28->unk4 |= 4;
}

#endif
