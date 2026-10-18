#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Ov003Rot;

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
    virtual void SetRot(s32 x, s32 y, s32 z);
};

typedef struct {
    u8 unk_00[8];
    u16 unk_08;
    u16 unk_0a;
} Ov003SpDef;

typedef struct {
    void *unk_00;
    u8 unk_04[0x3c];
    void *unk_40;
    s32 unk_44;
} Ov003SpRes;

typedef struct {
    u8 unk_00[0x1c];
    s16 scale;
    u8 unk_1e[0x2e];
    Ov003SpDef *def;
    u8 unk_50[0x2c];
    Ov003Rot rot;
    u8 unk_82[2];
    Ov003Vec offset;
    u8 unk_90[0x40];
    Ov003SpRes *res;
    u8 unk_d4[0x14];
    s32 unk_e8;
    u8 unk_ec[4];
    s32 unk_f0;
} Ov003Spawner;

typedef struct {
    u8 b0 : 5;
    u8 b5 : 2;
    u8 b7 : 1;
} Ov003Bits93;

typedef struct {
    u8 unk_00[0x64];
    s32 unk_64;
    u8 unk_68[4];
    s32 unk_6c;
    Ov003Vec pos;
    u8 unk_7c[0x17];
    Ov003Bits93 unk_93;
} Ov003SpPlayer;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern BOOL func_ov000_0219aae8(Ov003Spawner *a, Ov003Spawner *b, u16 c, u8 d, s32 e, Ov003Vec *pos, Ov003Rot *rot, s32 f, s32 g, s32 h, s32 i);
extern Ov003SpPlayer *func_ov000_0219bf90(void);
extern Ov003SpFx *func_02065f88(s32 id, Ov003Vec *pos);
extern Ov003SpFx *func_02066900(void *a, void *b, Ov003Vec *pos);
extern void func_020639d4(Ov003SpFx *e, s32 a, s32 b);

static inline void Ov003_RotX(Ov003Vec *out, const Ov003Vec *in, u16 ang) {
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

BOOL func_ov003_021dc840(Ov003Spawner *self) {
    u16 size;
    BOOL ok;
    Ov003SpPlayer *pl;
    Ov003SpFx *e;
    Ov003Rot rot;
    Ov003Vec pos;
    Ov003Vec ppos;

    rot.x = self->rot.x + 0x4000;
    rot.y = self->rot.y;
    rot.z = self->rot.z;
    size = self->def->unk_08;
    if (self->scale != 0 && self->scale != 0x1000) {
        size = (u16)(((s64)size * self->scale + 0x800) >> 12);
    }
    pos.x = self->offset.x;
    pos.y = self->offset.y;
    pos.z = self->offset.z;
    Ov003_RotX(&pos, &pos, self->rot.x);
    ok = func_ov000_0219aae8(self, self, size, (u8)self->def->unk_0a, 2, &pos, &rot,
                             (s32)(((s64)self->unk_e8 * 0x666 + 0x800) >> 12),
                             (s32)(((s64)self->unk_f0 * 0xf800 + 0x800) >> 12), -1, 0x1000);
    if (ok) {
        pl = func_ov000_0219bf90();
        if (pl != NULL) {
            ppos.x = pl->pos.x;
            ppos.y = pl->pos.y;
            ppos.z = pl->pos.z;
            if (pl->unk_93.b5) {
                e = func_02065f88(0x327, &ppos);
                e->SetSize(pl->unk_64 * 2);
            } else {
                Ov003SpRes *r = self->res;
                if (r->unk_00 != NULL && r->unk_40 != NULL) {
                    e = func_02066900(r->unk_00, r->unk_40, &ppos);
                    func_020639d4(e, 0x10, 0);
                    e->SetSize(0x99a);
                } else {
                    e = func_02065f88(0x64, &ppos);
                }
            }
            if (e != NULL) {
                e->SetSize(self->res->unk_44);
                e->SetRot(0, pl->unk_6c, 0);
            }
        }
    }
    return ok;
}

}
