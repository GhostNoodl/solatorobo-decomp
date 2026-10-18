#include "ov002/ov002.h"

extern "C" {

bool func_ov002_021cd7bc(Task50 *self) {
    BOOL r = Task50_getFlag4(self);
    return r;
}

void func_ov002_021cd7e0(Task50 *self) {
    self->unk_20 = 0x10000;
    self->unk_3c = NULL;
    self->unk_40 = NULL;
    self->unk_44 = NULL;
    self->unk_48 = 0;
    self->unk_4c = -1;
    self->unk_4d = 0;
}

void func_ov002_021cd80c(Task50 *self) {
    u32 saved;
    void *p;
    VObject *o;

    HEAP_PUSH(saved);
    p = self->unk_3c;
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        self->unk_3c = NULL;
    }
    HEAP_POP(saved);

    HEAP_PUSH(saved);
    o = self->unk_40;
    if (o != NULL) {
        if (o != NULL) {
            VC(o, 0x4)();
        }
        self->unk_40 = NULL;
    }
    HEAP_POP(saved);

    HEAP_PUSH(saved);
    o = self->unk_44;
    if (o != NULL) {
        if (o != NULL) {
            VC(o, 0x4)();
        }
        self->unk_44 = NULL;
    }
    HEAP_POP(saved);

    if (self->unk_4d) {
        func_02035acc(data_ov002_021ef3e4, data_ov002_021ef3ec, 2);
    }
}

void func_ov002_021cd910(void *self, int arg) {
    func_ov000_0218084c(data_ov000_021ccd44, arg, 0);
}

void func_ov002_021cd92c(Task50 *self, int kind) {
    void *msg = data_02149ef8;
    void *str = data_ov002_021ef3f8;
    switch (kind) {
    case 0:
        str = func_0204c0e8(msg, 0xdf);
        break;
    case 1:
        str = func_0204c0e8(msg, 0xe0);
        break;
    case 2:
        str = func_0204c0e8(msg, 0xc3);
        break;
    case 3:
        str = func_0204c0e8(msg, 0xe2);
        break;
    case 4:
        str = func_0204c0e8(msg, 0xe1);
        break;
    case 5:
        str = func_0204c0e8(msg, 0xde);
        break;
    }
    func_ov000_0215bb14(self->unk_44, str);
    VC(self->unk_44, 0x70)();
}

}

extern "C" {
extern void *data_ov000_021ccd54;
typedef struct { u8 pad[0x52]; u16 r, g, b; } Save1534;
extern Save1534 data_02fe1534;
void func_ov000_02186bb0(void *p);
void func_ov000_02187b50(void *p);
void func_ov000_02188ca0(u8 *buf, int a);
void func_02062524(void);
BOOL func_020624d8(void);
void func_ov000_0216f42c(void *a, void *b);

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 rest : 29;
} Flags021cd9c0;

static inline u8 *ov002_021cd9c0_getSelected(void *list) {
    u8 *item = FIELD(list, 0x98, u8 *);
    if (item == NULL) {
        item = NULL;
    } else {
        s32 n = FIELD(list, 0xb1, s8);
        while (n-- != 0) {
            item = FIELD(item, 0x2c, u8 *);
        }
    }
    return item;
}

void func_ov002_021cd9c0(Task50 *self) {
    u16 keys;
    s8 sel;
    s8 v;
    keys = FIELD(data_02097dc8, 0x12, u16);
    sel = (s8)FIELD(ov002_021cd9c0_getSelected(self->unk_40), 0x6, u16);
    v = data_ov002_021f0f80->unk_08;
    if (v != -1) {
        self->unk_4c = -1;
        sel = v;
        data_ov002_021f0f80->unk_08 = -1;
    }
    if (self->unk_4c != sel) {
        keys = 0;
    }
    if (keys & 1) {
        switch (sel) {
        case 0:
            if (!FIELD(self, 0x48, Flags021cd9c0).b0) {
                data_ov002_021f0f80->unk_08 = 0;
                func_0203cc58(self->unk_20, 2, 0);
                func_ov000_02186bb0(data_ov000_021ccd54);
                VC(self, 0xc)(0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            break;
        case 1:
            if (!FIELD(self, 0x48, Flags021cd9c0).b2) {
                void *o;
                data_ov002_021f0f80->unk_08 = 1;
                o = func_ov000_0218084c(data_ov000_021ccd44, 0x1a, 0);
                FIELD(o, 0x2c, s32) = 0;
                FIELD(o, 0x3c, s32) = FIELD(self, 0x14, s32);
                VC(self, 0x50)();
                FIELD(self, 0x4, u32) |= 6;
                func_0203cc58(self->unk_20, 2, -1);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            break;
        case 2:
            data_ov002_021f0f80->unk_08 = 2;
            VC(self, 0x60)(6, 0);
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            break;
        case 3:
            data_ov002_021f0f80->unk_08 = 3;
            FIELD(data_0214a424, 0x9, u8) = 0;
            VC(self, 0x60)(7, 0);
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            break;
        case 4:
            data_ov002_021f0f80->unk_08 = 4;
            FIELD(func_ov000_0218084c(data_ov000_021ccd44, 0x11, 0), 0x2c, s32) = 0;
            data_ov000_021ccd34 = 1;
            data_ov000_021ccd44->flag0 = 0;
            VC(self, 0x50)();
            FIELD(self, 0x4, u32) |= 6;
            func_0203cc58(self->unk_20, 2, -1);
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            break;
        case 5:
            if (!FIELD(self, 0x48, Flags021cd9c0).b1) {
                void *t;
                func_0203cc58(self->unk_20, 2, -1);
                if (func_020624d8()) {
                    u8 buf[3];
                    buf[0] = data_02fe1534.r;
                    buf[1] = data_02fe1534.g;
                    buf[2] = data_02fe1534.b;
                    func_ov000_02187b50(data_ov000_021ccd54);
                    func_ov000_02188ca0(buf, 1);
                    func_02062524();
                }
                t = data_ov000_021ccd30;
                if (t != NULL) {
                    func_ov000_0216f42c(t, FIELD(t, 0x118, void *));
                    FIELD(t, 0x118, void *) = NULL;
                }
                VC(self, 0xc)(0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            break;
        }
    } else if (keys & 2) {
        VObject *m = self->unk_40;
        sel = 5;
        m->v0xa8(func_ov000_02154b58(m, (void *)5));
    }
    if (self->unk_4c != sel) {
        VC(self, 0x78)(sel);
    }
    self->unk_4c = sel;
}
}
