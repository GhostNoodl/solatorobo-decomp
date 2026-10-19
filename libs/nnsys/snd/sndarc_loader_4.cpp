extern "C" {
#include "nnsys/snd/sndarc.h"

extern void DC_StoreRange(void *buffer, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
void func_020311a4(void *data, u32 size, u32 arc, u32 fileId);

extern SndWaveArc data_020961f0; // static wave archive header buffer
}

// The target pools the header buffer twice; this file is C++ only for this second declaration.
namespace Dup { extern "C" SndWaveArc data_020961f0; }

// Loads a wave archive's header and offset table; the table's second half is filled in as waves are loaded.
extern "C" void *LoadWaveArcTable(u32 fileId, NNSSndHeap *heap, BOOL setAddress) {
    u32 size2;
    SndWaveArc *waveArc;
    u32 tableSize;
    void *arc;

    waveArc = (SndWaveArc *)NNS_SndArcGetFileAddress(fileId);
    if (waveArc == NULL) {
        arc = NULL;
        if (NNS_SndArcReadFile(fileId, &data_020961f0, sizeof(SndWaveArc), 0) != sizeof(SndWaveArc)) {
            return NULL;
        }
        tableSize = Dup::data_020961f0.waveCount * sizeof(u32);
        size2 = tableSize * 2;
        if (heap == NULL) {
            return NULL;
        }
        if (setAddress) {
            arc = NNS_SndArcGetCurrent();
        }
        waveArc = (SndWaveArc *)NNS_SndHeapAlloc(heap, sizeof(SndWaveArc) + size2 + 0x20, (NNSSndHeapDisposeCallback)func_020311a4, (u32)arc, fileId);
        if (waveArc == NULL) {
            return NULL;
        }
        {
            int readSize = NNS_SndArcReadFile(fileId, waveArc, (int)(sizeof(SndWaveArc) + tableSize), 0);
            if (readSize != (int)sizeof(SndWaveArc) + (int)tableSize) {
                return NULL;
            }
        }
        MI_CpuCopy8(waveArc->waveOffset, &waveArc->waveOffset[waveArc->waveCount], tableSize);
        MI_CpuFill8(waveArc->waveOffset, 0, tableSize);
        DC_StoreRange(waveArc, sizeof(SndWaveArc) + size2);
        if (setAddress) {
            NNS_SndArcSetFileAddress(fileId, waveArc);
        }
    }
    return waveArc;
}
