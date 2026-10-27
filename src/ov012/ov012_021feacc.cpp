#include "ov012/ov012.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov012_0220a4a4[];
extern u8 data_ov012_0220a4a8[];
extern u8 data_ov012_0220a4ac[];
extern u8 data_ov012_0220a4bc[];
extern u8 data_ov012_0220a4c0[];
extern u8 data_ov012_0220a4c4[];
extern void func_ov000_0218996c(u8 a, u8 b);
extern void VEC_MultAdd(s32 s, const Ov012Vec *a, const Ov012Vec *b, Ov012Vec *out);
extern s32 VEC_Distance(const Ov012Vec *a, const Ov012Vec *b);


static inline s32 Ov012_FxMulFe8b4(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov012_021fe8b4(Ov012Actor *self, const Ov012Vec *p, u8 n) {
    Ov012Vec d;
    d.x = p->x - self->pos.x;
    d.y = p->y - self->pos.y;
    d.z = p->z - self->pos.z;
    func_01ffc9fc(&d, &d, 0xffff - self->rot[1]);
    func_ov000_0218d918(self, (u8 *)self + 0x124, FLD(s32, self, 0x130));
    switch (FLD(u8, self, 0x134)) {
    case 0:
        if (d.x > 0 && !(FLD(u32, self, 0x10c) & 0x1000000)) {
            if (FLD(u8, self, 0x135) == 0) {
                FLD(u8, self, 0x135) = n;
            }
            if (--FLD(u8, self, 0x135) == 0) {
                FLD(u32, self, 0x10c) |= 0x1000000;
            }
        }
        if ((self->rot[1] < 0xe87a && self->rot[1] > 0xbff4) || (FLD(u32, self, 0x10c) & 0x1000000)) {
            FLD(s32, self, 0x124) = Ov012_FxMulFe8b4(FLD(s32, self, 0x124), -0x1000);
            FLD(u8, self, 0x134) = 1;
            FLD(u8, self, 0x135) = 0;
            if (FLD(u32, self, 0x10c) & 0x1000000) {
                FLD(u32, self, 0x10c) ^= 0x1000000;
            }
        }
        break;
    case 1:
        if (d.x < 0 && !(FLD(u32, self, 0x10c) & 0x1000000)) {
            if (FLD(u8, self, 0x135) == 0) {
                FLD(u8, self, 0x135) = n;
            }
            if (--FLD(u8, self, 0x135) == 0) {
                FLD(u32, self, 0x10c) |= 0x1000000;
            }
        }
        if ((self->rot[1] > 0x1776 && self->rot[1] < 0x4000) || (FLD(u32, self, 0x10c) & 0x1000000)) {
            FLD(s32, self, 0x124) = Ov012_FxMulFe8b4(FLD(s32, self, 0x124), -0x1000);
            FLD(u8, self, 0x134) = 0;
            FLD(u8, self, 0x135) = 0;
            if (FLD(u32, self, 0x10c) & 0x1000000) {
                FLD(u32, self, 0x10c) ^= 0x1000000;
            }
        }
        break;
    }
}

struct Ov012Feacc {
    u8 pad[0x394];
    Ov012Vec v[2];
};

void func_ov012_021feacc(u8 *self, s32 i) {
    switch (FLD(u8, self, 0x3ae)) {
    case 0:
        func_02049f44(data_02097e4c, 0x46, &((Ov012Feacc *)self)->v[i], 0);
        FLD(u8, self, 0x3af) |= 0x10;
        FLD(u8, self, 0x3ae)++;
    case 1: {
        Ov012Vec d;
        s32 tx, ty, tz;
        tx = FLD(s32, data_ov012_0220a4a4, i * 12);
        d.x = tx - ((Ov012Vec *)(self + 0x394))[i].x;
        ty = FLD(s32, data_ov012_0220a4a8, i * 12);
        d.y = ty - ((Ov012Feacc *)self)->v[i].y;
        tz = FLD(s32, data_ov012_0220a4ac, i * 12);
        d.z = tz - ((Ov012Feacc *)self)->v[i].z;
        VEC_MultAdd(0x171, &d, &((Ov012Feacc *)self)->v[i], &((Ov012Feacc *)self)->v[i]);
        if (VEC_Distance(&((Ov012Feacc *)self)->v[i], (Ov012Vec *)(data_ov012_0220a4a4 + i * 12)) >= 0x4cd) {
            return;
        }
        ((Ov012Vec *)(self + 0x394))[i].x = tx;
        ((Ov012Feacc *)self)->v[i].y = ty;
        ((Ov012Feacc *)self)->v[i].z = tz;
        func_ov000_0218996c(7, 0xf);
        if (FLD(u8, self, 0x3af) & 0x10) {
            func_02049f44(data_02097e4c, 0x47, &((Ov012Feacc *)self)->v[i], 0);
            FLD(u8, self, 0x3af) ^= 0x10;
        }
        switch (i) {
        case 0:
            if (FLD(u8, self, 0x3af) & 1) {
                FLD(u8, self, 0x3af) ^= 1;
            }
            break;
        case 1:
            if (FLD(u8, self, 0x3af) & 2) {
                FLD(u8, self, 0x3af) ^= 2;
            }
            break;
        }
        break;
    }
    }
}

void func_ov012_021fec58(u8 *self, s32 i) {
    switch (FLD(u8, self, 0x3ae)) {
    case 0:
        func_02049f44(data_02097e4c, 0x18, &((Ov012Feacc *)self)->v[i], 0);
        FLD(u8, self, 0x3af) |= 0x10;
        FLD(u8, self, 0x3ae)++;
        break;
    case 1:
        if (FLD(u8, self + 0x3ac, i)++ <= 0x14) {
            return;
        }
        if (FLD(u8, self, 0x3af) & 0x10) {
            func_02049f44(data_02097e4c, 0x46, &((Ov012Feacc *)self)->v[i], 0);
            FLD(u8, self, 0x3af) ^= 0x10;
        }
        FLD(u8, self + 0x3ac, i) = 0;
        FLD(u8, self, 0x3ae)++;
        break;
    case 2: {
        Ov012Vec d;
        s32 tx, ty, tz;
        tx = FLD(s32, data_ov012_0220a4bc, i * 12);
        d.x = tx - ((Ov012Vec *)(self + 0x394))[i].x;
        ty = FLD(s32, data_ov012_0220a4c0, i * 12);
        d.y = ty - ((Ov012Feacc *)self)->v[i].y;
        tz = FLD(s32, data_ov012_0220a4c4, i * 12);
        d.z = tz - ((Ov012Feacc *)self)->v[i].z;
        VEC_MultAdd(0xa4, &d, &((Ov012Feacc *)self)->v[i], &((Ov012Feacc *)self)->v[i]);
        if (VEC_Distance(&((Ov012Feacc *)self)->v[i], (Ov012Vec *)(data_ov012_0220a4bc + i * 12)) >= 0x2000) {
            return;
        }
        ((Ov012Vec *)(self + 0x394))[i].x = tx;
        ((Ov012Feacc *)self)->v[i].y = ty;
        ((Ov012Feacc *)self)->v[i].z = tz;
        switch (i) {
        case 0:
            if (FLD(u8, self, 0x3af) & 4) {
                FLD(u8, self, 0x3af) ^= 4;
            }
            break;
        case 1:
            if (FLD(u8, self, 0x3af) & 8) {
                FLD(u8, self, 0x3af) ^= 8;
            }
            break;
        }
        break;
    }
    }
}

}
