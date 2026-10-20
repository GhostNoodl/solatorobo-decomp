#include "ov002/ov002.h"

typedef struct ov002_Anim021e1148 {
    void *vtbl;
    u32 unk4;
    u8 unk8[0x1c];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 unk30[4];
    u16 unk34;
    u8 unk36;
    s8 unk37;
    s32 unk38;
    u8 unk3C[8];
    u8 unk44[4];
    u8 unk48[4];
    s32 unk4C;
} ov002_Anim021e1148;

typedef struct ov002_Info021e1148 {
    u8 unk0[6];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
} ov002_Info021e1148;

extern "C" {

s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca14(ov002_Anim021e1148 *a, int b);

static inline void ov002_Anim1148_Start(ov002_Anim021e1148 *s, s32 a) {
    s->unk24 = a;
    s->unk4C = func_0204c4fc(s->unk28, s->unk38, s->unk24, s->unk44, s->unk48, s->unk37 != 0 ? TRUE : FALSE);
    FIELD(data_02097ce0, 0x4, s32) = s->unk28;
}

static inline void ov002_Anim1148_Show(ov002_Anim021e1148 *a, s32 text, s32 font, s32 pal) {
    ((VObject *)a)->v0x8();
    a->unk28 = font;
    a->unk2C = pal;
    a->unk34 = 0;
    ov002_Anim1148_Start(a, text);
    func_0204ca14(a, 0xc);
    a->unk4 |= 4;
}

#define SLOT1148(n) (((ov002_Anim021e1148 **)((u8 *)self + 8))[n])

static inline void ov002_Slot1148(void *self, s32 *n, s32 text) {
    if (*n < 4) {
        ov002_Anim021e1148 *a = SLOT1148(*n);
        if (a != NULL) {
            ov002_Anim1148_Show(a, text, 3, 0);
        }
    }
    (*n)++;
}

void func_ov002_021e1148(void *self, u16 id) {
    void *mgr;
    int i;
    ov002_Info021e1148 *info;
    for (i = 0; i < 4; i++) {
        VObject *o = ((VObject **)((u8 *)self + 8))[i];
        if (o != NULL) {
            o->v0x8();
        }
    }
    FIELD(self, 4, VObject *)->v0x8();
    if (id == 0xffff) {
        return;
    }
    info = (ov002_Info021e1148 *)func_0206ef10(id);
    mgr = data_02149ef8;
    if (id == 0x8008) {
        s32 text = (s32)func_0204c0e8(data_02149ef8, 0x15f);
        ov002_Anim021e1148 *a = SLOT1148(0);
        if (a != NULL) {
            ov002_Anim1148_Show(a, text, 3, 0);
        }
    } else {
        s32 n = 0;
        if (info->b0) {
            ov002_Slot1148(self, &n, (s32)func_0204c0e8(data_02149ef8, 0x156));
        }
        if (info->b1) {
            ov002_Slot1148(self, &n, (s32)func_0204c0e8(mgr, 0x157));
        }
        if (info->b2) {
            ov002_Slot1148(self, &n, (s32)func_0204c0e8(mgr, 0x158));
        }
        if (info->b3) {
            ov002_Slot1148(self, &n, (s32)func_0204c0e8(mgr, 0x159));
        }
        if (info->b4) {
            ov002_Slot1148(self, &n, (s32)func_0204c0e8(mgr, 0x15a));
        }
        if (info->b5) {
            ov002_Slot1148(self, &n, (s32)func_0204c0e8(mgr, 0x15b));
        }
        if (info->b6) {
            ov002_Slot1148(self, &n, (s32)func_0204c0e8(mgr, 0x15c));
        }
        if (info->b7) {
            ov002_Slot1148(self, &n, (s32)func_0204c0e8(mgr, 0x15d));
        }
        if (info->b8) {
            ov002_Slot1148(self, &n, (s32)func_0204c0e8(mgr, 0x15e));
        }
    }
    {
        s32 text = (s32)func_0206ec48(id);
        if (FIELD(self, 4, void *) == NULL) {
            return;
        }
        FIELD(self, 4, VObject *)->v0x8();
        FIELD(self, 4, ov002_Anim021e1148 *)->unk28 = 7;
        FIELD(self, 4, ov002_Anim021e1148 *)->unk2C = 4;
        FIELD(self, 4, ov002_Anim021e1148 *)->unk34 = 0;
        ov002_Anim1148_Start(FIELD(self, 4, ov002_Anim021e1148 *), text);
        func_0204ca14(FIELD(self, 4, ov002_Anim021e1148 *), 0xc);
        FIELD(self, 4, ov002_Anim021e1148 *)->unk4 |= 4;
    }
}

}
