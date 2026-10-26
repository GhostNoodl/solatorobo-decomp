#include "nitro/gxstate.h"

void GX_VRAMCNT_SetLCDC_(int lcdc);

typedef enum {
    GX_VRAMCNT_A_DISABLE           = 0,
    GX_VRAMCNT_A_LCDC_0x06800000   = (0 << REG_GX_VRAMCNT_A_MST_SHIFT) | (0 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_BG_0x06000000     = (1 << REG_GX_VRAMCNT_A_MST_SHIFT) | (0 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_BG_0x06020000     = (1 << REG_GX_VRAMCNT_A_MST_SHIFT) | (1 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_BG_0x06040000     = (1 << REG_GX_VRAMCNT_A_MST_SHIFT) | (2 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_BG_0x06060000     = (1 << REG_GX_VRAMCNT_A_MST_SHIFT) | (3 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_OBJ_0x06400000    = (2 << REG_GX_VRAMCNT_A_MST_SHIFT) | (0 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_OBJ_0x06420000    = (2 << REG_GX_VRAMCNT_A_MST_SHIFT) | (1 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_TEX_0             = (3 << REG_GX_VRAMCNT_A_MST_SHIFT) | (0 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_TEX_1             = (3 << REG_GX_VRAMCNT_A_MST_SHIFT) | (1 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_TEX_2             = (3 << REG_GX_VRAMCNT_A_MST_SHIFT) | (2 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT),
    GX_VRAMCNT_A_TEX_3             = (3 << REG_GX_VRAMCNT_A_MST_SHIFT) | (3 << REG_GX_VRAMCNT_A_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_A_E_SHIFT)
} GX_VRAMCNT_A;

typedef enum {
    GX_VRAMCNT_B_DISABLE           = 0,
    GX_VRAMCNT_B_LCDC_0x06820000   = (0 << REG_GX_VRAMCNT_B_MST_SHIFT) | (0 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_BG_0x06000000     = (1 << REG_GX_VRAMCNT_B_MST_SHIFT) | (0 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_BG_0x06020000     = (1 << REG_GX_VRAMCNT_B_MST_SHIFT) | (1 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_BG_0x06040000     = (1 << REG_GX_VRAMCNT_B_MST_SHIFT) | (2 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_BG_0x06060000     = (1 << REG_GX_VRAMCNT_B_MST_SHIFT) | (3 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_OBJ_0x06400000    = (2 << REG_GX_VRAMCNT_B_MST_SHIFT) | (0 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_OBJ_0x06420000    = (2 << REG_GX_VRAMCNT_B_MST_SHIFT) | (1 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_TEX_0             = (3 << REG_GX_VRAMCNT_B_MST_SHIFT) | (0 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_TEX_1             = (3 << REG_GX_VRAMCNT_B_MST_SHIFT) | (1 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_TEX_2             = (3 << REG_GX_VRAMCNT_B_MST_SHIFT) | (2 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT),
    GX_VRAMCNT_B_TEX_3             = (3 << REG_GX_VRAMCNT_B_MST_SHIFT) | (3 << REG_GX_VRAMCNT_B_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_B_E_SHIFT)
} GX_VRAMCNT_B;

typedef enum {
    GX_VRAMCNT_C_DISABLE           = 0,
    GX_VRAMCNT_C_LCDC_0x06840000   = (0 << REG_GX_VRAMCNT_C_MST_SHIFT) | (0 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_BG_0x06000000     = (1 << REG_GX_VRAMCNT_C_MST_SHIFT) | (0 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_BG_0x06020000     = (1 << REG_GX_VRAMCNT_C_MST_SHIFT) | (1 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_BG_0x06040000     = (1 << REG_GX_VRAMCNT_C_MST_SHIFT) | (2 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_BG_0x06060000     = (1 << REG_GX_VRAMCNT_C_MST_SHIFT) | (3 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_ARM7_0x06000000   = (2 << REG_GX_VRAMCNT_C_MST_SHIFT) | (0 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_ARM7_0x06020000   = (2 << REG_GX_VRAMCNT_C_MST_SHIFT) | (1 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_TEX_0             = (3 << REG_GX_VRAMCNT_C_MST_SHIFT) | (0 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_TEX_1             = (3 << REG_GX_VRAMCNT_C_MST_SHIFT) | (1 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_TEX_2             = (3 << REG_GX_VRAMCNT_C_MST_SHIFT) | (2 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_TEX_3             = (3 << REG_GX_VRAMCNT_C_MST_SHIFT) | (3 << REG_GX_VRAMCNT_C_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT),
    GX_VRAMCNT_C_SUBBG_0x06200000  = (4 << REG_GX_VRAMCNT_C_MST_SHIFT) | (1 << REG_GX_VRAMCNT_C_E_SHIFT)
} GX_VRAMCNT_C;

typedef enum {
    GX_VRAMCNT_D_DISABLE           = 0,
    GX_VRAMCNT_D_LCDC_0x06860000   = (0 << REG_GX_VRAMCNT_D_MST_SHIFT) | (0 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_BG_0x06000000     = (1 << REG_GX_VRAMCNT_D_MST_SHIFT) | (0 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_BG_0x06020000     = (1 << REG_GX_VRAMCNT_D_MST_SHIFT) | (1 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_BG_0x06040000     = (1 << REG_GX_VRAMCNT_D_MST_SHIFT) | (2 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_BG_0x06060000     = (1 << REG_GX_VRAMCNT_D_MST_SHIFT) | (3 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_ARM7_0x06000000   = (2 << REG_GX_VRAMCNT_D_MST_SHIFT) | (0 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_ARM7_0x06020000   = (2 << REG_GX_VRAMCNT_D_MST_SHIFT) | (1 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_TEX_0             = (3 << REG_GX_VRAMCNT_D_MST_SHIFT) | (0 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_TEX_1             = (3 << REG_GX_VRAMCNT_D_MST_SHIFT) | (1 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_TEX_2             = (3 << REG_GX_VRAMCNT_D_MST_SHIFT) | (2 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_TEX_3             = (3 << REG_GX_VRAMCNT_D_MST_SHIFT) | (3 << REG_GX_VRAMCNT_D_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT),
    GX_VRAMCNT_D_SUBOBJ_0x06600000 = (4 << REG_GX_VRAMCNT_D_MST_SHIFT) | (1 << REG_GX_VRAMCNT_D_E_SHIFT)
} GX_VRAMCNT_D;

typedef enum {
    GX_VRAMCNT_E_DISABLE           = 0,
    GX_VRAMCNT_E_LCDC_0x06880000   = (0 << REG_GX_VRAMCNT_E_MST_SHIFT) | (1 << REG_GX_VRAMCNT_E_E_SHIFT),
    GX_VRAMCNT_E_BG_0x06000000     = (1 << REG_GX_VRAMCNT_E_MST_SHIFT) | (1 << REG_GX_VRAMCNT_E_E_SHIFT),
    GX_VRAMCNT_E_OBJ_0x06400000    = (2 << REG_GX_VRAMCNT_E_MST_SHIFT) | (1 << REG_GX_VRAMCNT_E_E_SHIFT),
    GX_VRAMCNT_E_TEXPLTT_0123      = (3 << REG_GX_VRAMCNT_E_MST_SHIFT) | (1 << REG_GX_VRAMCNT_E_E_SHIFT),
    GX_VRAMCNT_E_BGEXTPLTT_0123    = (4 << REG_GX_VRAMCNT_E_MST_SHIFT) | (1 << REG_GX_VRAMCNT_E_E_SHIFT)
}
GX_VRAMCNT_E;

typedef enum {
    GX_VRAMCNT_F_DISABLE           = 0,
    GX_VRAMCNT_F_LCDC_0x06890000   = (0 << REG_GX_VRAMCNT_F_MST_SHIFT) | (0 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_BG_0x06000000     = (1 << REG_GX_VRAMCNT_F_MST_SHIFT) | (0 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_BG_0x06004000     = (1 << REG_GX_VRAMCNT_F_MST_SHIFT) | (1 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_BG_0x06010000     = (1 << REG_GX_VRAMCNT_F_MST_SHIFT) | (2 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_BG_0x06014000     = (1 << REG_GX_VRAMCNT_F_MST_SHIFT) | (3 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_OBJ_0x06400000    = (2 << REG_GX_VRAMCNT_F_MST_SHIFT) | (0 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_OBJ_0x06404000    = (2 << REG_GX_VRAMCNT_F_MST_SHIFT) | (1 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_OBJ_0x06410000    = (2 << REG_GX_VRAMCNT_F_MST_SHIFT) | (2 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_OBJ_0x06414000    = (2 << REG_GX_VRAMCNT_F_MST_SHIFT) | (3 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_TEXPLTT_0         = (3 << REG_GX_VRAMCNT_F_MST_SHIFT) | (0 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_TEXPLTT_1         = (3 << REG_GX_VRAMCNT_F_MST_SHIFT) | (1 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_TEXPLTT_4         = (3 << REG_GX_VRAMCNT_F_MST_SHIFT) | (2 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_TEXPLTT_5         = (3 << REG_GX_VRAMCNT_F_MST_SHIFT) | (3 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_BGEXTPLTT_01      = (4 << REG_GX_VRAMCNT_F_MST_SHIFT) | (0 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_BGEXTPLTT_23      = (4 << REG_GX_VRAMCNT_F_MST_SHIFT) | (1 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT),
    GX_VRAMCNT_F_OBJEXTPLTT        = (5 << REG_GX_VRAMCNT_F_MST_SHIFT) | (0 << REG_GX_VRAMCNT_F_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_F_E_SHIFT)
} GX_VRAMCNT_F;

typedef enum {
    GX_VRAMCNT_G_DISABLE           = 0,
    GX_VRAMCNT_G_LCDC_0x06894000   = (0 << REG_GX_VRAMCNT_G_MST_SHIFT) | (0 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_BG_0x06000000     = (1 << REG_GX_VRAMCNT_G_MST_SHIFT) | (0 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_BG_0x06004000     = (1 << REG_GX_VRAMCNT_G_MST_SHIFT) | (1 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_BG_0x06010000     = (1 << REG_GX_VRAMCNT_G_MST_SHIFT) | (2 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_BG_0x06014000     = (1 << REG_GX_VRAMCNT_G_MST_SHIFT) | (3 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_OBJ_0x06400000    = (2 << REG_GX_VRAMCNT_G_MST_SHIFT) | (0 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_OBJ_0x06404000    = (2 << REG_GX_VRAMCNT_G_MST_SHIFT) | (1 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_OBJ_0x06410000    = (2 << REG_GX_VRAMCNT_G_MST_SHIFT) | (2 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_OBJ_0x06414000    = (2 << REG_GX_VRAMCNT_G_MST_SHIFT) | (3 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_TEXPLTT_0         = (3 << REG_GX_VRAMCNT_G_MST_SHIFT) | (0 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_TEXPLTT_1         = (3 << REG_GX_VRAMCNT_G_MST_SHIFT) | (1 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_TEXPLTT_4         = (3 << REG_GX_VRAMCNT_G_MST_SHIFT) | (2 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_TEXPLTT_5         = (3 << REG_GX_VRAMCNT_G_MST_SHIFT) | (3 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_BGEXTPLTT_01      = (4 << REG_GX_VRAMCNT_G_MST_SHIFT) | (0 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_BGEXTPLTT_23      = (4 << REG_GX_VRAMCNT_G_MST_SHIFT) | (1 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT),
    GX_VRAMCNT_G_OBJEXTPLTT        = (5 << REG_GX_VRAMCNT_G_MST_SHIFT) | (0 << REG_GX_VRAMCNT_G_OFS_SHIFT) | (1 << REG_GX_VRAMCNT_G_E_SHIFT)
} GX_VRAMCNT_G;

typedef enum {
    GX_VRAMCNT_H_DISABLE           = 0,
    GX_VRAMCNT_H_LCDC_0x06898000   = (0 << REG_GX_VRAMCNT_H_MST_SHIFT) | (1 << REG_GX_VRAMCNT_H_E_SHIFT),
    GX_VRAMCNT_H_SUBBG_0x06200000  = (1 << REG_GX_VRAMCNT_H_MST_SHIFT) | (1 << REG_GX_VRAMCNT_H_E_SHIFT),
    GX_VRAMCNT_H_SUBBGEXTPLTT_0123 = (2 << REG_GX_VRAMCNT_H_MST_SHIFT) | (1 << REG_GX_VRAMCNT_H_E_SHIFT)
} GX_VRAMCNT_H;

typedef enum {
    GX_VRAMCNT_I_DISABLE           = 0,
    GX_VRAMCNT_I_LCDC_0x068A0000   = (0 << REG_GX_VRAMCNT_I_MST_SHIFT) | (1 << REG_GX_VRAMCNT_I_E_SHIFT),
    GX_VRAMCNT_I_SUBBG_0x06208000  = (1 << REG_GX_VRAMCNT_I_MST_SHIFT) | (1 << REG_GX_VRAMCNT_I_E_SHIFT),
    GX_VRAMCNT_I_SUBOBJ_0x06600000 = (2 << REG_GX_VRAMCNT_I_MST_SHIFT) | (1 << REG_GX_VRAMCNT_I_E_SHIFT),
    GX_VRAMCNT_I_SUBOBJEXTPLTT     = (3 << REG_GX_VRAMCNT_I_MST_SHIFT) | (1 << REG_GX_VRAMCNT_I_E_SHIFT)
} GX_VRAMCNT_I;

    #pragma thumb off

static inline void GX_VRAMCNT_SetBG_ (GXVRamBG bg)
{
    switch (bg) {
    case GX_VRAM_BG_128_D:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06000000;
        break;
    case GX_VRAM_BG_256_CD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06020000;
    case GX_VRAM_BG_128_C:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_BG_0x06000000;
        break;
    case GX_VRAM_BG_384_BCD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06040000;
    case GX_VRAM_BG_256_BC:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_BG_0x06020000;
    case GX_VRAM_BG_128_B:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_BG_0x06000000;
        break;
    case GX_VRAM_BG_512_ABCD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06060000;
    case GX_VRAM_BG_384_ABC:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_BG_0x06040000;
    case GX_VRAM_BG_256_AB:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_BG_0x06020000;
    case GX_VRAM_BG_128_A:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_BG_0x06000000;
    case GX_VRAM_BG_NONE:
        break;
    case GX_VRAM_BG_384_ABD:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_BG_0x06000000;
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_BG_0x06020000;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06040000;
        break;
    case GX_VRAM_BG_384_ACD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06040000;
    case GX_VRAM_BG_256_AC:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_BG_0x06000000;
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_BG_0x06020000;
        break;
    case GX_VRAM_BG_256_AD:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_BG_0x06000000;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06020000;
        break;
    case GX_VRAM_BG_256_BD:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_BG_0x06000000;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06020000;
        break;
    case GX_VRAM_BG_96_EFG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BG_0x06014000;
    case GX_VRAM_BG_80_EF:
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_BG_0x06010000;
    case GX_VRAM_BG_64_E:
        reg_GX_VRAMCNT_E = (u8)GX_VRAMCNT_E_BG_0x06000000;
        break;
    case GX_VRAM_BG_80_EG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BG_0x06010000;
        reg_GX_VRAMCNT_E = (u8)GX_VRAMCNT_E_BG_0x06000000;
        break;
    case GX_VRAM_BG_32_FG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BG_0x06004000;
    case GX_VRAM_BG_16_F:
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_BG_0x06000000;
        break;
    case GX_VRAM_BG_16_G:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BG_0x06000000;
        break;
    default:
        break;
    }
}

static inline void GX_VRAMCNT_SetBGEx1_ (GXVRamBG bg)
{
    switch (bg) {
    case GX_VRAM_BG_96_EFG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BG_0x06014000;
    case GX_VRAM_BG_80_EF:
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_BG_0x06010000;
    case GX_VRAM_BG_64_E:
        reg_GX_VRAMCNT_E = (u8)GX_VRAMCNT_E_BG_0x06000000;
        break;
    case GX_VRAM_BG_80_EG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BG_0x06010000;
        reg_GX_VRAMCNT_E = (u8)GX_VRAMCNT_E_BG_0x06000000;
        break;
    case GX_VRAM_BG_32_FG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BG_0x06004000;
    case GX_VRAM_BG_16_F:
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_BG_0x06000000;
        break;
    case GX_VRAM_BG_16_G:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BG_0x06000000;
        break;
    default:
        break;
    }
}

static inline void GX_VRAMCNT_SetBGEx2_ (GXVRamBG bg)
{
    switch (bg) {
    case GX_VRAM_BG_128_D:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06020000;
        break;
    case GX_VRAM_BG_256_CD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06040000;
    case GX_VRAM_BG_128_C:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_BG_0x06020000;
        break;
    case GX_VRAM_BG_384_BCD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06060000;
    case GX_VRAM_BG_256_BC:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_BG_0x06040000;
    case GX_VRAM_BG_128_B:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_BG_0x06020000;
        break;
    case GX_VRAM_BG_384_ABC:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_BG_0x06060000;
    case GX_VRAM_BG_256_AB:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_BG_0x06040000;
    case GX_VRAM_BG_128_A:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_BG_0x06020000;
    case GX_VRAM_BG_NONE:
        break;
    case GX_VRAM_BG_384_ABD:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_BG_0x06020000;
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_BG_0x06040000;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06060000;
        break;
    case GX_VRAM_BG_384_ACD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06060000;
    case GX_VRAM_BG_256_AC:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_BG_0x06020000;
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_BG_0x06040000;
        break;
    case GX_VRAM_BG_256_AD:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_BG_0x06020000;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06040000;
        break;
    case GX_VRAM_BG_256_BD:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_BG_0x06020000;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_BG_0x06040000;
        break;
    default:
        break;
    }
}

static inline void GX_VRAMCNT_SetOBJ_ (GXVRamOBJ obj)
{
    switch (obj) {
    case GX_VRAM_OBJ_256_AB:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_OBJ_0x06420000;
    case GX_VRAM_OBJ_128_A:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_OBJ_0x06400000;
    case GX_VRAM_OBJ_NONE:
        break;
    case GX_VRAM_OBJ_128_B:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_OBJ_0x06400000;
        break;
    case GX_VRAM_OBJ_96_EFG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_OBJ_0x06414000;
    case GX_VRAM_OBJ_80_EF:
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_OBJ_0x06410000;
    case GX_VRAM_OBJ_64_E:
        reg_GX_VRAMCNT_E = (u8)GX_VRAMCNT_E_OBJ_0x06400000;
        break;
    case GX_VRAM_OBJ_80_EG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_OBJ_0x06410000;
        reg_GX_VRAMCNT_E = (u8)GX_VRAMCNT_E_OBJ_0x06400000;
        break;
    case GX_VRAM_OBJ_32_FG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_OBJ_0x06404000;
    case GX_VRAM_OBJ_16_F:
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_OBJ_0x06400000;
        break;
    case GX_VRAM_OBJ_16_G:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_OBJ_0x06400000;
        break;
    default:
        break;
    }
}

static inline void GX_VRAMCNT_SetARM7_ (GXVRamARM7 arm7)
{
    switch (arm7) {
    case GX_VRAM_ARM7_256_CD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_ARM7_0x06020000;
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_ARM7_0x06000000;
        break;
    case GX_VRAM_ARM7_128_C:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_ARM7_0x06000000;
        break;
    case GX_VRAM_ARM7_128_D:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_ARM7_0x06000000;
    case GX_VRAM_ARM7_NONE:
        break;
    default:
        break;
    }
}

static inline void texOn_ (void)
{
    reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT &
                               ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK)) |
                              REG_G3X_DISP3DCNT_TME_MASK);
}

static inline void texOff_ (void)
{
    reg_G3X_DISP3DCNT &= (u16) ~(REG_G3X_DISP3DCNT_TME_MASK |
                                 REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
}

static inline void GX_VRAMCNT_SetTEX_ (GXVRamTex tex)
{
    if (tex == GX_VRAM_TEX_NONE) {
        texOff_();
        return;
    }

    texOn_();

    switch (tex) {
    case GX_VRAM_TEX_01_AC:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_TEX_0;
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_TEX_1;
        break;
    case GX_VRAM_TEX_01_AD:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_TEX_0;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_TEX_1;
        break;
    case GX_VRAM_TEX_01_BD:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_TEX_0;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_TEX_1;
        break;
    case GX_VRAM_TEX_012_ABD:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_TEX_0;
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_TEX_1;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_TEX_2;
        break;
    case GX_VRAM_TEX_012_ACD:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_TEX_0;
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_TEX_1;
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_TEX_2;
        break;
    case GX_VRAM_TEX_0_D:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_TEX_0;
        break;
    case GX_VRAM_TEX_01_CD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_TEX_1;
    case GX_VRAM_TEX_0_C:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_TEX_0;
        break;
    case GX_VRAM_TEX_012_BCD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_TEX_2;
    case GX_VRAM_TEX_01_BC:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_TEX_1;
    case GX_VRAM_TEX_0_B:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_TEX_0;
        break;
    case GX_VRAM_TEX_0123_ABCD:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_TEX_3;
    case GX_VRAM_TEX_012_ABC:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_TEX_2;
    case GX_VRAM_TEX_01_AB:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_TEX_1;
    case GX_VRAM_TEX_0_A:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_TEX_0;
        break;
    default:
        break;
    }
}

static inline void clearImageOn_ (void)
{
    reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_PRI_MASK;
}

static inline void clearImageOff_ (void)
{
    reg_G3X_DISP3DCNT &= ~REG_G3X_DISP3DCNT_PRI_MASK;
}

static inline void GX_VRAMCNT_SetCLRIMG_ (GXVRamClearImage clrImg)
{
    switch (clrImg) {
    case GX_VRAM_CLEARIMAGE_256_AB:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_TEX_2;
    case GX_VRAM_CLEARDEPTH_128_B:
        reg_GX_VRAMCNT_B = (u8)GX_VRAMCNT_B_TEX_3;
        clearImageOn_();
        break;
    case GX_VRAM_CLEARIMAGE_256_CD:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_TEX_2;
    case GX_VRAM_CLEARDEPTH_128_D:
        reg_GX_VRAMCNT_D = (u8)GX_VRAMCNT_D_TEX_3;
        clearImageOn_();
        break;
    case GX_VRAM_CLEARIMAGE_NONE:
        clearImageOff_();
        break;
    case GX_VRAM_CLEARDEPTH_128_A:
        reg_GX_VRAMCNT_A = (u8)GX_VRAMCNT_A_TEX_3;
        clearImageOn_();
        break;
    case GX_VRAM_CLEARDEPTH_128_C:
        reg_GX_VRAMCNT_C = (u8)GX_VRAMCNT_C_TEX_3;
        clearImageOn_();
        break;
    default:
        break;
    }
}

static inline void GX_VRAMCNT_SetTEXPLTT_ (GXVRamTexPltt texPltt)
{
    switch (texPltt) {
    case GX_VRAM_TEXPLTT_01_FG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_TEXPLTT_1;
    case GX_VRAM_TEXPLTT_0_F:
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_TEXPLTT_0;
        break;
    case GX_VRAM_TEXPLTT_0_G:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_TEXPLTT_0;
        break;
    case GX_VRAM_TEXPLTT_012345_EFG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_TEXPLTT_5;
    case GX_VRAM_TEXPLTT_01234_EF:
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_TEXPLTT_4;
    case GX_VRAM_TEXPLTT_0123_E:
        reg_GX_VRAMCNT_E = (u8)GX_VRAMCNT_E_TEXPLTT_0123;
        break;
    case GX_VRAM_TEXPLTT_NONE:
        break;
    default:
        break;
    }
}

static inline void bgExtPlttOn_ (void)
{
    reg_GX_DISPCNT |= REG_GX_DISPCNT_BG_MASK;
}

static inline void bgExtPlttOff_ (void)
{
    reg_GX_DISPCNT &= ~REG_GX_DISPCNT_BG_MASK;
}

static inline void GX_VRAMCNT_SetBGEXTPLTT_ (GXVRamBGExtPltt bgExtPltt)
{
    switch (bgExtPltt) {
    case GX_VRAM_BGEXTPLTT_0123_E:
        bgExtPlttOn_();
        reg_GX_VRAMCNT_E = (u8)GX_VRAMCNT_E_BGEXTPLTT_0123;
        break;
    case GX_VRAM_BGEXTPLTT_23_G:
        bgExtPlttOn_();
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BGEXTPLTT_23;
        break;
    case GX_VRAM_BGEXTPLTT_0123_FG:
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_BGEXTPLTT_23;
    case GX_VRAM_BGEXTPLTT_01_F:
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_BGEXTPLTT_01;
        bgExtPlttOn_();
        break;
    case GX_VRAM_BGEXTPLTT_NONE:
        bgExtPlttOff_();
        break;
    default:
        break;
    }
}

static inline void objExtPlttOn_ (void)
{
    reg_GX_DISPCNT |= REG_GX_DISPCNT_O_MASK;
}

static inline void objExtPlttOff_ (void)
{
    reg_GX_DISPCNT &= ~REG_GX_DISPCNT_O_MASK;
}

static inline void GX_VRAMCNT_SetOBJEXTPLTT_ (GXVRamOBJExtPltt objExtPltt)
{
    switch (objExtPltt) {
    case GX_VRAM_OBJEXTPLTT_0_F:
        objExtPlttOn_();
        reg_GX_VRAMCNT_F = (u8)GX_VRAMCNT_F_OBJEXTPLTT;
        break;
    case GX_VRAM_OBJEXTPLTT_0_G:
        objExtPlttOn_();
        reg_GX_VRAMCNT_G = (u8)GX_VRAMCNT_G_OBJEXTPLTT;
        break;
    case GX_VRAM_OBJEXTPLTT_NONE:
        objExtPlttOff_();
        break;
    default:
        break;
    }
}

static inline void GX_VRAMCNT_SetSubBG_ (GXVRamSubBG bg)
{
    switch (bg) {
    case GX_VRAM_SUB_BG_128_C:
        reg_GX_VRAMCNT_C = GX_VRAMCNT_C_SUBBG_0x06200000;
        break;
    case GX_VRAM_SUB_BG_48_HI:
        reg_GX_VRAMCNT_I = GX_VRAMCNT_I_SUBBG_0x06208000;
    case GX_VRAM_SUB_BG_32_H:
        reg_GX_VRAMCNT_H = GX_VRAMCNT_H_SUBBG_0x06200000;
        break;
    case GX_VRAM_SUB_BG_NONE:
        break;
    default:
        break;
    }
}

static inline void GX_VRAMCNT_SetSubOBJ_ (GXVRamSubOBJ obj)
{
    switch (obj) {
    case GX_VRAM_SUB_OBJ_128_D:
        reg_GX_VRAMCNT_D = GX_VRAMCNT_D_SUBOBJ_0x06600000;
        break;
    case GX_VRAM_SUB_OBJ_16_I:
        reg_GX_VRAMCNT_I = GX_VRAMCNT_I_SUBOBJ_0x06600000;
        break;
    case GX_VRAM_SUB_OBJ_NONE:
        break;
    default:
        break;
    }
}

static inline void subBGExtPlttOn_ (void)
{
    reg_GXS_DB_DISPCNT |= REG_GXS_DB_DISPCNT_BG_MASK;
}

static inline void subBGExtPlttOff_ (void)
{
    reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_BG_MASK;
}

static inline void GX_VRAMCNT_SetSubBGExtPltt_ (GXVRamSubBGExtPltt bgExtPltt)
{
    switch (bgExtPltt) {
    case GX_VRAM_SUB_BGEXTPLTT_0123_H:
        subBGExtPlttOn_();
        reg_GX_VRAMCNT_H = GX_VRAMCNT_H_SUBBGEXTPLTT_0123;
        break;
    case GX_VRAM_SUB_BGEXTPLTT_NONE:
        subBGExtPlttOff_();
        break;
    default:
        break;
    }
}

static inline void subOBJExtPlttOn_ (void)
{
    reg_GXS_DB_DISPCNT |= REG_GXS_DB_DISPCNT_O_MASK;
}

static inline void subOBJExtPlttOff_ (void)
{
    reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_O_MASK;
}

static inline void GX_VRAMCNT_SetSubOBJExtPltt_ (GXVRamSubOBJExtPltt objExtPltt)
{
    switch (objExtPltt) {
    case GX_VRAM_SUB_OBJEXTPLTT_0_I:
        subOBJExtPlttOn_();
        reg_GX_VRAMCNT_I = GX_VRAMCNT_I_SUBOBJEXTPLTT;
        break;
    case GX_VRAM_SUB_OBJEXTPLTT_NONE:
        subOBJExtPlttOff_();
        break;
    }
}

extern vu16 GXi_VRamLockId;

static inline void GxSetBankForBG (GXVRamBG bg)
{

    gGXState.vramCnt.lcdc = (u16)(~bg & (gGXState.vramCnt.lcdc | gGXState.vramCnt.bg));
    gGXState.vramCnt.bg = bg;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetBG_(bg);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

static inline void GxSetBankForOBJ (GXVRamOBJ obj)
{

    gGXState.vramCnt.lcdc = (u16)(~obj & (gGXState.vramCnt.lcdc | gGXState.vramCnt.obj));
    gGXState.vramCnt.obj = obj;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetOBJ_(obj);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

static inline void GxSetBankForBGExtPltt (GXVRamBGExtPltt bgExtPltt)
{

    gGXState.vramCnt.lcdc = (u16)(~bgExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.bgExtPltt));
    gGXState.vramCnt.bgExtPltt = bgExtPltt;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetBGEXTPLTT_(bgExtPltt);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

static inline void GxSetBankForOBJExtPltt (GXVRamOBJExtPltt objExtPltt)
{

    gGXState.vramCnt.lcdc = (u16)(~objExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.objExtPltt));
    gGXState.vramCnt.objExtPltt = objExtPltt;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetOBJEXTPLTT_(objExtPltt);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

static inline void GxSetBankForTex (GXVRamTex tex)
{

    gGXState.vramCnt.lcdc = (u16)(~tex & (gGXState.vramCnt.lcdc | gGXState.vramCnt.tex));
    gGXState.vramCnt.tex = tex;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetTEX_(tex);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

static inline void GxSetBankForTexPltt (GXVRamTexPltt texPltt)
{

    gGXState.vramCnt.lcdc = (u16)(~texPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.texPltt));
    gGXState.vramCnt.texPltt = texPltt;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetTEXPLTT_(texPltt);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

static inline void GxSetBankForClearImage (GXVRamClearImage clrImg)
{

    gGXState.vramCnt.lcdc = (u16)(~clrImg & (gGXState.vramCnt.lcdc | gGXState.vramCnt.clrImg));
    gGXState.vramCnt.clrImg = clrImg;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetCLRIMG_(clrImg);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

static inline void GxSetBankForARM7 (GXVRamARM7 arm7)
{

    gGXState.vramCnt.lcdc = (u16)(~arm7 & (gGXState.vramCnt.lcdc | gGXState.vramCnt.arm7));
    gGXState.vramCnt.arm7 = arm7;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetARM7_(arm7);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

static inline void GxSetBankForLCDC (int lcdc)
{

    gGXState.vramCnt.lcdc |= lcdc;

    GX_StateCheck_VRAMCnt();
    GX_VRAMCNT_SetLCDC_(lcdc);
}

static inline void GxSetBankForSubBG (GXVRamSubBG sub_bg)
{

    gGXState.vramCnt.lcdc = (u16)(~sub_bg & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_bg));
    gGXState.vramCnt.sub_bg = sub_bg;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetSubBG_(sub_bg);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

void GX_SetBankForSubBG (GXVRamSubBG sub_bg)
{
    GxSetBankForSubBG(sub_bg);
}

static inline void GxSetBankForSubOBJ (GXVRamSubOBJ sub_obj)
{

    gGXState.vramCnt.lcdc = (u16)(~sub_obj & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_obj));
    gGXState.vramCnt.sub_obj = sub_obj;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetSubOBJ_(sub_obj);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

void GX_SetBankForSubOBJ (GXVRamSubOBJ sub_obj)
{
    GxSetBankForSubOBJ(sub_obj);
}

static inline void GxSetBankForSubBGExtPltt (GXVRamSubBGExtPltt sub_bgExtPltt)
{

    gGXState.vramCnt.lcdc = (u16)(~sub_bgExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_bgExtPltt));
    gGXState.vramCnt.sub_bgExtPltt = sub_bgExtPltt;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetSubBGExtPltt_(sub_bgExtPltt);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

static inline void GxSetBankForSubOBJExtPltt (GXVRamSubOBJExtPltt sub_objExtPltt)
{

    gGXState.vramCnt.lcdc = (u16)(~sub_objExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_objExtPltt));
    gGXState.vramCnt.sub_objExtPltt = sub_objExtPltt;

    GX_StateCheck_VRAMCnt();

    GX_VRAMCNT_SetSubOBJExtPltt_(sub_objExtPltt);
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}

void GX_SetBankForSubOBJExtPltt (GXVRamSubOBJExtPltt sub_objExtPltt)
{
    GxSetBankForSubOBJExtPltt(sub_objExtPltt);
}

#pragma thumb reset

static int resetBankForX_ (u16 *g3bit)
{
    int rval = *g3bit;

    *g3bit = 0;
    gGXState.vramCnt.lcdc |= rval;

    GX_VRAMCNT_SetLCDC_(rval);
    return rval;
}

GXVRamBG GX_ResetBankForBG (void)
{
    return (GXVRamBG)resetBankForX_(&gGXState.vramCnt.bg);
}

GXVRamOBJ GX_ResetBankForOBJ (void)
{
    return (GXVRamOBJ)resetBankForX_(&gGXState.vramCnt.obj);
}

GXVRamBGExtPltt GX_ResetBankForBGExtPltt (void)
{
    bgExtPlttOff_();
    return (GXVRamBGExtPltt)resetBankForX_(&gGXState.vramCnt.bgExtPltt);
}

GXVRamOBJExtPltt GX_ResetBankForOBJExtPltt (void)
{
    objExtPlttOff_();
    return (GXVRamOBJExtPltt)resetBankForX_(&gGXState.vramCnt.objExtPltt);
}

GXVRamTex GX_ResetBankForTex (void)
{
    return (GXVRamTex)resetBankForX_(&gGXState.vramCnt.tex);
}

GXVRamTexPltt GX_ResetBankForTexPltt (void)
{
    return (GXVRamTexPltt)resetBankForX_(&gGXState.vramCnt.texPltt);
}

GXVRamSubBG GX_ResetBankForSubBG (void)
{
    return (GXVRamSubBG)resetBankForX_(&gGXState.vramCnt.sub_bg);
}

GXVRamSubOBJ GX_ResetBankForSubOBJ (void)
{
    return (GXVRamSubOBJ)resetBankForX_(&gGXState.vramCnt.sub_obj);
}

GXVRamSubBGExtPltt GX_ResetBankForSubBGExtPltt (void)
{
    subBGExtPlttOff_();
    return (GXVRamSubBGExtPltt)resetBankForX_(&gGXState.vramCnt.sub_bgExtPltt);
}

GXVRamSubOBJExtPltt GX_ResetBankForSubOBJExtPltt (void)
{
    subOBJExtPlttOff_();
    return (GXVRamSubOBJExtPltt)resetBankForX_(&gGXState.vramCnt.sub_objExtPltt);
}

    #pragma thumb off

static int disableBankForX_ (u16 *g3bit)
{
    int rval = *g3bit;
    *g3bit = 0;

    if (rval & GX_VRAM_LCDC_A)
        reg_GX_VRAMCNT_A = 0;

    if (rval & GX_VRAM_LCDC_B)
        reg_GX_VRAMCNT_B = 0;

    if (rval & GX_VRAM_LCDC_C)
        reg_GX_VRAMCNT_C = 0;

    if (rval & GX_VRAM_LCDC_D)
        reg_GX_VRAMCNT_D = 0;

    if (rval & GX_VRAM_LCDC_E)
        reg_GX_VRAMCNT_E = 0;

    if (rval & GX_VRAM_LCDC_F)
        reg_GX_VRAMCNT_F = 0;

    if (rval & GX_VRAM_LCDC_G)
        reg_GX_VRAMCNT_G = 0;

    if (rval & GX_VRAM_LCDC_H)
        reg_GX_VRAMCNT_H = 0;

    if (rval & GX_VRAM_LCDC_I)
        reg_GX_VRAMCNT_I = 0;

    OSi_UnlockVram((u16)rval, GXi_VRamLockId);
    return rval;
}

    #pragma thumb reset

GXVRamLCDC GX_DisableBankForLCDC (void)
{
    return (GXVRamLCDC)disableBankForX_(&gGXState.vramCnt.lcdc);
}
