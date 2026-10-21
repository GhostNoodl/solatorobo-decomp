#pragma opt_loop_invariants off
#include "ov002/ov002.h"

extern "C" {

typedef struct Ent021dd9dc {
    u16 id;
    u16 x : 3;
    u16 y : 3;
    u16 rot : 2;
    u16 rest : 8;
} Ent021dd9dc;

typedef struct Rot021dd9dc {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Rot021dd9dc;

void func_ov002_021d9ed8(void *w, void *a, int b);
void func_ov002_021d7b80(void *self);
void func_ov002_021d7e54(void *self);
void MTX_RotY33_(void *m, s32 s, s32 c);

static inline void ov002_Piece_SetRot(void *self, u16 rot) {
    FIELD(self, 0x52, Rot021dd9dc).rot = rot;
    switch (rot) {
    case 0:
        FIELD(self, 0x10, s16) = 0;
        FIELD(self, 0x12, s16) = 0;
        FIELD(self, 0x14, s16) = 0;
        MTX_Identity33_((u8 *)self + 0x18);
        break;
    case 1:
        FIELD(self, 0x10, s16) = 0;
        FIELD(self, 0x12, u16) = 0x3fff;
        FIELD(self, 0x14, s16) = 0;
        MTX_Identity33_((u8 *)self + 0x18);
        MTX_RotY33_((u8 *)self + 0x18, FX_SINCOS(0x3ff * 2), FX_SINCOS(0x3ff * 2 + 1));
        break;
    case 2:
        FIELD(self, 0x10, s16) = 0;
        FIELD(self, 0x12, u16) = 0x7fff;
        FIELD(self, 0x14, s16) = 0;
        MTX_Identity33_((u8 *)self + 0x18);
        MTX_RotY33_((u8 *)self + 0x18, FX_SINCOS(0x7ff * 2), FX_SINCOS(0x7ff * 2 + 1));
        break;
    case 3:
        FIELD(self, 0x10, s16) = 0;
        FIELD(self, 0x12, u16) = 0xbffd;
        FIELD(self, 0x14, s16) = 0;
        MTX_Identity33_((u8 *)self + 0x18);
        MTX_RotY33_((u8 *)self + 0x18, FX_SINCOS(0xbff * 2), FX_SINCOS(0xbff * 2 + 1));
        break;
    }
}

static inline void ov002_Board_Add(void *self, void *node) {
    void *p = FIELD(self, 0x6c, void *);
    if (p != NULL) {
        if (p != NULL) {
            void *q;
            do {
                q = FIELD(p, 0x70, void *);
                if (q == NULL) {
                    break;
                }
                p = q;
            } while (p != NULL);
        }
        FIELD(p, 0x70, void *) = node;
        FIELD(node, 0x74, void *) = p;
    } else {
        FIELD(self, 0x6c, void *) = node;
    }
    func_ov002_021da184(self, node);
    if (FIELD(data_0214a424, 0x18, Bits021d9e38).mode == 1) {
        func_ov000_021c9544((u8 *)self + 0x76, FIELD(self, 0x6c, void *));
        func_ov000_021c95ac((u8 *)self + 0x76, FIELD(data_0214a424, 0x18, Bits021d9e38).id | 0x8000);
    } else {
        func_ov000_021c9544((u8 *)self + 0x76, FIELD(self, 0x6c, void *));
    }
}

void func_ov002_021dd9dc(void *self, u8 *w, u8 *obj) {
    Ent021dd9dc *e;
    w = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
    u8 *a;
    u8 *next;
    a = FIELD(w, 0x6c, u8 *);
    if (a != NULL) {
        do {
            next = FIELD(a, 0x70, u8 *);
            if (FIELD(a, 0x4a, u8) == 1) {
                func_ov002_021d9ed8(w, a, 1);
            }
            a = next;
        } while (a != NULL);
    }
    e = (Ent021dd9dc *)((u8 *)data_0214a424 + 0x8e);
    if (e->id != 0xffff) {
        do {
            u16 id = e->id | 0x2000;
            if (func_0206ede8(id)[0] != 0x80) {
            obj = (u8 *)func_0203dd9c(0xd4);
            if (obj != NULL) {
                *(VFunc **)obj = data_ov002_021efeb8;
                func_ov002_021d7b80(obj);
                *(VFunc **)obj = data_ov002_021efe9c;
                func_ov002_021d7e54(obj);
            }
            FIELD(obj, 0x48, u16) = id;
            VC(obj, 0x8)();
            if (FIELD(obj, 0xac, s32) != 2) {
                FIELD(obj, 0xac, s32) = 2;
                FIELD(obj, 0xa4, s32) = 0;
                FIELD(obj, 0xa8, s32) = 5;
            }
            {
                Nibbles16 *d = &FIELD(FIELD(FIELD(w, 0x4, u8 *), 0x6c, u8 *), 0x6, Nibbles16);
                s32 n0 = d->n0;
                s32 n1 = d->n1;
                FIELD(obj, 0x64, s32) = n0;
                FIELD(obj, 0x68, s32) = n1;
            }
            {
                s32 x = e->x;
                s32 y = e->y;
                FIELD(obj, 0x54, s32) = x;
                FIELD(obj, 0x58, s32) = y;
            }
            func_ov002_021e3b0c((s32 *)(obj + 0x4), (s32 *)(obj + 0x54), (s32 *)(obj + 0x64));
            ov002_Piece_SetRot(obj, (u8)e->rot);
            ov002_Board_Add(w, obj);
            }
        } while ((++e)->id != 0xffff);
    }
    MI_CpuCopy8((u8 *)data_0214a424 + 0x2a, w + 0x8, 0x64);
}

}
