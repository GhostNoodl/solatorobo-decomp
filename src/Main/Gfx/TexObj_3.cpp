#include "types.h"

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/TexObj.h"
#include "nnsys/g2d/g2d_OAM.h"
#include "nitro/fx.h"

extern "C" {

// OAM entry as two words, so the bitfields are read and written 32 bits at a time.
typedef struct TexObjOam {
    /* 0x0 */ u32 unk_0_0 : 10;
    /* 0x0 */ u32 objMode : 2;
    /* 0x0 */ u32 unk_0_12 : 4;
    /* 0x0 */ u32 x : 9;
    /* 0x0 */ u32 unk_0_25 : 7;
    /* 0x4 */ u32 charName : 10;
    /* 0x4 */ u32 priority : 2;
    /* 0x4 */ u32 cParam : 4;
    /* 0x4 */ u32 unk_4_16 : 16;
} TexObjOam;

typedef struct TexObjFlagsB {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 polyId : 6;
    u32 unk_13 : 4;
    u32 hflip : 1;
    u32 vflip : 1;
    u32 alphaOn : 1;
    u32 depthDecal : 1;
    u32 xluDepth : 1;
    u32 unk_22 : 10;
} TexObjFlagsB;

typedef struct TexObjFlags {
    u32 unk_0 : 19;
    u32 flag19 : 1;
    u32 unk_20 : 12;
} TexObjFlags;

typedef TexObjOam *(*TexObjOamFunc)(TexObj *obj, TexObjEntry *e, TexObjOam *oam, u16 *count);

typedef struct TexObjTexRes {
    /* 0x0 */ u8 unk_0[8];
    /* 0x8 */ u32 shift;
} TexObjTexRes;

extern BOOL func_0203e63c(u32 id);
extern u16 func_02024730(TexObjOam *dst, u16 max, void *cell, const void *mtx, const TexObjPair *trans, u16 affineIdx, BOOL doubleAffine);

extern void *func_0203bbfc(GfxSys *sys, int which);

BOOL func_02042958(TexObj *obj, int idx, TexObjEntry *e);

void func_02042720(TexObj *obj, int idx, TexObjOam *oam, void *cell, TexObjEntry *e, u8 affine);
void func_020429a0(TexObj *obj, TexObjOam *oam, void *cell, TexObjEntry *e, u8 affine);

typedef int OamShape;

extern const int data_02082898[][4];

static inline int Oam_GetWidthShift(const OamShape *shape) {
    const u16 shapeBit = (u16)((*shape & 0xc000) >> 14);
    const u16 sizeBit = (u16)((*shape & 0xc0000000) >> 30);
    return data_02082898[shapeBit][sizeBit];
}

static inline void TexObj_ReleaseTransfer(u32 *p) {
    if (*p != 0 && func_0203e63c(*p)) {
        *p = 0;
    }
}

void func_02042628(TexObj *obj, void *cell, TexObjEntry *e, u8 affine) {
    TexObjOam oam[0x80];
    if (((obj->unk_06c << 25) >> 27) == 0) {
        return;
    }
    TexObj_ReleaseTransfer(&obj->pltt.transfer);
    TexObj_ReleaseTransfer(&obj->plttPtr->transfer);
    if (obj->unk_085 & 2) {
        func_02042720(obj, 1, oam, cell, e, affine);
    }
    if (obj->unk_085 & 4) {
        func_02042720(obj, 2, oam, cell, e, affine);
    }
    if (obj->unk_085 & 1) {
        func_020429a0(obj, oam, cell, e, affine);
    }
}

void func_02042720(TexObj *obj, int idx, TexObjOam *oam, void *cell, TexObjEntry *e, u8 affine) {
    NNSG2dOamManagerInstance *mgr;
    TexObjPair trans;
    u16 count;
    int i;
    func_02042958(obj, idx, e);
    if (idx == 1) {
        mgr = (NNSG2dOamManagerInstance *)func_0203bbfc(data_02097d48, 0);
    } else {
        mgr = (NNSG2dOamManagerInstance *)func_0203bbfc(data_02097d48, 1);
    }
    trans.a = obj->pairs[idx].a + 0x80000;
    trans.b = obj->pairs[idx].b + 0x60000;
    if (affine) {
        TexObjVec *mtx = &obj->vecs[idx];
        count = func_02024730(oam, 0x80, cell, mtx, &trans, NNS_G2dEntryOamManagerAffine(mgr, (const MtxFx22 *)mtx), TRUE);
    } else {
        count = func_02024730(oam, 0x80, cell, NULL, &trans, 0, FALSE);
    }
    if (obj->unk_084 & (1 << idx)) {
        u32 base;
        ((u16 *)obj->unk_0f0)[idx] = (((u32 *)&e->key)[idx] >> 5) >> ((TexObjTexRes *)((void **)obj->res)[1])->shift;
        base = oam[0].charName;
        for (i = 0; i < count; i++) {
            oam[i].charName = oam[i].charName - base;
        }
    }
    if (e != NULL && e->unk_0c != 0) {
        oam = ((TexObjOamFunc)e->unk_0c)(obj, e, oam, &count);
    }
    {
        s8 *map = obj->plttPtr->maps[idx];
        int j;
        for (j = 0; j < count; j++) {
            TexObjOam *o = &oam[j];
            o->charName = o->charName + ((u16 *)obj->unk_0f0)[idx];
            if (map != NULL) {
                o->cParam = map[o->cParam];
            }
            if (((TexObjFlags *)&obj->unk_06c)->flag19) {
                o->objMode = 1;
            }
        }
    }
    NNS_G2dEntryOamManagerOam(mgr, (GXOamAttr *)oam, count);
}

BOOL func_02042958(TexObj *obj, int idx, TexObjEntry *e) {
    if (e->transfers[idx] == 0) {
        return TRUE;
    }
    if (func_0203e63c(e->transfers[idx])) {
        e->transfers[idx] = 0;
    } else {
        return FALSE;
    }
    return TRUE;
}


typedef void (*TexObjMtxFunc)(MtxFx43 *mtx, TexObj *obj, TexObjEntry *e);
typedef void (*TexObjDrawFunc)(int i, int x, int y, int z, u16 color, TexObjOam *oam, int *tex, u32 texBase, u32 plttBase, MtxFx43 *mtx, int arg);

extern const u8 data_0208288c[];
extern void func_02043d20(void *obj, int a);
extern void NNS_G3dGeSendDL(const void *list, u32 size);
extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void NNS_G2dSetImageLocation(TexObj *obj, int idx, u32 addr);
extern u32 NNS_G2dGetImageLocation(TexObj *obj, int idx);
extern u32 NNS_G2dGetImagePaletteLocation(PlttSub *sub, int idx);
extern void func_02043100(int x, int y, int z, u32 color, TexObjOam *oam, int *tex, u32 texBase, u32 plttBase, const MtxFx43 *mtx);

static inline TexObjFlagsB *FB(TexObj *obj) {
    return (TexObjFlagsB *)&obj->unk_06c;
}

// Identity 3x3 with a translation row, written the way the SDK matrix code does.
static inline void TexObj_SetTransMtx(MtxFx43 *m, s32 x, s32 y, s32 z) {
    asm {
        str x, [m, #0x24]
        mov r1, #0x1000
        str y, [m, #0x28]
        mov r2, #0
        str z, [m, #0x2c]
        mov r3, #0
        stmia m!, {r1, r2}
        stmia m!, {r2, r3}
        stmia m!, {r1, r2}
        stmia m!, {r2, r3}
        stmia m!, {r1}
    }
}

static inline void TexObj_SetImage(TexObj *obj, u32 addr) {
    *(u32 *)obj->unk_000 = (u32)-1;
    NNS_G2dSetImageLocation(obj, 0, addr);
}

static inline int Oam_GetX(const TexObjOam *o) {
    int x = o->x;
    if (x > 0xff) {
        x |= ~0xff;
    }
    return x;
}

// Polygon attribute command (light mask, polygon mode, cull mode, id, alpha, misc bits).
static inline void G3_PolygonAttr(int light, int mode, int cull, int id, int alpha, int misc) {
    u32 v = light | (mode << 4) | (cull << 6) | misc | (id << 24) | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &v, 1);
}

static inline u32 TexObj_GetPolyMisc(TexObj *obj) {
    u32 m = 0;
    if (FB(obj)->depthDecal) {
        m |= 0x4000;
    }
    if (FB(obj)->xluDepth) {
        m |= 0x800;
    }
    return m;
}

static inline u32 TexObj_GetAlpha(TexObj *obj) {
    if (FB(obj)->alphaOn) {
        return FB(obj)->alpha;
    }
    return 0x1f;
}

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

void func_020429a0(TexObj *obj, TexObjOam *oam, void *cell, TexObjEntry *e, u8 affine) {
    u16 count;
    u32 texBase;
    int z;
    BOOL hflip;
    BOOL vflip;
    u32 plttBase;
    MtxFx43 mtx;
    func_02042958(obj, 0, e);
    func_02043d20((u8 *)data_02097d48 + 0x8b0, 0);
    NNS_G3dGeSendDL(data_0208288c, 0xc);
    if (obj->plttPtr->fmt == 4) {
        obj->unk_018 = 1;
    }
    if (FB(obj)->hflip ? TRUE : FALSE) {
        hflip = TRUE;
    } else {
        hflip = FALSE;
    }
    if (FB(obj)->vflip ? TRUE : FALSE) {
        vflip = TRUE;
    } else {
        vflip = FALSE;
    }
    G3_PolygonAttr(0, 0, 2, FB(obj)->polyId, TexObj_GetAlpha(obj), TexObj_GetPolyMisc(obj));
    count = func_02024730(oam, 0x80, cell, NULL, NULL, 0, FALSE);
    if ((obj->unk_084 & 1) ? TRUE : FALSE) {
        u32 base;
        int i;
        TexObj_SetImage(obj, ((u32)e->key << 15) >> 12);
        base = oam[0].charName;
        for (i = 0; i < count; i++) {
            oam[i].charName = oam[i].charName - base;
        }
    }
    if (e != NULL && e->unk_0c != 0) {
        oam = ((TexObjOamFunc)e->unk_0c)(obj, e, oam, &count);
    }
    texBase = NNS_G2dGetImageLocation(obj, 0);
    plttBase = NNS_G2dGetImagePaletteLocation(&obj->plttPtr->sub, 0);
    if (hflip) {
        int i;
        for (i = 0; i < count; i++) {
            int x = Oam_GetX(&oam[i]);
            OamShape shape = *(const u32 *)&oam[i] & 0xc000c000;
            oam[i].x = (s16)-(x + (1 << Oam_GetWidthShift(&shape)) * 8);
        }
    }
    z = obj->unk_150;
    if (affine) {
        if (obj->unk_15c != 0) {
            ((TexObjMtxFunc)obj->unk_15c)(&mtx, obj, e);
        } else {
            mtx._00 = obj->vecs[0].v[0];
            mtx._01 = obj->vecs[0].v[1];
            mtx._02 = 0;
            mtx._10 = obj->vecs[0].v[2];
            mtx._11 = obj->vecs[0].v[3];
            mtx._12 = 0;
            mtx._20 = 0;
            mtx._21 = 0;
            mtx._22 = 0x1000;
            mtx._30 = 0;
            mtx._31 = 0;
            mtx._32 = 0;
        }
        {
            MtxFx43 t;
            TexObj_SetTransMtx(&t, obj->unk_144, obj->unk_148, 0);
            MTX_Concat43(&mtx, &t, &mtx);
        }
        MTX_TransApply43(&mtx, &mtx, -obj->unk_144, -obj->unk_148, 0);
    }
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    {
        s8 *map = obj->plttPtr->maps[0];
        int i;
        for (i = 0; i < count; i++) {
            if (map != NULL) {
                oam[i].cParam = map[oam[i].cParam];
            }
            NNS_G3dGeBufferOP_N(0x15, NULL, 0);
            if (hflip) {
                *(u32 *)&oam[i] |= 0x10000000;
            }
            if (vflip) {
                *(u32 *)&oam[i] |= 0x20000000;
            }
            if (obj->unk_158 != 0) {
                ((TexObjDrawFunc)obj->unk_158)(i, obj->pairs[0].a + 0x80000, obj->pairs[0].b + 0x60000, z, obj->unk_154, &oam[i], &obj->unk_00c, texBase, plttBase, affine ? &mtx : NULL, e->unk_08);
            } else {
                func_02043100(obj->pairs[0].a + 0x80000, obj->pairs[0].b + 0x60000, z, obj->unk_154, &oam[i], &obj->unk_00c, texBase, plttBase, affine ? &mtx : NULL);
            }
        }
    }
    G3_Cmd1(0x12, 1);
}

}
