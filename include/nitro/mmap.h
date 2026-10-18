#ifndef NITRO_MMAP_H
#define NITRO_MMAP_H

// Memory map from the NitroSDK (mmap_global.h, mmap_vram.h): VRAM, palette and OAM only
#define HW_BG_PLTT              0x05000000
#define HW_BG_PLTT_END          0x05000200
#define HW_BG_PLTT_SIZE         (HW_BG_PLTT_END-HW_BG_PLTT)
#define HW_OBJ_PLTT             0x05000200
#define HW_OBJ_PLTT_END         0x05000400
#define HW_OBJ_PLTT_SIZE        (HW_OBJ_PLTT_END-HW_OBJ_PLTT)
#define HW_PLTT                 HW_BG_PLTT
#define HW_PLTT_END             HW_OBJ_PLTT_END
#define HW_PLTT_SIZE            (HW_PLTT_END-HW_PLTT)
#define HW_DB_BG_PLTT           0x05000400
#define HW_DB_BG_PLTT_END       0x05000600
#define HW_DB_BG_PLTT_SIZE      (HW_DB_BG_PLTT_END-HW_DB_BG_PLTT)
#define HW_DB_OBJ_PLTT          0x05000600
#define HW_DB_OBJ_PLTT_END      0x05000800
#define HW_DB_OBJ_PLTT_SIZE     (HW_DB_OBJ_PLTT_END-HW_DB_OBJ_PLTT)
#define HW_DB_PLTT              HW_DB_BG_PLTT
#define HW_DB_PLTT_END          HW_DB_OBJ_PLTT_END
#define HW_DB_PLTT_SIZE         (HW_DB_PLTT_END-HW_DB_PLTT)
#define HW_BG_VRAM              0x06000000
#define HW_BG_VRAM_END          0x06080000
#define HW_BG_VRAM_SIZE         (HW_BG_VRAM_END-HW_BG_VRAM)
#define HW_DB_BG_VRAM           0x06200000
#define HW_DB_BG_VRAM_END       0x06220000
#define HW_DB_BG_VRAM_SIZE      (HW_DB_BG_VRAM_END-HW_DB_BG_VRAM)
#define HW_OBJ_VRAM             0x06400000
#define HW_OBJ_VRAM_END         0x06440000
#define HW_OBJ_VRAM_SIZE        (HW_OBJ_VRAM_END-HW_OBJ_VRAM)
#define HW_DB_OBJ_VRAM          0x06600000
#define HW_DB_OBJ_VRAM_END      0x06620000
#define HW_DB_OBJ_VRAM_SIZE     (HW_DB_OBJ_VRAM_END-HW_DB_OBJ_VRAM)
#define HW_LCDC_VRAM            0x06800000


#define HW_LCDC_VRAM_END        0x068A4000

#define HW_LCDC_VRAM_SIZE       (HW_LCDC_VRAM_END-HW_LCDC_VRAM)
#define HW_OAM                  0x07000000
#define HW_OAM_END              0x07000400
#define HW_OAM_SIZE             (HW_OAM_END-HW_OAM)
#define HW_DB_OAM               0x07000400
#define HW_DB_OAM_END           0x07000800
#define HW_DB_OAM_SIZE          (HW_DB_OAM_END-HW_DB_OAM)
#define HW_VRAM_A_SIZE          0x20000 // VRAM-A
#define HW_VRAM_B_SIZE          0x20000 //      B
#define HW_VRAM_C_SIZE          0x20000 //      C
#define HW_VRAM_D_SIZE          0x20000 //      D
#define HW_VRAM_E_SIZE          0x10000 //      E
#define HW_VRAM_F_SIZE          0x4000 //      F
#define HW_VRAM_G_SIZE          0x4000 //      G
#define HW_VRAM_H_SIZE          0x8000 //      H
#define HW_VRAM_I_SIZE          0x4000 //      I
#define HW_LCDC_VRAM_A          (HW_LCDC_VRAM)
#define HW_LCDC_VRAM_B          (HW_LCDC_VRAM_A + HW_VRAM_A_SIZE)
#define HW_LCDC_VRAM_C          (HW_LCDC_VRAM_B + HW_VRAM_B_SIZE)
#define HW_LCDC_VRAM_D          (HW_LCDC_VRAM_C + HW_VRAM_C_SIZE)
#define HW_LCDC_VRAM_E          (HW_LCDC_VRAM_D + HW_VRAM_D_SIZE)
#define HW_LCDC_VRAM_F          (HW_LCDC_VRAM_E + HW_VRAM_E_SIZE)
#define HW_LCDC_VRAM_G          (HW_LCDC_VRAM_F + HW_VRAM_F_SIZE)
#define HW_LCDC_VRAM_H          (HW_LCDC_VRAM_G + HW_VRAM_G_SIZE)
#define HW_LCDC_VRAM_I          (HW_LCDC_VRAM_H + HW_VRAM_H_SIZE)

#endif
