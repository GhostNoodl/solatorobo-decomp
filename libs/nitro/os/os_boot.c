#include "nitro/os.h"

#define HW_WM_BOOT_BUF          0x02fffc40
#define HW_TWL_ROM_HEADER_BUF   0x02ffe000

typedef u16 OSBootType;

typedef struct OSBootInfo {
    OSBootType boot_type;
} OSBootInfo;

OSBootType OS_GetBootType(void);
const OSBootInfo * OS_GetBootInfo(void);
BOOL OSi_IsCodecTwlMode(void);

OSBootType OS_GetBootType (void)
{
    const OSBootInfo * pInfo = OS_GetBootInfo();
    return pInfo->boot_type;
}

const OSBootInfo * OS_GetBootInfo (void)
{
    return (const OSBootInfo *)HW_WM_BOOT_BUF;
}

static BOOL OSi_CodecTwlMode = FALSE;
static BOOL OSi_CodecTwlModeInitialized = FALSE;

#pragma force_active on
BOOL OSi_IsCodecTwlMode (void)
{
    if (!OSi_CodecTwlModeInitialized) {
        OSi_CodecTwlMode = (OS_IsRunOnTwl() == TRUE && ((*(u8 *)(HW_TWL_ROM_HEADER_BUF + 0x1bf)) & 0x01) == 0x01) ? TRUE : FALSE;
    }
    OSi_CodecTwlModeInitialized = TRUE;
    return OSi_CodecTwlMode;
}
#pragma force_active reset
