#include "types.h"
#include "Main/Gfx/PlttRes.h"
#include "ov000/FieldMgr.h"
#include "nnsys/g3d.h"

extern "C" {

void *ResMgr_GetArcList(void *a);
void *Path_SkipDir(void *a);
void **ResList_FindType5(void *a, void *b);
void **ResList_FindType4(void *a, void *b);

#define LOADANM021b70c0(i, FLAGSTMT)                         \
if (res->anm[i] != NULL) {                                   \
    void *a = NNS_G3dGetAnmByIdx(self->res->anm[i], 0);      \
    if (a != NULL) {                                         \
        u32 size = NNS_G3dAnmObjCalcSizeRequired(a, mdl);    \
        if (self->anm[i] == NULL) {                          \
            self->anm[i] = (NNSG3dAnmObj *)Heap_AllocHi(size, 4); \
        }                                                    \
        NNS_G3dAnmObjInit(self->anm[i], a, mdl, tex);        \
        NNS_G3dRenderObjAddAnmObj(self->rob, self->anm[i]);  \
        FLAGSTMT;                                            \
    }                                                        \
}

// tex is a trailing parameter (callers pass six arguments); it fixes the
// register order of mdl and tex. needMat and nsub are u8 for the
// prologue order of the two stack-argument copies.
void func_ov000_021b70c0(FieldPropModel *self, FieldPropLoader *res, u8 *list, u8 count, u8 needMat, u8 nsub, NNSG3dResTex *tex) {
    NNSG3dResMdlSet *set;
    NNSG3dResMdl *mdl;
    BOOL needJnt;
    u8 i;
    self->res = res;
    set = NNS_G3dGetMdlSet((NNSG3dResFileHeader *)*res->mdl);
    if (res->tex != NULL) {
        NNS_G3dBindMdlSet(set, NNS_G3dGetTex((NNSG3dResFileHeader *)*res->tex));
    }
    if (list != NULL && count != 0) {
        for (i = 0; i < count; i++, list += 0x18) {
            void *f = ResMgr_GetArcList(list);
            if (f != NULL) {
                void *n = Path_SkipDir(list);
                void **p = ResList_FindType5(f, n);
                if (p != NULL && *p != NULL) {
                    NNS_G3dBindMdlSet(set, NNS_G3dGetTex((NNSG3dResFileHeader *)*p));
                } else {
                    p = ResList_FindType4(f, n);
                    if (p == NULL || *p == NULL) {
                        continue;
                    }
                    NNS_G3dBindMdlSet(set, NNS_G3dGetTex((NNSG3dResFileHeader *)*p));
                }
            }
        }
    }
    self->cur = 0;
    i = self->cur;
    mdl = NNS_G3dGetMdlByIdx(set, i);
    self->rob = (NNSG3dRenderObj *)self->robj;
    NNS_G3dRenderObjInit(self->rob, mdl);
    needJnt = TRUE;
    if (res->anm != NULL) {
        tex = NNS_G3dGetTex((NNSG3dResFileHeader *)*self->res->mdl);
        LOADANM021b70c0(0, needJnt = FALSE)
        LOADANM021b70c0(1, needMat = FALSE)
        LOADANM021b70c0(2, needMat = FALSE)
        LOADANM021b70c0(3, needMat = FALSE)
        LOADANM021b70c0(4, (void)0)
    }
    if (needMat || needJnt) {
        if (needMat) {
            void *p = Heap_AllocHi(mdl->info.numMat * sizeof(NNSG3dMatAnmResult), 4);
            self->matBuf = p;
            self->rob->recMatAnm = (NNSG3dMatAnmResult *)p;
        }
        if (needJnt) {
            void *p = Heap_AllocHi(mdl->info.numNode * sizeof(NNSG3dJntAnmResult), 4);
            self->jntBuf = p;
            self->rob->recJntAnm = (NNSG3dJntAnmResult *)p;
        }
        self->rob->flag |= NNS_G3D_RENDEROBJ_FLAG_NOGECMD;
        self->rob->flag |= NNS_G3D_RENDEROBJ_FLAG_RECORD;
        NNS_G3dDraw(self->rob);
        self->rob->flag &= ~NNS_G3D_RENDEROBJ_FLAG_NOGECMD;
        self->rob->flag &= ~NNS_G3D_RENDEROBJ_FLAG_RECORD;
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
            NNSG3dResMdl *m;
            m = NNS_G3dGetMdlByIdx(set, i + 1);
            if (m != NULL) {
                self->sub[i] = (NNSG3dRenderObj *)Heap_AllocHi(sizeof(NNSG3dRenderObj), 4);
                NNS_G3dRenderObjInit(self->sub[i], m);
            }
        }
    }
}

}
