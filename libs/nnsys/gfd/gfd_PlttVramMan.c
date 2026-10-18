#include "nnsys/gfd.h"

static NNSGfdPlttKey AllocPlttVram_(u32 szByte, BOOL b4Pltt, u32 bAllocFromLo);
static int FreePlttVram_(NNSGfdPlttKey key);

NNSGfdFuncAllocPlttVram NNS_GfdDefaultFuncAllocPlttVram = AllocPlttVram_;
NNSGfdFuncFreePlttVram NNS_GfdDefaultFuncFreePlttVram = FreePlttVram_;

static NNSGfdPlttKey AllocPlttVram_(u32 szByte, BOOL b4Pltt, u32 bAllocFromLo) {
#pragma unused(szByte, b4Pltt, bAllocFromLo)
    return NNS_GFD_ALLOC_ERROR_PLTTKEY;
}

static int FreePlttVram_(NNSGfdPlttKey key) {
#pragma unused(key)
    return -1;
}
