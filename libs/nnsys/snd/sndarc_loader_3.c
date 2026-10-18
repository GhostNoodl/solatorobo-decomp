#include "nnsys/snd/sndarc.h"

extern SndInstIterator func_0201cc18(void);
extern BOOL func_0201cc38(void *bank, SndInstData *inst, SndInstIterator *iter);

BOOL func_020312d4(SndWaveArc *waveArc, void *bank, int waveArcIndex, u32 fileId, GroupHeap *heap) {
    SndInstIterator iter = func_0201cc18();
    SndInstData inst;
    if (bank == NULL) {
        return FALSE;
    }
    while (func_0201cc38(bank, &inst, &iter)) {
        if (inst.type == 1 && waveArcIndex == inst.waveArcNo) {
            if (!func_0203120c(waveArc, inst.waveIndex, fileId, heap)) {
                return FALSE;
            }
        }
    }
    return TRUE;
}
