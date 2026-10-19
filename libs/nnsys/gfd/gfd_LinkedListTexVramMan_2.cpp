#include "nnsys/gfd.h"

typedef struct NNS_GfdLnkTexVramManager {
    NNSiGfdLnkVramMan mgrNrm;            // 0x00
    NNSiGfdLnkVramMan mgr4x4;            // 0x04
    NNSiGfdLnkVramBlock *pBlockPoolList; // 0x08
    u32 szByte;                          // 0x0c
    u32 szByteFor4x4;                    // 0x10
    NNSiGfdLnkVramBlock *pWorkHead;      // 0x14
    u32 szByteManagementWork;            // 0x18
} NNS_GfdLnkTexVramManager;

typedef struct SlotData {
    u32 szFree;
    u32 szAllocatedNrm;
    u32 szAllocated4x4;
} SlotData;

typedef struct SlotDataArr {
    SlotData s[4];
} SlotDataArr;

extern "C" {
extern NNS_GfdLnkTexVramManager sLnkTexVramMgr;
// Labels the gap keeps for &sLnkTexVramMgr.mgr4x4 and &sLnkTexVramMgr.pBlockPoolList.
extern NNSiGfdLnkVramMan data_020917fc;
extern NNSiGfdLnkVramBlock *data_02091800;
// The function's initializer template in .rodata ({0x20000, 0, 0} for each slot).
extern const SlotDataArr data_020755e4;
}

// The target pools sLnkTexVramMgr twice; this file is C++ only for this second declaration.
namespace Dup { extern "C" NNS_GfdLnkTexVramManager sLnkTexVramMgr; }

extern "C" void NNS_GfdResetLnkTexVramState(void) {
    SlotDataArr sd = data_020755e4;
    {
        u32 i;
        u32 szNrm = sLnkTexVramMgr.szByte - (sLnkTexVramMgr.szByteFor4x4 + sLnkTexVramMgr.szByteFor4x4 / 2);
        u32 sz4x4 = sLnkTexVramMgr.szByteFor4x4;
        u32 szIdx = sz4x4 / 2;
        u32 sz;

        for (i = 0; i < 4; i++) {
            if (i == 0 || i == 2) {
                SlotData *p = &sd.s[i];
                if (p->szFree > 0 && sz4x4 > 0) {
                    sz = p->szFree;
                    if (sz > sz4x4) {
                        sz = sz4x4;
                    }
                    p->szAllocated4x4 += sz;
                    sz4x4 -= sz;
                    p->szFree -= sz;
                }
            }
        }

        sd.s[1].szFree -= szIdx;

        for (i = 0; i < 4; i++) {
            SlotData *p = &sd.s[i];
            if (p->szFree > 0 && szNrm > 0) {
                sz = p->szFree;
                if (sz > szNrm) {
                    sz = szNrm;
                }
                p->szAllocatedNrm += sz;
                szNrm -= sz;
                p->szFree -= sz;
            }
        }

        NNSi_GfdInitLnkVramMan(&Dup::sLnkTexVramMgr.mgrNrm);
        NNSi_GfdInitLnkVramMan(&data_020917fc);
        sLnkTexVramMgr.pBlockPoolList = NNSi_GfdInitLnkVramBlockPool(sLnkTexVramMgr.pWorkHead, sLnkTexVramMgr.szByteManagementWork / sizeof(NNSiGfdLnkVramBlock));

        sz = sd.s[0].szAllocated4x4;
        if (sz != 0) {
            NNSi_GfdAddNewFreeBlock(&data_020917fc, &data_02091800, 0, sz);
        }
        if (sd.s[0].szAllocatedNrm != 0) {
            NNSi_GfdAddNewFreeBlock(&Dup::sLnkTexVramMgr.mgrNrm, &data_02091800, sz, sd.s[0].szAllocatedNrm);
        }
        sz = sd.s[2].szAllocated4x4;
        if (sz != 0) {
            NNSi_GfdAddNewFreeBlock(&data_020917fc, &data_02091800, 0x40000, sz);
        }
        if (sd.s[2].szAllocatedNrm != 0) {
            NNSi_GfdAddNewFreeBlock(&Dup::sLnkTexVramMgr.mgrNrm, &data_02091800, 0x40000 + sz, sd.s[2].szAllocatedNrm);
        }
        if (sd.s[3].szAllocatedNrm != 0) {
            NNSi_GfdAddNewFreeBlock(&Dup::sLnkTexVramMgr.mgrNrm, &data_02091800, 0x60000, sd.s[3].szAllocatedNrm);
        }
        if (sd.s[1].szAllocatedNrm != 0) {
            NNSi_GfdAddNewFreeBlock(&Dup::sLnkTexVramMgr.mgrNrm, &data_02091800, 0x20000 + szIdx, sd.s[1].szAllocatedNrm);
        }

        NNSi_GfdMergeAllFreeBlocks(&Dup::sLnkTexVramMgr.mgrNrm, &data_02091800);
        NNSi_GfdMergeAllFreeBlocks(&data_020917fc, &data_02091800);
    }
}
