#include "Main/Snd/SndMgr.h"

extern "C" {

static inline void SndMgr_StartBgm(SndMgr *mgr, s32 seq, s32 vol) {
    NNS_SndArcPlayerStartSeq(&mgr->bgm, seq);
    if (vol < 0 || vol > 100) {
        vol = SndMgr_GetSeqVolume(seq);
    }
    NNS_SndPlayerSetVolume(&mgr->bgm, vol);
    mgr->curBgm = seq;
    NNS_SndPlayerSetPlayerPriority(&mgr->bgm, 0x7f);
}

void SndMgr_UpdateLoad(SndMgr *mgr);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match declared the local seq as an unused second parameter
// (callers pass only mgr) and renamed the header prototype out of the way; as a local the registers differ. This file
// is the function's whole .text, so it has no delinks entry. The score is in docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void SndMgr_UpdateLoad(SndMgr *mgr) {
    s32 seq;
    s32 i;
    switch (mgr->loadType) {
        case 0:
            return;
        case 1:
            NNS_SndHeapLoadState(mgr->heaps[0], mgr->heapLevels[0]);
            if (NNS_SndArcLoadSeq(mgr->loadId, gSndQueue.mgr->heaps[0]) == TRUE) {
                if (mgr->playAfterLoad) {
                    seq = mgr->loadId;
                    SndMgr_StartBgm(mgr, seq, mgr->loadArg);
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
            NNS_SndArcLoadSeqArc(mgr->loadId, gSndQueue.mgr->heaps[0]);
            break;
        case 3:
            NNS_SndArcLoadBank(mgr->loadId, gSndQueue.mgr->heaps[0]);
            break;
        case 4:
            if (mgr->loadId < 2 || mgr->loadId == 3) {
                if (NNS_SndArcLoadGroup(mgr->loadId, gSndQueue.mgr->heaps[0]) == TRUE) {
                    mgr->heapLevels[0] = NNS_SndHeapSaveState(mgr->heaps[0]);
                }
            } else {
                if (NNS_SndArcLoadGroup(mgr->loadId, gSndQueue.mgr->heaps[1]) == TRUE) {
                    mgr->heapLevels[1] = NNS_SndHeapSaveState(mgr->heaps[1]);
                }
            }
            break;
        case 5:
            if (NNS_SndArcLoadSeqEx(mgr->loadId, 1, gSndQueue.mgr->heaps[0]) == TRUE) {
                mgr->loadedSeqEx[mgr->loadArg] = mgr->loadId;
            }
            break;
    }
    mgr->loadType = 0;
    NNS_SndHeapGetFreeSize(gSndQueue.mgr->heaps[0]);
    NNS_SndHeapGetFreeSize(gSndQueue.mgr->heaps[1]);
}
#endif

}
