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

extern "C" {
void func_02041c18(void *m, int a);
void func_02041c20(void *a, int b, int c);

static inline void *ov002_021e28b0_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void ov002_021e28b0_PlayPart(void *model, int idx) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov002_021e28b0_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 0);
}

static inline void ov002_021e28b0_SetPos(void *m, s32 x, s32 y) {
    FIELD(m, 0x10c, s32) = x;
    FIELD(m, 0x110, s32) = y;
}

static inline s8 ov002_021e28b0_Clamp(void *self, int i) {
    s16 v = ((s16 *)((u8 *)self + 0x2c))[i] + ((s16 *)((u8 *)self + 0x36))[i];
    if (v < 0) {
        v = 0;
    } else if (v > 99) {
        v = 99;
    }
    return v;
}

void func_ov002_021e28b0(void *self) {
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x5e000, -0x4a000);
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 9);
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x66000, -0x4a000);
    func_02041c18(FIELD(self, 0x10, void *), 0);
    func_02041c20(FIELD(self, 0x10, void *), 1, ov002_021e28b0_Clamp(self, 0));
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 1);
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x5e000, -0x35000);
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 9);
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x66000, -0x35000);
    func_02041c18(FIELD(self, 0x10, void *), 0);
    func_02041c20(FIELD(self, 0x10, void *), 1, ov002_021e28b0_Clamp(self, 1));
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 1);
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x5e000, -0x20000);
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 9);
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x66000, -0x20000);
    func_02041c18(FIELD(self, 0x10, void *), 0);
    func_02041c20(FIELD(self, 0x10, void *), 1, ov002_021e28b0_Clamp(self, 2));
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 1);
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x5e000, -0xb000);
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 9);
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x66000, -0xb000);
    func_02041c18(FIELD(self, 0x10, void *), 0);
    func_02041c20(FIELD(self, 0x10, void *), 1, ov002_021e28b0_Clamp(self, 3));
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 1);
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x5e000, 0xa000);
    func_02041c18(FIELD(self, 0x10, void *), 1);
    func_02041c20(FIELD(self, 0x10, void *), 1, ov002_021e28b0_Clamp(self, 4));
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 1);
    ov002_021e28b0_SetPos(FIELD(self, 0x10, void *), 0x6e000, 0xa000);
    ov002_021e28b0_PlayPart(FIELD(self, 0x10, void *), 10);
}
}
