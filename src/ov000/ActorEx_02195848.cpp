#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 rest : 9;
} B16_02195848;

extern "C" {
extern void *data_ov000_021ccd64;
extern u8 data_ov000_021cc456[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void *func_ov003_021f0868(void *a, s32 r, s32 h);
void Target_Set(void *body, void *p);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
void func_ov000_0218bed8(void *a, s32 b, void *c);
void HitSphere_Link(void *p);
void func_0203f364(void *p);
void func_ov000_021987b8(void *p, s32 a, s32 b, s32 c);
void HitMesh_SetMtx(void *p, MtxFx43 *m);

static inline BOOL PlayerIdle02195848(void) {
    FieldState *pl = data_ov000_021ccd54;
    if (pl != NULL) {
        if (pl->head != pl->tail ? TRUE : FALSE) {
            return FALSE;
        }
        if (pl->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline void RotZYX02195848(MtxFx43 *m, MtxFx43 *tp, u16 rx, u16 ry, u16 rz) {
    BOOL any = FALSE;
    MTX_Identity43_(m);
    if (rz != 0) {
        MTX_RotZ43_(m, SC(rz));
        any = TRUE;
    }
    if (ry != 0) {
        if (any) {
            MTX_RotY43_(tp, SC(ry));
            MTX_Concat43(tp, m, m);
        } else {
            MTX_RotY43_(m, SC(ry));
            any = TRUE;
        }
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX43_(tp, SC(rx));
            MTX_Concat43(tp, m, m);
        } else {
            MTX_RotX43_(m, SC(rx));
        }
    }
}

void func_ov000_02195848(VObj *obj) {
    ActorEx *self = (ActorEx *)obj;
    MtxFx43 t;
    MtxFx43 m;
    ActorSub48 *h;

    h = self->unk_48;
    if (h != NULL) {
        h->unk_9a_6 = 0;
    }
    switch (self->unk_40->st) {
    case 0:
        if ((void *)((u8 *)self->model) != NULL) {
            func_ov000_02190cb0(((u8 *)self->model), data_ov000_021cc456, 0x1000, 0);
            func_ov000_021915a0(((u8 *)self->model));
        }
        self->unk_40->st++;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_cc |= 2;
        break;
    case 1:
        if (((u8 *)self->unk_4c) != NULL && self->unk_4c->unk_00 == 2) {
            void *r = func_ov003_021f0868((u8 *)self + 0x70, self->unk_64, self->unk_68);
            if (r != NULL) {
                Target_Set(((u8 *)self->unk_4c), r);
                func_ov000_02198360(((u8 *)self->unk_40), 0xd, 0);
                break;
            }
        }
        if (self->unk_20 == 0xffff && self->unk_cc_4) {
            if (PlayerIdle02195848()) {
                u8 *st = ((u8 *)self->unk_40);
                LFLD(u16, st, 2)++;
                if ((s32)LFLD(u16, st, 2) > 0x1fe) {
                    if ((s32)LFLD(u16, st, 2) > 0x258) {
                        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
                        obj->vfunc_08();
                        break;
                    }
                    if (((u8 *)self->model) != NULL) {
                        if ((LFLD(u16, st, 2) & 7) > 2) {
                            self->model->alpha = 10;
                        } else {
                            self->model->alpha = 0x1f;
                        }
                    }
                }
            } else if (((u8 *)self->model) != NULL) {
                self->model->alpha = 0x1f;
            }
        }
        if ((self->msg_flags & 0x80) && (h = self->unk_48) != NULL) {
            LFLD(B16_02195848, h, 0x9a).b0 = 1;
            LFLD(u16, h, 0x9a) |= 8;
            HitSphere_Link(h);
            func_ov000_021987b8(self->unk_48, 0, 0, 0);
        }
        break;
    }
    if (self->unk_58 != NULL && (self->unk_cc_1 || (self->msg_flags & 0x80))) {
        void *p;
        u16 rx;
        u16 ry;
        u16 rz;
        self->unk_cc_0 = 1;
        rz = self->rot_z;
        p = self->unk_58;
        ry = self->rot_y;
        rx = self->rot_x;
        RotZYX02195848(&m, &t, rx, ry, rz);
        m._30 = self->pos.x;
        m._31 = self->pos.y;
        m._32 = self->pos.z;
        HitMesh_SetMtx(p, &m);
    }
    h = self->unk_48;
    if (h == NULL) {
        return;
    }
    {
        s32 k = self->param->type;
        if (k == 3) {
            return;
        }
        if (self->unk_58 != NULL && self->unk_cc_0 && k != 1) {
            h->unk_9a_3 = 0;
            func_0203f364(h);
        }
    }
    if (!self->unk_cc_1) {
        self->unk_48->unk_9a_4 = 0;
        self->unk_93_0 = 1;
        return;
    }
    LFLD(u16, self->unk_48, 0x9a) |= 0x20;
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        if (PlayerIdle02195848()) {
            func_ov000_02198360(((u8 *)self->unk_40), 4, 0);
        }
        return;
    }
    if (self->unk_48->unk_50 & 0x40000) {
        return;
    }
    if (!PlayerIdle02195848()) {
        return;
    }
    self->unk_cc_1 = 0;
    self->unk_48->unk_9a_4 = 0;
}
}
