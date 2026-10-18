#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
void *func_ov000_0218e640(void *mgr, u16 id);

static inline void *FindActor0218c040(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

static inline BOOL IsHere0218c040(u8 *e) {
    u8 *g = data_ov000_021ccd54;
    BOOL ret = FALSE;
    if (g[0xca] == e[0x3e] && g[0xcb] == e[0x3f] && g[0xcc] == e[0x40]) {
        ret = TRUE;
    }
    return ret;
}

s32 func_ov000_0218c040(u8 **list, s32 max, VecFx32 *out, s32 kind, u16 id) {
    s32 n = 0;
    u8 *e;
    s32 i;

    for (e = *list; e != NULL; e = LFLD(u8 *, e, 0x4)) {
        if (!IsHere0218c040(e)) {
            continue;
        }
        if (kind != 0 && kind != (LFLD(u16, e, 0x32) >> 12)) {
            continue;
        }
        if (id != 0xffff && LFLD(u16, e, 0x30) != id) {
            continue;
        }
        if (e[0xb] != 0) {
            for (i = 0; i < e[0xb]; i++) {
                u8 *ent = e + i * 0x24;
                u8 *a = (u8 *)FindActor0218c040(LFLD(u16, ent, 0xe));
                if (a != NULL) {
                    if (id == 0xffff || id == LFLD(u16, a, 0xe)) {
                        out[n].x = LFLD(s32, a, 0x70);
                        out[n].y = LFLD(s32, a, 0x74);
                        out[n].z = LFLD(s32, a, 0x78);
                        n++;
                    }
                } else if (LFLD(u16, ent, 0xe) != 0xffff && (id == 0xffff || id == LFLD(u16, ent, 0xc))) {
                    out[n].x = LFLD(s32, ent, 0x24);
                    out[n].y = LFLD(s32, ent, 0x28);
                    out[n].z = LFLD(s32, ent, 0x2c);
                    n++;
                }
                if (n >= max) {
                    break;
                }
            }
        } else {
            out[n].x = LFLD(s32, e, 0x88);
            out[n].y = LFLD(s32, e, 0x8c);
            out[n].z = LFLD(s32, e, 0x90);
            n++;
        }
        if (n >= max) {
            break;
        }
    }
    return n;
}
}
