#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov009_02215d0c[];
extern void *data_ov009_0221707c;
extern char data_ov009_02216bb4[];
extern char data_ov009_02216bba[];
extern void SndMgr_LoadHeapState(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void *func_ov003_021da940(void *p);
extern void *func_0204a028(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern s16 *func_ov000_02191318(Model0218fe1c *m, s32 a);
void func_ov009_02205d94(Ov009Names *self, void *res);

struct Ov009Rot {
    s16 x;
    s16 y;
    s16 z;
};

void func_ov009_02205d14(Ov009ActVt_02216bc8 *self) {
    if (self->fsm->st == 0 && self->unk_f2 == 0) {
        self->radius >>= 1;
    }
    func_ov003_021d6054(self);
}

void func_ov009_02205d40(Ov003Actor *self) {
    func_ov003_021d0fc0(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 0xe);
}

void func_ov009_02205d78(Ov003Actor *self) {
    if (self->unk_1a != 0) {
        self->unk_cc = 0xc000;
    }
    func_ov003_021d1e8c(self);
}

void func_ov009_02205d94(Ov009Names *self, void *res) {
    char *a = func_0207011c(res);
    char *b = func_020701d4(res);
    u8 *c = func_02070558(res);
    char *s;
    char *t;
    STD_CopyString(self->mdlDir, a);
    STD_CopyString(self->mdlName, b);
    self->ownMdl = 1;
    s = (char *)data_ov009_02215d0c[15];
    STD_CopyString(self->anmDir, s);
    STD_CopyString(self->anmName, (char *)data_ov009_02215d0c[14]);
    self->ownAnm = 1;
    t = FLD(char *, c, 0x28);
    if (t != NULL) {
        STD_CopyString(self->evDir, s);
        STD_CopyString(self->evName, t);
        self->ownEv = 1;
    }
    self->unk_00 = 0;
}

void func_ov009_02205e54(Ov003Actor *self) {
    if (self->kind == 0x5051) {
        self->unk_d8 = (void *)func_ov009_02205d94;
    }
    func_ov003_021d0fc0(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x5014:
    case 0x501e:
    case 0x5028:
    case 0x502c:
    case 0x5034:
    case 0x5043:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        break;
    case 0x5019:
    case 0x501a:
    case 0x5020:
    case 0x502b:
    case 0x5051:
    case 0x5052:
    case 0x505a:
    case 0x505b:
        func_ov000_02187a20(data_ov000_021ccd54, 0xe);
        break;
    }
    self->unk_ea_10 = 1;
    self->unk_ea_14 = 1;
}

void func_ov009_02205ff0(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        self->radius >>= 1;
    }
    func_ov003_021d6054(self);
}

void Ov009ActVt_02216dcc_Init(Ov009ActVt_02216dcc *self) {
    func_ov003_021d0fc0(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 0xd);
    self->unk_b8 = self->pos;
    self->unk_ea_10 = 1;
    self->unk_f0 = 0;
    self->unk_f2 = 0;
    self->unk_f4 = 0;
}

#ifdef NONMATCHING
// Ov009ActVt_02216dcc_Update (0x2ec bytes, update of the vtable data_ov009_02216dcc actor): 7 / 7 (raw / masked).
// This file's .text ends at 0x02206084, so it goes here once it matches. Blocker: the ROM reads pl->id before the
// unk_93 bit-field store; ours orders them the other way (the strh/strb pair has no memory edge, so list order
// decides). History: docs/MATCHING.md rounds near7, bgV, nmA, mtA, cvA; docs/UNMATCHED.md.
extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021983b0(ActorSub40 *st, s32 a, s32 b, s32 c);
extern s32 _s32_div_f(s32 a, s32 b);

#define OV009_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV009_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV009_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void Ov009ActVt_02216dcc_Update(Ov009ActVt_02216dcc *self) {
    Ov003Actor *pl;
    VecFx32 p;
    s32 pct;
    s32 dist;
    u8 mode;
    if (!Ov009_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    self->unk_93_4 = 1;
    self->target = pl->id;
    p.x = pl->pos.x;
    p.y = pl->pos.y;
    p.z = pl->pos.z;
    dist = VEC_Distance(&self->pos, &p);
    mode = self->fsm->current;
    pct = (u16)_s32_div_f(self->hp[0] * 100, self->hp[1]);
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 == 0 && self->fsm->current == 1) {
        if (func_ov000_021983b0(self->fsm, 0x12, 2, 1) || func_ov000_021983b0(self->fsm, 0x13, 2, 1)) {
            self->unk_f4++;
            if (self->unk_f4 >= 2) {
                self->unk_f4 = 0;
            } else {
                self->fsm->flags |= 0x20000;
                return;
            }
        }
        if (dist <= 0x5000) {
            if (pct <= 0x50 && Rand_UpTo(1) == 0) {
                self->fsm->flags |= 0x10000;
            } else {
                self->fsm->flags |= 0x8000;
            }
        } else if (dist > 0x5000) {
            if (pct <= 0x3c && Rand_UpTo(2) != 0) {
                self->fsm->flags |= 0x10000;
            } else {
                self->fsm->flags |= 4;
                self->unk_b8.x = p.x;
                self->unk_b8.y = p.y;
                self->unk_b8.z = p.z;
                self->unk_b6 = 0x32;
            }
        }
    }
    if (mode != 2) {
        return;
    }
    if (self->unk_b6 == 0) {
        return;
    }
    {
        s64 sq;
        s32 dx;
        s32 dz;
        dx = self->pos.x - self->unk_b8.x;
        dz = self->pos.z - self->unk_b8.z;
        sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        OV009_SQRTCNT = 1;
        OV009_SQRT_PARAM = (u64)(sq * 4);
    }
    while (OV009_SQRTCNT & 0x8000) {
    }
    if ((s32)(OV009_SQRT_RESULT + 1) >> 1 <= 0x2ccd) {
        return;
    }
    if (self->hit->unk_50 & 0x40000000) {
        return;
    }
    self->fsm->flags |= 4;
}
#endif

}
