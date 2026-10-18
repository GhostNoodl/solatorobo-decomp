#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x111];
    u8 unk_111_0 : 2;
    u8 unk_111_2 : 1;
    s16 unk_112;
} Ov003SubAnim;

typedef struct {
    u8 unk_00[4];
    void *unk_04;
    u8 unk_08[0xb6];
    u8 unk_be;
} Ov003Mdl;

typedef struct {
    u16 state;
} Ov003Wk;

typedef struct {
    u8 unk_00[0x18];
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003Mdl *model;
    u8 unk_3c[4];
    Ov003Wk *work;
    u8 unk_44[8];
    void *unk_4c;
    u8 unk_50[8];
    void *unk_58;
    u8 unk_5c[0x37];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x38];
    u16 unk_cc_0 : 1;
} Ov003Prop;

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0xb12];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
} Ov003Plr;

extern void *data_ov000_021ccd64;
extern s32 func_ov003_021f093c(void *p);
extern void func_020627b4(void);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern s32 func_0205b1fc(void);
extern Ov003Plr *func_ov000_0219bf90(void);
extern char data_ov003_021f803c[];
extern char data_ov003_021f8046[];
extern void func_ov000_0219433c(void *p);
extern void func_ov000_02194758(void *p);
extern void func_ov000_02197d80(void *p);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_0202a624(void *p, s32 a, s32 b);
extern void func_0203f920(void *p);
extern void func_0203f8d8(void *p);
extern void func_ov000_02191318(Ov003Mdl *m, s32 a);
extern Ov003SubAnim *func_ov000_02190a30(Ov003Mdl *m, s32 a);

void func_ov003_021ddf00(Ov003Prop *self) {
    Ov003Unit *u;
    func_ov000_0219433c(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
}

void func_ov003_021ddf34(Ov003Prop *self) {
    Ov003SubAnim *a;
    func_ov000_02194758(self);
    func_ov000_02197d80(self);
    switch (self->unk_18) {
    case 2:
        func_ov000_02190cb0(self->model, data_ov003_021f803c, 0x1000, 0);
        if (self->unk_1c == 1) {
            func_0202a624(self->model->unk_04, 0, 0x1f0000);
            self->model->unk_be = 0;
        }
        if (self->unk_1c != 2) {
            self->unk_cc_0 = 0;
            if (self->unk_58 != NULL) {
                func_0203f920(self->unk_58);
            }
        }
        break;
    case 0:
    case 1:
    case 3:
        func_ov000_02190cb0(self->model, data_ov003_021f8046, 0x1000, 0);
        if (self->unk_1c == 1) {
            func_0202a624(self->model->unk_04, 1, 0x1f0000);
        }
        self->unk_cc_0 = 1;
        if (self->unk_58 != NULL) {
            func_0203f8d8(self->unk_58);
        }
        break;
    }
    func_ov000_02191318(self->model, -1);
    self->work->state = 0;
    a = func_ov000_02190a30(self->model, 2);
    if (a != NULL) {
        s16 s;
        a->unk_111_2 = 1;
        s = self->unk_1e;
        if (s != 0 && s != 0x1000) {
            s = (s16)((s * 0x800) >> 12);
        } else {
            s = 0x800;
        }
        a->unk_112 = s;
    }
    self->unk_93_1 = (u16)self->unk_18;
}

void func_ov003_021de0a4(Ov003Prop *self) {
    switch (self->unk_1a) {
    case 3: {
        BOOL changed;
        s16 v;
        Ov003Plr *p;
        s32 r = func_ov003_021f093c(self->unk_4c);
        changed = FALSE;
        switch (r) {
        case 3:
        case 4:
            if (self->unk_18 != 2 && self->work->state != 0x14) {
                self->work->state = 0x14;
                self->unk_18 = 2;
                changed = TRUE;
            }
            break;
        case 1:
        case 2:
            if (self->unk_18 != 0 && self->work->state != 10) {
                self->work->state = 10;
                self->unk_18 = 0;
                changed = TRUE;
            }
            break;
        }
        if (!changed) {
            return;
        }
        v = self->unk_18;
        self->unk_93_1 = (u16)v;
        func_020627b4();
        func_ov000_02197dec(self, v, v);
        if (func_0205b1fc() != 1) {
            return;
        }
        p = func_ov000_0219bf90();
        if (p == NULL) {
            return;
        }
        if (p->unk_b28_0 != 0) {
            return;
        }
        p->unk_15 = 3;
        p->unk_b28_0 = 0;
        p->unk_b28_2 = 1;
        break;
    }
    case 1: {
        s16 v;
        if (self->unk_93_1 == self->unk_18) {
            return;
        }
        switch (self->unk_18) {
        case 2:
            if (self->work->state != 0x14) {
                self->work->state = 0x14;
                self->unk_18 = 2;
            }
            break;
        case 0:
        case 1:
        case 3:
            if (self->work->state != 10) {
                self->work->state = 10;
                self->unk_18 = 0;
            }
            break;
        }
        self->unk_93_1 = (u16)self->unk_18;
        func_ov000_02197dec(self, self->unk_18, -1);
        break;
    }
    }
}
