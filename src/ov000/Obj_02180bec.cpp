#include "ov000/VObj.h"

class Obj021810e8 : public VObj {
public:
    s32 unk_04;
    u8 unk_08[0x30];
    VObj *unk_38;
    s32 unk_3c;
    Obj021810e8 *unk_40;
    Obj021810e8 *unk_44;
    Obj021810e8 *unk_48;
};

typedef struct {
    u8 unk_00[0x14];
    u32 unk_14;
} Data021ccd34Entry;

typedef struct {
    u32 unk_00;
    u32 unk_04;
    Obj021810e8 *unk_08;
    Data021ccd34Entry *unk_0c;
} Data021ccd34;

extern "C" {

extern u8 data_ov000_021cbae0[];
extern u8 data_ov000_021cbb60[];
extern u8 data_ov000_021cbc60[];
extern u8 data_ov000_021cbd60[];
extern u8 data_ov000_021cbde0[];
extern u8 data_ov000_021cbe60[];
extern u8 data_ov000_021cbee0[];
extern u8 data_ov000_021cbf60[];
extern u8 data_ov000_021cbfe0[];
extern u8 data_ov000_021cc060[];
extern u8 data_0208ba70[];
extern u8 data_ov000_021cbac8[];
extern u8 data_ov000_021cbbe0[];
extern u8 data_ov000_021cbce0[];
void func_ov000_021c2310(void *ptr);
extern Data021ccd34 data_ov000_021ccd34;

void func_0203de1c(void *ptr);
void func_ov000_0217fb44(VObj *self);
void func_ov000_02178110(VObj *self);

void func_ov000_02180bec(void) {
}

BOOL func_ov000_02180bf0(void) {
    return TRUE;
}

void func_ov000_02180bf8(void) {
}

void func_ov000_02180bfc(Obj021810e8 *self) {
    Obj021810e8 *obj;
    Obj021810e8 *next;
    if (self->unk_04 == 0 || (obj = data_ov000_021ccd34.unk_08) == NULL) {
        return;
    }
    do {
        next = (Obj021810e8 *)obj->unk_38;
        obj->vfunc_74();
        obj = next;
    } while (obj != NULL);
}

VObj *func_ov000_02180c3c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbf60);
    func_ov000_0217fb44(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02180c80(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbf60);
    func_ov000_0217fb44(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_02180cbc(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbae0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02180d08(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbae0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_02180d4c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbb60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02180d98(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbb60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_02180ddc(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbc60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02180e28(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbc60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_02180e6c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbd60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02180eb8(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbd60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_02180efc(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbde0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02180f48(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbde0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_02180f8c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbe60);
    func_ov000_02178110(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02180fd0(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbe60);
    func_ov000_02178110(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_0218100c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbee0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02181058(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbee0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_0218109c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbfe0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov000_021810e8(Obj021810e8 *self) {
    if (self->unk_3c != 0) {
        return FALSE;
    }
    if (self->vfunc_54()) {
        if (data_ov000_021ccd34.unk_0c != NULL) {
            data_ov000_021ccd34.unk_04 = data_ov000_021ccd34.unk_0c->unk_14;
        } else {
            data_ov000_021ccd34.unk_04 = 0;
        }
        data_ov000_021ccd34.unk_0c = NULL;
    }
    return TRUE;
}

VObj *func_ov000_02181140(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbfe0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_02181184(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbbe0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x3f8), data_0208ba70);
    VOBJ_AT(self, 0x3f8)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x340), data_0208ba70);
    VOBJ_AT(self, 0x340)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x288), data_0208ba70);
    VOBJ_AT(self, 0x288)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x1d0), data_0208ba70);
    VOBJ_AT(self, 0x1d0)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x118), data_0208ba70);
    VOBJ_AT(self, 0x118)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x60), data_0208ba70);
    VOBJ_AT(self, 0x60)->vfunc_08();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

static inline BOOL IsState5(Obj021810e8 *obj) {
    return obj->unk_04 == 5 ? TRUE : FALSE;
}

BOOL func_ov000_02181250(Obj021810e8 *self) {
    if (self->unk_40 != NULL && !IsState5(self->unk_40)) {
        return FALSE;
    }
    if (self->unk_44 != NULL && !IsState5(self->unk_44)) {
        return FALSE;
    }
    if (self->unk_48 != NULL && !IsState5(self->unk_48)) {
        return FALSE;
    }
    if (self->vfunc_54()) {
        if (data_ov000_021ccd34.unk_0c != NULL) {
            data_ov000_021ccd34.unk_04 = data_ov000_021ccd34.unk_0c->unk_14;
        } else {
            data_ov000_021ccd34.unk_04 = 0;
        }
        data_ov000_021ccd34.unk_0c = NULL;
    }
    return TRUE;
}

VObj *func_ov000_02181310(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbbe0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x3f8), data_0208ba70);
    VOBJ_AT(self, 0x3f8)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x340), data_0208ba70);
    VOBJ_AT(self, 0x340)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x288), data_0208ba70);
    VOBJ_AT(self, 0x288)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x1d0), data_0208ba70);
    VOBJ_AT(self, 0x1d0)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x118), data_0208ba70);
    VOBJ_AT(self, 0x118)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x60), data_0208ba70);
    VOBJ_AT(self, 0x60)->vfunc_08();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_021813d4(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbce0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02181420(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbce0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_02181464(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbac8);
    func_ov000_021c2310(self);
    func_0203de1c(self);
    return self;
}

void func_ov000_0218148c(void) {
}

void func_ov000_02181490(void) {
}

VObj *func_ov000_02181494(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbac8);
    func_ov000_021c2310(self);
    return self;
}

VObj *func_ov000_021814b4(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

}
