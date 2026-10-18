#include "types.h"

typedef struct {
    u8 pad_00[0xb6];
    u16 unk_b6;
    u16 unk_b8;
    u16 unk_ba;
    u16 unk_bc;
} Ov003DispModel;

typedef struct {
    u8 pad_00[0x68];
    Ov003DispModel *unk_68[2];
} Ov003Sub68;

typedef struct {
    u32 unk_00;
    u64 flags;
    u8 pad_0c[0x7];
    u8 kind;
} Ov003DispWork;

typedef struct {
    u16 unk_00;
    u16 pad_02;
    u16 unk_04;
    u16 unk_06;
    u8 unk_08;
    u8 unk_09;
    u16 unk_0a;
} Ov003DispState;

typedef struct {
    u16 unk_00;
    s16 unk_02;
} Ov003DispPos;

typedef struct {
    u8 unk_00;
    u8 pad_01[3];
    u8 pad_04;
    u8 type;
    u16 unk_06;
    u8 unk_08;
    u8 pad_09;
    s16 unk_0a;
    u16 unk_0c;
} Ov003DispEv;

typedef struct {
    u8 pad_00[0xc];
    u16 unk_0c;
    u8 pad_0e[0x16];
    u8 unk_24[0xc];
    u32 unk_30;
    u8 pad_34[4];
    Ov003DispModel *unk_38;
    u8 pad_3c[4];
    Ov003DispWork *unk_40;
    u8 pad_44[0xc];
    Ov003DispState *unk_50;
    Ov003DispPos *unk_54;
    u8 pad_58[0x78];
    Ov003Sub68 *unk_d0;
    u8 pad_d4[0x16];
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 3;
    u16 unk_ea_6 : 2;
    u16 unk_ea_8 : 1;
    u16 unk_ea_9 : 7;
} Ov003Disp;

extern s32 func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, s32 b);
extern s32 func_ov003_021d6548(Ov003Disp *self, void *data);
extern void func_ov000_02191418(void *m, s32 a, s32 b);
extern BOOL func_ov000_0218d494(Ov003Disp *self, Ov003DispEv *ev);

static inline void Ov003_SetColor(Ov003DispModel *m, u16 c0, u16 c1) {
    m->unk_b6 = c0;
    m->unk_b8 = c1;
    m->unk_ba = 0xb;
    m->unk_bc = 0xa;
}

void func_ov003_021d1b88(Ov003Disp *self) {
    s32 i;
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40(self->unk_24));
    }
    if (self->unk_d0 == NULL || self->unk_ea_3 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        if (self->unk_d0->unk_68[i] != NULL) {
            func_ov000_02190a80(self->unk_d0->unk_68[i], 0x1000);
        }
    }
}

BOOL func_ov003_021d1c00(Ov003Disp *self, Ov003DispEv *ev) {
    BOOL ret = FALSE;
    BOOL base = TRUE;
    switch (ev->type) {
    case 9: {
        Ov003DispState *st;
        base = FALSE;
        ret = TRUE;
        st = self->unk_50;
        if (st != NULL && st->unk_0a == 0 && self->unk_40->kind != 0x20) {
            s32 n;
            u8 b;
            u16 c0;
            u16 c1;
            s32 i;
            st->unk_04 = ev->unk_06;
            n = func_ov003_021d6548(self, &ev->unk_08);
            b = self->unk_50->unk_09;
            if (n != 0) {
                self->unk_40->flags |= (1ULL << n);
            }
            if (b != 1) {
                func_ov000_02191418(self->unk_38, 5, 0);
            }
            if (ev->unk_06 != self->unk_0c) {
                self->unk_50->unk_0a = 5;
            }
            c0 = 0x14bf;
            if (self->unk_ea_8) c0 = 0x5adf;
            c1 = 0x739f;
            Ov003_SetColor(self->unk_38, c0, c1);
            if (self->unk_d0 != NULL && self->unk_ea_3 != 0) {
                for (i = 0; i < 2; i++) {
                    Ov003DispModel *m = self->unk_d0->unk_68[i];
                    if (m != NULL) {
                        Ov003_SetColor(m, c0, c1);
                    }
                }
            }
        }
        break;
    }
    case 11: {
        Ov003DispState *st;
        base = FALSE;
        if (ev->unk_08 == 1) {
            u16 x = ev->unk_0c;
            s16 y = ev->unk_0a;
            Ov003DispPos *pos = self->unk_54;
            pos->unk_02 = y;
            pos->unk_00 = x;
        }
        self->unk_50->unk_04 = ev->unk_06;
        st = self->unk_50;
        st->unk_06 = 0;
        st->unk_08 = 0;
        st->unk_09 = 0;
        if (self->unk_50->unk_00 != 0) {
            self->unk_40->flags |= 0x40000;
        }
        ret = TRUE;
        break;
    }
    }
    if (base) {
        if (func_ov000_0218d494(self, ev)) {
            return TRUE;
        }
    }
    if (ret) {
        self->unk_30 |= 1 << ev->type;
        ev->type = 0;
    }
    return ret;
}
