#include "ov000/LoCommon.h"

typedef struct {
    u8 pad_00[0x8];
    char *unk_08;
    char *unk_0c;
    u8 unk_10;
    u8 pad_11[3];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    VObj *unk_20;
    VObj *unk_24;
    s32 unk_28;
} Loader021633ac;

extern "C" {
extern u8 *data_ov000_021ccd70;
extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u8 data_0208ba70[];
extern u8 data_0208bbc8[];
void func_ov000_021bc3ec(void *f, s32 a, s32 b);
void func_ov000_021bc458(void *f);
void func_0204bfcc(void *res);
void func_0204bfe4(void *res, const char *arc, const char *name);
void func_0204c030(void *res);
s32 func_0204c08c(void *res, u16 id, s32 *out, s32 d);
void func_0204c7d0(void *p);
void func_02050f70(void *p);

static inline BOOL Fade021633ac_Done(void) {
    return LFLD(s32, data_ov000_021ccd70, 4) == 0 ? TRUE : FALSE;
}

static inline VObj *Res021633ac_New(const char *arc, const char *name) {
    VObj *o = (VObj *)func_0203dd9c(0x58);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208b318);
        o->vfunc_08();
        VOBJ_SET_VTABLE(o, data_0208ba30);
        func_0204bfcc(o);
    }
    func_0204bfe4(o, arc, name);
    return o;
}

BOOL func_ov000_021633ac(Loader021633ac *self) {
    BOOL ret = TRUE;
    VObj *o;
    switch (self->unk_28) {
    case 0:
        func_ov000_021bc3ec(data_ov000_021ccd70, 3, 0xa000);
        self->unk_24 = Res021633ac_New(self->unk_08, self->unk_0c);
        self->unk_28 = 1;
    case 1:
        if (self->unk_24->vfunc_2c()) {
            self->unk_28 = 2;
        }
        break;
    case 2:
        func_0204c030(self->unk_24);
        self->unk_18 = func_0204c08c(self->unk_24, self->unk_14, &self->unk_1c, 1);
        o = (VObj *)func_0203dd9c(0xb80);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_0208ba70);
            func_0204c7d0(o);
            VOBJ_SET_VTABLE(o, data_0208bbc8);
            func_02050f70(o);
        }
        self->unk_20 = o;
        LFLD(s32, o, 0x28) = 8;
        {
            s32 a = self->unk_18;
            u8 *p = (u8 *)self->unk_20;
            LFLD(s32, p, 0xb7c) = self->unk_1c;
            LFLD(s32, p, 0xb70) = 0;
            LFLD(s32, p, 0xb74) = a;
        }
        LFLD(u32, self->unk_20, 0xb8) = (LFLD(u32, self->unk_20, 0xb8) & ~0xf) | 4;
        if (self->unk_10) {
            LFLD(u32, self->unk_20, 0xbc) |= 0x80;
        }
        LFLD(u32, self->unk_20, 0x4) |= 4;
        self->unk_28 = 3;
        break;
    case 3:
        if (!self->unk_20->vfunc_8c()) {
            func_ov000_021bc458(data_ov000_021ccd70);
            self->unk_28 = 4;
        }
        break;
    case 4:
        if (Fade021633ac_Done()) {
            ret = FALSE;
        }
        break;
    }
    return ret;
}
}
