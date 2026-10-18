#include "nitro/os.h"

#define HW_C6_PR_ENABLE     1
#define HW_C6_PR_4KB        0x16
#define HW_C6_PR_BASE_MASK  0xfffff000

void OS_SetProtectionRegion0(u32 param);
void OS_SetProtectionRegion1(u32 param);
void OS_SetProtectionRegion2(u32 param);
void OS_SetProtectionRegion3(u32 param);
void OS_SetProtectionRegion4(u32 param);
void OS_SetProtectionRegion5(u32 param);
void OS_SetProtectionRegion6(u32 param);
void OS_SetProtectionRegion7(u32 param);
u32 OS_GetProtectionRegion0(void);
u32 OS_GetProtectionRegion1(void);
u32 OS_GetProtectionRegion2(void);
u32 OS_GetProtectionRegion3(void);
u32 OS_GetProtectionRegion4(void);
u32 OS_GetProtectionRegion5(void);
u32 OS_GetProtectionRegion6(void);
u32 OS_GetProtectionRegion7(void);
void OS_SetProtectionRegionParam(int regionNo, u32 param);
void OS_SetProtectionRegionEx(int regionNo, u32 address, u32 sizeStr);

static void (*OSi_SetProtectionRegionFunc[8])(u32 param) = {
    OS_SetProtectionRegion0,
    OS_SetProtectionRegion1,
    OS_SetProtectionRegion2,
    OS_SetProtectionRegion3,
    OS_SetProtectionRegion4,
    OS_SetProtectionRegion5,
    OS_SetProtectionRegion6,
    OS_SetProtectionRegion7
};

static u32 (*OSi_GetProtectionRegionFunc[8])(void) = {
    OS_GetProtectionRegion0,
    OS_GetProtectionRegion1,
    OS_GetProtectionRegion2,
    OS_GetProtectionRegion3,
    OS_GetProtectionRegion4,
    OS_GetProtectionRegion5,
    OS_GetProtectionRegion6,
    OS_GetProtectionRegion7
};

void OS_SetProtectionRegionParam (int regionNo, u32 param)
{
    OSi_SetProtectionRegionFunc[regionNo](param);
}

asm void OS_SetProtectionRegion0 (u32 param)
{
    mcr p15, 0, r0, c6, c0, 0
    bx lr
}

asm void OS_SetProtectionRegion1 (u32 param)
{
    mcr p15, 0, r0, c6, c1, 0
    bx lr
}

asm void OS_SetProtectionRegion2 (u32 param)
{
    mcr p15, 0, r0, c6, c2, 0
    bx lr
}

asm void OS_SetProtectionRegion3 (u32 param)
{
    mcr p15, 0, r0, c6, c3, 0
    bx lr
}

asm void OS_SetProtectionRegion4 (u32 param)
{
    mcr p15, 0, r0, c6, c4, 0
    bx lr
}

asm void OS_SetProtectionRegion5 (u32 param)
{
    mcr p15, 0, r0, c6, c5, 0
    bx lr
}

asm void OS_SetProtectionRegion6 (u32 param)
{
    mcr p15, 0, r0, c6, c6, 0
    bx lr
}

asm void OS_SetProtectionRegion7 (u32 param)
{
    mcr p15, 0, r0, c6, c7, 0
    bx lr
}

asm u32 OS_GetProtectionRegion0 (void)
{
    mrc p15, 0, r0, c6, c0, 0
    bx lr
}

asm u32 OS_GetProtectionRegion1 (void)
{
    mrc p15, 0, r0, c6, c1, 0
    bx lr
}

asm u32 OS_GetProtectionRegion2 (void)
{
    mrc p15, 0, r0, c6, c2, 0
    bx lr
}

asm u32 OS_GetProtectionRegion3 (void)
{
    mrc p15, 0, r0, c6, c3, 0
    bx lr
}

asm u32 OS_GetProtectionRegion4 (void)
{
    mrc p15, 0, r0, c6, c4, 0
    bx lr
}

asm u32 OS_GetProtectionRegion5 (void)
{
    mrc p15, 0, r0, c6, c5, 0
    bx lr
}

asm u32 OS_GetProtectionRegion6 (void)
{
    mrc p15, 0, r0, c6, c6, 0
    bx lr
}

asm u32 OS_GetProtectionRegion7 (void)
{
    mrc p15, 0, r0, c6, c7, 0
    bx lr
}

void OS_SetProtectionRegionEx (int regionNo, u32 address, u32 sizeStr)
{
    u32 mask = HW_C6_PR_BASE_MASK << ((sizeStr - HW_C6_PR_4KB) >> 1);
    OS_SetProtectionRegionParam(regionNo, (sizeStr | (address & mask)) | HW_C6_PR_ENABLE);
}
