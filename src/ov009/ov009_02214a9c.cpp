#include "ov009/ov009.h"

extern "C" {

void func_ov009_02214a9c(Ov009Actor *self) {
    FLD(u16, self, 0xd2) = 0xffff;
    func_ov000_02198360(self->unk_40, 4, 0);
}


#define OV009_F32_TO_FX32(f) ((s32)(((f) > 0) ? (f) * 4096.0f + 0.5f : (f) * 4096.0f - 0.5f))

struct Ov009ParamB {
    s16 unk_00;
    u16 unk_02_0 : 3;
    u16 unk_02_3 : 13;
};

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

extern void *data_02097e4c;
extern void func_0203f324(Ov009Sub48 *p);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern u16 func_ov000_02198da8(Ov009Sub48 *p, u16 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern void *func_ov000_02199ba0(void *p);

void func_ov009_02214ac0(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Sub48 *o48;
    BOOL flag;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub48 *s48;
        Ov009Sub44 *s44;
        if (self->unk_a8 == 0) {
            self->unk_a8 = 0x52;
        }
        self->unk_a4 = 0xfae;
        s48 = self->unk_48;
        s48->unk_9a_0 = 1;
        s48->unk_9a_3 = 1;
        func_0203f324(s48);
        s48 = self->unk_48;
        s48->unk_9a_1 = 1;
        s48->unk_9a_4 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        self->unk_92 = 0;
        self->unk_40->state++;
    }
    case 1: {
        Ov009Sub48 *s48 = self->unk_48;
        u32 f = s48->unk_50;
        if ((f & 0x20000000) || (f & 0x40000000) || FLD(s32, s48, 0x58) != 0) {
            u8 n = self->unk_92;
            if (f & 0x20000000) {
                if (n < 5) {
                    self->unk_a0 = OV009_F32_TO_FX32(0.2f - 0.0315f * n);
                    func_0204a028(data_02097e4c, 0x83, &self->pos, -2);
                    self->unk_92++;
                }
                if (self->unk_a0 < 0) {
                    self->unk_a0 = 0;
                }
                self->unk_a8 = 0x29;
                self->unk_9c = Ov009_FxMulL(self->unk_9c, 0xc00);
            } else {
                self->unk_98 = func_ov000_02198da8(s48, self->unk_98);
                self->unk_9c = Ov009_FxMulL(self->unk_9c, 0x59a);
                if (FLD(s32, self->unk_48, 0x58) != 0 && n < 5) {
                    if (self->unk_a0 < 0xcd) {
                        self->unk_a0 = 0xcd;
                    }
                    self->unk_92++;
                }
                self->unk_a8 = 0x29;
            }
            FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        }
        break;
    }
    }
    func_ov000_0218dbe0(self, 0);
    if (self->unk_48 == NULL) {
        return;
    }
    if (((Ov009ParamB *)self->unk_b0)->unk_02_0 == 2) {
        Ov009Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 1;
        s48->unk_9a_3 = 1;
        func_0203f324(s48);
    }
    o48 = NULL;
    flag = FALSE;
    {
        void *p4c = FLD(void *, self, 0x4c);
        if (p4c != NULL && FLD(u16, p4c, 0x1c) != 0xffff && FLD(u8, p4c, 1) == 1) {
            void *p;
            s32 r = self->unk_64 + 0x4cd;
            if (r < 0xccd) {
                r = 0xccd;
            }
            self->unk_48->unk_44 = r;
            p = func_ov000_02199ba0(FLD(void *, self, 0x4c));
            if (p != NULL && (o48 = FLD(Ov009Sub48 *, p, 0x48)) != NULL && o48->unk_9a_3) {
                o48->unk_9a_3 = 0;
                func_0203f364(o48);
                flag = TRUE;
            }
        }
    }
    v = self->pos;
    v.y -= FLD(s32, self, 0x68);
    func_ov000_021987b8(self->unk_48, 1, (s32)&v, (s32)self->rot);
    if (flag) {
        o48->unk_9a_3 = 1;
        func_0203f324(o48);
    }
}

}
