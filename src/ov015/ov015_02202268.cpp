#include "ov015/ov015.h"

extern "C" {

extern Ov015Globals data_ov015_02213320;
extern u8 *data_02097d48;
void NNS_G3dGeFlushBuffer(void);
void func_ov015_02208070(void *p);
void func_ov015_02209b8c(u8 *self);
void func_ov015_0220f7a8(u8 *self);
void func_ov015_02210d04(u8 *self);
void func_ov015_02212264(u8 *self);
void func_ov015_021fb758(u8 *self);
BOOL func_ov000_021903b4(void *a);
extern void **data_0214a420;
extern void *data_02097cdc;
s32 func_02065748(void *a, void *b);
void func_ov015_021fa6cc(void *p);
void func_02036838(void *a, void *b, int c, int d);
void func_020656b4(void *p);
void func_ov015_0220101c(u8 *self);
void func_ov015_02211878(void *p);
extern u8 data_ov015_0221296c[];
extern u8 data_ov015_0221280c[];
extern u8 data_ov015_022127dc[];
extern u8 data_ov015_022127ec[];
extern char data_ov015_022128c1[];
extern u8 data_ov015_0221293c[];
extern char data_ov015_022128ab[];
void func_0206e900(char *buf, const char *name);
void func_02041558(void *p);
void func_02041278(void *p);
extern u8 data_ov015_0221294c[];
void *func_ov000_0218fee4(void *a);
void *func_ov000_0218ea20(void *a);
extern u8 data_ov015_022128ec[];
void func_ov015_0220f4d4(void *p);
extern u8 data_ov015_022128fc[];
void func_ov015_02209270(void *p);
void func_0203f2b8(void *p);
void *func_ov000_02191b04(void *p);
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);
void func_ov015_0220900c(void *p);
extern u8 data_ov015_0221292c[];
void func_ov015_022120fc(void *p);
extern u8 data_ov015_0221290c[];
extern u8 data_ov015_0221295c[];

s32 func_ov015_02202268(void) {
    switch (((Ov015Child *)data_ov015_02213320.unk_00)->state) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return 3;
    case 0:
    default:
        return 1;
    }
}

static inline void Ov015_022022ac_Draw(u8 *self) {
    u8 *p;
    u8 *n;
    func_ov015_02208070(FLD(void *, self, 0x18));
    p = FLD(u8 *, self, 0x20);
    func_ov000_021903b4(p + 0x13c);
    func_ov000_021903b4(p + 0x35c);
    func_ov000_021903b4(p + 0x57c);
    NNS_G3dGeFlushBuffer();
    for (n = FLD(u8 *, FLD(u8 *, self, 0x1c), 0x4); n != NULL; n = FLD(u8 *, n, 0xc)) {
        func_ov015_02209b8c(FLD(u8 *, n, 0x4));
    }
}
void func_ov015_022022ac(u8 *self) {
    switch (FLD(s32, self, 0xc)) {
    case 0:
        break;

    case 0x28:
        if (FLD(s32, self, 0x34) > 2 && FLD(Ov015D48Bits2, data_02097d48, 0xa30).b4) {
            if (FLD(u8 *, self, 0x40) != NULL) func_ov015_02212264(FLD(u8 *, self, 0x40));
            if (FLD(void *, self, 0x44) != NULL) VCALL(FLD(void *, self, 0x44))->v1c();
        }
        if (FLD(s32, self, 0x34) >= 3) {
            Ov015_022022ac_Draw(self);
        }
        if (FLD(u8 *, self, 0x90) != NULL) func_ov015_02210d04(FLD(u8 *, self, 0x90));
        break;
    case 0x32:
    case 0x3c:
        if (FLD(Ov015D48Bits2, data_02097d48, 0xa30).b4) {
            func_ov015_021fb758(FLD(u8 *, self, 0x28));
        }
        Ov015_022022ac_Draw(self);
        if (FLD(u8 *, self, 0x90) != NULL) func_ov015_02210d04(FLD(u8 *, self, 0x90));
        NNS_G3dGeFlushBuffer();
        break;
    case 0x46:
        func_ov015_0220f7a8(FLD(u8 *, self, 0x2c));
        break;
    }
}

void *func_ov015_02202448(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_0221296c);
    func_ov015_0220101c(self);
    func_02036838(data_02097cdc, data_ov015_022128c1, 7, 0);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x2c));
    HEAP_POP(saved);
    func_020656b4(data_0214a420);
    FLD(u8, data_0214a420, 0x10) = 0;
    FLD(s32, data_02097d48, 0x4) = 1;
    func_ov015_02211878(self + 0x94);
    SET_VT(self + 0x5c, data_ov015_022127dc);
    if (func_02065748(data_0214a420, FLD(void *, self, 0x60))) {
        HEAP_PUSH(saved);
        DELETE_V(FLD(void *, self, 0x60));
        HEAP_POP(saved);
    }
    SET_VT(self + 0x30, data_ov015_022127ec);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x40));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x44));
    HEAP_POP(saved);
    FLD(s32, self, 0x34) = 0;
    FLD(s32, self, 0x38) = 0;
    FLD(u8, self, 0x3c) = 0;
    FLD(s32, self, 0x40) = 0;
    FLD(s32, self, 0x44) = 0;
    FLD(s32, self, 0x48) = 0;
    FLD(s32, self, 0x4c) = 0;
    FLD(s32, self, 0x50) = 0;
    FLD(s32, self, 0x54) = 0;
    FLD(s32, self, 0x58) = 0;
    SET_VT(self, data_ov015_0221280c);
    func_ov015_021fa6cc(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_0220261c(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_0221296c);
    func_ov015_0220101c(self);
    func_02036838(data_02097cdc, data_ov015_022128c1, 7, 0);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x2c));
    HEAP_POP(saved);
    func_020656b4(data_0214a420);
    FLD(u8, data_0214a420, 0x10) = 0;
    FLD(s32, data_02097d48, 0x4) = 1;
    func_ov015_02211878(self + 0x94);
    SET_VT(self + 0x5c, data_ov015_022127dc);
    if (func_02065748(data_0214a420, FLD(void *, self, 0x60))) {
        HEAP_PUSH(saved);
        DELETE_V(FLD(void *, self, 0x60));
        HEAP_POP(saved);
    }
    SET_VT(self + 0x30, data_ov015_022127ec);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x40));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x44));
    HEAP_POP(saved);
    FLD(s32, self, 0x34) = 0;
    FLD(s32, self, 0x38) = 0;
    FLD(u8, self, 0x3c) = 0;
    FLD(s32, self, 0x40) = 0;
    FLD(s32, self, 0x44) = 0;
    FLD(s32, self, 0x48) = 0;
    FLD(s32, self, 0x4c) = 0;
    FLD(s32, self, 0x50) = 0;
    FLD(s32, self, 0x54) = 0;
    FLD(s32, self, 0x58) = 0;
    SET_VT(self, data_ov015_0221280c);
    func_ov015_021fa6cc(self);
    return self;
}

void *func_ov015_022027e8(u8 *self) {
    char buf[0x20];
    SET_VT(self, data_ov015_0221293c);
    {
        u32 saved;
        HEAP_PUSH(saved);
        {
            u8 *o = FLD(u8 *, self, 0x24);
            if (o != NULL) {
                if (o != NULL) {
                    func_02041558(o);
                    func_02041278(o + 0x88);
                    func_0203de1c(o);
                }
                FLD(void *, self, 0x24) = NULL;
            }
        }
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        {
            u8 *o = FLD(u8 *, self, 0x28);
            if (o != NULL) {
                if (o != NULL) {
                    func_02041558(o);
                    func_02041278(o + 0x88);
                    func_0203de1c(o);
                }
                FLD(void *, self, 0x28) = NULL;
            }
        }
        HEAP_POP(saved);
    }
    func_0206e900(buf, data_ov015_022128ab);
    func_02036838(data_02097cdc, buf, 7, 0);

    return self;
}

void *func_ov015_022028dc(u8 *self) {
    SET_VT(self, data_ov015_0221294c);
    func_ov000_0218fee4(self + 0x57c);
    func_ov000_0218ea20(self + 0x444);
    func_ov000_0218fee4(self + 0x35c);
    func_ov000_0218ea20(self + 0x224);
    func_ov000_0218fee4(self + 0x13c);
    func_ov000_0218ea20(self + 0x4);
    return self;
}

void *func_ov015_02202930(void *self) {
    SET_VT(self, data_ov015_022128ec);
    func_ov015_0220f4d4(self);
    return self;
}

void *func_ov015_02202950(u8 *self) {
    SET_VT(self, data_ov015_022128fc);
    func_ov015_02209270(self);
    func_0203f2b8(self + 0x568);
    func_ov000_02191b04(self + 0x54c);
    func_ov000_0218fee4(self + 0x464);
    func_ov000_0218ea20(self + 0x32c);
    func_ov000_0218fee4(self + 0x244);
    func_ov000_0218ea20(self + 0x10c);
    func_ov015_0220900c(self + 0xc0);
    return self;
}

void *func_ov015_022029b4(void *self) {
    SET_VT(self, data_ov015_0221292c);
    func_ov015_022120fc(self);
    return self;
}

void func_ov015_022029d4(Ov015List *self, s32 key) {
    Ov015Node *n;
    u32 saved;
    if (self->head == NULL) {
        return;
    }
    for (n = self->head; n != NULL; n = n->next) {
        if (n->key == key) {
            break;
        }
    }
    if (n == NULL) {
        return;
    }
    if (n == self->head) {
        self->head = n->next;
    }
    if (n == self->tail) {
        self->tail = n->prev;
    }
    HEAP_PUSH(saved);
    DELETE_V(n);
    HEAP_POP(saved);
    self->count--;
}

Ov015List *func_ov015_02202a78(Ov015List *self) {
    Ov015Node *n;
    SET_VT(self, data_ov015_0221290c);
    n = self->head;
    while (n != NULL) {
        Ov015Node *next = n->next;
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_V(n);
        HEAP_POP(saved);
        n = next;
    }
    self->count = 0;
    func_0203de1c(self);
    return self;
}

Ov015Node *func_ov015_02202af8(Ov015Node *self) {
    SET_VT(self, data_ov015_0221295c);
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
    func_0203de1c(self);
    return self;
}

Ov015List *func_ov015_02202b3c(Ov015List *self) {
    Ov015Node *n;
    SET_VT(self, data_ov015_0221290c);
    n = self->head;
    while (n != NULL) {
        Ov015Node *next = n->next;
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_V(n);
        HEAP_POP(saved);
        n = next;
    }
    self->count = 0;
    return self;
}

Ov015Node *func_ov015_02202bb4(Ov015Node *self) {
    SET_VT(self, data_ov015_0221295c);
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
    return self;
}

void func_ov015_02202be4(void) {
}

s32 func_ov015_02202be8(void) {
    return 1;
}

extern void *data_0208cca0;
extern void *data_0208ccc0;
void func_02041218(void *p);
void func_02041440(void *p, void *name, int c);
void *STD_CopyString(void *p, void *name);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *a, void *b);
void func_02041d9c(void *a, int b, int c);
void func_02041c20(void *a, int b, void *c);
void func_0203cb78(s32 a, s32 b, s32 c);
void func_ov000_02173648(void *p);
void func_ov015_02206bf0(void *self, s32 x, s32 y, s32 z, s32 unused, void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs);
static inline void Ov015Label_Ctor2(u8 *l, void *name, void *dict) {
    func_02041218(l + 0x88);
    func_02041440(l, dict, 0);
    STD_CopyString(l + 0x2c, name);
}
void func_ov015_02202bf0(u8 *self) {
    Ov015Bgm *p = (Ov015Bgm *)data_02097e48;
    void *name;
    void *file;
    u8 *l;
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
    FLD(u32, self, 0x4) &= ~2;
    if (VCALL(self)->v28()) return;
    l = (u8 *)func_0203dd9c(0x160);
    if (l != NULL) {
        file = data_0208cca0;
        name = data_0208ccc0;
        func_02041218(l + 0x88);
        func_02041440(l, name, 0);
        STD_CopyString(l + 0x2c, file);
    }
    FLD(u8 *, self, 0x3c) = l;
    func_020417e0(FLD(void *, self, 0x3c), func_02034d88(func_02035d5c(data_0208cca0), data_0208ccc0));
    FLD(u32, FLD(u8 *, self, 0x3c), 0x6c) |= 2;
    func_02041d9c(FLD(void *, self, 0x3c), 0, 0);
    {
        u8 *p = FLD(u8 *, self, 0x3c);
        FLD(s32, p, 0xfc) = 0;
        FLD(s32, p, 0x100) = 0;
    }
    FLD(s32, FLD(u8 *, self, 0x3c), 0x150) = 0xfffe019a;
    FLD(void *, FLD(u8 *, self, 0x3c), 0x158) = (void *)func_ov015_02206bf0;
    func_02041c20(FLD(void *, self, 0x3c), 0, self + 0x44);
    FLD(s32, self, 0x2c) = 0;
    FLD(u8, self, 0x40) = 1;
    func_ov000_02173648(self);
    func_0203cb78(0x14000, 0, 1);
    func_0203cb78(0x14000, 0, 0);
}

}
