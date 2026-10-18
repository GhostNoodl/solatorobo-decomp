#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003SwVec;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003SwSub44;

typedef struct {
    u8 unk_00[2];
    u8 unk_02;
    u8 unk_03[5];
    u16 unk_08;
    u16 unk_0a;
    u8 unk_0c[0x10];
    u16 unk_1c;
} Ov003SwPart;

typedef struct {
    u16 state;
    u16 timer;
} Ov003SwWork;

typedef struct {
    u8 unk_00;
    u8 unk_01;
} Ov003SwInfo;

class Ov003Switch {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
    u8 unk_04[0x8];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
    u8 unk_1a[0x1e];
    void *model;
    u8 unk_3c[4];
    Ov003SwWork *work;
    Ov003SwSub44 *unk_44;
    u8 unk_48[4];
    Ov003SwPart *unk_4c;
    u8 unk_50[8];
    void *unk_58;
    u8 unk_5c[0x14];
    Ov003SwVec pos;
    u8 unk_7c[0x34];
    Ov003SwInfo *unk_b0;
    u8 unk_b4[0x18];
    u16 unk_cc_0 : 1;
};

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern char data_ov003_021f803c[];
extern void func_02049f44(void *mgr, s32 id, Ov003SwVec *pos, s32 a);
extern void func_ov000_02198360(Ov003SwWork *w, s32 a, s32 b);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 v);
extern BOOL func_ov000_02191120(void *model);
extern void func_0203f920(void *p);
extern Ov003SwPart *func_ov000_02199ba0(Ov003SwPart *p);
extern void func_ov000_0218d398(Ov003SwPart *p, u16 id, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);

static inline void Ov003SwSub44_Clear(Ov003SwSub44 *p) {
    p->unk_22_0 = 0;
    p->unk_22_1 = 0;
}

void func_ov003_021ddaa0(Ov003Switch *self) {
    switch (self->work->state) {
    case 0:
        if (self->unk_18 == 3) {
            if (self->unk_4c->unk_0a != 0xffff) {
                func_02049f44(data_02097e4c, self->unk_4c->unk_0a, &self->pos, 0);
            }
            self->unk_4c->unk_1c = 0xffff;
            func_ov000_02198360(self->work, 1, 0);
            return;
        }
        if (self->model != NULL) {
            u8 k = self->unk_b0->unk_01;
            s32 speed = 0x1000;
            s32 frame = 0x1000;
            if (k != 1 && k != 2) {
                speed = 0x89;
            }
            if (k != 2) {
                frame = 0x800;
            }
            func_ov000_02190cb0(self->model, data_ov003_021f803c, speed, 0);
            func_ov000_021911c8(self->model, frame);
        }
        if (self->unk_4c->unk_08 != 0xffff) {
            func_02049f44(data_02097e4c, self->unk_4c->unk_08, &self->pos, 0);
        }
        self->work->state++;
        break;
    case 1:
        if (self->model != NULL && !func_ov000_02191120(self->model)) {
            return;
        }
        self->unk_cc_0 = 0;
        if (self->unk_58 != NULL) {
            func_0203f920(self->unk_58);
        }
        Ov003SwSub44_Clear(self->unk_44);
        if (self->unk_4c->unk_02 != 6) {
            Ov003SwPart *p = func_ov000_02199ba0(self->unk_4c);
            if (p != NULL) {
                func_ov000_0218d398(p, self->unk_0c, 3, 1, 0, 0);
            }
            self->unk_4c->unk_1c = 0xffff;
        }
        if (self->unk_4c->unk_02 == 5) {
            func_ov000_02197dec(self, 0xf, -1);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->Destroy();
        }
        self->work->state++;
        break;
    }
}

}
