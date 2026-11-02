#include "ov000/Vec.h"
#include "nitro/std.h"
#include "Main/Sys/SysState.h"
#include "ov000/Model0218fe1c.h"

extern "C" {


void Heap_Free(void *ptr);
s16 *AnimEvent_Exec(s16 *p, Model0218fe1c *m);
void *Heap_Alloc(u32 size);
ResMdlSet *NNS_G3dGetMdlSet(void *file);
void *NNS_G3dGetTex(void *file);
void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 a, u32 mask);
void NNSi_G3dModifyMatFlag(void *mdl, s32 a, u32 mask);
void NNS_G3dRenderObjInit(void *obj, void *mdl);
s32 NNS_G3dGetResDictIdxByName(void *dict, const char *name);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, AnmObj *anm);
BOOL AnimCtrl_Update(AnimCtrl *self, void *obj, s16 speed);
BOOL AnimCtrl_SetAnim(AnimCtrl *self, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
BOOL AnimCtrl_SetAnimByIndex(AnimCtrl *self, void *obj, void *tex, void *file, s32 index, s16 blend, u8 force);
s16 *AnimEvent_Next(s16 *p);
BOOL AnimCtrl_IsDone(AnimCtrl *self);

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
    AnimCtrl *ctrl = (AnimCtrl *)Heap_Alloc(sizeof(AnimCtrl));
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
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (*ptr != NULL) {
        Heap_Free(*ptr);
        *ptr = NULL;
    }
    data_02097dd0->cur = saved;
}

#define FX_SIN_IDX(idx) (FX_SinCosTable_[((idx) >> 4) * 2])
#define FX_COS_IDX(idx) (FX_SinCosTable_[((idx) >> 4) * 2 + 1])

AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i) {
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

void Model0218fe1c_UpdateAnim(Model0218fe1c *self, s16 speed) {
    s32 frame;
    s16 *ev;
    s16 *best;
    s16 *it;
    self->anim_state = 0;
    if (self->blend != 0) {
        self->blend--;
    }
    self->unk_e4 = 0;
    if (self->res->anims == NULL) {
        return;
    }
    if (self->unk_0c != NULL) {
        if (AnimCtrl_Update(self->unk_0c, self->renderObj, speed)) {
            self->evCursor = self->evScript;
        }
        if (self->evCursor != NULL) {
            frame = AnimCtrl_GetFrame(self->unk_0c) >> 12;
            if (!AnimCtrl_IsReverse(self->unk_0c)) {
                ev = self->evCursor;
                while (*ev >= 0 && *ev <= frame) {
                    ev = ((AnimEventFunc)self->evFunc)(ev + 1, self);
                    if (ev == NULL) {
                        goto done;
                    }
                    self->evCursor = ev;
                    if (*ev == frame && (self->unk_e4 & 0x20000000)) {
                        goto done;
                    }
                    frame = AnimCtrl_GetFrame(self->unk_0c) >> 12;
                }
            } else {
                it = self->evScript;
                best = NULL;
                while (*it < frame && *it >= 0) {
                    if (best == NULL || *best < *it) {
                        best = it;
                    }
                    it = AnimEvent_Next(it + 1);
                }
                if (*self->evCursor >= 0) {
                    ev = it;
                    while (ev <= self->evCursor && *ev >= 0) {
                        ev = ((AnimEventFunc)self->evFunc)(ev + 1, self);
                    }
                }
                if (best == NULL) {
                    best = it;
                    while (*best >= 0) {
                        best = AnimEvent_Next(best + 1);
                    }
                }
                self->evCursor = best;
            }
        }
    }
done:
    if (self->unk_10 != NULL) {
        AnimCtrl_Update(self->unk_10, self->renderObj, speed);
    }
    if (self->unk_14 != NULL) {
        AnimCtrl_Update(self->unk_14, self->renderObj, speed);
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        AnimCtrl_Update(self->unk_18, self->renderObj, speed);
    }
    if (self->unk_1c != NULL) {
        AnimCtrl_Update(self->unk_1c, self->renderObj, speed);
    }
}

BOOL Model0218fe1c_SetAnim(Model0218fe1c *self, const char *name, s16 blend, u8 force) {
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
        ret = AnimCtrl_SetAnim(self->unk_0c, self->renderObj, self->res, list->list[0], name, blend, force);
    }
    if (self->unk_10 != NULL) {
        AnimCtrl_SetAnim(self->unk_10, self->renderObj, self->res, list->list[1], name, blend, force);
    }
    if (self->unk_14 != NULL) {
        AnimCtrl_SetAnim(self->unk_14, self->renderObj, self->res, list->list[2], name, 0, force);
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        AnimCtrl_SetAnim(self->unk_18, self->renderObj, self->res, list->list[3], name, 0, force);
    }
    if (self->unk_1c != NULL) {
        AnimCtrl_Stop(self->unk_1c, self->renderObj);
        AnimCtrl_SetAnim(self->unk_1c, self->renderObj, self->res, list->list[4], name, 0, force);
    }
    if (ret) {
        i = 0;
        self->evScript = NULL;
        if (self->evTable != NULL) {
            if (self->evTable->is_ptr == 0) {
                entry = self->evTable->entries;
                ptr = self->evData;
                for (; i < self->evTable->count; i++, entry++) {
                    if (!STD_CompareString(entry->name, name)) {
                        self->evScript = ptr;
                        break;
                    }
                    ptr += entry->value;
                }
            } else {
                entry = *(AnimEventEntry **)self->evTable->entries;
                for (; i < self->evTable->count; i++, entry++) {
                    if (!STD_CompareString(entry->name, name)) {
                        self->evScript = (s16 *)entry->value;
                        break;
                    }
                }
            }
        }
        self->anim_state = 0;
        self->evCursor = self->evScript;
    }
    return ret;
}

void Model0218fe1c_SetAnimByIndex(Model0218fe1c *self, s32 index, s16 blend, u8 force) {
    AnimList *list = self->res->anims;
    AnimCtrl *ctrl;
    if (list == NULL) {
        return;
    }
    if (self->unk_0c != NULL) {
        AnimCtrl_SetAnimByIndex(self->unk_0c, self->renderObj, self->tex, list->list[0], index, blend, force);
    }
    if (self->unk_10 != NULL) {
        AnimCtrl_SetAnimByIndex(self->unk_10, self->renderObj, self->tex, self->res->anims->list[1], index, blend, force);
    }
    if (self->unk_14 != NULL) {
        AnimCtrl_SetAnimByIndex(self->unk_14, self->renderObj, self->tex, self->res->anims->list[2], index, 0, force);
    }
    if (!self->unk_c2_6 && self->unk_18 != NULL) {
        ResSet *res = self->res;
        if (self->unk_20 != NULL) {
            res = self->unk_20;
        }
        AnimCtrl_SetAnimByIndex(self->unk_18, self->renderObj, self->tex, res->anims->list[3], index, 0, force);
    }
    ctrl = self->unk_1c;
    if (ctrl == NULL) {
        return;
    }
    AnimCtrl_Stop(ctrl, self->renderObj);
    if (self->unk_1c != NULL) {
        AnimCtrl_SetAnimByIndex(self->unk_1c, self->renderObj, self->tex, self->res->anims->list[4], index, 0, force);
    }
}

void Model0218fe1c_StopAnim(Model0218fe1c *self) {
    AnimCtrl *a;
    u8 none = 0xff;
    u8 zero = 0;

    a = self->unk_0c;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->renderObj, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
    a = self->unk_10;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->renderObj, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
    a = self->unk_14;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->renderObj, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
    a = self->unk_18;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->renderObj, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
    a = self->unk_1c;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(self->renderObj, a->cur);
        a->name[0] = zero;
        a->index = none;
        a->playing = 0;
        a->same = 0;
    }
}

BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *self) {
    BOOL done = TRUE;

    if (self->unk_0c != NULL) {
        if (!AnimCtrl_IsDone(self->unk_0c) && !(self->unk_e4 & 0x20000000)) {
            done = FALSE;
        }
    }
    if (self->unk_10 != NULL) {
        if (!AnimCtrl_IsDone(self->unk_10)) {
            done = FALSE;
        }
    }
    if (self->unk_14 != NULL) {
        if (!AnimCtrl_IsDone(self->unk_14)) {
            done = FALSE;
        }
    }
    if (self->unk_18 != NULL && !self->unk_c2_6) {
        if (!AnimCtrl_IsDone(self->unk_18)) {
            done = FALSE;
        }
    }
    if (self->unk_1c != NULL) {
        if (!AnimCtrl_IsDone(self->unk_1c)) {
            done = FALSE;
        }
    }
    return done;
}

void Model0218fe1c_SetAnimSpeed(Model0218fe1c *self, s16 speed) {
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

s16 *Model0218fe1c_SeekMainAnim(Model0218fe1c *self, s32 frame) {
    s16 *ret = NULL;
    AnimCtrl *a = self->unk_0c;
    AnmObj *cur;
    s32 f;
    s16 *next;

    if (a != NULL) {
        AnimCtrl_SetFrame(a, frame);
        self->evCursor = self->evScript;
        if (self->evCursor != NULL) {
            a = self->unk_0c;
            cur = a->cur;
            if (cur != NULL) {
                f = cur->frame;
            } else {
                f = 0;
            }
            if (!AnimCtrl_IsReverse(a)) {
                while (self->evCursor[0] >= 0 && self->evCursor[0] < (f >> 12)) {
                    self->evCursor = AnimEvent_Next(self->evCursor + 1);
                }
            } else {
                while (self->evCursor[0] >= 0 && self->evCursor[0] <= (f >> 12)) {
                    next = AnimEvent_Next(self->evCursor + 1);
                    if (next[0] > (f >> 12) || next[0] < 0) {
                        break;
                    }
                    self->evCursor = next;
                }
            }
            ret = self->evCursor;
        }
    }
    return ret;
}

s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *self, s32 frame) {
    s16 *ret = NULL;

    if (self->unk_0c != NULL) {
        ret = Model0218fe1c_SeekMainAnim(self, frame);
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

void Model0218fe1c_SetAnimDelay(Model0218fe1c *self, u16 delay, BOOL force) {
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

BOOL Model0218fe1c_IsAnimDelayed(Model0218fe1c *self) {
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

void Model0218fe1c_SetLoop(Model0218fe1c *self) {
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

void Model0218fe1c_ClearLoop(Model0218fe1c *self) {
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

void Model0218fe1c_PauseAnim(Model0218fe1c *self) {
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

void Model0218fe1c_ResumeAnim(Model0218fe1c *self) {
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

void Model0218fe1c_SetReverse(Model0218fe1c *self) {
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

void Model0218fe1c_ClearReverse(Model0218fe1c *self) {
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
    AnimCtrl_SetAnimByIndex(self->unk_18, self->renderObj, self->tex, res->anims->list[3], index, blend, force);
}

}
