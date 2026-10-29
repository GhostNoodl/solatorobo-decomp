#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d1e44(void) {
}

void func_ov002_021d1e48(Task50 *self) {
    u16 keys = FIELD(data_02097dc8, 0x12, u16);
    void *ev = FIELD(self, 0x44, void *);
    if (ev != NULL) {
        if (!(keys & 2)) {
            return;
        }
        if (FIELD(ev, 0x58, s32) < 0x1000) {
            return;
        }
        FIELD(ev, 0x6c, u8) = 0;
        FIELD(self, 0x44, void *) = NULL;
        func_ov000_021c701c(self->unk_3c);
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    } else {
        void *m;
        if (!(keys & 2)) {
            return;
        }
        FIELD(self->unk_3c, 0xc, u32) |= 4;
        m = FIELD(self->unk_3c, 0x88, void *);
        if (m != NULL) {
            data_ov002_021f0f84[2] = FIELD(m, 0x4, s32);
        }
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        self->v0xc(0);
    }
}

void func_ov002_021d1f20(Task50 *self) {
    if (self->unk_3c != NULL) {
        TASK_VOBJ(self, 0x3c)->v0x20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->v0x20();
    }
    if (self->unk_48 != 0) {
        func_ov002_021d1f70(self);
    }
}

}

#ifdef NONMATCHING
// func_ov002_021d1f70: 12 raw / 0 register-masked diffs, real signature (self only), no pragma or one-element arrays.
// Register colouring only. Round bgN (was 35): a u8 n was folded into an int temp (every use is
// promoted), so n is s32 and stays a user variable above x; the first PlayPart's model goes through m,
// declared between n and x. Round raC (was 24): SetPos takes fx32 values (the shifts are at the call
// sites) and the count drawing, called only here, is written in place, so the shared y (fy) is a user
// variable instead of an IRO CSE temp of by << 12 (20). The PlayPart(8) model read into num, declared
// between bx and fy, moves that PlayPart's model and res temps into place (12; reusing m gives 17).
// Left: fy (ours r7, ROM r8) and the res temp of the PlayPart(6) calls around it (ours r8, ROM r7).
// ramerge.py: fy numbered between those two res temps, that res numbered between fy and num (both
// would need an inline local to become a user variable or the reverse), or fy merged with the res
// of the function's own PlayPart(0x48, 6). A local for any other PlayPart's model (all 212 subsets and
// orders with fy) stays at 12. Kept as an inline (DrawCount with its own fy local) it is 24 again.
#include "ov002/ov002.h"

extern "C" {

void func_02041c20(void *a, int b, s32 c);

static inline void *ov002_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void ov002_Model_PlayPart(void *model, int idx) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov002_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 0);
}

static inline void ov002_SetPos(void *o, s32 x, s32 y) {
    FIELD(o, 0xfc, s32) = x;
    FIELD(o, 0x100, s32) = y;
}

void func_ov002_021d1f70(void *self) {
    s32 v44;
    s32 d;
    s32 n;
    void *m;
    s32 x;
    u8 *o;
    s32 y;
    s32 z;
    s32 bx;
    void *num;
    s32 fy;
    o = FIELD(FIELD(self, 0x3c, u8 *), 0x88, u8 *);
    x = FIELD(self, 0x50, s32) - 0x6c;
    y = FIELD(self, 0x54, s32) - 0x44;
    v44 = FIELD(o, 0x44, s32);
    n = o[0x51];
    d = n - o[0x50];
    z = FIELD(self, 0x58, s32) + 0x20;
    ov002_SetPos(FIELD(self, 0x4c, void *), x << 12, (y + 9) << 12);
    FIELD(FIELD(self, 0x4c, void *), 0x150, s32) = z;
    m = FIELD(self, 0x4c, void *);
    ov002_Model_PlayPart(m, 4);
    ov002_SetPos(FIELD(self, 0x48, void *), (x + 0x10) << 12, y << 12);
    FIELD(FIELD(self, 0x48, void *), 0x150, s32) = z;
    func_02041c20(FIELD(self, 0x48, void *), 6, v44);
    ov002_Model_PlayPart(FIELD(self, 0x48, void *), 6);
    func_02041c20(FIELD(self, 0x48, void *), 6, 0);
    bx = FIELD(self, 0x50, s32) + 0x50;
    fy = (FIELD(self, 0x54, s32) - 0x44) << 12;
    FIELD(FIELD(self, 0x48, void *), 0x150, s32) = FIELD(self, 0x58, s32) + 0x20;
    ov002_SetPos(FIELD(self, 0x48, void *), bx << 12, fy);
    func_02041c20(FIELD(self, 0x48, void *), 6, n - d);
    ov002_Model_PlayPart(FIELD(self, 0x48, void *), 6);
    ov002_SetPos(FIELD(self, 0x48, void *), (bx + 10) << 12, fy);
    num = FIELD(self, 0x48, void *);
    ov002_Model_PlayPart(num, 8);
    ov002_SetPos(FIELD(self, 0x48, void *), (bx + 0x14) << 12, fy);
    func_02041c20(FIELD(self, 0x48, void *), 6, n);
    ov002_Model_PlayPart(FIELD(self, 0x48, void *), 6);
    func_02041c20(FIELD(self, 0x48, void *), 6, 0);
}

}
#endif
