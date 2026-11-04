#include "ov015/ov015.h"

extern "C" {

extern u8 Ov015Info38_vtbl[];
u8 *Param_GetHarpoonInfo(u16 id);
extern Ov015Obj290 *gOv015Obj290;
extern const char *data_ov015_02213228[];
extern const char *data_ov015_02213230[];
extern const char *data_ov015_02213208[];
s32 ResSet_UpdateLoad(void *a);

void Ov015Vt_02213200_Dtor(void) {
}

void Ov015Info38_Ctor(Ov015Info38 *self) {
    SET_VT(self, Ov015Info38_vtbl);
    self->id = 0xffff;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
    self->unk_34 = 0;
}

void Ov015Info38_Dtor(Ov015Info38 *self) {
}

void *Ov015Info38_DtorDelete(Ov015Info38 *self) {
    Heap_Free(self);
    return self;
}

void Ov015Info38_Set(Ov015Info38 *self, u16 id, s32 mode) {
    u8 *info;
    s32 t;
    self->id = id;
    info = Param_GetHarpoonInfo(id);
    self->unk_08 = info[2] * 0x333 + 0x4cd;
    self->unk_0c = info[2] * 0x4cd + 0xccd;
    self->unk_10 = 0xa000;
    self->unk_14 = 0;
    t = info[3] * -0x99a - 0x1800;
    self->unk_18 = t;
    self->unk_1c = t >> 1;
    self->unk_20 = FLD(s16, info, 0x4) << 4;
    if (mode == 1) {
        self->unk_20 += 0x1000;
    }
    self->unk_24 = FLD(s16, info, 0x4) << 4;
    self->unk_28 = -0x1800;
    self->unk_2c = -0xc0;
    self->unk_30 = FLD(s16, info, 0x6) << 4;
}

struct Ov015Info30 {
    u8 pad[0x24];
    Ov015Vec v;
};
void func_ov015_02211954(NNSG3dRS *rs) {
    Ov015Obj290 *g = gOv015Obj290;
    s32 k;
    Ov015Info30 info;
    if (g == NULL) {
        return;
    }
    k = (rs->flag & 0x10) ? rs->currentNodeDesc : -1;
    if (k != g->unk_0c) {
        return;
    }
    NNS_G3dGetCurrentMtx((MtxFx43 *)&info, (MtxFx33 *)0);
    g->unk_234 = info.v;
    rs->cbVecFunc[NNS_G3D_SBC_NODEDESC] = NULL;
    rs->cbVecTiming[NNS_G3D_SBC_NODEDESC] = 0;
}

void func_ov015_022119d0(NNSG3dRS *rs) {
    rs->cbVecFunc[NNS_G3D_SBC_NODEDESC] = func_ov015_02211954;
    rs->cbVecTiming[NNS_G3D_SBC_NODEDESC] = NNS_G3D_SBC_CALLBACK_TIMING_C;
}

void Ov015Obj290_Reset(Ov015Obj290 *self) {
    self->vfunc_08();
    self->unk_04 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->animSpeed = 0x1000;
}

void func_ov015_02211a18(void) {
}

void Ov015Obj290_Init(Ov015Obj290 *self) {
    self->step = 0;
    self->unk_234.x = 0;
    self->unk_234.y = 0;
    self->unk_234.z = 0;
    self->unk_240.x = 0;
    self->unk_240.y = 0;
    self->unk_240.z = 0;
    MTX_Identity33_((MtxFx33 *)(&self->rot));
    self->unk_270.x = 0;
    self->unk_270.y = 0;
    self->unk_270.z = 0;
    self->unk_27c.x = 0;
    self->unk_27c.y = 0;
    self->unk_27c.z = 0;
    self->yaw = 0;
    self->unk_28a = 0;
}

static inline void Ov015_SetPairB(u8 *l, s32 i, const void *a, const void *b) {
    STD_CopyString((char *)(l + 0x10 + i * 0x3c), (char *)a);
    STD_CopyString((char *)(l + 0x30 + i * 0x3c), (char *)b);
    l[3] |= 2 << i;
}
void Ov015Obj290_Load(Ov015Obj290 *self) {
    s32 idx = gOv015Shared->unk_2c;
    Ov015_SetPairB((u8 *)&self->res, 0, data_ov015_02213230[idx], data_ov015_02213228[idx]);
    Ov015_SetPairB((u8 *)&self->res, 1, data_ov015_02213230[idx], data_ov015_02213208[idx]);
    self->res.unk_00 = 0;
}

BOOL Ov015Obj290_IsLoaded(Ov015Obj290 *self) {
    BOOL r = TRUE;
    if (self->res.unk_00 >= 0) {
        if ((ResSet_UpdateLoad(&self->res) & 1) == 0) r = FALSE;
    }
    return r;
}


BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
void Model0218fe1c_ClearLoop(void *a);
s32 Model_FindResIdxByName(void *a, const void *b, const void *c);
extern u8 data_ov015_02213280[];
extern const char *data_ov015_02213210[];

BOOL Ov015Obj290_Setup(Ov015Obj290 *self) {
    Model0218fe1c_SetRes(&self->model, &self->res, 0, 1);
    Model0218fe1c_SetAnim(&self->model, data_ov015_02213280, 0x1000, 0);
    Model0218fe1c_ClearLoop(&self->model);
    self->model.flags.boxTest = 0;
    self->model.flags.invV = 0;
    self->model.flags.visible = 0;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)(&self->model.renderObj), func_ov015_022119d0);
    self->model.flags.clearInit = 0;
    self->model.flags.flushVP = 1;
    s32 r = gOv015Shared->unk_2c;
    r = Model_FindResIdxByName(&self->model, data_ov015_02213210[r], NULL);
    self->unk_0c = r;
    return TRUE;
}

}
