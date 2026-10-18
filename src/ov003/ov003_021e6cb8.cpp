#include "ov003/GmObj.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern char data_ov003_021f8574[];
extern char data_ov003_021f85ba[];
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 a);
extern BOOL func_ov000_02191120(void *model);
extern void func_0203f324(Ov003Ctl *ctl);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003Fx *func_02065f88(s32 id, const Ov003Vec3 *pos);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern Ov003Part *func_ov000_02199ba0(Ov003Part *p);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern s32 func_02040528(s32 max);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(void *self, void *other, s32 a);

static inline void *Ov003_FindObj(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov003_021e6cb8(Ov003Obj *self) {
    switch (self->work->state) {
    case 0: {
        Ov003Ctl *ctl;
        Ov003Fx *fx;
        self->unk_4c->unk_1c = 0xffff;
        func_ov000_02190cb0(self->model, data_ov003_021f8574, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x2800);
        ctl = self->ctl;
        if (ctl != NULL) {
            ctl->unk_9a_0 = 1;
            ctl->unk_9a_3 = 1;
            func_0203f324(ctl);
        }
        Ov003Sub44_Set(self->unk_44);
        if (!self->unk_cc_8) {
            func_ov000_02198360(self->work, 1, 0);
            return;
        }
        self->unk_cc_8 = 0;
        fx = func_02065f88(0x322, &self->pos);
        fx->SetRot(0, self->unk_6c, 0);
        fx->SetScale(self->unk_64, self->unk_64, self->unk_64);
        self->work->state++;
        break;
    }
    case 1: {
        Ov003Work *w = self->work;
        w->timer++;
        if (w->timer <= 0x4b) {
            return;
        }
        func_ov000_02198360(self->work, 1, 0);
        break;
    }
    }
}

void func_ov003_021e6e20(Ov003Obj *self) {
    u16 t;
    if (self->work->state == 0) {
        self->unk_d0 = 0;
        func_ov000_021911c8(self->model, 0x5000);
    }
    func_ov000_02195d88(self);
    self->unk_d0++;
    t = self->unk_d0;
    if (t > 0x78) {
        Ov003Part *p;
        u8 k;
        if (self->kind == 1) {
            func_02065f88(0x12f, &self->pos)->SetSpeed(0xa66);
            func_ov000_02197dec(self, 0xf, -1);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            Ov003Obj_Destroy(self);
            return;
        }
        p = func_ov000_02199ba0(self->unk_4c);
        k = 0;
        if (p != NULL && p->unk_40 != NULL) {
            k = p->unk_40->kind;
        }
        if (k == 0 || k == 1 || k == 2 || k == 4) {
            func_02049f44(data_02097e4c, 0x83, &self->pos, 0);
            func_ov000_02198360(self->work, 10, 0);
        }
        return;
    }
    {
        s32 r = 0x78 - t;
        if (r <= 0x1f && self->kind == 1) {
            self->model->unk_be = r;
            return;
        }
    }
    if (t & 0xf) {
        return;
    }
    {
        Ov003Fx *fx = func_02065f88(0x44d, &self->pos);
        s32 a = func_02040528(0x4cd);
        s32 b = func_02040528(0x4cd);
        fx->SetRot(a, -0x19a, b);
    }
}

void func_ov003_021e6fb4(Ov003Obj *self) {
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f85ba, 0x1000, 0);
        self->work->state++;
    case 1:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, data_ov003_021f8574, 0x19a, 0);
            func_ov000_021915a0(self->model);
            func_ov000_021911c8(self->model, 0xccd);
            self->work->timer = 0;
            self->work->state++;
        } else {
            Ov003Work *w = self->work;
            w->timer++;
            if (w->timer <= 0x50) {
                void *o = Ov003_FindObj(self->unk_90);
                if (o != NULL) {
                    func_ov000_0218d988(self, o, 0x333);
                }
            }
        }
        break;
    case 2: {
        Ov003Work *w = self->work;
        w->timer++;
        if (w->timer > 0x50) {
            func_ov000_02198360(self->work, 1, 0);
        }
        break;
    }
    }
    if (self->unk_cc_8) {
        func_ov000_02198360(self->work, 10, 0);
    }
}

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Ov003MapId;

typedef struct {
    u8 unk_00[0x772];
    Ov003MapId map;
} Ov003Plyr;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
} Ov003NearObj;

extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003Plyr *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a7bc(void *self, s32 a, Ov003Vec3 *pos, s32 r, s32 b, Ov003NearObj **list);
extern void func_ov000_02196860(void *self);

static inline BOOL Ov003MapId_Equal(const Ov003MapId *a, const Ov003MapId *b) {
    BOOL r = FALSE;
    const u8 *x = (const u8 *)a;
    const u8 *y = (const u8 *)b;
    if (x[0] == y[0] && x[1] == y[1] && x[2] == y[2]) {
        r = TRUE;
    }
    return r;
}

void func_ov003_021e7114(Ov003Obj *self) {
    if (self->work->state == 0 && self->unk_cc_8) {
        Ov003Plyr *p;
        self->unk_cc_8 = 0;
        p = func_ov000_0219bf90();
        if (p != NULL && !Ov003MapId_Equal((Ov003MapId *)&data_ov000_021ccd54->unk_ca, &p->map)) {
            Ov003Vec3 v;
            Ov003NearObj *list[32];
            s32 n;
            s32 i;
            BOOL found;
            v = self->pos;
            v.y -= 0x2800;
            found = FALSE;
            n = func_ov000_0219a7bc(self, 0x10, &v, 0x8000, 0x5000, list);
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    if (list[i] != NULL) {
                        u16 id = list[i]->id;
                        if (id == 0x4008 || id == 0x4022 || id == 0x4031 || id == 0x4014) {
                            found = TRUE;
                            break;
                        }
                    }
                }
            }
            if (found) {
                self->unk_4c->unk_1c = 0xffff;
                func_ov000_02198360(self->work, 1, 0);
                return;
            }
        }
    }
    func_ov000_02196860(self);
}

}
