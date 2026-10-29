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


typedef struct {
    u16 b0 : 1;
    u16 b1 : 5;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
    u16 rest : 7;
} C2_0219c8e0;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_0219c8e0;

typedef struct {
    u16 b0 : 1;
    u16 mode : 2;
    u16 rest : 13;
} G18_0219c8e0;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} B24_0219c8e0;

#define M ((Model0218fe1c *)(self + 0x368))
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define F(type, off) (*(type *)((u8 *)self + (off)))

extern "C" {
extern char data_ov000_021cc5e3[];
extern char data_ov000_021cc5e9[];
extern char data_ov000_021cc5ef[];
extern char data_ov000_021cc5f6[];
extern char data_ov000_021cc5fd[];
extern char data_ov000_021cc605[];
extern char data_ov000_021cc60a[];
extern u8 *data_0214a424;
void *func_ov003_021ce630(void);
void *func_0203dd9c(u32 size);
ResMdlSet *NNS_G3dGetMdlSet(void *file);
BOOL NNS_G3dBindMdlSet(ResMdlSet *set, void *tex);
BOOL func_ov000_0218ffdc(Model0218fe1c *self, void *res, u8 mode, s32 e);
Model0218fe1c *func_ov000_0218fe1c(Model0218fe1c *self);
BOOL func_ov000_02190cb0(Model0218fe1c *self, const char *name, s32 blend, s32 force);
void func_ov000_021915a0(Model0218fe1c *self);
void func_ov000_02191870(Model0218fe1c *self, void *p);
AnimCtrl *func_ov000_02190a30(Model0218fe1c *self, u32 i);
void func_ov000_02191920(Model0218fe1c *self, s32 index, s16 blend, u8 force);
void func_ov000_02190a80(Model0218fe1c *self, s32 a);
s32 func_ov000_021909a8(Model0218fe1c *self, void *p, const char *name);

void func_ov000_0219c8e0(u8 *self) {
    AnimEventTable *tbl;
    u8 *base;
    const char *name;
    func_ov000_0218ffdc(M, self + 0x450, 0, 1);
    M->unk_b4 = F(u16, 0xc);
    tbl = F(void **, 0x510) != NULL ? (AnimEventTable *)((u8 *)*F(void **, 0x510) + 8) : NULL;
    M->unk_d0 = tbl;
    if (tbl != NULL) {
        if (tbl->is_ptr == 0) {
            M->unk_d4 = (s16 *)&tbl->entries[tbl->count];
        }
    }
    M->unk_e0 = (void *)func_ov003_021ce630;
    {
        const char *nm = data_ov000_021cc5e3;
        if (!F(B24_0219c8e0, 0xb24).b1) {
            nm = data_ov000_021cc5e9;
        }
        func_ov000_02190cb0(M, nm, 0x1000, 1);
    }
    func_ov000_021915a0(M);
    if (F(u8 *, 0xba0) != NULL) {
        AnimCtrl *ctrl;
        void *q = NULL;
        if (F(u8 *, 0xba0)[0x18] != 0) {
            q = self + 0x588;
        }
        func_ov000_02191870(M, q);
        ctrl = func_ov000_02190a30(M, 3);
        if (ctrl != NULL) {
            u32 v;
            float f;
            s32 frame;
            func_ov000_02191920(M, 0, 0x1000, 0);
            v = F(u8 *, 0xba0)[0x18];
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
    F(C2_0219c8e0, 0x42a).b6 = 1;
    func_ov000_02190a80(M, 0x1000);
    F(u8, 0xae3) = 0;
    F(C2_0219c8e0, 0x42a).b0 = 1;
    F(u8, 0xae4) = 0;
    if (!F(B22_0219c8e0, 0xb22).b3) {
        base = self + 0xbc;
        F(u8, 0xae1) = func_ov000_021909a8(M, base + 0x400, data_ov000_021cc5ef);
        F(u8, 0xae0) = func_ov000_021909a8(M, base + 0x400, data_ov000_021cc5f6);
        F(u8, 0xae2) = func_ov000_021909a8(M, base + 0x400, data_ov000_021cc5fd);
    } else {
        base = self + 0xbc;
        F(u8, 0xae1) = func_ov000_021909a8(M, base + 0x400, data_ov000_021cc605);
        F(u8, 0xae0) = func_ov000_021909a8(M, base + 0x400, data_ov000_021cc60a);
        F(u8, 0xae2) = func_ov000_021909a8(M, base + 0x400, data_ov000_021cc5fd);
    }
    if (!F(B22_0219c8e0, 0xb22).b3 && ((G18_0219c8e0 *)(data_0214a424 + 0x18))->mode != 2) {
        Model0218fe1c *m2 = (Model0218fe1c *)(self + 0xac);
        void *tex = M->tex;
        NNS_G3dBindMdlSet(NNS_G3dGetMdlSet(m2->res->mdl_handle != NULL ? m2->res->mdl_handle->unk_00 : NULL), tex);
        F(C2_0219c8e0, 0x16e).b0 = 1;
    }
    if (((G18_0219c8e0 *)(data_0214a424 + 0x18))->mode == 2) {
        F(C2_0219c8e0, 0x42a).b8 = 0;
    } else {
        F(C2_0219c8e0, 0x42a).b8 = 1;
    }
    if (F(B22_0219c8e0, 0xb22).b0 != 0 && F(void *, 0x99c) != NULL) {
        Model0218fe1c *p = (Model0218fe1c *)func_0203dd9c(0xe8);
        if (p != NULL) {
            p = func_ov000_0218fe1c(p);
        }
        F(Model0218fe1c *, 0x998) = p;
        func_ov000_0218ffdc(p, F(void *, 0x99c), 0, 1);
    }
    if (F(Model0218fe1c *, 0x998) != NULL) {
        F(Model0218fe1c *, 0x998)->unk_c2_0 = 1;
    }
}

}

