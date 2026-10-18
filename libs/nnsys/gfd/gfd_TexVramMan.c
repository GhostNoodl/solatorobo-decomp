#include "nnsys/gfd.h"

static NNSGfdTexKey AllocTexVram_(u32 szByte, BOOL is4x4comp, u32 opt);
static int FreeTexVram_(NNSGfdTexKey memKey);

NNSGfdFuncAllocTexVram NNS_GfdDefaultFuncAllocTexVram = AllocTexVram_;
NNSGfdFuncFreeTexVram NNS_GfdDefaultFuncFreeTexVram = FreeTexVram_;

static NNSGfdTexKey AllocTexVram_(u32 szByte, BOOL is4x4comp, u32 opt) {
#pragma unused(szByte, is4x4comp, opt)
    return NNS_GFD_ALLOC_ERROR_TEXKEY;
}

static int FreeTexVram_(NNSGfdTexKey memKey) {
#pragma unused(memKey)
    return -1;
}
