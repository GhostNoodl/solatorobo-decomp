#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 state;
    u16 timer;
} St_021a5d00;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 3;
} B18_021a5d00;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 7;
} B19_021a5d00;

extern "C" {

extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd6c;
extern void *data_02097e4c;
extern char data_ov000_021cc67e[];
extern char data_ov000_021cc61e[];
extern char data_ov000_021cc660[];
extern char data_ov000_021cc684[];
Actor *ActorMgr_GetActor(void *mgr, u16 id);
u16 FX_Atan2(s32 y, s32 x);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL Hit_DiffInCylinder(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void Actor_Move(void *self, s32 turn);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_021899d8(void *pos, s32 a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov000_02191120(void *a);
void func_02062764(s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_ov000_02182590(void *p);
BOOL func_0205b1fc(void);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void Target_Set(u8 *info, u8 *self);
void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
BOOL func_ov000_02198360(St_021a5d00 *st, s32 state, s32 x);

static inline Actor *FindActor021a5d00(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u16 AngleTo021a5d00(Robo021ca458 *self, Actor *a) {
    if (a == NULL || a == self) {
        return self->rot_y;
    }
    return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
}

static inline BOOL Ev19_021a5d00(void) {
    u8 *e = LFLD(u8 *, data_ov000_021ccd6c, 0x14);
    if (e != NULL && LFLD(B19_021a5d00, e, 0x19).b0) {
        return TRUE;
    }
    return FALSE;
}

static inline void Fx021a5d00(Robo021ca458 *self, u8 *info) {
    if (!Ev19_021a5d00() && !(info != NULL && (LFLD(B18_021a5d00, info, 0x18).b4 ? TRUE : FALSE))) {
        VecFx32 v;
        v = *(VecFx32 *)((u8 *)self + 0x70);
        v.y += self->height;
        func_ov000_021899d8(&v, 0, 0x8000, 1, 0x1000, 0x1000);
    }
    self->unk_44->unk_22_1 = 0;
}

static inline void Reset021a5d00(Robo021ca458 *self) {
    self->unk_b24_5 = 0;
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_7 = self->unk_b24_9;
    func_ov000_02198360((St_021a5d00 *)self->fsm, 1, 0);
}

void func_ov000_021a5d00(Robo021ca458 *self) {
    Actor *a;
    u8 *info;
    self->hit->unk_9a |= 0x20;
    a = FindActor021a5d00(self->target);
    info = NULL;
    if (a != NULL) {
        info = ((u8 *)a->targetObj);
    }
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    switch (((St_021a5d00 *)self->fsm)->state) {
    case 0: {
        char *lbl = data_ov000_021cc67e;
        if (a != NULL) {
            VecFx32 pos;
            pos = *(VecFx32 *)((u8 *)self + 0x70);
            pos.y -= 0x1000;
            self->moveYaw = AngleTo021a5d00(self, a);
            self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
            {
                St_021a5d00 *st = (St_021a5d00 *)self->fsm;
                st->timer++;
                if (st->timer < 0xf) {
                    if (!Hit_DiffInCylinder(&a->pos, &pos, (a->radius << 1) + 0x19a, 0x3800)) {
                        func_ov000_02190cb0(self->model, data_ov000_021cc61e, 0x400, 0);
                        func_ov000_021915a0(self->model);
                        self->speed = 0x15c;
                        Actor_Move(self, 0);
                        func_ov000_021987b8(self->hit, 0, 0, 0);
                        return;
                    }
                }
            }
            if (pos.y > self->pos.y) {
                lbl = data_ov000_021cc660;
            }
        }
        func_ov000_02190cb0(self->model, lbl, 0x400, 0);
        ((St_021a5d00 *)self->fsm)->state++;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        return;
    }
    case 1:
        Fx021a5d00(self, info);
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        if (a != NULL && info != NULL) {
            BOOL done;
            u8 *o44;
            o44 = ((u8 *)a->unk_44);
            done = FALSE;
            if (LFLD(B18_021a5d00, info, 0x18).b1 && info[3] != 10 && info[3] != 11) {
                FieldState *g;
                func_02062764(0x3c0, 0x80);
                func_020627a0(a->kind, a->id);
                g = data_ov000_021ccd54;
                g->stageFlags = 1;
                func_ov000_02182590((u8 *)g + 0xac);
                if (func_0205b1fc()) {
                    done = TRUE;
                }
            }
            if (!done && o44 != NULL) {
                u8 k0 = info[0];
                u8 k1 = info[1];
                if ((k0 == 5 || k0 == 7) && (k1 == 4 || k1 == 6)) {
                    self->unk_b24_5 = 3;
                    self->unk_b24_7 = 3;
                    self->unk_b1c = self->target;
                    self->target = 0xffff;
                    func_ov000_0218d46c(a, self->id, 0xd);
                    Target_Set(info, (u8 *)self);
                    info[1] = 9;
                    if (info[3] != 10 && info[3] != 11) {
                        func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
                    }
                    func_ov000_02190cb0(self->model, data_ov000_021cc684, 0x1000, 0);
                    ((St_021a5d00 *)self->fsm)->state++;
                    ((St_021a5d00 *)self->fsm)->timer = 0;
                    return;
                }
            }
        }
        Reset021a5d00(self);
        return;
    case 2:
        if (func_ov000_02191120(self->model)) {
            St_021a5d00 *st = (St_021a5d00 *)self->fsm;
            st->timer++;
            if (st->timer > 0x14) {
                Reset021a5d00(self);
            }
        }
        Fx021a5d00(self, info);
        return;
    }
}

}
