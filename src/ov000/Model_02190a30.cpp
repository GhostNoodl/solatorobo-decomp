#include "ov000/Vec.h"
#include "nitro/std.h"

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
s16 *func_ov000_02191f18(s16 *p, Model0218fe1c *m);
void *func_0203dd9c(u32 size);
ResMdlSet *NNS_G3dGetMdlSet(void *file);
void *NNS_G3dGetTex(void *file);
void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 a, u32 mask);
void NNSi_G3dModifyMatFlag(void *mdl, s32 a, u32 mask);
void NNS_G3dRenderObjInit(void *obj, void *mdl);
s32 NNS_G3dGetResDictIdxByName(void *dict, const char *name);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, AnmObj *anm);
BOOL func_ov000_0218f874(AnimCtrl *self, void *obj, s16 speed);
BOOL func_ov000_0218fa28(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
BOOL func_ov000_0218fb64(AnimCtrl *self, void *obj, void *tex, void *file, s32 index, s16 blend, u8 force);
s16 *func_ov000_02192a28(s16 *p);
BOOL func_ov000_0218fd84(AnimCtrl *self);
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

AnimCtrl *func_ov000_02190a30(Model0218fe1c *self, u32 i) {
    AnimCtrl *ret = NULL;
    switch (i) {
    case 0:
        ret = self->unk_0c;
        break;
    case 1:
        ret = self->unk_10;
        break;
    case 2:
        ret = self->unk_14;
        break;
    case 3:
        ret = self->unk_18;
        break;
    case 4:
        ret = self->unk_1c;
        break;
    }
    return ret;
}

void func_ov000_02190a80(Model0218fe1c *self, s16 speed) {
    s32 frame;
    s16 *ev;
    s16 *best;
    s16 *it;
    self->unk_c4 = 0;
    if (self->unk_ba != 0) {
        self->unk_ba--;
    }
    self->unk_e4 = 0;
    if (self->res->anims == NULL) {
        return;
    }
    if (self->unk_0c != NULL) {
        if (func_ov000_0218f874(self->unk_0c, self->unk_24, speed)) {
            self->unk_dc = self->unk_d8;
        }
        if (self->unk_dc != NULL) {
            frame = AnimCtrl_GetFrame(self->unk_0c) >> 12;
            if (!AnimCtrl_IsReverse(self->unk_0c)) {
                ev = self->unk_dc;
                while (*ev >= 0 && *ev <= frame) {
                    ev = ((AnimEventFunc)self->unk_e0)(ev + 1, self);
                    if (ev == NULL) {
                        goto done;
                    }
                    self->unk_dc = ev;
                    if (*ev == frame && (self->unk_e4 & 0x20000000)) {
                        goto done;
                    }
                    frame = AnimCtrl_GetFrame(self->unk_0c) >> 12;
                }
            } else {
                it = self->unk_d8;
                best = NULL;
                while (*it < frame && *it >= 0) {
                    if (best == NULL || *best < *it) {
                        best = it;
                    }
                    it = func_ov000_02192a28(it + 1);
                }
                if (*self->unk_dc >= 0) {
                    ev = it;
                    while (ev <= self->unk_dc && *ev >= 0) {
                        ev = ((AnimEventFunc)self->unk_e0)(ev + 1, self);
                    }
                }
                if (best == NULL) {
                    best = it;
                    while (*best >= 0) {
                        best = func_ov000_02192a28(best + 1);
                    }
                }
                self->unk_dc = best;
            }
        }
    }
done:
    if (self->unk_10 != NULL) {
        func_ov000_0218f874(self->unk_10, self->unk_24, speed);
    }
    if (self->unk_14 != NULL) {
        func_ov000_0218f874(self->unk_14, self->unk_24, speed);
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        func_ov000_0218f874(self->unk_18, self->unk_24, speed);
    }
    if (self->unk_1c != NULL) {
        func_ov000_0218f874(self->unk_1c, self->unk_24, speed);
    }
}

BOOL func_ov000_02190cb0(Model0218fe1c *self, const char *name, s16 blend, u8 force) {
    BOOL ret;
    AnimList *list = self->res->anims;
    AnimEventEntry *entry;
    s16 *ptr;
    s32 i;
    if (list == NULL) {
        return FALSE;
    }
    ret = FALSE;
    if (self->unk_0c != NULL) {
        ret = func_ov000_0218fa28(self->unk_0c, self->unk_24, self->res, list->list[0], name, blend, force);
    }
    if (self->unk_10 != NULL) {
        func_ov000_0218fa28(self->unk_10, self->unk_24, self->res, list->list[1], name, blend, force);
    }
    if (self->unk_14 != NULL) {
        func_ov000_0218fa28(self->unk_14, self->unk_24, self->res, list->list[2], name, 0, force);
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        func_ov000_0218fa28(self->unk_18, self->unk_24, self->res, list->list[3], name, 0, force);
    }
    if (self->unk_1c != NULL) {
        AnimCtrl_Stop(self->unk_1c, self->unk_24);
        func_ov000_0218fa28(self->unk_1c, self->unk_24, self->res, list->list[4], name, 0, force);
    }
    if (ret) {
        i = 0;
        self->unk_d8 = NULL;
        if (self->unk_d0 != NULL) {
            if (self->unk_d0->is_ptr == 0) {
                entry = self->unk_d0->entries;
                ptr = self->unk_d4;
                for (; i < self->unk_d0->count; i++, entry++) {
                    if (!STD_CompareString(entry->name, name)) {
                        self->unk_d8 = ptr;
                        break;
                    }
                    ptr += entry->value;
                }
            } else {
                entry = *(AnimEventEntry **)self->unk_d0->entries;
                for (; i < self->unk_d0->count; i++, entry++) {
                    if (!STD_CompareString(entry->name, name)) {
                        self->unk_d8 = (s16 *)entry->value;
                        break;
                    }
                }
            }
        }
        self->unk_c4 = 0;
        self->unk_dc = self->unk_d8;
    }
    return ret;
}

void func_ov000_02190e98(Model0218fe1c *self, s32 index, s16 blend, u8 force) {
    AnimList *list = self->res->anims;
    AnimCtrl *ctrl;
    if (list == NULL) {
        return;
    }
    if (self->unk_0c != NULL) {
        func_ov000_0218fb64(self->unk_0c, self->unk_24, self->tex, list->list[0], index, blend, force);
    }
    if (self->unk_10 != NULL) {
        func_ov000_0218fb64(self->unk_10, self->unk_24, self->tex, self->res->anims->list[1], index, blend, force);
    }
    if (self->unk_14 != NULL) {
        func_ov000_0218fb64(self->unk_14, self->unk_24, self->tex, self->res->anims->list[2], index, 0, force);
    }
    if (!self->unk_c2_6 && self->unk_18 != NULL) {
        ResSet *res = self->res;
        if (self->unk_20 != NULL) {
            res = self->unk_20;
        }
        func_ov000_0218fb64(self->unk_18, self->unk_24, self->tex, res->anims->list[3], index, 0, force);
    }
    ctrl = self->unk_1c;
    if (ctrl == NULL) {
        return;
    }
    AnimCtrl_Stop(ctrl, self->unk_24);
    if (self->unk_1c != NULL) {
        func_ov000_0218fb64(self->unk_1c, self->unk_24, self->tex, self->res->anims->list[4], index, 0, force);
    }
}

void func_ov000_02191008(Model0218fe1c *self) {
    AnimCtrl *a;
    u8 none = 0xff;
    u8 zero = 0;

    a = self->unk_0c;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->unk_24, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
    a = self->unk_10;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->unk_24, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
    a = self->unk_14;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->unk_24, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
    a = self->unk_18;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->unk_24, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
    a = self->unk_1c;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->unk_24, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
}

BOOL func_ov000_02191120(Model0218fe1c *self) {
    BOOL done = TRUE;

    if (self->unk_0c != NULL) {
        if (!func_ov000_0218fd84(self->unk_0c) && !(self->unk_e4 & 0x20000000)) {
            done = FALSE;
        }
    }
    if (self->unk_10 != NULL) {
        if (!func_ov000_0218fd84(self->unk_10)) {
            done = FALSE;
        }
    }
    if (self->unk_14 != NULL) {
        if (!func_ov000_0218fd84(self->unk_14)) {
            done = FALSE;
        }
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        if (!func_ov000_0218fd84(self->unk_18)) {
            done = FALSE;
        }
    }
    if (self->unk_1c != NULL) {
        if (!func_ov000_0218fd84(self->unk_1c)) {
            done = FALSE;
        }
    }
    return done;
}

void func_ov000_021911c8(Model0218fe1c *self, s16 speed) {
    if (self->unk_0c != NULL) {
        self->unk_0c->speed = speed;
    }
    if (self->unk_10 != NULL) {
        self->unk_10->speed = speed;
    }
    if (self->unk_14 != NULL) {
        self->unk_14->speed = speed;
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        self->unk_18->speed = speed;
    }
    if (self->unk_1c != NULL) {
        self->unk_1c->speed = speed;
    }
}

static inline void AnimCtrl_SetFrame(AnimCtrl *a, s32 frame) {
    AnmObj *cur = a->cur;
    if (cur != NULL) {
        if (frame >= 0) {
            cur->frame = frame;
        } else {
            cur->frame = (((u16 *)cur->res)[2] << 12) - 1;
        }
    }
}

s16 *func_ov000_0219122c(Model0218fe1c *self, s32 frame) {
    s16 *ret = NULL;
    AnimCtrl *a = self->unk_0c;
    AnmObj *cur;
    s32 f;
    s16 *next;

    if (a != NULL) {
        AnimCtrl_SetFrame(a, frame);
        self->unk_dc = self->unk_d8;
        if (self->unk_dc != NULL) {
            a = self->unk_0c;
            cur = a->cur;
            if (cur != NULL) {
                f = cur->frame;
            } else {
                f = 0;
            }
            if (!AnimCtrl_IsReverse(a)) {
                while (self->unk_dc[0] >= 0 && self->unk_dc[0] < (f >> 12)) {
                    self->unk_dc = func_ov000_02192a28(self->unk_dc + 1);
                }
            } else {
                while (self->unk_dc[0] >= 0 && self->unk_dc[0] <= (f >> 12)) {
                    next = func_ov000_02192a28(self->unk_dc + 1);
                    if (next[0] > (f >> 12) || next[0] < 0) {
                        break;
                    }
                    self->unk_dc = next;
                }
            }
            ret = self->unk_dc;
        }
    }
    return ret;
}

s16 *func_ov000_02191318(Model0218fe1c *self, s32 frame) {
    s16 *ret = NULL;

    if (self->unk_0c != NULL) {
        ret = func_ov000_0219122c(self, frame);
    }
    if (self->unk_10 != NULL) {
        AnimCtrl_SetFrame(self->unk_10, frame);
    }
    if (self->unk_14 != NULL) {
        AnimCtrl_SetFrame(self->unk_14, frame);
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        AnimCtrl_SetFrame(self->unk_18, frame);
    }
    if (self->unk_1c != NULL) {
        AnimCtrl_SetFrame(self->unk_1c, frame);
    }
    return ret;
}

void func_ov000_02191418(Model0218fe1c *self, u16 delay, BOOL force) {
    if (self->unk_0c != NULL && (force || self->unk_0c->delay < delay)) {
        self->unk_0c->delay = delay;
    }
    if (self->unk_10 != NULL && (force || self->unk_10->delay < delay)) {
        self->unk_10->delay = delay;
    }
    if (self->unk_14 != NULL && (force || self->unk_14->delay < delay)) {
        self->unk_14->delay = delay;
    }
    if (self->unk_18 != NULL && !self->unk_c2_6 && (force || self->unk_18->delay < delay)) {
        self->unk_18->delay = delay;
    }
    if (self->unk_1c != NULL && (force || self->unk_1c->delay < delay)) {
        self->unk_1c->delay = delay;
    }
}

BOOL func_ov000_02191508(Model0218fe1c *self) {
    BOOL busy = FALSE;

    if (self->unk_0c != NULL && self->unk_0c->delay != 0) {
        busy = TRUE;
    }
    if (self->unk_10 != NULL && self->unk_10->delay != 0) {
        busy = TRUE;
    }
    if (self->unk_14 != NULL && self->unk_14->delay != 0) {
        busy = TRUE;
    }
    if (self->unk_18 != NULL && !self->unk_c2_6 && self->unk_18->delay != 0) {
        busy = TRUE;
    }
    if (self->unk_1c != NULL && self->unk_1c->delay != 0) {
        busy = TRUE;
    }
    return busy;
}

void func_ov000_021915a0(Model0218fe1c *self) {
    if (self->unk_0c != NULL) {
        self->unk_0c->loop = 1;
    }
    if (self->unk_10 != NULL) {
        self->unk_10->loop = 1;
    }
    if (self->unk_14 != NULL) {
        self->unk_14->loop = 1;
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        self->unk_18->loop = 1;
    }
    if (self->unk_1c != NULL) {
        self->unk_1c->loop = 1;
    }
}

void func_ov000_02191618(Model0218fe1c *self) {
    if (self->unk_0c != NULL) {
        self->unk_0c->loop = 0;
    }
    if (self->unk_10 != NULL) {
        self->unk_10->loop = 0;
    }
    if (self->unk_14 != NULL) {
        self->unk_14->loop = 0;
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        self->unk_18->loop = 0;
    }
    if (self->unk_1c != NULL) {
        self->unk_1c->loop = 0;
    }
}

void func_ov000_02191690(Model0218fe1c *self) {
    if (self->unk_0c != NULL) {
        self->unk_0c->paused = 1;
    }
    if (self->unk_10 != NULL) {
        self->unk_10->paused = 1;
    }
    if (self->unk_14 != NULL) {
        self->unk_14->paused = 1;
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        self->unk_18->paused = 1;
    }
    if (self->unk_1c != NULL) {
        self->unk_1c->paused = 1;
    }
}

void func_ov000_02191708(Model0218fe1c *self) {
    if (self->unk_0c != NULL) {
        self->unk_0c->paused = 0;
    }
    if (self->unk_10 != NULL) {
        self->unk_10->paused = 0;
    }
    if (self->unk_14 != NULL) {
        self->unk_14->paused = 0;
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        self->unk_18->paused = 0;
    }
    if (self->unk_1c != NULL) {
        self->unk_1c->paused = 0;
    }
}

void func_ov000_02191780(Model0218fe1c *self) {
    if (self->unk_0c != NULL) {
        self->unk_0c->reverse = 1;
    }
    if (self->unk_10 != NULL) {
        self->unk_10->reverse = 1;
    }
    if (self->unk_14 != NULL) {
        self->unk_14->reverse = 1;
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        self->unk_18->reverse = 1;
    }
    if (self->unk_1c != NULL) {
        self->unk_1c->reverse = 1;
    }
}

void func_ov000_021917f8(Model0218fe1c *self) {
    if (self->unk_0c != NULL) {
        self->unk_0c->reverse = 0;
    }
    if (self->unk_10 != NULL) {
        self->unk_10->reverse = 0;
    }
    if (self->unk_14 != NULL) {
        self->unk_14->reverse = 0;
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        self->unk_18->reverse = 0;
    }
    if (self->unk_1c != NULL) {
        self->unk_1c->reverse = 0;
    }
}

void func_ov000_02191870(Model0218fe1c *self, ResSet *res) {
    FreeOnHeap(&self->unk_18);
    self->unk_20 = NULL;
    if (res != NULL && res->anims != NULL && res->anims->list[3] != NULL) {
        self->unk_18 = AnimCtrl_New();
        self->unk_20 = res;
    }
}

void func_ov000_02191920(Model0218fe1c *self, s32 index, s16 blend, u8 force) {
    ResSet *res;

    if (self->unk_18 == NULL) {
        return;
    }
    res = self->res;
    if (self->unk_20 != NULL) {
        res = self->unk_20;
    }
    func_ov000_0218fb64(self->unk_18, self->unk_24, self->tex, res->anims->list[3], index, blend, force);
}

}
