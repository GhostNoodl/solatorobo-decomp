#include "Main/Net/Wh.h"

extern "C" {

static inline BOOL WH_StateInEndScan(void) {
    WH_ChangeSysState(3);
    return WH_CheckResult(WM_EndScan((void (*)(void *))func_02046418));
}

BOOL func_020463c8(WhMgr *wh) {
    return WH_StateInEndScan();
}

static inline BOOL WH_StateInStartChild(WhMgr *wh) {
    int result;
    if (wh->sysState == 4 || wh->sysState == 5) {
        return TRUE;
    }
    WH_ChangeSysState(3);
    wh->unk_46 = 0;
    result = WM_StartConnectEx((void (*)(void *))func_020465c8, wh->bssDesc, wh->unk_60, TRUE, 0);
    if (result != 2) {
        WH_SetError(result);
        return FALSE;
    }
    return TRUE;
}

void func_02046418(WhCbArg *arg) {
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        return;
    }
    WH_ChangeSysState(1);
    if (data_02097e40->unk_46 == 0) {
        return;
    }
    if (!WH_StateInStartChild(data_02097e40)) {
        WH_ChangeSysState(8);
    }
}

BOOL func_020464e0(WhMgr *wh, int mode, const void *bssDesc) {
    wh->recvSize = wh->cfg.childRecvSize;
    wh->sendSize = wh->cfg.childSendSize;
    wh->connectMode = mode;
    WH_ChangeSysState(3);
    switch (mode) {
    case 2:
    case 4:
        MI_CpuCopy8(bssDesc, wh->bssDesc, sizeof(wh->bssDesc));
        DC_FlushRange(wh->bssDesc, sizeof(wh->bssDesc));
        DC_WaitWriteBufferEmpty();
        return WH_StateInStartChild(wh);
    }
    return FALSE;
}

static inline BOOL WH_StateInStartChildMP(void) {
    WhMgr *wh;
    WH_ChangeSysState(4);
    wh = data_02097e40;
    return WH_CheckResult(WM_StartMP((void (*)(void *))func_020467b4, wh->recvBuf, wh->recvSize, wh->sendBuf, wh->sendSize, wh->cfg.mpFreq));
}

void func_020465c8(WhCbArg *arg) {
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        if (arg->errcode == 0xc) {
            WH_ChangeSysState(8);
            return;
        }
        if (arg->errcode == 0xb) {
            WH_ChangeSysState(8);
            return;
        }
        if (arg->errcode == 1) {
            WH_ChangeSysState(7);
        } else {
            WH_ChangeSysState(8);
        }
        return;
    }
    switch (arg->unk_08) {
    case 8:
        return;
    case 7:
        if (!WH_StateInStartChildMP()) {
            WH_ChangeSysState(3);
            return;
        }
        data_02097e40->unk_30 = arg->unk_0a;
        return;
    case 6:
        return;
    case 9:
        WH_SetError(0x14);
        WH_ChangeSysState(8);
        return;
    case 0x1a:
        return;
    default:
        WH_ChangeSysState(8);
        break;
    }
}

void func_02046774(WhCbArg *arg) {
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        return;
    }
    WH_ChangeSysState(1);
}

void func_020467b4(WhCbArg *arg) {
    if (arg->errcode != 0) {
        if (arg->errcode == 0xf || arg->errcode == 9 || arg->errcode == 0xd) {
            return;
        }
        WH_SetError(arg->errcode);
        WH_ChangeSysState(8);
        return;
    }
    switch (arg->state) {
    case 10: {
        WhMgr *wh = data_02097e40;
        if (wh->connectMode == 4) {
            int result = WM_StartDataSharing(wh->dsInfo, wh->cfg.dsPort, (u16)((1 << (wh->cfg.maxChildren + 1)) - 1), wh->cfg.dsDataSize, wh->cfg.doubleMode);
            if (result != 0) {
                WH_SetError(result);
                func_02045094(data_02097e40);
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

static inline BOOL WH_StateInEndChild(void) {
    int result;
    WH_ChangeSysState(3);
    result = WM_Disconnect((void (*)(void *))func_02046774, 0);
    if (result != 2) {
        WH_SetError(result);
        WH_Reset(data_02097e40, NULL);
        return FALSE;
    }
    return TRUE;
}

void func_020468d0(WhCbArg *arg) {
    if (arg->errcode != 0) {
        func_02045094(data_02097e40);
        return;
    }
    if (!WH_StateInEndChild()) {
        WH_ChangeSysState(8);
    }
}

BOOL func_020469d4(WhMgr *wh, const void *data) {
    int result = WM_StepDataSharing(wh->dsInfo, data, wh->unk_18e0);
    if (result == 7) {
        return TRUE;
    }
    if (result == 5) {
        WH_SetError(result);
        return FALSE;
    }
    if (result != 0) {
        WH_SetError(result);
        return FALSE;
    }
    return TRUE;
}

void *func_02046a50(WhMgr *wh, u16 aid) {
    return WM_GetSharedDataAddress(wh->dsInfo, wh->unk_18e0, aid);
}

void func_02046a6c(WhMgr *wh, u32 ggid) {
    wh->parentParam.ggid = ggid;
}

void func_02046a78(WhMgr *wh, const void *src, u32 len) {
    if (len >= 0x18) {
        len = 0x18;
    }
    MI_CpuCopy8(src, wh->unk_60, len);
    MI_CpuFill8(wh->unk_60 + len, 0, 0x18 - len);
}

u16 func_02046ab4(WhMgr *wh) {
    return wh->unk_30;
}

int func_02046abc(WhMgr *wh) {
    return wh->errCode;
}

BOOL func_02046ac4(void) {
    WhMgr *wh = data_02097e40;
    if (wh != NULL ? TRUE : FALSE) {
        if (WH_IsStopped(wh)) {
            WH_Destroy(wh);
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

}
