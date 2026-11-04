#ifndef NONMATCHING
// FAKEMATCH (round fkA): SndMgr.h declares SndMgr_UpdateLoad(SndMgr *) for its callers; the fakematch below
// defines it with a second parameter, so the header's prototype is renamed out of the way.
#define SndMgr_UpdateLoad func_02049690_hdr
#endif
#include "Main/Snd/SndMgr.h"
#ifndef NONMATCHING
#undef SndMgr_UpdateLoad
#endif

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

#ifdef NONMATCHING
void SndMgr_UpdateLoad(SndMgr *mgr);
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
#else
// Round fkA fakematch (docs/FAKEMATCHES.md). The honest draft is the NONMATCHING branch above.
// FAKEMATCH: seq is a local declared as a fake second parameter (callers pass only mgr); it is assigned
// before every use, and as a parameter it numbers below the codegen temps, which gives the ROM's registers.
void SndMgr_UpdateLoad(SndMgr *mgr, s32 seq) {
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
