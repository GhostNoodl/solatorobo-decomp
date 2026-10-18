#include "wm_private.h"

static BOOL WmCheckParentParameter(const WMParentParam *param);

WMErrCode WM_Initialize(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo) {
    return WMi_InitializeEx(wmSysBuf, callback, dmaNo, 0);
}

WMErrCode WMi_InitializeEx(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, u32 miscFlags) {
    WMErrCode result;

    result = WM_Init(wmSysBuf, dmaNo);
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_INITIALIZE, callback);
    WMi_RegisterSleepCallback();

    {
        WMArm9Buf *p = WMi_GetSystemWork();

        result = WMi_SendCommand(WM_APIID_INITIALIZE, 4, (u32)(p->WM7), (u32)(p->status), (u32)(p->fifo7to9), miscFlags);
        WM_CHECK_RESULT(result);
    }

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_Reset(WMCallbackFunc callback) {
    WMErrCode result;

    result = WMi_CheckIdle();
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_RESET, callback);

    result = WMi_SendCommand(WM_APIID_RESET, 0);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_End(WMCallbackFunc callback) {
    WMErrCode result;

    result = WMi_CheckState(WM_STATE_IDLE);
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_END, callback);

    result = WMi_SendCommand(WM_APIID_END, 0);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_SetParentParameter(WMCallbackFunc callback, const WMParentParam *pparaBuf) {
    WMErrCode result;

    result = WMi_CheckState(WM_STATE_IDLE);
    WM_CHECK_RESULT(result);

    WM_CHECK_TWL_WIRELESS();

    if (pparaBuf == NULL) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (pparaBuf->userGameInfoLength > 0) {
        if (pparaBuf->userGameInfo == NULL) {
            return WM_ERRCODE_INVALID_PARAM;
        }
    }

    if ((pparaBuf->parentMaxSize + (pparaBuf->KS_Flag ? WM_SIZE_KS_PARENT_DATA + WM_SIZE_MP_PARENT_PADDING : 0) >
         WM_SIZE_MP_DATA_MAX) ||
        (pparaBuf->childMaxSize + (pparaBuf->KS_Flag ? WM_SIZE_KS_CHILD_DATA + WM_SIZE_MP_CHILD_PADDING : 0) >
         WM_SIZE_MP_DATA_MAX)) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    (void)WmCheckParentParameter(pparaBuf);

    WMi_SetCallbackTable(WM_APIID_SET_P_PARAM, callback);
    DC_StoreRange((void *)pparaBuf, WM_PARENT_PARAM_SIZE);

    if (pparaBuf->userGameInfoLength > 0) {
        DC_StoreRange(pparaBuf->userGameInfo, pparaBuf->userGameInfoLength);
    }

    result = WMi_SendCommand(WM_APIID_SET_P_PARAM, 1, (u32)pparaBuf);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}

static BOOL WmCheckParentParameter(const WMParentParam *param) {
    if (param->userGameInfoLength > WM_SIZE_USER_GAMEINFO) {
        return FALSE;
    }

    if ((param->beaconPeriod < 10) || (param->beaconPeriod > 1000)) {
        return FALSE;
    }

    if ((param->channel < 1) || (param->channel > 14)) {
        return FALSE;
    }

    return TRUE;
}

WMErrCode WMi_StartParentEx(WMCallbackFunc callback, BOOL powerSave) {
    WMErrCode result;

    result = WMi_CheckState(WM_STATE_IDLE);
    WM_CHECK_RESULT(result);

    WM_CHECK_TWL_WIRELESS();

    {
        WMArm9Buf *w9b = WMi_GetSystemWork();
        w9b->myAid = 0;
        w9b->connectedAidBitmap = 0;
    }

    WMi_SetCallbackTable(WM_APIID_START_PARENT, callback);

    result = WMi_SendCommand(WM_APIID_START_PARENT, 1, (u32)powerSave);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_StartParent(WMCallbackFunc callback) {
    return WMi_StartParentEx(callback, TRUE);
}

WMErrCode WM_EndParent(WMCallbackFunc callback) {
    WMErrCode result;

    result = WMi_CheckState(WM_STATE_PARENT);
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_END_PARENT, callback);

    result = WMi_SendCommand(WM_APIID_END_PARENT, 0);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_StartScan(WMCallbackFunc callback, const WMScanParam *param) {
    WMErrCode result;

    result = WMi_CheckStateEx(3, WM_STATE_IDLE, WM_STATE_CLASS1, WM_STATE_SCAN);
    WM_CHECK_RESULT(result);

    WM_CHECK_TWL_WIRELESS();

    if (param == NULL) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (param->scanBuf == NULL) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    if ((param->channel < 1) || (param->channel > 14)) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    WMi_SetCallbackTable(WM_APIID_START_SCAN, callback);

    {
        WMStartScanReq Req;

        Req.apiid = WM_APIID_START_SCAN;
        Req.channel = param->channel;
        Req.scanBuf = param->scanBuf;
        Req.maxChannelTime = param->maxChannelTime;
        Req.bssid[0] = param->bssid[0];
        Req.bssid[1] = param->bssid[1];
        Req.bssid[2] = param->bssid[2];
        Req.bssid[3] = param->bssid[3];
        Req.bssid[4] = param->bssid[4];
        Req.bssid[5] = param->bssid[5];
        result = WMi_SendCommandDirect(&Req, sizeof(Req));
        WM_CHECK_RESULT(result);
    }

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_EndScan(WMCallbackFunc callback) {
    WMErrCode result;

    result = WMi_CheckState(WM_STATE_SCAN);
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_END_SCAN, callback);

    result = WMi_SendCommand(WM_APIID_END_SCAN, 0);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_StartConnectEx(WMCallbackFunc callback, const WMBssDesc *pInfo, const u8 *ssid, BOOL powerSave, const u16 authMode) {
    WMErrCode result;

    result = WMi_CheckState(WM_STATE_IDLE);
    WM_CHECK_RESULT(result);

    WM_CHECK_TWL_WIRELESS();

    if (pInfo == NULL) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_StoreRange((void *)pInfo, (u32)(pInfo->length * 2));

    {
        WMArm9Buf *w9b = WMi_GetSystemWork();
        w9b->myAid = 0;
        w9b->connectedAidBitmap = 0;
    }

    WMi_SetCallbackTable(WM_APIID_START_CONNECT, callback);

    {
        WMStartConnectReq Req;

        Req.apiid = WM_APIID_START_CONNECT;
        Req.pInfo = (WMBssDesc *)pInfo;

        if (ssid != NULL) {
            MI_CpuCopy8(ssid, Req.ssid, WM_SIZE_CHILD_SSID);
        } else {
            MI_CpuClear8(Req.ssid, WM_SIZE_CHILD_SSID);
        }

        Req.powerSave = powerSave;
        Req.authMode = authMode;

        result = WMi_SendCommandDirect(&Req, sizeof(Req));
        WM_CHECK_RESULT(result);
    }

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_Disconnect(WMCallbackFunc callback, u16 aid) {
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(5, WM_STATE_PARENT, WM_STATE_MP_PARENT, WM_STATE_CHILD, WM_STATE_MP_CHILD, WM_STATE_DCF_CHILD);
    WM_CHECK_RESULT(result);

    if ((p->status->state == WM_STATE_PARENT) || (p->status->state == WM_STATE_MP_PARENT)) {
        if ((aid < 1) || (aid > WM_NUM_MAX_CHILD)) {
            return WM_ERRCODE_INVALID_PARAM;
        }
        DC_InvalidateRange(&(p->status->child_bitmap), 2);
        if (!(p->status->child_bitmap & (0x0001 << aid))) {
            return WM_ERRCODE_NO_CHILD;
        }
    } else {
        if (aid != 0) {
            return WM_ERRCODE_INVALID_PARAM;
        }
    }

    WMi_SetCallbackTable(WM_APIID_DISCONNECT, callback);

    result = WMi_SendCommand(WM_APIID_DISCONNECT, 1, (u32)(0x0001 << aid));
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
