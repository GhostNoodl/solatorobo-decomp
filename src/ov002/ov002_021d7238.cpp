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
    return NNS_G3dGetResDictIdxByName(dict + 4, name);
}

void func_ov002_021d7238(void *self) {
    u8 *res;
    char name[0x10];
    int idx;
    FIELD(self, 0x6c, void *) = func_02070dcc(*func_0206ef50(FIELD(self, 0x68, u16)));
    res = FIELD(FIELD(self, 0x8, void *), 0x4, u8 *);
    if (res == NULL) {
        return;
    }
    MIi_CpuClear32(0, name, 0x10);
    STD_CopyLStringZeroFill(name, data_ov002_021efddd, 0x10);
    idx = func_ov002_021d7238_find(res, name);
    if (idx < 0) {
        return;
    }
    switch (FIELD(self, 0x68, u16)) {
    case 0x9000:
        NNS_G3dMdlSetMdlAlpha(res, idx, 0x1f);
        break;
    case 0x9001:
        NNS_G3dMdlSetMdlAlpha(res, idx, 0);
        break;
    }
}

}
