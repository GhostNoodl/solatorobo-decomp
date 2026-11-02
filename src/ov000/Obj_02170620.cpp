#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

#define NEW_02170620(o)                                    \
    do {                                                   \
        o = (VObj *)Heap_Alloc(0x1e4);                  \
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
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *Heap_Alloc(u32 size);
BOOL func_ov000_02184498(void *p);

struct Obj02170620 {
    u8 unk_00[0x24];
    s32 unk_24;
    u8 unk_28[0x20];
    VObj *unk_48;
};

BOOL func_ov000_02170620(Obj02170620 *self, s32 kind, s32 arg) {
    VObj *o;
    if (self->unk_48 != NULL) {
        return FALSE;
    }
    if (!func_ov000_02184498(data_ov000_021ccd54)) {
        return FALSE;
    }
    switch (kind) {
    case 0:
        NEW_02170620(o);
        self->unk_48 = o;
        LFLD(s32, o, 0x1dc) = arg;
        LFLD(u32, self->unk_48, 0xc) &= ~0x4000000;
        break;
    case 1:
        NEW_02170620(o);
        self->unk_48 = o;
        LFLD(s32, o, 0x1dc) = arg;
        LFLD(u32, self->unk_48, 0xc) |= 0x4000000;
        break;
    case 2:
        NEW_02170620(o);
        self->unk_48 = o;
        LFLD(s32, o, 0x1dc) = arg;
        LFLD(u32, self->unk_48, 0xc) &= ~0x4000000;
        LFLD(s16, self->unk_48, 0x1d8) = 0x8c;
        break;
    case 3:
        NEW_02170620(o);
        self->unk_48 = o;
        LFLD(s32, o, 0x1dc) = arg;
        LFLD(u32, self->unk_48, 0xc) |= 0x4000000;
        LFLD(s16, self->unk_48, 0x1d8) = 0x8c;
        break;
    }
    self->unk_48->vfunc_08();
    if (self->unk_24 != 4) {
        self->unk_24 = 0xb;
    }
    return TRUE;
}
}
