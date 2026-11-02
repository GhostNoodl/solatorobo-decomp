#include "ov000/LoCommon.h"
#include "ov000/ModelViewer.h"

extern "C" {

int STD_CopyLString(void *dst, const void *src, s32 n);

void ModelViewer_SetModel(ModelViewer *self, const void *s0, const void *s1, const void *s2, const void *s3, s32 d, s32 e, s16 f) {
    STD_CopyLString(self->res.mdlArc, s0, sizeof(self->res.mdlArc));
    STD_CopyLString(self->res.mdlName, s1, sizeof(self->res.mdlName));
    STD_CopyLString(self->res.anmArc, s2, sizeof(self->res.anmArc));
    STD_CopyLString(self->res.anmName, s3, sizeof(self->res.anmName));
    self->res.useMdlForB = e != 0 ? TRUE : FALSE;
    self->res.reload = 1;
    self->request = 1;
    self->anim = (const char *)d;
    self->frame = e;
    self->speed = f;
}

}

#include "ov000/Vec.h"

extern "C" {

void ResSet_SetName0(void *p, s32 a, s32 b, s32 c, s32 d);
void ResSet_SetName1(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02161fac(ModelViewerRes *res);
BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_SetAnim(void *a, const char *b, s32 c, s32 d);
void Model0218fe1c_SetAnimSpeed(void *a, s32 b);
void Model0218fe1c_SetLoop(void *a);
void func_ov000_02191870(void *a, void *b);
AnimCtrl *Model0218fe1c_GetAnimCtrl(void *a, s32 b);
void func_ov000_02191920(void *a, s32 b, s32 c, s32 d);
BOOL Interp_MoveTo(void *out, s32 speed, const void *from, const void *to, s32 minDist);
void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);

static inline void StopSlot(ModelViewerRes *res, u8 i) {
    if (i > 2) {
        return;
    }
    ActorRes *a = res->a;
    ActorRes *b = res->b;
    ResSet_SetName0(&a[i], 0, 0, 1, 0);
    ResSet_SetName1(&a[i], 0, 0, 1, 0);
    a[i].unk_00 = 0;
    ResSet_SetName1(&b[i], 0, 0, 1, 0);
    b[i].unk_00 = 0;
}


void func_ov000_02162bd4(ModelViewer *self) {
    switch (self->state) {
    case 0:
        if (self->request) {
            self->state = 10;
            self->request = 0;
        }
        break;
    case 10:
        self->model.visible = 0;
        StopSlot(&self->res, self->res.cur);
        self->state++;
        break;
    case 11: {
        AnimCtrl *ctrl;

        func_ov000_02161fac(&self->res);
        if (self->res.state != 20) {
            break;
        }
        self->res.cur ^= 1;
        Model0218fe1c_SetRes(&self->model, &self->res.a[self->res.cur], 0, 1);
        self->model.unk_c2_6 = 1;
        Model0218fe1c_SetAnim(&self->model, self->anim, 0x1000, 0);
        Model0218fe1c_SetAnimSpeed(&self->model, self->speed);
        Model0218fe1c_SetLoop(&self->model);
        self->model.boxTest = 0;
        self->model.visible = 0;
        if (LFLD(void *, &self->res.b[self->res.cur], 0x48) != NULL &&
            LFLD(s32, LFLD(void *, &self->res.b[self->res.cur], 0x48), 0xc) != 0) {
            func_ov000_02191870(&self->model, &self->res.b[self->res.cur]);
            ctrl = Model0218fe1c_GetAnimCtrl(&self->model, 3);
            if (ctrl != NULL) {
                s32 v;
                float f;
                s32 frame;
                func_ov000_02191920(&self->model, 0, 0x1000, 0);
                v = self->frame;
                if (v > 0) {
                    f = (float)(v << 12) + 0.5f;
                } else {
                    f = (float)(v << 12) - 0.5f;
                }
                frame = (s32)f;
                if (ctrl->cur != NULL) {
                    if (frame >= 0) {
                        ctrl->cur->frame = frame;
                    } else {
                        ctrl->cur->frame = (LFLD(u16, ctrl->cur->res, 4) << 12) - 1;
                    }
                }
                ctrl->paused = 1;
            }
        } else {
            func_ov000_02191870(&self->model, &self->res.a[self->res.cur]);
        }
        self->state = 0x14;
        self->request = 0;
    }
    case 20:
        self->timer = 0xc;
        self->pos = self->unk_6ec;
        self->state++;
    case 21:
        if (self->timer != 0) {
            if (self->request) {
                self->state = 10;
                self->request = 0;
            }
            self->timer--;
            break;
        }
        self->model.visible = 1;
        if (Interp_MoveTo(&self->pos, 0x266, &self->pos, &self->home, 0xcd)) {
            self->state++;
        }
        break;
    case 22:
        self->pos = self->home;
        if (self->request) {
            self->state = 0x1e;
            self->request = 0;
        }
        break;
    case 30: {
        VecFx32 d;
        d.x = self->unk_6f8.x - self->home.x;
        d.y = self->unk_6f8.y - self->home.y;
        d.z = self->unk_6f8.z - self->home.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0xcd, &d, &self->home, &self->pos);
        self->state++;
        break;
    }
    case 31: {
        VecFx32 d;
        d.x = self->pos.x - self->home.x;
        d.y = self->pos.y - self->home.y;
        d.z = self->pos.z - self->home.z;
        VEC_MultAdd(0x14cd, &d, &self->home, &self->pos);
        if ((s32)(((s64)d.x * (self->unk_6f8.x - self->pos.x) + (s64)d.y * (self->unk_6f8.y - self->pos.y) + (s64)d.z * (self->unk_6f8.z - self->pos.z) + 0x800) >> 12) <= 0) {
            self->state = 10;
        }
        break;
    }
    case 40: {
        VecFx32 d;
        d.x = self->unk_6f8.x - self->home.x;
        d.y = self->unk_6f8.y - self->home.y;
        d.z = self->unk_6f8.z - self->home.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0xcd, &d, &self->home, &self->pos);
        self->state++;
        break;
    }
    case 41: {
        VecFx32 d;
        d.x = self->pos.x - self->home.x;
        d.y = self->pos.y - self->home.y;
        d.z = self->pos.z - self->home.z;
        VEC_MultAdd(0x14cd, &d, &self->home, &self->pos);
        if ((s32)(((s64)d.x * (self->unk_6f8.x - self->pos.x) + (s64)d.y * (self->unk_6f8.y - self->pos.y) + (s64)d.z * (self->unk_6f8.z - self->pos.z) + 0x800) >> 12) > 0) {
            break;
        }
        self->model.visible = 0;
        self->state++;
        break;
    }
    case 42: // empty case; moves the compare-tree pivot to 30
        break;
    }
}

}
