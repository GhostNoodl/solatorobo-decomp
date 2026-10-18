#include "nitro/ioreg.h"

void MI_SetWramBank(int cnt) {
    reg_GX_VRAMCNT_WRAM = (u8)cnt;
}
