#include "types.h"

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/TexObj.h"
#include "nnsys/g2d/g2d_OAM.h"

extern "C" {

// OAM entry as two words, so the bitfields are read and written 32 bits at a time.
typedef struct TexObjOam {
    /* 0x0 */ u32 unk_0_0 : 10;
    /* 0x0 */ u32 objMode : 2;
    /* 0x0 */ u32 unk_0_12 : 20;
    /* 0x4 */ u32 charName : 10;
    /* 0x4 */ u32 priority : 2;
    /* 0x4 */ u32 cParam : 4;
    /* 0x4 */ u32 unk_4_16 : 16;
} TexObjOam;

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

}
