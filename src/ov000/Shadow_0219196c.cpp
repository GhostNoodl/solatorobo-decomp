#include "ov000/Vec.h"
#include "Main/Gfx/GfxMgr.h"

typedef struct {
    u8 revision;
    u8 num_entry;
    u16 size_dict;
    u16 unk_04;
    u16 ofs_entry;
} ResDict;

typedef struct {
    u16 size_unit;
    u16 size_data;
    u8 data[4];
} ResDictEntry;

typedef struct {
    u8 unk_00[0x8];
    ResDict dict;
} ResMdlSet;

typedef struct {
    u32 offset;
} ResDictMdlSetData;

typedef struct {
    void *file;
} ShadowRes;

typedef struct {
    void *file;
    void *name;
} ShadowArc;

typedef struct {
    const void *vtbl;
    ShadowRes *res;
    void *mdl;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    u8 type : 4;
    u8 prev : 4;
    u8 alpha;
    u8 unk_1a;
    u8 state;
} Shadow;
SIZE_ASSERT(Shadow, 0x1c);

typedef struct {
    u8 unk_00[0xfc];
    u32 unk_fc;
} GxState;

extern "C" {

extern const u8 data_ov000_021cc438[];
extern ShadowArc data_ov000_021c9d80;
extern MtxFx33 data_020928b4;
extern GxState NNS_G3dGlb;

ShadowRes *func_02035e34(void *file, void *name);
void Vram_FreeRes(void *file);
int ResMgr_IsLoaded(void *a, int b);
void *ResMgr_Load(void *a, int b, int c);
void ResMgr_ReleaseByName(void *a, void *b, int c, int d);
char *G3dRes_SetupVram(void *name, void *file);
void Heap_Free(void *ptr);
ResMdlSet *NNS_G3dGetMdlSet(void *file);
void NNS_G3dGlbSetBaseScale(VecFx32 *scale);
void NNS_G3dGlbSetBaseTrans(VecFx32 *trans);
void NNS_G3dGlbFlushVP(void);
void NNS_G3dMdlSetMdlAlpha(void *mdl, u32 idx, u32 alpha);
void NNS_G3dMdlSetMdlPolygonID(void *mdl, u32 idx, u32 id);
void NNS_G3dMdlSetMdlCullMode(void *mdl, u32 idx, u32 mode);
void NNS_G3dDraw1Mat1Shp(void *mdl, u32 idx, u32 a, u32 b);
u8 Gfx3DState_NextPolyId(void *p);

static inline void *ResDict_GetDataByIdx(const ResDict *dict, u32 idx) {
    if (dict != NULL && idx < dict->num_entry) {
        const ResDictEntry *entry = (const ResDictEntry *)((const u8 *)dict + dict->ofs_entry);
        return (void *)((const u8 *)entry->data + entry->size_unit * idx);
    }
    return NULL;
}

static inline void *ResMdlSet_GetMdlByIdx(ResMdlSet *set, u32 idx) {
    ResDictMdlSetData *data = (ResDictMdlSetData *)ResDict_GetDataByIdx(&set->dict, idx);
    if (data != NULL) {
        return (u8 *)set + data->offset;
    } else {
        return NULL;
    }
}

static inline void SetScaleXZ(VecFx32 *v, s32 s) {
    v->x = s;
    v->y = 0x1000;
    v->z = s;
}

static inline void *Res_GetMdl(void *file, u32 idx) {
    ResMdlSet *set = NNS_G3dGetMdlSet(file);
    if (set != NULL) {
        ResDictMdlSetData *data = (ResDictMdlSetData *)ResDict_GetDataByIdx(&set->dict, idx);
        if (data != NULL) {
            return (u8 *)set + data->offset;
        }
    }
    return NULL;
}

static inline void Shadow_Init(Shadow *self) {
    self->vtbl = data_ov000_021cc438;
    self->res = NULL;
    self->mdl = NULL;
    self->unk_0c = 0xa000;
    self->unk_10 = 0;
    self->unk_14 = 0x1000;
    self->type = 1;
    self->prev = 1;
    self->alpha = 0xff;
    self->unk_1a = 0;
    self->state = 0;
}

static inline void Shadow_Destroy(Shadow *self) {
    self->vtbl = data_ov000_021cc438;
    if (self->res != NULL) {
        Vram_FreeRes(func_02035e34(data_ov000_021c9d80.file, data_ov000_021c9d80.name)->file);
    }
    if (self->state != 0) {
        ResMgr_ReleaseByName(data_02097cdc, data_ov000_021c9d80.file, 7, 0);
    }
}

Shadow *Shadow_CtorBase(Shadow *self) {
    Shadow_Init(self);
    return self;
}

Shadow *Shadow_Ctor(Shadow *self) {
    Shadow_Init(self);
    return self;
}

Shadow *Ov000Vt_021cc438_Dtor(Shadow *self) {
    Shadow_Destroy(self);
    return self;
}

Shadow *Ov000Vt_021cc438_DtorDelete(Shadow *self) {
    Shadow_Destroy(self);
    Heap_Free(self);
    return self;
}

Shadow *Shadow_DtorBase(Shadow *self) {
    Shadow_Destroy(self);
    return self;
}

void Shadow_Load(Shadow *self) {
    ResMgr_Load(data_ov000_021c9d80.file, 7, 0);
    self->state = 1;
}

BOOL Shadow_UpdateLoad(Shadow *self) {
    BOOL ret = FALSE;
    void *file;
    void *name;

    switch (self->state) {
    case 1:
        self->state = 2;
    case 2:
        file = data_ov000_021c9d80.file;
        if (!ResMgr_IsLoaded(file, 7)) {
            break;
        }
        name = data_ov000_021c9d80.name;
        self->res = func_02035e34(file, name);
        if (self->res != NULL) {
            G3dRes_SetupVram(name, self->res->file);
        }
        self->state = 3;
    default:
        ret = TRUE;
        break;
    }
    return ret;
}

/* The shadow is flat: its y scale is always 1.0. As an enum-typed local it is not
   constant-propagated, so it is coloured after the unk_14 load (round lfA). */
typedef enum { SHADOW_SCALE_Y = 0x1000 } ShadowScale;

void Shadow_Draw(Shadow *self, VecFx32 *pos) {
    VecFx32 scale;
    VecFx32 trans;
    MtxFx33 mtx;
    u8 alpha;
    if (self->mdl == NULL || self->type != self->prev) {
        if (self->res != NULL) {
            self->mdl = Res_GetMdl(self->res->file, self->type);
        }
    }
    if (self->mdl == NULL) {
        return;
    }
    if (self->unk_10 > self->unk_0c) {
        return;
    }
    {
        ShadowScale sy = SHADOW_SCALE_Y;
        scale.x = self->unk_14;
        scale.y = sy;
        scale.z = self->unk_14;
    }
    NNS_G3dGlbSetBaseScale(&scale);
    trans = *pos;
    if (self->type <= 1) {
        trans.y += 0x800 - self->unk_10;
    } else {
        trans.y += 0xcd - self->unk_10;
    }
    NNS_G3dGlbSetBaseTrans(&trans);
    if (self->type == 1 || self->type == 3) {
        MTX_Identity33_(&mtx);
        MI_Copy36B(&mtx, &data_020928b4);
        NNS_G3dGlb.unk_fc &= ~0xa4;
    }
    NNS_G3dGlbFlushVP();
    alpha = self->alpha;
    if (alpha == 0xff) {
        u8 a = (self->unk_10 * 15) / self->unk_0c;
        if (a < 1) {
            a = 1;
        } else if (a > 15) {
            a = 15;
        }
        alpha = 16 - a;
    }
    NNS_G3dMdlSetMdlAlpha(self->mdl, 0, alpha);
    if (self->type <= 1) {
        u8 id;
        NNS_G3dMdlSetMdlPolygonID(self->mdl, 0, 0);
        NNS_G3dMdlSetMdlCullMode(self->mdl, 0, 1);
        NNS_G3dDraw1Mat1Shp(self->mdl, 0, 0, 1);
        id = self->unk_1a;
        if (id == 0) {
            id = 5;
        }
        NNS_G3dMdlSetMdlPolygonID(self->mdl, 0, id);
        NNS_G3dMdlSetMdlCullMode(self->mdl, 0, 3);
        NNS_G3dDraw1Mat1Shp(self->mdl, 0, 0, 1);
    } else {
        u8 id = data_02097d48->unk_8b0[1];
        Gfx3DState_NextPolyId(data_02097d48->unk_8b0);
        NNS_G3dMdlSetMdlPolygonID(self->mdl, 0, id);
        NNS_G3dDraw1Mat1Shp(self->mdl, 0, 0, 1);
    }
}

}
