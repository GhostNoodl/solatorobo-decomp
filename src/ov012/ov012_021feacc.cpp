#include "ov012/ov012.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov012_0220a4a4[];
extern u8 data_ov012_0220a4a8[];
extern u8 data_ov012_0220a4ac[];
extern u8 data_ov012_0220a4bc[];
extern u8 data_ov012_0220a4c0[];
extern u8 data_ov012_0220a4c4[];
extern void func_02049f44(void *a, s32 b, Ov012Vec *c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void VEC_MultAdd(s32 s, const Ov012Vec *a, const Ov012Vec *b, Ov012Vec *out);
extern s32 VEC_Distance(const Ov012Vec *a, const Ov012Vec *b);

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
