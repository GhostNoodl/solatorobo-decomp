#include "nitro/gx.h"

typedef enum {
    G2_BLENDTYPE_NONE    = 0x0000,
    G2_BLENDTYPE_ALPHA   = 0x0040,
    G2_BLENDTYPE_FADEIN  = 0x0080,
    G2_BLENDTYPE_FADEOUT = 0x00c0
} G2_BLENDTYPE;

void G2x_SetBlendAlpha_(u32 addr, int plane1, int plane2, int ev1, int ev2) {
    *((vu32 *)addr + 0) = (u32)((G2_BLENDTYPE_ALPHA | plane1 | plane2 << 8) | ((ev1 | ev2 << 8) << 16));
}

void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness) {
    if (brightness < 0) {
        *((vu16 *)addr + 0) = (u16)(G2_BLENDTYPE_FADEOUT | plane);
        *((vu16 *)addr + 2) = (u16)-brightness;
    } else {
        *((vu16 *)addr + 0) = (u16)(G2_BLENDTYPE_FADEIN | plane);
        *((vu16 *)addr + 2) = (u16)brightness;
    }
}
