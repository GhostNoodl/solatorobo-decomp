#include "ov000/Vec.h"
#include "Main/Sys/SysState.h"
#include "ov000/Model0218fe1c.h"
#include "ov000/ObjLayouts.h"
#include "Main/Res/StageFlags.h"

extern "C" {
extern char data_ov000_021cc5e3[];
extern char data_ov000_021cc5e9[];
extern char data_ov000_021cc5ef[];
extern char data_ov000_021cc5f6[];
extern char data_ov000_021cc5fd[];
extern char data_ov000_021cc605[];
extern char data_ov000_021cc60a[];
s16 *func_ov003_021ce630(s16 *p, void *hit);
void *Heap_Alloc(u32 size);
ResMdlSet *NNS_G3dGetMdlSet(void *file);
BOOL NNS_G3dBindMdlSet(ResMdlSet *set, void *tex);
BOOL Model0218fe1c_SetRes(Model0218fe1c *self, void *res, u8 mode, s32 e);
Model0218fe1c *Model0218fe1c_Init(Model0218fe1c *self);
BOOL Model0218fe1c_SetAnim(Model0218fe1c *self, const char *name, s32 blend, s32 force);
void Model0218fe1c_SetLoop(Model0218fe1c *self);
void Model0218fe1c_BindAnim3Res(Model0218fe1c *self, void *p);
AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
void Model0218fe1c_SetAnim3(Model0218fe1c *self, s32 index, s16 blend, u8 force);
void Model0218fe1c_UpdateAnim(Model0218fe1c *self, s32 a);
s32 Model_FindResIdxByName(Model0218fe1c *self, void *p, const char *name);

void func_ov000_0219c8e0(Robo021ca458 *self) {
    AnimEventTable *tbl;
    u8 *base;
    const char *name;
    Model0218fe1c_SetRes(&self->mdl1, &self->res1, 0, 1);
    self->mdl1.actor_id = self->id;
    tbl = self->res1.unk_c0 != NULL ? (AnimEventTable *)((u8 *)*self->res1.unk_c0 + 8) : NULL;
    self->mdl1.evTable = tbl;
    if (tbl != NULL) {
        if (tbl->is_ptr == 0) {
            self->mdl1.evData = (s16 *)&tbl->entries[tbl->count];
        }
    }
    self->mdl1.evFunc = (void *)func_ov003_021ce630;
    {
        const char *nm = data_ov000_021cc5e3;
        if (!self->unk_b24_1) {
            nm = data_ov000_021cc5e9;
        }
        Model0218fe1c_SetAnim(&self->mdl1, nm, 0x1000, 1);
    }
    Model0218fe1c_SetLoop(&self->mdl1);
    if (self->unk_ba0 != NULL) {
        AnimCtrl *ctrl;
        void *q = NULL;
        if (self->unk_ba0[0x18] != 0) {
            q = &self->res2;
        }
        Model0218fe1c_BindAnim3Res(&self->mdl1, q);
        ctrl = Model0218fe1c_GetAnimCtrl(&self->mdl1, 3);
        if (ctrl != NULL) {
            u32 v;
            float f;
            s32 frame;
            Model0218fe1c_SetAnim3(&self->mdl1, 0, 0x1000, 0);
            v = self->unk_ba0[0x18];
            if (v > 0) {
                f = (float)(s32)(v << 12) + 0.5f;
            } else {
                f = (float)(s32)(v << 12) - 0.5f;
            }
            frame = (s32)f;
            if (ctrl->cur != NULL) {
                if (frame >= 0) {
                    ctrl->cur->frame = frame;
                } else {
                    ctrl->cur->frame = (*(u16 *)((u8 *)ctrl->cur->res + 4) << 12) - 1;
                }
            }
            *((u8 *)ctrl + 0x111) |= 8;
        }
    }
    self->mdl1.unk_c2_6 = 1;
    Model0218fe1c_UpdateAnim(&self->mdl1, 0x1000);
    self->unk_ae3 = 0;
    self->mdl1.visible = 1;
    self->unk_ae4 = 0;
    if (!self->unk_b22_3) {
        base = (u8 *)self + 0xbc;
        self->unk_ae1 = Model_FindResIdxByName(&self->mdl1, base + 0x400, data_ov000_021cc5ef);
        self->unk_ae0 = Model_FindResIdxByName(&self->mdl1, base + 0x400, data_ov000_021cc5f6);
        self->unk_ae2 = Model_FindResIdxByName(&self->mdl1, base + 0x400, data_ov000_021cc5fd);
    } else {
        base = (u8 *)self + 0xbc;
        self->unk_ae1 = Model_FindResIdxByName(&self->mdl1, base + 0x400, data_ov000_021cc605);
        self->unk_ae0 = Model_FindResIdxByName(&self->mdl1, base + 0x400, data_ov000_021cc60a);
        self->unk_ae2 = Model_FindResIdxByName(&self->mdl1, base + 0x400, data_ov000_021cc5fd);
    }
    if (!self->unk_b22_3 && gStageFlags->bits18.mode != 2) {
        Model0218fe1c *m2 = &self->mdl0;
        void *tex = self->mdl1.tex;
        NNS_G3dBindMdlSet(NNS_G3dGetMdlSet(m2->res->mdl_handle != NULL ? m2->res->mdl_handle->unk_00 : NULL), tex);
        self->mdl0.visible = 1;
    }
    if (gStageFlags->bits18.mode == 2) {
        self->mdl1.flushVP = 0;
    } else {
        self->mdl1.flushVP = 1;
    }
    if (self->unk_b22_0 != 0 && self->unk_99c != NULL) {
        Model0218fe1c *p = (Model0218fe1c *)Heap_Alloc(0xe8);
        if (p != NULL) {
            p = Model0218fe1c_Init(p);
        }
        self->unk_998 = p;
        Model0218fe1c_SetRes(p, self->unk_99c, 0, 1);
    }
    if (self->unk_998 != NULL) {
        ((Model0218fe1c *)self->unk_998)->visible = 1;
    }
}

}

