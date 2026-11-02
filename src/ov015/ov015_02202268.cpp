#include "ov015/ov015.h"

extern "C" {

extern Ov015Globals data_ov015_02213320;
void func_ov015_02208070(Ov015Ship *p);
void func_ov015_02209b8c(Ov015Fish *self);
void func_ov015_0220f7a8(u8 *self);
void func_ov015_02210d04(u8 *self);
void func_ov015_02212264(Ov015Obj292c *self);
void func_ov015_021fb758(u8 *self);
BOOL func_ov000_021903b4(void *a);
s32 func_02065748(void *a, void *b);
void func_ov015_021fa6cc(void *p);
void func_020656b4(void *p);
void func_ov015_0220101c(Ov015Game *self);
void func_ov015_02211878(void *p);
extern u8 data_ov015_0221296c[];
extern u8 data_ov015_0221280c[];
extern u8 data_ov015_022127dc[];
extern u8 data_ov015_022127ec[];
extern char data_ov015_022128c1[];
extern u8 data_ov015_0221293c[];
extern char data_ov015_022128ab[];
void func_0206e900(char *buf, const char *name);
extern u8 data_ov015_0221294c[];
void *func_ov000_0218fee4(void *a);
void *func_ov000_0218ea20(void *a);
extern u8 data_ov015_022128ec[];
void func_ov015_0220f4d4(void *p);
extern u8 data_ov015_022128fc[];
void func_ov015_02209270(Ov015Fish *p);
void func_0203f2b8(void *p);
void *func_ov000_02191b04(void *p);
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);
void func_ov015_0220900c(void *p);
extern u8 data_ov015_0221292c[];
void func_ov015_022120fc(Ov015Obj292c *self);
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

static inline void Ov015_022022ac_Draw(Ov015Game *self) {
    u8 *p;
    u8 *n;
    func_ov015_02208070(self->unk_18);
    p = self->unk_20;
    func_ov000_021903b4(p + 0x13c);
    func_ov000_021903b4(p + 0x35c);
    func_ov000_021903b4(p + 0x57c);
    NNS_G3dGeFlushBuffer();
    for (n = FLD(u8 *, self->unk_1c, 0x4); n != NULL; n = FLD(u8 *, n, 0xc)) {
        func_ov015_02209b8c(FLD(Ov015Fish *, n, 0x4));
    }
}
void func_ov015_022022ac(Ov015Game *self) {
    switch (self->unk_0c) {
    case 0:
        break;

    case 0x28:
        if (self->unk_30.unk_04 > 2 && data_02097d48->unk_a30_4) {
            if (self->unk_30.unk_10 != NULL) func_ov015_02212264(self->unk_30.unk_10);
            if (self->unk_30.unk_14 != NULL) VCALL(self->unk_30.unk_14)->v1c();
        }
        if (self->unk_30.unk_04 >= 3) {
            Ov015_022022ac_Draw(self);
        }
        if (self->unk_90 != NULL) func_ov015_02210d04(self->unk_90);
        break;
    case 0x32:
    case 0x3c:
        if (data_02097d48->unk_a30_4) {
            func_ov015_021fb758(self->unk_28);
        }
        Ov015_022022ac_Draw(self);
        if (self->unk_90 != NULL) func_ov015_02210d04(self->unk_90);
        NNS_G3dGeFlushBuffer();
        break;
    case 0x46:
        func_ov015_0220f7a8(self->unk_2c);
        break;
    }
}

void *Ov015Game_DtorDelete(Ov015Game *self) {
    void *saved;
    SET_VT(self, data_ov015_0221296c);
    func_ov015_0220101c(self);
    func_02036838(data_02097cdc, data_ov015_022128c1, 7, 0);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_2c);
    HEAP_POP(saved);
    func_020656b4(data_0214a420);
    data_0214a420->drawFilter = 0;
    data_02097d48->nextState = 1;
    func_ov015_02211878(&self->unk_94);
    SET_VT(&self->unk_5c, data_ov015_022127dc);
    if (func_02065748(data_0214a420, self->unk_5c.unk_04)) {
        HEAP_PUSH(saved);
        DELETE_V(self->unk_5c.unk_04);
        HEAP_POP(saved);
    }
    SET_VT(&self->unk_30, data_ov015_022127ec);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_30.unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_30.unk_14);
    HEAP_POP(saved);
    self->unk_30.unk_04 = 0;
    self->unk_30.unk_08 = 0;
    self->unk_30.unk_0c = 0;
    self->unk_30.unk_10 = 0;
    self->unk_30.unk_14 = 0;
    self->unk_30.unk_18 = 0;
    self->unk_30.unk_1c = 0;
    self->unk_30.unk_20 = 0;
    self->unk_30.unk_24 = 0;
    self->unk_30.unk_28 = 0;
    SET_VT(self, data_ov015_0221280c);
    func_ov015_021fa6cc(self);
    Heap_Free(self);
    return self;
}

void *Ov015Game_Dtor(Ov015Game *self) {
    void *saved;
    SET_VT(self, data_ov015_0221296c);
    func_ov015_0220101c(self);
    func_02036838(data_02097cdc, data_ov015_022128c1, 7, 0);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_2c);
    HEAP_POP(saved);
    func_020656b4(data_0214a420);
    data_0214a420->drawFilter = 0;
    data_02097d48->nextState = 1;
    func_ov015_02211878(&self->unk_94);
    SET_VT(&self->unk_5c, data_ov015_022127dc);
    if (func_02065748(data_0214a420, self->unk_5c.unk_04)) {
        HEAP_PUSH(saved);
        DELETE_V(self->unk_5c.unk_04);
        HEAP_POP(saved);
    }
    SET_VT(&self->unk_30, data_ov015_022127ec);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_30.unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_30.unk_14);
    HEAP_POP(saved);
    self->unk_30.unk_04 = 0;
    self->unk_30.unk_08 = 0;
    self->unk_30.unk_0c = 0;
    self->unk_30.unk_10 = 0;
    self->unk_30.unk_14 = 0;
    self->unk_30.unk_18 = 0;
    self->unk_30.unk_1c = 0;
    self->unk_30.unk_20 = 0;
    self->unk_30.unk_24 = 0;
    self->unk_30.unk_28 = 0;
    SET_VT(self, data_ov015_0221280c);
    func_ov015_021fa6cc(self);
    return self;
}

void *func_ov015_022027e8(u8 *self) {
    char buf[0x20];
    SET_VT(self, data_ov015_0221293c);
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            u8 *o = FLD(u8 *, self, 0x24);
            if (o != NULL) {
                if (o != NULL) {
                    func_02041558((Model *)o);
                    func_02041278((PlttRes *)(o + 0x88));
                    Heap_Free(o);
                }
                FLD(void *, self, 0x24) = NULL;
            }
        }
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            u8 *o = FLD(u8 *, self, 0x28);
            if (o != NULL) {
                if (o != NULL) {
                    func_02041558((Model *)o);
                    func_02041278((PlttRes *)(o + 0x88));
                    Heap_Free(o);
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

void *Ov015Result_Dtor(void *self) {
    SET_VT(self, data_ov015_022128ec);
    func_ov015_0220f4d4(self);
    return self;
}

void *Ov015Fish_Dtor(Ov015Fish *self) {
    SET_VT(self, data_ov015_022128fc);
    func_ov015_02209270(self);
    func_0203f2b8(&self->unk_568);
    func_ov000_02191b04(&self->unk_54c);
    func_ov000_0218fee4(&self->unk_464);
    func_ov000_0218ea20(&self->unk_32c);
    func_ov000_0218fee4(&self->unk_244);
    func_ov000_0218ea20(&self->unk_10c);
    func_ov015_0220900c(&self->unk_c0);
    return self;
}

void *Ov015Obj292c_Dtor(Ov015Obj292c *self) {
    SET_VT(self, data_ov015_0221292c);
    func_ov015_022120fc(self);
    return self;
}

void func_ov015_022029d4(Ov015List *self, s32 key) {
    Ov015Node *n;
    void *saved;
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
        void *saved;
        HEAP_PUSH(saved);
        DELETE_V(n);
        HEAP_POP(saved);
        n = next;
    }
    self->count = 0;
    Heap_Free(self);
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
    Heap_Free(self);
    return self;
}

Ov015List *func_ov015_02202b3c(Ov015List *self) {
    Ov015Node *n;
    SET_VT(self, data_ov015_0221290c);
    n = self->head;
    while (n != NULL) {
        Ov015Node *next = n->next;
        void *saved;
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

void func_0203cb78(s32 a, s32 b, s32 c);
void func_ov000_02173648(void *p);
void func_ov015_02206bf0(void *self, s32 x, s32 y, s32 z, s32 unused, void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs);
static inline void Ov015Label_Ctor2(u8 *l, void *name, void *dict) {
    func_02041218((PlttRes *)(l + 0x88));
    func_02041440((Model *)l, (char *)dict, 0);
    STD_CopyString((char *)(l + 0x2c), (char *)name);
}
void func_ov015_02202bf0(u8 *self) {
    SndQueue *p = data_02097e48.queue;
    void *name;
    void *file;
    u8 *l;
    if (p->flag0) {
        if (p->unk_06 != 0xffff || p->unk_04 != 0x25) {
            u16 v;
            if (p->unk_02 != 10 && p->unk_02 != 0) {
                if (p->unk_06 != 0xffff) {
                    func_0204aab0(p, p->unk_06);
                }
                v = 1;
            } else {
                v = 0;
            }
            p->unk_02 = v;
            p->unk_06 = 0x25;
            p->unk_08 = 10;
        }
    }
    FLD(u32, self, 0x4) &= ~2;
    if (VCALL(self)->v28()) return;
    l = (u8 *)Heap_Alloc(0x160);
    if (l != NULL) {
        file = (void *)data_0208cca0;
        name = data_0208ccc0;
        func_02041218((PlttRes *)(l + 0x88));
        func_02041440((Model *)l, (char *)name, 0);
        STD_CopyString((char *)(l + 0x2c), (char *)file);
    }
    FLD(u8 *, self, 0x3c) = l;
    func_020417e0((Model *)FLD(void *, self, 0x3c), func_02034d88(func_02035d5c(data_0208cca0), data_0208ccc0));
    FLD(u32, FLD(u8 *, self, 0x3c), 0x6c) |= 2;
    func_02041d9c((Model *)FLD(void *, self, 0x3c), 0, 0);
    {
        u8 *p = FLD(u8 *, self, 0x3c);
        FLD(s32, p, 0xfc) = 0;
        FLD(s32, p, 0x100) = 0;
    }
    FLD(s32, FLD(u8 *, self, 0x3c), 0x150) = 0xfffe019a;
    FLD(void *, FLD(u8 *, self, 0x3c), 0x158) = (void *)func_ov015_02206bf0;
    func_02041c20((Model *)FLD(void *, self, 0x3c), 0, self + 0x44);
    FLD(s32, self, 0x2c) = 0;
    FLD(u8, self, 0x40) = 1;
    func_ov000_02173648(self);
    func_0203cb78(0x14000, 0, 1);
    func_0203cb78(0x14000, 0, 0);
}

}
