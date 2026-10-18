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
BOOL MATHi_SetOverlayTableMode(BOOL enable);
void MATH_CalcHMACSHA1(void *digest, const void *src, int len, const void *key, u32 keylen);
BOOL FS_OpenFileFast(FSFile *file, FSFileID id);
BOOL FS_CloseFile(FSFile *file);
int FS_ReadFile(FSFile *file, void *buffer, int length);
BOOL FS_LoadOverlayInfo(FSOverlayInfo *p_ovi, u32 target, u32 id);

u32 FS_GetOverlayImageSize(const FSOverlayInfo *p_ovi);
void FS_ClearOverlayImage(FSOverlayInfo *p_ovi);
FSFileID FS_GetOverlayFileID(const FSOverlayInfo *p_ovi);

static inline u32 FS_GetOverlayTotalSize(const FSOverlayInfo *p_ovi) {
    return p_ovi->header.ram_size + p_ovi->header.bss_size;
}

BOOL FS_LoadOverlayImage(FSOverlayInfo *p_ovi) {
    BOOL retval = FALSE;
    FSFile file[1];

    FS_InitFile(file);
    if (FS_OpenFileFast(file, FS_GetOverlayFileID(p_ovi))) {
        int size = (int)FS_GetOverlayImageSize(p_ovi);
        FS_ClearOverlayImage(p_ovi);
        if (FS_ReadFile(file, p_ovi->header.ram_address, size) == size) {
            retval = TRUE;
        }
        (void)FS_CloseFile(file);
    }
    return retval;
}

BOOL FSi_CompareDigest(const u8 *spec_digest, void *src, int len, BOOL use_sdk) {
    int i;
    u8 digest[FS_OVERLAY_DIGEST_SIZE];
    u8 digest_key[64];

    MI_CpuClear8(digest, sizeof(digest));
    MI_CpuCopy8(fsi_rom.digest_key, digest_key, fsi_rom.digest_key_len);
    if (!use_sdk && OS_IsRunOnTwl()) {
        func_0200c118(digest, src, len, digest_key, fsi_rom.digest_key_len);
    } else {
        BOOL old = FALSE;
        if (use_sdk) {
            old = MATHi_SetOverlayTableMode(TRUE);
        }
        MATH_CalcHMACSHA1(digest, src, len, digest_key, fsi_rom.digest_key_len);
        if (use_sdk) {
            (void)MATHi_SetOverlayTableMode(old);
        }
    }
    for (i = 0; i < sizeof(digest); i += sizeof(u32)) {
        if (*(const u32 *)(digest + i) != *(const u32 *)(spec_digest + i)) {
            break;
        }
    }
    return (i == sizeof(digest));
}

void FS_StartOverlay(FSOverlayInfo *p_ovi) {
    u32 rare_size = FS_GetOverlayImageSize(p_ovi);

    if ((u32)p_ovi->header.ram_address >= 0x022183c0 && (u32)p_ovi->header.ram_address < 0x02298140 && OS_IsRunOnTwl()) {
        if (!fsi_rom.twl_region_loaded) {
            fsi_rom.twl_region_loaded = TRUE;
        }
    }

    if (OS_GetBootType() != 1) {
        BOOL ret = FALSE;
        if (p_ovi->header.flag & FS_OVERLAY_FLAG_AUTH) {
            const u32 odt_max = (u32)((SDK_OVERLAY_DIGEST_END - SDK_OVERLAY_DIGEST) / FS_OVERLAY_DIGEST_SIZE);
            if (p_ovi->header.id < odt_max) {
                const u8 *digest = SDK_OVERLAY_DIGEST + FS_OVERLAY_DIGEST_SIZE * p_ovi->header.id;
                ret = FSi_CompareDigest(digest, p_ovi->header.ram_address, (int)rare_size, ret);
            }
        }
        if (!ret) {
            MI_CpuFill8(p_ovi->header.ram_address, 0, rare_size);
            OS_Terminate();
            return;
        }
    }

    if (p_ovi->header.flag & FS_OVERLAY_FLAG_COMP) {
        MIi_UncompressBackward(p_ovi->header.ram_address + rare_size);
    }
    DC_FlushRange(p_ovi->header.ram_address, p_ovi->header.ram_size);
    {
        FSOverlayInitFunc *p = p_ovi->header.sinit_init;
        FSOverlayInitFunc *q = p_ovi->header.sinit_init_end;
        for (; p < q; ++p) {
            if (*p) {
                (**p)();
            }
        }
    }
}

void FS_EndOverlay(FSOverlayInfo *p_ovi) {
    for (;;) {
        MWiDestructorChain *head = NULL, *tail = NULL;
        const u32 region_top = (u32)p_ovi->header.ram_address;
        const u32 region_bottom = region_top + FS_GetOverlayTotalSize(p_ovi);
        {
            OSIntrMode bak_psr = OS_DisableInterrupts();
            MWiDestructorChain *prev = NULL;
            MWiDestructorChain *base = __global_destructor_chain;
            MWiDestructorChain *p = base;
            while (p) {
                MWiDestructorChain *next = p->next;
                const u32 dtor = (u32)p->dtor;
                const u32 obj = (u32)p->obj;
                if (((obj == 0) && (dtor >= region_top) && (dtor < region_bottom)) || ((obj >= region_top) && (obj < region_bottom))) {
                    if (!tail) {
                        head = p;
                    } else {
                        tail->next = p;
                    }
                    if (base == p) {
                        base = __global_destructor_chain = next;
                    }
                    tail = p, p->next = NULL;
                    if (prev) {
                        prev->next = next;
                    }
                } else {
                    prev = p;
                }
                p = next;
            }
            (void)OS_RestoreInterrupts(bak_psr);
        }
        if (!head) {
            break;
        }
        do {
            MWiDestructorChain *next = head->next;
            if (head->dtor) {
                (*head->dtor)(head->obj);
            }
            head = next;
        } while (head);
    }
}

BOOL FS_UnloadOverlayImage(FSOverlayInfo *p_ovi) {
    FS_EndOverlay(p_ovi);
    return TRUE;
}

BOOL FS_LoadOverlay(u32 target, u32 id) {
    BOOL retval = FALSE;
    FSOverlayInfo ovi;

    if (FS_LoadOverlayInfo(&ovi, target, id) && FS_LoadOverlayImage(&ovi)) {
        FS_StartOverlay(&ovi);
        retval = TRUE;
    }
    return retval;
}

BOOL FS_UnloadOverlay(u32 target, u32 id) {
    FSOverlayInfo ovi;

    if (FS_LoadOverlayInfo(&ovi, target, id) && FS_UnloadOverlayImage(&ovi)) {
        return TRUE;
    }
    return FALSE;
}
