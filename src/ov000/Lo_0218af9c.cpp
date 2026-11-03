#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Vec.h"
#include "ov000/Group.h"

extern "C" {
extern Group *data_ov000_021ccd64;
Robo021ca458 *ActorMgr_FindPlayer(void);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
BOOL Hit_DiffInBox(VecFx32 *a, VecFx32 *b, VecFx32 *min, VecFx32 *max);
u16 FX_Atan2(s32 x, s32 z);
void GroupNode_UpdateEntry(GroupNode *self, s32 mode, Actor *src);
Actor *Group_SpawnActor(Group *g, const GroupActorDesc *desc, const VecFx32 *pos, const Rot16 *rot, u16 id);

static inline BOOL GBusy0218af9c(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline s16 GIdle0218af9c(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy0218af9c(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 FxMul0218af9c(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov000_0218af9c(GroupNode *self) {
    unsigned long on;
    s32 dist;
    BOOL any;
    Robo021ca458 *pl;
    u8 i;
    GroupNodeFlags *fl;
    s32 mode;
    Actor *best;
    Actor *tgt;
    GroupView seg;
    GroupActorDesc d;

    mode = 0;
    best = NULL;
    any = FALSE;
    pl = ActorMgr_FindPlayer();
    on = FALSE;
    fl = &self->flags;
    if (self->flags.unk_0 && data_ov000_021ccd64->unk_0c.bits.flag_1) {
        on = TRUE;
    }
    if (on && pl != NULL) {
        on = GIdle0218af9c();
    }
    for (i = 0; i < data_ov000_021ccd64->viewCount; i++) {
        seg.to.x = data_ov000_021ccd64->viewPos[i].x;
        seg.to.y = data_ov000_021ccd64->viewPos[i].y;
        seg.to.z = data_ov000_021ccd64->viewPos[i].z;
        seg.yaw = data_ov000_021ccd64->viewYaw[i];
        if (mode == 3 || mode == 1) {
            continue;
        }
        if (self->entries[0].actor != 0xffff && (u16)(self->entries[0].actor & 0xfff) != 0) {
            tgt = best;
            if (best == NULL) {
                if (data_ov000_021ccd68 == NULL) {
                    tgt = NULL;
                } else {
                    tgt = ActorMgr_GetActor(data_ov000_021ccd68, self->entries[0].actor);
                }
            }
            if (tgt != NULL) {
                BOOL r;
                any = TRUE;
                mode = 1;
                if (!on) {
                    continue;
                }
                if (pl != NULL) {
                    if (self->entries[0].actor == pl->unk_b1c || self->entries[0].actor == pl->unk_b20) {
                        continue;
                    }
                }
                seg.from = tgt->pos;
                if (!Hit_DiffInBox(&seg.from, &seg.to, &self->despawnMin, &self->despawnMax)) {
                    r = TRUE;
                } else {

                    {
                        s32 dx = seg.to.x - seg.from.x;
                        s32 dz = seg.to.z - seg.from.z;
                        s64 sq = (s64)dx * dx;
                        sq += (s64)dz * dz;
                        REG_SQRTCNT = 1;
                        REG_SQRT_PARAM = (u64)(sq << 2);
                    }
                    while (REG_SQRTCNT & 0x8000) {
                    }
                    dist = (s32)(REG_SQRT_RESULT + 1) >> 1;
                    if (self->despawnRange < dist) {
                        r = TRUE;
                    } else if (!fl->useAngle) {
                        r = FALSE;
                    } else {
                        u16 a = FX_Atan2(seg.from.x - seg.to.x, seg.from.z - seg.to.z) - seg.yaw;
                        s32 k;
                        if (a > 0x8000) {
                            a = -a;
                        }
                        k = 0x119a - (a >> 3);
                        if (k > 0x1000) {
                            k = 0x1000;
                        } else if (k < 0x43d) {
                            k = 0x43d;
                        }
                        if (k == 0x1000) {
                            r = FALSE;
                        } else if (dist > FxMul0218af9c(self->despawnRange, k)) {
                            r = TRUE;
                        } else {
                            r = FALSE;
                        }
                    }
                }
                if (r) {
                    best = tgt;
                    mode = 2;
                }
            } else {
                self->entries[0].actor = 0xffff;
                self->entries[0].kind = 0xffff;
            }
        } else if (self->entries[0].kind != 0xffff) {
            FieldState *g = data_ov000_021ccd54;
            BOOL same;
            any = TRUE;
            same = FALSE;
            if (self->entries[0].fieldId.c[0] == g->unk_ca.c[0] && self->entries[0].fieldId.c[1] == g->unk_ca.c[1] && self->entries[0].fieldId.c[2] == g->unk_ca.c[2]) {
                same = TRUE;
            }
            if (same) {
                seg.from = self->entries[0].pos;
                if (func_01ffc89c(self, &seg)) {
                    mode = 3;
                }
            }
        }
    }
    if (any) {
        switch (mode) {
        case 2:
            GroupNode_UpdateEntry(self, 1, best);
            best->vfunc_08();
            break;
        case 3: {
            u16 kind = self->id;
            s32 j;
            Actor *o;
            d.kind = self->entries[0].kind;
            d.group = self->entries[0].actor & 0xf000;
            for (j = 0; j < 4; j++) {
                d.args[j] = self->entries[0].args[j];
            }
            d.unk_0c = self->entries[0].unk_0c;
            o = Group_SpawnActor(data_ov000_021ccd64, &d, &self->entries[0].pos, &self->entries[0].rot, kind);
            if (o != NULL) {
                self->entries[0].actor = o->id;
            }
            if (o != NULL && self->unk_a3 != 0xff) {
                o->unk_17 = self->unk_a3;
            }
            break;
        }
        }
    } else {
        self->count = 0;
    }
}

}
