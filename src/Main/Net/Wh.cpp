#include "Main/Net/Wh.h"

extern "C" {

WhMgr *data_02097e40;

void func_02044a0c(WhConfig *cfg) {
    WH_CalcBufferSizes(cfg);
}

void func_02044a60(WhCbArg *arg) {
    if (arg->errcode == 8) {
        data_02097e40->sysState = 8;
    }
}

void func_02044a80(void) {
    WhMgr *wh = data_02097e40;
    WH_ChangeSysState(3);
    if (WM_End((void (*)(void *))func_02044fc0) != 2) {
        WH_ChangeSysState(8);
    } else {
        wh->initialized = FALSE;
    }
}

void func_02044ac4(void) {
    WhMgr *wh;
    if (data_02097e40 != NULL) {
        return;
    }
    data_02097dd0->align = 0x20;
    wh = (WhMgr *)func_0203dd9c(sizeof(WhMgr));
    if (wh != NULL) {
        func_02044cb8(wh);
    }
    data_02097e40 = wh;
    data_02097dd0->align = 4;
}

BOOL func_02044b20(void) {
    return WH_Destroy(data_02097e40);
}

BOOL func_02044c80(void) {
    return WH_IsStopped(data_02097e40);
}

void func_02044cb8(WhMgr *wh) {
    wh->flags = 0;
    wh->cfg.unk_00 = 1;
    wh->cfg.unk_02 = 0x70;
    wh->cfg.maxChildren = 0xf;
    wh->cfg.dsDataSize = 0xc;
    wh->cfg.parentSize = 0xc4;
    wh->cfg.childSize = 0xc;
    wh->cfg.mpFreq = 1;
    wh->cfg.unk_0e = 0xe;
    wh->cfg.unk_10 = 2;
    wh->cfg.dsPort = 0xd;
    wh->cfg.doubleMode = 1;
    WH_CalcBufferSizes(&wh->cfg);
    wh->sysState = 0;
    wh->unk_30 = 0;
    wh->childBitmap = 1;
    wh->errCode = 0;
    wh->connectMode = 0;
    wh->unk_3c = 0;
    wh->channel = 0;
    wh->bestBusyRatio = 0;
    wh->channelBitmap = 0;
    wh->scanChannel = 0;
    wh->unk_46 = 0;
    wh->recvBufRaw = NULL;
    wh->recvBuf = NULL;
    wh->recvSize = 0;
    wh->sendBufRaw = NULL;
    wh->sendBuf = NULL;
    wh->sendSize = 0;
    wh->indicateCb = NULL;
    wh->resultCb = NULL;
    wh->unk_80 = 0;
    wh->unk_84 = 0;
    wh->unk_88 = 0;
    wh->judgeCb = NULL;
    wh->portCb = func_02045d98;
    MI_CpuFill8(wh->unk_60, 0, sizeof(wh->unk_60));
    MI_CpuFill8(wh->wmBuf, 0, sizeof(wh->wmBuf));
    MI_CpuFill8(wh->bssDesc, 0, sizeof(wh->bssDesc));
    MI_CpuFill8(&wh->scanParam, 0, sizeof(wh->scanParam));
    MI_CpuFill8(&wh->parentParam, 0, sizeof(wh->parentParam));
    MI_CpuFill8(wh->dsInfo, 0, sizeof(wh->dsInfo));
    MI_CpuFill8(wh->unk_18e0, 0, sizeof(wh->unk_18e0));
}

#define WH_MAX(a, b) ((a) > (b) ? (a) : (b))

static inline BOOL WH_StateInInitialize(WhMgr *wh) {
    int result;
    WH_ChangeSysState(3);
    result = WM_Initialize(wh->wmBuf, (void (*)(void *))func_02045004, wh->cfg.unk_00);
    if (result != 2) {
        WH_SetError(result);
        WH_ChangeSysState(9);
        return FALSE;
    }
    return TRUE;
}

BOOL func_02044e38(WhMgr *wh, void (*cb)(void *arg)) {
    u32 recvSize;
    u32 sendSize;
    if (wh->initialized) {
        return FALSE;
    }
    if (cb != NULL) {
        wh->indicateCb = cb;
    } else {
        wh->indicateCb = (void (*)(void *))func_02044a60;
    }
    if (wh->recvBufRaw != NULL) {
        func_0203df0c(wh->recvBufRaw);
        wh->recvBufRaw = NULL;
    }
    if (wh->sendBufRaw != NULL) {
        func_0203df0c(wh->sendBufRaw);
        wh->sendBufRaw = NULL;
    }
    recvSize = WH_MAX(wh->cfg.parentRecvSize, wh->cfg.childRecvSize);
    sendSize = WH_MAX(wh->cfg.parentSendSize, wh->cfg.childSendSize);
    wh->recvBufRaw = func_0203de84(recvSize + 0x20, 4);
    wh->recvBuf = (void *)(((u32)wh->recvBufRaw + 0x1f) & ~0x1f);
    wh->sendBufRaw = func_0203de84(sendSize + 0x20, 4);
    wh->sendBuf = (void *)(((u32)wh->sendBufRaw + 0x1f) & ~0x1f);
    if (!WH_StateInInitialize(wh)) {
        return FALSE;
    }
    wh->initialized = TRUE;
    return TRUE;
}

BOOL func_02044f70(WhMgr *wh) {
    WH_ChangeSysState(3);
    if (WM_End((void (*)(void *))func_02044fc0) != 2) {
        WH_ChangeSysState(8);
        return FALSE;
    }
    wh->initialized = FALSE;
    return TRUE;
}

void func_02044fc0(WhCbArg *arg) {
    if (arg->errcode != 0) {
        WH_ChangeSysState(9);
        return;
    }
    WH_ChangeSysState(0);
    data_02097e40->busy = FALSE;
}

void func_02045004(WhCbArg *arg) {
    int result;
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        WH_ChangeSysState(9);
        return;
    }
    result = WM_SetIndCallback(data_02097e40->indicateCb);
    if (result != 0) {
        WH_SetError(result);
        WH_ChangeSysState(9);
        return;
    }
    WH_ChangeSysState(1);
}

static inline BOOL WH_StateInEndChildMP(void) {
    WH_ChangeSysState(3);
    return WH_CheckResult(WM_EndMP((void (*)(void *))func_020468d0));
}

static inline BOOL WH_StateInEndParentMP(void) {
    WH_ChangeSysState(3);
    return WH_CheckResult(WM_EndMP((void (*)(void *))func_02045ef8));
}

static inline BOOL WH_EndScan(WhMgr *wh) {
    if (wh->sysState != 2) {
        return FALSE;
    }
    wh->unk_46 = 0;
    WH_ChangeSysState(3);
    return TRUE;
}

void func_02045094(WhMgr *wh) {
    if (wh->sysState == 1) {
        return;
    }
    if (wh->sysState == 2) {
        if (!WH_EndScan(wh)) {
            WH_Reset(wh, NULL);
        }
        return;
    }
    if (wh->sysState != 4 && wh->sysState != 5) {
        WH_ChangeSysState(3);
        WH_Reset(wh, NULL);
        return;
    }
    WH_ChangeSysState(3);
    switch (wh->connectMode) {
    case 4:
        if (WM_EndDataSharing(wh->dsInfo) != 0) {
            WH_Reset(wh, NULL);
            return;
        }
    case 2:
        if (!WH_StateInEndChildMP()) {
            WH_Reset(wh, NULL);
        }
        break;
    case 3:
        if (WM_EndDataSharing(wh->dsInfo) != 0) {
            WH_Reset(wh, NULL);
            return;
        }
    case 1:
        if (!WH_StateInEndParentMP()) {
            WH_Reset(wh, NULL);
        }
        break;
    }
}

void func_02045498(WhMgr *wh, void (*cb)(BOOL)) {
    WH_Reset(wh, cb);
}

void func_02045530(WhCbArg *arg) {
    if (arg->errcode != 0) {
        WH_ChangeSysState(8);
        WH_SetError(arg->errcode);
    } else {
        WH_ChangeSysState(1);
    }
    if (data_02097e40->resultCb != NULL) {
        data_02097e40->resultCb(arg->errcode == 0 ? TRUE : FALSE);
    }
}

BOOL func_020455ac(WhMgr *wh) {
    u8 macAddr[8];
    u16 result;
    OS_GetMacAddress(macAddr);
    wh->channel = 0;
    wh->bestBusyRatio = 0x65;
    WH_ChangeSysState(3);
    result = func_02045674(wh, 1);
    if (result == 0x18) {
        WH_SetError(0x18);
        WH_ChangeSysState(8);
        return FALSE;
    }
    if (result != 2) {
        WH_SetError(result);
        WH_ChangeSysState(8);
        return FALSE;
    }
    return TRUE;
}

u16 func_02045674(WhMgr *wh, u16 channel) {
    u32 allowed = WM_GetAllowedChannel();
    if (allowed == 0x8000) {
        WH_SetError(3);
        WH_ChangeSysState(8);
        return 3;
    }
    if (allowed == 0) {
        WH_SetError(0x16);
        WH_ChangeSysState(8);
        return 0x16;
    }
    while (!(allowed & (1 << (channel - 1)))) {
        channel++;
        if (channel > 16) {
            return 0x18;
        }
    }
    return WM_MeasureChannel((void (*)(void *))func_02045770, 3, 0x11, channel, 0x1e);
}

void func_02045770(WhCbArg *arg) {
    u16 channel;
    u16 busy;
    u16 best;
    u16 bitmap;
    WhMgr *wh;
    u16 result;
    if (arg->errcode != 0) {
        WH_SetError(arg->errcode);
        WH_ChangeSysState(8);
        return;
    }
    busy = arg->unk_0a;
    wh = data_02097e40;
    channel = arg->unk_08;
    best = wh->bestBusyRatio;
    bitmap = wh->channelBitmap;
    if (best > busy) {
        best = busy;
        bitmap = 1 << (channel - 1);
    } else if (best == busy) {
        bitmap |= 1 << (channel - 1);
    }
    wh->bestBusyRatio = best;
    data_02097e40->channelBitmap = bitmap;
    result = func_02045674(data_02097e40, channel + 1);
    if (result == 0x18) {
        WH_ChangeSysState(6);
        return;
    }
    if (result != 2) {
        WH_ChangeSysState(8);
    }
}

s16 func_0204587c(WhMgr *wh, u16 bitmap);

u16 func_0204584c(WhMgr *wh) {
    WH_ChangeSysState(1);
    wh->channel = func_0204587c(wh, wh->channelBitmap);
    return wh->channel;
}

s16 func_0204587c(WhMgr *wh, u16 bitmap) {
    s16 i;
    s16 channel = 0;
    u16 num = 0;
    u16 select;
    for (i = 0; i < 16; i++) {
        if (bitmap & (1 << i)) {
            channel = (s16)(i + 1);
            num++;
        }
    }
    if (num <= 1) {
        return channel;
    }
    select = (u16)((num * ((int)func_0204045c() & 0xff)) / 0x100);
    for (i = 0; i < 16; i++) {
        if (bitmap & 1) {
            if (select == 0) {
                return (s16)(i + 1);
            }
            select--;
        }
        bitmap >>= 1;
    }
    return 0;
}

void func_0204593c(void *arg) {
}

void func_02045940(WhMgr *wh, void *info, u16 length) {
    wh->parentParam.userGameInfo = info;
    wh->parentParam.userGameInfoLength = length;
}

void func_02045950(WhMgr *wh, void *info, int length) {
    wh->parentParam.userGameInfoLength = length;
    wh->parentParam.userGameInfo = info;
    u8 attr = 0;
    attr |= (u8)(wh->parentParam.entryFlag ? 1 : 0);
    attr |= (u8)(wh->parentParam.multiBootFlag ? 2 : 0);
    WM_SetGameInfo(func_0204593c, info, length, wh->parentParam.ggid, wh->parentParam.tgid, attr);
}

#ifdef NONMATCHING
// Register allocation differs.
BOOL func_020459cc(WhMgr *wh, int mode, u16 tgid, u16 channel) {
    wh->recvSize = wh->cfg.parentRecvSize;
    wh->sendSize = wh->cfg.parentSendSize;
    wh->connectMode = mode;
    WH_ChangeSysState(3);
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
        WH_ChangeSysState(3);
        result = WM_SetParentParameter((void (*)(void *))func_02045ab4, &wh->parentParam);
        if (result != 2) {
            WH_SetError(result);
            WH_ChangeSysState(8);
            return FALSE;
        }
        return TRUE;
    }
    }
    return FALSE;
}
#endif

}
