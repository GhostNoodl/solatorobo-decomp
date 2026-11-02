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
void func_ov015_02205c7c(Ov015Scene2b08 *self);
void func_ov015_02204110(Ov015Scene2c08 *self);
void func_ov015_02203020(Ov015Scene2a08 *self);
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
void *Ov000Vt_021cc438_Dtor(void *p);
void *func_ov000_0218ea20(void *p);
void __cxa_vec_cleanup(void *p, s32 n, s32 size, void *dtor);
void func_01ffc9fc(Ov015V3 *in, Ov015V3 *out, u16 ang);
void VEC_Add(const void *a, const void *b, void *out);

void *func_ov015_02206f04(void) {
    Ov015Scene2a88 *p = (Ov015Scene2a88 *)Heap_Alloc(0x58);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212a88);
        p->unk_3c = 0;
        p->unk_40 = 0;
        p->unk_44 = 0;
        p->unk_48 = 0;
        p->unk_4c = 0;
        p->unk_50 = 0;
        p->unk_54 = 0;
    }
    VCALL(p)->v08(0x1e, 0xc8);
    return p;
}

void *func_ov015_02206f7c(void) {
    Ov015Scene2a08 *p = (Ov015Scene2a08 *)Heap_Alloc(0xb0);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212a08);
        func_02043548(&p->unk_44.eye);
        func_020434e0(&p->unk_44.fovSin);
        p->unk_3c = 0;
        p->unk_40 = 0;
        p->unk_80 = 0;
        p->unk_84 = 0;
        p->unk_88 = 0;
        p->unk_8c = 0;
        p->unk_90 = 0;
        p->unk_94 = 0;
        p->unk_98 = 0;
        p->unk_9c = 0;
        p->unk_a0 = 0;
        p->unk_a4 = 0;
        p->unk_a8 = 0;
        p->unk_ac = 0;
    }
    VCALL(p)->v08(0x1f, 0xc8);
    return p;
}

void *func_ov015_02207020(void) {
    Ov015Scene2c08 *p = (Ov015Scene2c08 *)Heap_Alloc(0x6c);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212c08);
        p->unk_3c = 0;
        p->unk_40 = 0;
        p->unk_44 = 0;
        p->unk_48 = 0;
        p->unk_4c = 0;
        p->unk_50 = 0;
        p->unk_54 = 0;
        p->unk_58 = 1;
        p->unk_5c = 0;
        p->unk_60 = 0;
        p->unk_64 = 0;
        p->unk_68 = 0xa000;
        p->unk_6a = 0;
    }
    VCALL(p)->v08(0x20, 0xc8);
    return p;
}

void *func_ov015_022070b8(void) {
    Ov015Scene2b88 *p = (Ov015Scene2b88 *)Heap_Alloc(0x58);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212b88);
        p->unk_3c = 0;
        p->unk_40 = 0;
        p->unk_44 = 0;
        p->unk_48 = 0;
        p->unk_4c = 0;
        p->unk_50 = 1;
        p->unk_54 = 0xffff;
    }
    VCALL(p)->v08(0x21, 0xc8);
    return p;
}

void *func_ov015_02207138(void) {
    Ov015Scene2b08 *p = (Ov015Scene2b08 *)Heap_Alloc(0x164);
    if (p != NULL) {
        Ov015TaskBase_Ctor(p);
        SET_VT(p, data_ov015_02212b08);
        p->unk_3c = 0;
        p->unk_40 = 0;
        p->unk_44 = 0;
        p->unk_48 = 0;
        p->unk_4c = 0;
        p->unk_50 = 0;
        p->unk_54 = 3;
        p->unk_58 = 0;
        p->unk_5c = 0;
        p->unk_60 = 0;
        p->unk_64[0] = 0;
    }
    VCALL(p)->v08(0x22, 0xc8);
    return p;
}

void *func_ov015_022071c4(void *self) {
    SET_VT(self, data_ov015_022129e0);
    func_ov000_02180754();
    SET_VT(self, data_ov015_0221280c);
    func_ov015_021fa6cc(self);
    Heap_Free(self);
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

bool Ov015Task_TestFlags(Ov015Task *self, u32 mask) {
    BOOL r = Ov015Task_Test(self, mask);
    return r;
}

void Ov015Task_ClearFlag7(Ov015Task *self) {
    self->flag7 = 0;
}

void Ov015Task_SetFlag7(Ov015Task *self) {
    self->flag7 = 1;
}

static inline bool Ov015Task_Get_flag6(Ov015Task *t) {
    return t->flag6;
}

bool Ov015Task_GetFlag6(Ov015Task *self) {
    BOOL r = Ov015Task_Get_flag6(self);
    return r;
}

void Ov015Task_SetFlag6(Ov015Task *self) {
    self->flag6 = 1;
}

static inline bool Ov015Task_Get_flag5(Ov015Task *t) {
    return t->flag5;
}

bool Ov015Task_GetFlag5(Ov015Task *self) {
    BOOL r = Ov015Task_Get_flag5(self);
    return r;
}

void Ov015Task_SetFlag5(Ov015Task *self) {
    self->flag5 = 1;
}

void Ov015Task_ClearFlag4(Ov015Task *self) {
    self->flag4 = 0;
}

void Ov015Task_SetFlag4(Ov015Task *self) {
    self->flag4 = 1;
}

s32 func_ov015_02207380(void) {
    return 1;
}

void *Ov015Scene2b08_DtorDelete(Ov015Scene2b08 *self) {
    SET_VT(self, data_ov015_02212b08);
    func_ov015_02205c7c(self);
    Ov015TaskBase_Dtor(self);
    Heap_Free(self);
    return self;
}

void *Ov015Scene2b08_Dtor(Ov015Scene2b08 *self) {
    SET_VT(self, data_ov015_02212b08);
    func_ov015_02205c7c(self);
    Ov015TaskBase_Dtor(self);

    return self;
}

void *Ov015Scene2c08_DtorDelete(Ov015Scene2c08 *self) {
    SET_VT(self, data_ov015_02212c08);
    func_ov015_02204110(self);
    Ov015TaskBase_Dtor(self);
    Heap_Free(self);
    return self;
}

void *Ov015Scene2c08_Dtor(Ov015Scene2c08 *self) {
    SET_VT(self, data_ov015_02212c08);
    func_ov015_02204110(self);
    Ov015TaskBase_Dtor(self);

    return self;
}

void *Ov015Scene2a08_DtorDelete(Ov015Scene2a08 *self) {
    SET_VT(self, data_ov015_02212a08);
    func_ov015_02203020(self);
    Ov015TaskBase_Dtor(self);
    Heap_Free(self);
    return self;
}

void *Ov015Scene2a08_Dtor(Ov015Scene2a08 *self) {
    SET_VT(self, data_ov015_02212a08);
    func_ov015_02203020(self);
    Ov015TaskBase_Dtor(self);

    return self;
}

void func_ov015_02207508(void) {
}

void *Ov015Scene2a88_DtorDelete(Ov015Scene2a88 *self) {
    u32 saved;
    SET_VT(self, data_ov015_02212a88);
    HEAP_PUSH(saved);
    {
        u8 *p = self->unk_3c;
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278(p + 0x88);
                Heap_Free(p);
            }
            self->unk_3c = NULL;
        }
    }
    HEAP_POP(saved);
    self->unk_40 = 0;
    Ov015TaskBase_Dtor(self);
    Heap_Free(self);
    return self;
}

void *Ov015Scene2a88_Dtor(Ov015Scene2a88 *self) {
    u32 saved;
    SET_VT(self, data_ov015_02212a88);
    HEAP_PUSH(saved);
    {
        u8 *p = self->unk_3c;
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278(p + 0x88);
                Heap_Free(p);
            }
            self->unk_3c = NULL;
        }
    }
    HEAP_POP(saved);
    self->unk_40 = 0;
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
    Ov000Vt_021cc438_Dtor(&self->unk_cb8);
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
