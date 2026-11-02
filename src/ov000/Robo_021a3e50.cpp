#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 a;
    u16 b;
    u8 c;
} Msg021a3e50;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd30;
extern u8 *data_ov000_021ccd54;
extern u8 *data_0214a424;
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc648[];
Actor *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_0218d398(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d988(void *self, void *other, s32 step);
BOOL func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
void func_ov000_021915a0(void *p);
void func_020627a0(u16 a, u16 b);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_021700c4(void *p);
void *func_ov000_02173610(s32 kind);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);

static inline Actor *FindActor021a3e50(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

static inline BOOL IsBusy021a3e50(void) {
    BOOL r;
    u8 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 6)) {
        r = TRUE;
    } else if (LFLD(void *, m, 0x11c) == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021700c4(LFLD(void *, m, 0x11c));
    }
    return r;
}

void func_ov000_021a3e50(Robo021ca458 *self) {
    Actor *t;
    ActorSub40 *sub;
    LFLD(u16, self->unk_48, 0x9a) |= 0x20;
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    t = FindActor021a3e50(self->target);
    sub = self->unk_40;
    switch (sub->st) {
    case 0:
        if (t != NULL) {
            Msg021a3e50 m;
            m.a = 1;
            m.b = 0x19a;
            m.c = 1;
            func_ov000_0218d398(t, self->id, 5, TRUE, 6, &m);
            if (t->kind == 0x2003) {
                u16 v;
                self->unk_40->st++;
                v = LFLD(u16, ((u8 *)self->hp), 2);
                func_ov000_0218d398(self, self->id, 10, TRUE, 2, &v);
            } else {
                self->unk_40->st = 10;
                if (self->unk_bac != self->target) {
                    u8 *g;
                    u32 n;
                    self->unk_bac = self->target;
                    g = data_0214a424;
                    n = LFLD(u16, g, 0x14) + 1;
                    if (n >= 0xffff) {
                        n = 0xffff;
                    }
                    LFLD(u16, g, 0x14) = n;
                }
            }
        }
        {
            u8 *anim = data_ov000_021cc5e3;
            if (!LBIT(self, 0xb24).b1) {
                anim = data_ov000_021cc648;
            }
            func_ov000_02190cb0(self->unk_38, anim, 0x400, 0);
        }
        func_ov000_021915a0(self->unk_38);
        self->unk_40->timer = 0;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        break;
    case 1:
        sub->timer++;
        if (sub->timer > 0x1e) {
            self->unk_40->st = 10;
            self->unk_40->timer = 0;
        }
        break;
    case 10:
        if (t != NULL) {
            func_020627a0(t->kind, t->id);
            LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
        }
        self->unk_40->st++;
        break;
    case 11:
        sub->timer++;
        if (sub->timer > 0x14) {
            self->unk_40->st++;
            self->unk_40->timer = 0;
        }
        break;
    case 12:
        if (IsBusy021a3e50()) {
            break;
        }
        if (func_ov000_02173610(7)) {
            break;
        }
        if (t != NULL) {
            Msg021a3e50 m;
            m.a = 0;
            m.b = 0x19a;
            m.c = 1;
            func_ov000_0218d398(t, self->id, 5, TRUE, 6, &m);
        }
        self->unk_b2f = 0x2d;
        self->target = 0xffff;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    func_ov000_0218d988(self, t, 0x400);
}

}
