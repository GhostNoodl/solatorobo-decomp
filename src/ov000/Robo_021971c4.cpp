#include "nitro/fx.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} Save021971c4;

extern "C" {
extern char data_ov000_021cc469[];
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern Save021971c4 *data_0214a424;
void *Target_Get(void *p);
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
Actor *ActorMgr_GetActor(void *mgr, u16 id);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void Target_Set(void *a, void *b);
BOOL func_ov000_02199cd8(void *a, u16 id);
BOOL func_ov000_02191120(void *a);
void Actor_SendMsg(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
u8 *func_020704b4(u16 id);
void func_ov000_0219b400(u16 *ids, u8 *rates, s32 n, void *pos, void *rot, u8 check);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
u16 func_0206e7ec(u32 a, u32 b);
void func_020627c8(void);
void func_ov000_0218bed8(void *a, s32 b, void *c);
u16 func_ov000_02199bc8(void *a, void *pos, s32 b, s32 c);

static inline Actor *FindActor021971c4(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline void SetNibble021971c4(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &data_0214a424->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int GetNibble021971c4(s32 row, s32 idx) {
    u32 v = data_0214a424->flags[row][idx / 8];
    return (v >> ((idx % 8) * 4)) & 0xf;
}

void func_ov000_021971c4(VObj *obj) {
    ActorEx *self = (ActorEx *)obj;
    u32 none = 0xffff;
    s32 zero = 0;
    u8 *tgt = (u8 *)Target_Get(((u8 *)self->unk_4c));
    switch (self->unk_40->st) {
    case 0:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov000_021cc469, 0x1000, zero);
        }
        if (tgt != NULL) {
            if (self->target != none) {
                Actor *a;
                obj->vfunc_88();
                a = FindActor021971c4(self->target);
                if (a != NULL) {
                    func_ov000_0218d46c(a, self->id, 6);
                    a->target = none;
                    if (((void *)a->unk_4c) != NULL) {
                        Target_Set(((void *)a->unk_4c), self);
                    }
                }
            } else if (func_ov000_02199cd8(((u8 *)self->unk_4c), LFLD(u16, tgt, 0xe))) {
                obj->vfunc_8c();
                self->unk_4c->unk_1c = none;
            }
        }
        self->unk_40->st++;
        break;
    case 1:
        if (self->model != NULL && !func_ov000_02191120(self->model)) {
            break;
        }
        if (tgt != NULL) {
            Actor_SendMsg(tgt, self->id, 3, 1, zero, (const void *)zero);
        }
        if (self->unk_4c->unk_01 == 8) {
            u8 *d = func_020704b4(self->kind);
            func_ov000_0219b400((u16 *)(d + 0x20), d + 0x24, 2, &self->pos, (u8 *)self + 0x7c, zero);
        }
        if (self->target != none) {
            u8 *m = ((u8 *)self->unk_4c);
            if (LFLD(u8, m, 2) != 0 && LFLD(u8, m, 2) != 7) {
                LFLD(u16, m, 0x1c) = none;
            } else {
                func_ov000_02198360(self->unk_40, 9, 0);
            }
            self->target = none;
        } else {
            self->unk_4c->unk_1c = none;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        if (self->unk_4c->unk_02 == 5) {
            u8 idx = self->unk_17;
            s32 row;
            if (idx != 0xff) {
                row = func_0206e7ec(self->unk_ac, self->unk_ad);
                if (row != none) {
                    u8 val = 0xf;
                    val |= GetNibble021971c4(row, idx) & 8;
                    SetNibble021971c4(row, idx, val);
                }
            }
            func_020627c8();
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            obj->vfunc_08();
        }
        break;
    }
    if (tgt != NULL && self->target != none) {
        func_ov000_02199bc8(((u8 *)self->unk_4c), &self->pos, 0, 0);
        self->rot_x = LFLD(u16, tgt, 0x7c);
        self->rot_y = LFLD(u16, tgt, 0x7e);
        self->rot_z = LFLD(u16, tgt, 0x80);
    }
}

}
