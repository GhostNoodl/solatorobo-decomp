#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_02210154[];
extern char data_ov010_0220ff84[];
extern char data_ov010_0220ff91[];
extern char data_ov010_0220ffa1[];
extern char data_ov010_0220ffae[];
extern void *data_02097e4c;
extern void func_ov003_021d0c1c(void *self);
extern void *func_ov003_021d0edc(void *self);
extern void func_ov003_021d8f24(void *p);
extern void func_ov003_021d8f34(void *p);
extern void *func_ov010_0220d79c(void *p);
extern void *func_ov010_0220d7c0(void *p);
extern void *func_ov003_021d7f0c(void *p);
extern void *func_ov003_021d7fc0(void *p);
extern void *func_ov003_021d8b88(void *p);
extern void *func_ov003_021d8bb8(void *p);
extern void func_ov003_021cf340(const char *p);
extern void func_ov003_021cf3fc(s32 a);
extern void func_ov003_021cf39c(s32 a, const char *b);
extern void func_ov010_02207520(void *self);
extern void func_ov010_022075bc(void *self);
extern BOOL func_ov000_0218cf5c(void *self);
extern void func_02049678(void *a, s32 b, s32 c, s32 d);
extern BOOL func_0204985c(void *a);
extern void func_ov003_021d883c(void *a, Ov010Vec *b, Ov010Vec *c, s32 d);
extern u16 func_ov003_021d16cc(void *self);

void *func_ov010_02204204(void *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov010_02210154;
    func_ov003_021d8f24((u8 *)self + 0x160);
    func_ov010_0220d79c((u8 *)self + 0x174);
    func_ov003_021d7f0c((u8 *)self + 0x1b0);
    func_ov003_021d8b88((u8 *)self + 0x1dc);
    func_ov003_021cf340(data_ov010_0220ff84);
    func_ov003_021cf3fc(1);
    func_ov003_021cf39c(2, data_ov010_0220ff91);
    func_ov003_021cf39c(0, data_ov010_0220ffa1);
    func_ov003_021cf39c(1, data_ov010_0220ffae);
    func_ov010_02207520(self);
    return self;
}

static inline void Ov010_02204294_Body(void *self) {
    FLD(void *, self, 0) = data_ov010_02210154;
    func_ov003_021cf3fc(0);
    func_ov010_022075bc(self);
    func_ov003_021d8bb8((u8 *)self + 0x1dc);
    func_ov003_021d7fc0((u8 *)self + 0x1b0);
    func_ov010_0220d7c0((u8 *)self + 0x174);
    func_ov003_021d8f34((u8 *)self + 0x160);
    func_ov003_021d0edc(self);
}

void *func_ov010_02204294(void *self) {
    Ov010_02204294_Body(self);
    return self;
}

void *func_ov010_022042e8(void *self) {
    Ov010_02204294_Body(self);
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_02204344(void *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(u8, self, 0xf0) == 0) {
        FLD(u8, self, 0xf0) = 1;
        if (((Ov010V *)self)->va8((u8 *)self + 0x128)) {
            func_02049678(data_02097e4c, 4, FLD(s32, self, 0x128), -1);
        }
        r = FALSE;
    } else if (func_0204985c(data_02097e4c) == 0) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov010_022043c4(void *self) {
    Ov010Vec saved = FLD(Ov010Vec, self, 0x70);
    BOOL r;
    func_ov003_021d883c((u8 *)self + 0x1b0, &FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x70), 0x480);
    r = func_ov003_021d16cc(self);
    FLD(Ov010Vec, self, 0x70) = saved;
    return r;
}

}
