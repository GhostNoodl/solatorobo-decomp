#include "nnsys/snd/sndarc.h"

// Heap callbacks of sndarc_loader.c, which release loaded files.

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
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
    prev = NNS_SndArcSetCurrent(arc);
    if (data == NNS_SndArcGetFileAddress(fileId)) {
        NNS_SndArcSetFileAddress(fileId, NULL);
    }
    NNS_SndArcSetCurrent(prev);
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

extern u32 SND_GetWaveDataCount(const SndWaveArc *waveArc);
extern void DC_StoreRange(const void *startAddr, u32 nBytes);

// LoadSingleWave: loads one wave of a wave archive into the heap, unless it is already loaded.
BOOL func_0203120c(SndWaveArc *waveArc, int index, u32 fileId, NNSSndHeap *heap) {
    u32 count;
    u32 *p;
    u32 waveOffset;
    u32 waveSize;
    void *buffer;
    if (SND_GetWaveDataAddress(waveArc, index) != NULL) {
        return TRUE;
    }
    count = SND_GetWaveDataCount(waveArc);
    // p[15] is waveOffset[waveCount + index]; indexing from the struct base matches the target's addressing.
    p = (u32 *)waveArc + (waveArc->waveCount + index);
    waveOffset = p[15];
    if (index < count - 1) {
        waveSize = p[16] - waveOffset;
    } else {
        waveSize = waveArc->fileSize - waveOffset;
    }
    if (heap == NULL) {
        return FALSE;
    }
    buffer = NNS_SndHeapAlloc(heap, waveSize + 0x20, func_020311c4, (u32)waveArc, index);
    if (buffer == NULL) {
        return FALSE;
    }
    if (NNS_SndArcReadFile(fileId, buffer, waveSize, waveOffset) != waveSize) {
        return FALSE;
    }
    DC_StoreRange(buffer, waveSize);
    SND_SetWaveDataAddress(waveArc, index, buffer);
    return TRUE;
}
