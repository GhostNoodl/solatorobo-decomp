#include "ov002/ov002.h"

extern "C" {





u32 Vram_GetTexTransferId(const char *name);




static inline void ov002_strSet(char *dst, const char **src, u32 n) {
    MIi_CpuClear32(0, dst, n);
    STD_CopyLString(dst, *src, n);
}

static inline void *ov002_findEntry(u8 *d, char *name) {
    u32 *e;
    if (d != NULL && (e = (u32 *)NNS_G3dGetResDataByName((NNSG3dResDict *)(d + 8), (NNSG3dResName *)name)) != NULL) {
        return d + *e;
    }
    return NULL;
}

void Ov002Mdl021efe3c_Load(Ov002Mdl021efe3c *self) {
    ResList *res;
    char buf[16];
    void **anms;
    const char *name;
    res = ResMgr_GetArcList(self->arc);
    self->renderObj = (NNSG3dRenderObj *)Heap_Alloc(sizeof(NNSG3dRenderObj));
    self->file = ResList_FindType4(res, self->name);
    ov002_strSet(buf, &self->name, sizeof(buf));
    self->mdl = (NNSG3dResMdl *)ov002_findEntry((u8 *)NNS_G3dGetMdlSet(self->file->data), buf);
    name = self->name;
    if (self->file != NULL) {
        name = (const char *)G3dRes_SetupVram(name, self->file->data);
    }
    self->texTask = Vram_GetTexTransferId(name);
    NNS_G3dRenderObjInit(self->renderObj, self->mdl);
    anms = (void **)ResList_FindType6(res, self->anmName);
    ov002_strSet(buf, &self->anmName, sizeof(buf));
    if (anms[0] != NULL) {
        void *a = NNS_G3dGetAnmByName(anms[0], (NNSG3dResName *)buf);
        self->anm[0] = (NNSG3dAnmObj *)Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, self->mdl), 4);
        NNS_G3dAnmObjInit(self->anm[0], a, self->mdl, NULL);
        NNS_G3dRenderObjAddAnmObj(self->renderObj, self->anm[0]);
    }
    if (anms[1] != NULL) {
        void *a = NNS_G3dGetAnmByName(anms[1], (NNSG3dResName *)buf);
        self->anm[1] = (NNSG3dAnmObj *)Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, self->mdl), 4);
        NNS_G3dAnmObjInit(self->anm[1], a, self->mdl, NULL);
        NNS_G3dRenderObjAddAnmObj(self->renderObj, self->anm[1]);
    }
    if (anms[2] != NULL) {
        void *a = NNS_G3dGetAnmByName(anms[2], (NNSG3dResName *)buf);
        self->anm[2] = (NNSG3dAnmObj *)Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, self->mdl), 4);
        NNS_G3dAnmObjInit(self->anm[2], a, self->mdl, NULL);
        NNS_G3dRenderObjAddAnmObj(self->renderObj, self->anm[2]);
    }
    if (self->anm[0] != NULL) {
        self->frameCount = ((NNSG3dResAnmCommon *)self->anm[0]->resAnm)->numFrame << 12;
    } else if (self->anm[1] != NULL) {
        self->frameCount = ((NNSG3dResAnmCommon *)self->anm[1]->resAnm)->numFrame << 12;
    } else if (self->anm[2] != NULL) {
        self->frameCount = ((NNSG3dResAnmCommon *)self->anm[2]->resAnm)->numFrame << 12;
    }
}

}
