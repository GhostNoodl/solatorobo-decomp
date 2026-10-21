#include "Main/Snd/SndMgr.h"

extern "C" {

NNSSndHeap *func_02049550(SndMgr *mgr, u32 idx) {
    if (idx >= 2) {
        return NULL;
    }
    return mgr->heaps[idx];
}

void func_02049564(SndMgr *mgr, s32 level, s32 idx) {
    if (idx < 0 || idx >= 2) {
        return;
    }
    if (level < 0) {
        return;
    }
    if (level > mgr->heapLevels[idx]) {
        return;
    }
    NNS_SndHeapLoadState(mgr->heaps[idx], level);
    mgr->heapLevels[idx] = level;
}

void func_020495ac(SndMgr *mgr, s32 type, s32 id) {
    switch (type) {
        case 0:
            break;
        case 1:
            NNS_SndHeapLoadState(mgr->heaps[0], mgr->heapLevels[0]);
            NNS_SndArcLoadSeq(id, data_02097e48.mgr->heaps[0]);
            break;
        case 2:
            NNS_SndArcLoadSeqArc(id, data_02097e48.mgr->heaps[0]);
            break;
        case 3:
            if (NNS_SndArcLoadBank(id, data_02097e48.mgr->heaps[0]) == TRUE) {
                mgr->heapLevels[0] = NNS_SndHeapSaveState(mgr->heaps[0]);
            }
            break;
        case 4:
            if (NNS_SndArcLoadGroup(id, data_02097e48.mgr->heaps[0]) == TRUE) {
                mgr->heapLevels[0] = NNS_SndHeapSaveState(mgr->heaps[0]);
            }
            break;
    }
    mgr->loadType = 0;
    NNS_SndHeapGetFreeSize(data_02097e48.mgr->heaps[0]);
    NNS_SndHeapGetFreeSize(data_02097e48.mgr->heaps[1]);
}

void func_02049678(SndMgr *mgr, s32 type, s32 id, s32 arg) {
    SndMgr_RequestLoad(mgr, type, id, arg);
}

}
