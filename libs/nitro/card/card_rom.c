#include "card_private.h"
#include "nitro/os_alarm.h"

#pragma force_active on


#define REG_MI_MCCNT0_E_MASK   0x8000
#define REG_MI_MCCNT0_I_MASK   0x4000
#define REG_MI_MCCNT0_SEL_MASK 0x2000

#define REG_MI_MCCNT1_START_MASK 0x80000000
#define REG_MI_MCCNT1_RDY_MASK   0x00800000
#define REG_MI_MCCNT1_PC_MASK    0x07000000
#define REG_MI_MCCNT1_CT_MASK    0x08000000
#define REG_MI_MCCNT1_RESB_MASK  0x20000000
#define REG_MI_MCCNT1_WR_MASK    0x40000000
#define REG_MI_MCCNT1_SCR_MASK   0x00002000

#define CARD_ROM_HEADER_CTRL (*(u32 *)0x02fffae0)
#define CARD_ROM_STATUS_FLAG (*(u32 *)0x02fffc00)

extern BOOL data_0208ec30;
void OS_Sleep(u32 msec);

typedef struct {
    u8 unk_00[0x1b4];
    u32 unk_0_4 : 5;
    u32 game_card_nitro_mode : 1;
    u32 unk_6_7 : 2;
    u32 game_card_on : 1;
    u32 unk_9_31 : 23;
} CARDRomHeaderTWLFlags;

static inline u32 CARDi_SwapEndian32(u32 v) {
    return ((v & 0xff000000) >> 24) | ((v & 0x00ff0000) >> 8) | ((v & 0x0000ff00) << 8) | (v << 24);
}

void func_0200d0dc(u32 command1, u32 command2) {
    u32 hi = (command2 >> 8) | (command1 << 24);
    u32 lo = command2 << 24;

    while (reg_MI_MCCNT1 & REG_MI_MCCNT1_START_MASK) {
    }

    reg_MI_MCCNT0 = (u16)((reg_MI_MCCNT0 & ~REG_MI_MCCNT0_SEL_MASK) | (REG_MI_MCCNT0_E_MASK | REG_MI_MCCNT0_I_MASK));
    reg_MI_MCCMD0 = CARDi_SwapEndian32(hi);
    reg_MI_MCCMD1 = CARDi_SwapEndian32(lo);
}

BOOL func_0200d15c(void) {
    const CARDRomHeaderTWLFlags *header = (const CARDRomHeaderTWLFlags *)CARD_GetOwnRomHeaderTWL();

    if (OS_IsRunOnTwl() && OS_GetBootType() != 1 && header->game_card_nitro_mode && !header->game_card_on) {
        return TRUE;
    }
    return FALSE;
}

void func_0200d1a8(u32 src) {
    u32 cmd = 0xb7;

    if (func_0200d15c()) {
        cmd = 0x00;
    }
    func_0200d0dc(cmd, src);
    reg_MI_MCCNT1 = (CARD_ROM_HEADER_CTRL & ~REG_MI_MCCNT1_PC_MASK) | (REG_MI_MCCNT1_START_MASK | REG_MI_MCCNT1_RESB_MASK | 0x01000000);
}

u32 func_0200d1f0(void) {
    u32 cmd = 0xb8;

    if (func_0200d15c()) {
        cmd = 0x90;
    }
    func_0200d0dc(cmd, 0);
    reg_MI_MCCNT1 = ((CARD_ROM_HEADER_CTRL & ~REG_MI_MCCNT1_PC_MASK) | (REG_MI_MCCNT1_START_MASK | REG_MI_MCCNT1_RESB_MASK | REG_MI_MCCNT1_PC_MASK)) & ~0x1fff;
    while (!(reg_MI_MCCNT1 & REG_MI_MCCNT1_RDY_MASK)) {
    }
    return reg_MI_MCD1;
}

u32 func_0200d258(void) {
    if (!(CARD_ROM_STATUS_FLAG & 0x20000000)) {
        return 0x20;
    }
    func_0200d0dc(0xd6, 0);
    reg_MI_MCCNT1 = ((CARD_ROM_HEADER_CTRL & ~REG_MI_MCCNT1_PC_MASK) | (REG_MI_MCCNT1_START_MASK | REG_MI_MCCNT1_RESB_MASK | REG_MI_MCCNT1_PC_MASK)) & ~0x1fff;
    while (!(reg_MI_MCCNT1 & REG_MI_MCCNT1_RDY_MASK)) {
    }
    return reg_MI_MCD1;
}

void func_0200d320(void);

void func_0200d2c0(u32 mask) {
    if (func_0200d258() & mask) {
        func_0200d320();
        if (!(func_0200d258() & 0x20)) {
            do {
                if (data_0208ec30 && OS_IsAlarmAvailable()) {
                    OS_Sleep(1);
                }
            } while (!(func_0200d258() & 0x20));
        }
    }
}

void func_0200d320(void) {
    func_0200d0dc(0xb5, 0);
    reg_MI_MCCNT1 = ((CARD_ROM_HEADER_CTRL & ~REG_MI_MCCNT1_PC_MASK) | (REG_MI_MCCNT1_START_MASK | REG_MI_MCCNT1_RESB_MASK)) & ~0x1fff;
    while (reg_MI_MCCNT1 & REG_MI_MCCNT1_START_MASK) {
    }
}

