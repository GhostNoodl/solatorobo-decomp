#include "types.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 unk_00[0x4];
    u16 num_frames;
} AnmRes;

typedef struct {
    s32 frame;
    s32 ratio;
    AnmRes *res;
    u8 unk_0c[0x74];
} AnmObj;

typedef struct {
    u8 unk_00[0x4];
    void *mdl;
} RenderObj;

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
    ResHandle *handle;
    char name[0x20];
    char ext[0x18];
} ResEntry;

typedef struct {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
    void *unk_04;
    void *unk_08;
    ResEntry entries[5];
} ResSet;

extern "C" {

void NNS_G3dRenderObjRemoveAnmObj(RenderObj *obj, AnmObj *anm);
void NNS_G3dRenderObjAddAnmObj(RenderObj *obj, AnmObj *anm);
void NNS_G3dAnmObjInit(AnmObj *anm, void *res, void *mdl, void *tex);
void *NNS_G3dGetAnmByIdx(void *file, s32 index);
void *NNS_G3dGetAnmByName(void *file, const char *name);
void *NNS_G3dGetTex(void *tex);
void func_0201e520(char *dst, const char *src);
void func_0201e78c(char *dst, const char *src);
BOOL func_0201e7b0(const char *a, const char *b);
void func_ov000_0218fc28(AnimCtrl *self, RenderObj *obj, void *res, void *tex, s16 blend);

BOOL func_ov000_0218f874(AnimCtrl *self, RenderObj *obj, s16 speed) {
    s32 zero = 0;
    BOOL ret = FALSE;
    u16 delay = self->delay;
    s32 last;
    if (delay != 0) {
        self->delay = delay - 1;
    }
    if (!self->playing) {
        return FALSE;
    }
    if (self->paused) {
        return FALSE;
    }
    if (self->blend != 0x1000 && self->prev != NULL) {
        self->cur->ratio += self->blend;
        self->prev->ratio -= self->blend;
        if (self->cur->ratio >= 0x1000 || self->prev->ratio <= 0) {
            self->blend = 0x1000;
            self->cur->ratio = 0x1000;
            NNS_G3dRenderObjRemoveAnmObj(obj, self->prev);
            self->prev->ratio = zero;
        } else {
            return FALSE;
        }
    }
    if (delay != 0) {
        return FALSE;
    }
    if (speed == 0x1000) {
        speed = self->speed;
    } else if (self->speed != 0x1000) {
        speed = FX_MUL(self->speed, speed);
    }
    if (self->reverse) {
        speed = -speed;
    }
    self->cur->frame += speed;
    last = (self->cur->res->num_frames << 12) - 1;
    if (!self->reverse) {
        if (self->cur->frame >= last) {
            if (self->loop) {
                self->cur->frame = zero;
                ret = TRUE;
            } else {
                self->cur->frame = last;
            }
        }
    } else {
        if (self->cur->frame <= 0) {
            if (self->loop) {
                self->cur->frame = last;
                ret = TRUE;
            } else {
                self->cur->frame = zero;
            }
        }
    }
    return ret;
}

BOOL func_ov000_0218fa28(AnimCtrl *self, RenderObj *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force) {
    BOOL ret;
    char buf[0x10];
    u32 i;
    void *anm;
    void *tex;
    self->same = 0;
    ret = FALSE;
    if (name == NULL) {
        NNS_G3dRenderObjRemoveAnmObj(obj, self->cur);
        self->name[0] = 0;
        self->index = 0xff;
        self->playing = 0;
        self->same = 0;
        return ret;
    }
    if (!force && !func_0201e7b0(self->name, name)) {
        self->same = 1;
        return ret;
    }
    for (i = 0; i < 4; i++) {
        ((u32 *)buf)[i] = 0;
    }
    tex = NULL;
    func_0201e520(buf, res->entries[1].ext);
    func_0201e78c(buf, name);
    anm = NNS_G3dGetAnmByName(file, buf);
    if (anm != NULL) {
        func_0201e520(self->name, name);
        self->index = 0xff;
        if (res->entries[0].handle != NULL) {
            tex = res->entries[0].handle->unk_00;
        }
        func_ov000_0218fc28(self, obj, anm, NNS_G3dGetTex(tex), blend);
        ret = TRUE;
    }
    return ret;
}

BOOL func_ov000_0218fb64(AnimCtrl *self, RenderObj *obj, void *tex, void *file, s32 index, s16 blend, u8 force) {
    BOOL ret;
    void *anm;
    self->same = 0;
    ret = FALSE;
    if (index < 0) {
        NNS_G3dRenderObjRemoveAnmObj(obj, self->cur);
        self->name[0] = 0;
        self->index = 0xff;
        self->playing = 0;
        self->same = 0;
    }
    if (!force && self->index == index) {
        self->same = 1;
        return FALSE;
    }
    anm = NNS_G3dGetAnmByIdx(file, index);
    if (anm != NULL) {
        self->index = index;
        self->name[0] = 0;
        func_ov000_0218fc28(self, obj, anm, tex, blend);
        ret = TRUE;
    }
    return ret;
}

void func_ov000_0218fc28(AnimCtrl *self, RenderObj *obj, void *res, void *tex, s16 blend) {
    s32 ratio;
    void *mdl;
    self->playing = 1;
    self->same = 1;
    mdl = obj->mdl;
    ratio = 0x1000;
    if (blend == 0x1000 || blend == 0 || res == NULL) {
        self->blend = 0x1000;
        NNS_G3dRenderObjRemoveAnmObj(obj, self->cur);
        if (self->prev != NULL) {
            NNS_G3dRenderObjRemoveAnmObj(obj, self->prev);
            self->prev->ratio = 0;
        }
    } else {
        self->blend = blend;
        if (self->prev != NULL) {
            if (self->blend == 0x1000 || self->cur->ratio > self->prev->ratio) {
                AnmObj *cur;
                AnmObj *prev;
                NNS_G3dRenderObjRemoveAnmObj(obj, self->prev);
                cur = self->cur;
                prev = self->prev;
                self->prev = cur;
                self->cur = prev;
            } else {
                NNS_G3dRenderObjRemoveAnmObj(obj, self->cur);
            }
        } else {
            self->prev = self->cur;
            self->cur->ratio = ratio;
            self->cur = &self->obj_b;
        }
        ratio = 0;
    }
    NNS_G3dAnmObjInit(self->cur, res, mdl, tex);
    if (ratio != 0x1000) {
        self->cur->ratio = ratio;
    }
    NNS_G3dRenderObjAddAnmObj(obj, self->cur);
    self->speed = 0x1000;
    self->delay = 0;
    self->loop = 0;
    self->paused = 0;
    self->reverse = 0;
}

BOOL func_ov000_0218fd84(AnimCtrl *self) {
    BOOL ret;
    if (self->delay != 0) {
        return FALSE;
    }
    if (self->loop) {
        return TRUE;
    }
    if (self->cur == NULL) {
        return TRUE;
    }
    if (!self->playing) {
        return TRUE;
    }
    if (!self->same) {
        return TRUE;
    }
    ret = TRUE;
    if (!self->reverse) {
        if (self->cur->frame < (self->cur->res->num_frames << 12) - 1) {
            ret = FALSE;
        }
    } else {
        if (self->cur->frame > 0) {
            ret = FALSE;
        }
    }
    return ret;
}

}
