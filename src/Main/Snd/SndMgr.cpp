#include "Main/Snd/SndMgr.h"

extern "C" {

SndMgr *func_020492e0(SndMgr *mgr) {
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
    return mgr;
}

extern BOOL OS_IsRunOnTwl(void);
extern void func_0221d6d8(void);  /* TWL only */
extern void NNS_SndInit(void);
extern void NNS_SndArcInit(void *arc, const char *filePath, NNSSndHeap *heap, BOOL symbolLoadFlag);

extern s32 NNS_SndArcGetSeqCount(void);
extern s32 NNS_SndArcGetSeqArcCount(void);
extern s32 NNS_SndArcGetBankCount(void);
extern s32 NNS_SndArcGetWaveArcCount(void);
extern s32 NNS_SndArcGetGroupCount(void);
extern s32 NNS_SndArcGetStrmCount(void);
extern void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int seqCount);
void func_020495ac(SndMgr *mgr, s32 type, s32 id);
extern u8 data_020bbef0[];
extern u8 data_02097ef0[];
extern u8 data_02097e50[];
extern char data_0208b6cc[];

void func_02049344(SndMgr *mgr) {
    s32 i;
    NNSSndHeap *heap;

    if (OS_IsRunOnTwl() == TRUE) {
        func_0221d6d8();
    }
    mgr->unk_a0 = 0;
    mgr->unk_a4 = 0;
    NNS_SndInit();
    heap = NNS_SndHeapCreate(data_020bbef0, 0x8e000);
    if (heap != NULL) {
        mgr->heaps[0] = heap;
    }
    heap = NNS_SndHeapCreate(data_02097ef0, 0x24000);
    if (heap != NULL) {
        mgr->heaps[1] = heap;
    }
    NNS_SndArcInit(data_02097e50, data_0208b6cc, mgr->heaps[0], FALSE);
    NNS_SndArcPlayerSetup(mgr->heaps[0]);
    NNS_SndHandleInit(&mgr->bgm);
    NNS_SndHandleInit(&mgr->se);
    for (i = 0; i < 5; i++) {
        NNS_SndHandleInit(&mgr->seqArc[i]);
    }
    NNS_SndHandleInit(&mgr->voice);
    NNS_SndArcStrmInit(0xf, mgr->heaps[1]);
    func_02031990((StrmHandle *)&mgr->strm);
    mgr->heapLevels[1] = NNS_SndHeapSaveState(mgr->heaps[1]);
    mgr->unk_00 = 0x80;
    mgr->unk_04 = 0x100;
    mgr->unk_08 = 0x100;
    mgr->curBgm = -1;
    mgr->unk_48 = -1;
    mgr->loadType = 0;
    mgr->loadId = -1;
    mgr->loadArg = -1;
    mgr->unk_58 = 0;
    mgr->playAfterLoad = 0;
    mgr->unk_5b = 0;
    mgr->noAutoPlay = 0;
    mgr->loadedSeq = -1;
    for (i = 0; i < 3; i++) {
        mgr->loadedSeqEx[i] = -1;
    }
    for (i = 0; i < 5; i++) {
        mgr->unk_70[i] = -1;
    }
    mgr->unk_b8[0] = NNS_SndArcGetSeqCount();
    mgr->unk_b8[1] = NNS_SndArcGetSeqArcCount();
    mgr->unk_b8[2] = NNS_SndArcGetBankCount();
    mgr->unk_b8[3] = NNS_SndArcGetWaveArcCount();
    mgr->unk_b8[4] = NNS_SndArcGetGroupCount();
    mgr->unk_b8[5] = NNS_SndArcGetStrmCount();
    NNS_SndPlayerSetPlayableSeqCount(0, 8);
    NNS_SndPlayerSetPlayerPriority(&mgr->bgm, 0x7f);
    for (i = 0; i < 5; i++) {
        NNS_SndPlayerSetPlayerPriority(&mgr->seqArc[i], 0x6e);
    }
    NNS_SndPlayerSetPlayerPriority(&mgr->voice, 0x40);
    NNS_SndPlayerSetPlayerPriority(&mgr->se, 0x40);
    func_020495ac(data_02097e48.mgr, 4, 0);
    func_020495ac(data_02097e48.mgr, 4, 1);
    func_020495ac(data_02097e48.mgr, 4, 3);
}

}
