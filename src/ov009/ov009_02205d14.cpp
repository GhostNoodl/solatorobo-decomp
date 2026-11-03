#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov009_02215d0c[];
extern void *data_ov009_0221707c;
extern char data_ov009_02216bb4[];
extern char data_ov009_02216bba[];
extern void SndMgr_LoadHeapState(void *mgr, s32 a, s32 b);
extern void SceneCmd_Push25(void *p, s32 a);
extern void *Ov003FxList_Dtor(void *p);
extern void *SndMgr_PlayAtPitch(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *m, s32 a);
void Ov009Names_Fill_02205d94(Ov009Names *self, u16 kind);

struct Ov009Rot {
    s16 x;
    s16 y;
    s16 z;
};

void Ov009ActVt_02216bc8_StateDie(Ov009ActVt_02216bc8 *self) {
    if (self->fsm->st == 0 && self->unk_f2 == 0) {
        self->radius >>= 1;
    }
    Ov003Actor_StateDie(self);
}

void Ov009ActVt_02216fd0_Init(Ov003Actor *self) {
    Ov003Actor_Init(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    SceneCmd_Push25(data_ov000_021ccd54, 0xe);
}

void Ov009ActVt_02216fd0_Update(Ov003Actor *self) {
    if (self->unk_1a != 0) {
        self->unk_cc = 0xc000;
    }
    Ov003Actor_Update(self);
}

void Ov009Names_Fill_02205d94(Ov009Names *self, u16 kind) {
    char *a = Tbl_GetResFile(kind);
    char *b = func_020701d4(kind);
    TblActorParam *c = Tbl_GetActorParam(kind);
    char *s;
    char *t;
    STD_CopyString(self->mdlDir, a);
    STD_CopyString(self->mdlName, b);
    self->ownMdl = 1;
    s = (char *)data_ov009_02215d0c[15];
    STD_CopyString(self->anmDir, s);
    STD_CopyString(self->anmName, (char *)data_ov009_02215d0c[14]);
    self->ownAnm = 1;
    t = c->evName;
    if (t != NULL) {
        STD_CopyString(self->evDir, s);
        STD_CopyString(self->evName, t);
        self->ownEv = 1;
    }
    self->unk_00 = 0;
}

void Ov009ActVt_02216f24_Init(Ov003Actor *self) {
    if (self->kind == 0x5051) {
        self->unk_d8 = (void *)Ov009Names_Fill_02205d94;
    }
    Ov003Actor_Init(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x5014:
    case 0x501e:
    case 0x5028:
    case 0x502c:
    case 0x5034:
    case 0x5043:
        SceneCmd_Push25(data_ov000_021ccd54, 0xd);
        break;
    case 0x5019:
    case 0x501a:
    case 0x5020:
    case 0x502b:
    case 0x5051:
    case 0x5052:
    case 0x505a:
    case 0x505b:
        SceneCmd_Push25(data_ov000_021ccd54, 0xe);
        break;
    }
    self->unk_ea_10 = 1;
    self->unk_ea_14 = 1;
}

void Ov009ActVt_02216f24_StateDie(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        self->radius >>= 1;
    }
    Ov003Actor_StateDie(self);
}

void Ov009ActVt_02216dcc_Init(Ov009ActVt_02216dcc *self) {
    Ov003Actor_Init(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    SceneCmd_Push25(data_ov000_021ccd54, 0xd);
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
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern BOOL History_HasState(ActorSub40 *st, s32 a, s32 b, s32 c);
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
    pl = ActorMgr_FindPlayer();
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
        if (History_HasState(self->fsm, 0x12, 2, 1) || History_HasState(self->fsm, 0x13, 2, 1)) {
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
