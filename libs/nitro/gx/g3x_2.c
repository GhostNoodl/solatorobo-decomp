#include "nitro/gx.h"

int G3X_GetMtxStackLevelPV (s32 *level)
{

    if (reg_G3X_GXSTAT & REG_G3X_GXSTAT_SB_MASK) {
        return -1;
    } else {
        *level = (s32)((reg_G3X_GXSTAT & REG_G3X_GXSTAT_PV_MASK) >> REG_G3X_GXSTAT_PV_SHIFT);
        return 0;
    }
}

int G3X_GetMtxStackLevelPJ (s32 *level)
{

    if (reg_G3X_GXSTAT & REG_G3X_GXSTAT_SB_MASK) {
        return -1;
    } else {
        *level = (s32)((reg_G3X_GXSTAT & REG_G3X_GXSTAT_PJ_MASK) >> REG_G3X_GXSTAT_PJ_SHIFT);
        return 0;
    }
}

int G3X_GetBoxTestResult (s32 *in)
{

    if (reg_G3X_GXSTAT & REG_G3X_GXSTAT_TB_MASK)
        return -1;
    else {
        *in = (s32)(reg_G3X_GXSTAT & REG_G3X_GXSTAT_TR_MASK);
        return 0;
    }
}

#pragma thumb off

asm void GXi_NopClearFifo128_ (register void *pDest)
{
    mov r1, #0
    mov r2, #0
    mov r3, #0
    mov r12, #0
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    stmia r0, {r1 - r3, r12}
    bx lr
}

#pragma thumb reset
