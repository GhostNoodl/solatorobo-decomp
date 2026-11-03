#include "ov015/ov015.h"

extern "C" {

BOOL Interp_MoveTo(Ov015Vec *a, s32 b, Ov015Vec *c, Ov015Vec *d, s32 e);

void Ov015CamPair_Mode7(Ov015CamPair *self) {
    Ov015Vec res1;
    Ov015Vec tgt;
    Ov015Vec prev;
    Ov015Vec res2;
    Ov015Vec d1;
    Ov015Vec d2;
    tgt = self->target;
    if (tgt.x > 0x207ec) {
        tgt.x = 0x207ec;
    } else if (tgt.x < -0x207ec) {
        tgt.x = -0x207ec;
    }
    tgt.y += 0x7000;
    tgt.z = -0x6b800;
    prev = self->cam0.at;
    Interp_MoveTo(&tgt, 0x7b, &prev, &tgt, 0x1000);
    d1.x = self->unk_18c.x - self->target.x;
    d1.y = self->unk_18c.y - self->target.y;
    d1.z = self->unk_18c.z - self->target.z;
    VEC_Normalize(&d1, &d1);
    VEC_MultAdd(self->unk_198, &d1, (&self->unk_18c), &res1);
    res1.y += 0x1e000;
    prev = self->cam0.pos;
    Interp_MoveTo(&res1, 0x7b, &prev, &res1, 0x1000);
    self->cam0.pos = res1;
    self->cam0.at = tgt;
    d2.x = self->unk_18c.x - tgt.x;
    d2.y = self->unk_18c.y - tgt.y;
    d2.z = self->unk_18c.z - tgt.z;
    VEC_Normalize(&d2, &d2);
    VEC_MultAdd(self->unk_198, &d2, (&self->unk_18c), &res2);
    res2.z -= 0x1000;
    self->cam1.at.x = 0;
    self->cam1.at.y = 0x1000;
    self->cam1.at.z = -0x1000;
    self->cam1.pos = res2;
}
void func_ov015_021fd0f4(Ov015CamPair *self, Ov015Vec *out);


void Ov015CamPair_Mode8(Ov015CamPair *self) {
    Ov015Vec o;
    Ov015Vec res;
    Ov015Vec tgt;
    Ov015Vec cam;
    Ov015Vec r;
    Ov015Vec p;
    Ov015Vec w;
    Ov015Vec d;
    Ov015Vec d2;
    Ov015Mtx33 m;
    Ov015Vec c;
    Ov015Vec e;
    Ov015Vec up;
    func_ov015_021fd0f4(self, &o);
    d.x = self->unk_18c.x - o.x;
    d.y = self->unk_18c.y - o.y;
    d.z = self->unk_18c.z - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, (&self->unk_18c), &res);
    tgt = self->cam0.at;
    Interp_MoveTo(&tgt, 0x19a, &tgt, &o, 0);
    cam = self->cam0.pos;
    Interp_MoveTo(&cam, 0x29, &cam, &res, 0);
    self->cam0.pos = cam;
    up = self->cam0.up;
    self->cam0.at = tgt;
    d2.x = self->unk_18c.x - tgt.x;
    d2.y = self->unk_18c.y - tgt.y;
    d2.z = self->unk_18c.z - tgt.z;
    VEC_Normalize(&d2, &d2);
    VEC_MultAdd(self->unk_198, &d2, (&self->unk_18c), &p);
    e.x = tgt.x - p.x;
    e.y = tgt.y - p.y;
    e.z = tgt.z - p.z;
    VEC_Normalize(&e, &e);
    c.x = (s32)(((s64)e.y * up.z - (s64)e.z * up.y + 0x800) >> 12);
    c.y = (s32)(((s64)e.z * up.x - (s64)e.x * up.z + 0x800) >> 12);
    c.z = (s32)(((s64)e.x * up.y - (s64)e.y * up.x + 0x800) >> 12);
    VEC_Normalize(&c, &c);
    MTX_RotAxis33((MtxFx33 *)&m, &c, FX_SinCosTable_[0xdfc * 2], FX_SinCosTable_[0xdfc * 2 + 1]);
    MTX_MultVec33(&e, (MtxFx33 *)&m, &r);
    VEC_Add(&r, &p, &r);
    w = self->cam1.at;
    Interp_MoveTo(&w, 0x29, &w, &r, 0);
    self->cam1.at = w;
    w = self->cam1.pos;
    Interp_MoveTo(&w, 0x29, &w, &p, 0);
    self->cam1.pos = w;
}

}
