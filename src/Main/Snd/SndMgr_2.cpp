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

#ifdef NONMATCHING
static inline void SndMgr_StartBgm(SndMgr *mgr, s32 seq, s32 vol) {
    NNS_SndArcPlayerStartSeq(&mgr->bgm, seq);
    if (vol < 0 || vol > 100) {
        vol = SndMgr_GetSeqVolume(seq);
    }
    NNS_SndPlayerSetVolume(&mgr->bgm, vol);
    mgr->curBgm = seq;
    NNS_SndPlayerSetPlayerPriority(&mgr->bgm, 0x7f);
}

void func_02049690(SndMgr *mgr) {
    s32 i;
    switch (mgr->loadType) {
        case 0:
            return;
        case 1:
            NNS_SndHeapLoadState(mgr->heaps[0], mgr->heapLevels[0]);
            if (NNS_SndArcLoadSeq(mgr->loadId, data_02097e48.mgr->heaps[0]) == TRUE) {
                if (mgr->playAfterLoad) {
                    SndMgr_StartBgm(mgr, mgr->loadId, mgr->loadArg);
                    mgr->playAfterLoad = FALSE;
                }
                mgr->loadedSeq = mgr->loadId;
                for (i = 0; i < 3; i++) {
                    mgr->loadedSeqEx[i] = -1;
                }
            } else {
                mgr->curBgm = -1;
            }
            break;
        case 2:
            NNS_SndArcLoadSeqArc(mgr->loadId, data_02097e48.mgr->heaps[0]);
            break;
        case 3:
            NNS_SndArcLoadBank(mgr->loadId, data_02097e48.mgr->heaps[0]);
            break;
        case 4:
            if (mgr->loadId < 2 || mgr->loadId == 3) {
                if (NNS_SndArcLoadGroup(mgr->loadId, data_02097e48.mgr->heaps[0]) == TRUE) {
                    mgr->heapLevels[0] = NNS_SndHeapSaveState(mgr->heaps[0]);
                }
            } else {
                if (NNS_SndArcLoadGroup(mgr->loadId, data_02097e48.mgr->heaps[1]) == TRUE) {
                    mgr->heapLevels[1] = NNS_SndHeapSaveState(mgr->heaps[1]);
                }
            }
            break;
        case 5:
            if (NNS_SndArcLoadSeqEx(mgr->loadId, 1, data_02097e48.mgr->heaps[0]) == TRUE) {
                mgr->loadedSeqEx[mgr->loadArg] = mgr->loadId;
            }
            break;
    }
    mgr->loadType = 0;
    NNS_SndHeapGetFreeSize(data_02097e48.mgr->heaps[0]);
    NNS_SndHeapGetFreeSize(data_02097e48.mgr->heaps[1]);
}
#endif

}
