#ifndef NNSYS_SND_SNDARC_STREAM_H
#define NNSYS_SND_SNDARC_STREAM_H

#include "nnsys/fnd/list.h"
#include "nnsys/snd/sndarc.h"
#include "nitro/os.h"
#include "nitro/mi.h"
#include "nnsys/snd/stream.h"

#ifdef __cplusplus
extern "C" {
#endif

// NitroSystem sound archive stream player (NNS_SndArcStrm*).

typedef struct StrmHeader {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ u8 format;
    /* 0x19 */ u8 loop;
    /* 0x1a */ u8 channels;
    /* 0x1b */ u8 unk_1b;
    /* 0x1c */ u16 sampleRate;
    /* 0x1e */ u16 timer;
    /* 0x20 */ u32 loopStart;
    /* 0x24 */ u32 sampleCount;
    /* 0x28 */ u32 dataOffset;
    /* 0x2c */ u32 numBlocks;
    /* 0x30 */ u32 blockSize;
    /* 0x34 */ u32 blockSamples;
    /* 0x38 */ u32 lastBlockSize;
    /* 0x3c */ u32 lastBlockSamples;
} StrmHeader; // size 0x40

typedef struct StrmAdpcmState {
    /* 0x0 */ s16 pred;
    /* 0x2 */ u8 index;
} StrmAdpcmState; // size 0x4

struct StrmHandle;

typedef struct StrmPlayer {
    /* 0x000 */ NNSSndStrm strm;
    /* 0x064 */ u8 file[0x48];
    /* 0x0ac */ u32 fileOffset;
    /* 0x0b0 */ StrmHeader header;
    /* 0x0f0 */ SndFader fader;
    /* 0x100 */ StrmAdpcmState adpcm[6];
    /* 0x118 */ BOOL active : 1;
    /* 0x118 */ BOOL playing : 1;
    /* 0x118 */ BOOL startReq : 1;
    /* 0x118 */ BOOL stopReq : 1;
    /* 0x118 */ BOOL unk_118_4 : 1;
    /* 0x118 */ BOOL unk_118_5 : 1;
    /* 0x118 */ BOOL mono : 1;
    /* 0x11c */ volatile int unk_11c;
    /* 0x120 */ volatile int unk_120;
    /* 0x124 */ int cmdCount;
    /* 0x128 */ int chRefCount;
    /* 0x12c */ u8 chNum;
    /* 0x12d */ u8 unk_12d;
    /* 0x12e */ u8 chList[6];
    /* 0x134 */ void *buffer;
    /* 0x138 */ u32 bufSize;
    /* 0x13c */ u32 unk_13c;
    /* 0x140 */ u32 unk_140;
    /* 0x144 */ BOOL (*callback)(u32 *arg0, u32 *arg1, u32 a, u32 b);
    /* 0x148 */ u32 callbackArg;
    /* 0x14c */ u32 strmNo;
    /* 0x150 */ int playerNo;
    /* 0x154 */ struct StrmHandle *handle;
    /* 0x158 */ int prio;
    /* 0x15c */ int volume;
    /* 0x160 */ int userVolume;
    /* 0x164 */ int curVolume;
    /* 0x168 */ u32 startOffset;
    /* 0x16c */ BOOL (*openFn)(struct StrmPlayer *player, u32 fileId);
    /* 0x170 */ void (*closeFn)(struct StrmPlayer *player);
    /* 0x174 */ u32 (*readFn)(struct StrmPlayer *player, void *buf, u32 size, u32 offset);
    /* 0x178 */ void (*stopFn)(struct StrmPlayer *player);
} StrmPlayer; // size 0x17c

typedef struct StrmHandle {
    /* 0x0 */ StrmPlayer *volatile player;
} StrmHandle;

typedef struct StrmCommand {
    /* 0x00 */ NNSFndLink link;
    /* 0x08 */ StrmPlayer *player;
    /* 0x0c */ int unk_0c;
    /* 0x10 */ int numBuffers;
    /* 0x14 */ void *buffers[6];
    /* 0x2c */ u32 size;
} StrmCommand; // size 0x30

typedef struct StrmThread {
    /* 0x0000 */ OSThread thread;
    /* 0x00c0 */ u8 stack[0x1000];
    /* 0x10c0 */ OSThreadQueue queue;
    /* 0x10c8 */ OSMutex mutex;
    /* 0x10e0 */ NNSFndList cmdList;
} StrmThread; // size 0x10ec

typedef struct StrmGlobals {
    /* 0x0 */ BOOL initialized;
    /* 0x4 */ StrmThread *altThread;
    /* 0x8 */ void *unk_8;
} StrmGlobals;

extern StrmGlobals data_0209622c;
extern NNSFndList data_02096238;
extern OSMutex data_02096244;
extern StrmCommand data_0209625c[8];
extern u8 data_020963e0[];
extern StrmPlayer data_020965e0[4];
extern StrmThread data_02096bd0;
extern OSMutex data_02097c98;
extern NNSFndList data_02097cb0;
extern const s16 data_02075210[];

extern void FS_InitFile(void *file);

typedef struct StrmCbInfo {
    /* 0x0 */ int playerNo;
    /* 0x4 */ u32 strmNo;
} StrmCbInfo;

typedef struct StrmCbNext {
    /* 0x0 */ u32 strmNo;
    /* 0x4 */ u32 offset;
} StrmCbNext;

typedef struct FSFileID {
    /* 0x0 */ void *arc;
    /* 0x4 */ u32 fileId;
} FSFileID;

extern FSFileID NNS_SndArcGetFileID(void);
extern void *SndArc_GetAltPath(void);
extern u32 SndArc_GetAltTop(void);
extern u32 SndArc_GetAltBottom(void);
extern BOOL FS_OpenFileFast(void *file, FSFileID id);
extern BOOL FS_OpenFileEx(void *file, void *arc, u32 mode);
extern BOOL FS_SetSeekCache(void *file, u32 top, u32 bottom);
extern BOOL FS_CloseFile(void *file);
extern BOOL FS_SeekFile(void *file, int offset, int origin);
extern int FS_ReadFile(void *file, void *buf, u32 size);
extern void FS_CancelFile(void *file);
extern void Strm_ProcessCommand(StrmCommand *cmd);

void NNS_SndArcStrmInit(u32 prio, NNSSndHeap *heap);
BOOL Strm_SetupPlayers(NNSSndHeap *heap);
BOOL NNS_SndArcStrmPrepare(StrmHandle *handle, int strmNo, u32 offset);
void NNS_SndArcStrmStartPrepared(StrmHandle *handle);
BOOL NNS_SndArcStrmStart(StrmHandle *handle, int strmNo, u32 offset);
void NNS_SndArcStrmStop(StrmHandle *handle, int frames);
void NNS_SndArcStrmSetVolume(StrmHandle *handle, int volume);
void NNS_SndArcStrmMoveVolume(StrmHandle *handle, int volume, int frames);
void NNS_SndArcStrmInitHandle(StrmHandle *handle);
void NNS_SndArcStrmReleaseHandle(StrmHandle *handle);
void NNSi_SndArcStrmMain(void);
StrmThread *Strm_GetThread(void);
StrmPlayer *Strm_AllocPlayer(StrmHandle *handle, int playerNo, int prio);
void StrmPlayer_Free(StrmPlayer *player);
BOOL Strm_PreparePlayer(StrmHandle *handle, const NNSSndArcStrmInfo *info, int playerNo, int prio, u32 strmNo, u32 offset, u32 a6, u32 a7, void *a8, u32 a9);
void StrmPlayer_Stop(StrmPlayer *player, int frames);
void StrmPlayer_ForceStop(StrmPlayer *player);
void StrmPlayer_Shutdown(StrmPlayer *player);
BOOL StrmPlayer_AllocChannel(StrmPlayer *player, int chNum, u8 *chList);
void StrmPlayer_FreeChannel(StrmPlayer *player);
void StrmThread_Init(StrmThread *thread, u32 prio);
void Strm_RemovePlayerCommands(NNSFndList *list, StrmPlayer *player);
StrmCommand *Strm_PopCommand(NNSFndList *list);
StrmCommand *Strm_AllocCommand(void);
void Strm_FreeCommand(StrmCommand *cmd);
void StrmPlayer_OnHeapDispose(void *data, u32 size, u32 arg0, u32 arg1);
void StrmPlayer_OnStrmData(int status, int numBuffers, void **buffers, u32 size, int format, void *arg);
void StrmPlayer_NextStream(StrmPlayer *player);
void StrmPlayer_SetFileFuncs(StrmPlayer *player, u32 fileId);
BOOL StrmPlayer_OpenArcFile(StrmPlayer *player, u32 fileId);
void StrmPlayer_CloseArcFile(StrmPlayer *player);
u32 StrmPlayer_ReadArcFile(StrmPlayer *player, void *buf, u32 size, u32 offset);
void StrmPlayer_CancelArcFile(StrmPlayer *player);
BOOL StrmPlayer_OpenMem(StrmPlayer *player, u32 fileId);
void StrmPlayer_CloseMem(StrmPlayer *player);
u32 StrmPlayer_ReadMem(StrmPlayer *player, void *buf, u32 size, u32 offset);
void StrmPlayer_CancelMem(StrmPlayer *player);
void StrmThread_Main(void *arg);

#ifdef __cplusplus
}
#endif

#endif
