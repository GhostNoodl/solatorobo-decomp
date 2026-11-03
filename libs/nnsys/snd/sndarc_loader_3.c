#include "nnsys/snd/sndarc.h"

extern SndInstIterator SND_GetFirstInstDataPos(void);
extern BOOL SND_GetNextInstData(void *bank, SndInstData *inst, SndInstIterator *iter);

BOOL SndArcLd_LoadBankWaves(SndWaveArc *waveArc, void *bank, int waveArcIndex, u32 fileId, NNSSndHeap *heap) {
    SndInstIterator iter = SND_GetFirstInstDataPos();
    SndInstData inst;
    if (bank == NULL) {
        return FALSE;
    }
    while (SND_GetNextInstData(bank, &inst, &iter)) {
        if (inst.type == 1 && waveArcIndex == inst.waveArcNo) {
            if (!SndArcLd_LoadWave(waveArc, inst.waveIndex, fileId, heap)) {
                return FALSE;
            }
        }
    }
    return TRUE;
}
