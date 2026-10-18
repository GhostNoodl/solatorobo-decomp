#include "ov011/ov011.h"

struct Ov011Fade {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
    u8 pad[0xb];
    s32 cur;
    s32 to;
    s32 step;
};

struct Ov011Tut {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
    Ov011Fade *fade;
    u16 state;
    u16 timer;
    u64 flags;
};

struct Ov011Arg2 {
    s32 a;
    s32 b;
    s32 c;
};

static inline void Ov011Fade_Start(Ov011Fade *f, s32 to, s32 frames) {
    s32 c = f->cur;
    if (f->b0) {
        f->b2 = 1;
        Ov011_SetLerp(&f->cur, c, to, frames);
    }
}

static inline void Ov011Fade_Run(Ov011Fade *f, s32 to, s32 frames) {
    if (f->b0) {
        Ov011Fade_Start(f, to, frames);
    }
}

static inline BOOL Ov011Fade_Done4(Ov011Fade *f) {
    BOOL r = FALSE;
    if (f->b0) {
        r = !f->b4;
    }
    return r;
}

static inline BOOL Ov011Fade_Done2(Ov011Fade *f) {
    BOOL r = FALSE;
    if (f->b0) {
        r = !f->b2;
    }
    return r;
}

static inline BOOL Ov011Fade_Done3(Ov011Fade *f) {
    BOOL r = FALSE;
    if (f->b0) {
        r = !f->b3;
    }
    return r;
}

static inline BOOL Ov011Fade_AllDone(Ov011Fade *f) {
    if (!Ov011Fade_Done4(f)) {
        return FALSE;
    }
    if (!Ov011Fade_Done2(f)) {
        return FALSE;
    }
    if (!Ov011Fade_Done3(f)) {
        return FALSE;
    }
    return TRUE;
}

extern "C" {

void func_ov000_0219bdb0(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);

static inline void Ov011_Msg(u16 id, s32 a, s32 b) {
    Ov011Arg2 arg;
    arg.a = a;
    arg.b = b;
    func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &arg);
}

#pragma force_active on
void func_ov011_021fcb84(Ov011Tut *self) {
    switch (self->state) {
    case 0: {
        Ov011_Msg(self->id, 1, 1);
        Ov011Fade_Run(self->fade, 0x3800, 20);
        self->state = 1;
        break;
    }
    case 1:
        self->timer++;
        if (Ov011Fade_AllDone(self->fade) && self->timer >= 0x50) {
            self->flags |= 0x10;
        }
        break;
    }
}

struct Ov011ArgA {
    s32 kind;
    u8 b;
    u8 pad[7];
};

struct Ov011ArgB {
    s32 kind;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    s16 x;
    s16 y;
    u8 pad2[2];
};

static inline void Ov011_SendA(u16 id, s32 kind, u8 v) {
    Ov011ArgA a;
    a.kind = kind;
    a.b = v;
    func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &a);
}

static inline void Ov011_SendB(u16 id, s32 kind, s16 x, s16 y) {
    Ov011ArgB b;
    b.kind = kind;
    b.b0 = 0;
    b.b1 = 0;
    b.x = x;
    b.y = y;
    func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &b);
}

void func_ov011_021fcd00(Ov011Tut *self) {
    switch (self->state) {
    case 0:
        Ov011_SendA(self->id, 3, 1);
        Ov011_SendB(self->id, 2, 0, 0x1000);
        self->state = 1;
        break;
    case 1:
        self->timer++;
        if (self->timer >= 0x79) {
            self->timer = 0;
            Ov011_SendA(self->id, 3, 0);
            self->flags |= 0x20;
        }
        break;
    }
}
#pragma force_active reset
}
