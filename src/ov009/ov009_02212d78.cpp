#include "ov009/ov009.h"

extern "C" {

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void HitMesh_SetMtx(void *mesh, const void *mtx);
struct Ov009AngSrc2 {
    u8 unk_00[4];
    s32 x;
    u8 unk_08[4];
    s32 z;
    u8 unk_10[0x30];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
};

extern u16 Camera_GetYaw(Ov009AngSrc2 *p);
extern void func_ov000_0216912c(void *o, u16 id, s32 a, u16 b, u16 c, const VecFx32 *pos);

struct Ov009EaBits {
    u16 b0 : 13;
    u16 b13 : 1;
    u16 b14 : 2;
};

struct Ov009Notifier {
    u8 unk_00[0x60];
    void *unk_60;
};

static inline s32 Ov009_GetAng2(Ov009AngSrc2 *p) {
    if (p->unk_40 != 0) {
        return p->unk_44;
    }
    return Camera_GetYaw(p);
}

static inline void Ov009_Notify(u16 id, u16 b, u16 c, const VecFx32 *pos) {
    Ov009Notifier *o = FLD(Ov009Notifier *, data_ov000_021ccd30, 0x11c);
    void *q;
    if (o != NULL && (q = o->unk_60) != NULL) {
        func_ov000_0216912c(q, id, 0, b, c, pos);
    }
}

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Ov009_Mode(Ov003Actor *a) {
    return a->fsm != NULL ? a->fsm->current : 0;
}

struct Ov009PosMsg {
    VecFx32 pos;
    u16 rot[3];
    u32 unk_14;
};

extern void HitMesh_Link(void *mesh);
extern void func_0203f920(void *mesh);

struct Ov009Bit84 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void func_ov009_02212d78(Ov009ActVt_02217d5c *self) {
    Ov009PosMsg msg;
    Ov003Actor *a;
    if (FLD(Ov009EaBits, self, 0xea).b13) {
        Ov009AngSrc2 *p = (Ov009AngSrc2 *)((u8 *)data_ov000_021ccd54 + 0xf4);
        s32 px = p->x;
        s32 pz = p->z;
        s32 ang = Ov009_GetAng2(p);
        if ((u16)(FX_Atan2(self->unk_11c.x - px, self->unk_11c.z - pz) - ang + 0x4000) <= 0x8000 &&
            self->unk_ea_6 != 1) {
            self->unk_ea_6 = 1;
            Ov009_Notify(self->id, self->hp[0], self->hp[1], &self->unk_11c);
        }
    }
    func_ov003_021d3008(self);
    if (self->hitMesh != NULL) {
        HitMesh_SetMtx(self->hitMesh, &self->unk_f8);
        if (self->unk_93_4) {
            if (FLD(Ov009Bit84, self->hitMesh, 0x84).b0 != 1) {
                HitMesh_Link(self->hitMesh);
            }
        } else {
            if (FLD(Ov009Bit84, self->hitMesh, 0x84).b0) {
                func_0203f920(self->hitMesh);
            }
        }
    }
    a = Ov009_FindActor(self->unk_f0);
    if (a == NULL) {
        return;
    }
    msg.pos = self->unk_11c;
    {
        u16 x = a->rot_x;
        u16 y = a->rot_y;
        u16 z = a->rot_z;
        msg.rot[0] = x;
        msg.rot[1] = y;
        msg.rot[2] = z;
    }
    Actor_SendMsg(a, self->id, 7, TRUE, 0x18, &msg);
}

}
