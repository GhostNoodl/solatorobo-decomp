#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003SwVec;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003SwSub44;

typedef struct {
    u8 unk_00[2];
    u8 unk_02;
    u8 unk_03[3];
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u8 unk_0c[0x10];
    u16 unk_1c;
} Ov003SwPart;

typedef struct {
    u16 state;
    u16 timer;
    s32 unk_04;
    s32 unk_08;
} Ov003SwWork;

typedef struct {
    u8 unk_00;
    u8 unk_01;
} Ov003SwInfo;

typedef struct {
    u8 unk_00[0x111];
    u8 unk_111_0 : 2;
    u8 unk_111_2 : 1;
    s16 unk_112;
} Ov003SwAnim;

class Ov003Switch {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
    u8 unk_04[0x8];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    u8 unk_1e[0x1a];
    void *model;
    u8 unk_3c[4];
    Ov003SwWork *work;
    Ov003SwSub44 *unk_44;
    u8 unk_48[4];
    Ov003SwPart *unk_4c;
    u8 unk_50[8];
    void *unk_58;
    u8 unk_5c[0x14];
    Ov003SwVec pos;
    u8 unk_7c[0x17];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x1c];
    Ov003SwInfo *unk_b0;
    u8 unk_b4[0x18];
    u16 unk_cc_0 : 1;
    u16 unk_ce;
};

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0x5a];
    Ov003SwVec pos;
    u8 unk_7c[0xaac];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
} Ov003SwPlayer;

extern "C" {

extern void *data_02097e4c;
extern char data_ov003_021f803c[];
extern char data_ov003_021f8041[];
extern char data_ov003_021f8046[];
extern char data_ov003_021f804b[];
extern void *func_02049f44(void *mgr, s32 id, Ov003SwVec *pos, s32 a);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 v);
extern BOOL func_ov000_02191120(void *model);
extern Ov003SwAnim *func_ov000_02190a30(void *model, s32 n);
extern void func_0203f8d8(void *p);
extern void func_0203f920(void *p);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov003SwPart *func_ov000_02199ba0(Ov003SwPart *p);
extern void func_ov000_0218d398(Ov003SwPart *p, u16 id, s32 a, s32 b, s32 c, s32 d);
extern s32 func_ov003_021f093c(Ov003SwPart *p);
extern BOOL func_ov000_02198360(Ov003SwWork *w, s32 a, s32 b);
extern BOOL func_ov003_021f0abc(Ov003SwPart *p, s32 a);
extern void *func_ov000_02191318(void *model, s32 a);
extern Ov003SwPlayer *func_ov000_0219bf90(void);
extern s32 VEC_Distance(const Ov003SwVec *a, const Ov003SwVec *b);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_020627b4(void);
extern s32 func_0205b1fc(void);

static inline void Ov003SwWork_Clear(Ov003SwWork *w) {
    w->unk_04 = 0;
    w->unk_08 = 0;
}

static inline void Ov003SwSub44_Set(Ov003SwSub44 *p) {
    p->unk_22_0 = 1;
    p->unk_22_1 = 1;
}

static inline void Ov003SwSub44_Clear(Ov003SwSub44 *p) {
    p->unk_22_0 = 0;
    p->unk_22_1 = 0;
}

static inline void Ov003Sw_Anim2(Ov003Switch *self) {
    Ov003SwAnim *a = func_ov000_02190a30(self->model, 2);
    if (a != NULL) {
        a->unk_111_2 = 1;
        a->unk_112 = 0x800;
    }
}

static inline void Ov003Sw_Play(Ov003Switch *self, const char *name, s32 slow) {
    if (self->model != NULL) {
        u8 k = self->unk_b0->unk_01;
        s32 speed = 0x1000;
        s32 frame = 0x1000;
        if (k != 1 && k != 2) {
            speed = slow;
        }
        if (k != 2) {
            frame = 0x800;
        }
        func_ov000_02190cb0(self->model, name, speed, 0);
        func_ov000_021911c8(self->model, frame);
        Ov003Sw_Anim2(self);
    }
}

static inline void Ov003Sw_On(Ov003Switch *self) {
    self->unk_cc_0 = 1;
    if (self->unk_58 != NULL) {
        func_0203f8d8(self->unk_58);
    }
}

static inline void Ov003Sw_Next(Ov003Switch *self) {
    self->work->timer = 0;
    self->work->state++;
}

static inline void Ov003Sw_Sound(Ov003Switch *self) {
    if (self->unk_b0->unk_01 == 3) {
        func_ov000_0218996c(7, 0x14);
        func_02049f44(data_02097e4c, 0x47, &self->pos, 0);
    }
}

void func_ov003_021dcf20(Ov003Switch *self) {
    s32 next;
    s32 res;
    u16 snd;
    s16 m;
    Ov003SwPlayer *pl;
    res = 0;
    next = 0;
    switch (self->unk_1a) {
    case 0:
    case 5:
        break;
    case 3:
        if (self->unk_ce != 0) {
            self->unk_ce--;
        } else {
            res = func_ov003_021f093c(self->unk_4c);
        }
        snd = 0xffff;
        switch (res) {
        case 3:
        case 4:
            if (self->unk_18 != 2) {
                snd = self->unk_4c->unk_08;
                next = 20;
            }
            break;
        case 1:
            if (self->unk_18 != 3) {
                snd = self->unk_4c->unk_08;
                next = 40;
            }
            break;
        case 2:
            if (self->unk_18 != 1) {
                snd = self->unk_4c->unk_08;
                next = 30;
            }
            break;
        }
        if (snd != 0xffff) {
            func_02049f44(data_02097e4c, snd, &self->pos, 0);
        }
        break;
    case 4:
    case 8:
        if (self->unk_ce != 0) {
            self->unk_ce--;
        } else {
            res = func_ov003_021f093c(self->unk_4c);
        }
        snd = 0xffff;
        switch (res) {
        case 3:
        case 4:
            if (self->unk_18 == 3) {
                self->unk_ce = 10;
                snd = self->unk_4c->unk_08;
                next = 20;
                if (self->unk_1a == 8) {
                    self->unk_1a = 0;
                }
            } else if (self->unk_18 == 2) {
                self->unk_ce = 10;
                snd = self->unk_4c->unk_08;
                next = 40;
            }
            break;
        }
        if (snd != 0xffff) {
            func_02049f44(data_02097e4c, snd, &self->pos, 0);
        }
        break;
    case 2:
    case 7:
        if (func_ov003_021f0abc(self->unk_4c, res)) {
            if (self->unk_1a == 7) {
                if (self->unk_18 != 2) {
                    self->unk_1a = 0;
                    next = 20;
                }
                break;
            }
            if (self->unk_18 != 0) {
                next = 10;
            }
            if (self->unk_44 != NULL) {
                Ov003SwSub44_Set(self->unk_44);
            }
        } else {
            if (self->unk_18 != 3) {
                next = 40;
            }
            if (self->unk_44 != NULL) {
                Ov003SwSub44_Clear(self->unk_44);
            }
        }
        break;
    case 10:
        if (func_ov003_021f0abc(self->unk_4c, res)) {
            if (self->unk_18 == 3) {
                next = 10;
                func_ov000_02190cb0(self->model, data_ov003_021f8046, 0x1000, 0);
                func_ov000_02191318(self->model, -1);
            }
        } else {
            if (self->unk_18 != 3) {
                next = 40;
            }
            break;
        }
    case 6:
    case 9: {
        s32 dist = 0xa000;
        Ov003SwPlayer *pl;
        if (self->unk_1c != 0) {
            dist = self->unk_1c << 4;
        }
        pl = func_ov000_0219bf90();
        if (pl != NULL) {
            BOOL neg = FALSE;
            if (dist < 0) {
                dist = -dist;
                neg = TRUE;
            }
            if (VEC_Distance(&pl->pos, &self->pos) <= dist) {
                if (neg) {
                    res = 2;
                } else {
                    res = 3;
                }
            } else if (neg) {
                res = 3;
            } else {
                res = 2;
            }
        }
        snd = 0xffff;
        switch (res) {
        case 3:
            if (self->unk_18 != 2) {
                snd = self->unk_4c->unk_08;
                next = 20;
                if (self->unk_1a == 9) {
                    self->unk_1a = 0;
                }
            }
            break;
        case 2:
            if (self->unk_18 != 0) {
                snd = self->unk_4c->unk_08;
                next = 10;
                if (self->unk_1a == 9) {
                    self->unk_1a = 0;
                }
            }
            break;
        }
        if (snd != 0xffff) {
            func_02049f44(data_02097e4c, snd, &self->pos, 0);
        }
        break;
    }
    case 1:
        if (self->unk_93_1 != self->unk_18) {
            snd = 0xffff;
            switch (self->unk_18) {
            case 3:
                Ov003SwWork_Clear(self->work);
                func_ov000_02198360(self->work, 1, 0);
                self->work->state = 40;
                snd = self->unk_4c->unk_06;
                break;
            case 0:
                Ov003SwWork_Clear(self->work);
                func_ov000_02198360(self->work, 1, 0);
                self->work->state = 10;
                snd = self->unk_4c->unk_06;
                break;
            case 2:
                Ov003SwWork_Clear(self->work);
                func_ov000_02198360(self->work, 1, 0);
                self->work->state = 20;
                snd = self->unk_4c->unk_06;
                if (self->unk_44 != NULL) {
                    Ov003SwSub44_Clear(self->unk_44);
                }
                break;
            }
            if (snd != 0xffff) {
                func_02049f44(data_02097e4c, snd, &self->pos, 0);
            }
            func_ov000_02197dec(self, self->unk_18, -1);
            self->unk_93_1 = (u8)(u16)self->unk_18;
        }
        break;
    }
    if (next != 0) {
        switch (next) {
        case 20:
            self->work->state = 20;
            self->unk_18 = 2;
            break;
        case 10:
            self->work->state = 10;
            self->unk_18 = 0;
            break;
        case 30:
            self->work->state = 30;
            self->unk_18 = 1;
            break;
        case 40:
            self->work->state = 40;
            self->unk_18 = 3;
            break;
        }
        m = self->unk_18;
        func_020627b4();
        func_ov000_02197dec(self, m, m);
        if (func_0205b1fc() == 1) {
            pl = func_ov000_0219bf90();
            if (pl != NULL && pl->unk_b28_0 == 0) {
                pl->unk_15 = 3;
                pl->unk_b28_0 = 0;
                pl->unk_b28_2 = 1;
            }
        }
        self->unk_93_1 = (u8)(u16)m;
    }
}

void func_ov003_021dd478(Ov003Switch *self) {
    Ov003SwWork *w = self->work;
    switch (w->state) {
    case 0:
        return;
    case 10:
        Ov003Sw_Play(self, data_ov003_021f8046, 0xcd);
        Ov003Sw_On(self);
        Ov003Sw_Next(self);
        break;
    case 11:
        if (self->model != NULL) {
            w->timer++;
            if (w->timer < 0x14) {
                return;
            }
            if (!func_ov000_02191120(self->model)) {
                return;
            }
        }
        if (self->unk_44 != NULL) {
            Ov003SwSub44_Set(self->unk_44);
        }
        Ov003Sw_Sound(self);
        self->work->state = 0x32;
        break;
    case 40:
        if (self->model != NULL) {
            u8 k = self->unk_b0->unk_01;
            s32 speed = 0x1000;
            s32 frame = 0x1000;
            if (k != 1 && k != 2) {
                speed = 0xcd;
            }
            if (k != 2) {
                frame = 0x800;
            }
            func_ov000_02190cb0(self->model, data_ov003_021f8046, speed, 0);
            func_ov000_02190cb0(self->model, data_ov003_021f804b, 0xcd, 0);
            func_ov000_021911c8(self->model, frame);
            Ov003Sw_Anim2(self);
        }
        Ov003Sw_On(self);
        Ov003Sw_Next(self);
        break;
    case 41:
        if (self->model != NULL) {
            w->timer++;
            if (w->timer < 0x14) {
                return;
            }
            if (!func_ov000_02191120(self->model)) {
                return;
            }
        }
        Ov003Sw_Sound(self);
        self->work->state = 0x32;
        break;
    case 20:
        Ov003Sw_Play(self, data_ov003_021f803c, 0x89);
        Ov003Sw_Next(self);
        break;
    case 21:
        if (self->model != NULL) {
            w->timer++;
            if (w->timer < 0x1e) {
                return;
            }
            if (!func_ov000_02191120(self->model)) {
                return;
            }
        }
        self->unk_cc_0 = 0;
        if (self->unk_58 != NULL) {
            func_0203f920(self->unk_58);
        }
        if (self->unk_44 != NULL) {
            Ov003SwSub44_Clear(self->unk_44);
        }
        Ov003Sw_Sound(self);
        self->work->state = 0x32;
        break;
    case 30:
        Ov003Sw_Play(self, data_ov003_021f8041, 0x89);
        Ov003Sw_On(self);
        Ov003Sw_Next(self);
        break;
    case 31:
        if (self->model != NULL) {
            w->timer++;
            if (w->timer < 0x1e) {
                return;
            }
            if (!func_ov000_02191120(self->model)) {
                return;
            }
        }
        if (self->unk_44 != NULL) {
            Ov003SwSub44_Set(self->unk_44);
        }
        self->work->state = 0x32;
        break;
    case 50:
        if (self->unk_4c->unk_02 != 6) {
            Ov003SwPart *p = func_ov000_02199ba0(self->unk_4c);
            if (p != NULL) {
                func_ov000_0218d398(p, self->unk_0c, 3, 1, 0, 0);
            }
            self->unk_4c->unk_1c = 0xffff;
        }
        break;
    }
}

}
