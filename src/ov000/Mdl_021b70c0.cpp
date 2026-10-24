#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad00[0x14];
    void **mdl;
    void **tex;
    void **anm;
} Res021b70c0;

typedef struct {
    Res021b70c0 *res;
    void *anm[5];
    void *buf38;
    void *buf58;
    u8 *rob;
    void *sub[1];
    u8 robj[0x54];
    u8 pad7c[0x3e];
    u8 nsub;
    u8 unk_bb;
} Self021b70c0;

extern "C" {

void *NNS_G3dGetMdlSet(void *file);
void *NNS_G3dGetTex(void *file);
void NNS_G3dBindMdlSet(void *mdlset, void *tex);
void *func_02035d5c(void *a);
void *func_02039674(void *a);
void **func_02034f5c(void *a, void *b);
void **func_02034ec0(void *a, void *b);
void NNS_G3dRenderObjInit(void *rob, void *mdl);
void *NNS_G3dGetAnmByIdx(void *file, s32 idx);
u32 NNS_G3dAnmObjCalcSizeRequired(void *anm, void *mdl);
void *func_0203de84(u32 size, s32 align);
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
            self->anm[i] = func_0203de84(size, 4);           \
        }                                                    \
        NNS_G3dAnmObjInit(self->anm[i], a, mdl, tex);        \
        NNS_G3dRenderObjAddAnmObj(self->rob, self->anm[i]);  \
        FLAGSTMT;                                            \
    }                                                        \
}

// tex is a trailing parameter (callers pass six arguments); it fixes the
// register order of mdl and tex. needMat and nsub are u8 for the
// prologue order of the two stack-argument copies.
void func_ov000_021b70c0(Self021b70c0 *self, Res021b70c0 *res, u8 *list, u8 count, u8 needMat, u8 nsub, void *tex) {
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
            void *f = func_02035d5c(list);
            if (f != NULL) {
                void *n = func_02039674(list);
                void **p = func_02034f5c(f, n);
                if (p != NULL && *p != NULL) {
                    NNS_G3dBindMdlSet(set, NNS_G3dGetTex(*p));
                } else {
                    p = func_02034ec0(f, n);
                    if (p == NULL || *p == NULL) {
                        continue;
                    }
                    NNS_G3dBindMdlSet(set, NNS_G3dGetTex(*p));
                }
            }
        }
    }
    self->unk_bb = 0;
    i = self->unk_bb;
    mdl = (u8 *)GetMdlByIdx021b70c0(set, i);
    self->rob = self->robj;
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
            void *p = func_0203de84(mdl[0x18] * 0x38, 4);
            self->buf38 = p;
            LFLD(void *, self->rob, 0x38) = p;
        }
        if (needJnt) {
            void *p = func_0203de84(mdl[0x17] * 0x58, 4);
            self->buf58 = p;
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
                self->sub[i] = func_0203de84(0x54, 4);
                NNS_G3dRenderObjInit(self->sub[i], m);
            }
        }
    }
}

}
