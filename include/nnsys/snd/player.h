#ifndef NNSYS_SND_PLAYER_H
#define NNSYS_SND_PLAYER_H

#include "types.h"
#include "nitro/snd.h"
#include "nnsys/fnd/list.h"
#include "nnsys/snd/heap.h"
#include "nnsys/snd/sndarc.h"

#ifdef __cplusplus
extern "C" {
#endif

// NitroSystem sequence player (NNS_SndPlayer*).

#define NNS_SND_PLAYER_NUM 32

#define NNS_SND_SEQ_PLAYER_STATUS_STOP    0
#define NNS_SND_SEQ_PLAYER_STATUS_PLAY    1
#define NNS_SND_SEQ_PLAYER_STATUS_FADEOUT 2

#define NNS_SND_PLAYER_SEQ_TYPE_INVALID 0
#define NNS_SND_PLAYER_SEQ_TYPE_SEQ     1
#define NNS_SND_PLAYER_SEQ_TYPE_SEQARC  2

struct NNSSndHandle;
struct NNSSndPlayer;
struct NNSSndPlayerHeap;

typedef struct NNSSndSeqPlayer {
    /* 0x00 */ struct NNSSndHandle *handle;
    /* 0x04 */ struct NNSSndPlayer *player;
    /* 0x08 */ struct NNSSndPlayerHeap *heap;
    /* 0x0c */ NNSFndLink playerLink;
    /* 0x14 */ NNSFndLink prioLink;
    /* 0x1c */ SndFader fader;
    /* 0x2c */ u8 status;
    /* 0x2d */ u8 startFlag;
    /* 0x2e */ u8 pauseFlag;
    /* 0x2f */ u8 prepareFlag;
    /* 0x30 */ u32 commandTag;
    /* 0x34 */ u16 seqType;
    /* 0x36 */ u16 padding;
    /* 0x38 */ u16 seqNo;
    /* 0x3a */ u16 seqArcIndex;
    /* 0x3c */ u8 playerNo;
    /* 0x3d */ u8 prio;
    /* 0x3e */ s16 volume;
    /* 0x40 */ u8 initVolume;
    /* 0x41 */ u8 extVolume;
} NNSSndSeqPlayer; // size 0x44

typedef struct NNSSndPlayer {
    /* 0x00 */ NNSFndList playerList;
    /* 0x0c */ NNSFndList heapList;
    /* 0x18 */ u32 playableSeqCount;
    /* 0x1c */ u32 allocChBitFlag;
    /* 0x20 */ u8 volume;
} NNSSndPlayer; // size 0x24

typedef struct NNSSndPlayerHeap {
    /* 0x00 */ NNSFndLink link;
    /* 0x08 */ NNSSndHeap *handle;
    /* 0x0c */ NNSSndSeqPlayer *player;
    /* 0x10 */ int playerNo;
} NNSSndPlayerHeap; // size 0x14

typedef struct NNSSndHandle {
    /* 0x0 */ NNSSndSeqPlayer *player;
} NNSSndHandle;

static inline BOOL NNS_SndHandleIsValid(const NNSSndHandle *handle) {
    return handle->player != NULL;
}

void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int seqCount);
void NNS_SndPlayerSetAllocatableChannel(int playerNo, u32 chBitFlag);
BOOL NNS_SndPlayerCreateHeap(int playerNo, NNSSndHeap *heap, u32 size);
void NNS_SndPlayerStopSeq(NNSSndHandle *handle, int fadeFrame);
void NNS_SndPlayerStopSeqBySeqNo(int seqNo, int fadeFrame);
void NNS_SndPlayerStopSeqBySeqArcIdx(int seqArcNo, int index, int fadeFrame);
void NNS_SndPlayerStopSeqAll(int fadeFrame);
void NNS_SndPlayerPause(NNSSndHandle *handle, BOOL flag);
void NNS_SndHandleInit(NNSSndHandle *handle);
void NNS_SndHandleReleaseSeq(NNSSndHandle *handle);
void NNS_SndPlayerSetVolume(NNSSndHandle *handle, int volume);
void NNS_SndPlayerSetInitialVolume(NNSSndHandle *handle, int volume);
void NNS_SndPlayerMoveVolume(NNSSndHandle *handle, int targetVolume, int frames);
void NNS_SndPlayerSetPlayerPriority(NNSSndHandle *handle, int priority);
void NNS_SndPlayerSetChannelPriority(NNSSndHandle *handle, int priority);
void NNS_SndPlayerSetTrackPitch(NNSSndHandle *handle, u16 trackBitMask, int pitch);
void NNS_SndPlayerSetTrackPan(NNSSndHandle *handle, u16 trackBitMask, int pan);
void NNS_SndPlayerSetSeqNo(NNSSndHandle *handle, int seqNo);
void NNS_SndPlayerSetSeqArcNo(NNSSndHandle *handle, int seqArcNo, int index);
void NNSi_SndPlayerInit(void);
void NNSi_SndPlayerMain(void);
NNSSndSeqPlayer *NNSi_SndPlayerAllocSeqPlayer(NNSSndHandle *handle, int playerNo, int prio);
void NNSi_SndPlayerFreeSeqPlayer(NNSSndSeqPlayer *seqPlayer);
void NNSi_SndPlayerStartSeq(NNSSndSeqPlayer *seqPlayer, const void *seqDataBase, u32 seqDataOffset, SNDBankData *bank);
void NNSi_SndPlayerStopSeq(NNSSndSeqPlayer *seqPlayer, int fadeFrame);
void NNSi_SndPlayerPause(NNSSndSeqPlayer *seqPlayer, BOOL flag);
NNSSndHeap *NNSi_SndPlayerAllocHeap(int playerNo, NNSSndSeqPlayer *seqPlayer);

#ifdef __cplusplus
}
#endif

#endif
