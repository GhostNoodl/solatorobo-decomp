#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov003HeapCtx {
    void *cur;
    u32 unk_04;
    void *alt;
};

struct Ov003Work {
    u16 state;
    u16 timer;
};

struct Ov003Unit {
    u8 unk_00[0xa2];
    u8 active : 1;
};

struct Ov003BrAnim {
    u8 unk_00[0x78];
    Ov003Vec pos;
};

struct Ov003BrCtl {
    u8 unk_00[0x28];
    s32 unk_28;
    u8 unk_2c[0xc];
    s32 unk_38;
    u8 unk_3c[0x24];
    s32 unk_60;
    u8 unk_64[0x36];
    u16 enable : 1;
    u16 unk_9a_1 : 1;
    u16 unk_9a_2 : 1;
    u16 visible : 1;
    u16 unk_9a_4 : 1;
};

struct Ov003Bridge {
    void *vtbl;
    u8 unk_04[8];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 kind;
    s16 mode;
    s16 height;
    u8 unk_1e[2];
    u16 unitId;
    u8 unk_22[2];
    u8 unk_24[0x14];
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[4];
    Ov003BrCtl *ctl;
    u8 unk_4c[0x18];
    s32 unk_64;
    u8 unk_68[4];
    s32 unk_6c;
    Ov003Vec pos;
    u8 rot[0x17];
    u8 unk_93_0 : 1;
    u8 state : 3;
    u8 unk_94[0x20];
    void *res[2];
    u8 unk_bc[0x10];
    u16 unk_cc_0 : 1;
    u8 unk_ce[2];
    Ov003BrAnim *anim;
};

extern "C" {

extern Ov003HeapCtx *data_02097dd0;
extern void *data_ov000_021ccd64;
extern u8 data_ov003_021f9e10[];
extern char data_ov003_021f9fd6[];
extern char data_ov003_021f9fd0[];
extern void *func_ov000_0218fee4(void *p);
extern void func_0203de1c(void *p);
extern void *func_ov000_0219429c(void *p);
extern void func_ov000_0219433c(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_02197d80(void *self);
extern BOOL func_ov000_02194c08(void *self);
extern BOOL func_ov000_021903b4(void *anim);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern void func_ov000_02194758(void *self);
extern void *func_0203dd9c(u32 size);
extern Ov003BrCtl *func_ov000_021985e8(void *p);
extern void func_ov000_02198c8c(Ov003BrCtl *p, u16 id);
extern void func_0203f324(Ov003BrCtl *p);
extern Ov003BrAnim *func_ov000_0218fe1c(void *p);
extern BOOL func_ov000_0218ffdc(Ov003BrAnim *anim, void *res, s32 a, s32 b);
extern void func_ov000_02190758(Ov003BrAnim *anim, void *p, s32 a);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *p, s32 a);

static inline void Ov003Bridge_Dtor(Ov003Bridge *self) {
    void *p;
    void *old;
    self->vtbl = data_ov003_021f9e10;
    old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->alt;
    p = self->anim;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0218fee4(p);
            func_0203de1c(p);
        }
        self->anim = NULL;
    }
    data_02097dd0->cur = old;
    func_ov000_0219429c(self);
}

Ov003Bridge *func_ov003_021eeb04(Ov003Bridge *self) {
    Ov003Bridge_Dtor(self);
    return self;
}

Ov003Bridge *func_ov003_021eeb74(Ov003Bridge *self) {
    Ov003Bridge_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021eebec(Ov003Bridge *self) {
    Ov003Unit *u;
    func_ov000_0219433c(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
    if (u != NULL) {
        u->active = 0;
    }
    func_ov000_02197d80(self);
    s16 kind;
    self->state = 0;
    kind = self->kind;
    if (self->mode == 0) {
        if (kind == 1 || kind == 2 || (u16)(s16)(kind - 5) <= 1) {
            self->state = 1;
        }
    } else if ((u16)(s16)(kind - 3) <= 3) {
        self->state = 1;
    }
    self->anim = NULL;
}

BOOL func_ov003_021eecb0(Ov003Bridge *self) {
    BOOL r = func_ov000_02194c08(self);
    if (r && self->anim != NULL) {
        func_ov000_021903b4(self->anim);
    }
    return r;
}

void func_ov003_021eecd8(Ov003Bridge *self) {
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(self->unk_24));
    }
    if (self->anim != NULL) {
        func_ov000_02190a80(self->anim, func_0203db40(self->unk_24));
    }
}

void func_ov003_021eed24(Ov003Bridge *self) {
    const char *name;
    func_ov000_02194758(self);
    if (self->state != 0) {
        void *res;
        s32 i;
        name = data_ov003_021f9fd6;
        self->unk_cc_0 = 0;
        if (self->ctl == NULL) {
            Ov003BrCtl *c = (Ov003BrCtl *)func_0203dd9c(0x9c);
            if (c != NULL) {
                c = func_ov000_021985e8(c);
            }
            self->ctl = c;
            func_ov000_02198c8c(c, self->unk_0c);
            self->ctl->unk_28 = 0x10;
            self->ctl->unk_38 = self->unk_64;
            self->ctl->unk_60 = self->unk_6c;
            c = self->ctl;
            c->enable = 1;
            c->visible = 1;
            func_0203f324(c);
            c = self->ctl;
            c->unk_9a_1 = 0;
            c->unk_9a_4 = 0;
        }
        for (i = 0; i < 2; i++) {
            res = self->res[i];
            if (res != NULL) {
                break;
            }
        }
        if (res != NULL) {
            Ov003BrAnim *a = (Ov003BrAnim *)func_0203dd9c(0xe8);
            if (a != NULL) {
                a = func_ov000_0218fe1c(a);
            }
            self->anim = a;
            func_ov000_0218ffdc(a, res, 0, 1);
            { Ov003Vec v; v.x = self->pos.x; v.y = self->pos.y; v.z = self->pos.z; v.y += self->height << 4; self->anim->pos = v; }
            func_ov000_02190758(self->anim, self->rot, 0);
        }
        func_ov000_02198360(self->work, 1, 1);
        self->work->state = 10;
    } else {
        name = data_ov003_021f9fd0;
    }
    if (self->model != NULL) {
        func_ov000_02190cb0(self->model, name, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x4cd);
    }
}

}
