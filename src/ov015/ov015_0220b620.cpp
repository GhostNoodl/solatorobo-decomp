#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212f20[];
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e47[];
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_02191618(void *a);

void *Ov015FishState18_Dtor(void *self) {
    SET_VT(self, data_ov015_02212f20);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *Ov015FishState18_DtorDelete(void *self) {
    SET_VT(self, data_ov015_02212f20);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    Heap_Free(self);
    return self;
}

BOOL Ov015FishState18_Enter(Ov015FishState18 *self, Ov015Fish *p) {
    self->unk_08 = 0;
    self->unk_0c = 0x50;
    self->unk_10 = p->unk_c0.unk_14;
    func_ov000_02190cb0(&p->unk_244, data_ov015_02212e47, 0x19a, 0);
    func_ov000_02191618(&p->unk_244);
    p->unk_104 = 0x800;
    p->unk_bc = 1;
    return TRUE;
}

u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e55[];
extern u8 data_ov015_02212e4e[];
extern u8 data_ov015_02212e61[];
BOOL func_ov000_02191120(void *p);
void func_ov000_021915a0(void *a);
void func_ov015_0220bb68(Ov015FishState18 *self, Ov015Fish *p);
void func_ov015_0220be38(Ov015FishState18 *self, Ov015Fish *p);
static inline void Ov015_SpeedB6f0(Ov015Fish *p) {
    s32 r;
    s32 sp = p->unk_c0.unk_28;
    s32 s = p->unk_c0.unk_10 << 12;
    if (sp < 0xe10000) {
        r = FX_Mul(s, 0x1000);
    } else if (sp < 0x1c20000) {
        r = FX_Mul(s, 0xccd);
    } else {
        r = FX_Mul(s, 0xb33);
    }
    p->unk_c0.unk_1c = r;
}
BOOL Ov015FishState18_Update(Ov015FishState18 *self, Ov015Fish *p) {
    Ov015Vec b;
    Ov015Vec a;
    self->unk_04 = p;
    switch (self->unk_08) {
    case 0:
        func_ov015_0220bb68(self, p);
        if (func_ov000_02191120(&p->unk_244)) {
            func_ov000_02190cb0(&p->unk_244, data_ov015_02212e4e, 0x19a, 0);
            func_ov000_021915a0(&p->unk_244);
            p->unk_104 = 0x1000;
            self->unk_08 = 1;
            self->unk_0c = self->unk_10;
        }
        break;
    case 1: {
        Ov015V *e;
        Ov015Fish *q;
        {
            s32 c = self->unk_0c;
            s32 t = self->unk_10;
            Ov015VecC v(*(Ov015VecC *)&p->unk_40);
            if (t - c >= 0x3c) {
                s32 r = FX_Div(c << 12, t >> 12);
                u16 idx = FX_Mul(0x1000 - r, 0x2ffff) >> 12;
                v.y = FX_Mul(FX_SinCosTable_[(idx >> 4) * 2], 0xccd) + 0x4000;
            }
            *(Ov015VecC *)&p->unk_40 = v;
        }
        q = self->unk_04;
        a.x = q->unk_40.x;
        a.y = q->unk_40.y > 0 ? 0 : q->unk_40.y;
        a.z = q->unk_40.z;
        e = func_020657b0(data_0214a420, self->unk_14);
        if (e == NULL) {
            e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e55, 0, &self->unk_04->unk_40);
            FLD(s32, e, 0xd4) = 1;
            FLD(u8, e, 0x28) = 0;
            FLD(s32, e, 0x3c) = 0x800;
            FLD(s32, e, 0xc8) = -1;
            FLD(s32, e, 0x50) = -0xc8000;
            e->v34(0, 0x3fff, 0);
            self->unk_14 = FLD(void *, e, 0x24);
        }
        e->v18(&a);
        q = self->unk_04;
        {
            s32 k = q->unk_7c;
            b.x = FX_Mul(q->unk_70, k);
            b.y = FX_Mul(q->unk_74, k);
            b.z = FX_Mul(q->unk_78, k);
        }
        e->v10(&b);
        if (self->unk_0c % 50 == 0) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (self->unk_0c <= 0) {
            p->unk_104 = 0x800;
            self->unk_08 = 2;
            self->unk_0c = 0x50;
            func_ov000_02190cb0(&p->unk_244, data_ov015_02212e61, 0x19a, 0);
            func_ov000_02191618(&p->unk_244);
            p->unk_104 = 0x800;
            e = func_020657b0(data_0214a420, self->unk_14);
            if (e != NULL) {
                void *saved;
                HEAP_PUSH(saved);
                if (e != NULL) {
                    if (e != NULL) {
                        e->v04();
                    }
                }
                HEAP_POP(saved);
            }
        }
        break;
    }
    case 2:
        func_ov015_0220be38(self, p);
        if (func_ov000_02191120(&p->unk_244)) {
            Ov015_SpeedB6f0(p);
            return FALSE;
        }
        break;
    }
    self->unk_0c--;
    if (self->unk_0c <= 0) {
        self->unk_0c = 0;
    }
    p->unk_bc = 1;
    return TRUE;
}

}
