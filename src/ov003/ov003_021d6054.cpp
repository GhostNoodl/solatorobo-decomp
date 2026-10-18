#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003DtVec;

typedef struct {
    u16 state;
    u16 timer;
} Ov003DtWork;

typedef struct {
    u8 pad_00[4];
    void *mdl;
    u8 pad_08[0xb6];
    u8 alpha;
    u8 pad_bf[3];
    u16 unk_c2_0 : 9;
    u16 unk_c2_9 : 2;
} Ov003DtModel;

typedef struct {
    u8 pad_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003DtS44;

typedef struct {
    u8 pad_00[0x9a];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
} Ov003DtCtl;

typedef struct {
    u8 pad_00[6];
    u16 unk_06;
    u8 pad_08[0x14];
    u16 unk_1c;
} Ov003DtPart;

typedef struct {
    u16 unk_00;
    u8 pad_02[2];
    u16 unk_04;
} Ov003DtS50;

typedef struct {
    u8 pad_00[6];
    u16 unk_06;
} Ov003DtB0;

typedef struct {
    u8 pad_00[0x68];
    Ov003DtModel *unk_68[2];
} Ov003DtD0;

typedef struct {
    s16 sound;
    s16 unk_02;
    s16 unk_04;
    s16 fx;
    s16 scale;
    s16 unk_0a;
} Ov003DtEnt;

typedef struct {
    u8 pad_00[0xe];
    u16 unk_0e;
    u8 pad_10[0x28];
    Ov003DtModel *model;
    u8 pad_3c[4];
    Ov003DtWork *work;
    Ov003DtS44 *unk_44;
    Ov003DtCtl *unk_48;
    Ov003DtPart *unk_4c;
    Ov003DtS50 *unk_50;
    u8 pad_54[0x10];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov003DtVec pos;
    u16 rot[3];
    u8 pad_82[0x2e];
    Ov003DtB0 *unk_b0;
    u8 pad_b4[0x1c];
    Ov003DtD0 *unk_d0;
    u8 pad_d4[0x16];
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 3;
    u16 unk_ea_6 : 4;
    u16 unk_ea_10 : 1;
    u16 unk_ea_11 : 1;
    u16 unk_ea_12 : 1;
} Ov003Dt;

class Ov003DtFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    u8 pad_04[0x38];
    s32 unk_3c;
};

extern "C" {

extern void *data_02097e4c;
extern const Ov003DtEnt data_ov003_021f4648[];
extern char data_ov003_021f7a7f[];
extern void func_ov000_02190cb0(Ov003DtModel *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(Ov003DtModel *model);
extern void func_0203f364(Ov003DtCtl *c);
extern void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 on, u32 mask);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02049f44(void *mgr, s32 id, Ov003DtVec *pos, s32 a);
extern void func_ov000_0219b71c(Ov003DtVec *pos, Ov003DtVec *v, s32 a, s32 b, s32 c, s32 d);
extern Ov003DtFx *func_02065f88(s32 id, Ov003DtVec *pos);
extern u8 *func_02070558(u16 id);
extern void func_ov000_0219b400(u8 *a, u8 *b, s32 c, Ov003DtVec *pos, u16 *rot, s32 d);
extern void func_ov000_0219b5dc(u16 id, Ov003DtVec *pos, u16 *rot);
extern void func_ov003_021d6a3c(Ov003Dt *self, s32 a, s32 b, s32 c);

void func_ov003_021d6054(Ov003Dt *self) {
    u16 idx = self->unk_4c->unk_06;
    const Ov003DtEnt *e;
    Ov003DtVec v;
    if (idx >= 10) {
        idx = 0;
    }
    e = &data_ov003_021f4648[idx];
    switch (self->work->state) {
    case 0: {
        Ov003DtCtl *c;
        Ov003DtS44 *s;
        Ov003DtModel *m;
        self->unk_50->unk_00 = 0;
        if (!self->unk_ea_12) {
            func_ov000_02190cb0(self->model, data_ov003_021f7a7f, 0xcd, 0);
            func_ov000_021915a0(self->model);
        }
        c = self->unk_48;
        if (c != NULL) {
            c->unk_9a_0 = 0;
            c->unk_9a_3 = 0;
            func_0203f364(c);
        }
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
        }
        self->unk_4c->unk_1c = 0xffff;
        m = self->model;
        m->unk_c2_9 = 2;
        NNSi_G3dModifyPolygonAttrMask(m->mdl, 0, 0xc0);
        self->unk_ea_3 = 0;
        if (self->unk_ea_10) {
            self->work->state++;
            return;
        }
        func_ov000_0218996c(9, 0x14);
        self->work->state = 10;
        break;
    }
    case 1: {
        u16 t = self->work->timer;
        if (t >= 0x78) {
            func_ov000_0218996c(0x19, 0x78);
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x53, &self->pos, 0);
            self->work->state = 10;
            return;
        }
        if (t % 20 == 0) {
            Ov003DtVec r;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            v.y += self->unk_6c;
            r.x = self->unk_64;
            r.y = self->unk_68 >> 2;
            r.z = self->unk_64 + (self->unk_64 >> 2);
            func_ov000_0219b71c(&v, &r, 0x733, 0xccd, e->unk_02, 0x32);
            func_ov000_0218996c(8, 10);
            func_02049f44(data_02097e4c, 0x35, &v, 0);
        }
        self->work->timer++;
        break;
    }
    case 10: {
        u8 *res;
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += (self->unk_68 >> 1) - (self->unk_68 >> 3);
        if (e->fx != -1) {
            Ov003DtFx *fx = func_02065f88(e->fx, &v);
            s32 sc = e->scale << 4;
            if (sc == 0) {
                sc = self->unk_64;
                if (idx != 0) {
                    if (idx == 5) {
                        fx->unk_3c = 0xccd;
                        sc = (sc >> 1) + 0x3800;
                    }
                } else {
                    sc = sc + (sc >> 1);
                }
            }
            fx->SetScale(sc, sc, sc);
        }
        if (e->sound >= 0 && self->unk_50->unk_04 != 0xffff) {
            func_02049f44(data_02097e4c, e->sound, &v, 0);
        }
        res = func_02070558(self->unk_0e);
        func_ov000_0219b400(res + 0x3e, res + 0x42, 2, &v, self->rot, 1);
        func_ov000_0219b5dc(self->unk_b0->unk_06, &v, self->rot);
        self->work->timer = 0;
        self->work->state++;
        break;
    }
    case 11: {
        u16 lim = 0x3c;
        u8 a;
        u16 h;
        Ov003DtWork *w;
        if (self->unk_ea_10) {
            lim = 0x78;
        }
        w = self->work;
        w->timer++;
        if (w->timer > lim) {
            func_ov003_021d6a3c(self, 1, 1, 1);
            return;
        }
        h = self->work->timer >> 1;
        if (h > 0x1f) {
            h = 0x1f;
        }
        a = 0x1f - h;
        self->model->alpha = a;
        if (self->unk_d0 != NULL && self->unk_ea_3 != 0) {
            s32 i;
            for (i = 0; i < 2; i++) {
                Ov003DtModel *m = self->unk_d0->unk_68[i];
                if (m != NULL) {
                    m->alpha = a;
                }
            }
        }
        break;
    }
    }
}

}
