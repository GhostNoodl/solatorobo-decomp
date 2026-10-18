#include "nnsys/snd/sndarc.h"

SndSeqArcSeqInfo *func_02032eac(SndSeqArc *seqArc, int index) {
    if (index < 0) {
        return NULL;
    }
    if (index >= seqArc->count) {
        return NULL;
    }
    if (seqArc->info[index].offset == 0xffffffff) {
        return NULL;
    }
    return &seqArc->info[index];
}

void NNSi_SndFaderInit(SndFader *fader) {
    fader->origin = fader->target = 0;
    fader->counter = fader->frames = 0;
}

void NNSi_SndFaderSet(SndFader *fader, int target, int frames) {
    fader->origin = NNSi_SndFaderGet(fader);
    fader->target = target;
    fader->frames = frames;
    fader->counter = 0;
}

int NNSi_SndFaderGet(SndFader *fader) {
    if (fader->counter >= fader->frames) {
        return fader->target;
    }
    return fader->origin + (fader->target - fader->origin) * fader->counter / fader->frames;
}

void NNSi_SndFaderUpdate(SndFader *fader) {
    if (fader->counter < fader->frames) {
        fader->counter++;
    }
}

BOOL NNSi_SndFaderIsFinished(SndFader *fader) {
    return fader->counter >= fader->frames;
}
