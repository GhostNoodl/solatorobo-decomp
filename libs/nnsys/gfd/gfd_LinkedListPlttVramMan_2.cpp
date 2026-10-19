#include "nnsys/gfd.h"

typedef struct NNS_GfdLnkPlttVramManager {
    NNSiGfdLnkVramMan mgr;               // 0x00
    NNSiGfdLnkVramBlock *pBlockPoolList; // 0x04
    u32 szByte;                          // 0x08
    NNSiGfdLnkVramBlock *pWorkHead;      // 0x0c
    u32 szByteManagementWork;            // 0x10
} NNS_GfdLnkPlttVramManager;

extern "C" {
extern NNS_GfdLnkPlttVramManager sLnkPlttVramMgr;
// &sLnkPlttVramMgr.pBlockPoolList has a label of its own in the gap.
extern NNSiGfdLnkVramBlock *data_02091818;
}

// The target pools sLnkPlttVramMgr twice; this file is C++ only for this second declaration.
namespace Dup { extern "C" NNS_GfdLnkPlttVramManager sLnkPlttVramMgr; }

extern "C" void NNS_GfdResetLnkPlttVramState(void) {
    sLnkPlttVramMgr.pBlockPoolList = NNSi_GfdInitLnkVramBlockPool(sLnkPlttVramMgr.pWorkHead, sLnkPlttVramMgr.szByteManagementWork / sizeof(NNSiGfdLnkVramBlock));
    NNSi_GfdInitLnkVramMan(&Dup::sLnkPlttVramMgr.mgr);
    NNSi_GfdAddNewFreeBlock(&Dup::sLnkPlttVramMgr.mgr, &data_02091818, 0, sLnkPlttVramMgr.szByte);
    NNSi_GfdMergeAllFreeBlocks(&Dup::sLnkPlttVramMgr.mgr, &data_02091818);
}
