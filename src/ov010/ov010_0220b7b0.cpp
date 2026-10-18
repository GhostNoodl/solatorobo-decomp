#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_0220f534[];
extern void *data_ov000_021ccd68;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_ov010_02209074(void *p);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov000_02190cb0(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov000_02195d88(void *self);

static inline void *Ov010_FindObjById(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return NULL;
}

void func_ov010_0220b7b0(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    Ov010Vec p = FLD(Ov010Vec, self, 0x70);
    Ov010V *fx;
    void *obj;
    fx = func_02065f88(0x321, &p);
    fx->v0c(0x1000);
    FLD(void *, fx, 0xdc) = (void *)func_ov010_02209074;
    FLD(s32, fx, 4) = 6;
    obj = Ov010_FindObjById(FLD(u16, self, 0x180));
    if (obj != NULL) {
        u8 c = 1;
        func_ov000_0218d398(obj, FLD(u16, self, 0xc), 0xe, 1, 1, &c);
    }
    FLD(Ov010Flags, FLD(void *, self, 0x38), 0xc2).b0 = 0;
    FLD(u8, self, 0xcf) = 0;
    func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
}

void func_ov010_0220b890(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    if (FLD(void *, self, 0x38) != NULL) {
        func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(s32, data_ov010_0220f534, 0xc), 0x1000, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
    }
    FLD(u16, FLD(void *, self, 0x40), 0) = 1;
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
}

void func_ov010_0220b8f8(void *self) {
    u8 *p = func_ov000_02190a30(FLD(void *, self, 0x38), 0);
    FLD(Ov010Flags8, p, 0x111).b3 = 0;
    func_ov000_02195d88(self);
}

}
