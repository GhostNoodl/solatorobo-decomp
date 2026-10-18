#include "Main/Net/Wh.h"

extern "C" {

static inline BOOL WH_StateInStartParent(WhMgr *wh) {
    int result;
    if (wh->sysState == 4 || wh->sysState == 5) {
        return TRUE;
    }
    result = func_020204d8((void (*)(void *))func_02045b68);
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
    result = func_020209d8(wh->portCb, wh->recvBuf, wh->recvSize, wh->sendBuf, wh->sendSize, wh->cfg.mpFreq);
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
            int result = func_02020768(NULL, arg->aid);
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
            int result = func_02020bf0(wh->dsInfo, wh->cfg.dsPort, (u16)((1 << (wh->cfg.maxChildren + 1)) - 1), wh->cfg.dsDataSize, wh->cfg.doubleMode);
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

BOOL func_02045ea4(WhMgr *wh) {
    if (wh->sysState != 4 && wh->sysState != 5) {
        return TRUE;
    }
    return WH_CheckResult(func_02021880(NULL));
}

void func_02045ef8(WhCbArg *arg) {
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        WH_Reset(data_02097e40, NULL);
        return;
    }
    if (!WH_CheckResult(func_020204e8((void (*)(void *))func_02045d58))) {
        WH_Reset(data_02097e40, NULL);
    }
}

#ifdef NONMATCHING
// Register allocation differs.
BOOL func_02046070(WhMgr *wh, const u16 *bssid, u16 channel) {
    WH_ChangeSysState(2);
    wh->scanChannel = channel;
    wh->scanParam.channel = 0;
    wh->scanParam.bssid[2] = bssid[2];
    wh->scanParam.bssid[1] = bssid[1];
    wh->scanParam.bssid[0] = bssid[0];
    if (!func_020460d0(wh)) {
        WH_ChangeSysState(8);
        return FALSE;
    }
    return TRUE;
}

// One branch condition is inverted.
BOOL func_020460d0(WhMgr *wh) {
    u32 allowed = func_0201ffb0();
    if (allowed == 0x8000) {
        WH_SetError(3);
        return TRUE;
    }
    if (allowed == 0) {
        WH_SetError(0x16);
        return TRUE;
    }
    if (wh->scanChannel == 0) {
        while (TRUE) {
            wh->scanParam.channel++;
            if (wh->scanParam.channel > 16) {
                wh->scanParam.channel = 1;
            }
            if (allowed & (1 << (wh->scanParam.channel - 1))) {
                break;
            }
        }
    } else {
        wh->scanParam.channel = wh->scanChannel;
    }
    wh->scanParam.scanBuf = wh->bssDesc;
    wh->scanParam.maxChannelTime = func_02020114();
    return WH_CheckResult(func_0202052c((void (*)(void *))func_020461e4, &wh->scanParam));
}

static inline BOOL WH_StateInEndScan(void) {
    WH_ChangeSysState(3);
    return WH_CheckResult(func_02020638((void (*)(void *))func_02046418));
}

static inline BOOL WH_IsValidGameInfo(WhScanCbArg *arg) {
    if (arg->gameInfoLength >= 0x10 && arg->gameInfoLength <= 0x80 && arg->gameInfoLength == arg->userGameInfoLength + 0x10 && arg->magicNumber == 1) {
        return TRUE;
    }
    return FALSE;
}

// Register allocation differs.
void func_020461e4(WhCbArg *cbArg) {
    WhScanCbArg *arg = (WhScanCbArg *)cbArg;
    WhMgr *wh;
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        WH_ChangeSysState(8);
        return;
    }
    wh = data_02097e40;
    if (wh->sysState != 2) {
        wh->unk_46 = 0;
        if (!WH_StateInEndScan()) {
            WH_ChangeSysState(8);
        }
        return;
    }
    switch (arg->state) {
    case 3:
    case 4:
        break;
    case 5: {
        WhParentParam *pp = &wh->parentParam;
        DC_InvalidateRange(wh->bssDesc, sizeof(wh->bssDesc));
        if (data_02097e40->unk_84 != 0 && !((BOOL (*)(void *))data_02097e40->unk_84)(wh->bssDesc)) {
            break;
        }
        if (!WH_IsValidGameInfo(arg)) {
            break;
        }
        if (arg->ggid == pp->ggid && (arg->attribute & 3) == 1) {
            BOOL ok = TRUE;
            if (data_02097e40->unk_80 != 0) {
                ok = ((BOOL (*)(void *))data_02097e40->unk_80)(wh->bssDesc);
            }
            if (ok && data_02097e40->unk_46 != 0) {
                if (!WH_StateInEndScan()) {
                    WH_ChangeSysState(8);
                }
                return;
            }
        }
        break;
    }
    }
    if (!func_020460d0(data_02097e40)) {
        WH_ChangeSysState(8);
    }
}
#endif

}
