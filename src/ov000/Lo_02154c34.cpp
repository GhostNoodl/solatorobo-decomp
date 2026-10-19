#include "ov000/LoCommon.h"

typedef struct Ent02154c34 {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    VObj *unk_1c;
    VObj *unk_20;
    u32 unk_24;
    u32 unk_28;
    struct Ent02154c34 *next;
} Ent02154c34;

typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    void *model;
} Obj02154c34Sub;

extern "C" {

static inline void Ent02154c34_Dtor(Ent02154c34 *e) {
    LO_FREE_V(e, 0x1c);
    LO_FREE_V(e, 0x20);
    e->unk_00 = 0;
    e->unk_04 = 0;
    e->unk_06 = 0;
    e->unk_08 = 0xffff;
    e->unk_0a = 0xffff;
    e->unk_0c = 0;
    e->unk_10 = 0;
    e->unk_14 = 0;
    e->unk_18 = 0;
    e->unk_1c = NULL;
    e->unk_20 = NULL;
    e->unk_24 = 0;
    e->unk_28 = 0;
    e->next = NULL;
}

static inline void Sub02154c34_Dtor(Obj02154c34Sub *s) {
    LO_FREE_M(s, 0x28);
    s->unk_00 = 0;
    s->unk_04 = 0;
    s->unk_08 = 0;
    s->unk_0c = 0;
    s->unk_1c = 0;
    s->unk_18 = 0;
    s->unk_10 = 0x80000;
    s->unk_14 = 0xf000;
    s->unk_20 = 0;
    s->unk_24 = 0;
    s->model = NULL;
}

void func_ov000_02154c34(void *self) {
    Ent02154c34 *e = LFLD(Ent02154c34 *, self, 0x94);
    while (e != NULL) {
        Ent02154c34 *next = e->next;
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (e != NULL) {
            Ent02154c34 *p = e;
            if (p != NULL) {
                Ent02154c34_Dtor(p);
                func_0203de1c(p);
            }
            e = NULL;
        }
        LO_HEAP_POP(saved);
        e = next;
    }
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (LFLD(Obj02154c34Sub *, self, 0xac) != NULL) {
            Obj02154c34Sub *p = LFLD(Obj02154c34Sub *, self, 0xac);
            if (p != NULL) {
                Sub02154c34_Dtor(p);
                func_0203de1c(p);
            }
            LFLD(Obj02154c34Sub *, self, 0xac) = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_M(self, 0xb8);
    LO_FREE_M(self, 0xbc);
    LO_FREE_M(self, 0xb4);
}

}
