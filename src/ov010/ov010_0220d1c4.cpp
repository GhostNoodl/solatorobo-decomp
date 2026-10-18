#include "ov010/ov010.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern BOOL func_ov003_021d7a44(void *self, const Ov010Vec *target, const Ov010Vec *start, s32 speed, s32 maxDist, u8 noSnap);
extern void func_0204a028(void *mgr, s32 id, const Ov010Vec *pos, s32 a);
extern Ov010V *func_02065f88(s32 id, const Ov010Vec *pos);
extern void func_ov010_02209074(void);

static inline u8 *Ov010_FindActorD(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov010_0220d1c4(u8 *self) {
    switch (FLD(u16, self, 0x16c)) {
    case 0: {
        u8 *t = Ov010_FindActorD(FLD(u16, self, 0xd0));
        if (t != NULL && FLD(s32, self, 0xd8) == 1) {
            Ov010Vec p;
            Ov010Vec q;
            Ov010V *e;
            FLD(s32, self, 0xd8) = 3;
            Ov010_VecCopy(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, t, 0x70));
            VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xfc), &FLD(Ov010Vec, self, 0x70));
            FLD(u16, self, 0x7c) = 0xbfff;
            FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
            p.x = FLD(s32, self, 0x70);
            p.y = FLD(s32, self, 0x74) + 0xa000;
            p.z = FLD(s32, self, 0x78);
            func_ov003_021d7a44(self + 0x120, &p, &FLD(Ov010Vec, self, 0x70), 0x29, 0x4cd, 0);
            func_0204a028(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 5);
            OV010_BLKCPY(&q, self + 0x70);
            e = func_02065f88(0x321, &q);
            e->v0c(0x1000);
            FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
            FLD(s32, e, 4) = 6;
            FLD(u16, self, 0x16c) = 1;
        } else {
            FLD(u16, self, 0x16c) = 2;
        }
        break;
    }
    case 1: {
        Ov010Vec *v = (Ov010Vec *)((Ov010V *)(self + 0x120))->v10();
        FLD(s32, self, 0x70) = v->x;
        FLD(s32, self, 0x74) = v->y;
        FLD(s32, self, 0x78) = v->z;
        if (((Ov010V *)(self + 0x120))->v14()) {
            FLD(u16, self, 0x16c) = 2;
        }
        break;
    }
    case 2:
        FLD(s32, self, 0xd8) = 2;
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
        ((Ov010V *)(self + 0x120))->v08();
        FLD(Ov010Flags8, self, 0xce).b1 = 0;
        break;
    }
}

}
