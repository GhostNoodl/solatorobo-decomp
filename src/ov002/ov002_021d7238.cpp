#include "ov002/ov002.h"

extern "C" {

static inline void *func_ov002_021d7238_getDict(u8 *res) {
    if (res != NULL && FIELD(res, 0x8, s32) != 0) {
        return res + FIELD(res, 0x8, s32);
    }
    return NULL;
}

static inline int func_ov002_021d7238_find(u8 *res, const char *name) {
    u8 *dict = (u8 *)func_ov002_021d7238_getDict(res);
    if (dict == NULL) {
        return -1;
    }
    return NNS_G3dGetResDictIdxByName((NNSG3dResDict *)(dict + 4), (NNSG3dResName *)name);
}

void func_ov002_021d7238(Obj021efe4c *self) {
    u8 *res;
    char name[0x10];
    int idx;
    self->map = (Ov002Shape *)(ParamKind_GetShape(*func_0206ef50(self->unk_68)));
    res = (u8 *)self->unk_08->mdl;
    if (res == NULL) {
        return;
    }
    MIi_CpuClear32(0, name, 0x10);
    STD_CopyLStringZeroFill(name, data_ov002_021efddd, 0x10);
    idx = func_ov002_021d7238_find(res, name);
    if (idx < 0) {
        return;
    }
    switch (self->unk_68) {
    case 0x9000:
        NNS_G3dMdlSetMdlAlpha(res, idx, 0x1f);
        break;
    case 0x9001:
        NNS_G3dMdlSetMdlAlpha(res, idx, 0);
        break;
    }
}

}
