#include "wm_private.h"
#include "nitro/rtc.h"

#define WM_GET_ALLOWED_CHANNEL_BEFORE_INIT 0x8000

WMErrCode WM_SetIndCallback(WMCallbackFunc callback) {
    WMErrCode result;
    OSIntrMode e;

    e = OS_DisableInterrupts();

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        (void)OS_RestoreInterrupts(e);
        return result;
    }

    WMi_GetSystemWork()->indCallback = callback;
    (void)OS_RestoreInterrupts(e);

    return WM_ERRCODE_SUCCESS;
}

WMErrCode WM_SetPortCallback(u16 port, WMCallbackFunc callback, void *arg) {
    WMErrCode result;
    OSIntrMode e;
    WMPortRecvCallback cb_Port;

    if (callback != NULL) {
        MI_CpuClear8(&cb_Port, sizeof(WMPortRecvCallback));
        cb_Port.apiid = WM_APIID_PORT_RECV;
        cb_Port.errcode = WM_ERRCODE_SUCCESS;
        cb_Port.state = WM_STATECODE_PORT_INIT;
        cb_Port.port = port;
        cb_Port.recvBuf = NULL;
        cb_Port.data = NULL;
        cb_Port.length = 0;
        cb_Port.seqNo = 0xffff;
        cb_Port.arg = arg;
        cb_Port.aid = 0;
        OS_GetMacAddress(cb_Port.macAddress);
    }

    e = OS_DisableInterrupts();

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        (void)OS_RestoreInterrupts(e);
        return result;
    }

    {
        WMArm9Buf *p = WMi_GetSystemWork();

        p->portCallbackTable[port] = callback;
        p->portCallbackArgument[port] = arg;
    }

    if (callback != NULL) {
        cb_Port.connectedAidBitmap = WM_GetConnectedAIDs();
        cb_Port.myAid = WM_GetAID();
        (*callback)((void *)&cb_Port);
    }

    (void)OS_RestoreInterrupts(e);

    return WM_ERRCODE_SUCCESS;
}

int WM_GetMPSendBufferSize(void) {
    WMErrCode result;
    int maxSendSize;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(2, WM_STATE_PARENT, WM_STATE_CHILD);
    if (result != WM_ERRCODE_SUCCESS) {
        return 0;
    }

    DC_InvalidateRange(&(p->status->mp_flag), 4);
    if (p->status->mp_flag == TRUE) {
        return 0;
    }

    DC_InvalidateRange(&(p->status->mp_maxSendSize), 4);
    maxSendSize = p->status->mp_maxSendSize;

    return ((maxSendSize + 31) & ~0x1f);
}

int WM_GetMPReceiveBufferSize(void) {
    WMErrCode result;
    BOOL isParent;
    int maxReceiveSize;
    int maxEntry;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(2, WM_STATE_PARENT, WM_STATE_CHILD);
    if (result != WM_ERRCODE_SUCCESS) {
        return 0;
    }

    DC_InvalidateRange(&(p->status->mp_flag), 4);
    if (p->status->mp_flag == TRUE) {
        return 0;
    }

    DC_InvalidateRange(&(p->status->aid), 2);
    isParent = (p->status->aid == 0) ? TRUE : FALSE;
    DC_InvalidateRange(&(p->status->mp_maxRecvSize), 2);
    maxReceiveSize = p->status->mp_maxRecvSize;

    if (isParent == TRUE) {
        DC_InvalidateRange(&(p->status->pparam.maxEntry), 2);
        maxEntry = p->status->pparam.maxEntry;
        return (int)((sizeof(WMMpRecvHeader) - sizeof(WMMpRecvData) +
                      ((sizeof(WMMpRecvData) + maxReceiveSize - 2 + 2) * maxEntry) + 31) & ~0x1f) * 2;
    } else {
        return (int)((sizeof(WMMpRecvBuf) + maxReceiveSize - 4 + 31) & ~0x1f) * 2;
    }
}

u16 WM_GetAllowedChannel(void) {
    WMErrCode result;

    if (OS_IsRunOnTwl()) {
        if (!func_0201fd30()) {
            return 0;
        }
    }

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return WM_GET_ALLOWED_CHANNEL_BEFORE_INIT;
    }

    return *((u16 *)((u32)(OS_GetSystemWork()->nvramUserInfo) + 0x7a));
}

WMLinkLevel WM_GetLinkLevel(void) {
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return WM_LINK_LEVEL_0;
    }

    DC_InvalidateRange(&(p->status->state), 2);
    switch (p->status->state) {
    case WM_STATE_MP_PARENT:
        DC_InvalidateRange(&(p->status->child_bitmap), 2);
        if (p->status->child_bitmap == 0) {
            return WM_LINK_LEVEL_0;
        }
    case WM_STATE_MP_CHILD:
    case WM_STATE_DCF_CHILD:
        DC_InvalidateRange(&(p->status->linkLevel), 2);
        return (WMLinkLevel)(p->status->linkLevel);
    }

    return WM_LINK_LEVEL_0;
}

u16 WM_GetDispersionBeaconPeriod(void) {
    u8 mac[6];
    u16 ret;
    s32 i;

    OS_GetMacAddress(mac);
    for (i = 0, ret = 0; i < 6; i++) {
        ret += mac[i];
    }

    ret += OS_GetVBlankCount();
    ret *= 7;

    return (u16)(WM_DEFAULT_BEACON_PERIOD + (ret % 20));
}

u16 WM_GetDispersionScanPeriod(void) {
    u8 mac[6];
    u16 ret;
    s32 i;

    OS_GetMacAddress(mac);
    for (i = 0, ret = 0; i < 6; i++) {
        ret += mac[i];
    }

    ret += OS_GetVBlankCount();
    ret *= 13;

    return (u16)(WM_DEFAULT_SCAN_PERIOD + (ret % 10));
}

u16 WM_GetNextTgid(void) {
    enum { TGID_DEFAULT = (1 << 16) };
    static u32 tgid_bak = (u32)TGID_DEFAULT;

    if (tgid_bak == (u32)TGID_DEFAULT) {
        RTCTime rt[1];
        RTC_Init();
        if (RTC_GetTime(rt) == RTC_RESULT_SUCCESS) {
            tgid_bak = (u16)(rt->second + (rt->minute << 8));
        }
    }

    tgid_bak = (u16)(tgid_bak + 1);
    return (u16)tgid_bak;
}
