#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern void *data_ov000_021ccd68;
Actor *ActorMgr_GetActor(void *mgr, u16 id);
s32 func_ov000_0219840c(void *s, s32 *list, s32 count, BOOL push);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_020627dc(u16 a);
void func_ov000_02182590(void *p);
BOOL func_0205b1fc(void);
void func_0205c234(s32 a, s32 b);

static inline Actor *FindActor021a09b8(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline void Ping021a09b8(void) {
    FieldState *g = data_ov000_021ccd54;
    g->stageFlags = 1;
    func_ov000_02182590((u8 *)g + 0xac);
}

s32 func_ov000_021a09b8(Robo021ca458 *self, s32 *list, s32 count) {
    Actor *a;
    u8 kind;
    s32 r;
    ActorSub4c *sub;
    BOOL done;

    a = NULL;
    r = func_ov000_0219840c(((void *)self->fsm), list, count, FALSE);
    if (r == 0) {
        return r;
    }
    a = FindActor021a09b8(self->target);
    sub = NULL;
    if (a != NULL) {
        sub = (ActorSub4c *)((u8 *)a->targetObj);
    }
    kind = 0;
    if (sub != NULL) {
        kind = sub->type;
    }
    done = FALSE;
    switch (r) {
    case 6:
        if (a == NULL || sub == NULL) {
            break;
        }
        if (kind != 4 && kind != 6 && kind != 0xc && kind != 0xd) {
            break;
        }
        if (sub->unk_18_1 && sub->unk_03 != 0xa && sub->unk_03 != 0xb) {
            func_020627a0(a->kind, a->id);
            func_020627dc(a->unk_18);
            Ping021a09b8();
            if (func_0205b1fc()) {
                done = TRUE;
            }
        }
        if (done) {
            r = 0;
        } else {
            switch (sub->type) {
            case 6:
                if (LBIT(self, 0xb24).b1) {
                    r = 0;
                    func_0205c234(0x64, 0);
                }
                break;
            case 0xc:
            case 0xd:
                if (!LBIT(self, 0xb24).b1) {
                    r = 0;
                    func_0205c234(0x65, 0);
                }
                break;
            }
        }
        break;
    case 7:
    case 0x18:
        if (a == NULL || sub == NULL) {
            break;
        }
        if (kind != 5 && kind != 0xe && kind != 0xf && kind != 0x11 && kind != 0x13 && kind != 0x12 && kind != 0x14) {
            break;
        }
        if (sub->unk_18_1) {
            func_020627a0(a->kind, a->id);
            func_020627dc(a->unk_18);
            Ping021a09b8();
            if (func_0205b1fc()) {
                done = TRUE;
            }
        }
        if (done) {
            r = 0;
            self->unk_b2c_4 = 0;
        } else if (!LBIT(self, 0xb24).b1) {
            r = 0;
            func_0205c234(0x65, 0);
        }
        break;
    case 8:
    case 0x1e:
        if (a == NULL || sub == NULL) {
            break;
        }
        if (sub->unk_18_1 && sub->unk_03 != 0xa && sub->unk_03 != 0xb) {
            func_020627a0(a->kind, a->id);
            func_020627dc(a->unk_18);
            Ping021a09b8();
            if (func_0205b1fc()) {
                done = TRUE;
            }
        }
        if (done) {
            r = 0;
        } else if (LBIT(self, 0xb24).b1) {
            r = 0;
            func_0205c234(0x64, 0);
        }
        break;
    case 0x10:
        if (a == NULL) {
            break;
        }
        func_020627a0(a->kind, a->id);
        Ping021a09b8();
        if (func_0205b1fc()) {
            r = 0;
        }
        break;
    case 0x1d:
        func_020627a0(a->kind, a->id);
        Ping021a09b8();
        if (func_0205b1fc()) {
            r = 0;
        } else {
            switch (sub->type) {
            case 8:
                if (LBIT(self, 0xb24).b1) {
                    func_0205c234(0x64, 0);
                    r = 0;
                }
                break;
            case 0x10:
                if (!LBIT(self, 0xb24).b1) {
                    func_0205c234(0x65, 0);
                    r = 0;
                }
                break;
            }
        }
        break;
    }
    if (r != 0) {
        func_ov000_02198360(((void *)self->fsm), (u8)r, 0);
    }
    return r;
}

}
