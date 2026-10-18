#include "Main/Res/ResMgr.h"

extern "C" {

extern int GXi_DmaId;
extern u8 data_02fe0000[];
extern void func_02013428(void);
extern void func_02013618(void);
extern void FX_Init(void);
extern void func_02019e14(void);
extern void func_0201b348(void);
extern void func_0203d770(void);
extern void OS_SetIrqFunction(int a, void (*func)(void));
extern void OS_EnableIrqMask(int a);
extern void func_020135d0(int a);
extern void func_0201ad28(void *dt);
extern void func_020403e4(int seed, int b);
extern void func_02015744(void);
extern void func_02015758(void);
extern void func_020156d4(void);
extern void func_020156fc(void);
extern void func_020156e8(void);
extern void func_0201576c(void);
extern void func_02015794(void);
extern void func_02015780(void);
extern void func_020157bc(void);
extern void func_020154ec(int a);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_020158a4(void);
void func_0203d824(void);

void func_0203d6b4(void) {
    int dt[8];
    GXi_DmaId = 3;
    func_02013428();
    func_02013618();
    *(volatile u32 *)0x4001000 &= ~0x10000;
    FX_Init();
    func_02019e14();
    func_0201b348();
    func_0203d770();
    OS_SetIrqFunction(1, func_0203d824);
    OS_EnableIrqMask(1);
    {
        u16 old = *(volatile u16 *)0x4000208;
        *(volatile u16 *)0x4000208 = 1;
    }
    func_020135d0(1);
    func_0201ad28(dt);
    func_020403e4(dt[1] * 3 + dt[3] * 5 + dt[5] * 7 + dt[7] * 11, 0);
}

void func_0203d770(void) {
    func_02015744();
    func_02015758();
    func_020156d4();
    func_020156fc();
    func_020156e8();
    func_0201576c();
    func_02015794();
    func_02015780();
    func_020157bc();
    func_020154ec(0x1ff);
    MIi_CpuClearFast(0, (void *)0x6800000, 0xa4000);
    func_020158a4();
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
