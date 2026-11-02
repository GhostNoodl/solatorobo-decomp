#include "types.h"
#include "Main/Sys/FieldState.h"

typedef struct {
    u16 x, y, z;
} Ov003BmRot;

class Ov003BmFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    u8 unk_04[0x38];
    s32 unk_3c;
};

class Ov003Bomb {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
    u8 unk_04[0xa];
    u16 unk_0e;
    u8 unk_10[0xa];
    s16 unk_1a;
    u8 unk_1c[0x24];
    u16 *work;
    u8 unk_44[0x2c];
    VecFx32 pos;
    Ov003BmRot rot;
};

typedef struct {
    u8 unk_00[0x20];
    u8 unk_20[4];
    u8 unk_24[4];
} Ov003BmInfo;

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern u16 Camera_GetYaw(Camera *cam);
extern void func_01ffc9fc(VecFx32 *src, VecFx32 *dst, u16 angle);
extern Ov003BmFx *func_02065f88(s32 id, const VecFx32 *pos);
extern void *func_0204a028(void *mgr, s32 id, VecFx32 *pos, s32 a);
extern void *func_02049f44(void *mgr, s32 id, VecFx32 *pos, s32 a);
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern Ov003BmInfo *func_020704b4(u16 id);
extern void func_ov000_0219b400(void *a, void *b, s32 c, VecFx32 *pos, Ov003BmRot *rot, s32 d);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *sc, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);

static inline u16 Camera_GetAngle(Camera *cam) {
    return cam->mode != 0 ? cam->yaw : Camera_GetYaw(cam);
}

void func_ov003_021de778(Ov003Bomb *self) {
    switch (self->work[0]) {
    case 0:
        if (self->unk_1a == 0) {
            VecFx32 v;
            Ov003BmFx *fx;
            Camera *cam = &data_ov000_021ccd54->cam.base;
            v.x = -0x2000;
            v.y = 0;
            v.z = 0x5000;
            func_01ffc9fc(&v, &v, Camera_GetAngle(cam) + 0x8000);
            VEC_Add(&v, &self->pos, &v);
            fx = func_02065f88(5, &v);
            fx->SetScale(0x7800, 0x7800, 0x7800);
            fx->unk_3c = 0xccd;
            fx = func_02065f88(0x6d, &v);
            fx->SetScale(0x3000, 0x3000, 0x3000);
            fx->unk_3c = 0x333;
            cam->shakeX = 1;
            cam->shakeY = 1;
            cam->shakeZ = 1;
            cam->shakeTime = 0x19;
            cam->shakeLen = 0x32;
            cam->shakeCur = 0x32;
            func_0204a028(data_02097e4c, 0x79, &self->pos, -0xf);
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        }
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4030, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4031, 0x15);
        self->work[1] = 1;
        self->work[0]++;
        break;
    case 1:
        if (self->work[1] >= 0x120) {
            Ov003BmInfo *inf = func_020704b4(self->unk_0e);
            func_ov000_0219b400(inf->unk_20, inf->unk_24, 2, &self->pos, &self->rot, 0);
            func_ov000_02197dec(self, 0xf, 4);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->Destroy();
            return;
        }
        if ((self->work[1] & 0xf) == 0) {
            VecFx32 sc;
            s32 a = -1;
            s32 b = 100;
            switch (self->work[1] & 0x3f) {
            case 0:
                a = 1;
                break;
            case 0x10:
                break;
            case 0x20:
                a = 3;
                break;
            case 0x30:
                a = 3;
                b = 25;
                break;
            }
            sc.x = 0x5000;
            sc.y = 0x3000;
            sc.z = 0x3800;
            func_ov000_0219b71c(&self->pos, &sc, 0x1000, 0x2800, a, b);
            func_ov000_0218996c(0xf, 0x1e);
        }
        self->work[1]++;
        break;
    }
}

}
