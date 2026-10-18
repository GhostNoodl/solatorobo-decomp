#include "nnsys/snd/sndarc.h"

extern SndInstIterator SND_GetFirstInstDataPos(void);
extern BOOL SND_GetNextInstData(void *bank, SndInstData *inst, SndInstIterator *iter);

BOOL func_020312d4(SndWaveArc *waveArc, void *bank, int waveArcIndex, u32 fileId, NNSSndHeap *heap) {
    SndInstIterator iter = SND_GetFirstInstDataPos();
    SndInstData inst;
    if (bank == NULL) {
        return FALSE;
    }
    while (SND_GetNextInstData(bank, &inst, &iter)) {
        if (inst.type == 1 && waveArcIndex == inst.waveArcNo) {
            if (!func_0203120c(waveArc, inst.waveIndex, fileId, heap)) {
                return FALSE;
            }
        }
    }
    return TRUE;
}
