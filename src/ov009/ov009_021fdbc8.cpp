#include "ov009/ov009.h"
#include "ov000/FieldCam.h"

extern "C" {

extern Ov003Actor *func_ov000_0219bf90(void);
void Ov009ActVt_022165f8_Start(Ov009ActVt_022165f8 *self) {
    Ov003Actor_Start(self);
    switch (self->unk_1a) {
    case 0: {
        FieldCam *g = &data_ov000_021ccd54->cam;
        u16 a = FieldCam_GetYaw(g) + Rand_PlusMinus(0x1000);
        s32 r = Rand_PlusMinus(0x1800) + 0x3800;
        self->pos = g->base.at;
        self->pos.x += FX_Mul(r, OV009_SIN(a));
        self->pos.z += FX_Mul(r, OV009_COS(a));
        self->pos.y += 0xa000;
        break;
    }
    case 1:
        self->velY = 0x466;
        func_ov000_02198360(self->fsm, 0x20, 0);
        break;
    case 2: {
        Ov003Actor *t = func_ov000_0219bf90();
        if (t != NULL) {
            u16 r = t->rot_y;
            u16 a = r + Rand_PlusMinus(0x1000);
            s64 k = 0x333;
            self->pos.x = t->pos.x;
            self->pos.y = t->pos.y;
            self->pos.z = t->pos.z;
            self->speed = (s32)((OV009_SIN(a) * k + 0x800) >> 12);
            self->friction = (s32)((OV009_COS(a) * k + 0x800) >> 12);
            self->velY = 0x266;
            VEC_MultAdd(0x28000, (VecFx32 *)&self->speed, &self->pos, &self->pos);
        }
        func_ov000_02198360(self->fsm, 0x20, 0);
        break;
    }
    }
    self->unk_f4 = self->kind;
    switch (self->kind) {
    case 0x5013:
        self->unk_f2 = 0x12c;
        break;
    case 0x5045:
        self->unk_f2 = 0xc8;
        break;
    }
    if (data_ov000_021ccd54->unk_ca.c[0] == 2) {
        self->unk_18 = 1;
    }
    self->unk_f8 = 0;
    self->unk_ea_6 = 1;
}



void Ov009ActVt_022165f8_Update(Ov009ActVt_022165f8 *self) {
    VecFx32 t;
    Robo021ca458 *pl;
    self->unk_93_4 = 0;
    if (*self->hp == 0) {
        return;
    }
    pl = (Robo021ca458 *)func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    self->target = pl->id;
    switch (self->unk_b4) {
    case 0: {
        BOOL blocked = FALSE;
        BOOL go = FALSE;
        s32 ang;
        u16 a;
        u16 d;
        u16 r;
        s32 dist;
        self->unk_f0 = 0;
        if (pl->unk_b22_0 != 3 && pl->unk_b22_0 != 4) {
            self->unk_f0 = 1;
            if (pl->hit != NULL && (pl->hit->unk_50 & 0x20000000)) {
                if (Ov009_GameIdle()) {
                    go = TRUE;
                } else {
                    blocked = TRUE;
                }
            }
            if (!blocked) {
                self->unk_93_4 = 1;
            }
        }
        if (go) {
            self->unk_b6++;
            if (self->unk_b6 > self->unk_f2) {
                self->fsm->flags |= 0x8000;
                self->unk_b4++;
            }
        } else {
            self->unk_b6 = 0;
        }
        {
            FieldCam *g = &data_ov000_021ccd54->cam;
            t = pl->pos;
            t.y += 0x1400;
            ang = FieldCam_GetYaw(g);
        }
        if (blocked) {
            ang = pl->rot_y;
        }
        a = FX_Atan2(self->pos.x - t.x, self->pos.z - t.z);
        d = a - ang;
        if (d < 0x8000) {
            if (d > 0x1100) {
                r = ang + 0x1100;
            } else {
                r = 0;
            }
        } else {
            if (d < 0xef00) {
                r = ang - 0x1100;
            } else {
                r = 0;
            }
        }
        if (r != 0) {
            a = func_01ffc128(r, a, 0x400, 1, 0x8000);
        }
        dist = 0x6800;
        if (self->unk_f0 != 0 && !blocked) {
            dist = 0x2800;
        }
        t.x += FX_Mul(dist, OV009_SIN(a));
        t.z += FX_Mul(dist, OV009_COS(a));
        if (!Hit_DiffInSphere(&self->pos, &t, self->radius + 0x400)) {
            self->fsm->flags |= 4;
            self->unk_b8 = t;
        }
        break;
    }
    case 1:
        if (Ov009_GameIdle()) {
            self->unk_93_4 = 1;
            if (self->fsm->current != 0xf) {
                self->unk_b6 = Rand_UpTo(0x3c);
                self->unk_b4 = 0;
            }
        }
        break;
    }
    if (self->fsm->current == 0xf) {
        return;
    }
    if (self->unk_f8 != 0) {
        EffectMgr_Kill(data_0214a420, self->unk_f8);
        self->unk_f8 = 0;
    }
    if (self->rot_x == 0) {
        return;
    }
    self->rot_x = func_01ffc128(0, self->rot_x, 0x19a, 1, 0x8000);
}

}
