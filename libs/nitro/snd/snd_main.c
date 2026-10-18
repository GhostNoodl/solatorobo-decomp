#include "nitro/snd.h"
#include "nitro/os.h"

static OSMutex sSndMutex;
static s32 sSndInitialized;

void SND_Init(void) {
    if (sSndInitialized) {
        return;
    }
    sSndInitialized = 1;
    OS_InitMutex(&sSndMutex);
    SND_CommandInit();
    SND_AlarmInit();
}

void SNDi_LockMutex(void) {
    OS_LockMutex(&sSndMutex);
}

void SNDi_UnlockMutex(void) {
    OS_UnlockMutex(&sSndMutex);
}
