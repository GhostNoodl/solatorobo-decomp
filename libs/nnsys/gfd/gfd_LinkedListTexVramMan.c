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

// Static in NitroSystem, but it stays in the gap since other code reaches its fields through labels of their own.
extern NNS_GfdLnkTexVramManager sLnkTexVramMgr;

u32 NNS_GfdGetLnkTexVramManagerWorkSize(u32 numMemBlk) {
    return numMemBlk * sizeof(NNSiGfdLnkVramBlock);
}

void NNS_GfdInitLnkTexVramManager(u32 szByte, u32 szByteFor4x4, void *pManagementWork, u32 szByteManagementWork, BOOL useAsDefault) {
    sLnkTexVramMgr.szByte = szByte;
    sLnkTexVramMgr.szByteFor4x4 = szByteFor4x4;
    sLnkTexVramMgr.pWorkHead = pManagementWork;
    sLnkTexVramMgr.szByteManagementWork = szByteManagementWork;

    NNS_GfdResetLnkTexVramState();

    if (useAsDefault) {
        NNS_GfdDefaultFuncAllocTexVram = NNS_GfdAllocLnkTexVram;
        NNS_GfdDefaultFuncFreeTexVram = NNS_GfdFreeLnkTexVram;
    }
}

NNSGfdTexKey NNS_GfdAllocLnkTexVram(u32 szByte, BOOL is4x4comp, u32 opt) {
#pragma unused(opt)
    u32 addr;
    BOOL result;

    szByte = NNSi_GfdGetTexKeyRoundupSize(szByte);
    if (szByte >= NNS_GFD_TEXSIZE_MAX) {
        return NNS_GFD_ALLOC_ERROR_TEXKEY;
    }

    if (is4x4comp) {
        result = NNSi_GfdAllocLnkVram(&sLnkTexVramMgr.mgr4x4, &sLnkTexVramMgr.pBlockPoolList, &addr, szByte);
    } else {
        result = NNSi_GfdAllocLnkVram(&sLnkTexVramMgr.mgrNrm, &sLnkTexVramMgr.pBlockPoolList, &addr, szByte);
    }

    if (result) {
        return NNS_GfdMakeTexKey(addr, szByte, is4x4comp);
    } else {
        return NNS_GFD_ALLOC_ERROR_TEXKEY;
    }
}

int NNS_GfdFreeLnkTexVram(NNSGfdTexKey memKey) {
    BOOL result;
    const u32 addr = NNS_GfdGetTexKeyAddr(memKey);
    const u32 szByte = NNS_GfdGetTexKeySize(memKey);
    const BOOL b4x4 = NNS_GfdGetTexKey4x4Flag(memKey);

    if (szByte != 0) {
        if (b4x4) {
            result = NNSi_GfdFreeLnkVram(&sLnkTexVramMgr.mgr4x4, &sLnkTexVramMgr.pBlockPoolList, addr, szByte);
        } else {
            result = NNSi_GfdFreeLnkVram(&sLnkTexVramMgr.mgrNrm, &sLnkTexVramMgr.pBlockPoolList, addr, szByte);
        }
        if (result) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 2;
    }
}
