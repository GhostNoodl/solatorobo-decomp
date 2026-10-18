#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_0220fccc[];
extern char data_ov010_0220fbd0[];
extern char data_ov010_0220fbdd[];
extern char data_ov010_0220fbec[];
extern char data_ov010_0220fbf7[];
extern char data_ov010_0220fc02[];
extern void *data_02097e4c;
extern void *data_0214a420;

extern void func_ov003_021d0c1c(void *self);
extern void func_ov003_021d0edc(void *self);
extern void func_ov003_021d7f0c(void *p);
extern void func_ov010_02201914(void *p);
extern void func_ov003_021cf2bc(void *p);
extern void func_ov003_021d8f24(void *p);
extern void func_ov003_021d8910(void *p);
extern void func_ov003_021cf418(void *p);
extern void func_ov003_021cf340(const char *p);
extern void func_ov003_021cf3fc(s32 a);
extern void func_ov003_021cf39c(s32 a, const char *b);
extern void func_ov010_021fedd4(void *self);
extern void func_02049bb4(void *a, s32 b);
extern void func_ov010_021fee70(void *self);
extern void func_ov003_021cf428(void *p);
extern void func_ov003_021d8928(void *p);
extern void func_ov003_021d8f34(void *p);
extern void func_ov003_021cf2d8(void *p);
extern void func_ov010_02201944(void *p);
extern void func_ov003_021d7fc0(void *p);
extern void func_02065804(void *a, s32 b);
extern BOOL func_ov000_0218cf5c(void *self);
extern void func_02049564(void *a, s32 b, s32 c);
extern void func_02049678(void *a, s32 b, s32 c, s32 d);
extern BOOL func_0204985c(void *a);

void *func_ov010_021fa860(void *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov010_0220fccc;
    FLD(Ov010Flags8, self, 0x138).b0 = 0;
    func_ov003_021d7f0c((u8 *)self + 0x150);
    func_ov010_02201914((u8 *)self + 0x17c);
    func_ov003_021cf2bc((u8 *)self + 0x19c);
    func_ov003_021d8f24((u8 *)self + 0x1ac);
    func_ov003_021d8910((u8 *)self + 0x1c0);
    func_ov003_021cf418((u8 *)self + 0x1d0);
    func_ov003_021cf340(data_ov010_0220fbd0);
    func_ov003_021cf3fc(1);
    func_ov003_021cf39c(0, data_ov010_0220fbdd);
    func_ov003_021cf39c(1, data_ov010_0220fbec);
    func_ov003_021cf39c(2, data_ov010_0220fbf7);
    func_ov003_021cf39c(3, data_ov010_0220fc02);
    func_ov010_021fedd4(self);
    return self;
}

static inline void Ov010_021fa91c_Body(void *self) {
    FLD(void *, self, 0) = data_ov010_0220fccc;
    func_ov003_021cf3fc(0);
    func_02049bb4(data_02097e4c, FLD(s32, self, 0x11c));
    func_ov010_021fee70(self);
    func_ov003_021cf428((u8 *)self + 0x1d0);
    func_ov003_021d8928((u8 *)self + 0x1c0);
    func_ov003_021d8f34((u8 *)self + 0x1ac);
    func_ov003_021cf2d8((u8 *)self + 0x19c);
    func_ov010_02201944((u8 *)self + 0x17c);
    func_ov003_021d7fc0((u8 *)self + 0x150);
    if (FLD(Ov010Flags8, self, 0x138).b0) {
        func_02065804(data_0214a420, FLD(s32, self, 0x148));
        FLD(Ov010Flags8, self, 0x138).b0 = 0;
    }
    func_ov003_021d0edc(self);
}

void *func_ov010_021fa91c(void *self) {
    Ov010_021fa91c_Body(self);
    return self;
}

void *func_ov010_021fa9c4(void *self) {
    Ov010_021fa91c_Body(self);
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_021faa74(void *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (!FLD(Ov010Flags8, self, 0xf0).b0) {
        FLD(Ov010Flags8, self, 0xf0).b0 = 1;
        func_02049564(data_02097e4c, 1, 1);
        func_02049678(data_02097e4c, 4, 0xb, -1);
        r = FALSE;
    } else if (func_0204985c(data_02097e4c) == 0) {
        r = FALSE;
    }
    return r;
}

extern void func_ov003_021cf4ec(void *p);
extern void func_020114a4(void *m, s32 s, s32 c);
extern void func_0201146c(void *m, s32 s, s32 c);
extern void func_02011488(void *m, s32 s, s32 c);
extern void func_02011610(void *a, void *b, void *c);
extern void func_ov003_021d883c(void *a, Ov010Vec *b, void *c, s32 d);
extern void func_02016dbc(void *m, void *b);
extern BOOL func_ov003_021d16cc(void *self);
extern void func_ov010_0220166c(void *p);

BOOL func_ov010_021faaf0(void *self) {
    BOOL r;
    u8 m1[0x24];
    u8 m2[0x24];
    Ov010Vec v;
    func_ov003_021cf4ec((u8 *)self + 0x1d0);
    func_020114a4(m1, OV010_SIN(FLD(u16, self, 0x80)), OV010_COS(FLD(u16, self, 0x80)));
    func_0201146c(m2, OV010_SIN(FLD(u16, self, 0x7c)), OV010_COS(FLD(u16, self, 0x7c)));
    func_02011610(m1, m2, m1);
    func_02011488(m2, OV010_SIN(FLD(u16, self, 0x7e)), OV010_COS(FLD(u16, self, 0x7e)));
    func_02011610(m1, m2, m1);
    func_ov003_021d883c((u8 *)self + 0x150, &v, (u8 *)self + 0x70, FLD(s16, self, 0xf2));
    FLD(Ov010Flags8, self, 0x93).b0 = 1;
    func_02016dbc(m1, FLD(u8 *, self, 0x38) + 0x84);
    FLD(Ov010Vec, FLD(u8 *, self, 0x38), 0x78) = v;
    r = func_ov003_021d16cc(self);
    func_ov010_0220166c(FLD(void *, self, 0x100));
    return r;
}

}
