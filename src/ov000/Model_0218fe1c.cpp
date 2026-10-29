#include "ov000/Vec.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

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
    s32 frame;
    s32 ratio;
    void *res;
    u8 unk_0c[0x74];
} AnmObj;

typedef struct {
    AnmObj *cur;
    AnmObj *prev;
    AnmObj obj_a;
    AnmObj obj_b;
    char name[0x8];
    u8 index;
    u8 playing : 1;
    u8 same : 1;
    u8 loop : 1;
    u8 paused : 1;
    u8 reverse : 1;
    u8 flags_5 : 3;
    s16 speed;
    s16 blend;
    u16 delay;
} AnimCtrl;

typedef struct {
    void *unk_00;
} ResHandle;

typedef struct {
    void *list[5];
} AnimList;

typedef struct {
    u8 unk_00[0xc];
    ResHandle *mdl_handle;
    char mdl_name[0x20];
    char mdl_ext[0x18];
    AnimList *anims;
} ResSet;

typedef struct {
    char name[0x8];
    s32 value;
} AnimEventEntry;

typedef struct {
    u16 count;
    u16 is_ptr;
    AnimEventEntry entries[1];
} AnimEventTable;

typedef struct {
    ResSet *res;
    void *mdl;
    void *tex;
    AnimCtrl *unk_0c;
    AnimCtrl *unk_10;
    AnimCtrl *unk_14;
    AnimCtrl *unk_18;
    AnimCtrl *unk_1c;
    ResSet *unk_20;
    u8 unk_24[0x54];
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    u8 unk_84[0x24];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u16 unk_b4;
    u8 unk_b6[0x4];
    u16 unk_ba;
    u16 unk_bc;
    u8 unk_be;
    u8 unk_bf;
    u8 unk_c0;
    u8 unk_c1;
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 1;
    u16 unk_c2_2 : 2;
    u16 unk_c2_4 : 1;
    u16 unk_c2_5 : 1;
    u16 unk_c2_6 : 1;
    u16 unk_c2_7 : 1;
    u16 unk_c2_8 : 1;
    u16 unk_c2_9 : 2;
    u16 unk_c2_11 : 5;
    u16 unk_c4;
    u16 unk_c6;
    u16 unk_c8;
    u16 unk_ca;
    s16 unk_cc;
    u16 unk_ce;
    AnimEventTable *unk_d0;
    s16 *unk_d4;
    s16 *unk_d8;
    s16 *unk_dc;
    void *unk_e0;
    u32 unk_e4;
} Model0218fe1c;

typedef s16 *(*AnimEventFunc)(s16 *data, Model0218fe1c *model);

extern "C" {

extern HeapState *data_02097dd0;

void MTX_Identity33_(void *mtx);
void func_0203de1c(void *ptr);
void *func_ov000_02191f18(void);
void *func_0203dd9c(u32 size);
ResMdlSet *NNS_G3dGetMdlSet(void *file);
void *NNS_G3dGetTex(void *file);
void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 a, u32 mask);
void NNSi_G3dModifyMatFlag(void *mdl, s32 a, u32 mask);
void NNS_G3dRenderObjInit(void *obj, void *mdl);
void STD_CopyString(char *dst, const char *src);
void STD_ConcatenateString(char *dst, const char *src);
s32 NNS_G3dGetResDictIdxByName(void *dict, const char *name);
BOOL STD_CompareString(const char *a, const char *b);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, AnmObj *anm);
BOOL func_ov000_0218f874(AnimCtrl *self, void *obj, s16 speed);
BOOL func_ov000_0218fa28(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
BOOL func_ov000_0218fb64(AnimCtrl *self, void *obj, void *tex, void *file, s32 index, s16 blend, u8 force);
s16 *func_ov000_02192a28(s16 *p);
void MTX_RotX33_(void *mtx, s32 sin, s32 cos);
void MTX_RotY33_(void *mtx, s32 sin, s32 cos);
void MTX_RotZ33_(void *mtx, s32 sin, s32 cos);
void MTX_Concat33(void *a, void *b, void *ab);

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

static inline AnimCtrl *AnimCtrl_New(void) {
    AnimCtrl *ctrl = (AnimCtrl *)func_0203dd9c(sizeof(AnimCtrl));
    if (ctrl != NULL) {
        ctrl->cur = &ctrl->obj_a;
        ctrl->prev = NULL;
        ctrl->name[0] = 0;
        ctrl->index = 0xff;
        *((u8 *)ctrl + 0x111) = 0;
        ctrl->speed = 0x1000;
        ctrl->blend = 0x1000;
        ctrl->delay = 0;
    }
    return ctrl;
}

static inline void AnimCtrl_Stop(AnimCtrl *ctrl, void *obj) {
    NNS_G3dRenderObjRemoveAnmObj(obj, ctrl->cur);
    ctrl->name[0] = 0;
    ctrl->index = 0xff;
    ctrl->playing = 0;
    ctrl->same = 0;
}

static inline s32 AnimCtrl_GetFrame(AnimCtrl *ctrl) {
    return ctrl->cur != NULL ? ctrl->cur->frame : 0;
}

static inline BOOL AnimCtrl_IsReverse(AnimCtrl *ctrl) {
    return ctrl->reverse ? TRUE : FALSE;
}

static inline void FreeOnHeap(AnimCtrl **ptr) {
    void *saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (*ptr != NULL) {
        func_0203de1c(*ptr);
        *ptr = NULL;
    }
    data_02097dd0->current = saved;
}

typedef struct {
    s32 m[3][3];
} MtxFx33;

#define FX_SIN_IDX(idx) (FX_SinCosTable_[((idx) >> 4) * 2])
#define FX_COS_IDX(idx) (FX_SinCosTable_[((idx) >> 4) * 2 + 1])

Model0218fe1c *func_ov000_0218fe1c(Model0218fe1c *self) {
    self->res = NULL;
    self->mdl = NULL;
    self->tex = NULL;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
    self->unk_18 = NULL;
    self->unk_1c = NULL;
    self->unk_20 = NULL;
    self->unk_78 = 0;
    self->unk_7c = 0;
    self->unk_80 = 0;
    MTX_Identity33_(self->unk_84);
    self->unk_a8 = 0x1000;
    self->unk_ac = 0x1000;
    self->unk_b0 = 0x1000;
    self->unk_b4 = 0xffff;
    self->unk_c4 = 0;
    self->unk_c6 = 0;
    self->unk_c8 = 0;
    self->unk_ca = 0;
    self->unk_cc = -1;
    self->unk_ce = 0;
    self->unk_d0 = NULL;
    self->unk_d4 = NULL;
    self->unk_d8 = NULL;
    self->unk_dc = NULL;
    self->unk_e0 = (void *)func_ov000_02191f18;
    self->unk_e4 = 0;
    self->unk_ba = 0;
    self->unk_bc = 0;
    self->unk_be = 0x1f;
    self->unk_bf = 0x1f;
    self->unk_c0 = 0xff;
    self->unk_c1 = 0;
    *(u16 *)((u8 *)self + 0xc2) = 0;
    return self;
}

Model0218fe1c *func_ov000_0218fee4(Model0218fe1c *self) {
    FreeOnHeap(&self->unk_0c);
    FreeOnHeap(&self->unk_10);
    FreeOnHeap(&self->unk_14);
    FreeOnHeap(&self->unk_18);
    FreeOnHeap(&self->unk_1c);
    return self;
}

BOOL func_ov000_0218ffdc(Model0218fe1c *self, ResSet *res, u8 idx, BOOL anim) {
    void *file;
    ResMdlSet *set;
    self->unk_c0 = idx;
    self->res = res;
    file = res->mdl_handle != NULL ? res->mdl_handle->unk_00 : NULL;
    if (file == NULL) {
        return FALSE;
    }
    self->mdl = NULL;
    self->unk_c2_0 = TRUE;
    self->unk_c2_4 = 1;
    set = NNS_G3dGetMdlSet(file);
    {
        void *mdl;
        ResDictMdlSetData *data;
        if (set != NULL && (data = (ResDictMdlSetData *)ResDict_GetDataByIdx(&set->dict, idx)) != NULL) {
            mdl = (u8 *)set + data->offset;
        } else {
            mdl = NULL;
        }
        self->mdl = mdl;
    }
    self->tex = NNS_G3dGetTex(file);
    NNSi_G3dModifyPolygonAttrMask(self->mdl, FALSE, 0x8000);
    NNSi_G3dModifyPolygonAttrMask(self->mdl, FALSE, 0x1f0000);
    NNSi_G3dModifyPolygonAttrMask(self->mdl, FALSE, 0x3f000000);
    NNSi_G3dModifyMatFlag(self->mdl, FALSE, 0x40);
    NNSi_G3dModifyMatFlag(self->mdl, FALSE, 0x80);
    NNSi_G3dModifyMatFlag(self->mdl, FALSE, 0x200);
    NNSi_G3dModifyMatFlag(self->mdl, FALSE, 0x400);
    self->unk_c2_7 = 0;
    self->unk_c2_9 = 3;
    NNS_G3dRenderObjInit(self->unk_24, self->mdl);
    FreeOnHeap(&self->unk_0c);
    FreeOnHeap(&self->unk_10);
    FreeOnHeap(&self->unk_14);
    FreeOnHeap(&self->unk_18);
    FreeOnHeap(&self->unk_1c);
    self->unk_c2_1 = 0;
    if (anim && res->anims != NULL) {
        AnimList *anims = res->anims;
        self->unk_c2_1 = 1;
        if (anims->list[0] != NULL) {
            self->unk_0c = AnimCtrl_New();
        }
        if (anims->list[1] != NULL) {
            self->unk_10 = AnimCtrl_New();
        }
        if (anims->list[2] != NULL) {
            self->unk_14 = AnimCtrl_New();
        }
        if (anims->list[3] != NULL) {
            self->unk_18 = AnimCtrl_New();
        }
        if (anims->list[4] != NULL) {
            self->unk_1c = AnimCtrl_New();
        }
    }
    self->unk_be = 0x1f;
    self->unk_ba = 0;
    self->unk_bc = 0;
    return TRUE;
}

}
