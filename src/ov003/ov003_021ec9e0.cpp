#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov000/ActorParts.h"
#include "ov003/ActEx.h"
#include "ov003/ActorApi.h"


struct Ov003GmGlobal {
    u8 unk_00[0xac];
    u8 unk_ac;
};

struct Ov003GmPlayer {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x36];
    void *unk_44;
    u8 unk_48[0xad6];
    u16 target;
};

struct Ov003GmArg {
    u8 a;
    u8 b;
};

struct Ov003GmTable {
    void *res[4];
};

extern "C" {

extern char data_ov003_021f99d8[];
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 v);
extern void func_ov000_02191618(void *model);
extern void *func_ov000_02191318(void *model, s32 v);
extern void func_ov000_02191708(void *model);
extern void func_ov000_02191690(void *model);
extern BOOL func_ov000_02191120(void *model);
extern BOOL func_ov000_02198360(ActorSub40 *p, u8 a, BOOL b);
extern Ov003GmPlayer *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(void *a, void *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern BOOL func_ov000_0219a8bc(void *a, void *b, void *c, s32 d, s32 e, VecFx32 *f, s32 g, s32 h, s32 i);
extern void func_ov000_0219bd20(s32 id, u16 a, s32 b, s32 c, s32 d, Ov003GmArg *arg);
extern void *func_0206fef8(u16 id);
extern void func_ov000_0219badc(void *model, void *p, void *info);
extern void HitSphere_Link(ActorSub48 *ctl);
extern void func_ov000_021987b8(ActorSub48 *ctl, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_0218996c(u8 a, u8 b);

void func_ov003_021ec9e0(Ov003Gimmick *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
        func_ov000_021911c8(self->model, 0x800);
        func_ov000_02191618(self->model);
        func_ov000_02191318(self->model, 0);
        func_ov000_02191708(self->model);
        self->fsm->st++;
        break;
    case 1:
        w->timer++;
        if (w->timer >= 0xf && w->timer <= 0x64) {
            Ov003GmPlayer *pl = func_ov000_0219bf90();
            u16 id;
            func_ov000_0219aae8(self, self, 0x78, 0x11, (u16)(1 << (pl->unk_0c >> 12)), 0, 0,
                                self->radius + (self->radius >> 1), self->height, 0x6d, 0xccd);
            id = pl->target;
            if (id != 0xffff && id == self->id) {
                func_ov000_0219a8bc(pl->unk_44, self, self, 0xa, 0x11, &self->pos, 0x6d, 0xccd, 0x1000);
            }
        }
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02198360(self->fsm, 1, 1);
        break;
    }
}

void func_ov003_021ecb6c(Ov003Gimmick *self) {
    if (self->fsm->st == 0) {
        if (self->kind == 0x4064) {
            if (self->unk_cf_u != 1) {
                self->unk_cf_u = 0;
            }
            self->rotOfs.y = 0;
            self->rotOfs.z = 0;
            self->rotOfs.x = 0x4000;
            if (self->unk_bc != NULL) {
                Ov003GmArg arg;
                EffectMgr_Kill(data_0214a420, self->unk_bc);
                self->unk_bc = NULL;
                arg.a = self->unk_1c;
                arg.b = 0;
                func_ov000_0219bd20(0x4064, self->id, 0xe, 1, 2, &arg);
            }
        } else if (self->kind == 0x4065 && self->unk_cf_u == 0) {
            func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
            func_ov000_02191690(self->model);
            func_ov000_02191318(self->model, 0);
        }
    }
    func_ov000_02195d88(self);
}

void func_ov003_021ecc68(Ov003Gimmick *self) {
    Ov003GmArg arg;
    ActorSub40 *w = self->fsm;
    if (w->st == 0 && w->history[0] != 10 && self->unk_ce_u != 0) {
        self->unk_ce_u--;
    }
    if (self->unk_ce_u == 0 && self->unk_cf_u == 1) {
        if (self->unk_bc != NULL) {
            EffectMgr_Kill(data_0214a420, self->unk_bc);
            self->unk_bc = NULL;
        }
        func_ov000_0219763c(self);
        return;
    }
    switch (self->fsm->st) {
    case 0:
        if (self->unk_ce_u == 0) {
            s16 m;
            EffectObj *e;
            if (self->unk_bc != NULL) {
                EffectMgr_Kill(data_0214a420, self->unk_bc);
                self->unk_bc = NULL;
                if (self->kind == 0x4064) {
                    arg.a = self->unk_1c;
                    arg.b = 0;
                    func_ov000_0219bd20(0x4064, self->id, 0xe, 1, 2, &arg);
                }
            }
            self->unk_cf_u = 1;
            self->unk_ce_u = self->unk_1a;
            if (self->unk_ce_u == 0) {
                self->unk_ce_u = 1;
            }
            func_ov000_0219badc(self->model, &self->res, func_0206fef8(self->kind));
            e = func_02065f88(0x6d, &self->pos);
            e->SetScaleXYZ(self->radius + (self->radius >> 3), self->radius + (self->radius >> 3), self->radius + (self->radius >> 3));
            e = func_02065f88(4, &self->pos);
            e->SetScaleXYZ(self->radius + (self->radius >> 3), self->radius + (self->radius >> 3), self->radius + (self->radius >> 3));
            e->AddPosXYZ(0, self->centerY, 0);
            func_02049f44(data_02097e4c, 0x16, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        }
        {
            ActorSub48 *c = self->hit;
            c->unk_9a_0 = 1;
            c->unk_9a_3 = 1;
            HitSphere_Link(c);
            self->hit->unk_9a |= 0x12;
        }
        self->velY = 0x2cd;
        self->gravity = 0x52;
        self->fsm->st++;
    case 1:
        func_ov000_02197ad0(self, 0);
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x20000000) {
            ActorSub44 *s = self->unk_44;
            s->unk_22_0 = 1;
            s->unk_22_1 = 1;
            func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
            func_ov000_021915a0(self->model);
            func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            func_ov000_0218996c(0xf, 0x14);
            self->velY = 0;
            self->fsm->st++;
            self->fsm->timer = 0;
            return;
        }
        if (self->velY >= 0) {
            return;
        }
        w = self->fsm;
        w->timer++;
        if (w->timer <= 0x46) {
            return;
        }
        self->fsm->timer = 0x46;
        if (self->hit->unk_54 & 0x20000000) {
            return;
        }
        func_ov000_02198360(self->fsm, 0x15, 1);
        break;
    case 2:
        self->hit->unk_9a |= 0x20;
        w = self->fsm;
        w->timer++;
        if (w->timer < 6) {
            return;
        }
        self->fsm->timer = 6;
        if (!func_ov000_02191120(self->model) && self->fsm->flags == 0) {
            return;
        }
        self->targetObj->target = 0xffff;
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
}
}
