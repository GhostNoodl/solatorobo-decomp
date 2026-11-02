#include "types.h"
#include "ov003/Shot.h"

// The effect object the effect functions return (Main EffectObj; only the methods used here).
class Ov003SpFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetSize(s32 size);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void AddPosXYZ(s32 x, s32 y, s32 z);
};

extern "C" {

extern BOOL func_ov000_0219aae8(Actor *a, Actor *b, u16 c, u8 d, s32 e, VecFx32 *pos, ActorRot *rot, s32 f, s32 g, s32 h, s32 i);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern Ov003SpFx *func_02065f88(s32 id, VecFx32 *pos);
extern Ov003SpFx *EffectGroup_Create(void *a, void *b, VecFx32 *pos);
extern void EffectObj_AddSndCue(Ov003SpFx *e, s32 a, s32 b);

static inline void Ov003_RotX(VecFx32 *out, const VecFx32 *in, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

BOOL func_ov003_021dc840(Ov003Beam *self) {
    u16 size;
    BOOL ok;
    Robo021ca458 *pl;
    Ov003SpFx *e;
    ActorRot rot;
    VecFx32 pos;
    VecFx32 ppos;

    rot.x = self->rot_x + 0x4000;
    rot.y = self->rot_y;
    rot.z = self->rot_z;
    size = self->targetObj->unk_08;
    if (self->unk_1c != 0 && self->unk_1c != 0x1000) {
        size = (u16)(((s64)size * self->unk_1c + 0x800) >> 12);
    }
    pos.x = self->unk_84.x;
    pos.y = self->unk_84.y;
    pos.z = self->unk_84.z;
    Ov003_RotX(&pos, &pos, self->rot_x);
    ok = func_ov000_0219aae8(self, self, size, (u8)self->targetObj->unk_0a, 2, &pos, &rot,
                             (s32)(((s64)self->scales[1].x * 0x666 + 0x800) >> 12),
                             (s32)(((s64)self->scales[1].z * 0xf800 + 0x800) >> 12), -1, 0x1000);
    if (ok) {
        pl = func_ov000_0219bf90();
        if (pl != NULL) {
            ppos.x = pl->pos.x;
            ppos.y = pl->pos.y;
            ppos.z = pl->pos.z;
            if (pl->unk_93_5) {
                e = func_02065f88(0x327, &ppos);
                e->SetSize(pl->radius * 2);
            } else {
                Ov003BeamDef *r = self->def;
                if (r->arc != NULL && r->hitFx != NULL) {
                    e = EffectGroup_Create(r->arc, r->hitFx, &ppos);
                    EffectObj_AddSndCue(e, 0x10, 0);
                    e->SetSize(0x99a);
                } else {
                    e = func_02065f88(0x64, &ppos);
                }
            }
            if (e != NULL) {
                e->SetSize(self->def->hitFxSize);
                e->AddPosXYZ(0, pl->centerY, 0);
            }
        }
    }
    return ok;
}

}
