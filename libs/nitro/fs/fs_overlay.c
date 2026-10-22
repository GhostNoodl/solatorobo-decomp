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

extern MWiDestructorChain *__global_destructor_chain;

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
BOOL MATHi_SetOverlayTableMode(BOOL enable);
void MATH_CalcHMACSHA1(void *digest, const void *src, int len, const void *key, u32 keylen);
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

// Overlay count from the linker script (dsd defines __OVERLAY_COUNT as an absolute symbol), so the
// value is a relocated pool word as in the SDK build.
extern char __OVERLAY_COUNT[];
#define SDK_OVERLAY_NUMBER ((u32)__OVERLAY_COUNT)

typedef struct FSRomHeaderOvt {
    u8 unk_00[0x50];
    CARDRomRegion main_ovt; // 0x50
    CARDRomRegion sub_ovt;  // 0x58
} FSRomHeaderOvt;

const u8 *CARD_GetOwnRomHeader(void);
BOOL FS_CreateFileFromRom(FSFile *file, u32 offset, u32 size);
u32 FS_GetFileImageTop(const FSFile *file);
u32 FS_GetFileLength(FSFile *file);

BOOL FS_LoadOverlayInfo(FSOverlayInfo *p_ovi, u32 target, u32 id) {
    BOOL retval = FALSE;
    const u32 pos = id * sizeof(FSOverlayInfoHeader);
    const CARDRomRegion *pr = (target == 0) ? &fsi_rom.ovt9 : &fsi_rom.ovt7;
    if (id >= SDK_OVERLAY_NUMBER && !OS_IsRunOnTwl()) {
    } else if (pr->offset != 0) {
        if (pos < pr->length) {
            FSFile file[1];
            FS_InitFile(file);
            MI_CpuCopy8((const void *)(pr->offset + pos), p_ovi, sizeof(FSOverlayInfoHeader));
            p_ovi->target = target;
            if (FS_OpenFileFast(file, FS_GetOverlayFileID(p_ovi))) {
                p_ovi->file_pos.offset = FS_GetFileImageTop(file);
                p_ovi->file_pos.length = FS_GetFileLength(file);
                FS_CloseFile(file);
                retval = TRUE;
            }
        }
    } else {
        if (target == 0) {
            pr = &((const FSRomHeaderOvt *)CARD_GetOwnRomHeader())->main_ovt;
        } else {
            pr = &((const FSRomHeaderOvt *)CARD_GetOwnRomHeader())->sub_ovt;
        }
        if (pos < pr->length) {
            FSFile file[1];
            FS_InitFile(file);
            if (FS_CreateFileFromRom(file, pr->offset + pos, pr->offset + pr->length)) {
                if (FS_ReadFile(file, p_ovi, sizeof(FSOverlayInfoHeader)) != sizeof(FSOverlayInfoHeader)) {
                    FS_CloseFile(file);
                } else {
                    FS_CloseFile(file);
                    p_ovi->target = target;
                    if (FS_OpenFileFast(file, FS_GetOverlayFileID(p_ovi))) {
                        p_ovi->file_pos.offset = FS_GetFileImageTop(file);
                        p_ovi->file_pos.length = FS_GetFileLength(file);
                        FS_CloseFile(file);
                        retval = TRUE;
                    }
                }
            }
        }
    }
    return retval;
}
