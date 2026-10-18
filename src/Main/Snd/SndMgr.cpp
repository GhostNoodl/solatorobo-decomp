#include "Main/Snd/SndMgr.h"

extern "C" {

void func_020492e0(SndMgr *mgr) {
    s32 i;
    for (i = 0; i < 2; i++) {
        mgr->heaps[i] = NULL;
        mgr->heapLevels[i] = -1;
    }
    for (i = 0; i < 5; i++) {
        mgr->seqArcHandles[i] = NULL;
    }
    for (i = 0; i < 5; i++) {
        mgr->seqArcSlots[i] = -1;
    }
    mgr->seqArcNext = 0;
    mgr->unk_9c = 0;
}

}
