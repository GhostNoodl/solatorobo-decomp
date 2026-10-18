#include "Main/Res/ResMgr.h"

extern "C" {

extern int GXi_DmaId;
extern u8 data_02fe0000[];
extern void func_02013428(void);
extern void GX_DispOff(void);
extern void FX_Init(void);
extern void OS_InitTick(void);
extern void RTC_Init(void);
extern void func_0203d770(void);
extern void OS_SetIrqFunction(int a, void (*func)(void));
extern void OS_EnableIrqMask(int a);
extern void GX_VBlankIntr(int a);
extern void OS_GetLowEntropyData(void *dt);
extern void func_020403e4(int seed, int b);
extern void GX_ResetBankForTex(void);
extern void GX_ResetBankForTexPltt(void);
extern void GX_ResetBankForBG(void);
extern void GX_ResetBankForBGExtPltt(void);
extern void GX_ResetBankForOBJ(void);
extern void GX_ResetBankForSubBG(void);
extern void GX_ResetBankForSubBGExtPltt(void);
extern void GX_ResetBankForSubOBJ(void);
extern void GX_ResetBankForSubOBJExtPltt(void);
extern void GX_SetBankForLCDC(int a);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void GX_DisableBankForLCDC(void);
void func_0203d824(void);

void func_0203d6b4(void) {
    int dt[8];
    GXi_DmaId = 3;
    func_02013428();
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

}
