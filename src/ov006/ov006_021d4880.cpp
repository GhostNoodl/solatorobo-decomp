#include "ov006/Tasks.h"
#include "ov006/SlotManager.h"

#define F(p, off, T) (*(T *)((u8 *)(p) + (off)))

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern ov006_Unk02097e40 *data_02097e40;
extern char data_ov006_021ebc5c[];
extern char data_ov006_021ebc0a[];
extern char data_ov006_021ebc1c[];

u16 func_ov006_021e60e8(int type, u16 mask);
void func_ov006_021dc048(ov006_Obj58 *p);
void func_ov006_021e5e00(ov006_Unk021ec888 *self);
void func_ov000_02190cb0(void *a, const void *b, int c, int d);
void *func_ov000_02190a30(void *a, int b);
void func_ov006_021d526c(ov006_TaskD37 *self, const char *name, s16 speed, u8 loop);
ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, data_ov006_021ebc0a, info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, data_ov006_021ebc1c, info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
}

static inline BOOL ov006_IsUnlocked(int type, u16 mask) {
    BOOL r = TRUE;
    if (func_ov006_021e60e8(type, mask) == 0) {
        r = FALSE;
    }
    return r;
}

static inline BOOL ov006_Anm_InRange(ov006_Anm74 *a, int start, int len) {
    return a->frame >= start && a->frame < start + len;
}

void func_ov006_021d4880(ov006_TaskD37 *self) {
    switch (self->unk3C) {
    case 0:
        if (self->head.unkC != 0) {
            if (data_ov006_021ec888->unk8 == 9) {
                self->unk3C = 100;
                return;
            }
            if (self->head.unkC == 1) {
                BOOL ok = ov006_IsUnlocked(5, 1);
                if (!ok) {
                    u16 m = data_02097e40->unk32;
                    if (m == func_ov006_021e60e8(4, m)) {
                        self->unk44 = 5;
                    }
                }
                if (ok) {
                    self->unk3C++;
                }
            } else if (self->head.unkC == 2) {
                if (ov006_IsUnlocked(5, 1)) {
                    self->unk3C++;
                }
            }
        } else {
            self->unk3C = 10;
        }
        break;
    case 1:
        self->unk44 = 0;
        if (self->head.unkC == 2) {
            self->unk3C = 0x28;
        } else {
            self->unk3C = 10;
        }
        break;
    case 10:
        self->unk50->flags &= ~4;
        self->unk3C++;
    case 11: {
        u16 trg;
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk50->flags |= 4;
            self->unk3C = 100;
            return;
        }
        trg = data_02097dc8->unk12;
        if (trg & 2) {
            if (self->unk3D) {
                func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
                self->unk50->flags |= 2;
                self->unk54->flags |= 2;
                func_ov006_021dc048(self->unk58);
                if (self->unk138->unk4 == 1) {
                    self->unk138->unk4 = 2;
                }
                self->head.flags |= 6;
                self->unk3C = 0x78;
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
        } else if (trg & 1) {
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            self->unk3C = 0x14;
        }
        break;
    }
    case 20:
        self->unk50->flags |= 4;
        self->unk5C->flags &= ~2;
        {
            ov006_Window *w = self->unk5C;
            VCALL(w, A8, func_ov000_02154b58(w, 1));
        }
        self->unk3C++;
        break;
    case 21:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk5C->flags |= 2;
            self->unk3C = 100;
            return;
        }
        if (!ov006_Window_IsState5(self->unk5C)) {
            return;
        }
        if (F(self, 0x40, int) == 0) {
            self->unk44 = 6;
            self->unk3C = 0x1e;
        } else {
            self->unk3C = 10;
        }
        break;
    case 30:
        self->unk50->flags |= 2;
        self->unk54->flags |= 2;
        func_ov006_021dc048(self->unk58);
        func_ov000_02190cb0(self->unk64, data_ov006_021ebc5c, 0, 1);
        F(func_ov000_02190a30(self->unk64, 0), 0x112, u16) = 0xb33;
        func_ov006_021d526c(self, data_ov006_021ebc5c, 0x1000, 0);
        {
            ov006_Info021daaa8 *info = func_ov006_021daaa8(self->unk4A);
            ov006_SlotManager *m = data_ov006_021ec884;
            m->unk6 = self->unk4A;
            m->unk8 = (ov006_SlotManagerInfo *)info;
        }
        self->unk3C++;
        break;
    case 31:
        if (data_ov006_021ec888->unk8 == 9) {
            func_ov006_021dc048(self->unk58);
            self->unk3C = 100;
            return;
        }
        {
            int f = self->unk74->frame;
            s16 len = self->unk7A;
            if ((f >= 0x10000 && f < 0x10000 + len) || (f >= 0x1e000 && f < 0x1e000 + len)) {
                func_02049a48(data_02097e4c, 0x32, -1, -1, -1);
            } else if (f >= 0xb000 && f < 0xb000 + len) {
                func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
            }
        }
        if (self->unk74->frame >= (self->unk74->res->numFrame << 12) - 0x1000) {
            self->head.flags |= 6;
            func_0203cc58(0x14000, 0, 0);
            func_0203cc58(0x14000, 0, 1);
            self->unk3C = 0x6e;
        }
        break;
    case 40:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk3C = 100;
            return;
        }
        if (!func_ov006_021e60e8(6, 1)) {
            return;
        }
        VCALL(self->unk50, A8, func_ov000_02154b58(self->unk50, self->unk4C));
        ov006_TaskD37_Select(self, self->unk4C);
        self->unk3C = 0x1e;
        break;
    case 100:
        func_ov006_021e5e00(data_ov006_021ec888);
        self->unk3C++;
    case 101:
        if (data_ov006_021ec888->unk8 == 9) {
            return;
        }
        func_0203cc58(0x1e000, 0, 0);
        func_0203cc58(0x1e000, 0, 1);
        self->unk3C++;
        break;
    case 102:
        if (ov006_IsMode4() && ov006_IsMode4b()) {
            self->unk50->flags |= 2;
            self->unk54->flags |= 2;
            func_ov006_021dc048(self->unk58);
            self->head.flags |= 6;
            self->unk3C = 0x82;
        }
        break;
    }
}

}
