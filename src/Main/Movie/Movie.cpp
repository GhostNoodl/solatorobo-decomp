#include "Main/Movie/Movie.h"
#include "nnsys/snd/heap.h"
#include "nitro/mi.h"

extern "C" {

Movie *gMovie;

extern void *Heap_Alloc(u32 size);
extern void PM_AppendPreSleepCallback(MovieSleepCb *cb);
extern void PM_AppendPostSleepCallback(MovieSleepCb *cb);
extern BOOL OS_IsRunOnTwl(void);
void Movie_StopPlayback(Movie *m);
void Movie_DecodeLoop(Movie *m, int arg);
void Movie_Init(Movie *m);

extern void SND_StartTimer(int chMask, int capMask, int alarmMask, int flags);
extern void SND_StopTimer(int chMask, int capMask, int alarmMask, int flags);
extern void SND_SetupAlarm(int alarm, u32 tick, u32 period, void (*cb)(void), void *arg);
extern void SND_LockChannel(int chMask, int flags);
extern void SND_UnlockChannel(int chMask, int flags);
extern void SND_SetupChannelPcm(int ch, int fmt, const void *data, int loop, int loopStart, u32 len, int volume, int volumeDiv, int timer, int pan);
extern BOOL SND_FlushCommand(int flags);
extern int OS_IsThreadTerminated(Movie *m);
extern void OS_DestroyThread(Movie *m);
extern void OS_SleepThreadDirect(Movie *m, int arg);
extern void OS_SleepThread(int arg);
extern void Heap_FreeLo(void *ptr);
extern void Mo_ClosePlayer(void *audio);
extern BOOL Mo_SkipFrame(void *audio);
extern u32 Mo_GetBlockSize(void *audio);
extern u32 Mo_GetCurFrame(void *audio);
extern BOOL Mo_ReadFrame(void *audio);
extern BOOL Mo_DecodeFrame(void *audio);
extern u32 Mo_GetChunkSamples(void *audio);
extern BOOL Mo_DecodeAudio(void *audio, s16 *dst);
extern BOOL FS_CloseFile(void *file);
extern void DC_StoreRange(const void *addr, u32 size);
extern void SndMgr_LoadHeapState(void *obj, int a, int b);
extern void *gSndMgr;

void Movie_Pause(void) {
    Movie *m = gMovie;
    if (m->state == 0) {
        return;
    }
    Movie_StopPlayback(m);
    m->paused = TRUE;
}

void Movie_Resume(void) {
    Movie *m = gMovie;
    if (m->state == 0) {
        return;
    }
    if (m->paused) {
        m->paused = FALSE;
    }
}

void Movie_Create(void) {
    Movie *m;
    if (gMovie != NULL) {
        return;
    }
    gSysState->cur = gSysState->heapLo;
    m = (Movie *)Heap_Alloc(sizeof(Movie));
    if (m != NULL) {
        Movie_Init(m);
    }
    gMovie = m;
    gSysState->cur = gSysState->heapHi;
}

void Movie_Init(Movie *m) {
    m->state = 0;
    *(u8 *)((u8 *)m + 0x14a) = 0;
    *(u8 *)((u8 *)m + 0x14b) = 0;
    m->name[0] = 0;
    m->names = NULL;
    m->unk_0e8 = 0;
    m->bufR = NULL;
    m->bufL = NULL;
    m->numQueued = 0;
    MIi_CpuClearFast(0, m, 0xc0);
    m->buf = NULL;
    m->preSleep.func = (void (*)(void))Movie_Pause;
    m->preSleep.arg = NULL;
    PM_AppendPreSleepCallback(&m->preSleep);
    m->postSleep.func = (void (*)(void))Movie_Resume;
    m->postSleep.arg = NULL;
    PM_AppendPostSleepCallback(&m->postSleep);
}

extern u32 OS_GetArenaLo(int region);
extern u32 OS_GetArenaHi(int region);
extern u32 MoMem_GetLargeSize(void);
extern u32 MoMem_GetSmallSize(void);
extern int MoMem_SetLargeMem(u32 addr, u32 size);
extern int MoMem_SetSmallMem(u32 addr, u32 size);
extern void FS_InitFile(void *file);
extern BOOL FS_OpenFile(void *file, const char *path);
extern void *Mo_OpenFile(void *file, int n);
extern u32 Mo_GetNumFrames(void *audio);
extern u32 func_020336ac(void *audio);
extern u32 Mo_GetSampleRate(void *audio);
extern u16 Mo_GetAudioChannels(void *audio);
extern BOOL Mo_Rewind(void *audio);
extern BOOL Mo_ConvertFrame(void *audio, u32 vram, int stride, int mode);
extern NNSSndHeap *SndMgr_GetHeap(void *obj, int idx);
extern void *Heap_AllocLo(u32 size, u32 align);
extern void OS_CreateThread(Movie *m, void (*cb)(int), int arg, void *buf, u32 size, int prio);
extern void OS_WakeupThreadDirect(Movie *m);
extern void OS_SetThreadStackWarningOffset(Movie *m, int arg);
extern const char data_0208b3d8[];
void Movie_DecodeThread(int arg);
void Movie_Close(Movie *m);
void Movie_StartSound(Movie *m);

static inline void Sys_SetFrameWait(u8 w) {
    UnkSys *sys = gSysState;
    if (w < 1) {
        w = 1;
    }
    sys->frameWait = w;
}

static inline void Movie_SetFrameWait(u32 wait) {
    if (wait < 1) {
        wait = 1;
    }
    Sys_SetFrameWait(wait);
}

void Movie_Update(Movie *m) {
    char path[0x60];
    u32 lo;
    u32 size;
    u32 bs;
    u32 n;
    switch (m->state) {
    case 1:
        Movie_Close(m);
        gGfxSys->nextState = 3;
        lo = OS_GetArenaLo(3);
        size = OS_GetArenaHi(3) - lo;
        if (size >= MoMem_GetLargeSize()) {
            size = MoMem_GetLargeSize();
        }
        MoMem_SetLargeMem(OS_GetArenaLo(3), size);
        lo = OS_GetArenaLo(4);
        size = OS_GetArenaHi(4) - lo;
        if (size >= MoMem_GetSmallSize()) {
            size = MoMem_GetSmallSize();
        }
        MoMem_SetSmallMem(OS_GetArenaLo(4), size);
        STD_CopyString(path, data_0208b3d8);
        STD_ConcatenateString(path, m->name);
        FS_InitFile(m->file);
        if (!FS_OpenFile(m->file, path)) {
            m->state = 0;
            return;
        }
        m->audio = Mo_OpenFile(m->file, 10);
        if (m->audio == NULL) {
            FS_CloseFile(m->file);
            m->state = 0;
            return;
        }
        m->unk_138 = 0;
        m->opened = TRUE;
        m->unk_13c = Mo_GetNumFrames(m->audio);
        m->unk_140 = func_020336ac(m->audio);
        m->sampleRate = Mo_GetSampleRate(m->audio);
        m->channels = Mo_GetAudioChannels(m->audio);
        m->numQueued = 0;
        m->writePos = 0;
        m->numBlocks = 0;
        bs = Mo_GetBlockSize(m->audio);
        n = ((u64)m->sampleRate << 24) / ((u64)m->unk_140 * bs);
        n = (n + 1) * 11;
        m->bufSize = n * bs * 2;
        m->blockCount = n;
        if (m->channels >= 1) {
            SndMgr_LoadHeapState(gSndMgr, 1, 1);
            m->bufL = (s16 *)NNS_SndHeapAlloc(SndMgr_GetHeap(gSndMgr, 1), m->bufSize, NULL, 0, 0);
            MIi_CpuClearFast(0, m->bufL, m->bufSize);
        }
        if (m->channels >= 2) {
            m->bufR = (s16 *)NNS_SndHeapAlloc(SndMgr_GetHeap(gSndMgr, 1), m->bufSize, NULL, 0, 0);
            MIi_CpuClearFast(0, m->bufR, m->bufSize);
        }
        m->buf = Heap_AllocLo(0x300, 4);
        OS_CreateThread(m, Movie_DecodeThread, 0, (u8 *)m->buf + 0x300, 0x300, 0x11);
        OS_SetThreadStackWarningOffset(m, 0x4c);
        Movie_SetFrameWait(60 / (m->unk_140 >> 24));
        m->state = 2;
        return;
    case 2:
        MIi_CpuClearFast(0, (void *)0x6800000, 0x18000);
        MIi_CpuClearFast(0, (void *)0x6820000, 0x18000);
        OS_WakeupThreadDirect(m);
        m->playing = TRUE;
        m->state = 3;
        return;
    case 3:
        if (m->numQueued < 10) {
            return;
        }
        if (m->channels != 0) {
            Movie_StartSound(m);
        }
        m->state = 4;
        return;
    case 4:
        if (m->paused) {
            Movie_StopPlayback(m);
            return;
        }
        if (m->numQueued >= 3 && m->numBlocks >= 4) {
            gGfxSys->unk_a30_2 = 1;
            Mo_ConvertFrame(m->audio, gGfxSys->unk_a30_3 == 0 ? 0x6820000 : 0x6800000, 0x100, m->mode);
            m->numQueued--;
        } else if (Mo_GetCurFrame(m->audio) < m->unk_13c) {
            gGfxSys->unk_a30_2 = 0;
            if (m->numQueued != 0) {
                Mo_SkipFrame(m->audio);
                m->numQueued--;
            }
        }
        if (++m->unk_138 >= m->unk_13c) {
            if (!m->loop) {
                Movie_Close(m);
                m->state = 6;
                return;
            }
            m->unk_138 = 0;
            Mo_Rewind(m->audio);
        }
        OS_WakeupThreadDirect(m);
        return;
    case 7:
        if (m->paused) {
            return;
        }
        OS_WakeupThreadDirect(m);
        m->state = 8;
        return;
    case 8:
        if (m->numQueued < 10) {
            return;
        }
        if (m->channels != 0) {
            Movie_StartSound(m);
        }
        m->state = 4;
        return;
    case 6:
        Movie_Close(m);
        m->name[0] = 0;
        m->state = 0;
        *(u8 *)((u8 *)m + 0x14b) = 0;
        gGfxSys->nextState = 1;
        gSysState->frameWait = 1;
        return;
    }
}

void Movie_DecodeThread(int arg) {
    Movie_DecodeLoop(gMovie, arg);
}

void Movie_Load(Movie *m, int idx, int mode, BOOL loop) {
    STD_CopyString(m->name, m->names[idx]);
    m->state = 1;
    *(u8 *)((u8 *)m + 0x14a) = 0;
    m->loop = (u8)loop;
    if (mode < 0) {
        if (OS_IsRunOnTwl()) {
            mode = TRUE;
        } else {
            mode = FALSE;
        }
    }
    m->mode = mode;
}

void Movie_RequestStop(Movie *m) {
    if (m->state != 0) {
        m->state = 6;
    }
}

static inline void Movie_StopSound(Movie *m) {
    int ch;
    if (m->soundOn) {
        ch = 3;
        if (m->channels == 1) {
            ch = 1;
        }
        SND_StopTimer(ch, 0, 1, 0);
        SND_UnlockChannel(ch, 0);
        SND_FlushCommand(1);
        m->soundOn = FALSE;
    }
}

void Movie_Close(Movie *m) {
    u32 i;
    if (!m->opened) {
        return;
    }
    gGfxSys->unk_a30_2 = 0;
    Movie_StopSound(m);
    if (OS_IsThreadTerminated(m) == 0) {
        OS_DestroyThread(m);
        if (m->buf != NULL) {
            Heap_FreeLo(m->buf);
            m->buf = NULL;
        }
    }
    for (i = 0; i < m->numQueued; i++) {
        Mo_SkipFrame(m->audio);
    }
    m->numQueued = 0;
    Mo_ClosePlayer(m->audio);
    FS_CloseFile(m->file);
    if (m->bufL != NULL || m->bufR != NULL) {
        SndMgr_LoadHeapState(gSndMgr, 1, 1);
    }
    m->bufL = NULL;
    m->bufR = NULL;
    m->opened = FALSE;
}

void Movie_StopPlayback(Movie *m) {
    if (!m->playing) {
        return;
    }
    OS_SleepThreadDirect(m, 0);
    gGfxSys->unk_a30_2 = 0;
    Movie_StopSound(m);
    if (m->channels != 0) {
        MIi_CpuClearFast(0, m->bufL, m->bufSize);
        DC_StoreRange(m->bufL, m->bufSize);
        if (m->channels >= 2) {
            MIi_CpuClearFast(0, m->bufR, m->bufSize);
            DC_StoreRange(m->bufR, m->bufSize);
        }
    }
    if (m->numBlocks > m->blockCount) {
        m->writePos = 0;
    } else {
        if (m->numBlocks < 0x18) {
            m->numBlocks = 0x18;
        }
        m->writePos = Mo_GetBlockSize(m->audio) * m->numBlocks;
    }
    m->state = 7;
}

void Movie_DecodeLoop(Movie *m, int arg) {
    u32 bs = Mo_GetBlockSize(m->audio);
    u32 total = m->blockCount * bs;
    for (;;) {
        if (m->numQueued >= 10 || Mo_GetCurFrame(m->audio) >= m->unk_13c || m->state == 6) {
            OS_SleepThread(0);
            continue;
        }
        if (!Mo_ReadFrame(m->audio)) {
            return;
        }
        if (!Mo_DecodeFrame(m->audio)) {
            return;
        }
        if (m->channels != 0) {
            u64 n = Mo_GetChunkSamples(m->audio);
            int i;
            for (i = 0; i < n; i++) {
                Mo_DecodeAudio(m->audio, m->bufL + m->writePos);
                if (m->channels >= 2) {
                    Mo_DecodeAudio(m->audio, m->bufR + m->writePos);
                }
                m->writePos += bs;
                if (m->writePos >= total) {
                    m->writePos = 0;
                }
                m->numBlocks++;
            }
        }
        m->numQueued++;
    }
}

void Movie_ReleaseBlock(void) {
    Movie *m = gMovie;
    if (m->numBlocks != 0) {
        m->numBlocks--;
    }
}

void Movie_StartSound(Movie *m) {
    u32 timer;
    u32 bs;
    int ch;
    int pan;
    m->soundOn = TRUE;
    timer = 0xffb0ff / m->sampleRate;
    bs = Mo_GetBlockSize(m->audio);
    ch = 3;
    pan = 0;
    if (m->channels == 1) {
        ch = 1;
        pan = 0x40;
    }
    SND_LockChannel(ch, 0);
    SND_SetupChannelPcm(0, 1, m->bufL, 1, 0, (m->blockCount * bs) >> 1, 0x7f, 0, timer, pan);
    if (m->channels >= 2) {
        SND_SetupChannelPcm(1, 1, m->bufR, 1, 0, (m->blockCount * bs) >> 1, 0x7f, 0, timer, 0x7f);
    }
    SND_SetupAlarm(0, (bs >> 6) * (timer << 1), (bs >> 6) * (timer << 1), Movie_ReleaseBlock, NULL);
    SND_StartTimer(ch, 0, 1, 0);
    SND_FlushCommand(1);
}

}
