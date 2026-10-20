#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003HmVec;

typedef struct {
    u16 x, y, z;
} Ov003HmRot;

typedef struct {
    u16 state;
    u16 timer;
} Ov003HmWork;

typedef struct {
    u8 unk_00[0x30];
    u32 unk_30;
    u8 unk_34[0x1c];
    u32 flags;
    u8 unk_54[0x46];
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 1;
} Ov003HmAnim;

typedef struct {
    u8 unk_00[2];
    u16 mode : 3;
} Ov003HmB0;

typedef struct {
    u8 unk_00[0xe];
    u16 unk_0e;
} Ov003HmPart;

typedef struct {
    u8 unk_00[0x30];
    u32 unk_30;
} Ov003HmCfg;

typedef struct {
    u8 unk_00[0x6c];
    s32 height;
    Ov003HmVec pos;
} Ov003HmTarget;

class Ov003HmFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetScale(s32 s);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(Ov003HmRot *r);
    u8 unk_04[0x20];
    s32 unk_24;
};

typedef struct {
    u8 unk_00[0x1a];
    s16 unk_1a;
    u8 unk_1c[0x24];
    Ov003HmWork *work;
    void *unk_44;
    Ov003HmAnim *anim;
    void *unk_4c;
    u8 unk_50[0x20];
    Ov003HmVec pos;
    Ov003HmRot rot;
    u8 unk_82[0xe];
    u16 target;
    u8 unk_92[6];
    u16 dir;
    u8 unk_9a[2];
    Ov003HmVec vel;
    s32 unk_a8;
    u8 unk_ac[4];
    Ov003HmB0 *unk_b0;
    u8 unk_b4[8];
    s32 fxh;
    Ov003HmVec fxofs;
    u8 unk_cc[4];
    Ov003HmCfg *cfg;
    u8 unk_d4[4];
    u16 unk_d8;
    u16 trailTimer;
} Ov003Hm;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern const Ov003HmVec data_ov003_021f6bd8;
extern void *data_ov000_021ccd68;
extern Ov003HmPart *func_ov000_02199ba0(void *def);
extern Ov003HmTarget *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021db244(Ov003Hm *self);
extern void func_ov003_021dc0c8(Ov003Hm *self);
extern BOOL func_ov003_021dbd80(Ov003Hm *self);
extern void func_ov000_0218d918(Ov003Hm *self, Ov003HmVec *v, s32 a);
extern Ov003HmFx *func_02065f88(s32 id, Ov003HmVec *pos);
extern void func_01ffc9fc(Ov003HmVec *dst, const Ov003HmVec *src, u16 ry);
extern void func_0203f324(Ov003HmAnim *a);
extern void func_ov000_021987b8(Ov003HmAnim *a, s32 b, s32 c, s32 d);
extern void VEC_Normalize(Ov003HmVec *a, Ov003HmVec *b);
extern void VEC_Add(Ov003HmVec *a, Ov003HmVec *b, Ov003HmVec *dst);

#define HM_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define HM_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])
#define HM_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline Ov003HmTarget *Ov003Hm_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov003Hm_Show(Ov003HmAnim *a) {
    a->b0 = 1;
    a->b3 = 1;
    func_0203f324(a);
}

void func_ov003_021ed15c(Ov003Hm *self) {
    Ov003HmVec ofs = data_ov003_021f6bd8;
    Ov003HmTarget *t;
    s32 speed;
    if (func_ov000_02199ba0(self->unk_4c)->unk_0e == 0x1000) {
        if (self->work->state == 0) {
            self->anim->unk_30 = self->cfg->unk_30;
        }
        func_ov003_021db244(self);
        return;
    }
    t = Ov003Hm_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    speed = 0;
    switch (self->work->state) {
    case 0: {
        Ov003HmFx *e;
        func_ov003_021dc0c8(self);
        self->vel.x = 0;
        self->vel.y = 0;
        self->vel.z = 0;
        self->unk_a8 = 0;
        speed = 0x333;
        e = func_02065f88(0x324, &self->pos);
        func_01ffc9fc(&self->fxofs, &ofs, self->rot.y);
        e->SetScale(0x2333);
        self->fxh = e->unk_24;
        self->work->timer = 0;
        self->work->state++;
        break;
    }
    case 1: {
        Ov003HmWork *w = self->work;
        speed = 0x333;
        w->timer++;
        if (w->timer > 0xf) {
            speed = 0x2e1;
            self->vel.y = 0x29;
            self->work->timer = 0;
            self->work->state++;
        }
        break;
    }
    case 2: {
        Ov003HmWork *w = self->work;
        Ov003HmVec p;
        u16 timer;
        s32 turn;
        speed = 0x2e1;
        w->timer++;
        timer = w->timer;
        p = t->pos;
        p.y += t->height;
        turn = 0x11f;
        if (timer > 0x14) {
            Ov003HmVec d;
            d.x = p.x - self->pos.x;
            d.y = p.y - self->pos.y;
            d.z = p.z - self->pos.z;
            VEC_Normalize(&d, &d);
            d.y = HM_MUL(d.y, speed);
            self->vel.y += HM_MUL(d.y - self->vel.y, 0x9a);
            turn = 0xe1;
        }
        func_ov000_0218d918(self, &p, turn);
        self->dir = self->rot.y;
        if (timer > 0x64) {
            if (self->unk_1a == 0) {
                self->anim->unk_30 = 0xe0000000;
            }
            self->work->timer = 0;
            self->work->state++;
        }
        break;
    }
    case 3:
        speed = 0x333;
        if (self->anim != NULL && (self->anim->flags & 0x60000000)) {
            self->unk_d8 = 0x270f;
        }
        break;
    }
    self->vel.x = HM_MUL(speed, HM_SIN(self->dir));
    self->vel.z = HM_MUL(speed, HM_COS(self->dir));
    VEC_Add(&self->pos, &self->vel, &self->pos);
    self->trailTimer++;
    if (self->trailTimer > 0xf) {
        self->trailTimer = 0;
        func_02065f88(0x12d, &self->pos)->SetRot(&self->rot);
    }
    if (self->fxh != -1) {
        func_01ffc9fc(&self->fxofs, &ofs, self->rot.y);
    }
    if (self->anim != NULL) {
        if (!(self->unk_b0->mode & 2)) {
            Ov003Hm_Show(self->anim);
        }
        func_ov000_021987b8(self->anim, 0, 0, 0);
    }
    func_ov003_021dbd80(self);
}

}
