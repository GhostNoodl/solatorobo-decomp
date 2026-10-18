#include "fs_private.h"

#pragma force_active on

typedef struct CARDRomRegion {
    u32 offset;
    u32 length;
} CARDRomRegion;

typedef void (*FSOverlayInitFunc)(void);

typedef struct FSOverlayInfoHeader {
    u32 id;                          // 0x00
    u8 *ram_address;                 // 0x04
    u32 ram_size;                    // 0x08
    u32 bss_size;                    // 0x0c
    FSOverlayInitFunc *sinit_init;   // 0x10
    FSOverlayInitFunc *sinit_init_end; // 0x14
    u32 file_id;                     // 0x18
    u32 compressed : 24;             // 0x1c
    u32 flag : 8;
} FSOverlayInfoHeader;

typedef struct FSOverlayInfo {
    FSOverlayInfoHeader header;      // 0x00
    u32 target;                      // 0x20
    CARDRomRegion file_pos;          // 0x24
} FSOverlayInfo; // size 0x2c

#define FS_OVERLAY_FLAG_COMP 0x01
#define FS_OVERLAY_FLAG_AUTH 0x02
#define FS_OVERLAY_DIGEST_SIZE 20

typedef struct FSiRomStatics {
    BOOL twl_region_loaded;   // 0x00
    FSArchive *arc_rom;       // 0x04
    CARDRomRegion ovt9;       // 0x08
    CARDRomRegion ovt7;       // 0x10
    const void *digest_key;   // 0x18
    u32 digest_key_len;       // 0x1c
} FSiRomStatics;

extern FSiRomStatics data_0208ea20;
#define fsi_rom data_0208ea20

typedef struct MWiDestructorChain {
    struct MWiDestructorChain *next;
    void (*dtor)(void *);
    void *obj;
} MWiDestructorChain;

extern MWiDestructorChain *data_0208de90;
#define __global_destructor_chain data_0208de90

extern u8 data_0208d800[];
extern u8 data_0208d940[];
#define SDK_OVERLAY_DIGEST data_0208d800
#define SDK_OVERLAY_DIGEST_END data_0208d940

extern const char data_0208af3c[];

void IC_InvalidateRange(void *startAddr, u32 nBytes);
void DC_InvalidateRange(void *startAddr, u32 nBytes);
void DC_FlushRange(const void *startAddr, u32 nBytes);
void MIi_UncompressBackward(void *bottom);
void func_0200c118(void *digest, const void *src, int len, const void *key, u32 keylen);
BOOL func_02015a3c(BOOL enable);
void func_02015d9c(void *digest, const void *src, int len, const void *key, u32 keylen);
BOOL FS_OpenFileFast(FSFile *file, FSFileID id);
BOOL FS_CloseFile(FSFile *file);
int FS_ReadFile(FSFile *file, void *buffer, int length);
BOOL FS_LoadOverlayInfo(FSOverlayInfo *p_ovi, u32 target, u32 id);

void func_0200f180(void) {
    if (OS_GetBootType() == 2) {
        fsi_rom.ovt9.offset = (u32)-1;
        fsi_rom.ovt9.length = 0;
        fsi_rom.ovt7.offset = (u32)-1;
        fsi_rom.ovt7.length = 0;
    } else {
        fsi_rom.ovt9.offset = 0;
        fsi_rom.ovt9.length = 0;
        fsi_rom.ovt7.offset = 0;
        fsi_rom.ovt7.length = 0;
    }
    fsi_rom.digest_key = (const void *)0x02070eec;
    fsi_rom.digest_key_len = 0x40;
    fsi_rom.arc_rom = FS_FindArchive(data_0208af3c, 3);
}

u32 FS_GetOverlayImageSize(const FSOverlayInfo *p_ovi) {
    return (p_ovi->header.flag & FS_OVERLAY_FLAG_COMP) ? p_ovi->header.compressed : p_ovi->header.ram_size;
}

static inline u32 FS_GetOverlayTotalSize(const FSOverlayInfo *p_ovi) {
    return p_ovi->header.ram_size + p_ovi->header.bss_size;
}

void FS_ClearOverlayImage(FSOverlayInfo *p_ovi) {
    u8 *const im_start = p_ovi->header.ram_address;
    const u32 ram_size = p_ovi->header.ram_size;
    const u32 total_size = ram_size + p_ovi->header.bss_size;

    IC_InvalidateRange(im_start, total_size);
    DC_InvalidateRange(im_start, total_size);
    MI_CpuFill8(im_start + ram_size, 0, total_size - ram_size);
}

FSFileID FS_GetOverlayFileID(const FSOverlayInfo *p_ovi) {
    FSFileID ret;
    ret.arc = fsi_rom.arc_rom;
    ret.file_id = p_ovi->header.file_id;
    return ret;
}

