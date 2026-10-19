#ifndef NNSYS_SND_SNDARC_H
#define NNSYS_SND_SNDARC_H

#include "types.h"
#include "nnsys/snd/heap.h"

#ifdef __cplusplus
extern "C" {
#endif

// NitroSystem sound archive (NNS_SndArc*).

#define NNS_SND_ARC_LOAD_SEQ    (1 << 0)
#define NNS_SND_ARC_LOAD_BANK   (1 << 1)
#define NNS_SND_ARC_LOAD_WAVE   (1 << 2)
#define NNS_SND_ARC_LOAD_SEQARC (1 << 3)

typedef enum SndArcLoadResult {
    SND_ARC_LOAD_SUCCESS = 0,
    SND_ARC_LOAD_ERR_INVALID_GROUP_NO = 1,
    SND_ARC_LOAD_ERR_INVALID_SEQ_NO = 2,
    SND_ARC_LOAD_ERR_INVALID_SEQARC_NO = 3,
    SND_ARC_LOAD_ERR_INVALID_BANK_NO = 4,
    SND_ARC_LOAD_ERR_INVALID_WAVEARC_NO = 5,
    SND_ARC_LOAD_ERR_FAILED_LOAD_SEQ = 6,
    SND_ARC_LOAD_ERR_FAILED_LOAD_SEQARC = 7,
    SND_ARC_LOAD_ERR_FAILED_LOAD_BANK = 8,
    SND_ARC_LOAD_ERR_FAILED_LOAD_WAVE = 9,
} SndArcLoadResult;

typedef struct NNSSndArcSeqInfo {
    /* 0x0 */ u32 fileId;
    /* 0x4 */ u16 bankNo;
    /* 0x6 */ u8 volume;
    /* 0x7 */ u8 channelPrio;
    /* 0x8 */ u8 playerPrio;
    /* 0x9 */ u8 playerNo;
    /* 0xa */ u16 reserved;
} NNSSndArcSeqInfo; // size 0xc

typedef struct NNSSndArcSeqArcInfo {
    /* 0x0 */ u32 fileId;
} NNSSndArcSeqArcInfo;

typedef struct NNSSndArcBankInfo {
    /* 0x0 */ u32 fileId;
    /* 0x4 */ u16 waveArcNo[4];
} NNSSndArcBankInfo; // size 0xc

typedef struct NNSSndArcWaveArcInfo {
    /* 0x0 */ u32 fileId : 24;
    /* 0x0 */ u32 flags : 8; // Bit 0: load single waves on demand
} NNSSndArcWaveArcInfo;

typedef struct NNSSndArcGroupItem {
    /* 0x0 */ u8 type;
    /* 0x1 */ u8 loadFlag;
    /* 0x2 */ u16 padding;
    /* 0x4 */ u32 index;
} NNSSndArcGroupItem; // size 0x8

typedef struct NNSSndArcGroupInfo {
    /* 0x0 */ u32 count;
    /* 0x4 */ NNSSndArcGroupItem item[];
} NNSSndArcGroupInfo;

typedef struct NNSSndArcPlayerInfo {
    /* 0x0 */ u8 seqMax;
    /* 0x1 */ u8 padding;
    /* 0x2 */ u16 allocChBitFlag;
    /* 0x4 */ u32 heapSize;
} NNSSndArcPlayerInfo; // size 0x8

typedef struct NNSSndArcStrmInfo {
    /* 0x0 */ u32 fileId;
    /* 0x4 */ u8 volume;
    /* 0x5 */ u8 playerPrio;
    /* 0x6 */ u8 playerNo;
    /* 0x7 */ u8 flags; // Bit 0: force stereo
} NNSSndArcStrmInfo;

typedef struct NNSSndArcStrmPlayerInfo {
    /* 0x0 */ u8 numChannels;
    /* 0x1 */ u8 chNoList[];
} NNSSndArcStrmPlayerInfo;

// Wave archive file (SNDWaveArc). Loaded "table only", waveOffset holds the wave data addresses followed by the wave
// offsets.
typedef struct SndWaveArc {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ u32 fileSize;
    /* 0x0c */ u8 unk_0c[0x2c];
    /* 0x38 */ u32 waveCount;
    /* 0x3c */ u32 waveOffset[];
} SndWaveArc;

typedef struct SndBinaryFile {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ u32 dataOffset;
} SndBinaryFile;

typedef struct SndInstIterator {
    /* 0x0 */ u32 unk_00;
    /* 0x4 */ u32 unk_04;
} SndInstIterator;

typedef struct SndInstData {
    /* 0x0 */ u8 type;
    /* 0x1 */ u8 padding;
    /* 0x2 */ u16 waveIndex;
    /* 0x4 */ u16 waveArcNo;
    /* 0x6 */ u8 unk_06[6];
} SndInstData; // size 0xc

typedef struct SndFader {
    /* 0x0 */ int origin;
    /* 0x4 */ int target;
    /* 0x8 */ int counter;
    /* 0xc */ int frames;
} SndFader; // size 0x10

typedef struct SndSeqArcSeqInfo {
    /* 0x0 */ u32 offset;
    /* 0x4 */ u16 bankNo;
    /* 0x6 */ u8 volume;
    /* 0x7 */ u8 channelPrio;
    /* 0x8 */ u8 playerPrio;
    /* 0x9 */ u8 playerNo;
    /* 0xa */ u16 reserved;
} SndSeqArcSeqInfo; // size 0xc

typedef struct SndSeqArc {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ u32 dataOffset;
    /* 0x1c */ u32 count;
    /* 0x20 */ SndSeqArcSeqInfo info[];
} SndSeqArc;

// sndarc.c
struct NNSSndArc;
struct NNSSndArc *NNS_SndArcSetCurrent(struct NNSSndArc *arc);
struct NNSSndArc *NNS_SndArcGetCurrent(void);
extern NNSSndArcSeqInfo *NNS_SndArcGetSeqInfo(int seqNo);
extern NNSSndArcSeqArcInfo *NNS_SndArcGetSeqArcInfo(int seqArcNo);
extern NNSSndArcBankInfo *NNS_SndArcGetBankInfo(int bankNo);
extern NNSSndArcWaveArcInfo *NNS_SndArcGetWaveArcInfo(int waveArcNo);
extern NNSSndArcStrmInfo *NNS_SndArcGetStrmInfo(int strmNo);
extern NNSSndArcPlayerInfo *NNS_SndArcGetPlayerInfo(int playerNo);
extern NNSSndArcStrmPlayerInfo *NNS_SndArcGetStrmPlayerInfo(int playerNo);
extern NNSSndArcGroupInfo *NNS_SndArcGetGroupInfo(int groupNo);
extern u32 NNS_SndArcGetFileOffset(u32 fileId);
extern u32 NNS_SndArcGetFileSize(u32 fileId);
extern int NNS_SndArcReadFile(u32 fileId, void *buffer, int size, int offset);
extern void *NNS_SndArcGetFileAddress(u32 fileId);
extern void NNS_SndArcSetFileAddress(u32 fileId, void *address);

// sndarc_loader.c
BOOL NNS_SndArcLoadGroup(int groupNo, NNSSndHeap *heap);
BOOL NNS_SndArcLoadSeq(int seqNo, NNSSndHeap *heap);
BOOL NNS_SndArcLoadSeqArc(int seqArcNo, NNSSndHeap *heap);
BOOL NNS_SndArcLoadBank(int bankNo, NNSSndHeap *heap);
BOOL NNS_SndArcLoadSeqEx(int seqNo, u32 loadFlag, NNSSndHeap *heap);
int func_020309a4(int groupNo, NNSSndHeap *heap);
int func_02030aa0(int seqNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out);
int func_02030b24(int seqArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out);
int func_02030b84(int bankNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out);
int func_02030cc4(int waveArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out);
void *func_02030d48(u32 fileId, NNSSndHeapDisposeCallback callback, u32 arg0, u32 arg1, NNSSndHeap *heap);
void *func_02030dec(u32 fileId, NNSSndHeap *heap, BOOL setAddress);
void *func_02030e58(u32 fileId, NNSSndHeap *heap, BOOL setAddress);
void *func_02030ec4(u32 fileId, NNSSndHeap *heap, BOOL setAddress);
void *func_02030f30(u32 fileId, NNSSndHeap *heap, BOOL setAddress);
void *LoadWaveArcTable(u32 fileId, NNSSndHeap *heap, BOOL setAddress);
void func_020310c4(void *data, void *arc, u32 fileId);
void func_0203111c(void *data, u32 size, u32 arc, u32 fileId);
void func_02031144(void *data, u32 size, u32 arc, u32 fileId);
void func_02031174(void *data, u32 size, u32 arc, u32 fileId);
void func_020311a4(void *data, u32 size, u32 arc, u32 fileId);
void func_020311c4(void *data, u32 size, u32 waveArc, u32 index);
BOOL func_0203120c(SndWaveArc *waveArc, int index, u32 fileId, NNSSndHeap *heap);
BOOL func_020312d4(SndWaveArc *waveArc, void *bank, int waveArcIndex, u32 fileId, NNSSndHeap *heap);

// sndarc_player.c
BOOL NNS_SndArcPlayerSetup(void *heap);
BOOL NNS_SndArcPlayerStartSeq(void *handle, int seqNo);
BOOL NNS_SndArcPlayerStartSeqArc(void *handle, int seqArcNo, int index);
BOOL func_020314f4(void *handle, int playerNo, int bankNo, int playerPrio, const NNSSndArcSeqInfo *info, int seqNo);
BOOL func_020315f8(void *handle, int playerNo, int bankNo, int playerPrio, const NNSSndArcSeqInfo *info, SndBinaryFile *seqArc, int seqArcNo, int index);

// sndarc_util.c
SndSeqArcSeqInfo *func_02032eac(SndSeqArc *seqArc, int index);
void NNSi_SndFaderInit(SndFader *fader);
void NNSi_SndFaderSet(SndFader *fader, int target, int frames);
int NNSi_SndFaderGet(SndFader *fader);
void NNSi_SndFaderUpdate(SndFader *fader);
BOOL NNSi_SndFaderIsFinished(SndFader *fader);

#ifdef __cplusplus
}
#endif

#endif
