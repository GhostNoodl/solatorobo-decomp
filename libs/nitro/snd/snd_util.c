#include "nitro/snd.h"

#define SND_VOL_DB_MIN (-723)

// Static in the SDK; referenced through an unrelocated pool constant here.
extern const u8 sVolumeTable[-SND_VOL_DB_MIN + 1];

u16 SND_CalcChannelVolume(int dB) {
    u32 vol;
    u32 shift;

    if (dB < SND_VOL_DB_MIN) {
        dB = SND_VOL_DB_MIN;
    } else if (dB > 0) {
        dB = 0;
    }

    vol = sVolumeTable[dB - SND_VOL_DB_MIN];

    if (dB < -240) {
        shift = 3;
    } else if (dB < -120) {
        shift = 2;
    } else if (dB < -60) {
        shift = 1;
    } else {
        shift = 0;
    }

    return (u16)((shift << 8) | vol);
}
