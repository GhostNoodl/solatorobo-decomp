#include "nitro/os.h"

BOOL OS_IsRunOnTwl(void);
void func_0228e770(void);  /* TWL only */

void func_020163b8 (void)
{
    if (OS_IsRunOnTwl()) {
        func_0228e770();
    }
}

#include "nitro/ioreg.h"

void MI_SetWramBank(int cnt) {
    reg_GX_VRAMCNT_WRAM = (u8)cnt;
}
