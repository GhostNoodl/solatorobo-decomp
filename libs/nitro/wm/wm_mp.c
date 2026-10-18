#include "wm_private.h"

WMErrCode WMi_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, WMMPTmpParam *tmpParam) {
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();
    WMStatus *status = p->status;

    result = WMi_CheckStateEx(2, WM_STATE_PARENT, WM_STATE_CHILD);
    WM_CHECK_RESULT(result);

    DC_InvalidateRange(&(status->aid), 2);
    DC_InvalidateRange(&(status->pwrMgtMode), 2);

    if (status->aid != 0 && status->pwrMgtMode != 1) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    DC_InvalidateRange(&(status->mp_flag), 4);

    if (status->mp_flag == TRUE) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    if ((recvBufSize & 0x3f) != 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    if ((sendBufSize & 0x1f) != 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_InvalidateRange(&(status->mp_ignoreSizePrecheckMode), sizeof(status->mp_ignoreSizePrecheckMode));

    if (status->mp_ignoreSizePrecheckMode == FALSE) {
        if (recvBufSize < WM_GetMPReceiveBufferSize()) {
            return WM_ERRCODE_INVALID_PARAM;
        }

        if (sendBufSize < WM_GetMPSendBufferSize()) {
            return WM_ERRCODE_INVALID_PARAM;
        }
    }

    WMi_SetCallbackTable(WM_APIID_START_MP, callback);

    {
        WMStartMPReq Req;

        MI_CpuClear32(&Req, sizeof(Req));

        Req.apiid = WM_APIID_START_MP;
        Req.recvBuf = (u32 *)recvBuf;
        Req.recvBufSize = (u32)(recvBufSize / 2);
        Req.sendBuf = (u32 *)sendBuf;
        Req.sendBufSize = (u32)sendBufSize;

        MI_CpuClear32(&Req.param, sizeof(Req.param));
        MI_CpuCopy32(tmpParam, &Req.tmpParam, sizeof(Req.tmpParam));

        result = WMi_SendCommandDirect(&Req, sizeof(Req));
        WM_CHECK_RESULT(result);
    }

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq) {
    WMMPTmpParam tmpParam;

    MI_CpuClear32(&tmpParam, sizeof(tmpParam));

    tmpParam.mask = WM_MP_TMP_PARAM_FREQUENCY | WM_MP_TMP_PARAM_MIN_FREQUENCY;
    tmpParam.minFrequency = mpFreq;
    tmpParam.frequency = mpFreq;

    return WMi_StartMP(callback, recvBuf, recvBufSize, sendBuf, sendBufSize, &tmpParam);
}

WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, const u16 *sendData, u16 sendDataSize, u16 destBitmap, u16 port, u16 prio) {
    WMErrCode result;
    BOOL isParent;
    u16 mpReadyBitmap = 0x0001;
    u16 childBitmap = 0x0001;
    WMArm9Buf *p = WMi_GetSystemWork();
    WMStatus *status = p->status;

    result = WMi_CheckStateEx(2, WM_STATE_MP_PARENT, WM_STATE_MP_CHILD);
    WM_CHECK_RESULT(result);

    DC_InvalidateRange(&(status->aid), 2);
    isParent = (status->aid == 0) ? TRUE : FALSE;

    if (isParent == TRUE) {
        DC_InvalidateRange(&(status->child_bitmap), 2);
        childBitmap = status->child_bitmap;
        DC_InvalidateRange(&(status->mp_readyBitmap), 2);
        mpReadyBitmap = status->mp_readyBitmap;
    }

    if (sendData == NULL) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (childBitmap == 0) {
        return WM_ERRCODE_NO_CHILD;
    }

    DC_InvalidateRange(&(status->mp_sendBuf), 2);

    if ((void *)sendData == (void *)status->mp_sendBuf) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (sendDataSize > WM_SIZE_MP_DATA_MAX) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (sendDataSize == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_StoreRange((void *)sendData, sendDataSize);

    result = WMi_SendCommand(WM_APIID_SET_MP_DATA, 7, (u32)sendData, (u32)sendDataSize, (u32)destBitmap, (u32)port,
                             (u32)prio, (u32)callback, (u32)arg);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_EndMP(WMCallbackFunc callback) {
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(2, WM_STATE_MP_PARENT, WM_STATE_MP_CHILD);
    WM_CHECK_RESULT(result);

    DC_InvalidateRange(&(p->status->mp_flag), 4);
    if (p->status->mp_flag == FALSE) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    WMi_SetCallbackTable(WM_APIID_END_MP, callback);

    result = WMi_SendCommand(WM_APIID_END_MP, 0);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
