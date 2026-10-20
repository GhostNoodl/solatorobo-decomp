#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"

typedef struct ov006_Rot021e76d8 {
    u16 x;
    u16 y;
    u16 z;
} ov006_Rot021e76d8;

typedef struct ov006_Mdl021e76d8 {
    u8 unk0[0xb6];
    u16 unkB6;
    u16 unkB8;
    u16 unkBA;
    u16 unkBC;
} ov006_Mdl021e76d8;

typedef struct ov006_Hit021e76d8 {
    int *unk0;
    u8 unk4[0x10d];
    u8 unk111;
} ov006_Hit021e76d8;

typedef struct ov006_Eff021e76d8 {
    u8 unk0[0x1c];
    int unk1C;
    u8 unk20[4];
    int unk24;
    u8 unk28[0x14];
    fx32 unk3C;
    VecFx32 unk40;
} ov006_Eff021e76d8;

typedef struct ov006_Ofs021e76d8 {
    VecFx32 a;
    VecFx32 b;
} ov006_Ofs021e76d8;

typedef struct ov006_Car021e76d8 {
    u8 unk0[0x38];
    ov006_Mdl021e76d8 *unk38;
    u8 unk3C[0x30];
    s32 unk6C;
    VecFx32 pos;
    ov006_Rot021e76d8 rot;
    u8 unk82[0x11a];
    u16 unk19C_0 : 2;
    u16 mode : 4;
    u16 boosting : 1;
    u16 unk19C_7 : 1;
    u16 swap : 1;
    u16 unk19C_9 : 1;
    u16 phase : 3;
    u16 unk19C_13 : 1;
    u16 unk19C_14 : 1;
    u16 unk19C_15 : 1;
    u8 unk19E;
    u8 unk19F;
    u8 unk1A0[0x1a];
    u16 look2x;
    u16 look2y;
    u8 unk1BE[0x12];
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    u8 unk1F4;
    u8 unk1F5;
    u16 boost;
    u16 unk1F8;
    u16 unk1FA;
    u16 unk1FC;
} ov006_Car021e76d8;

typedef struct ov006_CamRot021e76d8 {
    u8 unk0[0x42];
    u16 x;
    u16 y;
    u16 z;
} ov006_CamRot021e76d8;

#define OV006_SINCOS FX_SinCosTable_

extern "C" {

extern void *data_02097e4c;
extern void *data_0214a420;
extern u8 *data_ov000_021ccd54;
extern ov006_Ofs021e76d8 data_ov006_021eb954[];
ov006_Eff021e76d8 *func_020657b0(void *a, int b);
ov006_Eff021e76d8 *func_02065f88(s32 id, VecFx32 *pos);
void func_02063a14(ov006_Eff021e76d8 *e);
ov006_Hit021e76d8 *func_ov000_02190a30(void *a, int b);
void func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);

void func_ov006_021e76d8(ov006_Car021e76d8 *self) {
    VecFx32 v1;
    VecFx32 p1;
    MtxFx33 m;
    VecFx32 v2;
    VecFx32 o2;
    VecFx32 v3;
    VecFx32 o3;
    VecFx32 p4;
    MtxFx33 t;
    ov006_Rot021e76d8 r;
    ov006_Rot021e76d8 cr;
    ov006_Eff021e76d8 *e;
    if (self->unk1F5 != 0) {
        self->unk1F5--;
    }
    if (self->unk1F8 != 0) {
        self->unk1F8--;
        if (self->unk1F8 == 0) {
            e = func_020657b0(data_0214a420, self->unk1E8);
            if (e != NULL) {
                func_02063a14(e);
                e->unk1C = 4;
                self->unk1E8 = 0;
            }
            {
                ov006_Hit021e76d8 *h = func_ov000_02190a30(self->unk38, 3);
                if (h != NULL) {
                    if (h->unk0 != NULL) {
                        *h->unk0 = 0;
                    }
                    h->unk111 |= 8;
                }
            }
            {
                ov006_Mdl021e76d8 *m = self->unk38;
                m->unkB6 = 0x53ff;
                m->unkB8 = 0x53ff;
                m->unkBA = 2;
                m->unkBC = 1;
            }
        } else if (self->unk38->unkBA <= 1) {
            u16 a = 0;
            u16 b = 0;
            self->phase++;
            if (self->phase > 2) {
                self->phase = 0;
            }
            switch (self->phase) {
            case 0:
                a = 0x53ff;
                b = 0x7f94;
                break;
            case 1:
                a = 0x7f94;
                b = 0x5a5f;
                break;
            case 2:
                a = 0x5a5f;
                b = 0x53ff;
                break;
            }
            {
                ov006_Mdl021e76d8 *m = self->unk38;
                m->unkB6 = a;
                m->unkB8 = b;
                m->unkBA = 0x15;
                m->unkBC = 0x14;
            }
        }
        if (self->unk1E8 != 0) {
            e = func_020657b0(data_0214a420, self->unk1E8);
            if (e == NULL) {
                self->unk1E8 = 0;
            } else {
                VCALL(e, 18, &self->pos);
            }
        }
    }
    if (self->unk1FA != 0) {
        self->unk1FA--;
        if (self->boosting && self->unk1FA != 0) {
            self->unk1FA--;
        }
        if (self->unk1FA == 0 || self->unk1F8 != 0) {
            self->unk1FA = 0;
            e = func_020657b0(data_0214a420, self->unk1EC);
            if (e != NULL) {
                func_02063a14(e);
                self->unk1EC = 0;
            }
            if (self->unk19C_0 & 1) {
                e = func_02065f88(0x38a, &self->pos);
                if (e != NULL) {
                    VCALL(e, 0C, 0x1800);
                    self->unk1EC = e->unk24;
                    if (self->unk19E == data_ov006_021ec884->unk5) {
                        func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
                    }
                }
            }
        } else if (self->unk1EC == 0 && (self->unk19C_0 & 1)) {
            e = func_02065f88(0x38c, &self->pos);
            if (e != NULL) {
                if (self->unk19E == data_ov006_021ec884->unk5) {
                    VCALL(e, 0C, 0x1266);
                } else {
                    VCALL(e, 0C, 0xa66);
                }
                e->unk3C = 0x800;
                self->unk1EC = e->unk24;
            }
        }
    }
    if (self->unk1EC != 0) {
        e = func_020657b0(data_0214a420, self->unk1EC);
        if (e != NULL) {
            if (!(self->unk19C_0 & 1)) {
                e->unk1C = 4;
                self->unk1EC = 0;
            } else {
                VCALL(e, 18, &self->pos);
            }
        } else {
            self->unk1EC = 0;
        }
    }
    if (self->unk1D4 != 0) {
        e = func_020657b0(data_0214a420, self->unk1D4);
        if (e == NULL) {
            self->unk1D4 = 0;
        } else {
            v1.x = e->unk40.x;
            v1.y = e->unk40.y;
            v1.z = e->unk40.z;
            v1.x += 0x52;
            v1.y += 0x52;
            v1.z += 0xa4;
            VCALL(e, 10, &v1);
            p1 = self->pos;
            p1.y += self->unk6C;
            VCALL(e, 18, &p1);
            VCALL(e, 30, &self->rot);
        }
    }
    if (self->unk1D8 != 0 || self->unk1DC != 0) {
        BOOL set;
        u16 idx = func_ov006_021db060(data_ov006_021ec884, self->unk19E)->unkC & 0xfff;
        u16 rz = self->rot.z;
        u16 ry = self->rot.y;
        u16 rx = self->rot.x;
        set = FALSE;
        MTX_Identity33_(&m);
        if (ry != 0) {
            MTX_RotY33_(&m, OV006_SINCOS[(ry >> 4) * 2], OV006_SINCOS[(ry >> 4) * 2 + 1]);
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_(&t, OV006_SINCOS[(rx >> 4) * 2], OV006_SINCOS[(rx >> 4) * 2 + 1]);
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotX33_(&m, OV006_SINCOS[(rx >> 4) * 2], OV006_SINCOS[(rx >> 4) * 2 + 1]);
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_(&t, OV006_SINCOS[(rz >> 4) * 2], OV006_SINCOS[(rz >> 4) * 2 + 1]);
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotZ33_(&m, OV006_SINCOS[(rz >> 4) * 2], OV006_SINCOS[(rz >> 4) * 2 + 1]);
            }
        }
        r.x = func_01ffc128(self->rot.x, self->look2x, 0x4cd, 1, 0x8000);
        r.y = func_01ffc128(self->rot.y, self->look2y, 0x4cd, 1, 0x8000);
        r.z = self->rot.z;
        if (self->unk1D8 != 0) {
            e = func_020657b0(data_0214a420, self->unk1D8);
            if (e == NULL) {
                self->unk1D8 = 0;
            } else {
                v2.x = e->unk40.x;
                v2.y = e->unk40.y;
                v2.z = e->unk40.z;
                v2.x += 0x29;
                v2.y += 0x29;
                v2.z += 0xa4;
                VCALL(e, 10, &v2);
                MTX_MultVec33(&data_ov006_021eb954[idx].a, &m, &o2);
                VEC_Add(&o2, &self->pos, &o2);
                VCALL(e, 18, &o2);
                VCALL(e, 30, &r);
            }
        }
        if (self->unk1DC != 0) {
            e = func_020657b0(data_0214a420, self->unk1DC);
            if (e == NULL) {
                self->unk1DC = 0;
            } else {
                v3.x = e->unk40.x;
                v3.y = e->unk40.y;
                v3.z = e->unk40.z;
                v3.x += 0x29;
                v3.y += 0x29;
                v3.z += 0xa4;
                VCALL(e, 10, &v3);
                MTX_MultVec33(&data_ov006_021eb954[idx].b, &m, &o3);
                VEC_Add(&o3, &self->pos, &o3);
                VCALL(e, 18, &o3);
                VCALL(e, 30, &r);
            }
        }
    }
    if (self->unk1D0 != 0) {
        e = func_020657b0(data_0214a420, self->unk1D0);
        if (e == NULL) {
            self->unk1D0 = 0;
        } else {
            VCALL(e, 18, &self->pos);
        }
    }
    if (self->unk1E0 != 0) {
        e = func_020657b0(data_0214a420, self->unk1E0);
        if (e == NULL) {
            self->unk1E0 = 0;
        } else {
            VCALL(e, 18, &self->pos);
        }
    }
    if (self->unk1E4 != 0) {
        e = func_020657b0(data_0214a420, self->unk1E4);
        if (e == NULL) {
            self->unk1E4 = 0;
        } else {
            VCALL(e, 18, &self->pos);
        }
    }
    if (self->unk1F0 != 0) {
        e = func_020657b0(data_0214a420, self->unk1F0);
        if (e != NULL) {
            if (self->unk19C_14) {
            ov006_CamRot021e76d8 *c;
            s32 s;
            p4 = self->pos;
            p4.y += 0x800;
            VCALL(e, 18, &p4);
            c = (ov006_CamRot021e76d8 *)(data_ov000_021ccd54 + 0xf4);
            cr.x = c->x;
            cr.y = c->y;
            cr.z = c->z;
            cr.x += 0xc000;
            VCALL(e, 30, &cr);
            s = 0x2000;
            if (self->unk1FC < 10) {
                s += (10 - self->unk1FC) * 0x2800 / 10;
            }
            VCALL(e, 0C, s);
            } else {
                e->unk1C = 4;
                self->unk1F0 = 0;
            }
        } else {
            self->unk1F0 = 0;
        }
    }
}

}
