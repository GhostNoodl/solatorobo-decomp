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

void func_02032eec(SndFader *fader) {
    fader->origin = fader->target = 0;
    fader->counter = fader->frames = 0;
}

void func_02032f04(SndFader *fader, int target, int frames) {
    fader->origin = func_02032f2c(fader);
    fader->target = target;
    fader->frames = frames;
    fader->counter = 0;
}

int func_02032f2c(SndFader *fader) {
    if (fader->counter >= fader->frames) {
        return fader->target;
    }
    return fader->origin + (fader->target - fader->origin) * fader->counter / fader->frames;
}

void func_02032f60(SndFader *fader) {
    if (fader->counter < fader->frames) {
        fader->counter++;
    }
}

BOOL func_02032f78(SndFader *fader) {
    return fader->counter >= fader->frames;
}
