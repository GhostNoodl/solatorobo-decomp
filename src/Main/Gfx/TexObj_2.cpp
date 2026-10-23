#include "types.h"

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Gfx/TexObj.h"

extern "C" {

extern void MTX_Identity22_(TexObjVec *v);
extern void NNS_G2dInitImageProxy(TexObj *obj);
extern int NNS_G2dGetImageLocation(TexObj *obj, int idx);
extern void func_0203bd40(GfxSys *sys, u32 offset, BOOL sub);
extern void (*NNS_GfdDefaultFuncFreeTexVram)(u32 key);
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

extern u16 *NNS_G2dGetAnimSequenceByIdx(u16 *dict, int idx);
extern void NNS_G2dInitCellAnimation(TexObjAnim *anim, u16 *data, void *res);
extern void NNS_G2dSetCellAnimationSequence(TexObjAnim *anim, u16 *data);
extern void NNS_G2dSetAnimCtrlCallBackFunctor(TexObjAnim *anim, int type, TexObj *obj, void (*cb)(TexObj *));
extern void NNS_G2dTickCellAnimation(TexObjAnim *anim, int frame);
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

// Sums the OAM widths of a cell's attributes.
u32 func_02041b10(void *unused, OamList *list) {
    OamAttrs a;
    u32 total;
    u16 n;
    u16 i;
    OamAttrs *attrs;
    total = 0;
    n = list->count;
    i = 0;
    if (i < n) {
        attrs = list->attrs;
        do {
            a.attr0 = attrs[i].attr0;
            a.attr1 = attrs[i].attr1;
            a.attr2 = attrs[i].attr2;
            OamShape shape = Oam_GetShape(&a);
            total += Oam_GetWidth(&shape);
            i++;
        } while (i < n);
    }
    return total;
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
    NNS_G2dTickCellAnimation((TexObjAnim *)e->anim, obj->unk_074);
}

void func_02041cf8(TexObj *obj, int idx) {
    u16 *data = NNS_G2dGetAnimSequenceByIdx(((TexObjRes *)obj->res)->dict, idx);
    TexObjEntry *e = TexObj_GetEntry(obj, idx);
    TexObjAnim *anim;
    if (e == NULL || (anim = (TexObjAnim *)e->anim) == NULL) {
        return;
    }
    NNS_G2dInitCellAnimation(anim, data, ((TexObjRes *)obj->res)->unk_04);
    NNS_G2dSetCellAnimationSequence((TexObjAnim *)e->anim, data);
    anim->unk_0c = 1;
    NNS_G2dSetAnimCtrlCallBackFunctor(anim, 3, obj, func_02041c90);
    NNS_G2dTickCellAnimation((TexObjAnim *)e->anim, 0);
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
extern void NNS_G2dSetImageLocation(TexObj *obj, int idx, u32 addr);
extern void NNS_G2dLoadImage1DMapping(TexObjImageInfo *img, u32 addr, int idx, TexObj *obj);
extern void func_0203e098(const char *name, u32 value);
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32 size, int is4x4, int opt);

void func_02041e74(TexObj *obj, int idx) {
    TexObjImageInfo *img;
    u32 slot;
    int type;
    slot = NNS_G2dGetImageLocation(obj, idx);
    if (slot != -1) {
        return;
    }
    switch (idx) {
    case 1:
    case 2:
        img = ((TexObjRes3 *)obj->res)->image;
        if (idx == 1) {
            type = 2;
            slot = NNS_G2dGetImageLocation(obj, 1);
            if (slot == -1) {
                slot = func_0203bc20(data_02097d48, img->size, 0);
            }
        } else {
            type = 5;
            slot = NNS_G2dGetImageLocation(obj, 2);
            if (slot == -1) {
                slot = func_0203bc20(data_02097d48, img->size, 1);
            }
        }
        if ((obj->unk_06c << 30) >> 31) {
            func_0203e458(type, img->data, slot, img->size, 0);
            NNS_G2dSetImageLocation(obj, idx, slot);
        } else {
            NNS_G2dLoadImage1DMapping(img, slot, idx, obj);
        }
        ((u16 *)obj->unk_0f0)[idx] = (slot >> 5) >> ((TexObjRes3 *)obj->res)->info[2];
        return;
    case 0:
        img = ((TexObjRes3 *)obj->res)->image0;
        if (obj->texKey == 0) {
            func_0203e098(obj->name, 0xffff);
            slot = NNS_GfdDefaultFuncAllocTexVram(img->size, 0, 0);
            obj->texKey = slot;
        }
        if ((obj->unk_06c << 30) >> 31) {
            u32 addr = (slot << 15) >> 12;
            func_0203e458(0, img->data, addr, img->size, 0);
            NNS_G2dSetImageLocation(obj, 0, addr);
        } else {
            NNS_G2dLoadImage1DMapping(img, (slot << 15) >> 12, 0, obj);
        }
        return;
    default:
        return;
    }
}


typedef union TexObjOamA {
    struct {
        u16 attr0;
        u16 attr1;
        u16 attr2;
        u16 attr3;
    };
    struct {
        u32 attr01;
        u32 charName : 10;
        u32 unk_4_10 : 22;
    };
} TexObjOamA;

typedef struct TexObjCell {
    /* 0x0 */ u16 numOam;
    /* 0x4 */ const OamAttrs *attrs;
} TexObjCell;

typedef struct TexObjImgCopy {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ int fmt;
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u32 unk_0c;
    /* 0x10 */ u32 size;
    /* 0x14 */ u32 data;
} TexObjImgCopy;

typedef struct TexObjSeq {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ u16 **frames;
} TexObjSeq;

typedef struct TexObjRes4 {
    /* 0x00 */ u8 unk_00[0x4];
    /* 0x04 */ void *cells;
    /* 0x08 */ u8 unk_08[0x4];
    /* 0x0c */ u16 *dict;
    /* 0x10 */ u8 unk_10[0x4];
    /* 0x14 */ TexObjImgCopy *image;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ TexObjImgCopy *image0;
} TexObjRes4;

extern TexObjCell *NNS_G2dGetCellDataByIdx(void *cells, int idx);

void func_0204205c(TexObj *obj, int idx, int value) {
    TexObjEntry *e;
    TexObjRes4 *res;
    const TexObjCell *cell;
    u16 n;
    u32 total;
    u32 size;
    u32 first;
    u32 slot;
    int type;
    TexObjImgCopy *img;
    TexObjImgCopy info;
    TexObjOamA a;
    u16 i;
    int shift;
    int fmt;

    res = (TexObjRes4 *)obj->res;
    e = TexObj_GetEntry(obj, value);
    if (e != NULL && e->anim != NULL) {
        cell = *(TexObjCell **)((u8 *)e->anim + 0x30);
    } else {
        cell = NNS_G2dGetCellDataByIdx(res->cells, *((TexObjSeq *)NNS_G2dGetAnimSequenceByIdx(res->dict, value))->frames[0]);
    }
    n = cell->numOam;
    obj->unk_084 |= (u8)(1 << idx);
    total = 0;
    switch (idx) {
    case 1:
    case 2:
        img = ((TexObjRes4 *)obj->res)->image;
        shift = (obj->unk_020 & 0x700000) >> 20;
        info = *img;
        for (i = 0; i < n; i = (u16)(i + 1)) {
            u16 attr0 = cell->attrs[i].attr0;
            fmt = img->fmt;
            a.attr1 = cell->attrs[i].attr1;
            a.attr2 = cell->attrs[i].attr2;
            a.attr0 = attr0;
            {
                OamShape shape = Oam_GetShape((OamAttrs *)&a);
                const u16 shapeBit = (u16)((shape & 0xc000) >> 14);
                const u16 sizeBit = (u16)((shape & 0xc0000000) >> 30);
                int w = data_02082898[shapeBit][sizeBit];
                int h = data_020828c8[shapeBit][sizeBit];
                switch (fmt) {
                case 1:
                    size = ((8 << w) << h) << 3;
                    break;
                case 2:
                    size = ((8 << w) << h) << 1;
                    break;
                case 3:
                    size = ((8 << w) << h) << 2;
                    break;
                case 4:
                    size = ((8 << w) << h) << 3;
                    break;
                case 6:
                    size = ((8 << w) << h) << 3;
                    break;
                }
            }
            total += size; total = (total + ((0x20 << shift) - 1)) & ~((0x20 << shift) - 1);
            if (i == 0) {
                first = a.charName << (shift + 5);
            }
        }
        if ((&e->key)[idx] == -1) {
            if (idx == 1) {
                type = 2;
                slot = func_0203bc20(data_02097d48, total, 0);
            } else {
                type = 5;
                slot = func_0203bc20(data_02097d48, total, 1);
            }
            (&e->key)[idx] = slot;
        }
        info.size = total;
        info.data += first;
        if ((obj->unk_06c << 30) >> 31) {
            e->transfers[idx] = func_0203e458(type, info.data, slot, info.size, 0);
            return;
        }
        ((int *)obj)[idx] = -1;
        NNS_G2dLoadImage1DMapping((TexObjImageInfo *)&info, slot, idx, obj);
        ((int *)obj)[idx] = -1;
        return;
    case 0:
        img = ((TexObjRes4 *)obj->res)->image0;
        shift = (obj->unk_020 & 0x700000) >> 20;
        info = *img;
        for (i = 0; i < n; i = (u16)(i + 1)) {
            u16 attr0 = cell->attrs[i].attr0;
            fmt = img->fmt;
            a.attr1 = cell->attrs[i].attr1;
            a.attr2 = cell->attrs[i].attr2;
            a.attr0 = attr0;
            {
                OamShape shape = Oam_GetShape((OamAttrs *)&a);
                const u16 shapeBit = (u16)((shape & 0xc000) >> 14);
                const u16 sizeBit = (u16)((shape & 0xc0000000) >> 30);
                int w = data_02082898[shapeBit][sizeBit];
                int h = data_020828c8[shapeBit][sizeBit];
                switch (fmt) {
                case 1:
                    size = ((8 << w) << h) << 3;
                    break;
                case 2:
                    size = ((8 << w) << h) << 1;
                    break;
                case 3:
                    size = ((8 << w) << h) << 2;
                    break;
                case 4:
                    size = ((8 << w) << h) << 3;
                    break;
                case 6:
                    size = ((8 << w) << h) << 3;
                    break;
                }
            }
            total += size; total = (total + ((0x20 << shift) - 1)) & ~((0x20 << shift) - 1);
            if (i == 0) {
                first = a.charName << (shift + 5);
            }
        }
        if ((&e->key)[idx] == -1) {
            func_0203e098(obj->name, value);
            (&e->key)[idx] = NNS_GfdDefaultFuncAllocTexVram(total, 0, 0);
        }
        info.size = total;
        info.data += first;
        if ((obj->unk_06c << 30) >> 31) {
            e->transfers[idx] = func_0203e458(0, info.data, ((u32)(&e->key)[idx] << 15) >> 12, info.size, 0);
            return;
        }
        ((int *)obj)[idx] = -1;
        NNS_G2dLoadImage1DMapping((TexObjImageInfo *)&info, ((u32)(&e->key)[idx] << 15) >> 12, 0, obj);
        ((int *)obj)[idx] = -1;
        return;
    }
}

}
