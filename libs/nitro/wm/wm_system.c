#include "wm_private.h"
#include "nitro/pm.h"

#define WM_BUF_MSG_NUM 10

void PM_InsertPreSleepCallback(PMSleepCallbackInfo *info, int priority);
BOOL func_02019a48(u32 addr);
BOOL func_02019a94(u32 addr);
BOOL func_0201aa28(void);
BOOL func_0201aa44(void);
s32 func_020218d4(void);

// bss is laid out in reverse declaration order
static u32 fifoBuf[WM_BUF_MSG_NUM][WM_FIFO_BUF_SIZE / sizeof(u32)] __attribute__((aligned(32)));
static WMPortRecvCallback cb_Port;
static OSMessage bufMsg[WM_BUF_MSG_NUM];
static OSMessageQueue bufMsgQ;
static struct {
    u16 initialized;
    WMArm9Buf *wm9buf;
    PMSleepCallbackInfo sleepCbInfo;
} wmWork;
#define wmInitialized wmWork.initialized
#define wm9buf wmWork.wm9buf
#define sleepCbInfo wmWork.sleepCbInfo

static void WmReceiveFifo(PXIFifoTag tag, u32 fifo_buf_adr, BOOL err);
static void WmClearFifoRecvFlag(void);
static WMErrCode WmInitCore(void *wmSysBuf, u16 dmaNo, u32 bufSize);
static u32 *WmGetCommandBuffer4Arm7(void);
void WMi_RegisterSleepCallback(void);
void WMi_DeleteSleepCallback(void);
static void WmSleepCallback(void *arg);

WMErrCode WM_Init(void *wmSysBuf, u16 dmaNo) {
    WMErrCode result;
    result = WmInitCore(wmSysBuf, dmaNo, WM_SYSTEM_BUF_SIZE);

    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    wm9buf->scanOnlyFlag = FALSE;
    return result;
}

static WMErrCode WmInitCore(void *wmSysBuf, u16 dmaNo, u32 bufSize) {
    OSIntrMode e;

    e = OS_DisableInterrupts();

    if (OS_IsRunOnTwl() && func_020218d4() != 3) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    if (wmInitialized) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    if (wmSysBuf == NULL) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (func_02019a94((u32)wmSysBuf) || (OS_IsRunOnTwl() && func_02019a48((u32)wmSysBuf))) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (dmaNo > 3) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_INVALID_PARAM;
    }

    if ((u32)wmSysBuf & 0x01f) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_INVALID_PARAM;
    }

    PXI_Init();
    if (!PXI_IsCallbackReady(PXI_FIFO_TAG_WM, PXI_PROC_ARM7)) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_WM_DISABLE;
    }

    DC_InvalidateRange(wmSysBuf, bufSize);
    MIi_DmaFill32(dmaNo, wmSysBuf, 0, bufSize, TRUE);
    wm9buf = (WMArm9Buf *)wmSysBuf;
    wm9buf->WM7 = (WMArm7Buf *)((u32)wm9buf + WM_ARM9WM_BUF_SIZE);
    wm9buf->status = (WMStatus *)((u32)(wm9buf->WM7) + WM_ARM7WM_BUF_SIZE);
    wm9buf->fifo9to7 = (u32 *)((u32)(wm9buf->status) + WM_STATUS_BUF_SIZE);
    wm9buf->fifo7to9 = (u32 *)((u32)(wm9buf->fifo9to7) + WM_FIFO_BUF_SIZE);

    WmClearFifoRecvFlag();

    wm9buf->dmaNo = dmaNo;
    wm9buf->connectedAidBitmap = 0x0000;
    wm9buf->myAid = 0;

    {
        s32 i;

        for (i = 0; i < WM_NUM_OF_PORT; i++) {
            wm9buf->portCallbackTable[i] = NULL;
            wm9buf->portCallbackArgument[i] = NULL;
        }
    }

    {
        s32 i;

        OS_InitMessageQueue(&bufMsgQ, bufMsg, WM_BUF_MSG_NUM);
        for (i = 0; i < WM_BUF_MSG_NUM; i++) {
            *((u16 *)(fifoBuf[i])) = WM_API_REQUEST_ACCEPTED;
            DC_StoreRange(fifoBuf[i], 2);
            (void)OS_SendMessage(&bufMsgQ, fifoBuf[i], OS_MESSAGE_BLOCK);
        }
    }

    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_WM, (PXIFifoCallback)WmReceiveFifo);

    wmInitialized = 1;
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}

WMErrCode WM_Finish(void) {
    OSIntrMode e;
    WMErrCode result;

    e = OS_DisableInterrupts();

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    result = WMi_CheckState(WM_STATE_READY);
    WM_CHECK_RESULT(result);

    WmClearFifoRecvFlag();
    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_WM, NULL);
    wm9buf = 0;

    wmInitialized = 0;
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}

void WMi_SetCallbackTable(WMApiid id, WMCallbackFunc callback) {
    wm9buf->CallbackTable[id] = callback;
}

static u32 *WmGetCommandBuffer4Arm7(void) {
    u32 *tmpAddr;

    if (FALSE == OS_ReceiveMessage(&bufMsgQ, (OSMessage *)&tmpAddr, OS_MESSAGE_NOBLOCK)) {
        return NULL;
    }

    DC_InvalidateRange(tmpAddr, 2);
    if ((*((u16 *)tmpAddr) & WM_API_REQUEST_ACCEPTED) == 0) {
        (void)OS_JamMessage(&bufMsgQ, tmpAddr, OS_MESSAGE_BLOCK);
        return NULL;
    }

    return tmpAddr;
}

WMErrCode WMi_SendCommand(WMApiid id, u16 paramNum, ...) {
    va_list vlist;
    s32 i;
    int result;
    u32 *tmpAddr;

    tmpAddr = WmGetCommandBuffer4Arm7();
    if (tmpAddr == NULL) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    *(u16 *)tmpAddr = (u16)id;

    va_start(vlist, paramNum);
    for (i = 0; i < paramNum; i++) {
        tmpAddr[i + 1] = va_arg(vlist, u32);
    }
    va_end(vlist);

    DC_StoreRange(tmpAddr, WM_FIFO_BUF_SIZE);

    result = PXI_SendWordByFifo(PXI_FIFO_TAG_WM, (u32)tmpAddr, FALSE);

    (void)OS_SendMessage(&bufMsgQ, tmpAddr, OS_MESSAGE_BLOCK);

    if (result < 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    return WM_ERRCODE_OPERATING;
}

WMErrCode WMi_SendCommandDirect(void *data, u32 length) {
    int result;
    u32 *tmpAddr;

    tmpAddr = WmGetCommandBuffer4Arm7();
    if (tmpAddr == NULL) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    MI_CpuCopy8(data, tmpAddr, length);
    DC_StoreRange(tmpAddr, length);

    result = PXI_SendWordByFifo(PXI_FIFO_TAG_WM, (u32)tmpAddr, FALSE);

    (void)OS_SendMessage(&bufMsgQ, tmpAddr, OS_MESSAGE_BLOCK);

    if (result < 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    return WM_ERRCODE_OPERATING;
}

WMArm9Buf *WMi_GetSystemWork(void) {
    return wm9buf;
}

WMErrCode WMi_CheckInitialized(void) {
    if (!wmInitialized) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    return WM_ERRCODE_SUCCESS;
}

WMErrCode WMi_CheckIdle(void) {
    WMErrCode result;

    result = WMi_CheckInitialized();
    WM_CHECK_RESULT(result);

    DC_InvalidateRange(&(wm9buf->status->state), 2);
    if ((wm9buf->status->state == WM_STATE_READY) || (wm9buf->status->state == WM_STATE_STOP)) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    return WM_ERRCODE_SUCCESS;
}

WMErrCode WMi_CheckStateEx(s32 paramNum, ...) {
    WMErrCode result;
    u16 now;
    u32 temp;
    va_list vlist;

    result = WMi_CheckInitialized();
    WM_CHECK_RESULT(result);

    DC_InvalidateRange(&(wm9buf->status->state), 2);
    now = wm9buf->status->state;

    result = WM_ERRCODE_ILLEGAL_STATE;
    va_start(vlist, paramNum);
    for (; paramNum; paramNum--) {
        temp = va_arg(vlist, u32);
        if (temp == now) {
            result = WM_ERRCODE_SUCCESS;
        }
    }
    va_end(vlist);

    return result;
}

static void WmReceiveFifo(PXIFifoTag tag, u32 fifo_buf_adr, BOOL err) {
#pragma unused(tag)
    WMCallback *callback_p = (WMCallback *)fifo_buf_adr;
    WMArm9Buf *w9b = wm9buf;

    if (err)
        return;

    DC_InvalidateRange(w9b->fifo7to9, WM_FIFO_BUF_SIZE);
    if (!w9b->scanOnlyFlag) {
        DC_InvalidateRange(w9b->status, WM_STATUS_BUF_SIZE);
    }

    if ((u32)callback_p != (u32)(w9b->fifo7to9)) {
        DC_InvalidateRange(callback_p, WM_FIFO_BUF_SIZE);
    }

    if (callback_p->apiid >= WM_NUM_OF_CALLBACK) {
        if (callback_p->apiid == WM_APIID_INDICATION) {
            if (callback_p->errcode == WM_ERRCODE_FLASH_ERROR) {
                OS_Terminate();
            }
            if (w9b->indCallback != NULL) {
                w9b->indCallback((void *)callback_p);
            }
        } else if (callback_p->apiid == WM_APIID_PORT_RECV) {
            WMPortRecvCallback *cb_Port = (WMPortRecvCallback *)callback_p;

            if (w9b->portCallbackTable[cb_Port->port] != NULL) {
                cb_Port->arg = w9b->portCallbackArgument[cb_Port->port];
                cb_Port->connectedAidBitmap = (u16)w9b->connectedAidBitmap;
                DC_InvalidateRange(cb_Port->recvBuf, w9b->status->mp_recvBufSize);
                (w9b->portCallbackTable[cb_Port->port])((void *)cb_Port);
            }
        } else if (callback_p->apiid == WM_APIID_PORT_SEND) {
            WMPortSendCallback *cb_Port = (WMPortSendCallback *)callback_p;
            callback_p->apiid = WM_APIID_SET_MP_DATA;
            if (cb_Port->callback != NULL) {
                (cb_Port->callback)((void *)cb_Port);
            }
        }
    } else {
        if (callback_p->apiid == WM_APIID_START_MP) {
            WMStartMPCallback *cb_StartMP = (WMStartMPCallback *)callback_p;
            if (cb_StartMP->state == WM_STATECODE_MPEND_IND || cb_StartMP->state == WM_STATECODE_MP_IND) {
                if (cb_StartMP->errcode == WM_ERRCODE_SUCCESS) {
                    DC_InvalidateRange(cb_StartMP->recvBuf, w9b->status->mp_recvBufSize);
                }
            }
        }

        if (((callback_p->apiid == WM_APIID_DISABLE || callback_p->apiid == WM_APIID_END) &&
             callback_p->errcode == WM_ERRCODE_SUCCESS) ||
            ((callback_p->apiid == WM_APIID_ENABLE || callback_p->apiid == WM_APIID_INITIALIZE) &&
             callback_p->errcode != WM_ERRCODE_SUCCESS)) {
            WMi_DeleteSleepCallback();
        }

        if (callback_p->apiid == WM_APIID_END && callback_p->errcode == WM_ERRCODE_SUCCESS) {
            WMCallbackFunc cb = w9b->CallbackTable[callback_p->apiid];

            (void)WM_Finish();
            if (cb != NULL) {
                cb((void *)callback_p);
            }
            return;
        }

        if (NULL != w9b->CallbackTable[callback_p->apiid]) {
            (w9b->CallbackTable[callback_p->apiid])((void *)callback_p);

            if (!wmInitialized) {
                return;
            }
        }

        if (callback_p->apiid == WM_APIID_START_PARENT || callback_p->apiid == WM_APIID_START_CONNECT) {
            u16 state, aid, myAid, reason;
            u8 *macAddress;
            u8 *ssid;
            u16 parentSize, childSize;

            if (callback_p->apiid == WM_APIID_START_PARENT) {
                WMStartParentCallback *cb = (WMStartParentCallback *)callback_p;
                state = cb->state;
                aid = cb->aid;
                myAid = 0;
                macAddress = cb->macAddress;
                ssid = cb->ssid;
                reason = cb->reason;
                parentSize = cb->parentSize;
                childSize = cb->childSize;
            } else if (callback_p->apiid == WM_APIID_START_CONNECT) {
                WMStartConnectCallback *cb = (WMStartConnectCallback *)callback_p;
                state = cb->state;
                aid = 0;
                myAid = cb->aid;
                macAddress = cb->macAddress;
                ssid = NULL;
                reason = cb->reason;
                parentSize = cb->parentSize;
                childSize = cb->childSize;
            }
            if (state == WM_STATECODE_CONNECTED || state == WM_STATECODE_DISCONNECTED ||
                state == WM_STATECODE_DISCONNECTED_FROM_MYSELF) {
                u16 iPort;

                if (state == WM_STATECODE_CONNECTED) {
                    w9b->connectedAidBitmap |= (1 << aid);
                } else {
                    w9b->connectedAidBitmap &= ~(1 << aid);
                }
                w9b->myAid = myAid;

                MI_CpuClear8(&cb_Port, sizeof(WMPortRecvCallback));
                cb_Port.apiid = WM_APIID_PORT_RECV;
                cb_Port.errcode = WM_ERRCODE_SUCCESS;
                cb_Port.state = state;
                cb_Port.recvBuf = NULL;
                cb_Port.data = NULL;
                cb_Port.length = 0;
                cb_Port.aid = aid;
                cb_Port.myAid = myAid;
                cb_Port.connectedAidBitmap = (u16)w9b->connectedAidBitmap;
                cb_Port.seqNo = 0xffff;
                cb_Port.reason = reason;
                MI_CpuCopy8(macAddress, cb_Port.macAddress, WM_SIZE_MACADDR);
                if (ssid != NULL) {
                    MI_CpuCopy16(ssid, cb_Port.ssid, WM_SIZE_CHILD_SSID);
                } else {
                    MI_CpuClear16(cb_Port.ssid, WM_SIZE_CHILD_SSID);
                }
                cb_Port.maxSendDataSize = (myAid == 0) ? parentSize : childSize;
                cb_Port.maxRecvDataSize = (myAid == 0) ? childSize : parentSize;

                for (iPort = 0; iPort < WM_NUM_OF_PORT; iPort++) {
                    cb_Port.port = iPort;
                    if (w9b->portCallbackTable[iPort] != NULL) {
                        cb_Port.arg = w9b->portCallbackArgument[iPort];
                        (w9b->portCallbackTable[iPort])((void *)&cb_Port);
                    }
                }
            }
        }
    }

    DC_InvalidateRange(w9b->fifo7to9, WM_FIFO_BUF_SIZE);
    WmClearFifoRecvFlag();

    if ((u32)callback_p != (u32)(w9b->fifo7to9)) {
        callback_p->apiid |= WM_API_REQUEST_ACCEPTED;
        DC_StoreRange(callback_p, WM_FIFO_BUF_SIZE);
    }
}

static void WmClearFifoRecvFlag(void) {
    if (OS_GetSystemWork()->wm_callback_control & WM_EXCEPTION_CB_MASK) {
        OS_GetSystemWork()->wm_callback_control &= ~WM_EXCEPTION_CB_MASK;
    }
}

u16 WM_GetAID(void) {
    u16 myAid;
    OSIntrMode e;

    e = OS_DisableInterrupts();

    if (wm9buf != NULL) {
        myAid = wm9buf->myAid;
    } else {
        myAid = 0;
    }

    (void)OS_RestoreInterrupts(e);

    return myAid;
}

u16 WM_GetConnectedAIDs(void) {
    u32 connectedAidBitmap;
    OSIntrMode e;

    e = OS_DisableInterrupts();

    if (wm9buf != NULL) {
        connectedAidBitmap = wm9buf->connectedAidBitmap;
    } else {
        connectedAidBitmap = 0;
    }

    (void)OS_RestoreInterrupts(e);

    return (u16)connectedAidBitmap;
}

void WMi_RegisterSleepCallback(void) {
    PM_SetSleepCallbackInfo(&sleepCbInfo, WmSleepCallback, NULL);
    PM_InsertPreSleepCallback(&sleepCbInfo, 1000);
}

void WMi_DeleteSleepCallback(void) {
    PM_DeletePreSleepCallback(&sleepCbInfo);
}

static void WmSleepCallback(void *arg) {
#pragma unused(arg)
    OS_Terminate();
}

s32 func_0201fd04(void) {
    s32 result = 2;

    if (OS_IsRunOnTwl()) {
        result = func_0201fd30() ? 1 : 0;
    }
    return result;
}

BOOL func_0201fd30(void) {
    if (func_0201aa28() == 1 && func_0201aa44() == 0) {
        return TRUE;
    }
    return FALSE;
}
