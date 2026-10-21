// SndMgr.h declares func_02049690(SndMgr *) for its callers. The definition takes
// an extra parameter that it assigns before use (it only changes register
// allocation), so the header's prototype is renamed out of the way here.
#define func_02049690 func_02049690_hdr
#include "Main/Snd/SndMgr.h"
#undef func_02049690

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

void func_02049690(SndMgr *mgr, s32 seq) {
    s32 i;
    switch (mgr->loadType) {
        case 0:
            return;
        case 1:
            NNS_SndHeapLoadState(mgr->heaps[0], mgr->heapLevels[0]);
            if (NNS_SndArcLoadSeq(mgr->loadId, data_02097e48.mgr->heaps[0]) == TRUE) {
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

}
