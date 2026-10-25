// The table OSi_DetectDebugger indexes with OS_GetBootType(): the boot-device flag that goes into
// the console type for each boot type (none for an unknown boot type).
//
// main keeps its read-only data inside .text (see libs/msl/ctype.c); this is C data in a read-only
// user section named ".text" (see libs/nitro/math/math_sha1_rodata.c).

typedef unsigned long u32;

// OSBootType
enum {
    OS_BOOTTYPE_ILLEGAL,
    OS_BOOTTYPE_ROM,
    OS_BOOTTYPE_DOWNLOAD,
    OS_BOOTTYPE_NAND,
    OS_BOOTTYPE_MEMORY,
    OS_BOOTTYPE_MAX
};

// Boot-device bits of the console type
#define OSi_CONSOLE_BOOT_DOWNLOAD (1 << 14)
#define OSi_CONSOLE_BOOT_MEMORY   (1 << 15)
#define OSi_CONSOLE_BOOT_ROM      (1 << 17)
#define OSi_CONSOLE_BOOT_NAND     (1 << 18)

#pragma define_section rodata_text ".text" ".bss" ".text" abs32 R
#pragma section rodata_text begin

const u32 data_020751fc[OS_BOOTTYPE_MAX] = {
    0,                         // OS_BOOTTYPE_ILLEGAL
    OSi_CONSOLE_BOOT_ROM,      // OS_BOOTTYPE_ROM
    OSi_CONSOLE_BOOT_DOWNLOAD, // OS_BOOTTYPE_DOWNLOAD
    OSi_CONSOLE_BOOT_NAND,     // OS_BOOTTYPE_NAND
    OSi_CONSOLE_BOOT_MEMORY,   // OS_BOOTTYPE_MEMORY
};

#pragma section rodata_text end
