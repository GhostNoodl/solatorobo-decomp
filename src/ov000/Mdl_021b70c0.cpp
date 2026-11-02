#include "types.h"
#include "Main/Gfx/PlttRes.h"
#include "ov000/FieldMgr.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

void *NNS_G3dGetMdlSet(void *file);
void *NNS_G3dGetTex(void *file);
BOOL NNS_G3dBindMdlSet(void *mdlset, void *tex);
void *ResMgr_GetArcList(void *a);
void *Path_SkipDir(void *a);
void **ResList_FindType5(void *a, void *b);
void **ResList_FindType4(void *a, void *b);
void NNS_G3dRenderObjInit(void *rob, void *mdl);
void *NNS_G3dGetAnmByIdx(void *file, s32 idx);
u32 NNS_G3dAnmObjCalcSizeRequired(void *anm, void *mdl);
void NNS_G3dAnmObjInit(void *obj, void *anm, void *mdl, void *tex);
void NNS_G3dRenderObjAddAnmObj(void *rob, void *obj);
void NNS_G3dDraw(void *rob);

static inline void *Deref021b70c0(void **p) {
    return p != NULL ? *p : NULL;
}

static inline void *GetResDataByIdx021b70c0(u8 *dict, int idx) {
    if (dict != NULL && (u32)idx < dict[1]) {
        u8 *hdr = dict + LFLD(u16, dict, 6);
        return hdr + 4 + LFLD(u16, hdr, 0) * idx;
    }
    return NULL;
}

static inline void *GetMdlByIdx021b70c0(u8 *set, int idx) {
    if (set != NULL) {
        u32 *data = (u32 *)GetResDataByIdx021b70c0(set + 8, idx);
        if (data != NULL) {
            return set + *data;
        }
    }
    return NULL;
}

#define LOADANM021b70c0(i, FLAGSTMT)                         \
if (res->anm[i] != NULL) {                                   \
    void *a = NNS_G3dGetAnmByIdx(self->res->anm[i], 0);      \
    if (a != NULL) {                                         \
        u32 size = NNS_G3dAnmObjCalcSizeRequired(a, mdl);    \
        if (self->anm[i] == NULL) {                          \
            self->anm[i] = (struct NNSG3dAnmObj_ *)Heap_AllocHi(size, 4); \
        }                                                    \
        NNS_G3dAnmObjInit(self->anm[i], a, mdl, tex);        \
        NNS_G3dRenderObjAddAnmObj(self->rob, self->anm[i]);  \
        FLAGSTMT;                                            \
    }                                                        \
}

// tex is a trailing parameter (callers pass six arguments); it fixes the
// register order of mdl and tex. needMat and nsub are u8 for the
// prologue order of the two stack-argument copies.
void func_ov000_021b70c0(FieldPropModel *self, FieldPropLoader *res, u8 *list, u8 count, u8 needMat, u8 nsub, void *tex) {
    u8 *set;
    u8 *mdl;
    BOOL needJnt;
    u8 i;
    self->res = res;
    set = (u8 *)NNS_G3dGetMdlSet(*res->mdl);
    if (res->tex != NULL) {
        NNS_G3dBindMdlSet(set, NNS_G3dGetTex(*res->tex));
    }
    if (list != NULL && count != 0) {
        for (i = 0; i < count; i++, list += 0x18) {
            void *f = ResMgr_GetArcList(list);
            if (f != NULL) {
                void *n = Path_SkipDir(list);
                void **p = ResList_FindType5(f, n);
                if (p != NULL && *p != NULL) {
                    NNS_G3dBindMdlSet(set, NNS_G3dGetTex(*p));
                } else {
                    p = ResList_FindType4(f, n);
                    if (p == NULL || *p == NULL) {
                        continue;
                    }
                    NNS_G3dBindMdlSet(set, NNS_G3dGetTex(*p));
                }
            }
        }
    }
    self->cur = 0;
    i = self->cur;
    mdl = (u8 *)GetMdlByIdx021b70c0(set, i);
    self->rob = (struct NNSG3dRenderObj_ *)self->robj;
    NNS_G3dRenderObjInit(self->rob, mdl);
    needJnt = TRUE;
    if (res->anm != NULL) {
        tex = NNS_G3dGetTex(*self->res->mdl);
        LOADANM021b70c0(0, needJnt = FALSE)
        LOADANM021b70c0(1, needMat = FALSE)
        LOADANM021b70c0(2, needMat = FALSE)
        LOADANM021b70c0(3, needMat = FALSE)
        LOADANM021b70c0(4, (void)0)
    }
    if (needMat || needJnt) {
        if (needMat) {
            void *p = Heap_AllocHi(mdl[0x18] * 0x38, 4);
            self->matBuf = p;
            LFLD(void *, self->rob, 0x38) = p;
        }
        if (needJnt) {
            void *p = Heap_AllocHi(mdl[0x17] * 0x58, 4);
            self->jntBuf = p;
            LFLD(void *, self->rob, 0x34) = p;
        }
        LFLD(u32, self->rob, 0) |= 2;
        LFLD(u32, self->rob, 0) |= 1;
        NNS_G3dDraw(self->rob);
        LFLD(u32, self->rob, 0) &= ~2;
        LFLD(u32, self->rob, 0) &= ~1;
    }
    if (nsub == 0) {
        return;
    }
    if (nsub > 2) {
        nsub = 2;
    }
    self->nsub = nsub - 1;
    {
        s32 i;
        for (i = 0; i < self->nsub; i++) {
            void *m;
            m = GetMdlByIdx021b70c0(set, i + 1);
            if (m != NULL) {
                self->sub[i] = (struct NNSG3dRenderObj_ *)Heap_AllocHi(0x54, 4);
                NNS_G3dRenderObjInit(self->sub[i], m);
            }
        }
    }
}

}
