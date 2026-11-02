#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 pad[0x258];
    VecFx32 camPos;
} Glb0219cbf8;

extern "C" {
extern Glb0219cbf8 NNS_G3dGlb;
extern u8 *data_ov000_021ccd6c;
void func_ov000_021bd300(void *p);
void func_ov000_021bd438(void *p, VecFx32 *v, s32 dy);
void func_ov000_02198d28(void *body, VecFx32 *pos, u32 angle);

void func_ov000_0219cbf8(Robo021ca458 *self, VecFx32 *pos, u16 *rot) {
    self->pos.x = pos->x;
    self->pos.y = pos->y;
    self->pos.z = pos->z;
    if (self->unk_b22_6 != 5) {
        LFLD(VecFx32, self, 0xaf0).x = pos->x;
        LFLD(VecFx32, self, 0xaf0).y = pos->y;
        LFLD(VecFx32, self, 0xaf0).z = pos->z;
    } else {
        LFLD(VecFx32, self, 0xaf0).x = self->pos.x - NNS_G3dGlb.camPos.x;
        LFLD(VecFx32, self, 0xaf0).y = self->pos.y - NNS_G3dGlb.camPos.y;
        LFLD(VecFx32, self, 0xaf0).z = self->pos.z - NNS_G3dGlb.camPos.z;
    }
    LFLD(VecFx32, self, 0xafc).x = LFLD(VecFx32, self, 0xaf0).x;
    LFLD(VecFx32, self, 0xafc).y = LFLD(VecFx32, self, 0xaf0).y;
    LFLD(VecFx32, self, 0xafc).z = LFLD(VecFx32, self, 0xaf0).z;
    {
        u16 ry;
        self->rot_x = rot[0];
        self->rot_y = ry = rot[1];
        self->rot_z = rot[2];
        self->unk_98 = ry;
    }
    if (LBIT(self, 0xb24).b1) {
        self->unk_75c.x = self->pos.x;
        self->unk_75c.y = self->pos.y;
        self->unk_75c.z = self->pos.z;
        self->unk_76c = self->rot_x;
        self->unk_76e = self->rot_y;
        self->unk_770 = self->rot_z;
    }
    if (self->unk_5c != NULL) {
        func_ov000_021bd300(self->unk_5c);
        func_ov000_021bd438(self->unk_5c, &self->pos, 0);
    }
    if (self->unk_9b0 != NULL) {
        func_ov000_021bd300(self->unk_9b0);
        func_ov000_021bd438(self->unk_9b0, &self->unk_75c, 0);
    }
    func_ov000_02198d28((u8 *)self + 0x2cc, &self->pos, self->rot_y);
    self->unk_31c = 0;
    self->unk_320 = 0;
    self->unk_324 = 0;
    func_ov000_02198d28((u8 *)self + 0x6c0, &self->unk_75c, self->unk_76e);
    self->unk_710 = 0;
    self->unk_714 = 0;
    self->unk_718 = 0;
    self->vfunc_44();
    LBIT(self, 0xb24).b20 = 0;
    if (data_ov000_021ccd6c[9] == 0xff) {
        self->unk_b22_13 = 1;
    }
}
}


typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} H1_0219cdb8;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} C1_0219cdb8;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern u8 *data_ov000_021ccd30;
extern u8 *data_ov000_021ccd6c;
extern void *data_02097e4c;
Actor *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_02191008(void *p);
void func_02049bb4(void *mgr, s32 id);
void func_ov000_021697dc(void *p, u16 a, u16 b);
void func_ov000_0218ec60(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218edf0(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218ef10(void *p, s32 a, s32 b, s32 c, s32 d);
void *NNS_G3dGetMdlSet(void *file);
void NNS_G3dReleaseMdlSet(void *mdl);

static inline Actor *GetObj0219cdb8(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Reset0219cdb8(Robo021ca458 *self) {
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_5 = 0;
    self->unk_b24_7 = self->unk_b24_9;
}

void func_ov000_0219cdb8(Robo021ca458 *self) {
    if (self->unk_b24_12 == 3) {
        Actor *o = GetObj0219cdb8(self->unk_b20);
        if (o != NULL) {
            o->flags_0 = 1;
        }
        self->unk_b20 = 0xffff;
        self->rot_x = 0;
        self->unk_b24_12 = 0;
    }
    if (self->unk_b24_5 != 0) {
        Actor *o = GetObj0219cdb8(self->unk_b1c);
        u8 *p = NULL;
        if (o != NULL) {
            p = ((u8 *)o->unk_4c);
        }
        if (p == NULL || LFLD(u16, p, 0x1c) != self->id) {
            if (p != NULL) {
                LFLD(u16, p, 0x1c) = 0xffff;
            }
            Reset0219cdb8(self);
        }
    }
    self->target = 0xffff;
    self->unk_b2f = 0;
    self->unk_b24_2 = 0;
    if (self->unk_b22_0 != 0) {
        if (self->unk_998 != NULL) {
            func_ov000_02191008(self->unk_998);
        }
        if (self->unk_b64 >= 0) {
            func_02049bb4(data_02097e4c, self->unk_b64);
            self->unk_b64 = -1;
        }
        if (self->unk_b22_0 > 1) {
            self->unk_b22_0 = 1;
            self->rot_x = 0;
            self->rot_z = 0;
            self->unk_9a6 = 0;
            self->unk_9a8 = 0;
            self->unk_9aa = 0;
            self->unk_9a0 = 0;
            self->unk_9a2 = 0;
            self->unk_9a4 = 0;
        }
    }
    self->unk_b32 = 0;
    self->unk_bac = 0xffff;
    self->unk_93_0 = 0;
    self->unk_b36 = 0;
    self->unk_b38 = 0;
    self->unk_b2c_4 = 0;
    {
        u16 *v = ((u16 *)self->unk_54);
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
    }
    if (data_ov000_021ccd54[0xc9] != 0) {
        u16 *w = self->hp;
        u8 *a;
        u16 v;
        w[0] = v = w[1];
        a = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
        if (a != NULL && LFLD(u8 *, a, 0x58) != NULL) {
            func_ov000_021697dc(LFLD(u8 *, a, 0x58), v, v);
            LFLD(u32, LFLD(u8 *, a, 0x58), 0xc) |= 0x80;
        }
        LFLD(u16, self->hp, 0xa) = 0;
        Reset0219cdb8(self);
    }
    {
        u8 *a = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
        u8 *m = a != NULL ? LFLD(u8 *, a, 0x58) : NULL;
        if (m != NULL) {
            LFLD(s32, m, 0x5c) = LFLD(s32, m, 0x64);
            LFLD(s32, m, 0x68) = LFLD(s32, m, 0x64);
        }
    }
    if (self->unk_b22_12) {
        u8 *c = data_ov000_021ccd54;
        if (c[0xca] != c[0xd0] || c[0xcb] != c[0xd1]) {
            s32 *t;
            void **res;
            self->unk_b22_12 = 0;
            self->unk_42a_0 = 0;
            t = ((s32 *)self->unk_ba0);
            func_ov000_02191008((u8 *)self + 0x368);
            if ((u8 *)self->unk_998 != NULL) {
                LFLD(H1_0219cdb8, self->unk_998, 0xc2).b0 = 0;
            }
            self->unk_16e_0 = 0;
            res = LFLD(void **, self->unk_ac, 0xc);
            NNS_G3dReleaseMdlSet(NNS_G3dGetMdlSet(res != NULL ? *res : NULL));
            func_ov000_0218ec60((u8 *)self + 0x450, t[0], t[1], 1, 1);
            func_ov000_0218edf0((u8 *)self + 0x450, t[2], t[3], 1, 1);
            func_ov000_0218ef10((u8 *)self + 0x450, t[4], t[5], 1, 1);
            if (LFLD(u8, t, 0x18) != 0) {
                func_ov000_0218edf0((u8 *)self + 0x588, t[0], t[1], 1, 1);
            }
            self->unk_b22_11 = 1;
        }
    }
    if (data_ov000_021ccd6c[0xb] == 0xff) {
        self->unk_b22_13 = 1;
    }
}
}
