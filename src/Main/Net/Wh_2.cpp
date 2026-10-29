#include "Main/Net/Wh.h"

// Built at O2, like WhScan.cpp: func_020459cc only gets its register order at O2 (round raA), and every
// other function here matches at O2 and at O4.
#pragma optimization_level 2

extern "C" {

BOOL func_020459cc(WhMgr *wh, int mode, u16 tgid, u16 channel) {
    wh->recvSize = wh->cfg.parentRecvSize;
    wh->sendSize = wh->cfg.parentSendSize;
    wh->connectMode = mode;
    *WH_SysState(data_02097e40) = 3;
    wh->parentParam.tgid = tgid;
    wh->parentParam.channel = channel;
    wh->parentParam.beaconPeriod = WM_GetDispersionBeaconPeriod();
    wh->parentParam.parentMaxSize = wh->cfg.parentSize;
    wh->parentParam.childMaxSize = wh->cfg.childSize;
    wh->parentParam.maxEntry = wh->cfg.maxChildren;
    wh->parentParam.KS_Flag = 0;
    wh->parentParam.CS_Flag = 0;
    wh->parentParam.multiBootFlag = 0;
    wh->parentParam.entryFlag = 1;
    switch (mode) {
    case 1:
    case 3: {
        int result;
        *WH_SysState(data_02097e40) = 3;
        result = WM_SetParentParameter((void (*)(void *))func_02045ab4, &wh->parentParam);
        if (result != 2) {
            WH_SetError(result);
            *WH_SysState(data_02097e40) = 8;
            return FALSE;
        }
        return TRUE;
    }
    }
    return FALSE;
}

static inline BOOL WH_StateInStartParent(WhMgr *wh) {
    int result;
    if (wh->sysState == 4 || wh->sysState == 5) {
        return TRUE;
    }
    result = WM_StartParent((void (*)(void *))func_02045b68);
    if (result != 2) {
        WH_SetError(result);
        return FALSE;
    }
    wh->unk_30 = 0;
    wh->childBitmap = 1;
    return TRUE;
}

void func_02045ab4(WhCbArg *arg) {
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        WH_ChangeSysState(8);
        return;
    }
    if (!WH_StateInStartParent(data_02097e40)) {
        WH_ChangeSysState(8);
    }
}

static inline BOOL WH_StateInStartParentMP(void) {
    WhMgr *wh = data_02097e40;
    int result;
    if (wh->sysState == 4 || wh->sysState == 5) {
        return TRUE;
    }
    wh->sysState = 4;
    result = WM_StartMP(wh->portCb, wh->recvBuf, wh->recvSize, wh->sendBuf, wh->sendSize, wh->cfg.mpFreq);
    if (result != 2) {
        WH_SetError(result);
        return FALSE;
    }
    return TRUE;
}

void func_02045b68(WhCbArg *arg) {
    u16 bit = 1 << arg->aid;
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        WH_ChangeSysState(8);
        return;
    }
    switch (arg->unk_08) {
    case 2:
        break;
    case 7:
        if (data_02097e40->judgeCb != NULL && !data_02097e40->judgeCb(arg)) {
            int result = WM_Disconnect(NULL, arg->aid);
            if (result != 2) {
                WH_SetError(result);
                WH_ChangeSysState(8);
            }
            return;
        }
        data_02097e40->childBitmap |= bit;
        break;
    case 9:
        data_02097e40->childBitmap &= ~bit;
        break;
    case 0x1a:
        data_02097e40->childBitmap &= ~bit;
        break;
    case 0:
        if (!WH_StateInStartParentMP()) {
            WH_ChangeSysState(8);
        }
        break;
    }
}

void func_02045d58(WhCbArg *arg) {
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        return;
    }
    WH_ChangeSysState(1);
}

void func_02045d98(void *p) {
    WhCbArg *arg = (WhCbArg *)p;
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        WH_ChangeSysState(8);
        return;
    }
    switch (arg->state) {
    case 10: {
        WhMgr *wh = data_02097e40;
        if (wh->connectMode == 3) {
            int result = WM_StartDataSharing(wh->dsInfo, wh->cfg.dsPort, (u16)((1 << (wh->cfg.maxChildren + 1)) - 1), wh->cfg.dsDataSize, wh->cfg.doubleMode);
            if (result != 0) {
                WH_SetError(result);
                WH_ChangeSysState(8);
                return;
            }
            WH_ChangeSysState(5);
        } else {
            wh->sysState = 4;
        }
        break;
    }
    case 11:
    case 12:
    case 13:
        break;
    }
}

BOOL func_02045ea4(WhMgr *wh, BOOL enabled) {
    if (wh->sysState != 4 && wh->sysState != 5) {
        return TRUE;
    }
    return WH_CheckResult(WM_SetEntry(NULL, enabled));
}

void func_02045ef8(WhCbArg *arg) {
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        WH_Reset(data_02097e40, NULL);
        return;
    }
    if (!WH_CheckResult(WM_EndParent((void (*)(void *))func_02045d58))) {
        WH_Reset(data_02097e40, NULL);
    }
}

}
