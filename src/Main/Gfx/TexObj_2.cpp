#include "types.h"

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

typedef struct TexObjEntry {
    /* 0x00 */ u16 index;
    /* 0x04 */ void *anim;
    /* 0x08 */ int unk_08;
    /* 0x0c */ int unk_0c;
    /* 0x10 */ u32 transfers[3];
    /* 0x1c */ int key;
    /* 0x20 */ int slot0;
    /* 0x24 */ int slot1;
} TexObjEntry; // size 0x28

typedef struct TexObjVec {
    int v[4];
} TexObjVec;

typedef struct TexObjPair {
    int a;
    int b;
} TexObjPair;

typedef struct TexObj {
    /* 0x000 */ u8 unk_000[0xc];
    /* 0x00c */ int unk_00c;
    /* 0x010 */ int unk_010;
    /* 0x014 */ int unk_014;
    /* 0x018 */ int unk_018;
    /* 0x01c */ int unk_01c;
    /* 0x020 */ int unk_020;
    /* 0x024 */ u8 owned;
    /* 0x028 */ void *res;
    /* 0x02c */ char arcName[0x20];
    /* 0x04c */ char name[0x20];
    /* 0x06c */ u32 unk_06c;
    /* 0x070 */ int unk_070;
    /* 0x074 */ int unk_074;
    /* 0x078 */ TexObjEntry *entries;
    /* 0x07c */ int unk_07c;
    /* 0x080 */ int count;
    /* 0x084 */ u8 unk_084;
    /* 0x085 */ u8 unk_085;
    /* 0x088 */ PlttRes pltt;
    /* 0x0ec */ PlttRes *plttPtr;
    /* 0x0f0 */ u8 unk_0f0[8];
    /* 0x0f8 */ u32 texKey;
    /* 0x0fc */ TexObjPair pairs[3];
    /* 0x114 */ TexObjVec vecs[3];
    /* 0x144 */ int unk_144;
    /* 0x148 */ int unk_148;
    /* 0x14c */ int unk_14c;
    /* 0x150 */ int unk_150;
    /* 0x154 */ u16 unk_154;
    /* 0x158 */ int unk_158;
    /* 0x15c */ int unk_15c;
} TexObj;

extern void func_02011218(TexObjVec *v);
extern void func_02024178(TexObj *obj);
extern int func_0202419c(TexObj *obj, int idx);
extern void func_0203bd40(GfxSys *sys, u32 offset, BOOL sub);
extern void (*data_0208afd8)(u32 key);
extern void func_0203e58c(u32 id);
extern void func_02035acc(char *arc, char *name, int mode);
extern void func_02036838(ResMgr *mgr, char *name, int mode, int opt);


void func_020416b4(TexObj *obj, int i);
void func_02041440(TexObj *obj, const char *name, u8 owned);



typedef struct TexObjRes {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ void *unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u16 *dict;
} TexObjRes;

typedef struct TexObjAnim {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ int unk_0c;
} TexObjAnim;

extern u16 *func_02023390(u16 *dict, int idx);
extern void func_020246bc(TexObjAnim *anim, u16 *data, void *res);
extern void func_020246f8(TexObjAnim *anim, u16 *data);
extern void func_02023a34(TexObjAnim *anim, int type, TexObj *obj, void (*cb)(TexObj *));
extern void func_02024710(TexObjAnim *anim, int frame);
extern void func_020435e8(GfxPltt *pltt, void *src, u32 size);
void func_02041c90(TexObj *obj);


typedef struct OamAttrs {
    u16 attr0;
    u16 attr1;
    u16 attr2;
} OamAttrs;

typedef struct OamList {
    /* 0x0 */ u16 count;
    /* 0x4 */ OamAttrs *attrs;
} OamList;

typedef struct OamRes {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ OamAttrs *attrs;
} OamRes;

typedef int OamShape;

extern int data_02082898[][4];
extern int data_020828c8[][4];

static inline OamShape Oam_GetShape(const OamAttrs *attr) {
    return (OamShape)(*(u32 *)attr & 0xc000c000);
}

static inline int Oam_GetWidth(const OamShape *shape) {
    const u16 shapeBit = (u16)((*shape & 0xc000) >> 14);
    const u16 sizeBit = (u16)((*shape & 0xc0000000) >> 30);
    return 8 << data_02082898[shapeBit][sizeBit];
}

static inline int Oam_GetHeight(const OamShape *shape) {
    const u16 shapeBit = (u16)((*shape & 0xc000) >> 14);
    const u16 sizeBit = (u16)((*shape & 0xc0000000) >> 30);
    return 8 << data_020828c8[shapeBit][sizeBit];
}

u32 func_02041bb0(void *unused, OamRes *res) {
    u32 total = 0;
    OamAttrs a = *res->attrs;
    OamShape shape = Oam_GetShape(&a);
    total += Oam_GetHeight(&shape);
    return total;
}

void func_02041c18(TexObj *obj, int value) {
    obj->unk_070 = value;
}

void func_02041c20(TexObj *obj, int idx, int value) {
    obj->entries[idx].unk_08 = value;
}

void func_02041c34(TexObj *obj, int idx, int a, int b) {
    obj->entries[idx].unk_0c = a;
    if (b != 0) {
        obj->entries[idx].unk_08 = b;
    }
}

void func_02041c5c(TexObj *obj, int value) {
    u32 i;
    for (i = 0; i < obj->count; i++) {
        obj->entries[i].unk_0c = value;
    }
}

extern void func_0204205c(TexObj *obj, int idx, int value);

void func_02041c90(TexObj *obj) {
    TexObjEntry *e = (TexObjEntry *)obj->unk_07c;
    if (!(obj->unk_084 & 1)) {
        return;
    }
    func_0204205c(obj, 0, e->index);
}

static inline TexObjEntry *TexObj_GetEntry(TexObj *obj, int idx) {
    return idx >= obj->count ? NULL : &obj->entries[idx];
}

void func_02041cb4(TexObj *obj, int idx) {
    TexObjEntry *e = TexObj_GetEntry(obj, idx);
    if (e == NULL || e->anim == NULL) {
        return;
    }
    obj->unk_07c = (int)e;
    func_02024710((TexObjAnim *)e->anim, obj->unk_074);
}

void func_02041cf8(TexObj *obj, int idx) {
    u16 *data = func_02023390(((TexObjRes *)obj->res)->dict, idx);
    TexObjEntry *e = TexObj_GetEntry(obj, idx);
    TexObjAnim *anim;
    if (e == NULL || (anim = (TexObjAnim *)e->anim) == NULL) {
        return;
    }
    func_020246bc(anim, data, ((TexObjRes *)obj->res)->unk_04);
    func_020246f8((TexObjAnim *)e->anim, data);
    anim->unk_0c = 1;
    func_02023a34(anim, 3, obj, func_02041c90);
    func_02024710((TexObjAnim *)e->anim, 0);
}

extern void func_02039518(void *res);

void func_02041d8c(TexObj *obj) {
    func_02039518(obj->res);
}


typedef struct TexObjImage {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
    /* 0x4 */ int unk_4;
    /* 0x8 */ int unk_8;
} TexObjImage;

typedef struct TexObjRes2 {
    /* 0x00 */ u8 unk_00[0x14];
    /* 0x14 */ TexObjImage *image;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ TexObjImage *image0;
} TexObjRes2;

extern void func_02040dd8(PlttRes *res, int idx, int load);
void func_02041e74(TexObj *obj, int idx);

void func_02041d9c(TexObj *obj, int idx, u32 value) {
    TexObjImage *img;
    obj->unk_085 |= (u8)(1 << idx);
    if (idx == 1) {
        img = ((TexObjRes2 *)obj->res)->image;
    } else if (idx == 2) {
        img = ((TexObjRes2 *)obj->res)->image;
    } else if (idx == 0) {
        img = ((TexObjRes2 *)obj->res)->image0;
    }
    obj->unk_00c = img->unk_2;
    obj->unk_010 = img->unk_0;
    obj->unk_014 = img->unk_4;
    obj->unk_018 = 0;
    obj->unk_01c = 1;
    obj->unk_020 = img->unk_8;
    if (value == 0xffff) {
        func_02041e74(obj, idx);
    } else {
        func_0204205c(obj, idx, value);
    }
    obj->unk_06c = (obj->unk_06c & ~0x1f80) | 0x80;
    obj->unk_06c = (obj->unk_06c & ~0x7c) | 0x7c;
    func_02040dd8(&obj->pltt, idx, ((obj->unk_06c << 30) >> 31) ? TRUE : FALSE);
}


typedef struct TexObjImageInfo {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ u32 size;
    /* 0x14 */ u32 data;
} TexObjImageInfo;

typedef struct TexObjRes3 {
    /* 0x00 */ u8 unk_00[0x4];
    /* 0x04 */ u32 *info;
    /* 0x08 */ u8 unk_08[0xc];
    /* 0x14 */ TexObjImageInfo *image;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ TexObjImageInfo *image0;
} TexObjRes3;

extern u32 func_0203bc20(GfxSys *sys, u32 size, BOOL sub);
extern u32 func_0203e458(int type, u32 src, u32 dst, u32 size, u32 chunk);
extern void func_02024194(TexObj *obj, int idx, u32 addr);
extern void func_020241dc(TexObjImageInfo *img, u32 addr, int idx, TexObj *obj);
extern void func_0203e098(const char *name, u32 value);
extern u32 (*data_0208afd4)(u32 size, int is4x4, int opt);

void func_02041e74(TexObj *obj, int idx) {
    TexObjImageInfo *img;
    u32 slot;
    int type;
    slot = func_0202419c(obj, idx);
    if (slot != -1) {
        return;
    }
    switch (idx) {
    case 1:
    case 2:
        img = ((TexObjRes3 *)obj->res)->image;
        if (idx == 1) {
            type = 2;
            slot = func_0202419c(obj, 1);
            if (slot == -1) {
                slot = func_0203bc20(data_02097d48, img->size, 0);
            }
        } else {
            type = 5;
            slot = func_0202419c(obj, 2);
            if (slot == -1) {
                slot = func_0203bc20(data_02097d48, img->size, 1);
            }
        }
        if ((obj->unk_06c << 30) >> 31) {
            func_0203e458(type, img->data, slot, img->size, 0);
            func_02024194(obj, idx, slot);
        } else {
            func_020241dc(img, slot, idx, obj);
        }
        ((u16 *)obj->unk_0f0)[idx] = (slot >> 5) >> ((TexObjRes3 *)obj->res)->info[2];
        return;
    case 0:
        img = ((TexObjRes3 *)obj->res)->image0;
        if (obj->texKey == 0) {
            func_0203e098(obj->name, 0xffff);
            slot = data_0208afd4(img->size, 0, 0);
            obj->texKey = slot;
        }
        if ((obj->unk_06c << 30) >> 31) {
            u32 addr = (slot << 15) >> 12;
            func_0203e458(0, img->data, addr, img->size, 0);
            func_02024194(obj, 0, addr);
        } else {
            func_020241dc(img, (slot << 15) >> 12, 0, obj);
        }
        return;
    default:
        return;
    }
}

}
