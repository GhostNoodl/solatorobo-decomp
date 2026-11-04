#include "Main/Res/StageCmd.h"
#include "Main/Res/ResLoader.h"

extern "C" {

extern StageFlags gStageFlagsDefault;
extern u8 gStageFlagsSave[0x640];
extern void StageFlags_SetShape(StageFlags *f, u16 a);
extern u16 StageFlags_CountItems(StageFlags *f);

extern s32 DataRes_Unpack(DataRes *res, u8 *buf, s32 a);
extern s32 StageVars_Load(u8 *buf);
extern s32 SceneStage_Deserialize(u8 *dst, u8 *buf);

typedef struct StageFlagsInit {
    u32 data[5];
} StageFlagsInit;

extern const StageFlagsInit StageFlags_InitTable;

static inline void StageFlags_LoadBuf(StageFlags *f) {
    s32 n = 0;
    n += DataRes_Unpack(gDataRes, f->buf, 0);
    n += StageVars_Load(f->buf + n);
    SceneStage_Deserialize(&gSceneCmd->stageFlags, f->buf + n);
    data_02fe1534.unk_04 = f->unk_518_16;
    data_02fe1534.unk_06 = f->unk_518_28;
}

void StageFlags_Restore(StageFlags *f) {
    MI_CpuCopy8(gStageFlagsSave, f, sizeof(StageFlags));
    MI_CpuCopy8(gStageFlagsSave, &gStageFlagsDefault, 0x640);
    StageFlags_LoadBuf(f);
}

void StageFlags_LoadDefault(StageFlags *f) {
    MI_CpuCopy8(&gStageFlagsDefault, f, sizeof(StageFlags));
    StageFlags_LoadBuf(f);
}

extern void StageFlags_Reset(StageFlags *f);
extern u32 DataRes_UnpackKeep(DataRes *res, u8 *buf);

void StageFlags_ResetFromSave(StageFlags *f) {
    StageFlags tmp;
    u32 i;
    MI_CpuCopy8(gStageFlagsSave, &tmp, sizeof(StageFlags));
    StageFlags_Reset(f);
    f->frameCount = tmp.frameCount;
    f->unk_008 = tmp.unk_008;
    f->unk_00a = tmp.unk_00a;
    f->unk_00c = tmp.unk_00c;
    f->unk_010 = tmp.unk_010;
    f->unk_61c = tmp.unk_61c;
    f->unk_014 = tmp.unk_014;
    f->unk_016 = tmp.unk_016;
    f->bits18.mode = tmp.bits18.mode;
    f->bits18.unk_3 = tmp.bits18.unk_3;
    f->bits18.flag7 = tmp.bits18.flag7;
    f->unk_01a = tmp.unk_01a;
    f->unk_01c = tmp.unk_01c;
    f->unk_020 = tmp.unk_020;
    f->unk_024 = tmp.unk_024;
    f->itemTotal = tmp.itemTotal;
    f->shapeId = tmp.shapeId;
    MI_CpuCopy8(tmp.items, f->items, sizeof(f->items));
    MI_CpuCopy8(tmp.entries, f->entries, sizeof(f->entries));
    MI_CpuCopy8(tmp.unk_12c, f->unk_12c, sizeof(f->unk_12c));
    f->unk_518_28 = tmp.unk_518_28;
    DataRes_UnpackKeep(gDataRes, tmp.buf);
    data_02fe1534.unk_06 = f->unk_518_28;
    f->unk_614 = tmp.unk_614;
    f->unk_618 = tmp.unk_618;
    f->unk_620 = tmp.unk_620;
    for (i = 0; i < 5; i++) {
        f->unk_624[i] = tmp.unk_624[i];
    }
    f->unk_638 = tmp.unk_638;
    f->unk_639 = tmp.unk_639;
}

}
