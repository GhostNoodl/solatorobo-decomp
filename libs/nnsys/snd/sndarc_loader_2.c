#include "nnsys/snd/sndarc.h"

// Heap callbacks of sndarc_loader.c, which release loaded files.

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);
extern void SND_InvalidateSeqData(void *start, void *end);
extern void SND_InvalidateBankData(void *start, void *end);
extern void SND_InvalidateWaveData(void *start, void *end);
extern void SND_DestroyBank(void *bank);
extern void SND_DestroyWaveArc(void *waveArc);
extern void *SND_GetWaveDataAddress(SndWaveArc *waveArc, int index);
extern void SND_SetWaveDataAddress(SndWaveArc *waveArc, int index, void *data);

void func_020310c4(void *data, void *arc, u32 fileId) {
    void *prev;
    u32 state;
    if (arc == NULL) {
        return;
    }
    state = OS_DisableInterrupts();
    prev = func_0202fef8(arc);
    if (data == func_02030498(fileId)) {
        func_020304c0(fileId, NULL);
    }
    func_0202fef8(prev);
    OS_RestoreInterrupts(state);
}

void func_0203111c(void *data, u32 size, u32 arc, u32 fileId) {
    func_020310c4(data, (void *)arc, fileId);
    SND_InvalidateSeqData(data, (u8 *)data + size);
}

void func_02031144(void *data, u32 size, u32 arc, u32 fileId) {
    func_020310c4(data, (void *)arc, fileId);
    SND_InvalidateBankData(data, (u8 *)data + size);
    SND_DestroyBank(data);
}

void func_02031174(void *data, u32 size, u32 arc, u32 fileId) {
    func_020310c4(data, (void *)arc, fileId);
    SND_InvalidateWaveData(data, (u8 *)data + size);
    SND_DestroyWaveArc(data);
}

void func_020311a4(void *data, u32 size, u32 arc, u32 fileId) {
    func_020310c4(data, (void *)arc, fileId);
    SND_DestroyWaveArc(data);
}

void func_020311c4(void *data, u32 size, u32 waveArc, u32 index) {
    if (data == SND_GetWaveDataAddress((SndWaveArc *)waveArc, index)) {
        SND_SetWaveDataAddress((SndWaveArc *)waveArc, index, NULL);
    }
    SND_InvalidateWaveData(data, (u8 *)data + size);
}
