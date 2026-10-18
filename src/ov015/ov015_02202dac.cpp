#include "ov015/ov015.h"

extern "C" {

extern void *data_ov000_021ccd44;
u8 *func_ov000_0218084c(void *a, s32 b, s32 c);
extern void *data_ov000_021ccd40;
extern void *data_ov000_021ccd38;
void *func_02023390(void *a, int b);
void *func_02023410(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
extern void *data_02097e4c;
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
extern void *data_02149ef8;
void *func_0204c0e8(void *a, s32 b);
void func_ov000_0215bb14(void *a, void *b);
void func_ov015_02207738(void *p);
extern u8 data_ov015_022129c0[];
void func_ov000_02163254(void *p);
void func_ov000_02191b04(void *p);
extern u8 data_ov015_022129d0[];
void *func_ov015_0220765c(void *p);
void func_ov015_02207858(void *p);
void func_ov000_0219196c(void *p);
void func_ov000_02191b70(void *p);
extern Ov015Shared *data_ov015_02213368;
bool func_ov015_022078bc(void *p);
bool func_ov000_02191b9c(void *p);

static inline bool Ov015Task_Flag4(Ov015Task *t) {
    return t->flag4;
}

bool func_ov015_02202dac(Ov015Task *self) {
    BOOL r = Ov015Task_Flag4(self);
    return r;
}

void func_ov015_02202dd0(Ov015Task *self) {
    u8 *o;
    if (self->unk_08 == 8) {
        return;
    }
    if (self->unk_08 != 0xc) {
        return;
    }
    o = func_ov000_0218084c(data_ov000_021ccd44, 0x1f, 0);
    FLD(s32, o, 0xc) = self->unk_0c;
    VCALL(self)->v4c();
}

BOOL func_ov015_02202e20(Ov015Task *self) {
    if (VCALL(self)->v54()) {
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd38 = FLD(void *, data_ov000_021ccd40, 0x14);
        } else {
            data_ov000_021ccd38 = NULL;
        }
        data_ov000_021ccd40 = NULL;
    }
    return TRUE;
}

static inline bool Ov015_IsCurrent(void *p) {
    return data_ov000_021ccd40 == p;
}

bool func_ov015_02202e74(void *self) {
    BOOL r = Ov015_IsCurrent(self);
    return r;
}

void func_ov015_02202e9c(u8 *self) {
    s32 a = FLD(s32, self, 0x44);
    s32 r = 0;
    if (a < 0x1000000) {
        r = a + 0x8000;
    }
    FLD(s32, self, 0x44) = r;
    if (FLD(s32, self, 0x48) >= 0x1000000) {
        FLD(s32, self, 0x48) = 0;
    } else {
        FLD(s32, self, 0x48) += 0x8000;
    }
}

void func_ov015_02202ec8(u8 *self) {
    u8 *model = FLD(u8 *, self, 0x3c);
    u8 *res;
    u8 *anim;
    u8 *t;
    void *arg;
    if (model == NULL || FLD(u8, self, 0x40) == 0 || (res = FLD(u8 *, model, 0x28)) == NULL) {
        return;
    }
    anim = NULL;
    if (FLD(s32, model, 0x80) > 0) {
        anim = FLD(u8 *, model, 0x78);
    }
    if (anim != NULL && (t = FLD(u8 *, anim, 0x4)) != NULL) {
        arg = FLD(void *, t, 0x30);
    } else {
        void *e = func_02023390(FLD(void *, res, 0xc), 0);
        arg = func_02023410(FLD(void *, res, 0x4), **(u16 **)FLD(void *, e, 0xc));
    }
    func_02042628(model, arg, anim, 0);
}

BOOL func_ov015_02202f44(u8 *self, u8 *ev) {
    if (ev != NULL) {
        if (FLD(s32, ev, 0x10) != -1) {
            FLD(u8, FLD(u8 *, self, 0x8), 0xa4) = 1;
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        } else {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        }
    }
    return TRUE;
}

BOOL func_ov015_02202fa8(u8 *self, u8 *ev) {
    u8 *o = FLD(u8 *, self, 0x8);
    void *d = data_02149ef8;
    void *m;
    switch (FLD(u16, ev, 0x6)) {
    case 0:
        m = func_0204c0e8(d, 0xc7);
        break;
    case 1:
        m = func_0204c0e8(d, 0xcb);
        break;
    case 2:
        m = func_0204c0e8(d, 0xd5);
        break;
    }
    if (FLD(void *, o, 0x84) != NULL) {
        func_ov000_0215bb14(FLD(void *, o, 0x84), m);
        VCALL(FLD(void *, o, 0x84))->v70();
    }
    return TRUE;
}

void func_ov015_02203020(u8 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    {
    u8 *o = FLD(u8 *, self, 0x3c);
    if (o != NULL) {
        if (o != NULL) {
            func_ov015_02207738(o);
            func_0203de1c(o);
        }
        FLD(void *, self, 0x3c) = NULL;
    }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x40));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x80));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x84));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x88));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x8c));
    HEAP_POP(saved);
}

void *func_ov015_0220318c(void *self) {
    SET_VT(self, data_ov015_022129c0);
    func_ov000_02163254(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_022031b4(void *self) {
    func_ov000_02191b04(self);
    func_0203de1c(self);
    return self;
}

void func_ov015_022031d0(u8 *self) {
    void *p;
    void *q;
    p = func_0203dd9c(0xd58);
    if (p != NULL) {
        p = func_ov015_0220765c(p);
    }
    FLD(void *, self, 0x3c) = p;
    func_ov015_02207858(p);
    FLD(u16, FLD(u8 *, self, 0x3c), 0xd48) = data_ov015_02213368->unk_2c;
    q = func_0203dd9c(0x1c);
    if (q != NULL) {
        func_ov000_0219196c(q);
        SET_VT(q, data_ov015_022129d0);
    }
    FLD(void *, self, 0x40) = q;
    func_ov000_02191b70(q);
}

BOOL func_ov015_02203244(u8 *self) {
    BOOL r = func_ov015_022078bc(FLD(void *, self, 0x3c)) & 1 ? TRUE : FALSE;
    u8 st = FLD(u8, FLD(u8 *, self, 0x40), 0x1b);
    BOOL idle = TRUE;
    if (st != 3 && st != 0) {
        idle = FALSE;
    }
    if (!idle) {
        r = r & func_ov000_02191b9c(FLD(void *, self, 0x40)) ? TRUE : FALSE;
    }
    return r;
}

}
