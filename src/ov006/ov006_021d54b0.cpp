#include "ov006/ov006.h"

typedef struct ov006_Task0 {
    ov006_Task base;
    int unk10;
} ov006_Task0;

typedef struct ov006_Unk02097e48 {
    u16 active : 1;
    u16 unk0_1 : 15;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} ov006_Unk02097e48;

typedef struct ov006_Unk021ccd40 {
    u8 unk0[0x14];
    int unk14;
} ov006_Unk021ccd40;

typedef struct ov006_Flags {
    void *vtbl;
    u32 bit0 : 1;
    u32 bit1 : 1;
    u32 bit2 : 1;
    u32 bit3 : 1;
    u32 bit4 : 1;
    u32 bit5 : 1;
    u32 bit6 : 1;
    u32 bit7 : 1;
    u32 unk4_8 : 24;
} ov006_Flags;

typedef struct ov006_Unk021d58cc_Member {
    u8 unk0[0x88];
    u8 unk88[1];
} ov006_Unk021d58cc_Member;

typedef struct ov006_Unk021d58cc {
    void *vtbl;
    u8 unk4[0x38];
    ov006_Unk021d58cc_Member *unk3C;
    ov006_Unk021d58cc_Member *unk40;
    u8 unk44;
} ov006_Unk021d58cc;

typedef struct ov006_Task1 {
    ov006_Task base;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    u8 unk40[0x28];
    int unk68;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    int unk70[6];
} ov006_Task1;

extern "C" {

extern void *data_ov006_021ebc98;
extern void *data_ov006_021ebe40;
extern void *data_ov006_021ebc80;
extern void *data_ov006_021ebc70;
extern void *data_ov006_021ebfc0;
extern void *data_ov000_021cc060;
extern void *data_02097cdc;
extern void *data_0208cc94;
extern u8 data_ov006_021ec864[];
extern ov006_Unk02097e48 *data_02097e48;
extern ov006_Unk021ccd40 *data_ov000_021ccd40;
extern int data_ov000_021ccd38;

void func_ov006_021ccda0(void *self);
void func_ov006_021ccddc(void *self);
void func_ov006_021cd580(int a, int b, int c);
void func_ov000_02180754(void);
void func_ov000_02180660(int a, int b);
BOOL func_ov000_021735e8(void);
void func_ov000_021c2310(void *self);
void func_ov000_02163254(void *self);
void func_02036838(void *a, void *b, int c, int d);
void func_020359d0(void *a, int b, int c);
int func_02035b90(void *a, int b);
void func_0204aab0(ov006_Unk02097e48 *a);
void func_02041558(void *a);
void func_02041278(void *a);
void func_02016cd8(int value, void *dst, u32 size);

ov006_Task0 *func_ov006_021d54b0(ov006_Task0 *self) {
    func_ov006_021ccda0(self);
    self->base.vtbl = (ObjectVtbl *)&data_ov006_021ebc98;
    self->unk10 = 1;
    return self;
}

static inline void ov006_Task0_Dtor(ov006_Task0 *self) {
    self->base.vtbl = (ObjectVtbl *)&data_ov006_021ebc98;
    func_ov000_02180754();
    func_02036838(data_02097cdc, data_0208cc94, 7, 0);
    func_02036838(data_02097cdc, data_ov006_021ec864, 7, 0);
    func_ov006_021ccddc(self);
}

ov006_Task0 *func_ov006_021d54d8(ov006_Task0 *self) {
    ov006_Task0_Dtor(self);
    return self;
}

ov006_Task0 *func_ov006_021d5544(ov006_Task0 *self) {
    ov006_Task0_Dtor(self);
    func_0203de1c(self);
    return self;
}

BOOL func_ov006_021d55b8(void) {
    ov006_Unk02097e48 *p = data_02097e48;
    if (p->active) {
        if (p->unk6 != 0xffff || p->unk4 != 0x25) {
            u16 v;
            if (p->unk2 != 10 && p->unk2 != 0) {
                if (p->unk6 != 0xffff) {
                    func_0204aab0(p);
                }
                v = 1;
            } else {
                v = 0;
            }
            p->unk2 = v;
            p->unk6 = 0x25;
            p->unk8 = 10;
        }
    }
    func_020359d0(data_0208cc94, 7, 0);
    func_020359d0(data_ov006_021ec864, 7, 0);
    return TRUE;
}

BOOL func_ov006_021d5678(void) {
    return ((func_02035b90(data_0208cc94, 7) != 0) & func_02035b90(data_ov006_021ec864, 7)) != 0;
}

BOOL func_ov006_021d56bc(ov006_Task0 *self) {
    switch (self->base.subState) {
    case 0:
        func_ov000_02180660(0x23, 0);
        self->base.subState++;
    case 1:
        if (data_ov000_021ccd40 != NULL) {
            VCALL(data_ov000_021ccd40, 4C);
            func_ov006_021cd580(2, 0, 0);
            data_ov006_021ec888->unk15E = 2;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL func_ov006_021d5748(void) {
    BOOL result = TRUE;
    if (!func_ov000_021735e8()) {
        result = FALSE;
    }
    return result;
}

BOOL func_ov006_021d5764(void) {
    data_ov006_021ec860->taskType = 3;
    return TRUE;
}

void func_ov006_021d5780(void) {
}

static inline void ov006_SetUnk021ccd40(ov006_Unk021ccd40 *p) {
    if (data_ov000_021ccd40 != NULL) {
        data_ov000_021ccd38 = data_ov000_021ccd40->unk14;
    } else {
        data_ov000_021ccd38 = 0;
    }
    data_ov000_021ccd40 = p;
}

void func_ov006_021d5784(ov006_Unk021ccd40 *p) {
    ov006_SetUnk021ccd40(p);
}

void func_ov006_021d57b8(void *self) {
    if (VCALL(self, 54)) {
        ov006_SetUnk021ccd40(NULL);
    }
}

static inline BOOL ov006_Flags_Test(ov006_Flags *self, u32 mask) {
    return (((u32 *)self)[1] & mask) != 0;
}

BOOL func_ov006_021d5808(ov006_Flags *self, u32 mask) {
    return ov006_Flags_Test(self, mask) ? TRUE : FALSE;
}

void func_ov006_021d5828(ov006_Flags *self) {
    self->bit7 = 0;
}

static inline BOOL ov006_Flags_Bit6(ov006_Flags *self) {
    return self->bit6 != 0;
}

BOOL func_ov006_021d5838(ov006_Flags *self) {
    return ov006_Flags_Bit6(self) ? TRUE : FALSE;
}

void func_ov006_021d585c(ov006_Flags *self) {
    self->bit6 = 1;
}

static inline BOOL ov006_Flags_Bit5(ov006_Flags *self) {
    return self->bit5 != 0;
}

BOOL func_ov006_021d586c(ov006_Flags *self) {
    return ov006_Flags_Bit5(self) ? TRUE : FALSE;
}

void func_ov006_021d5890(ov006_Flags *self) {
    self->bit5 = 1;
}

void func_ov006_021d58a0(ov006_Flags *self) {
    self->bit4 = 0;
}

void func_ov006_021d58b0(ov006_Flags *self) {
    self->bit4 = 1;
}

BOOL func_ov006_021d58c0(void) {
    return TRUE;
}

void func_ov006_021d58c8(void) {
}

#define OV006_DELETE_MEMBER(obj)                                 \
    do {                                                         \
        void *saved_ = data_02097dd0->current;                   \
        data_02097dd0->current = data_02097dd0->unk8;            \
        if ((obj) != NULL) {                                     \
            if ((obj) != NULL) {                                 \
                ov006_Unk021d58cc_Member *m_ = (obj);            \
                func_02041558(m_);                               \
                func_02041278(m_->unk88);                        \
                func_0203de1c(m_);                               \
            }                                                    \
            (obj) = NULL;                                        \
        }                                                        \
        data_02097dd0->current = saved_;                         \
    } while (0)

static inline void ov006_Unk021d58cc_Dtor(ov006_Unk021d58cc *self) {
    self->vtbl = &data_ov006_021ebe40;
    OV006_DELETE_MEMBER(self->unk3C);
    OV006_DELETE_MEMBER(self->unk40);
    self->unk44 = 0;
    self->vtbl = &data_ov000_021cc060;
    VCALL(self, 5C);
}

ov006_Unk021d58cc *func_ov006_021d58cc(ov006_Unk021d58cc *self) {
    ov006_Unk021d58cc_Dtor(self);
    func_0203de1c(self);
    return self;
}

ov006_Unk021d58cc *func_ov006_021d59b4(ov006_Unk021d58cc *self) {
    ov006_Unk021d58cc_Dtor(self);
    return self;
}

void *func_ov006_021d5a94(void **self) {
    *self = &data_ov006_021ebc80;
    func_ov000_021c2310(self);
    func_0203de1c(self);
    return self;
}

void func_ov006_021d5abc(void) {
}

void func_ov006_021d5ac0(void) {
}

void *func_ov006_021d5ac4(void **self) {
    *self = &data_ov006_021ebc80;
    func_ov000_021c2310(self);
    return self;
}

void *func_ov006_021d5ae4(void **self) {
    *self = &data_ov006_021ebc70;
    func_ov000_02163254(self);
    return self;
}

ov006_Task1 *func_ov006_021d5b04(ov006_Task1 *self) {
    int i;
    func_ov006_021ccda0(self);
    self->base.vtbl = (ObjectVtbl *)&data_ov006_021ebfc0;
    self->unk10 = 0;
    self->unk12 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    func_02016cd8(0, self->unk40, sizeof(self->unk40));
    self->unk68 = 0;
    self->unk6C = 1;
    self->unk6D = 0;
    self->unk6E = 0;
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk3C = 0;
    for (i = 0; i < 6; i++) {
        self->unk70[i] = 0;
    }
    return self;
}

}
