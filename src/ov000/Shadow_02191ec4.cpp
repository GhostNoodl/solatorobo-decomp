#include "ov000/Vec.h"

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

typedef struct {
    s32 m[9];
} Mtx33;

typedef struct {
    u8 unk_00[0xfc];
    u32 unk_fc;
} GxState;

extern "C" {

extern const u8 data_ov000_021cc438[];
extern ShadowArc data_ov000_021c9d80;
extern void *data_02097cdc;
extern u8 *data_02097d48;
extern Mtx33 data_020928b4;
extern GxState NNS_G3dGlb;

ShadowRes *func_02035e34(void *file, void *name);
void func_0203f0b4(void *file);
void func_02036838(void *a, void *b, int c, int d);
void func_020359d0(void *a, int b, int c);
int func_02035b90(void *a, int b);
char *func_0203ed04(void *name, void *file);
void func_0203de1c(void *ptr);
ResMdlSet *NNS_G3dGetMdlSet(void *file);
void NNS_G3dGlbSetBaseScale(VecFx32 *scale);
void NNS_G3dGlbSetBaseTrans(VecFx32 *trans);
void MTX_Identity33_(Mtx33 *mtx);
void MI_Copy36B(const void *src, void *dst);
void NNS_G3dGlbFlushVP(void);
s32 _s32_div_f(s32 a, s32 b);
void NNS_G3dMdlSetMdlAlpha(void *mdl, u32 idx, u32 alpha);
void NNS_G3dMdlSetMdlPolygonID(void *mdl, u32 idx, u32 id);
void NNS_G3dMdlSetMdlCullMode(void *mdl, u32 idx, u32 mode);
void NNS_G3dDraw1Mat1Shp(void *mdl, u32 idx, u32 a, u32 b);
void func_02043d48(void *p);

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

static inline void VEC_Set(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
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
        func_0203f0b4(func_02035e34(data_ov000_021c9d80.file, data_ov000_021c9d80.name)->file);
    }
    if (self->state != 0) {
        func_02036838(data_02097cdc, data_ov000_021c9d80.file, 7, 0);
    }
}

void func_ov000_02191ec4(Shadow *self, u8 type, u32 flags) {
    switch (type) {
    case 1:
        if (flags & 0x10000) {
            type = 3;
        }
        break;
    case 0:
        if (flags & 0x10000) {
            type = 2;
        }
        break;
    }
    self->prev = self->type;
    self->type = type;
}

}
