#include "ov010/ov010.h"

extern "C" {

static inline void Ov010_0220a948_Set(void *self, u16 c, u16 d, s32 mode, s32 a, s32 b) {
    FLD(u16, self, 0xd0) = c;
    FLD(u16, self, 0xd2) = d;
    FLD(s32, self, 0xdc) = mode;
    FLD(s32, self, 0xe0) = a;
    FLD(s32, self, 0xe4) = b;
}

void func_ov010_0220a948(void *self, s32 mode, s32 a, s32 b, u16 c, u16 d) {
    switch (mode) {
    case 0:
        Ov010_0220a948_Set(self, c, d, mode, a, 0);
        break;
    case 1:
        Ov010_0220a948_Set(self, c, d, mode, 0, b);
        break;
    }
}


struct Ov010Mtx33a {
    s32 m[9];
};

extern void *data_ov000_021ccd68;
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void MTX_Identity33_(Ov010Mtx33a *m);
extern void MTX_RotX33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_Concat33(Ov010Mtx33a *a, Ov010Mtx33a *b, Ov010Mtx33a *out);
extern void MI_Copy36B(const void *src, void *dst);
extern void func_ov000_02194c08(void *self);

void func_ov010_0220a9a8(u8 *self) {
    Ov010Mtx33a out;
    Ov010Mtx33a tc;
    Ov010Mtx33a ma;
    Ov010Mtx33a mb;
    Ov010Mtx33a ta;
    Ov010Mtx33a tb;
    u8 *o;
    FLD(Ov010Flags8, self, 0x93).b0 = 1;
    o = NULL;
    if (FLD(s32, self, 0xd8) == 7) {
        void *mgr = data_ov000_021ccd68;
        u16 id = FLD(u16, self, 0x180);
        if (mgr != NULL) {
            o = func_ov000_0218e640(mgr, id);
        }
    }
    if (o != NULL) {
        BOOL set2;
        BOOL set;
        u16 dz;
        u16 az;
        u16 ay;
        u16 ax;
        u16 dx;
        u16 dy;
        dx = FLD(u16, o, 0x7c) - FLD(u16, self, 0x190);
        dy = FLD(u16, o, 0x7e) - FLD(u16, self, 0x192);
        dz = FLD(u16, o, 0x80) - FLD(u16, self, 0x194);
        az = FLD(u16, self, 0x19a);
        ay = FLD(u16, self, 0x198);
        ax = FLD(u16, self, 0x196);
        set = FALSE;
        MTX_Identity33_(&ma);
        if (az != 0) {
            MTX_RotZ33_(&ma, OV010_SIN(az), OV010_COS(az));
            set = TRUE;
        }
        if (ay != 0) {
            if (set) {
                MTX_RotY33_(&ta, OV010_SIN(ay), OV010_COS(ay));
                MTX_Concat33(&ta, &ma, &ma);
            } else {
                MTX_RotY33_(&ma, OV010_SIN(ay), OV010_COS(ay));
                set = TRUE;
            }
        }
        if (ax != 0) {
            if (set) {
                MTX_RotX33_(&ta, OV010_SIN(ax), OV010_COS(ax));
                MTX_Concat33(&ta, &ma, &ma);
            } else {
                MTX_RotX33_(&ma, OV010_SIN(ax), OV010_COS(ax));
                set = TRUE;
            }
        }
        set2 = FALSE;
        MTX_Identity33_(&mb);
        if (dz != 0) {
            MTX_RotZ33_(&mb, OV010_SIN(dz), OV010_COS(dz));
            set2 = TRUE;
        }
        if (dy != 0) {
            if (set2) {
                MTX_RotY33_(&tb, OV010_SIN(dy), OV010_COS(dy));
                MTX_Concat33(&tb, &mb, &mb);
            } else {
                MTX_RotY33_(&mb, OV010_SIN(dy), OV010_COS(dy));
                set2 = TRUE;
            }
        }
        if (dx != 0) {
            if (set2) {
                MTX_RotX33_(&tb, OV010_SIN(dx), OV010_COS(dx));
                MTX_Concat33(&tb, &mb, &mb);
            } else {
                MTX_RotX33_(&mb, OV010_SIN(dx), OV010_COS(dx));
                set2 = TRUE;
            }
        }
        MTX_Concat33(&ma, &mb, &out);
    } else {
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set;
        rz = FLD(u16, self, 0x80);
        ry = FLD(u16, self, 0x7e);
        rx = FLD(u16, self, 0x7c);
        set = FALSE;
        MTX_Identity33_(&out);
        if (rz != 0) {
            MTX_RotZ33_(&out, OV010_SIN(rz), OV010_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY33_(&tc, OV010_SIN(ry), OV010_COS(ry));
                MTX_Concat33(&tc, &out, &out);
            } else {
                MTX_RotY33_(&out, OV010_SIN(ry), OV010_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_(&tc, OV010_SIN(rx), OV010_COS(rx));
                MTX_Concat33(&tc, &out, &out);
            } else {
                MTX_RotX33_(&out, OV010_SIN(rx), OV010_COS(rx));
                set = TRUE;
            }
        }
    }
    MI_Copy36B(&out, FLD(u8 *, self, 0x38) + 0x84);
    {
        u8 *m = FLD(u8 *, self, 0x38);
        FLD(s32, m, 0x78) = FLD(s32, self, 0x70);
        FLD(s32, m, 0x7c) = FLD(s32, self, 0x74);
        FLD(s32, m, 0x80) = FLD(s32, self, 0x78);
    }
    func_ov000_02194c08(self);
}

}
