#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003HtVec;

typedef struct {
    u16 state;
    u16 timer;
    u64 flags;
} Ov003HtWork;

typedef struct {
    u8 unk_00[0x44];
    s32 unk_44;
    u8 unk_48[8];
    u32 flags;
    u32 unk_54;
    s32 unk_58;
    u8 unk_5c[0x28];
    s32 unk_84;
    u8 unk_88[0x12];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
} Ov003HtCtl;

typedef struct {
    u8 unk_00[0xc];
    u16 id;
    u8 unk_0e[0x3a];
    Ov003HtCtl *ctl;
    s32 *unk_4c;
    s32 *unk_50;
} Ov003HtActor;

typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
    s32 unk_14;
} Ov003HtSlot;

typedef struct {
    u8 type;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[6];
    u16 unk_0a;
    u8 unk_0c[0xd];
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
    u16 unk_1c;
} Ov003HtTarget;

typedef struct {
    u16 unk_00;
} Ov003HtCounter;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003HtS44;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c_0 : 5;
} Ov003HtB0;

class Ov003HtFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(s32 a);
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void SetRot(s32 x, u16 y, s32 z);
    u8 unk_04[0x38];
    s32 unk_3c;
};

typedef struct {
    u16 val;
    u8 kind;
    u16 id;
} Ov003HtMsg;

typedef struct {
    u8 unk_00[0xc];
    u16 id;
    u8 unk_0e[0x2a];
    void *model;
    u8 unk_3c[4];
    Ov003HtWork *work;
    Ov003HtS44 *unk_44;
    Ov003HtCtl *ctl;
    Ov003HtTarget *unk_4c;
    Ov003HtCounter *unk_50;
    u8 unk_54[0x10];
    s32 unk_64;
    u8 unk_68[4];
    s32 unk_6c;
    s32 pos[3];
    u8 unk_7c[2];
    u16 unk_7e;
    u8 unk_80[0x18];
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[4];
    Ov003HtB0 *unk_b0;
} Ov003Ht;

extern "C" {

extern void *data_02097e4c;
extern const char data_ov003_021f7a85[];
extern const char data_ov003_021f7a8b[];
void func_0203f324(Ov003HtCtl *ctl);
void func_0203f364(Ov003HtCtl *ctl);
void func_02049f44(void *mgr, s32 id, void *pos, s32 a);
Ov003HtFx *func_02065f88(s32 id, void *pos);
void func_ov000_0218996c(u8 a, u8 b);
void func_ov000_0218d398(Ov003Ht *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218dbe0(Ov003Ht *self, s32 a);
BOOL func_ov000_02190cb0(void *model, const char *name, s16 blend, u8 force);
BOOL func_ov000_02191120(void *model);
void func_ov000_021915a0(void *model);
void func_ov000_02198360(Ov003HtWork *w, s32 a, s32 b);
void func_ov000_021987b8(Ov003HtCtl *ctl, s32 a, s32 b, s32 c);
u16 func_ov000_02198da8(Ov003HtCtl *ctl, u16 angle);
Ov003HtActor *func_ov000_02199ba0(Ov003HtTarget *t);
u16 func_ov000_02199e94(Ov003HtTarget *t);
u32 func_ov000_02199f08(Ov003HtTarget *t);
void func_ov000_02199f48(Ov003HtCounter *t, Ov003HtActor *a);
u16 func_ov000_0219a874(Ov003HtCounter *a, Ov003HtSlot *b, s32 value);
BOOL func_ov000_0219aae8(Ov003Ht *a, Ov003HtActor *b, u16 c, u8 d, u16 mask, Ov003HtVec *ofs, void *rot, s32 r, s32 rr, s16 h, s32 i);
u8 func_ov003_021cee68(void);

void func_ov003_021d3d28(Ov003Ht *self) {
    BOOL hit;
    u16 c;
    s32 h;
    Ov003HtActor *tgt;
    Ov003HtSlot *slot;
    switch (self->work->state) {
    case 0: {
        Ov003HtCtl *ctl = self->ctl;
        Ov003HtS44 *s;
        ctl->unk_9a_0 = 1;
        ctl->unk_9a_3 = 1;
        func_0203f324(ctl);
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = 1;
            s->unk_22_1 = 1;
        }
        self->work->state++;
        if (self->unk_a8 == 0) {
            self->unk_a8 = 0x52;
        }
    }
    case 1: {
        if (self->unk_a0 > 0 && (self->ctl->flags & 0x80000000)) {
            self->unk_a0 = -0xcd;
        }
        if (self->unk_4c == NULL) {
            break;
        }
        tgt = func_ov000_02199ba0(self->unk_4c);
        if (tgt != NULL && self->unk_4c->unk_01 == 1) {
            Ov003HtCtl *ctl = self->ctl;
            if ((ctl->flags & 0x60000000) || ctl->unk_58 != 0) {
                slot = (Ov003HtSlot *)tgt->unk_50;
                hit = FALSE;
                c = func_ov000_02199e94(self->unk_4c);
                switch (self->unk_b0->unk_0c_0) {
                case 3:
                    if (self->unk_4c->unk_19 < 2) {
                        Ov003HtTarget *t;
                        c = 0;
                        func_02049f44(data_02097e4c, 0x66, self->pos, 0);
                        t = self->unk_4c;
                        t->unk_19 = 0;
                        t->unk_1b = 0;
                    }
                    break;
                case 4:
                    u8 n = func_ov003_021cee68();
                    if (self->unk_4c->unk_1a < n) {
                        c = 0;
                    }
                    break;
                }
                h = 100;
                if (self->ctl->flags & 0x20000000) {
                    Ov003HtFx *fx = func_02065f88(0x67, self->pos);
                    s32 r;
                    fx->SetRot(0, self->unk_7e + 0x8000, 0);
                    r = self->unk_64;
                    if (self->unk_4c->unk_19 != 0) {
                        s32 t = r + ((r >> 1) + 0x333);
                        fx->SetScale(t, t * 2, t);
                        fx->unk_3c = 0xc00;
                        fx = func_02065f88(0x57b, self->pos);
                        fx->SetScale(0x159a, 0x159a, 0x159a);
                    } else {
                        fx->SetScale(r + ((r >> 2) + 0x333), r + ((r >> 2) + 0x333), r + ((r >> 2) + 0x333));
                        fx->unk_3c = 0x2000;
                    }
                } else {
                    h = -1;
                    if (self->unk_4c->unk_19 != 0) {
                        Ov003HtFx *fx = func_02065f88(0x65, self->pos);
                        fx->SetRot(0x1800, self->unk_7e + 0x8000, 0);
                    } else {
                        Ov003HtFx *fx = func_02065f88(0x64, self->pos);
                        fx->SetScale(0xccd, 0xccd, 0xccd);
                    }
                }
                if (self->unk_4c->unk_19 != 0) {
                    s32 n = self->unk_4c->unk_1a + 1;
                    func_ov000_0218996c(n + 8, n * 2 + 0x14);
                    func_02049f44(data_02097e4c, 0x1a, self->pos, 0);
                } else {
                    func_ov000_0218996c(6, 10);
                    func_02049f44(data_02097e4c, 0x17, self->pos, 0);
                }
                if (self->unk_4c->unk_03 == 1) {
                    Ov003HtVec ofs;
                    s32 r = self->unk_64;
                    u8 d;
                    if (r < 0xccd) {
                        r = 0xccd;
                    }
                    r += 0xccd;
                    ofs.y = self->unk_6c;
                    ofs.x = 0;
                    ofs.z = 0;
                    d = self->unk_4c->unk_0a;
                    if (slot != NULL) {
                        s32 tmp = slot->unk_10;
                        slot->unk_10 = slot->unk_14;
                        slot->unk_14 = tmp;
                    }
                    hit = func_ov000_0219aae8(self, tgt, c, d, 0x30, &ofs, NULL, r, 0, h, 0x1000);
                    if (slot != NULL) {
                        s32 tmp = slot->unk_10;
                        slot->unk_10 = slot->unk_14;
                        slot->unk_14 = tmp;
                    }
                }
                if (self->unk_50->unk_00 != 0) {
                    u32 kind = func_ov000_02199f08(self->unk_4c);
                    Ov003HtMsg msg;
                    msg.val = func_ov000_0219a874(self->unk_50, slot, c);
                    msg.kind = kind;
                    msg.id = 0xffff;
                    if (hit && kind == 0x41) {
                        tgt = (Ov003HtActor *)self;
                    }
                    func_ov000_0218d398(self, tgt->id, 9, 0, sizeof(msg), &msg);
                } else {
                    Ov003HtS44 *s;
                    func_ov000_02199f48(self->unk_50, tgt);
                    func_ov000_02198360(self->work, 0x15, 0);
                    ctl = self->ctl;
                    ctl->unk_9a_0 = 0;
                    ctl->unk_9a_3 = 0;
                    func_0203f364(ctl);
                    s = self->unk_44;
                    s->unk_22_0 = 0;
                    s->unk_22_1 = 0;
                }
                self->unk_4c->unk_1c = 0xffff;
            }
        } else {
            Ov003HtCtl *ctl = self->ctl;
            if ((ctl->flags & 0x40000000) || ctl->unk_58 != 0) {
                self->unk_98 = func_ov000_02198da8(ctl, self->unk_98);
                self->unk_9c >>= 2;
                if (self->unk_9c < 0x8f) {
                    self->unk_9c = 0x8f;
                }
                ctl = self->ctl;
                if (ctl->unk_84 > 0x100 || ctl->unk_58 != 0) {
                    if (self->unk_a0 < -0xcd) {
                        self->unk_a0 = -0xcd;
                    }
                }
                self->work->timer = 0;
            }
            if (self->ctl->flags & 0x20000000) {
                func_ov000_02190cb0(self->model, data_ov003_021f7a85, 0x800, 0);
                if (self->unk_a0 < -0x266) {
                    s32 se = 8;
                    if (self->ctl->flags & 0x400) {
                        se = 0x3d;
                    } else if (self->unk_64 >= 0x1000 && self->unk_a0 < -0x400) {
                        Ov003HtFx *fx;
                        se = 0x17;
                        func_ov000_0218996c(10, 0x14);
                        fx = func_02065f88(0x12e, self->pos);
                        fx->v0c(0x1400);
                    }
                    func_02049f44(data_02097e4c, se, self->pos, 0);
                }
                self->work->state++;
                self->work->timer = 0;
                self->unk_a0 = 0;
                self->unk_a8 = 0;
                self->unk_a4 = 0x800;
            } else {
                func_ov000_02190cb0(self->model, data_ov003_021f7a8b, 0x400, 0);
                func_ov000_021915a0(self->model);
            }
        }
        if (!(self->ctl->flags & 0x20000000)) {
            Ov003HtWork *w = self->work;
            w->timer++;
            if (w->timer > 0x46) {
                self->work->timer = 0x46;
                if (!(self->ctl->unk_54 & 0x20000000)) {
                    func_ov000_02198360(self->work, 0x15, 0);
                }
            }
        }
        break;
    }
    case 2: {
        Ov003HtWork *w;
        self->ctl->unk_9a_5 = 1;
        w = self->work;
        w->timer++;
        if (w->timer >= 5) {
            self->work->timer = 5;
            if (func_ov000_02191120(self->model) || self->work->flags != 0) {
                self->unk_4c->unk_1c = 0xffff;
                self->unk_9c = 0;
                self->unk_a0 = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
                func_ov000_02198360(self->work, 1, 0);
            }
        }
        break;
    }
    }
    {
        Ov003HtCtl *other = NULL;
        BOOL restore;
        Ov003HtTarget *t;
        func_ov000_0218dbe0(self, 0);
        if (self->ctl == NULL) {
            return;
        }
        t = self->unk_4c;
        restore = FALSE;
        if (t != NULL && t->unk_1c != 0xffff && t->unk_01 == 1) {
            s32 r = self->unk_64 + 0x4cd;
            Ov003HtActor *a;
            if (r < 0xccd) {
                r = 0xccd;
            }
            self->ctl->unk_44 = r;
            a = func_ov000_02199ba0(self->unk_4c);
            if (a != NULL && (other = a->ctl) != NULL && other->unk_9a_3) {
                other->unk_9a_3 = 0;
                func_0203f364(other);
                restore = TRUE;
            }
        }
        func_ov000_021987b8(self->ctl, 1, 0, 0);
        if (restore) {
            other->unk_9a_3 = 1;
            func_0203f324(other);
        }
    }
}

}
