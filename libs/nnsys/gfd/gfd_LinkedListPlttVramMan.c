#include "nnsys/gfd.h"

typedef struct NNS_GfdLnkPlttVramManager {
    NNSiGfdLnkVramMan mgr;               // 0x00
    NNSiGfdLnkVramBlock *pBlockPoolList; // 0x04
    u32 szByte;                          // 0x08
    NNSiGfdLnkVramBlock *pWorkHead;      // 0x0c
    u32 szByteManagementWork;            // 0x10
} NNS_GfdLnkPlttVramManager;

// Static in NitroSystem, but it stays in the gap since other code reaches its fields through labels of their own.
extern NNS_GfdLnkPlttVramManager sLnkPlttVramMgr;

u32 NNS_GfdGetLnkPlttVramManagerWorkSize(u32 numMemBlk) {
    return numMemBlk * sizeof(NNSiGfdLnkVramBlock);
}

void NNS_GfdInitLnkPlttVramManager(u32 szByte, void *pManagementWork, u32 szByteManagementWork, BOOL useAsDefault) {
    sLnkPlttVramMgr.szByte = szByte;
    sLnkPlttVramMgr.pWorkHead = pManagementWork;
    sLnkPlttVramMgr.szByteManagementWork = szByteManagementWork;

    NNS_GfdResetLnkPlttVramState();

    if (useAsDefault) {
        NNS_GfdDefaultFuncAllocPlttVram = NNS_GfdAllocLnkPlttVram;
        NNS_GfdDefaultFuncFreePlttVram = NNS_GfdFreeLnkPlttVram;
    }
}

NNSGfdPlttKey NNS_GfdAllocLnkPlttVram(u32 szByte, BOOL b4Pltt, u32 opt) {
#pragma unused(opt)
    u32 addr;
    BOOL result;

    szByte = NNSi_GfdGetPlttKeyRoundupSize(szByte);
    if (szByte >= NNS_GFD_PLTTSIZE_MAX) {
        return NNS_GFD_ALLOC_ERROR_PLTTKEY;
    }

    if (b4Pltt) {
        result = NNSi_GfdAllocLnkVramAligned(&sLnkPlttVramMgr.mgr, &sLnkPlttVramMgr.pBlockPoolList, &addr, szByte, 0x08);
        if (addr + szByte > NNS_GFD_4PLTT_MAX_ADDR) {
            if (!NNSi_GfdFreeLnkVram(&sLnkPlttVramMgr.mgr, &sLnkPlttVramMgr.pBlockPoolList, addr, szByte)) {
            }
            return NNS_GFD_ALLOC_ERROR_PLTTKEY;
        }
    } else {
        result = NNSi_GfdAllocLnkVramAligned(&sLnkPlttVramMgr.mgr, &sLnkPlttVramMgr.pBlockPoolList, &addr, szByte, 0x10);
    }

    if (result) {
        return NNS_GfdMakePlttKey(addr, szByte);
    } else {
        return NNS_GFD_ALLOC_ERROR_PLTTKEY;
    }
}

int NNS_GfdFreeLnkPlttVram(NNSGfdPlttKey plttKey) {
    const u32 addr = NNS_GfdGetPlttKeyAddr(plttKey);
    const u32 szByte = NNS_GfdGetPlttKeySize(plttKey);
    const BOOL result = NNSi_GfdFreeLnkVram(&sLnkPlttVramMgr.mgr, &sLnkPlttVramMgr.pBlockPoolList, addr, szByte);

    if (result) {
        return 0;
    } else {
        return 1;
    }
}
