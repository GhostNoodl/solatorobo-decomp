#include "ov006/ov006.h"
#include "ov006/SlotManager.h"

typedef struct ov006_Part021d96a8 {
    void *vtbl;
    int unk4;
    int unk8;
    u32 flags;
    u8 unk10[0x24];
    int unk34;
    u8 unk38[0x50];
    int unk88;
    int unk8C;
} ov006_Part021d96a8;

typedef struct ov006_Task021d96a8 {
    void *vtbl;
    u32 flags;
    int unk8;
    int unkC;
    ov006_Part021d96a8 *unk10;
    ov006_Part021d96a8 *unk14;
    ov006_Part021d96a8 *unk18;
    ov006_Part021d96a8 *unk1C;
    ov006_Part021d96a8 *unk20;
    ov006_Part021d96a8 *unk24;
    ov006_Part021d96a8 *unk28;
    int unk2C;
    int unk30;
    int unk34;
    u32 unk38;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E[4];
} ov006_Task021d96a8;

typedef struct ov006_Fade021d96a8 {
    s32 unk0[3];
    s32 unkC;
} ov006_Fade021d96a8;

typedef struct ov006_Pad021d96a8 {
    u8 unk0[0x12];
    u16 trig;
} ov006_Pad021d96a8;

extern "C" {

extern ov006_Fade021d96a8 data_02097d78;
extern ov006_Pad021d96a8 *data_02097dc8;
extern u8 *data_0214a424;
extern u8 *data_02097e40;
extern void *data_02097e4c;
void *func_02046a50(void *a, int idx);
void func_0203cb78(s32 a, int b, int c);
void func_0203cc58(s32 a, int b, int c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
u16 func_ov006_021e60e8(int type, u16 mask);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
void func_ov006_021e4c5c(ov006_Unk021ec888 *self);
void func_ov006_021e5e00(ov006_Unk021ec888 *p);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);

static inline BOOL ov006_FadeIdle(void) {
    BOOL r;
    if (data_02097d78.unkC == 0 && data_02097d78.unk0[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL ov006_FadeDone(int ch) {
    BOOL r;
    if (data_02097d78.unkC == 4) {
        r = TRUE;
    } else {
        r = data_02097d78.unk0[ch] == 4;
    }
    return r;
}

static inline BOOL ov006_PartIs5(ov006_Part021d96a8 *p) {
    return p->unk4 == 5;
}

static inline void ov006_HideAll(ov006_Task021d96a8 *self) {
    self->unk20->flags |= 2;
    self->unk10->flags |= 2;
    self->unk14->flags |= 2;
    self->unk18->flags |= 2;
    self->unk1C->flags |= 2;
    self->unk24->flags |= 2;
    self->unk28->flags |= 2;
}

BOOL func_ov006_021d96a8(ov006_Task021d96a8 *self) {
    BOOL ret = TRUE;
    BOOL send = FALSE;
    if (data_ov006_021ec860->unk1C != 0 && data_ov006_021ec888->unk8 != 9) {
        send = TRUE;
        func_02046a50(data_02097e40, 0);
    }
    switch (self->unkC) {
    case 0:
        if (!ov006_FadeIdle()) {
            func_0203cb78(0x14000, 0, 0);
            func_0203cb78(0x14000, 0, 1);
        }
        self->unkC++;
        break;
    case 1:
        if (ov006_FadeIdle()) {
            self->unk20->flags &= ~2;
            self->unk34 = 0;
            self->unkC++;
        }
        break;
    case 2:
        if (self->unk34 >= 0x3c) {
            if (data_02097dc8->trig & 1) {
                {
                    u8 *g = data_0214a424;
                    if ((*(u32 *)(g + 0x20) += self->unk38) > 99999) {
                        *(u32 *)(g + 0x20) = 99999;
                    }
                }
                {
                    u32 n = self->unk38;
                    u8 *g = data_0214a424;
                    if (*(u32 *)(g + 0xc) + n >= 999999) {
                        *(u32 *)(g + 0xc) = 999999;
                    } else {
                        *(u32 *)(g + 0xc) = *(u32 *)(g + 0xc) + n;
                    }
                }
                func_ov000_0215d980(self->unk18, 0, 0);
                func_ov000_0215d980(self->unk1C, *(u32 *)(data_0214a424 + 0x20), 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
                self->unk34 = 0;
                self->unkC++;
            }
        } else {
            self->unk34++;
        }
        break;
    case 3:
        if (self->unk1C->unk8C != self->unk1C->unk88 || self->unk18->unk8C != self->unk18->unk88) {
            if ((data_02097dc8->trig & 1) || data_ov006_021ec888->unk8 == 9) {
                func_ov000_0215d980(self->unk18, 0, 1);
                func_ov000_0215d980(self->unk1C, *(u32 *)(data_0214a424 + 0x20), 1);
            } else {
                if (++self->unk34 % 4 == 0) {
                    func_02049a48(data_02097e4c, 0x18, -1, -1, -1);
                }
                break;
            }
        }
        func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
        self->unk34 = 0;
        self->unkC++;
        break;
    case 4:
        if (self->unk34 >= 0x14) {
            if (data_ov006_021ec888->unk8 == 9) {
                self->unkC = 0x32;
            } else if (data_02097dc8->trig & 1) {
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
                self->unk20->flags |= 2;
                self->unkC = 10;
            }
        } else {
            self->unk34++;
        }
        break;
    case 10:
        self->unk28->flags &= ~2;
        self->unkC++;
        break;
    case 11:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unkC = 0x32;
        } else if (ov006_PartIs5(self->unk28)) {
            if (self->unk2C != 0) {
                ov006_HideAll(self);
                if (send) {
                    func_ov006_021e4c5c(data_ov006_021ec888);
                }
                data_ov006_021ec860->unk20 = 1;
                self->unkC = 0x1e;
            } else if (!send) {
                ov006_HideAll(self);
                data_ov006_021ec860->unk20 = 2;
                self->unkC = 0x1e;
            } else {
                self->unkC = 0x14;
            }
        }
        break;
    case 0x14:
        self->unk24->flags &= ~2;
        VCALL(self->unk24, 70);
        self->unk30 = (self->unk24->unk34 >> 12) + 0x14;
        self->unkC++;
    case 0x15:
        if (self->unk30 < 0) {
            self->unk30 = 0;
            self->unk3C = 10;
            self->unkC++;
        } else {
            self->unk30--;
            break;
        }
    case 0x16:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unkC = 0x32;
        } else if (func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->unk12 == 0) {
            u16 k = *(u16 *)(data_02097e40 + 0x32);
            if (k == func_ov006_021e60e8(10, k)) {
                self->unk3C = 0xb;
                self->unkC++;
            }
        } else {
            self->unkC++;
        }
        break;
    case 0x17:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unkC = 0x32;
        } else if (func_ov006_021e60e8(0xb, 1) != 0) {
            ov006_HideAll(self);
            data_ov006_021ec860->unk20 = 2;
            self->unkC = 0x1e;
        }
        break;
    case 0x1e:
        func_0203cc58(0x14000, 0, 0);
        func_0203cc58(0x14000, 0, 1);
        self->unkC++;
    case 0x1f:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unkC = 0x32;
        } else if (ov006_FadeDone(0) && ov006_FadeDone(1)) {
            ret = FALSE;
            data_ov006_021ec860->taskType = 0;
        }
        break;
    case 0x32:
        self->unk24->flags |= 2;
        self->unk28->flags |= 2;
        func_0203cb78(0x1000, 0, 0);
        func_0203cb78(0x1000, 0, 1);
        func_ov006_021e5e00(data_ov006_021ec888);
        self->unkC++;
    case 0x33:
        if (data_ov006_021ec888->unk8 != 9) {
            ov006_HideAll(self);
            func_0203cc58(0x1e000, 0, 0);
            func_0203cc58(0x1e000, 0, 1);
            self->unkC++;
        }
        break;
    case 0x34:
        if (ov006_FadeDone(0) && ov006_FadeDone(1)) {
            data_ov006_021ec860->unk20 = 1;
            data_ov006_021ec860->taskType = 0;
        }
        break;
    }
    VCALL(self->unk10, 1C);
    VCALL(self->unk14, 1C);
    VCALL(self->unk18, 1C);
    VCALL(self->unk1C, 1C);
    VCALL(self->unk20, 1C);
    VCALL(self->unk28, 1C);
    VCALL(self->unk24, 1C);
    if (send) {
        func_ov006_021e4a80(data_ov006_021ec888, self->unk3C, 2, self->unk3E, 4);
    }
    return ret;
}

}
