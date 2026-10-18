#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_02216b98[];
extern BOOL func_02035b90(const char *name, s32 a);
extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void func_0203f8d8(void *p);

BOOL func_ov009_02202acc(Ov009Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->kind == 0x5055) {
        r = (r & func_02035b90(data_ov009_02216b98, 7)) ? TRUE : FALSE;
    }
    return r;
}

void func_ov009_02202b14(Ov009Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
    if (FLD(void *, self, 0x58) != NULL) {
        func_0203f8d8(FLD(void *, self, 0x58));
    }
}

extern char data_ov009_02216ba7[];
extern void func_0203f80c(void *p);
extern void func_0203f990(void *p, s32 v);
extern void func_0203f9b8(void *p, s32 v);
extern void func_02011974(void *m, s32 s, s32 c);
extern void func_02011994(void *m, s32 s, s32 c);
extern void func_020119b0(void *m, s32 s, s32 c);
extern void func_02011d40(void *a, void *b, void *out);
extern s32 func_ov000_021909a8(Ov009Sub38 *m, const char *a, const char *b);
extern void func_02011820(void *p);
extern void func_020267e8(void *p, void *cb);
extern void func_ov009_021ff690(Ov009Actor *self);
extern u8 *func_0206fef8(void *res);
extern void func_0203f9dc(void *mesh, const void *mtx);
struct Ov009Mtx43 {
    s32 m[9];
    Ov009Vec t;
};

void func_ov009_02202b48(Ov009Actor *self) {
    Ov009Sub38 *m;
    u8 *c;
    u32 *o;
    u32 v;
    func_ov003_021d112c(self);
    {
        Ov009Sub48 *s48 = self->unk_48;
        FLD(s32, s48, 0x5c) = 0;
        FLD(s32, s48, 0x60) = 0x1800;
        FLD(s32, s48, 0x64) = 0;
    }
    FLD(s32, self, 0xf8) = func_ov000_021909a8(self->unk_38, func_020701d4((void *)self->kind), data_ov009_02216ba7);
    func_02011820(&FLD(u8, self, 0xfc));
    m = self->unk_38;
    func_020267e8(m->unk_24, (void *)func_ov009_021ff690);
    m->unk_c2_5 = 0;
    self->unk_38->unk_c2_8 = 1;
    self->unk_38->unk_50 = &FLD(u8, self, 0xf8);
    {
        Ov009Sub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    self->unk_ea_6 = 1;
    c = func_0206fef8((void *)self->kind);
    o = FLD(u32 *, FLD(u8 *, self, 0x34), 0x84);
    v = o != NULL ? *o : 0;
    if (v != 0) {
        void *p = func_0203dd9c(0x98);
        if (p != NULL) {
            func_0203f80c(p);
        }
        FLD(void *, self, 0x58) = p;
        o = FLD(u32 *, FLD(u8 *, self, 0x34), 0x84);
        func_0203f990(FLD(void *, self, 0x58), o != NULL ? *o : 0);
        func_0203f9b8(FLD(void *, self, 0x58), FLD(s16, c, 0x10));
        {
            void *obj;
            Ov009Mtx43 t;
            Ov009Mtx43 mt;
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set = FALSE;
            rz = self->rot[2];
            obj = FLD(void *, self, 0x58);
            ry = self->rot[1];
            rx = self->rot[0];
            func_02011820(&mt);
            if (rz != 0) {
                func_020119b0(&mt, OV009_SIN(rz), OV009_COS(rz));
                set = TRUE;
            }
            if (ry != 0) {
                if (set) {
                    func_02011994(&t, OV009_SIN(ry), OV009_COS(ry));
                    func_02011d40(&t, &mt, &mt);
                } else {
                    func_02011994(&mt, OV009_SIN(ry), OV009_COS(ry));
                    set = TRUE;
                }
            }
            if (rx != 0) {
                if (set) {
                    func_02011974(&t, OV009_SIN(rx), OV009_COS(rx));
                    func_02011d40(&t, &mt, &mt);
                } else {
                    func_02011974(&mt, OV009_SIN(rx), OV009_COS(rx));
                    set = TRUE;
                }
            }
            mt.t.x = self->pos.x;
            mt.t.y = self->pos.y;
            mt.t.z = self->pos.z;
            func_0203f9dc(obj, &mt);
        }
    }
    self->unk_cc = 0xc000;
}

}
