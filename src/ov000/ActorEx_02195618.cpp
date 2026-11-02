#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ActorMarker.h"
#include "Main/Effect/Effect.h"

class Act02195618Cls;
typedef void (Act02195618Cls::*Act02195618Pmf)();

typedef struct {
    s32 key;
    Act02195618Pmf fn;
} Act02195618Entry;

extern "C" {

extern Act02195618Entry data_ov000_021c9e18[];
void HitMesh_Unlink_0203f920(void *p);
void func_ov000_0219af3c(u8 *self, void *p);
void Geom_AddRotatedOffset(VecFx32 *pos, const VecFx32 *ofs, s32 angle);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline BOOL PlayerIdle02195618(void) {
    FieldState *pl = data_ov000_021ccd54;
    if (pl != NULL) {
        if (pl->head != pl->tail ? TRUE : FALSE) {
            return FALSE;
        }
        if (pl->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void ActorEx_RunState(ActorEx *self) {
    s32 k;
    s32 i;
    EffectObj *o;
    VecFx32 pos;
    VecFx32 ofs;
    VecFx32 v;

    if (self->hitMesh != NULL) {
        HitMesh_Unlink_0203f920(self->hitMesh);
    }
    k = self->fsm->current;
    for (i = 0; i < 15; i++) {
        if (k == *(s32 *)((u8 *)data_ov000_021c9e18 + i * 12)) {
            (((Act02195618Cls *)self)->*data_ov000_021c9e18[i].fn)();
            break;
        }
    }
    {
        ActorSub40 *st = (ActorSub40 *)((u8 *)self->fsm);
        st->flags = 0;
    }
    if (self->unk_5c != NULL) {
        if (PlayerIdle02195618()) {
            func_ov000_0219af3c((u8 *)self, self->unk_5c);
            if (!self->unk_cc_7) {
                s32 r;
                ActorSub44 *hit = self->unk_44;
                if (hit != NULL) {
                    pos = *(VecFx32 *)hit;
                    if (hit->unk_22_4) {
                        ofs.z = hit->unk_1c;
                        ofs.x = 0;
                        ofs.y = 0;
                        Geom_AddRotatedOffset(&pos, &ofs, self->rot_y);
                    }
                    r = self->unk_44->unk_0c.y;
                    if (r == 0) {
                        r = self->unk_44->unk_1c;
                    }
                } else {
                    pos = self->pos;
                    r = self->height;
                    if (r == 0) {
                        r = self->radius;
                    }
                }
                self->unk_5c->unk_50 = pos;
                self->unk_5c->height = r;
            }
            ActorMarker_Update(self->unk_5c);
        } else {
            self->unk_5c->show = 0;
            func_ov000_021bd300(self->unk_5c);
        }
    }
    if (self->unk_bc == NULL) {
        return;
    }
    o = Effect_Find_020657b0(data_0214a420, self->unk_bc);
    if (o == NULL) {
        self->unk_bc = NULL;
        return;
    }
    VEC_Add((VecFx32 *)((u8 *)self + 0xc0), (VecFx32 *)((u8 *)self + 0x70), &v);
    o->SetPos(&v);
}
}
