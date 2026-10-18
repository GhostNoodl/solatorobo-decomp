#include "wm_private.h"

#define WM_SIZE_TEMP_USR_GAME_INFO_BUF 128

static u32 tmpUserGameInfoBuf[WM_SIZE_TEMP_USR_GAME_INFO_BUF / sizeof(u32)] __attribute__((aligned(32)));

WMErrCode WM_SetGameInfo(WMCallbackFunc callback, const u16 *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid, u8 attr) {
    WMErrCode result;

    result = WMi_CheckStateEx(2, WM_STATE_PARENT, WM_STATE_MP_PARENT);
    WM_CHECK_RESULT(result);

    if (userGameInfo == NULL) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (userGameInfoSize > WM_SIZE_USER_GAMEINFO) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    MI_CpuCopy16((void *)userGameInfo, (void *)tmpUserGameInfoBuf, userGameInfoSize);
    DC_StoreRange((void *)tmpUserGameInfoBuf, userGameInfoSize);

    WMi_SetCallbackTable(WM_APIID_SET_GAMEINFO, callback);

    result = WMi_SendCommand(WM_APIID_SET_GAMEINFO, 5, (u32)tmpUserGameInfoBuf, (u32)userGameInfoSize, (u32)ggid,
                             (u32)tgid, (u32)attr);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_MeasureChannel(WMCallbackFunc callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime) {
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckState(WM_STATE_IDLE);
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_MEASURE_CHANNEL, callback);

    {
        WMMeasureChannelReq Req;

        Req.apiid = WM_APIID_MEASURE_CHANNEL;
        Req.ccaMode = ccaMode;
        Req.edThreshold = edThreshold;
        Req.channel = channel;
        Req.measureTime = measureTime;

        result = WMi_SendCommandDirect(&Req, sizeof(Req));
        WM_CHECK_RESULT(result);
    }

    return WM_ERRCODE_OPERATING;
}

WMErrCode WM_SetEntry(WMCallbackFunc callback, BOOL enabled) {
    WMErrCode result;

    result = WMi_CheckStateEx(2, WM_STATE_PARENT, WM_STATE_MP_PARENT);
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_SET_ENTRY, callback);

    result = WMi_SendCommand(WM_APIID_SET_ENTRY, 1, (u32)enabled);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
