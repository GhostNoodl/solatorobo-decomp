#include "Main/Net/Wh.h"

// Built at O2 like the rest of the WH helper code: at O4 the scan loop in
// func_020460d0 gets its exit branch inverted.
#pragma optimization_level 2

extern "C" {

BOOL func_02046070(WhMgr *wh, const u16 *bssid, u16 channel) {
    *WH_SysState(data_02097e40) = 2;
    wh->scanChannel = channel;
    wh->scanParam.channel = 0;
    wh->scanParam.bssid[2] = bssid[2];
    wh->scanParam.bssid[1] = bssid[1];
    wh->scanParam.bssid[0] = bssid[0];
    if (!func_020460d0(wh)) {
        *WH_SysState(data_02097e40) = 8;
        return FALSE;
    }
    return TRUE;
}

BOOL func_020460d0(WhMgr *wh) {
    u32 allowed = WM_GetAllowedChannel();
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
    wh->scanParam.maxChannelTime = WM_GetDispersionScanPeriod();
    return WH_CheckResult(WM_StartScan((void (*)(void *))func_020461e4, &wh->scanParam));
}

static inline BOOL WH_StateInEndScan(void) {
    WH_ChangeSysState(3);
    return WH_CheckResult(WM_EndScan((void (*)(void *))func_02046418));
}

static inline BOOL WH_IsValidGameInfo(WhScanCbArg *arg) {
    if (arg->gameInfoLength >= 0x10 && arg->gameInfoLength <= 0x80 && arg->gameInfoLength == arg->userGameInfoLength + 0x10 && arg->magicNumber == 1) {
        return TRUE;
    }
    return FALSE;
}

void func_020461e4(WhCbArg *cbArg) {
    WhScanCbArg *arg = (WhScanCbArg *)cbArg;
    WhMgr *wh;
    u8 *bssDesc;
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
        bssDesc = wh->bssDesc;
        DC_InvalidateRange(bssDesc, sizeof(wh->bssDesc));
        if (data_02097e40->unk_84 != 0 && !((BOOL (*)(void *))data_02097e40->unk_84)(bssDesc)) {
            break;
        }
        if (!WH_IsValidGameInfo(arg)) {
            break;
        }
        if (arg->ggid == pp->ggid && (arg->attribute & 3) == 1) {
            BOOL ok = TRUE;
            if (data_02097e40->unk_80 != 0) {
                ok = ((BOOL (*)(void *))data_02097e40->unk_80)(bssDesc);
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

}
