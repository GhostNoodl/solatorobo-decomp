#include "ov000/VObj.h"
#include "ov000/SceneRes.h"

typedef struct {
    u8 unk_00[0x68];
    u16 unk_68;
    u16 unk_6a;
    u8 unk_6c[0x4];
    u16 unk_70;
    u8 unk_72[0x8];
    u16 unk_7a;
} Shared02fe1534;

extern "C" {
extern Shared02fe1534 data_02fe1534;
s32 MsgRes_GetString(void *a, void *b);

u32 func_ov000_0214c01c(u16 arg) {
    data_02fe1534.unk_70 = 1;
    data_02fe1534.unk_7a = arg;
    gSceneResSet.unk_08->vfunc_38(1);
    data_02fe1534.unk_7a = 0;
    return (data_02fe1534.unk_6a << 16) | data_02fe1534.unk_68;
}

s32 func_ov000_0214c064(void *arg) {
    return MsgRes_GetString(gSceneResSet.unk_08->sub, arg);
}

}
