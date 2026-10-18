#include "nnsys/snd/sndarc.h"

typedef struct FSFileID {
    /* 0x0 */ void *arc;
    /* 0x4 */ u32 fileId;
} FSFileID;

typedef struct SndArcHeader {
    /* 0x00 */ u8 fileHeader[0x10];
    /* 0x10 */ u32 symbolDataOffset;
    /* 0x14 */ u32 symbolDataSize;
    /* 0x18 */ u32 infoOffset;
    /* 0x1c */ u32 infoSize;
    /* 0x20 */ u32 fatOffset;
    /* 0x24 */ u32 fatSize;
    /* 0x28 */ u32 fileImageOffset;
    /* 0x2c */ u32 fileImageSize;
} SndArcHeader; // size 0x30

typedef struct SndArcOffsetTable {
    /* 0x0 */ u32 count;
    /* 0x4 */ u32 offset[];
} SndArcOffsetTable;

typedef struct SndArcInfo {
    /* 0x00 */ u8 blockHeader[8];
    /* 0x08 */ u32 seqOffset;
    /* 0x0c */ u32 seqArcOffset;
    /* 0x10 */ u32 bankOffset;
    /* 0x14 */ u32 waveArcOffset;
    /* 0x18 */ u32 playerInfoOffset;
    /* 0x1c */ u32 groupInfoOffset;
    /* 0x20 */ u32 strmPlayerInfoOffset;
    /* 0x24 */ u32 strmOffset;
} SndArcInfo;

typedef struct SndArcFileInfo {
    /* 0x0 */ u32 offset;
    /* 0x4 */ u32 size;
    /* 0x8 */ void *mem;
    /* 0xc */ u32 reserved;
} SndArcFileInfo; // size 0x10

typedef struct SndArcFat {
    /* 0x0 */ u8 blockHeader[8];
    /* 0x8 */ u32 count;
    /* 0xc */ SndArcFileInfo files[];
} SndArcFat;

typedef struct NNSSndArc {
    /* 0x00 */ SndArcHeader header;
    /* 0x30 */ BOOL file_open;
    /* 0x34 */ u8 file[0x48];
    /* 0x7c */ FSFileID fileId;
    /* 0x84 */ const char *altPath;
    /* 0x88 */ u32 altTop;
    /* 0x8c */ u32 altBottom;
    /* 0x90 */ SndArcFat *fat;
    /* 0x94 */ void *symbol;
    /* 0x98 */ SndArcInfo *info;
    /* 0x9c */ s32 loadBlockSize;
} NNSSndArc; // size 0xa0

extern BOOL FS_ConvertPathToFileID(FSFileID *fileId, const char *path); // FS_ConvertPathToFileID
extern void FS_InitFile(void *file);                         // FS_InitFile
extern BOOL FS_OpenFileFast(void *file, FSFileID id);            // FS_OpenFileFast
extern BOOL FS_OpenFileEx(void *file, const char *path, u32 mode);
extern BOOL FS_SeekFile(void *file, int offset, int origin); // FS_SeekFile
extern int FS_ReadFile(void *file, void *buf, u32 size);     // FS_ReadFile

extern NNSSndArc *data_020961ec; // sCurrent

static void InfoDisposeCallback(void *mem, u32 size, u32 data1, u32 data2);
static void FatDisposeCallback(void *mem, u32 size, u32 data1, u32 data2);
static void SymbolDisposeCallback(void *mem, u32 size, u32 data1, u32 data2);

static inline const void *GetPtrConst(const void *base, u32 offset) {
    if (offset == 0) {
        return NULL;
    }
    return (const u8 *)base + offset;
}

static inline const SndArcOffsetTable *GetOffsetTable(const SndArcInfo *info, u32 offset) {
    return (const SndArcOffsetTable *)GetPtrConst(info, offset);
}

BOOL NNS_SndArcSetup(NNSSndArc *arc, NNSSndHeap *heap, BOOL symbolLoadFlag);

void NNS_SndArcInit(NNSSndArc *arc, const char *filePath, NNSSndHeap *heap, BOOL symbolLoadFlag) {
    BOOL result;

    arc->info = NULL;
    arc->fat = NULL;
    arc->symbol = NULL;
    arc->loadBlockSize = 0;
    arc->altPath = NULL;
    arc->altTop = 0;
    arc->altBottom = 0;

    result = FS_ConvertPathToFileID(&arc->fileId, filePath);
    if (result) {
        FS_InitFile(arc->file);
        result = FS_OpenFileFast(arc->file, arc->fileId);
        if (!result) {
            return;
        }
    } else {
        arc->fileId.arc = NULL;
        arc->fileId.fileId = (u32)-1;
        result = FS_OpenFileEx(arc->file, filePath, 1);
        if (!result) {
            return;
        }
    }

    arc->file_open = TRUE;

    result = NNS_SndArcSetup(arc, heap, symbolLoadFlag);
    if (!result) {
        return;
    }

    data_020961ec = arc;
}

BOOL NNS_SndArcSetup(NNSSndArc *arc, NNSSndHeap *heap, BOOL symbolLoadFlag) {
    BOOL result;
    s32 readSize;

    result = FS_SeekFile(arc->file, 0, 0);
    if (!result) {
        return FALSE;
    }

    readSize = FS_ReadFile(arc->file, &arc->header, sizeof(arc->header));
    if (readSize != sizeof(arc->header)) {
        return FALSE;
    }

    if (heap != NULL) {
        arc->info = (SndArcInfo *)NNS_SndHeapAlloc(heap, arc->header.infoSize, InfoDisposeCallback, (u32)arc, 0);
        if (arc->info == NULL) {
            return FALSE;
        }
        result = FS_SeekFile(arc->file, (s32)arc->header.infoOffset, 0);
        if (!result) {
            return FALSE;
        }
        readSize = FS_ReadFile(arc->file, arc->info, (s32)arc->header.infoSize);
        if (readSize != arc->header.infoSize) {
            return FALSE;
        }

        arc->fat = (SndArcFat *)NNS_SndHeapAlloc(heap, arc->header.fatSize, FatDisposeCallback, (u32)arc, 0);
        if (arc->fat == NULL) {
            return FALSE;
        }
        result = FS_SeekFile(arc->file, (s32)arc->header.fatOffset, 0);
        if (!result) {
            return FALSE;
        }
        readSize = FS_ReadFile(arc->file, arc->fat, (s32)arc->header.fatSize);
        if (readSize != arc->header.fatSize) {
            return FALSE;
        }

        if (symbolLoadFlag && arc->header.symbolDataSize > 0) {
            arc->symbol = NNS_SndHeapAlloc(heap, arc->header.symbolDataSize, SymbolDisposeCallback, (u32)arc, 0);
            if (arc->symbol == NULL) {
                return FALSE;
            }
            result = FS_SeekFile(arc->file, (s32)arc->header.symbolDataOffset, 0);
            if (!result) {
                return FALSE;
            }

            readSize = FS_ReadFile(arc->file, arc->symbol, (s32)arc->header.symbolDataSize);
            if (readSize != arc->header.symbolDataSize) {
                return FALSE;
            }
        }
    }

    return TRUE;
}

NNSSndArc *NNS_SndArcSetCurrent(NNSSndArc *arc) {
    NNSSndArc *oldArc = data_020961ec;
    data_020961ec = arc;
    return oldArc;
}

NNSSndArc *NNS_SndArcGetCurrent(void) {
    return data_020961ec;
}

#define DEFINE_GET_INFO(name, type, field)                                                                             \
    type *name(int no) {                                                                                         \
        NNSSndArc *arc = data_020961ec;                                                                                \
        const SndArcOffsetTable *table;                                                                                \
                                                                                                                       \
        table = GetOffsetTable(arc->info, arc->info->field);                                                           \
        if (table == NULL) {                                                                                           \
            return NULL;                                                                                               \
        }                                                                                                              \
                                                                                                                       \
        if (no < 0) {                                                                                                  \
            return NULL;                                                                                               \
        }                                                                                                              \
        if (no >= table->count) {                                                                                      \
            return NULL;                                                                                               \
        }                                                                                                              \
                                                                                                                       \
        return (type *)GetPtrConst(arc->info, table->offset[no]);                                                \
    }

DEFINE_GET_INFO(NNS_SndArcGetSeqInfo, NNSSndArcSeqInfo, seqOffset)
DEFINE_GET_INFO(NNS_SndArcGetSeqArcInfo, NNSSndArcSeqArcInfo, seqArcOffset)
DEFINE_GET_INFO(NNS_SndArcGetBankInfo, NNSSndArcBankInfo, bankOffset)
DEFINE_GET_INFO(NNS_SndArcGetWaveArcInfo, NNSSndArcWaveArcInfo, waveArcOffset)
DEFINE_GET_INFO(NNS_SndArcGetStrmInfo, NNSSndArcStrmInfo, strmOffset)
DEFINE_GET_INFO(NNS_SndArcGetPlayerInfo, NNSSndArcPlayerInfo, playerInfoOffset)
DEFINE_GET_INFO(NNS_SndArcGetStrmPlayerInfo, NNSSndArcStrmPlayerInfo, strmPlayerInfoOffset)
DEFINE_GET_INFO(NNS_SndArcGetGroupInfo, NNSSndArcGroupInfo, groupInfoOffset)

#define DEFINE_GET_COUNT(name, field)                                                                                  \
    u32 name(void) {                                                                                                   \
        NNSSndArc *arc = data_020961ec;                                                                                \
        const SndArcOffsetTable *table;                                                                                \
                                                                                                                       \
        table = GetOffsetTable(arc->info, arc->info->field);                                                           \
        if (table == NULL) {                                                                                           \
            return 0;                                                                                                  \
        }                                                                                                              \
                                                                                                                       \
        return table->count;                                                                                           \
    }

DEFINE_GET_COUNT(NNS_SndArcGetSeqCount, seqOffset)
DEFINE_GET_COUNT(NNS_SndArcGetSeqArcCount, seqArcOffset)
DEFINE_GET_COUNT(NNS_SndArcGetBankCount, bankOffset)
DEFINE_GET_COUNT(NNS_SndArcGetWaveArcCount, waveArcOffset)
DEFINE_GET_COUNT(NNS_SndArcGetStrmCount, strmOffset)
DEFINE_GET_COUNT(NNS_SndArcGetGroupCount, groupInfoOffset)

u32 NNS_SndArcGetFileOffset(u32 fileId) {
    NNSSndArc *arc = data_020961ec;

    if (fileId >= arc->fat->count) {
        return 0;
    }
    return arc->fat->files[fileId].offset;
}

u32 NNS_SndArcGetFileSize(u32 fileId) {
    NNSSndArc *arc = data_020961ec;

    if (fileId >= arc->fat->count) {
        return 0;
    }
    return arc->fat->files[fileId].size;
}

s32 NNS_SndArcReadFile(u32 fileId, void *buffer, s32 size, s32 offset) {
    NNSSndArc *arc = data_020961ec;
    const SndArcFileInfo *file;
    s32 totalReadSize;
    s32 readSize;
    s32 blockSize;
    s32 currentOffset;
    s32 requestSize;
    u8 *destAddress;

    if (fileId >= arc->fat->count) {
        return -1;
    }
    file = &arc->fat->files[fileId];

    currentOffset = offset;

    blockSize = arc->loadBlockSize;
    if (blockSize == 0) {
        blockSize = size;
    }
    totalReadSize = 0;
    destAddress = (u8 *)buffer;

    while (totalReadSize < size) {
        requestSize = size - totalReadSize;
        if (requestSize > blockSize) {
            requestSize = blockSize;
        }
        if (requestSize > file->size - currentOffset) {
            requestSize = (s32)(file->size - currentOffset);
        }
        if (requestSize == 0) {
            break;
        }

        if (!FS_SeekFile(arc->file, (s32)(file->offset + currentOffset), 0)) {
            return -1;
        }
        readSize = FS_ReadFile(arc->file, destAddress, requestSize);
        if (readSize < 0) {
            return readSize;
        }

        totalReadSize += readSize;
        currentOffset += readSize;
        destAddress += readSize;
    }

    return totalReadSize;
}

FSFileID NNS_SndArcGetFileID(void) {
    NNSSndArc *arc = data_020961ec;

    return arc->fileId;
}

void *NNS_SndArcGetFileAddress(u32 fileId) {
    NNSSndArc *arc = data_020961ec;

    if (fileId >= arc->fat->count) {
        return NULL;
    }
    return arc->fat->files[fileId].mem;
}

void NNS_SndArcSetFileAddress(u32 fileId, void *address) {
    NNSSndArc *arc = data_020961ec;

    arc->fat->files[fileId].mem = address;
}

const char *func_020304dc(void) {
    NNSSndArc *arc = data_020961ec;

    return arc->altPath;
}

u32 func_020304f0(void) {
    NNSSndArc *arc = data_020961ec;

    return arc->altTop;
}

u32 func_02030504(void) {
    NNSSndArc *arc = data_020961ec;

    return arc->altBottom;
}

static void InfoDisposeCallback(void *mem, u32 size, u32 data1, u32 data2) {
    NNSSndArc *arc = (NNSSndArc *)data1;

    arc->info = NULL;
}

static void FatDisposeCallback(void *mem, u32 size, u32 data1, u32 data2) {
    NNSSndArc *arc = (NNSSndArc *)data1;

    arc->fat = NULL;
}

static void SymbolDisposeCallback(void *mem, u32 size, u32 data1, u32 data2) {
    NNSSndArc *arc = (NNSSndArc *)data1;

    arc->symbol = NULL;
}
