#include "Main/Res/ResMgr.h"

extern "C" {

extern int GXi_DmaId;
extern u8 data_02fe0000[];
extern void GX_Init(void);
extern void GX_DispOff(void);
extern void FX_Init(void);
extern void OS_InitTick(void);
extern void RTC_Init(void);
extern void func_0203d770(void);
extern void OS_SetIrqFunction(int a, void (*func)(void));
extern s32 OS_EnableIrqMask(int a);
extern s32 GX_VBlankIntr(int a);
extern void OS_GetLowEntropyData(void *dt);
extern void func_020403e4(int seed, int b);
extern s32 GX_ResetBankForTex(void);
extern s32 GX_ResetBankForTexPltt(void);
extern s32 GX_ResetBankForBG(void);
extern s32 GX_ResetBankForBGExtPltt(void);
extern s32 GX_ResetBankForOBJ(void);
extern s32 GX_ResetBankForSubBG(void);
extern s32 GX_ResetBankForSubBGExtPltt(void);
extern s32 GX_ResetBankForSubOBJ(void);
extern s32 GX_ResetBankForSubOBJExtPltt(void);
extern void GX_SetBankForLCDC(int a);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern s32 GX_DisableBankForLCDC(void);
void func_0203d824(void);

extern void OS_Init(void);
extern void OS_EnableITCM(void);
extern void OS_EnableDTCM(void);
extern void *OS_AllocFromArenaLo(int id, u32 size, int align);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern BOOL OS_IsRunOnTwl(void);
void func_0203d9e8(UnkSys *sys);
void func_0203d80c(void);
/* TWL only */
extern void func_0228f87c(int a);
extern void func_0228f808(void *info);
extern void func_0228f7bc(void);

void func_0203d5c4(void) {
    UnkSys *sys;
    OS_Init();
    OS_EnableITCM();
    OS_EnableDTCM();
    if (data_02097dd0 != NULL) {
        return;
    }
    sys = (UnkSys *)OS_AllocFromArenaLo(0, sizeof(UnkSys), 4);
    data_02097dd0 = sys;
    sys->cur = NULL;
    sys->unk_04 = NULL;
    sys->unk_08 = NULL;
    sys->unk_0c = (void *)-1;
    sys->frameCount = 0;
    sys->vblankFunc = NULL;
    sys->frameWait = 1;
    sys->vcount = 0;
    sys->unk_1e = 0;
    sys->unk_1f = 0;
    MI_CpuFill8(sys->unk_20, 0, sizeof(sys->unk_20));
    sys->unk_30 = 0;
    sys->unk_31 = 0;
    sys->node.next = NULL;
    sys->node.value = 0x1000;
    sys->node.unk_6_0 = 0;
    sys->node.unk_6_2 = 0;
    sys->node.unk_6_4 = 0;
    func_0203d9e8(data_02097dd0);
    sys = data_02097dd0;
    if (OS_IsRunOnTwl()) {
        func_0228f87c(0);
        sys->unk_20[0] = (u32)func_0203d80c;
        sys->unk_20[1] = 0;
        func_0228f808(sys->unk_20);
    }
}

void func_0203d6b4(void) {
    int dt[8];
    GXi_DmaId = 3;
    GX_Init();
    GX_DispOff();
    *(volatile u32 *)0x4001000 &= ~0x10000;
    FX_Init();
    OS_InitTick();
    RTC_Init();
    func_0203d770();
    OS_SetIrqFunction(1, func_0203d824);
    OS_EnableIrqMask(1);
    {
        u16 old = *(volatile u16 *)0x4000208;
        *(volatile u16 *)0x4000208 = 1;
    }
    GX_VBlankIntr(1);
    OS_GetLowEntropyData(dt);
    func_020403e4(dt[1] * 3 + dt[3] * 5 + dt[5] * 7 + dt[7] * 11, 0);
}

void func_0203d770(void) {
    GX_ResetBankForTex();
    GX_ResetBankForTexPltt();
    GX_ResetBankForBG();
    GX_ResetBankForBGExtPltt();
    GX_ResetBankForOBJ();
    GX_ResetBankForSubBG();
    GX_ResetBankForSubBGExtPltt();
    GX_ResetBankForSubOBJ();
    GX_ResetBankForSubOBJExtPltt();
    GX_SetBankForLCDC(0x1ff);
    MIi_CpuClearFast(0, (void *)0x6800000, 0xa4000);
    GX_DisableBankForLCDC();
    MIi_CpuClearFast(0xc0, (void *)0x7000000, 0x400);
    MIi_CpuClearFast(0xc0, (void *)0x7000400, 0x400);
    MIi_CpuClearFast(0, (void *)0x5000000, 0x400);
    MIi_CpuClearFast(0, (void *)0x5000400, 0x400);
}

void func_0203d80c(void) {
    data_02097dd0->unk_30 = 1;
}

void func_0203d824(void) {
    UnkSys *sys = data_02097dd0;
    if (++sys->frameCount >= 0x1499700) {
        sys->frameCount = 0x1499700 - 1;
    }
    sys = data_02097dd0;
    if (sys->vblankFunc != NULL) {
        void (*func)(void) = sys->vblankFunc;
        sys->vblankFunc = NULL;
        func();
    }
    sys = data_02097dd0;
    if (sys->frameWait > sys->vcount) {
        sys->vcount++;
    }
    *(volatile u32 *)((u32)data_02fe0000 + 0x3ff8) |= 1;
}

void func_0203d8b0(void) {
    if (OS_IsRunOnTwl()) {
        UnkSys *sys = data_02097dd0;
        if (sys->unk_30 == 1 && sys->unk_31 == 0) {
            func_0228f7bc();
        }
    }
}

}
