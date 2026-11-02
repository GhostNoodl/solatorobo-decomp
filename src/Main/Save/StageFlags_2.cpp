#include "Main/Res/StageCmd.h"
#include "Main/Res/ResLoader.h"

extern "C" {

extern StageFlags data_0214aa68;
extern u8 data_0214a428[0x640];
extern void func_0206ccb8(StageFlags *f, u16 a);
extern u16 StageFlags_CountItems(StageFlags *f);

extern s32 func_020591a4(DataRes *res, u8 *buf, s32 a);
extern s32 func_02062370(u8 *buf);
extern s32 SceneStage_Deserialize(u8 *dst, u8 *buf);

typedef struct StageFlagsInit {
    u32 data[5];
} StageFlagsInit;

extern const StageFlagsInit data_02082be4;

static inline void StageFlags_LoadBuf(StageFlags *f) {
    s32 n = 0;
    n += func_020591a4(data_02fe152c, f->buf, 0);
    n += func_02062370(f->buf + n);
    SceneStage_Deserialize(&data_ov000_021ccd54->stageFlags, f->buf + n);
    data_02fe1534.unk_04 = f->unk_518_16;
    data_02fe1534.unk_06 = f->unk_518_28;
}

void StageFlags_Restore(StageFlags *f) {
    MI_CpuCopy8(data_0214a428, f, sizeof(StageFlags));
    MI_CpuCopy8(data_0214a428, &data_0214aa68, 0x640);
    StageFlags_LoadBuf(f);
}

void func_0206ca44(StageFlags *f) {
    MI_CpuCopy8(&data_0214aa68, f, sizeof(StageFlags));
    StageFlags_LoadBuf(f);
}

extern void StageFlags_Reset(StageFlags *f);
extern u32 func_02059270(DataRes *res, u8 *buf);

void func_0206cadc(StageFlags *f) {
    StageFlags tmp;
    u32 i;
    MI_CpuCopy8(data_0214a428, &tmp, sizeof(StageFlags));
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
    func_02059270(data_02fe152c, tmp.buf);
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
