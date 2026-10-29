#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_0220edd4[];
extern const Ov010Vec data_ov010_0220fa94;
extern u8 data_ov010_0220fa2c[];
extern const char *const data_ov010_0220ebc0[];
extern BOOL func_ov003_021da03c(void *self);
extern BOOL func_ov003_021d98a0(void *p);
extern BOOL func_ov003_021d984c(void *p, void *a);
extern void func_ov003_021d8fc0(void *p);
extern void func_ov003_021d95e8(void *p, void *a, s32 b);
extern void func_ov003_021d97fc(void *p, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d9878(void *p);
struct Ov010B2 {
    u8 a;
    u8 b;
};
extern Ov010B2 func_ov003_021d9644(void *p);
extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);

void func_ov010_021fb95c(void *self) {
    BOOL a;
    BOOL b;
    if (!func_ov003_021da03c(self)) {
        return;
    }
    a = func_ov003_021d98a0((u8 *)self + 0x1ac) ? FALSE : TRUE;
    b = func_ov003_021d984c((u8 *)self + 0x1ac, data_ov010_0220edd4) ? FALSE : TRUE;
    func_ov003_021d8fc0((u8 *)self + 0x1ac);
    if (a && b) {
        u16 *hp = FLD(u16 *, self, 0x50);
        if (((hp[0] << 12) / hp[1]) <= 0x333) {
            func_ov003_021d95e8((u8 *)self + 0x1ac, data_ov010_0220edd4, 0x19);
            func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
            func_ov000_02198360(FLD(void *, self, 0x40), 0x14, 1);
            return;
        }
    }
    if (func_ov003_021d9878((u8 *)self + 0x1ac)) {
        Ov010B2 r = func_ov003_021d9644((u8 *)self + 0x1ac);
        FLD(Ov010B2, self, 0x1bc) = r;
        func_ov000_02198360(FLD(void *, self, 0x40), r.a, 1);
    }
}

void func_ov010_021fba6c(void) {
}

static inline void Ov010Cam_Start(u8 *cam) {
    if (FLD(u8, cam, 0x4) == 0) {
        FLD(u8, cam, 0x4) = 1;
        OV010_BLKCPY(cam + 0x4c, &data_ov010_0220fa94);
        FLD(s16, cam, 0x58) = FLD(s16, data_ov010_0220fa2c, 0x74);
        FLD(s16, cam, 0x5a) = FLD(s16, data_ov010_0220fa2c, 0x76);
        FLD(u16, cam, 0x5c) = FLD(u16, data_ov010_0220fa2c, 0x78);
        FLD(s16, cam, 0x5e) = FLD(s16, data_ov010_0220fa2c, 0x7a);
        FLD(s16, cam, 0x60) = FLD(s16, data_ov010_0220fa2c, 0x7c);
        FLD(s16, cam, 0x62) = FLD(s16, data_ov010_0220fa2c, 0x7e);
        FLD(s16, cam, 0x64) = FLD(s16, data_ov010_0220fa2c, 0x80);
        FLD(s16, cam, 0x66) = FLD(s16, data_ov010_0220fa2c, 0x82);
        func_ov003_021da48c(cam + 0x38, 0);
    }
}

void func_ov010_021fba70(void *self) {
    if (FLD(u16, FLD(u8 *, self, 0x40), 0) != 0) {
        return;
    }
    Ov010Cam_Start(FLD(u8 *, self, 0x104));
    func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220ebc0[8], 0xcd, 0);
    func_ov000_021915a0(FLD(void *, self, 0x38));
    FLD(u16, FLD(u8 *, self, 0x40), 0)++;
}

}
