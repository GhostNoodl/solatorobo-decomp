#include "types.h"
#include "Main/Lang/TblRes.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/Actor.h"

typedef struct {
    s16 sound;
    s16 unk_02;
    s16 unk_04;
    s16 fx;
    s16 scale;
    s16 unk_0a;
} Ov003DtEnt;

extern "C" {

extern const Ov003DtEnt data_ov003_021f4648[];
extern char data_ov003_021f7a7f[];
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s16 a, u8 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern void HitSphere_Unlink_0203f364(ActorSub48 *c);
extern void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 on, u32 mask);
extern void func_ov000_0218996c(u8 a, u8 b);
extern EffectObj *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);
extern void Drop_SpawnWeighted(u16 *ids, u8 *rates, s32 n, VecFx32 *pos, u16 *rot, s32 d);
extern void func_ov000_0219b5dc(u16 id, VecFx32 *pos, u16 *rot);

void Ov003Actor_StateDie(Ov003Actor *self) {
    u16 idx = self->targetObj->unk_06;
    const Ov003DtEnt *e;
    VecFx32 v;
    if (idx >= 10) {
        idx = 0;
    }
    e = &data_ov003_021f4648[idx];
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *c;
        ActorSub44 *s;
        Model0218fe1c *m;
        self->hpObj->cur = 0;
        if (!self->unk_ea_12) {
            Model0218fe1c_SetAnim(self->model, data_ov003_021f7a7f, 0xcd, 0);
            Model0218fe1c_SetLoop(self->model);
        }
        c = self->hit;
        if (c != NULL) {
            c->unk_9a_0 = 0;
            c->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(c);
        }
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
        }
        self->targetObj->target = 0xffff;
        m = self->model;
        m->cull = 2;
        NNSi_G3dModifyPolygonAttrMask(m->mdl, 0, 0xc0);
        self->unk_ea_3 = 0;
        if (self->unk_ea_10) {
            self->fsm->st++;
            return;
        }
        func_ov000_0218996c(9, 0x14);
        self->fsm->st = 10;
        break;
    }
    case 1: {
        u16 t = self->fsm->timer;
        if (t >= 0x78) {
            func_ov000_0218996c(0x19, 0x78);
            SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
            SndMgr_PlayAt(data_02097e4c, 0x53, &self->pos, 0);
            self->fsm->st = 10;
            return;
        }
        if (t % 20 == 0) {
            VecFx32 r;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            v.y += self->centerY;
            r.x = self->radius;
            r.y = self->height >> 2;
            r.z = self->radius + (self->radius >> 2);
            Spawn_ScatterEffect(&v, &r, 0x733, 0xccd, e->unk_02, 0x32);
            func_ov000_0218996c(8, 10);
            SndMgr_PlayAt(data_02097e4c, 0x35, &v, 0);
        }
        self->fsm->timer++;
        break;
    }
    case 10: {
        TblActorParam *res;
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += (self->height >> 1) - (self->height >> 3);
        if (e->fx != -1) {
            EffectObj *fx = Effect_SpawnId(e->fx, &v);
            s32 sc = e->scale << 4;
            if (sc == 0) {
                sc = self->radius;
                if (idx != 0) {
                    if (idx == 5) {
                        fx->speed = 0xccd;
                        sc = (sc >> 1) + 0x3800;
                    }
                } else {
                    sc = sc + (sc >> 1);
                }
            }
            fx->SetScaleXYZ(sc, sc, sc);
        }
        if (e->sound >= 0 && self->hpObj->unk_04 != 0xffff) {
            SndMgr_PlayAt(data_02097e4c, e->sound, &v, 0);
        }
        res = func_02070558(self->kind);
        Drop_SpawnWeighted(res->dropIds, res->dropRates, 2, &v, &self->rot_x, 1);
        func_ov000_0219b5dc(self->unk_b0->unk_06, &v, &self->rot_x);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 11: {
        u16 lim = 0x3c;
        u8 a;
        u16 h;
        ActorSub40 *w;
        if (self->unk_ea_10) {
            lim = 0x78;
        }
        w = self->fsm;
        w->timer++;
        if (w->timer > lim) {
            Ov003Actor_Defeat(self, 1, 1, 1);
            return;
        }
        h = self->fsm->timer >> 1;
        if (h > 0x1f) {
            h = 0x1f;
        }
        a = 0x1f - h;
        self->model->alpha = a;
        if (self->unk_d0 != NULL && self->unk_ea_3 != 0) {
            s32 i;
            for (i = 0; i < 2; i++) {
                Model0218fe1c *m = self->unk_d0->models[i];
                if (m != NULL) {
                    m->alpha = a;
                }
            }
        }
        break;
    }
    }
}

}
