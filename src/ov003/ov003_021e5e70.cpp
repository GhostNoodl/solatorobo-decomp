#include "ov003/GmObj.h"

class Ov003Bar {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();

    u8 unk_04[8];
    u32 flags;
    u8 unk_10[0xc];
    s32 unk_1c;
    u8 unk_20[0x28];
    u16 unk_48;
    u8 unk_4a[0xa];
    s32 unk_54;
    u8 unk_58[0x10];
    s16 unk_68;
};

typedef struct {
    s32 m[9];
} Ov003BarMtx;

typedef struct {
    u8 unk_00[0x16];
    u16 unk_16;
} Ov003BarSnd;

typedef struct {
    u8 unk_00[0x48];
    struct {
        u8 unk_00[4];
        void *unk_04;
    } *unk_48;
} Ov003BarHdr;

extern "C" {

extern int data_02097d78[];
extern void *data_ov000_021cac60[];
extern void *data_ov000_021cad50[];
extern void *data_02149ef8;
extern void *data_ov000_021ccd68;
extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003Vec3 data_02092a50;
extern void *func_0203dd9c(u32 size);
extern const char *func_0204c0e8(void *mgr, s32 id);
extern void func_ov000_0215c1bc(void *a, s32 b, const char *c);
extern void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);
extern Ov003BarSnd *func_ov000_0218e4cc(void *mgr, u16 id);
extern BOOL func_ov000_0218fb64(Ov003Anim *self, void *obj, void *tex, void *file, s32 index, s16 blend, u8 force);
extern Ov003BarMtx *NNS_G3dGlbGetInvV(void);
extern void VEC_Add(Ov003Vec3 *a, Ov003Vec3 *b, Ov003Vec3 *dst);

static inline BOOL Ov003Bar_FadeIdle(void) {
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline void Ov003Bar_Init(Ov003Bar *b) {
    b->flags |= 8;
    b->unk_48 = 0x14a5;
    b->unk_54 = 0x1c;
}

void func_ov003_021e5e70(Ov003Obj *self) {
    if (self->unk_20c != 0) {
        Ov003Bar *b;
        if (!Ov003Bar_FadeIdle()) {
            return;
        }
        if (self->unk_210 == 0) {
            b = (Ov003Bar *)func_0203dd9c(0xe8);
            if (b != NULL) {
                *(void ***)b = data_ov000_021cac60;
                b->v28();
                *(void ***)b = data_ov000_021cad50;
                b->v28();
            }
            self->unk_210 = (s32)b;
            b->flags |= 0x10000;
            Ov003Bar_Init((Ov003Bar *)self->unk_210);
            ((Ov003Bar *)self->unk_210)->flags |= 0x20000;
            ((Ov003Bar *)self->unk_210)->unk_1c = 4;
            ((Ov003Bar *)self->unk_210)->v08();
            func_ov000_0215c1bc((Ov003Bar *)self->unk_210, 0x8000, func_0204c0e8(data_02149ef8, 0x76));
            ((Ov003Bar *)self->unk_210)->unk_68 = -0x299a;
            ((Ov003Bar *)self->unk_210)->v70();
            func_ov000_02188140(data_ov000_021ccd54, 0xffff, 0, 0);
        } else {
            ((Ov003Bar *)self->unk_210)->v1c();
            ((Ov003Bar *)self->unk_210)->v20();
        }
        return;
    }
    switch (self->work->state) {
    case 0:
        if (self->unk_1e == 0) {
            Ov003BarSnd *s;
            Ov003Sub44 *p;
            if (self->unk_44 == NULL) {
                return;
            }
            s = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
            if (s == NULL) {
                return;
            }
            p = self->unk_44;
            if (s->unk_16 != 0) {
                p->unk_22_0 = 0;
                p->unk_22_1 = 0;
                return;
            }
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
            return;
        }
        if (self->unk_1e == 2) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0x8cd;
        } else {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0x59a;
        }
        self->work->state = 10;
    case 10: {
        s32 z = self->unk_8c;
        Ov003BarMtx *m;
        s32 x;
        s32 y;
        if (z < 0x2800) {
        if (z > -0x1800) {
            self->model->unk_be = ((0x2800 - z) * 31) / 0x4000;
            Ov003Model_ResetAnim(self->model);
        } else if (z < -0xf000) {
            self->model->unk_be = ((z + 0x14000) * 31) / 0x5000;
            Ov003Model_ResetAnim(self->model);
        } else {
            Ov003Model *md = self->model;
            if (md->unk_10 != NULL) {
                func_ov000_0218fb64(md->unk_10, md->unk_24, *(void **)(md->unk_04 + 4), ((Ov003BarHdr *)md->unk_00)->unk_48->unk_04, 0, 0x1000, 0);
            }
        }
        VEC_Add((Ov003Vec3 *)&self->unk_84, (Ov003Vec3 *)&self->unk_9c, (Ov003Vec3 *)&self->unk_84);
        m = NNS_G3dGlbGetInvV();
        y = self->unk_88;
        x = self->unk_84;
        z = self->unk_8c;
        self->pos.x = (s32)(((s64)x * m->m[0] + (s64)y * m->m[3] + (s64)z * m->m[6]) >> 12);
        self->pos.y = (s32)(((s64)x * m->m[1] + (s64)y * m->m[4] + (s64)z * m->m[7]) >> 12);
        self->pos.z = (s32)(((s64)x * m->m[2] + (s64)y * m->m[5] + (s64)z * m->m[8]) >> 12);
        VEC_Add(&self->pos, &data_02092a50, &self->pos);
        } else {
            Ov003Obj_Destroy(self);
        }
        break;
    }
    }
}

}
