#pragma opt_loop_invariants off
#include "ov002/ov002.h"

extern "C" {

void func_ov002_021da054(void *self);
void func_ov002_021d7b80(void *self);
void func_ov002_021d8e48(void *self);
void func_ov002_021d7e54(void *self);
void MTX_RotY33_(void *m, s32 s, s32 c);

typedef struct {
    u16 x : 3;
    u16 z : 3;
    u16 rot : 2;
    u16 flag : 1;
    u16 rest : 7;
} Info98ac;

typedef struct {
    u16 id;
    Info98ac info;
} Ent98ac;

typedef struct {
    u16 x : 4;
    u16 z : 4;
    u16 rest : 8;
} Size98ac;

typedef struct {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Rot98ac;

static inline void ov002_SetRot(void *self, u8 rot) {
    FIELD(self, 0x52, Rot98ac).rot = rot;
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

static inline void ov002_AddNode(void *self, void *node) {
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

void func_ov002_021d98ac(void *self) {
    int i;
    func_ov002_021d9504(self);
    func_ov002_021da054(self);
    MI_CpuCopy8((u8 *)data_0214a424 + 0x2a, (u8 *)self + 0x8, 0x64);
    for (i = 0; i < 0x25; i++) {
        Ent98ac *e = (Ent98ac *)((u8 *)data_0214a424 + 0x8e) + i;
        u16 id = e->id;
        u8 *n;
        if (id == 0xffff) {
            break;
        }
        if (func_0206ede8(id)[0] == 0x80) {
            n = (u8 *)func_0203dd9c(0xb4);
            if (n != NULL) {
                *(VFunc **)n = data_ov002_021efeb8;
                func_ov002_021d7b80(n);
                *(VFunc **)n = data_ov002_021efed4;
                func_ov002_021d8e48(n);
            }
            FIELD(n, 0x48, u16) = id;
            ((VObject *)n)->v0x8();
            FIELD(n, 0xac, s32) = FIELD(n, 0xa8, u16) <= FIELD(data_0214a424, 0x24, u16) ? 2 : 1;
        } else {
            n = (u8 *)func_0203dd9c(0xd4);
            if (n != NULL) {
                *(VFunc **)n = data_ov002_021efeb8;
                func_ov002_021d7b80(n);
                *(VFunc **)n = data_ov002_021efe9c;
                func_ov002_021d7e54(n);
            }
            FIELD(n, 0x48, u16) = id;
            ((VObject *)n)->v0x8();
            if (e->info.flag) {
                n[0x6c] = 1;
            }
        }
        {
            u8 *m = FIELD(FIELD(self, 0x4, u8 *), 0x6c, u8 *);
            s32 x = FIELD(m, 0x6, Size98ac).x;
            s32 z = FIELD(m, 0x6, Size98ac).z;
            FIELD(n, 0x64, s32) = x;
            FIELD(n, 0x68, s32) = z;
        }
        {
            s32 x = e->info.x;
            s32 z = e->info.z;
            FIELD(n, 0x54, s32) = x;
            FIELD(n, 0x58, s32) = z;
        }
        func_ov002_021e3b0c((s32 *)(n + 0x4), (s32 *)(n + 0x54), (s32 *)(n + 0x64));
        ov002_SetRot(n, e->info.rot);
        ov002_AddNode(self, n);
    }
    FIELD(self, 0x8a, u16) = FIELD(data_0214a424, 0x24, u16);
    if (FIELD(data_0214a424, 0x18, Bits021d9e38).mode == 1) {
        func_ov000_021c9544((u8 *)self + 0x76, FIELD(self, 0x6c, void *));
        func_ov000_021c95ac((u8 *)self + 0x76, FIELD(data_0214a424, 0x18, Bits021d9e38).id | 0x8000);
    } else {
        func_ov000_021c9544((u8 *)self + 0x76, FIELD(self, 0x6c, void *));
    }
}

}
