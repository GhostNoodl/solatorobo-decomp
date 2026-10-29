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

typedef struct {
    u8 pad_00[0x10];
    s16 scale;
    u16 b0 : 2;
    u16 mode : 3;
    u16 frame : 3;
    u16 f8 : 1;
    u16 f9 : 1;
    u16 f10 : 1;
    u16 f11 : 1;
    u16 rest : 4;
} Cfg0219badc;

typedef struct {
    u8 pad_00[0x48];
    void *anim;
    u8 pad_4c[0x74];
    void **events;
    u8 pad_c4[0x38];
    void **texFile;
} Res0219badc;

extern "C" {

void *NNS_G3dGetTex(void *file);
ResMdlSet *NNS_G3dGetMdlSet(void *file);
BOOL NNS_G3dBindMdlSet(ResMdlSet *set, void *tex);
void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 a, u32 mask);
void NNSi_G3dModifyMatFlag(void *mdl, s32 a, u32 mask);
BOOL func_ov000_0218ffdc(Model0218fe1c *self, Res0219badc *res, u8 mode, s32 e);
void func_ov000_02190e98(Model0218fe1c *self, s32 index, s16 blend, u8 force);
void func_ov000_021915a0(Model0218fe1c *self);
AnimCtrl *func_ov000_02190a30(Model0218fe1c *self, u32 i);
void func_ov000_02191920(Model0218fe1c *self, s32 index, s16 blend, u8 force);

void func_ov000_0219badc(Model0218fe1c *self, Res0219badc *res, const Cfg0219badc *cfg) {
    void *tex;
    AnimCtrl *ctrl;
    AnimEventTable *tbl;
    if (!func_ov000_0218ffdc(self, res, cfg->mode, 1)) {
        return;
    }
    if (res->anim != NULL) {
        func_ov000_02190e98(self, 0, 0x1000, 0);
        func_ov000_021915a0(self);
    }
    tex = res->texFile != NULL ? NNS_G3dGetTex(*res->texFile) : NULL;
    if (tex != NULL) {
        NNS_G3dBindMdlSet(NNS_G3dGetMdlSet(self->res->mdl_handle != NULL ? self->res->mdl_handle->unk_00 : NULL), tex);
    }
    {
        s32 sc = cfg->scale;
        if (sc != 0x1000) {
            self->unk_a8 = sc;
            self->unk_ac = sc;
            self->unk_b0 = sc;
        }
    }
    if (cfg->f8) {
        NNSi_G3dModifyPolygonAttrMask(self->mdl, 1, 0x3f000000);
    }
    if (cfg->f9) {
        NNSi_G3dModifyMatFlag(self->mdl, 1, 0x40);
        NNSi_G3dModifyMatFlag(self->mdl, 1, 0x80);
        NNSi_G3dModifyMatFlag(self->mdl, 1, 0x200);
        NNSi_G3dModifyMatFlag(self->mdl, 1, 0x400);
        self->unk_c2_7 = 1;
    }
    if (cfg->f10) {
        NNSi_G3dModifyPolygonAttrMask(self->mdl, 1, 0x1f0000);
    }
    if (cfg->f11) {
        *(u16 *)((u8 *)self + 0xc2) |= 4;
    }
    ctrl = func_ov000_02190a30(self, 3);
    if (ctrl != NULL) {
        u32 v;
        float f;
        s32 frame;
        self->unk_c2_6 = 1;
        func_ov000_02191920(self, 0, 0x1000, 0);
        v = cfg->frame;
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
    tbl = res->events != NULL ? (AnimEventTable *)((u8 *)*res->events + 8) : NULL;
    if (tbl != NULL) {
        self->unk_d0 = tbl;
        if (tbl != NULL) {
            if (!tbl->is_ptr) self->unk_d4 = (s16 *)(tbl->entries + tbl->count);
        }
    }
}

}
