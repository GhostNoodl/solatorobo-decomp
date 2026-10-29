#include "ov000/VObj.h"

extern "C" {

void func_ov000_021764c4();

void func_ov000_02188670(void) {
    func_ov000_021764c4();
}

}

#ifdef NONMATCHING
// func_ov000_0218867c: 28 raw / 12 register-masked, 22 / 6 with pool offsets masked (round rtF).
// Real one-argument signature (called through the CmdObj step table with only self). The
// break-at-zero check in the case-1 loop and the identical vfunc_38(1) arms are in the target
// (cmp r7, #0 with r7 starting at 0; beq / b to the same call). The 1 / 1U spelling keeps the two
// calls from being merged. Left: case 1 keeps data_02fe1534 for after the loop in a fresh scratch
// register; ours hoists it to the case head (move-constant-loads step 17->12 at pressure 10, the
// target refuses it, so its loop has one more live value), and the entry order of arg / 0x64.
// Round qpG: no gain from a Data0218867c pointer local (it also refuses the 0x64 move: 48 aligned), g_1 at the
// top of case 1 (38), five spellings of the g_1 ternary, or normal-mode scheduling of any one block (70 tried).
// Forcing only the 17->12 refusal gives 35 aligned, so the missing live value is not the whole story.
#include "ov000/CmdObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef void (*Cb0218867c)(void);

typedef struct {
    u8 pad_00[4];
    u8 *unk_04;
    s32 unk_08;
    Cb0218867c unk_0c;
    s32 unk_10;
} Data0218867c;

extern "C" {

extern u8 data_02fe1534[];
extern void *data_02fe152c;
extern Data0218867c data_ov000_021ccd50;
extern void *data_ov000_021ccd68;
u16 func_ov000_0214be28(u16 id);
void func_ov000_021763c8(void);
u32 func_ov000_02176538(void);
void func_ov000_02176560(void);
void func_ov000_02176590(u16 id);
u16 func_0206f954(void);
void *func_0205976c(void *res, u32 idx);
u32 func_0205975c(void *res, u32 idx);
u16 func_02059544(void *res, void *block, void *entries, int packed, u32 id);
VObj *func_ov000_0218e640(void *mgr, u16 id);
void func_0206228c(void);
u8 *func_ov000_0219bf90(void);
s32 FX_Div(s32 a, s32 b);

static inline BOOL Busy0218867c(VObj *v) {
    return LFLD(u8, v, 0x5a) ? TRUE : FALSE;
}

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} MapId0218867c;

typedef struct {
    u8 unk_00[0x772];
    MapId0218867c map;
} Plyr0218867c;

static inline VObj *Find0218867c(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
}

s32 func_ov000_0218867c(CmdObj *self) {
    s32 hit;
    s32 miss;
    u16 i;
    void *blk;
    void *ents;
    u32 n_1;
    u16 kind = self->unk_a4;
    u16 arg = self->unk_a6;
    u32 idx;
    s32 c1;
    s32 c2;
    switch (kind) {
    case 0: {
        u8 *g_0 = data_02fe1534;
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            LFLD(u16, g_0, 0x80) = func_ov000_0214be28(arg);
            self->step = 100;
            break;
        }
        break;
    }
    case 1:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1: {
            u16 n_0 = 0;
            VObj *p = LFLD(VObj *, data_ov000_021ccd50.unk_04, 0xbc);
            for (; p != NULL; p = LFLD(VObj *, p, 0xd4)) {
                if (n_0 == 0) {
                    break;
                }
                if (p->vfunc_34()) {
                    n_0++;
                }
            }
            {
                u8 *g_1 = data_02fe1534;
                LFLD(u16, g_1, 0x80) = p != NULL ? 1 : 0;
            }
            self->step = 100;
            break;
        }
        }
        break;
    case 2: {
        u8 *g_2 = data_02fe1534;
        switch (self->step) {
        case 0:
            func_ov000_021763c8();
            data_ov000_021ccd50.unk_0c = func_ov000_02188670;
            self->step++;
            return 0;
        case 1:
            if (func_ov000_02176538()) {
                func_ov000_02176560();
                func_ov000_02176590(arg);
                LFLD(u16, g_2, 0x80) = func_0206f954();
                self->step = 100;
            }
            break;
        }
        break;
    }
    case 5:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            self->step = 0x5a;
            idx = 8;
            c1 = 0x101;
            c2 = 0x201;
            break;
        }
        break;
    case 6:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            idx = 0xb;
            c1 = 0x101;
            self->step = 0x5a;
            c2 = 0x201;
            break;
        }
        break;
    case 4: {
        u8 *g_3 = data_02fe1534;
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1: {
            u8 *pl_0 = func_ov000_0219bf90();
            LFLD(u16, g_3, 0x80) = 0;
            if (pl_0 != NULL) {
                const u8 *y = (const u8 *)&((Plyr0218867c *)pl_0)->map;
                const u16 *x = (u16 *)(g_3 + 0x46);
                if (y[0] == x[0] && y[1] == x[1] && y[2] == x[2]) {
                    LFLD(u16, g_3, 0x80) = 1;
                }
            }
            self->step = 100;
            break;
        }
        }
        break;
    }
    case 7: {
        u8 *pl_1 = func_ov000_0219bf90();
        if (pl_1 != NULL) {
            VObj *o_0 = Find0218867c(LFLD(u16, pl_1, 0xb1c));
            if (o_0 != NULL) {
                o_0->vfunc_08();
            }
        }
        self->step = 100;
        break;
    }
    case 8: {
        VObj *o_1 = Find0218867c(arg);
        if (o_1 != NULL) {
            o_1->vfunc_08();
        }
        self->step = 100;
        break;
    }
    }
    if (self->step == 0x5a) {
        blk = LFLD(u8 *, data_02fe152c, 0x4c) + 0x10 + idx * 0x20;
        ents = func_0205976c(data_02fe152c, idx);
        n_1 = func_0205975c(data_02fe152c, idx);
        hit = 0;
        miss = 0;
        for (i = 0; i < n_1; i++) {
            if (func_02059544(data_02fe152c, blk, ents, c2, i) == 0) {
                if (func_02059544(data_02fe152c, blk, ents, c1, i) != 0) {
                    hit++;
                }
            } else {
                miss++;
            }
        }
        LFLD(u16, data_02fe1534, 0x80) = (s32)(((s64)FX_Div(hit << 12, (n_1 - miss) << 12) * 0x64000 + 0x800) >> 12) >> 12;
        self->step = 100;
    }
    if (self->step == 100) {
        u8 *o_2;
        if (data_ov000_021ccd50.unk_0c != NULL) {
            data_ov000_021ccd50.unk_0c();
        }
        data_ov000_021ccd50.unk_0c = NULL;
        data_ov000_021ccd50.unk_08 = 0;
        data_ov000_021ccd50.unk_10 = 0;
        o_2 = data_ov000_021ccd50.unk_04;
        if (LFLD(VObj *, o_2, 0xc0) != NULL) {
            if (o_2[0xc4]) {
                LFLD(VObj *, o_2, 0xc0)->vfunc_38(1);
            } else {
                LFLD(VObj *, o_2, 0xc0)->vfunc_38(1U);
            }
            if (!Busy0218867c(LFLD(VObj *, o_2, 0xc0))) {
                LFLD(VObj *, o_2, 0xc0) = NULL;
                o_2[0xc4] = 0;
            }
            if (LFLD(VObj *, o_2, 0xc0) == NULL) {
                func_0206228c();
            }
        }
        CmdObj_Done(self);
        return 1;
    }
    return 1;
}

}
#endif
