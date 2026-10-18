#include "ov003/GmObj.h"

extern "C" {

extern BOOL func_ov000_02194c08(void *self);
extern void *data_ov000_021ccd64;
extern Ov003PathPt *data_ov003_021f85c0[];
extern void func_ov000_02194758(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021e68b4(Ov003Obj *self) {
    Ov003Unit *u;
    Ov003PathPt *p;
    func_ov000_02194758(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
        u->unk_a2_0 = 0;
        u->unk_a2_6 = 0;
    }
    if (self->unk_4c != NULL) {
        self->unk_4c->unk_18_5 = 1;
    }
    self->unk_ce = 0;
    p = data_ov003_021f85c0[self->unk_1a];
    if (p != NULL) {
        self->pos.x = p[self->unk_ce].pos.x;
        self->pos.y = p[self->unk_ce].pos.y;
        self->pos.z = p[self->unk_ce].pos.z;
    }
}



BOOL func_ov003_021e694c(Ov003Obj *self) {
    BOOL r = FALSE;
    if (self->model->unk_be != 0) {
        r = func_ov000_02194c08(self);
    }
    return r;
}

extern char data_ov003_021f8574[];
extern Ov003Obj *func_ov000_0219bf90(void);
extern void func_0203f364(Ov003Ctl *ctl);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern void VEC_Normalize(Ov003Vec3 *src, Ov003Vec3 *dst);
extern void VEC_Add(Ov003Vec3 *a, Ov003Vec3 *b, Ov003Vec3 *dst);
extern BOOL func_01ffc198(Ov003Vec3 *a, Ov003Vec3 *b, s32 r);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0218d918(Ov003Obj *self, Ov003PathPt *pt, s32 a);

void func_ov003_021e6974(Ov003Obj *self) {
    Ov003Obj *pl;
    Ov003PathPt *pt;
    Ov003Work *w;
    s32 snd;
    if (self->unk_ce < 0) {
        return;
    }
    pt = data_ov003_021f85c0[self->unk_1a];
    if (pt == NULL) {
        return;
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        u8 a;
        self->unk_90 = pl->unk_0c;
        a = self->model->unk_be;
        if (pl->unk_93_4) {
            Ov003Sub44 *s = self->unk_44;
            Ov003Ctl *ctl;
            if (s != NULL) {
                s->unk_22_1 = 0;
            }
            ctl = self->ctl;
            if (ctl != NULL) {
                ctl->unk_9a_3 = 0;
                func_0203f364(ctl);
            }
            if (a != 0) {
                self->model->unk_be = a - 1;
            }
        } else if (a < 0x1f) {
            self->model->unk_be = a + 1;
        }
    }
    pt = &pt[self->unk_ce];
    w = self->work;
    switch (w->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f8574, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x2800);
        self->unk_4c->unk_1c = 0xffff;
        self->unk_cc_8 = 0;
        self->work->state++;
    case 1: {
        Ov003Vec3 *v = (Ov003Vec3 *)&self->unk_9c;
        s32 sp;
        v->x = pt->pos.x - self->pos.x;
        v->y = pt->pos.y - self->pos.y;
        v->z = pt->pos.z - self->pos.z;
        VEC_Normalize(v, v);
        sp = pt->speed;
        v->x = (s32)(((s64)v->x * sp + 0x800) >> 12);
        v->y = (s32)(((s64)v->y * sp + 0x800) >> 12);
        v->z = (s32)(((s64)v->z * sp + 0x800) >> 12);
        VEC_Add(&self->pos, v, &self->pos);
        if (func_01ffc198(&self->pos, &pt->pos, pt->speed << 3)) {
            self->work->state++;
            self->work->timer = pt->wait;
            self->unk_ce = pt->next;
            func_ov000_021911c8(self->model, 0x1000);
        }
        break;
    }
    case 2: {
        Ov003Vec3 *v = (Ov003Vec3 *)&self->unk_9c;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->work->state = 0;
        }
        v->x = (s32)(((s64)v->x * 0x59a + 0x800) >> 12);
        v->y = (s32)(((s64)v->y * 0x59a + 0x800) >> 12);
        v->z = (s32)(((s64)v->z * 0x59a + 0x800) >> 12);
        VEC_Add(&self->pos, v, &self->pos);
        break;
    }
    }
    snd = 0x133;
    if (self->kind == 2) {
        if (pl != NULL && func_01ffc198(&pl->pos, &self->pos, pl->unk_64 + 0x2000)) {
            func_ov000_02198360(self->work, 0xe, 0);
        }
        snd = 0xcd;
    }
    func_ov000_0218d918(self, pt, snd);
}

}
