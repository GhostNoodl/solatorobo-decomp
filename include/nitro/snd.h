#ifndef NITRO_SND_H
#define NITRO_SND_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SND_ALARM_COUNT 8

#define SND_CMD_FLAG_NOBLOCK   0x0
#define SND_CMD_FLAG_BLOCK     0x1
#define SND_CMD_FLAG_IMMEDIATE 0x2

#define SND_CMD_START_SEQ             0x00
#define SND_CMD_STOP_SEQ              0x01
#define SND_CMD_PREPARE_SEQ           0x02
#define SND_CMD_START_PREPARED_SEQ    0x03
#define SND_CMD_PAUSE_SEQ             0x04
#define SND_CMD_SKIP_SEQ              0x05
#define SND_CMD_PLAYER_PARAM          0x06
#define SND_CMD_TRACK_PARAM           0x07
#define SND_CMD_MUTE_TRACK            0x08
#define SND_CMD_ALLOCATABLE_CHANNEL   0x09
#define SND_CMD_PLAYER_LOCAL_VAR      0x0a
#define SND_CMD_PLAYER_GLOBAL_VAR     0x0b
#define SND_CMD_START_TIMER           0x0c
#define SND_CMD_STOP_TIMER            0x0d
#define SND_CMD_SETUP_CHANNEL_PCM     0x0e
#define SND_CMD_SETUP_CHANNEL_PSG     0x0f
#define SND_CMD_SETUP_CHANNEL_NOISE   0x10
#define SND_CMD_SETUP_CAPTURE         0x11
#define SND_CMD_SETUP_ALARM           0x12
#define SND_CMD_CHANNEL_TIMER         0x13
#define SND_CMD_CHANNEL_VOLUME        0x14
#define SND_CMD_CHANNEL_PAN           0x15
#define SND_CMD_SURROUND_DECAY        0x16
#define SND_CMD_MASTER_VOLUME         0x17
#define SND_CMD_MASTER_PAN            0x18
#define SND_CMD_OUTPUT_SELECTOR       0x19
#define SND_CMD_LOCK_CHANNEL          0x1a
#define SND_CMD_UNLOCK_CHANNEL        0x1b
#define SND_CMD_STOP_UNLOCKED_CHANNEL 0x1c
#define SND_CMD_SET_SHARED_WORK       0x1d
#define SND_CMD_INVALIDATE_SEQ        0x1e
#define SND_CMD_INVALIDATE_BANK       0x1f
#define SND_CMD_INVALIDATE_WAVE       0x20
#define SND_CMD_READ_DRIVER_INFO      0x21

typedef struct SNDCommand {
    struct SNDCommand *next; // 0x00
    s32 id;                  // 0x04
    u32 arg[4];              // 0x08
} SNDCommand; // size 0x18

typedef void (*SNDAlarmHandler)(void *arg);

#define SND_PLAYER_COUNT 16

typedef struct SNDSharedWork {
    u32 finishCommandTag; // 0x00
    u32 playerStatus;     // 0x04
    u16 channelStatus;    // 0x08
    u16 captureStatus;    // 0x0a
    u32 padding[5];       // 0x0c
    struct {
        s16 localVariable[16]; // 0x00
        u32 tickCounter;       // 0x20
    } player[SND_PLAYER_COUNT]; // 0x20
    s16 globalVariable[16];    // 0x260
} SNDSharedWork; // size 0x280

extern SNDSharedWork *SNDi_SharedWork;

#define SND_INST_MAX_KEYSPLIT 8

#define SND_INST_ILLEGAL    0
#define SND_INST_PCM        1
#define SND_INST_PSG        2
#define SND_INST_NOISE      3
#define SND_INST_DIRECTPCM  4
#define SND_INST_NULL       5
#define SND_INST_DRUM_SET   16
#define SND_INST_KEY_SPLIT  17

#define SND_BANK_MAX_WAVEARC 4

typedef struct SNDBinaryFileHeader {
    char signature[4]; // 0x00
    u16 byteOrder;     // 0x04
    u16 version;       // 0x06
    u32 fileSize;      // 0x08
    u16 headerSize;    // 0x0c
    u16 dataBlocks;    // 0x0e
} SNDBinaryFileHeader; // size 0x10

typedef struct SNDBinaryBlockHeader {
    u32 kind; // 0x00
    u32 size; // 0x04
} SNDBinaryBlockHeader; // size 0x8

typedef struct SNDInstParam {
    u16 wave[2];   // 0x0
    u8 originalKey; // 0x4
    u8 attack;     // 0x5
    u8 decay;      // 0x6
    u8 sustain;    // 0x7
    u8 release;    // 0x8
    u8 pan;        // 0x9
} SNDInstParam; // size 0xa

typedef struct SNDInstData {
    u8 type;            // 0x0
    u8 padding_;        // 0x1
    SNDInstParam param; // 0x2
} SNDInstData; // size 0xc

typedef struct SNDKeySplit {
    u8 key[SND_INST_MAX_KEYSPLIT]; // 0x0
    SNDInstData instOffset[0];     // 0x8
} SNDKeySplit;

typedef struct SNDDrumSet {
    u8 min;                    // 0x0
    u8 max;                    // 0x1
    SNDInstData instOffset[0]; // 0x2
} SNDDrumSet;

typedef struct SNDInstPos {
    u32 prgNo; // 0x0
    u32 index; // 0x4
} SNDInstPos;

struct SNDWaveArc;

typedef struct SNDWaveArcLink {
    struct SNDWaveArc *waveArc;  // 0x0
    struct SNDWaveArcLink *next; // 0x4
} SNDWaveArcLink; // size 0x8

typedef struct SNDBankData {
    SNDBinaryFileHeader fileHeader;                 // 0x00
    SNDBinaryBlockHeader blockHeader;               // 0x10
    SNDWaveArcLink waveArcLink[SND_BANK_MAX_WAVEARC]; // 0x18
    u32 instCount;                                  // 0x38
    u32 instOffset[0];                              // 0x3c
} SNDBankData;

typedef struct SNDWaveArc {
    SNDBinaryFileHeader fileHeader;   // 0x00
    SNDBinaryBlockHeader blockHeader; // 0x10
    SNDWaveArcLink *topLink;          // 0x18
    u32 reserved[7];                  // 0x1c
    u32 waveCount;                    // 0x38
    u32 waveOffset[0];                // 0x3c
} SNDWaveArc;

typedef struct SNDWaveData SNDWaveData;

struct SNDBankData;
void SND_StopSeq(s32 player);
void SND_PrepareSeq(s32 player, const void *seqBase, u32 seqOffset, struct SNDBankData *bank);
void SND_StartPreparedSeq(s32 player);
void SND_PauseSeq(s32 player, BOOL flag);
void SND_SetPlayerVolume(s32 player, s32 volume);
void SND_SetPlayerChannelPriority(s32 player, s32 prio);
void SND_SetTrackPitch(s32 player, u32 trackBitMask, s32 pitch);
void SND_SetTrackPan(s32 player, u32 trackBitMask, s32 pan);
void SND_SetTrackAllocatableChannel(s32 player, u32 trackBitMask, u32 chnBitMask);
void SND_StartTimer(u32 chnBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void SND_StopTimer(u32 chnBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void SND_SetupAlarm(s32 alarm, u32 tick, u32 period, SNDAlarmHandler handler, void *arg);
void SND_LockChannel(u32 chnBitMask, u32 flags);
void SND_UnlockChannel(u32 chnBitMask, u32 flags);
void SND_SetChannelVolume(u32 chnBitMask, s32 volume, s32 chnDataShift);
void SND_SetChannelPan(u32 chnBitMask, s32 pan);
void SND_SetupChannelPcm(s32 chn, s32 waveFormat, const void *dataAddr, s32 loopMode, s32 loopStart,
                         s32 dataLen, s32 volume, s32 chnDataShift, s32 timer, s32 pan);
void SND_InvalidateSeqData(const void *start, const void *end);
void SND_InvalidateBankData(const void *start, const void *end);
void SND_InvalidateWaveData(const void *start, const void *end);
void SND_SetOutputSelector(s32 left, s32 right, s32 channel1, s32 channel3);

extern const s16 SNDi_DecibelTable[128];

static inline s16 SND_CalcDecibel(int scale) {
    return SNDi_DecibelTable[scale];
}

void SND_Init(void);
void SNDi_LockMutex(void);
void SNDi_UnlockMutex(void);

void SND_CommandInit(void);
const SNDCommand *SND_RecvCommandReply(u32 flags);
SNDCommand *SND_AllocCommand(u32 flags);
void SND_PushCommand(SNDCommand *cmd);
BOOL SND_FlushCommand(u32 flags);
void SND_WaitForCommandProc(u32 tag);
u32 SND_GetCurrentCommandTag(void);
BOOL SND_IsFinishedCommandTag(u32 tag);
s32 SND_CountFreeCommand(void);
s32 SND_CountReservedCommand(void);
s32 SND_CountWaitingCommand(void);

void SND_AlarmInit(void);
void SNDi_CallAlarmHandler(s32 id);

u32 SND_GetPlayerStatus(void);
u32 SNDi_GetFinishedCommandTag(void);
void SNDi_InitSharedWork(SNDSharedWork *work);

u16 SND_CalcChannelVolume(int dB);

void SND_AssignWaveArc(SNDBankData *bank, int index, SNDWaveArc *waveArc);
void SND_DestroyBank(SNDBankData *bank);
void SND_DestroyWaveArc(SNDWaveArc *waveArc);
SNDInstPos SND_GetFirstInstDataPos(const SNDBankData *bank);
BOOL SND_GetNextInstData(const SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos);
u32 SND_GetWaveDataCount(const SNDWaveArc *waveArc);
void SND_SetWaveDataAddress(SNDWaveArc *waveArc, int index, const SNDWaveData *address);
const SNDWaveData *SND_GetWaveDataAddress(const SNDWaveArc *waveArc, int index);

void SNDi_IncAlarmId(u32 id);
u8 SNDi_SetAlarmHandler(u32 id, SNDAlarmHandler handler, void *arg);

void SNDi_SetPlayerParam(s32 player, u32 offset, u32 data, s32 size);
void SNDi_SetTrackParam(s32 player, u32 trackBitMask, u32 offset, u32 data, s32 size);

#ifdef __cplusplus
}
#endif

#endif
