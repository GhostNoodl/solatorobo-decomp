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
    s32 cur3;
    s32 to3;
    s32 step3;
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

static inline void Ov011Fade_Start3(Ov011Fade *f, s32 to, s32 frames) {
    u16 c = f->cur3;
    if (f->b0) {
        f->b3 = 1;
        Ov011_SetLerp(&f->cur3, c, to, frames);
    }
}

static inline void Ov011Fade_Run3(Ov011Fade *f, int to, s32 frames) {
    if (f->b0) {
        Ov011Fade_Start3(f, to, frames);
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

extern void *data_02097e4c;
extern void *func_02049f44(void *a, s32 b, Ov011Vec *c, s32 d);

#pragma force_active on
void func_ov011_021fc94c(Ov011Tut *self) {
    self->timer++;
    switch (self->state) {
    case 0:
        Ov011Fade_Run(self->fade, 0x1e66, 40);
        Ov011_SendB(self->id, 2, 0x1000, 0x1000);
        Ov011_Msg(self->id, 1, 0);
        self->state = 1;
        break;
    case 1:
        if (Ov011Fade_AllDone(self->fade) && self->timer > 50) {
            void *a;
            self->timer = 0;
            self->flags |= 8;
            a = Ov011_FindActor(self->id);
            if (a != NULL) {
                Ov011Vec pos;
                pos.x = FLD(s32, a, 0x70);
                pos.y = FLD(s32, a, 0x74);
                pos.z = FLD(s32, a, 0x78);
                func_02049f44(data_02097e4c, 0x5b, &pos, 0);
            }
        }
        break;
    }
}


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
extern Ov011V *func_02065f88(s32 id, const Ov011Vec *pos);

static inline void Ov011_SendC(u16 id, s32 kind, BOOL b0) {
    Ov011ArgB b;
    b.kind = kind;
    b.b0 = b0;
    b.b1 = 0;
    b.x = 0;
    b.y = 0x1000;
    func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &b);
}

static inline s32 Ov011_HpRatio(u16 id) {
    s32 r = 0;
    void *a = Ov011_FindActor(id);
    if (a != NULL) {
        u16 *hp = FLD(u16 *, a, 0x50);
        r = (hp[0] << 12) / hp[1];
    }
    return r;
}

void func_ov011_021fce2c(Ov011Tut *self) {
    self->timer++;
    switch (self->state) {
    case 0:
        Ov011Fade_Run3(self->fade, 0x38e, 10);
        Ov011_Msg(self->id, 1, 2);
        self->state = 1;
        break;
    case 1:
        self->state = 2;
        break;
    case 2: {
        s32 r = Ov011_HpRatio(self->id);
        s32 t = 0;
        if (r <= 0x554) {
            t = 300;
        } else if (r <= 0x554 * 2) {
            t = 0xb4;
        }
        Ov011Fade_Run3(self->fade, (u16)(t + 100), 0x8c);
        Ov011Fade_Run(self->fade, 0x8800, 0x8c);
        self->state = 3;
        break;
    }
    case 3:
        if (self->timer >= 0x8c) {
            self->state = 4;
        }
        break;
    case 4: {
        s32 r = Ov011_HpRatio(self->id);
        s32 t = 0;
        if (r <= 0x554) {
            t = 300;
        } else if (r <= 0x554 * 2) {
            t = 0xb4;
        }
        Ov011Fade_Run3(self->fade, t, 0x50);
        self->state = 5;
        break;
    }
    case 5:
        if (self->timer >= 0xdc) {
            self->state = 6;
        }
        break;
    case 6: {
        void *a;
        Ov011_SendC(self->id, 2, 1);
        self->state = 7;
        if (Ov011_HpRatio(self->id) < 0x554) {
            self->timer += 0x78;
        }
        a = Ov011_FindActor(self->id);
        if (a != NULL) {
            Ov011Vec v;
            v.x = FLD(s32, a, 0x70);
            v.y = FLD(s32, a, 0x74);
            v.z = FLD(s32, a, 0x78);
            func_02065f88(0x12e, &v)->v14(0x1400, 0x600, 0x1400);
        }
        break;
    }
    case 7:
        if (self->timer >= 0x1a4) {
            self->state = 8;
        }
        break;
    case 8:
        Ov011Fade_Run3(self->fade, 300, 5);
        Ov011_SendC(self->id, 2, 0);
        self->state = 9;
        break;
    case 9:
        if (self->timer >= 0x1d1) {
            self->state = 10;
        }
        break;
    case 10:
        Ov011Fade_Run3(self->fade, 0x71c, 0x5a);
        self->state = 11;
        break;
    case 11:
        if (self->timer >= 0x22b) {
            self->state = 12;
        }
        break;
    case 12:
        Ov011Fade_Run(self->fade, 0x3333, 15);
        self->state = 13;
        break;
    case 13:
        if (self->timer >= 0x23a) {
            self->state = 14;
        }
        break;
    case 14:
        if (self->timer >= 0x258) {
            self->flags |= 0x40;
        }
        break;
    }
}
#pragma force_active reset
}
