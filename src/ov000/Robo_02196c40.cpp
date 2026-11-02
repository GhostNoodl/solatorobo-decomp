#include "types.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
    s32 unk_04;
    s32 unk_08;
} State02196c40;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 rest : 9;
} Bits02196c40;

typedef struct {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 rest : 5;
} Bits8_02196c40;

class VObj02196c40 {
public:
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0c(s32 a);
};

extern "C" {
extern char data_ov000_021cc463[];
extern u8 *data_0214a424;
extern void *data_02097e4c;
extern void *data_ov000_021ccd6c;
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
BOOL func_ov000_02191120(void *a);
void HitSphere_Link(void *a);
void func_0203f364(void *a);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
Robo021ca458 *func_ov000_0219bf90(void);
void *Target_Get(void *p);
void Target_Set(void *a, void *b);
void func_ov003_021f0c60(void *self, s32 a);
void *func_ov003_021f0868(void *pos, s32 a, s32 b);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
VObj02196c40 *func_02065f88(s32 id, void *pos);
u8 *func_ov000_021b68b8(void *mgr, void *pos);
void func_ov000_02197ad0(void *self, BOOL b);
void Actor_Move(void *self, s32 a);
void func_ov000_021987b8(void *a, BOOL b, s32 c, s32 d);

static inline s32 FxMul02196c40(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline BOOL IsB2_02196c40(u8 *m) {
    return LFLD(Bits8_02196c40, m, 0x18).b2 ? TRUE : FALSE;
}

void func_ov000_02196c40(ActorEx *self) {
    BOOL flag = TRUE;
    self->hit->unk_9a_6 = 0;
    switch (((State02196c40 *)self->fsm)->st) {
    case 0:
        if (self->gravity == 0) {
            self->gravity = 0x52;
        }
        self->unk_92 = 0;
        self->unk_cc_6 = 0;
        ((State02196c40 *)self->fsm)->st++;
        break;
    case 1: {
        u32 in = self->hit->unk_50;
        u8 *hit;
        if (self->velY > 0 && (in & 0x80000000)) {
            self->velY = -0xcd;
        }
        if (self->msg_flags & 0x80) {
            self->speed = 0;
        }
        if (in & 0x400) {
            VObj02196c40 *o;
            if (self->unk_cc_6) {
                break;
            }
            self->unk_cc_6 = 1;
            self->speed = 0;
            self->unk_92 = 3;
            func_02049f44(data_02097e4c, 0x3d, &self->pos, 0);
            o = func_02065f88(0x2bd, &self->pos);
            if (self->radius > 0x1000) {
                o->vfunc_0c(self->radius);
            }
            break;
        }
        hit = func_ov000_021b68b8(data_ov000_021ccd6c, &self->pos);
        if (hit != NULL) {
            u16 ang = LFLD(u16, hit, 0x1a);
            self->speed = FxMul02196c40(self->speed, 0x59a);
            if (self->speed < 0x8f) {
                self->speed = 0x8f;
            }
            self->moveYaw = ang;
            self->gravity = 0x52;
            flag = FALSE;
        }
        if (hit != NULL || (in & 0x20000000) || ((in & 0x40000000) && !IsB2_02196c40(((u8 *)self->targetObj))) ||
            ((s32)self->hit->unk_58) != 0) {
            s32 kind = 0;
            BOOL got = FALSE;
            ((State02196c40 *)self->fsm)->timer = 0;
            if (hit != NULL || self->targetObj->target != 0xffff) {
                if (self->targetObj->unk_01 == 1) {
                    kind = self->targetObj->unk_02;
                    got = TRUE;
                }
            }
            switch (kind) {
            case 1:
            case 2: {
                Robo021ca458 *p;
                if (self->unk_44 != NULL) {
                    u8 *q = self->unk_44;
                    LFLD(Bits02196c40, q, 0x22).b0 = 0;
                    LFLD(Bits02196c40, q, 0x22).b1 = 0;
                }
                if (self->hit != NULL) {
                    ActorSub48 *q = self->hit;
                    LFLD(Bits02196c40, q, 0x9a).b0 = 0;
                    q->unk_9a_3 = 0;
                    func_0203f364(q);
                    q = self->hit;
                    LFLD(Bits02196c40, q, 0x9a).b1 = 0;
                    q->unk_9a_4 = 0;
                }
                p = func_ov000_0219bf90();
                if (p->id == self->targetObj->target) {
                    u8 *g = data_0214a424;
                    u32 n = LFLD(u16, g, 0x16) + 1;
                    if (n >= 0xffff) {
                        n = 0xffff;
                    }
                    LFLD(u16, g, 0x16) = n;
                }
                if (self->targetObj->unk_03 != 0) {
                    func_ov003_021f0c60(self, 0);
                }
                func_ov000_02198360(((State02196c40 *)self->fsm), 0x15, 0);
                break;
            }
            default:
                func_ov000_02197ad0(self, got);
                if (((in & 0x20000000) && self->velY == 0) || self->unk_92 > 3) {
                    ((State02196c40 *)self->fsm)->st++;
                    self->velY = 0;
                    self->gravity = 0;
                    self->friction = 0x800;
                }
                break;
            }
        }
        if (self->velY < 0) {
            State02196c40 *st;
            func_ov000_02190cb0(self->model, data_ov000_021cc463, 0x1000, 0);
            func_ov000_021915a0(self->model);
            st = ((State02196c40 *)self->fsm);
            st->timer++;
            if (st->timer > 0x46) {
                ((State02196c40 *)self->fsm)->timer = 0x46;
                if (!(self->hit->unk_54 & 0x20000000)) {
                    func_ov000_02198360(((State02196c40 *)self->fsm), 0x15, 0);
                }
            }
        }
        break;
    }
    case 2: {
        State02196c40 *st;
        self->hit->unk_9a_5 = 1;
        st = ((State02196c40 *)self->fsm);
        st->timer++;
        if (st->timer < 6) {
            break;
        }
        ((State02196c40 *)self->fsm)->timer = 6;
        if (!func_ov000_02191120(self->model) && LFLD(s64, ((State02196c40 *)self->fsm), 4) == 0) {
            break;
        }
        self->targetObj->target = 0xffff;
        func_ov000_02198360(((State02196c40 *)self->fsm), 1, 0);
        break;
    }
    }
    Actor_Move(self, 0);
    if (self->hit != NULL) {
        u8 *other;
        BOOL saved;
        u8 *m;
        if (self->param->type == 2) {
            ActorSub48 *q = self->hit;
            LFLD(Bits02196c40, q, 0x9a).b0 = 1;
            q->unk_9a_3 = 1;
            HitSphere_Link(q);
        }
        m = ((u8 *)self->targetObj);
        other = NULL;
        saved = FALSE;
        if (m != NULL && LFLD(u16, m, 0x1c) != 0xffff && LFLD(u8, m, 1) == 1) {
            s32 h = self->radius + 0x4cd;
            u8 *t;
            if (h < 0xccd) {
                h = 0xccd;
            }
            self->hit->unk_44 = h;
            t = (u8 *)Target_Get(((u8 *)self->targetObj));
            if (t != NULL && (other = LFLD(u8 *, t, 0x48)) != NULL && LFLD(Bits02196c40, other, 0x9a).b3) {
                LFLD(Bits02196c40, other, 0x9a).b3 = 0;
                func_0203f364(other);
                saved = TRUE;
            }
        }
        func_ov000_021987b8(self->hit, flag, 0, 0);
        if (saved) {
            LFLD(Bits02196c40, other, 0x9a).b3 = 1;
            HitSphere_Link(other);
        }
    }
    if (((u8 *)self->targetObj) != NULL && self->targetObj->type == 2) {
        void *r = func_ov003_021f0868(&self->pos, self->radius, self->height);
        if (r != NULL) {
            Target_Set(((u8 *)self->targetObj), r);
            func_ov000_02198360(((State02196c40 *)self->fsm), 0xd, 0);
        }
    }
}

}
