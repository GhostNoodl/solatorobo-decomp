#include "Main/Movie/Movie.h"
#include "nnsys/snd/heap.h"

extern "C" {

Movie *data_02097e3c;

extern void *func_0203dd9c(u32 size);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void PM_AppendPreSleepCallback(MovieSleepCb *cb);
extern void PM_AppendPostSleepCallback(MovieSleepCb *cb);
extern BOOL OS_IsRunOnTwl(void);
void func_02044670(Movie *m);
void func_0204479c(Movie *m, int arg);
void func_02043ef8(Movie *m);

extern void SND_StartTimer(int chMask, int capMask, int alarmMask, int flags);
extern void SND_StopTimer(int chMask, int capMask, int alarmMask, int flags);
extern void SND_SetupAlarm(int alarm, u32 tick, u32 period, void (*cb)(void), void *arg);
extern void SND_LockChannel(int chMask, int flags);
extern void SND_UnlockChannel(int chMask, int flags);
extern void SND_SetupChannelPcm(int ch, int fmt, const void *data, int loop, int loopStart, u32 len, int volume, int volumeDiv, int timer, int pan);
extern void SND_FlushCommand(int flags);
extern int OS_IsThreadTerminated(Movie *m);
extern void OS_DestroyThread(Movie *m);
extern void OS_SleepThreadDirect(Movie *m, int arg);
extern void OS_SleepThread(int arg);
extern void func_0203df40(void *ptr);
extern void func_0203365c(void *audio);
extern void func_0203379c(void *audio);
extern u32 func_020336dc(void *audio);
extern u32 func_020336f4(void *audio);
extern BOOL func_0203370c(void *audio);
extern BOOL func_02033754(void *audio);
extern u32 func_020337c0(void *audio);
extern void func_020337d8(void *audio, s16 *dst);
extern void FS_CloseFile(void *file);
extern void DC_StoreRange(const void *addr, u32 size);
extern void func_02049564(void *obj, int a, int b);
extern void *data_02097e4c;

void func_02043e38(void) {
    Movie *m = data_02097e3c;
    if (m->state == 0) {
        return;
    }
    func_02044670(m);
    m->paused = TRUE;
}

void func_02043e6c(void) {
    Movie *m = data_02097e3c;
    if (m->state == 0) {
        return;
    }
    if (m->paused) {
        m->paused = FALSE;
    }
}

void func_02043e9c(void) {
    Movie *m;
    if (data_02097e3c != NULL) {
        return;
    }
    data_02097dd0->cur = data_02097dd0->unk_04;
    m = (Movie *)func_0203dd9c(sizeof(Movie));
    if (m != NULL) {
        func_02043ef8(m);
    }
    data_02097e3c = m;
    data_02097dd0->cur = data_02097dd0->unk_08;
}

void func_02043ef8(Movie *m) {
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
    m->preSleep.func = (void (*)(void))func_02043e38;
    m->preSleep.arg = NULL;
    PM_AppendPreSleepCallback(&m->preSleep);
    m->postSleep.func = (void (*)(void))func_02043e6c;
    m->postSleep.arg = NULL;
    PM_AppendPostSleepCallback(&m->postSleep);
}

extern u32 OS_GetArenaLo(int region);
extern u32 OS_GetArenaHi(int region);
extern u32 func_02034600(void);
extern u32 func_0203460c(void);
extern void func_02034614(u32 addr, u32 size);
extern void func_02034634(u32 addr, u32 size);
extern void FS_InitFile(void *file);
extern BOOL FS_OpenFile(void *file, const char *path);
extern void *func_02033580(void *file, int n);
extern u32 func_020336c4(void *audio);
extern u32 func_020336ac(void *audio);
extern u32 func_0203367c(void *audio);
extern u8 func_02033694(void *audio);
extern void func_02033730(void *audio);
extern void func_02033778(void *audio, u32 vram, int stride, int mode);
extern NNSSndHeap *func_02049550(void *obj, int idx);
extern void *func_0203dec8(u32 size, u32 align);
extern void OS_CreateThread(Movie *m, void (*cb)(int), int arg, void *buf, u32 size, int prio);
extern void OS_WakeupThreadDirect(Movie *m);
extern void OS_SetThreadStackWarningOffset(Movie *m, int arg);
extern const char data_0208b3d8[];
void func_02044494(int arg);
void func_02044538(Movie *m);
void func_020448dc(Movie *m);

static inline void Sys_SetFrameWait(u8 w) {
    UnkSys *sys = data_02097dd0;
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

void func_02043f70(Movie *m) {
    char path[0x60];
    u32 lo;
    u32 size;
    u32 bs;
    u32 n;
    switch (m->state) {
    case 1:
        func_02044538(m);
        data_02097d48->nextState = 3;
        lo = OS_GetArenaLo(3);
        size = OS_GetArenaHi(3) - lo;
        if (size >= func_02034600()) {
            size = func_02034600();
        }
        func_02034614(OS_GetArenaLo(3), size);
        lo = OS_GetArenaLo(4);
        size = OS_GetArenaHi(4) - lo;
        if (size >= func_0203460c()) {
            size = func_0203460c();
        }
        func_02034634(OS_GetArenaLo(4), size);
        STD_CopyString(path, data_0208b3d8);
        STD_ConcatenateString(path, m->name);
        FS_InitFile(m->file);
        if (!FS_OpenFile(m->file, path)) {
            m->state = 0;
            return;
        }
        m->audio = func_02033580(m->file, 10);
        if (m->audio == NULL) {
            FS_CloseFile(m->file);
            m->state = 0;
            return;
        }
        m->unk_138 = 0;
        m->opened = TRUE;
        m->unk_13c = func_020336c4(m->audio);
        m->unk_140 = func_020336ac(m->audio);
        m->sampleRate = func_0203367c(m->audio);
        m->channels = func_02033694(m->audio);
        m->numQueued = 0;
        m->writePos = 0;
        m->numBlocks = 0;
        bs = func_020336dc(m->audio);
        n = ((u64)m->sampleRate << 24) / ((u64)m->unk_140 * bs);
        n = (n + 1) * 11;
        m->bufSize = n * bs * 2;
        m->blockCount = n;
        if (m->channels >= 1) {
            func_02049564(data_02097e4c, 1, 1);
            m->bufL = (s16 *)NNS_SndHeapAlloc(func_02049550(data_02097e4c, 1), m->bufSize, NULL, 0, 0);
            MIi_CpuClearFast(0, m->bufL, m->bufSize);
        }
        if (m->channels >= 2) {
            m->bufR = (s16 *)NNS_SndHeapAlloc(func_02049550(data_02097e4c, 1), m->bufSize, NULL, 0, 0);
            MIi_CpuClearFast(0, m->bufR, m->bufSize);
        }
        m->buf = func_0203dec8(0x300, 4);
        OS_CreateThread(m, func_02044494, 0, (u8 *)m->buf + 0x300, 0x300, 0x11);
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
            func_020448dc(m);
        }
        m->state = 4;
        return;
    case 4:
        if (m->paused) {
            func_02044670(m);
            return;
        }
        if (m->numQueued >= 3 && m->numBlocks >= 4) {
            data_02097d48->unk_a30_2 = 1;
            func_02033778(m->audio, data_02097d48->unk_a30_3 == 0 ? 0x6820000 : 0x6800000, 0x100, m->mode);
            m->numQueued--;
        } else if (func_020336f4(m->audio) < m->unk_13c) {
            data_02097d48->unk_a30_2 = 0;
            if (m->numQueued != 0) {
                func_0203379c(m->audio);
                m->numQueued--;
            }
        }
        if (++m->unk_138 >= m->unk_13c) {
            if (!m->loop) {
                func_02044538(m);
                m->state = 6;
                return;
            }
            m->unk_138 = 0;
            func_02033730(m->audio);
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
            func_020448dc(m);
        }
        m->state = 4;
        return;
    case 6:
        func_02044538(m);
        m->name[0] = 0;
        m->state = 0;
        *(u8 *)((u8 *)m + 0x14b) = 0;
        data_02097d48->nextState = 1;
        data_02097dd0->frameWait = 1;
        return;
    }
}

void func_02044494(int arg) {
    func_0204479c(data_02097e3c, arg);
}

void func_020444b0(Movie *m, int idx, int mode, BOOL loop) {
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

void func_02044524(Movie *m) {
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

void func_02044538(Movie *m) {
    u32 i;
    if (!m->opened) {
        return;
    }
    data_02097d48->unk_a30_2 = 0;
    Movie_StopSound(m);
    if (OS_IsThreadTerminated(m) == 0) {
        OS_DestroyThread(m);
        if (m->buf != NULL) {
            func_0203df40(m->buf);
            m->buf = NULL;
        }
    }
    for (i = 0; i < m->numQueued; i++) {
        func_0203379c(m->audio);
    }
    m->numQueued = 0;
    func_0203365c(m->audio);
    FS_CloseFile(m->file);
    if (m->bufL != NULL || m->bufR != NULL) {
        func_02049564(data_02097e4c, 1, 1);
    }
    m->bufL = NULL;
    m->bufR = NULL;
    m->opened = FALSE;
}

void func_02044670(Movie *m) {
    if (!m->playing) {
        return;
    }
    OS_SleepThreadDirect(m, 0);
    data_02097d48->unk_a30_2 = 0;
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
        m->writePos = func_020336dc(m->audio) * m->numBlocks;
    }
    m->state = 7;
}

void func_0204479c(Movie *m, int arg) {
    u32 bs = func_020336dc(m->audio);
    u32 total = m->blockCount * bs;
    for (;;) {
        if (m->numQueued >= 10 || func_020336f4(m->audio) >= m->unk_13c || m->state == 6) {
            OS_SleepThread(0);
            continue;
        }
        if (!func_0203370c(m->audio)) {
            return;
        }
        if (!func_02033754(m->audio)) {
            return;
        }
        if (m->channels != 0) {
            u64 n = func_020337c0(m->audio);
            int i;
            for (i = 0; i < n; i++) {
                func_020337d8(m->audio, m->bufL + m->writePos);
                if (m->channels >= 2) {
                    func_020337d8(m->audio, m->bufR + m->writePos);
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

void func_020448bc(void) {
    Movie *m = data_02097e3c;
    if (m->numBlocks != 0) {
        m->numBlocks--;
    }
}

void func_020448dc(Movie *m) {
    u32 timer;
    u32 bs;
    int ch;
    int pan;
    m->soundOn = TRUE;
    timer = 0xffb0ff / m->sampleRate;
    bs = func_020336dc(m->audio);
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
    SND_SetupAlarm(0, (bs >> 6) * (timer << 1), (bs >> 6) * (timer << 1), func_020448bc, NULL);
    SND_StartTimer(ch, 0, 1, 0);
    SND_FlushCommand(1);
}

}
