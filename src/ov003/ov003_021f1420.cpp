#include "types.h"

struct Ov003HeapCtx {
    void *cur;
    u32 unk_04;
    void *alt;
};

struct Ov003PropDef {
    u16 id;
    u16 arg;
};

struct Ov003PropInfo {
    u8 unk_00[0x12];
    u16 loop : 1;
    u16 reverse : 1;
    u16 unk_12_2 : 10;
    u16 shadow : 2;
};

struct Ov003PropRes {
    s16 handle;
};

struct Ov003PropShadow {
    u8 unk_00[0x1c];
};

struct Ov003Prop {
    void *vtbl;
    u8 unk_04[0xa];
    u16 id;
    u8 unk_10[0x24];
    Ov003PropRes *res;
    u8 unk_38[4];
    Ov003PropShadow *shadow;
    u8 unk_40[0x6c];
    void *unk_ac;
    u32 unk_b0;
};

extern "C" {

extern Ov003HeapCtx *data_02097dd0;
extern u8 data_ov003_021fa1b8[];
extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *p);
extern void *func_ov000_0218c2d4(void *p);
extern void func_ov000_0218d1c0(void *p, u16 a, u16 b, s32 c);
extern s32 func_0206ffa0(u16 id);
extern void func_ov000_021bd228(void *p);
extern void *func_ov000_0218c928(void *p);
extern Ov003PropInfo *func_0206fef8(u16 id);
extern void *func_0207011c(u16 id);
extern Ov003PropRes *func_ov000_0218e9c4(void *p);
extern Ov003PropShadow *func_ov000_021919c8(void *p);
extern void func_ov000_02191b70(Ov003PropShadow *p);
extern void func_ov000_0218f074(Ov003PropRes *p, void *res, s32 a, s32 b, s32 c, s32 d);

Ov003Prop *func_ov003_021f1420(Ov003PropDef *def) {
    Ov003Prop *p = (Ov003Prop *)func_0203dd9c(0xb4);
    if (p != NULL) {
        func_ov000_0218c2d4(p);
        p->vtbl = data_ov003_021fa1b8;
        p->unk_ac = NULL;
        p->unk_b0 = 0;
    }
    func_ov000_0218d1c0(p, def->arg, def->id, func_0206ffa0(def->id));
    return p;
}

static inline void Ov003Prop_Dtor(Ov003Prop *self) {
    void *p;
    void *old;
    self->vtbl = data_ov003_021fa1b8;
    old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->alt;
    p = self->unk_ac;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_021bd228(p);
            func_0203de1c(p);
        }
        self->unk_ac = NULL;
    }
    data_02097dd0->cur = old;
    func_ov000_0218c928(self);
}

Ov003Prop *func_ov003_021f1478(Ov003Prop *self) {
    Ov003Prop_Dtor(self);
    return self;
}

Ov003Prop *func_ov003_021f14e8(Ov003Prop *self) {
    Ov003Prop_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021f1560(Ov003Prop *self) {
    Ov003PropInfo *info = func_0206fef8(self->id);
    void *data = func_0207011c(self->id);
    Ov003PropRes *res;
    Ov003PropShadow *sh;
    if (data == NULL) {
        return;
    }
    res = (Ov003PropRes *)func_0203dd9c(0x138);
    if (res != NULL) {
        res = func_ov000_0218e9c4(res);
    }
    self->res = res;
    {
        BOOL loop = info->loop ? 1 : 0;
        BOOL reverse = info->reverse ? 1 : 0;
        func_ov000_0218f074(self->res, data, loop, reverse, 0, 0);
    }
    self->res->handle = 0;
    if (!info->shadow) {
        return;
    }
    sh = (Ov003PropShadow *)func_0203dd9c(0x1c);
    if (sh != NULL) {
        sh = func_ov000_021919c8(sh);
    }
    self->shadow = sh;
    func_ov000_02191b70(sh);
}
}
