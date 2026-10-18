#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern u8 **data_ov000_021ccd68;

static inline u8 *Find0218d2e0(u8 *mgr, u16 id) {
    u8 *res = NULL;
    u8 *grp;
    u8 *p;
    u16 g;
    if (id != 0xffff) {
        g = id & 0xf000;
        p = LFLD(u8 *, mgr, 0);
        grp = NULL;
        if (g == 0xf000) {
            grp = p;
        } else {
            for (; p != NULL; p = LFLD(u8 *, p, 4)) {
                if (LFLD(u16, p, 8) == g) {
                    grp = p;
                    break;
                }
            }
        }
        if (grp != NULL) {
            for (p = LFLD(u8 *, grp, 0xc); p != NULL; p = LFLD(u8 *, p, 8)) {
                if (id == LFLD(u16, p, 0xc)) {
                    res = p;
                    break;
                }
            }
        }
    }
    return res;
}

s32 func_ov000_0218d2e0(u8 *self) {
    u16 id = LFLD(u16, self, 0x90);
    u8 *mgr = (u8 *)data_ov000_021ccd68;
    s32 r = 0;
    u8 *found;
    if (mgr != NULL) {
        found = Find0218d2e0(mgr, id);
    } else {
        found = NULL;
    }
    if (found != NULL) {
        r = LFLD(s32, found, 0x44);
    }
    return r;
}
}
