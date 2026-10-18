#include "ov002/ov002.h"

extern "C" {

extern VFunc data_0208ba70[];

void func_0204c7d0(void *p);

static inline void setVec3(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov002_021e2754(void *self, u16 id) {
    if (FIELD(self, 0x28, void *) != NULL) {
        if (id == 0xffff) {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(FIELD(self, 0x28, VObject *));
            HEAP_POP(saved);
        }
    } else if (id != 0xffff) {
        s32 i;
        u8 *p;
        void *q;
        p = (u8 *)func_0203dd9c(0x2c);
        if (p != NULL) {
            *(VFunc **)p = data_ov002_021f000c;
            FIELD(p, 0x4, s32) = 0;
            MIi_CpuClear32(0, p + 0x8, 0x10);
            FIELD(p, 0x18, s32) = 0;
            FIELD(p, 0x1c, s32) = 0;
            FIELD(p, 0x20, s32) = 0;
            FIELD(p, 0x24, u16) = 0xffff;
            FIELD(p, 0x26, u16) = 0xffff;
            FIELD(p, 0x28, u8) = 0;
            FIELD(p, 0x29, u8) = 0;
        }
        FIELD(self, 0x28, u8 *) = p;
        for (i = 0; i < 4; i++) {
            q = func_0203dd9c(0xb8);
            if (q != NULL) {
                *(VFunc **)q = data_0208ba70;
                func_0204c7d0(q);
            }
            ((void **)(p + 0x8))[i] = q;
        }
        q = func_0203dd9c(0xb8);
        if (q != NULL) {
            *(VFunc **)q = data_0208ba70;
            func_0204c7d0(q);
        }
        FIELD(p, 0x4, void *) = q;
        setVec3((Vec3 *)(FIELD(self, 0x28, u8 *) + 0x18), 0, 0x88000, FIELD(FIELD(self, 0x28, u8 *), 0x20, s32));
    }
    if (FIELD(self, 0x28, void *) != NULL) {
        FIELD(FIELD(self, 0x28, void *), 0x24, u16) = id;
    }
}

}
