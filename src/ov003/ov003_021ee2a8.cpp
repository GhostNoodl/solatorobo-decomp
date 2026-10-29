#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov003Work {
    u16 state;
    u16 timer;
};

struct Ov003Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
};

struct Ov003SwPart {
    u8 unk_00[0x1c];
    u16 unk_1c;
    u8 unk_1e[4];
    u16 enable : 1;
    u16 visible : 1;
};

struct Ov003SwCfg {
    u8 unk_00;
    u8 type;
};

struct Ov003LvPlayer {
    u8 unk_00[0x64];
    s32 radius;
    u8 unk_68[8];
    Ov003Vec pos;
};

class Ov003LvEffect {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
};

struct Ov003Lever {
    void *vtbl;
    u8 unk_04[8];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 kind;
    s16 mode;
    s16 sound;
    u8 unk_1e[0x1a];
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    Ov003SwPart *part;
    u8 unk_48[4];
    void *link;
    u8 unk_50[0x20];
    Ov003Vec pos;
    u8 unk_7c[0x17];
    u8 unk_93_0 : 1;
    u8 state : 3;
    u8 unk_94[0x1c];
    Ov003SwCfg *cfg;
    u8 unk_b4[0x1a];
    u16 count;
};

extern "C" {

extern void *data_02097e4c;
extern Ov003Game54 *data_ov000_021ccd54;
extern char data_ov003_021f9fd6[];
extern char data_ov003_021f9fd0[];
extern void func_ov000_02194758(void *self);
extern void func_ov000_02197d80(void *self);
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern void *func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_020627b4(void);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void *func_ov000_02199ba0(void *p);
extern void func_ov000_0218d398(void *p, u16 a, s32 b, s32 c, s32 d, s32 e);
extern BOOL func_ov000_02191120(void *p);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003LvPlayer *func_ov000_0219bf90(void);
extern BOOL func_01ffc198(Ov003Vec *a, Ov003Vec *b, s32 r);
extern Ov003LvEffect *func_02065f88(s32 id, const Ov003Vec *pos);
extern s32 func_02040498(s32 max);
extern BOOL func_ov000_0219aae8(void *a, void *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k);

void func_ov003_021ee680(Ov003Lever *self, s16 kind, BOOL notify, s32 sound);

void func_ov003_021ee2a8(Ov003Lever *self) {
    func_ov000_02194758(self);
    func_ov000_02197d80(self);
    func_ov003_021ee680(self, self->kind, 0, -1);
    if (self->kind == 1 && self->mode != 0) {
        Ov003SwPart *p = self->part;
        p->enable = 0;
        p->visible = 0;
    }
    self->count = 0;
}

void func_ov003_021ee310(Ov003Lever *self) {
    Ov003Work *w = self->work;
    switch (w->state) {
    case 0:
        func_ov000_02197d80(self);
        if (self->kind == 1) {
            self->state = 1;
            if (self->cfg->type != 1) {
                return;
            }
            self->work->timer = 2;
            self->work->state++;
        } else if (self->kind == 0) {
            self->state = 0;
        }
        break;
    case 1:
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        func_ov003_021ee680(self, 0, 1, -1);
        self->work->state--;
        break;
    }
}

static inline BOOL Ov003Game_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game_IsIdle(Ov003Game54 *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return true;
}

static inline BOOL Ov003Work_Tick(Ov003Work *w) {
    if (w->timer != 0) {
        w->timer--;
    }
    return w->timer == 0;
}

void func_ov003_021ee3dc(Ov003Lever *self) {
    void *sp = func_ov000_02199ba0(self->link);
    Ov003Work *w = self->work;
    switch (w->state) {
    case 0: {
        s32 snd = 0x18;
        if (self->sound != 0) {
            self->count = 2;
            snd = 0x84;
        }
        if (self->kind == 0) {
            func_ov003_021ee680(self, 1, 1, snd);
        } else {
            func_ov003_021ee680(self, 0, 1, snd);
        }
        self->work->timer = 2;
        self->work->state++;
        break;
    }
    case 1:
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        if (self->cfg->type != 1) {
            self->work->timer = 0x78;
        } else {
            func_ov003_021ee680(self, 0, 1, -1);
            self->work->timer = 0x3c;
        }
        self->work->state++;
        break;
    case 2:
        if (self->sound != 0 && self->count < 0x41) {
            if (!(self->count & 0x1f)) {
                func_02049f44(data_02097e4c, 0x84, &self->pos, 0);
            }
            self->count++;
        }
        if (!Ov003_GameIdle()) {
            return;
        }
        w = self->work;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        if (self->model != NULL && !func_ov000_02191120(self->model)) {
            return;
        }
        if (sp != NULL) {
            func_ov000_0218d398(sp, self->unk_0c, 3, 1, 0, 0);
        }
        ((Ov003SwPart *)self->link)->unk_1c = 0xffff;
        if (self->mode != 0 && self->kind == 1) {
            Ov003SwPart *p;
            self->work->state = 10;
            p = self->part;
            p->enable = 0;
            p->visible = 0;
        } else {
            func_ov000_02198360(self->work, 1, 0);
        }
        break;
    case 10:
        break;
    }
}

void func_ov003_021ee680(Ov003Lever *self, s16 kind, BOOL notify, s32 sound) {
    const char *name;
    if (kind == 1) {
        self->state = 1;
        name = data_ov003_021f9fd6;
    } else {
        self->state = 0;
        name = data_ov003_021f9fd0;
    }
    if (self->model != NULL && name != NULL) {
        func_ov000_02190cb0(self->model, name, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x4cd);
    }
    if (sound >= 0) {
        func_02049f44(data_02097e4c, sound, &self->pos, 0);
    }
    self->kind = kind;
    if (notify) {
        s16 k = self->kind;
        func_020627b4();
        func_ov000_02197dec(self, k, k);
    }
}

void func_ov003_021ee73c(Ov003Lever *self) {
    Ov003Work *w;
    if (self->kind == 1) {
        Ov003SwPart *p;
        self->state = 1;
        p = self->part;
        p->enable = 0;
        p->visible = 0;
        return;
    }
    self->state = 0;
    w = self->work;
    switch (w->state) {
    case 0:
        if (!(w->timer & 0x7f)) {
            Ov003LvPlayer *pl = func_ov000_0219bf90();
            if (pl != NULL && func_01ffc198(&pl->pos, &self->pos, pl->radius + 0xf000)) {
                Ov003LvEffect *e = func_02065f88(0x322, &self->pos);
                e->SetScale(0xe66, 0xe66, 0xe66);
                func_02049f44(data_02097e4c, func_02040498(1) + 0x79, &self->pos, 0);
                self->work->state++;
                self->work->timer = 0;
                return;
            }
        }
        self->work->timer++;
        break;
    case 1:
        w->timer++;
        w = self->work;
        if (w->timer < 0x37) {
            func_ov000_0219aae8(self, self, 0x32, 0x20, 2, 0, 0, 0x1800, 0, 0x322, 0x800);
            return;
        }
        if (w->timer >= 0x87 - (self->mode << 4)) {
            w->state--;
            self->work->timer = 0;
        }
        break;
    }
}

void func_ov003_021ee910(Ov003Lever *self) {
    Ov003Work *w = self->work;
    switch (w->state) {
    case 0: {
        s16 k;
        Ov003SwPart *p;
        self->kind = 1;
        k = self->kind;
        self->state = 1;
        func_020627b4();
        func_ov000_02197dec(self, k, k);
        p = self->part;
        p->enable = 0;
        p->visible = 0;
        func_02049f44(data_02097e4c, 0x6e, &self->pos, 0);
        self->work->timer = 0x78;
        self->work->state++;
        break;
    }
    case 1: {
        void *sp;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        sp = func_ov000_02199ba0(self->link);
        if (sp != NULL) {
            func_ov000_0218d398(sp, self->unk_0c, 3, 1, 0, 0);
        }
        if (!Ov003_GameIdle()) {
            self->work->state++;
            return;
        }
        func_ov000_02198360(self->work, 0x15, 0);
        break;
    }
    case 2:
        if (!Ov003_GameIdle()) {
            return;
        }
        func_ov000_02198360(w, 0x15, 0);
        break;
    }
}
}
