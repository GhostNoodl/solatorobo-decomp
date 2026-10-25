// os_emulator.c's .data: the cached console type (and the word before it), both "not detected"
// until OS_GetConsoleType first runs. A data-only file so the matched os_emulator.c is left as it
// is; it links right after os_emulator.c.

typedef unsigned long u32;

#define OSi_CONSOLE_NOT_DETECTED 0xffffffff

typedef struct {
    u32 unk_00;
    u32 consoleType; // 0x04
} OSiEmulatorData;

OSiEmulatorData data_0208af78 = { OSi_CONSOLE_NOT_DETECTED, OSi_CONSOLE_NOT_DETECTED };
