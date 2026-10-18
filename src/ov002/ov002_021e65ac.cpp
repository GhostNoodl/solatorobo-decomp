#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e6784(void *self);

void func_02040578(void *out, Vec3 *dir);

static inline BOOL ov002_inWindow(s32 t) {
    u8 *g = (u8 *)data_ov002_021f0f98[1];
    BOOL r = FALSE;
    if (t > FIELD(g, 0xd4, s32) && t <= FIELD(g, 0xd0, s32)) {
        r = TRUE;
    }
    return r;
}

BOOL func_ov002_021e65ac(void *self) {
    u8 *g = (u8 *)data_ov002_021f0f98[1];
    s32 now = FIELD(g, 0xd0, s32);
    s32 i;
    if (now > FIELD(self, 0x1c, s32)) {
        return FALSE;
    }
    if (now < FIELD(self, 0x18, s32)) {
        return TRUE;
    }
    if (FIELD(self, 0x18, s32) > FIELD(g, 0xd4, s32) && FIELD(self, 0x18, s32) <= now) {
        func_ov002_021e61b4(FIELD(self, 0x60, void *));
    }
    if (FIELD(self, 0x64, s32) == 1) {
        while (ov002_inWindow(FIELD(self, 0x6c, s32))) {
            func_ov002_021e6784(self);
            FIELD(self, 0x6c, s32) += FIELD(self, 0x68, s32);
        }
    } else if (ov002_inWindow(FIELD(self, 0x18, s32))) {
        func_ov002_021e6784(self);
    }
    for (i = 0; i < 4; i++) {
        VObject *o = func_020657b0(data_0214a420, ((void **)((u8 *)self + 0x50))[i]);
        if (o == NULL) {
            ((void **)((u8 *)self + 0x50))[i] = NULL;
        } else {
            Vec3 dir;
            Vec3 scale;
            Vec3 pos;
            s32 rot[2];
            u8 *m = FIELD(self, 0x60, u8 *);
            pos.x = FIELD(m, 0xdc, s32);
            pos.y = FIELD(m, 0xe0, s32);
            pos.z = FIELD(m, 0xe4, s32);
            scale.x = FIELD(m, 0x94, s32);
            scale.y = FIELD(m, 0x98, s32);
            scale.z = FIELD(m, 0x9c, s32);
            dir.x = 0;
            dir.y = 0;
            dir.z = 0x1000;
            MTX_MultVec33(&dir, m + 0xb8, &dir);
            func_02040578(rot, &dir);
            o->v0x18(&pos);
            o->v0x10(&scale);
            o->v0x30(rot);
        }
    }
    return TRUE;
}

VObject *func_02065f88(void *a, Vec3 *b);

void func_ov002_021e6784(void *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((void **)((u8 *)self + 0x50))[i] == NULL) {
            Vec3 zero;
            Vec3 dir;
            Vec3 scale;
            Vec3 pos;
            s32 rot[2];
            VObject *o;
            u8 *m;
            s32 k;
            zero.x = 0;
            zero.y = 0;
            zero.z = 0;
            o = func_02065f88(FIELD(self, 0x4c, void *), &zero);
            m = FIELD(self, 0x60, u8 *);
            pos.x = FIELD(m, 0xdc, s32);
            pos.y = FIELD(m, 0xe0, s32);
            pos.z = FIELD(m, 0xe4, s32);
            scale.x = FIELD(m, 0x94, s32);
            scale.y = FIELD(m, 0x98, s32);
            scale.z = FIELD(m, 0x9c, s32);
            dir.x = 0;
            dir.y = 0;
            dir.z = 0x1000;
            MTX_MultVec33(&dir, m + 0xb8, &dir);
            func_02040578(rot, &dir);
            o->v0x18(&pos);
            o->v0x10(&scale);
            o->v0x30(rot);
            o->v0x8(FIELD(self, 0x8, void *));
            FIELD(o, 0x50, s32) = 0xfb1e0000;
            FIELD(o, 0x54, s32) = 0;
            k = FIELD(self, 0x64, s32);
            if (k == -1) {
                FIELD(o, 0xc8, s32) = -1;
            } else if (k == -2) {
                FIELD(o, 0xc8, s32) = -2;
            }
            ((void **)((u8 *)self + 0x50))[i] = FIELD(o, 0x24, void *);
            return;
        }
    }
}

}
