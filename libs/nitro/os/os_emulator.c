#include "nitro/os.h"

#pragma force_active on

#define OSi_CONSOLE_NOT_DETECTED 0xffffffff

u32 OS_GetBootType(void);
u32 OSi_DetectDebugger(void);

typedef struct {
    u32 unk_00;
    u32 consoleType; // 0x04
} OSiEmulatorData;

typedef struct {
    u32 unk_00;
    BOOL isTwl;      // 0x04
    u8 unk_08[0x14];
    BOOL isDetected; // 0x1c
} OSiTwlDetect;

extern OSiEmulatorData data_0208af78;
extern OSiTwlDetect data_0208ee98;
extern const u32 data_020751fc[]; // OSi_DebuggerTypeTable?

u32 OS_GetConsoleType(void) {
    if (data_0208af78.consoleType == OSi_CONSOLE_NOT_DETECTED) {
        OSiEmulatorData *p = &data_0208af78;
        p->consoleType = OS_IsRunOnTwl() ? 0x01800004 : 0x80000001;
        data_0208af78.consoleType |= OSi_DetectDebugger();
    }
    return data_0208af78.consoleType;
}

u32 OSi_DetectDebugger(void) {
    return data_020751fc[OS_GetBootType()];
}

BOOL OS_IsRunOnEmulator(void) {
    return (OS_GetConsoleType() & 0x10000000) ? TRUE : FALSE;
}

BOOL OS_IsRunOnTwl(void) {
    if (!data_0208ee98.isDetected) {
        data_0208ee98.isTwl = ((*(vu8 *)0x04004000 & 3) == 1) ? TRUE : FALSE;
        data_0208ee98.isDetected = TRUE;
    }
    return data_0208ee98.isTwl;
}

BOOL func_02018da4(void) {
    return OS_IsRunOnTwl();
}
