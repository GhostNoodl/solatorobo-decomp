#include "types.h"

typedef struct {
    s16 res;
    u8 unk_02[0x136];
} Ov003MultiSlot;

typedef struct Ov003Multi Ov003Multi;
struct Ov003Multi {
    u8 unk_00[8];
    u32 flags;
    u8 unk_0c[0xc];
    s16 kind;
    u8 unk_1a[0xa];
    void (*func)(Ov003Multi *self);
    u8 unk_28[0x6a];
    u8 state;
    u8 unk_93[0x1b];
    u8 group;
    u8 unk_af;
    Ov003MultiSlot slots[8];
};

typedef struct {
    u8 unk_00[0x30];
    u8 group;
    u8 unk_31[3];
} Ov003MultiTarget;

typedef struct {
    u8 unk_00[0xfe0];
    Ov003MultiTarget targets[5];
    u8 unk_10e4[0x36];
    u8 cur;
} Ov003MultiMgr;

typedef struct {
    void *res;
    u8 unk_04[0xc];
} Ov003MultiRes;

typedef struct {
    Ov003MultiRes *res;
    u8 unk_04[4];
    u16 count;
    u8 unk_0a[6];
} Ov003MultiDef;

extern Ov003MultiMgr *data_ov003_021fa680;
extern const Ov003MultiDef data_ov003_021f7470[];

extern void func_0202a4c8(void *p, s32 a);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0218f110(s16 *p);

void func_ov003_021f2374(Ov003Multi *self) {
    Ov003MultiMgr *mgr = data_ov003_021fa680;
    Ov003MultiTarget *t;
    s32 group;
    if (mgr == NULL) {
        return;
    }
    t = &mgr->targets[mgr->cur];
    if (self->flags & 0x10) {
        group = self->group;
    } else {
        group = -1;
    }
    if (t->group == 0xff) {
        return;
    }
    if (t->group != group) {
        return;
    }
    func_0202a4c8(t, 0);
    self->func = NULL;
    self->state = 0;
}

void func_ov003_021f23e0(Ov003Multi *self) {
    self->func = func_ov003_021f2374;
    self->state = 3;
}

void func_ov003_021f23f8(Ov003Multi *self) {
    const Ov003MultiDef *def = &data_ov003_021f7470[self->kind];
    s32 i;
    u16 n = def->count;
    if (n > 8) {
        n = 8;
    }
    for (i = 0; i < n; i++) {
        func_ov000_0218f074(&self->slots[i].res, def->res[i].res, 1, 1, 0, 0);
        self->slots[i].res = 0;
    }
}

BOOL func_ov003_021f247c(Ov003Multi *self) {
    const Ov003MultiDef *def = &data_ov003_021f7470[self->kind];
    BOOL r = TRUE;
    s32 i = 0;
    for (; i < def->count; i++) {
        if (self->slots[i].res >= 0) {
            if (!func_ov000_0218f110(&self->slots[i].res)) {
                r = FALSE;
            }
        }
    }
    return r;
}
