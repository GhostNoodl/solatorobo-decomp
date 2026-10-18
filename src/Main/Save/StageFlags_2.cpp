#include "Main/Res/StageCmd.h"

extern "C" {

extern StageFlags data_0214aa68;
extern void *func_0203dec8(u32 size, int align);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern u8 data_0214a428[0x640];
extern void func_0206ccb8(StageFlags *f, u32 a);
extern u16 func_0206d02c(StageFlags *f);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern s32 func_020591a4(DataRes *res, u8 *buf, s32 a);
extern s32 func_02062370(u8 *buf);
extern void func_ov000_02181c4c(u8 *dst, u8 *buf);

typedef struct StageFlagsInit {
    u32 data[5];
} StageFlagsInit;

extern const StageFlagsInit data_02082be4;

static inline void StageFlags_LoadBuf(StageFlags *f) {
    s32 n = 0;
    n += func_020591a4(data_02fe152c, f->buf, 0);
    n += func_02062370(f->buf + n);
    func_ov000_02181c4c(&data_ov000_021ccd54->unk_0ac, f->buf + n);
    data_02fe1534.unk_04 = f->unk_518_16;
    data_02fe1534.unk_06 = f->unk_518_28;
}

void func_0206c994(StageFlags *f) {
    MI_CpuCopy8(data_0214a428, f, sizeof(StageFlags));
    MI_CpuCopy8(data_0214a428, &data_0214aa68, 0x640);
    StageFlags_LoadBuf(f);
}

void func_0206ca44(StageFlags *f) {
    MI_CpuCopy8(&data_0214aa68, f, sizeof(StageFlags));
    StageFlags_LoadBuf(f);
}

}
