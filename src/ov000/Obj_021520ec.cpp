#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x6];
    u16 unk_06;
} Msg021521ec;

typedef struct {
    u8 unk_00[0x7c];
    u16 unk_7c;
} Dtcm02fe1534;

extern "C" {

extern u8 data_ov000_021caac8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021ca94c[];
extern u8 data_0208ba70[];
extern void *data_02097e4c;
extern Dtcm02fe1534 data_02fe1534;

void func_0206281c(void);
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);

VObj *func_ov000_021520ec(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021caac8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

BOOL func_ov000_02152168(void) {
    return TRUE;
}

BOOL func_ov000_02152170(void) {
    return FALSE;
}

VObj *func_ov000_02152178(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ca94c);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x148), data_0208ba70);
    VOBJ_AT(self, 0x148)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x90), data_0208ba70);
    VOBJ_AT(self, 0x90)->vfunc_08();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

BOOL func_ov000_021521ec(void *self, Msg021521ec *msg) {
    if (msg == NULL) {
        func_0206281c();
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        return FALSE;
    }
    if (msg->unk_06 == 0) {
        data_02fe1534.unk_7c = 1;
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    } else if (msg->unk_06 == 1) {
        data_02fe1534.unk_7c = 0;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    }
    return FALSE;
}

}
