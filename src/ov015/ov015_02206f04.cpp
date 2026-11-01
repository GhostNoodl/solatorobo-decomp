#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212a88[];
extern u8 data_ov015_02212a08[];
void *func_02043548(void *p);
void func_020434e0(void *p);
extern u8 data_ov015_02212c08[];
extern u8 data_ov015_02212b88[];
extern u8 data_ov015_02212b08[];
extern u8 data_ov015_022129e0[];
extern u8 data_ov015_0221280c[];
void func_ov000_02180754(void);
void func_ov015_021fa6cc(void *p);
extern void *data_ov000_021ccd40;
extern void *data_ov000_021ccd38;
void func_ov015_02205c7c(void *p);
void func_ov015_02204110(void *p);
void func_ov015_02203020(void *p);
void func_02041558(void *p);
void func_02041278(void *p);
extern u8 data_ov015_022129c0[];
void func_ov000_02163254(void *p);
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218fe1c(void *p);
void *func_ov000_0218fee4(void *p);
void *func_ov000_021919c8(void *p);
void __cxa_vec_ctor(void *p, s32 n, s32 size, void *ctor, void *dtor);
extern void **data_0214a420;
s32 func_02065748(void *a, void *b);
void *func_ov000_02191a24(void *p);
void *func_ov000_0218ea20(void *p);
void __cxa_vec_cleanup(void *p, s32 n, s32 size, void *dtor);
void func_01ffc9fc(Ov015V3 *in, Ov015V3 *out, u16 ang);
void VEC_Add(const void *a, const void *b, void *out);

void *func_ov015_02206f04(void) {
    u8 *p = (u8 *)func_0203dd9c(0x58);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212a88);
        FLD(s32, p, 0x3c) = 0;
        FLD(u8, p, 0x40) = 0;
        FLD(s32, p, 0x44) = 0;
        FLD(s32, p, 0x48) = 0;
        FLD(s32, p, 0x4c) = 0;
        FLD(s32, p, 0x50) = 0;
        FLD(s32, p, 0x54) = 0;
    }
    VCALL(p)->v08(0x1e, 0xc8);
    return p;
}

void *func_ov015_02206f7c(void) {
    u8 *p = (u8 *)func_0203dd9c(0xb0);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212a08);
        func_02043548(p + 0x44);
        func_020434e0(p + 0x68);
        FLD(s32, p, 0x3c) = 0;
        FLD(s32, p, 0x40) = 0;
        FLD(s32, p, 0x80) = 0;
        FLD(s32, p, 0x84) = 0;
        FLD(s32, p, 0x88) = 0;
        FLD(s32, p, 0x8c) = 0;
        FLD(s32, p, 0x90) = 0;
        FLD(s32, p, 0x94) = 0;
        FLD(s32, p, 0x98) = 0;
        FLD(s32, p, 0x9c) = 0;
        FLD(s32, p, 0xa0) = 0;
        FLD(u8, p, 0xa4) = 0;
        FLD(s32, p, 0xa8) = 0;
        FLD(s32, p, 0xac) = 0;
    }
    VCALL(p)->v08(0x1f, 0xc8);
    return p;
}

void *func_ov015_02207020(void) {
    u8 *p = (u8 *)func_0203dd9c(0x6c);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212c08);
        FLD(s32, p, 0x3c) = 0;
        FLD(s32, p, 0x40) = 0;
        FLD(s32, p, 0x44) = 0;
        FLD(s32, p, 0x48) = 0;
        FLD(s32, p, 0x4c) = 0;
        FLD(s32, p, 0x50) = 0;
        FLD(s32, p, 0x54) = 0;
        FLD(s32, p, 0x58) = 1;
        FLD(s32, p, 0x5c) = 0;
        FLD(s32, p, 0x60) = 0;
        FLD(s32, p, 0x64) = 0;
        FLD(u16, p, 0x68) = 0xa000;
        FLD(u8, p, 0x6a) = 0;
    }
    VCALL(p)->v08(0x20, 0xc8);
    return p;
}

void *func_ov015_022070b8(void) {
    u8 *p = (u8 *)func_0203dd9c(0x58);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212b88);
        FLD(s32, p, 0x3c) = 0;
        FLD(s32, p, 0x40) = 0;
        FLD(s32, p, 0x44) = 0;
        FLD(s32, p, 0x48) = 0;
        FLD(s32, p, 0x4c) = 0;
        FLD(s32, p, 0x50) = 1;
        FLD(u16, p, 0x54) = 0xffff;
    }
    VCALL(p)->v08(0x21, 0xc8);
    return p;
}

void *func_ov015_02207138(void) {
    u8 *p = (u8 *)func_0203dd9c(0x164);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212b08);
        FLD(s32, p, 0x3c) = 0;
        FLD(s32, p, 0x40) = 0;
        FLD(s32, p, 0x44) = 0;
        FLD(s32, p, 0x48) = 0;
        FLD(s32, p, 0x4c) = 0;
        FLD(s32, p, 0x50) = 0;
        FLD(s32, p, 0x54) = 3;
        FLD(s32, p, 0x58) = 0;
        FLD(s32, p, 0x5c) = 0;
        FLD(s32, p, 0x60) = 0;
        FLD(u8, p, 0x64) = 0;
    }
    VCALL(p)->v08(0x22, 0xc8);
    return p;
}

void *func_ov015_022071c4(void *self) {
    SET_VT(self, data_ov015_022129e0);
    func_ov000_02180754();
    SET_VT(self, data_ov015_0221280c);
    func_ov015_021fa6cc(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_02207200(void *self) {
    SET_VT(self, data_ov015_022129e0);
    func_ov000_02180754();
    SET_VT(self, data_ov015_0221280c);
    func_ov015_021fa6cc(self);
    return self;
}

void func_ov015_02207234(void *p) {
    if (data_ov000_021ccd40 != NULL) {
        data_ov000_021ccd38 = FLD(void *, data_ov000_021ccd40, 0x14);
    } else {
        data_ov000_021ccd38 = NULL;
    }
    data_ov000_021ccd40 = p;
}

void func_ov015_02207268(Ov015Task *self) {
    if (VCALL(self)->v54() == 0) {
        return;
    }
    if (data_ov000_021ccd40 != NULL) {
        data_ov000_021ccd38 = FLD(void *, data_ov000_021ccd40, 0x14);
    } else {
        data_ov000_021ccd38 = NULL;
    }
    data_ov000_021ccd40 = NULL;
}

static inline bool Ov015Task_Test(Ov015Task *t, u32 mask) {
    return FLD(u32, t, 0x4) & mask;
}

bool func_ov015_022072b8(Ov015Task *self, u32 mask) {
    BOOL r = Ov015Task_Test(self, mask);
    return r;
}

void func_ov015_022072d8(Ov015Task *self) {
    self->flag7 = 0;
}

void func_ov015_022072e8(Ov015Task *self) {
    self->flag7 = 1;
}

static inline bool Ov015Task_Get_flag6(Ov015Task *t) {
    return t->flag6;
}

bool func_ov015_022072f8(Ov015Task *self) {
    BOOL r = Ov015Task_Get_flag6(self);
    return r;
}

void func_ov015_0220731c(Ov015Task *self) {
    self->flag6 = 1;
}

static inline bool Ov015Task_Get_flag5(Ov015Task *t) {
    return t->flag5;
}

bool func_ov015_0220732c(Ov015Task *self) {
    BOOL r = Ov015Task_Get_flag5(self);
    return r;
}

void func_ov015_02207350(Ov015Task *self) {
    self->flag5 = 1;
}

void func_ov015_02207360(Ov015Task *self) {
    self->flag4 = 0;
}

void func_ov015_02207370(Ov015Task *self) {
    self->flag4 = 1;
}

s32 func_ov015_02207380(void) {
    return 1;
}

void *func_ov015_02207388(void *self) {
    SET_VT(self, data_ov015_02212b08);
    func_ov015_02205c7c(self);
    Ov015TaskBase_Dtor(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_022073cc(void *self) {
    SET_VT(self, data_ov015_02212b08);
    func_ov015_02205c7c(self);
    Ov015TaskBase_Dtor(self);

    return self;
}

void *func_ov015_02207408(void *self) {
    SET_VT(self, data_ov015_02212c08);
    func_ov015_02204110(self);
    Ov015TaskBase_Dtor(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_0220744c(void *self) {
    SET_VT(self, data_ov015_02212c08);
    func_ov015_02204110(self);
    Ov015TaskBase_Dtor(self);

    return self;
}

void *func_ov015_02207488(void *self) {
    SET_VT(self, data_ov015_02212a08);
    func_ov015_02203020(self);
    Ov015TaskBase_Dtor(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_022074cc(void *self) {
    SET_VT(self, data_ov015_02212a08);
    func_ov015_02203020(self);
    Ov015TaskBase_Dtor(self);

    return self;
}

void func_ov015_02207508(void) {
}

void *func_ov015_0220750c(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_02212a88);
    HEAP_PUSH(saved);
    {
        u8 *p = FLD(u8 *, self, 0x3c);
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278(p + 0x88);
                func_0203de1c(p);
            }
            FLD(u8 *, self, 0x3c) = NULL;
        }
    }
    HEAP_POP(saved);
    FLD(u8, self, 0x40) = 0;
    Ov015TaskBase_Dtor(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_022075a8(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_02212a88);
    HEAP_PUSH(saved);
    {
        u8 *p = FLD(u8 *, self, 0x3c);
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278(p + 0x88);
                func_0203de1c(p);
            }
            FLD(u8 *, self, 0x3c) = NULL;
        }
    }
    HEAP_POP(saved);
    FLD(u8, self, 0x40) = 0;
    Ov015TaskBase_Dtor(self);

    return self;
}

void *func_ov015_0220763c(void *self) {
    SET_VT(self, data_ov015_022129c0);
    func_ov000_02163254(self);
    return self;
}

void *func_ov015_0220765c(Ov015Ship *self) {
    func_ov000_0218e9c4(self);
    func_ov000_0218fe1c(&self->unk_138);
    func_ov000_0218e9c4(&self->unk_220);
    __cxa_vec_ctor(self->unk_358, 8, 0xe8, (void *)func_ov000_0218fe1c, (void *)func_ov000_0218fee4);
    func_ov000_0218e9c4(&self->unk_a98);
    func_ov000_0218fe1c(&self->unk_bd0);
    func_ov000_021919c8(&self->unk_cb8);
    self->unk_d14.x = 0;
    self->unk_d14.z = 0;
    self->unk_d08.x = 0;
    self->unk_d08.y = 0;
    self->unk_d08.z = 0;
    self->unk_d28 = 0;
    self->unk_d2c = 0;
    self->unk_d30 = 0;
    self->unk_d34 = 0;
    self->unk_d42 = 0;
    self->unk_d14.y = 0x1000;
    self->unk_d44 = 0x1000;
    self->unk_d20 = 0;
    self->unk_d24 = 0;
    self->unk_d38 = 0;
    self->unk_d3a = 0;
    self->unk_d3e = 0;
    self->unk_d48 = 0;
    self->unk_d22 = 0x8000;
    self->unk_d3c = 1;
    self->unk_d40 = 1;
    self->unk_d41 = 1;
    return self;
}

void *func_ov015_02207738(Ov015Ship *self) {
    u32 saved;
    if (func_02065748(data_0214a420, self->unk_d28) != 0) {
        HEAP_PUSH(saved);
        DELETE_V(self->unk_d28);
        HEAP_POP(saved);
    }
    if (func_02065748(data_0214a420, self->unk_d30) != 0) {
        HEAP_PUSH(saved);
        DELETE_V(self->unk_d30);
        HEAP_POP(saved);
    }
    func_ov000_02191a24(&self->unk_cb8);
    func_ov000_0218fee4(&self->unk_bd0);
    func_ov000_0218ea20(&self->unk_a98);
    __cxa_vec_cleanup(self->unk_358, 8, 0xe8, (void *)func_ov000_0218fee4);
    func_ov000_0218ea20(&self->unk_220);
    func_ov000_0218fee4(&self->unk_138);
    func_ov000_0218ea20(self);
    return self;
}

void func_ov015_02207858(Ov015Ship *self) {
    Ov015V3 v;
    v.z = 0xa000;
    v.x = 0;
    v.y = 0;
    func_01ffc9fc(&v, &v, self->unk_d22);
    VEC_Add(&self->unk_d14, &v, &self->unk_d4c);
    self->unk_d38 = 10;
}

}
