#include "types.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

#define NEW_02170620(o)                                    \
    do {                                                   \
        o = (VObj *)func_0203dd9c(0x1e4);                  \
        if (o != NULL) {                                   \
            *(void **)o = data_ov000_021cac60;             \
            o->vfunc_28();                                 \
            *(void **)o = data_ov000_021caec8;             \
            o->vfunc_28();                                 \
            *(void **)o = data_ov000_021cb1b0;             \
            o->vfunc_28();                                 \
            *(void **)o = data_ov000_021cb0b8;             \
            o->vfunc_28();                                 \
        }                                                  \
    } while (0)

extern "C" {
extern void *data_ov000_021ccd54;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *func_0203dd9c(u32 size);
BOOL func_ov000_02184498(void *p);

BOOL func_ov000_02170620(u8 *self, s32 kind, s32 arg) {
    VObj *o;
    if (LFLD(VObj *, self, 0x48) != NULL) {
        return FALSE;
    }
    if (!func_ov000_02184498(data_ov000_021ccd54)) {
        return FALSE;
    }
    switch (kind) {
    case 0:
        NEW_02170620(o);
        LFLD(VObj *, self, 0x48) = o;
        LFLD(s32, o, 0x1dc) = arg;
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) &= ~0x4000000;
        break;
    case 1:
        NEW_02170620(o);
        LFLD(VObj *, self, 0x48) = o;
        LFLD(s32, o, 0x1dc) = arg;
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) |= 0x4000000;
        break;
    case 2:
        NEW_02170620(o);
        LFLD(VObj *, self, 0x48) = o;
        LFLD(s32, o, 0x1dc) = arg;
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) &= ~0x4000000;
        LFLD(s16, LFLD(VObj *, self, 0x48), 0x1d8) = 0x8c;
        break;
    case 3:
        NEW_02170620(o);
        LFLD(VObj *, self, 0x48) = o;
        LFLD(s32, o, 0x1dc) = arg;
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) |= 0x4000000;
        LFLD(s16, LFLD(VObj *, self, 0x48), 0x1d8) = 0x8c;
        break;
    }
    LFLD(VObj *, self, 0x48)->vfunc_08();
    if (LFLD(s32, self, 0x24) != 4) {
        LFLD(s32, self, 0x24) = 0xb;
    }
    return TRUE;
}
}
