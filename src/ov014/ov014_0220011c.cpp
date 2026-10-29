#include "ov014/ov014.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern u8 data_ov014_022174dc[];
extern u8 data_ov014_0221651c[];
extern u8 data_ov014_0221664c[];
extern u8 data_ov014_0221665c[];
extern u8 data_ov014_0221666c[];
extern u8 data_ov014_0221667c[];
extern void func_ov003_021ceedc(void *p);
extern void *func_ov003_021cef0c(void *p);
extern void *func_ov003_021da940(void *p);
extern BOOL func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);
extern Ov014Actor *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov003_021cf1f0(void *a, s32 b, s32 c, const void *d);

#pragma force_active on
Ov014Actor *func_ov014_0220011c(Ov014Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov014_022174dc;
    func_ov003_021ceedc((u8 *)self + 0x108);
    FLD(s32, self, 0xf4) = 0;
    FLD(u8, self, 0xf8) = 0xff;
    FLD(void *, self, 0x100) = NULL;
    FLD(s32, self, 0x104) = 0;
    FLD(u16, self, 0xfc) = 0xff;
    FLD(u8, self, 0xfe) = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_Free100(Ov014Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0x100) != NULL) {
        void *p = FLD(void *, self, 0x100);
        if (p != NULL) {
            func_ov003_021da940(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0x100) = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014Actor *func_ov014_02200164(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022174dc;
    Ov014_Free100(self);
    func_ov003_021cef0c((u8 *)self + 0x108);
    func_ov003_021d0edc(self);
    return self;
}

Ov014Actor *func_ov014_022001dc(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022174dc;
    Ov014_Free100(self);
    func_ov003_021cef0c((u8 *)self + 0x108);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_0220025c(Ov014Actor *self, Ov014Msg *msg) {
    switch (msg->type) {
    case 6:
        FLD(u8, self, 0xf8) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    case 14:
        FLD(u16, self, 0xfc) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    func_ov003_021d1c00(self, msg);
}

void func_ov014_022002b8(Ov014Actor *self) {
    s32 *p;
    Ov014Actor *a;
    Ov014Sub48 *m;
    func_ov003_021d112c(self);
    FLD(s16, self, 0xf0) = self->unk_18 & 0xff;
    p = (s32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    FLD(s32 *, self, 0x100) = p;
    a = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (a != NULL) {
        FLD(Ov014Flags8, a, 0xa2).b0 = 0;
    }
    self->unk_ea_6 = 1;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    m = self->unk_48;
    FLD(s32, m, 0x5c) = 0;
    FLD(s32, m, 0x60) = -0x19a;
    FLD(s32, m, 0x64) = 0;
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        func_ov003_021cf1f0((u8 *)self + 0x108, 0, 1, data_ov014_0221651c);
        break;
    case 1:
        func_ov003_021cf1f0((u8 *)self + 0x108, 1, 2, data_ov014_0221664c);
        break;
    case 2:
        func_ov003_021cf1f0((u8 *)self + 0x108, 2, 2, data_ov014_0221665c);
        break;
    case 3:
        func_ov003_021cf1f0((u8 *)self + 0x108, 3, 2, data_ov014_0221666c);
        break;
    case 4:
        func_ov003_021cf1f0((u8 *)self + 0x108, 4, 2, data_ov014_0221667c);
        break;
    }
}

}
