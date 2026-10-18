#ifndef LIBS_NITRO_WM_PRIVATE_H
#define LIBS_NITRO_WM_PRIVATE_H

// Wireless manager (WM) library, ARM9 side

#include "types.h"
#include "nitro/os.h"
#include "nitro/os_tick.h"
#include "nitro/os_systemWork.h"
#include "nitro/mi.h"
#include "nitro/pxi.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PXI_FIFO_TAG_WM 10

typedef char *va_list;
#define va_start(ap, parm) ((ap) = (va_list)((char *)((unsigned long)(&parm) & ~3U) + ((sizeof(parm) + 3U) & ~3U)))
#define va_arg(ap, type) (*(type *)((ap += sizeof(type) + 3U & ~3U) - (sizeof(type) + 3U & ~3U)))
#define va_end(ap) ((void)0)

typedef enum WMApiid {
    WM_APIID_INITIALIZE = 0,
    WM_APIID_RESET,
    WM_APIID_END,
    WM_APIID_ENABLE,
    WM_APIID_DISABLE,
    WM_APIID_POWER_ON,
    WM_APIID_POWER_OFF,
    WM_APIID_SET_P_PARAM,
    WM_APIID_START_PARENT,
    WM_APIID_END_PARENT,
    WM_APIID_START_SCAN,
    WM_APIID_END_SCAN,
    WM_APIID_START_CONNECT,
    WM_APIID_DISCONNECT,
    WM_APIID_START_MP,
    WM_APIID_SET_MP_DATA,
    WM_APIID_END_MP,
    WM_APIID_START_DCF,
    WM_APIID_SET_DCF_DATA,
    WM_APIID_END_DCF,
    WM_APIID_SET_WEPKEY,
    WM_APIID_START_KS,
    WM_APIID_END_KS,
    WM_APIID_GET_KEYSET,
    WM_APIID_SET_GAMEINFO,
    WM_APIID_SET_BEACON_IND,
    WM_APIID_START_TESTMODE,
    WM_APIID_STOP_TESTMODE,
    WM_APIID_VALARM_MP,
    WM_APIID_SET_LIFETIME,
    WM_APIID_MEASURE_CHANNEL,
    WM_APIID_INIT_W_COUNTER,
    WM_APIID_GET_W_COUNTER,
    WM_APIID_SET_ENTRY,
    WM_APIID_AUTO_DEAUTH,
    WM_APIID_SET_MP_PARAMETER,
    WM_APIID_SET_BEACON_PERIOD,
    WM_APIID_AUTO_DISCONNECT,
    WM_APIID_START_SCAN_EX,
    WM_APIID_SET_WEPKEY_EX,
    WM_APIID_SET_PS_MODE,
    WM_APIID_START_TESTRXMODE,
    WM_APIID_STOP_TESTRXMODE,
    WM_APIID_KICK_MP_PARENT,
    WM_APIID_KICK_MP_CHILD,
    WM_APIID_KICK_MP_RESUME,
    WM_APIID_ASYNC_KIND_MAX,
    WM_APIID_INDICATION = 128,
    WM_APIID_PORT_SEND,
    WM_APIID_PORT_RECV,
    WM_APIID_READ_STATUS,
    WM_APIID_UNKNOWN = 255
} WMApiid;

#define WM_NUM_OF_CALLBACK (WM_APIID_ASYNC_KIND_MAX - 2)
#define WM_API_REQUEST_ACCEPTED 0x8000

typedef enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_FAILED = 1,
    WM_ERRCODE_OPERATING = 2,
    WM_ERRCODE_ILLEGAL_STATE = 3,
    WM_ERRCODE_WM_DISABLE = 4,
    WM_ERRCODE_NO_DATASET = 5,
    WM_ERRCODE_INVALID_PARAM = 6,
    WM_ERRCODE_NO_CHILD = 7,
    WM_ERRCODE_FIFO_ERROR = 8,
    WM_ERRCODE_TIMEOUT = 9,
    WM_ERRCODE_SEND_QUEUE_FULL = 10,
    WM_ERRCODE_NO_ENTRY = 11,
    WM_ERRCODE_OVER_MAX_ENTRY = 12,
    WM_ERRCODE_INVALID_POLLBITMAP = 13,
    WM_ERRCODE_NO_DATA = 14,
    WM_ERRCODE_SEND_FAILED = 15,
    WM_ERRCODE_DCF_TEST,
    WM_ERRCODE_WL_INVALID_PARAM,
    WM_ERRCODE_WL_LENGTH_ERR,
    WM_ERRCODE_FLASH_ERROR,
    WM_ERRCODE_MAX
} WMErrCode;

typedef enum WMState {
    WM_STATE_READY = 0,
    WM_STATE_STOP,
    WM_STATE_IDLE,
    WM_STATE_CLASS1,
    WM_STATE_TESTMODE,
    WM_STATE_SCAN,
    WM_STATE_CONNECT,
    WM_STATE_PARENT,
    WM_STATE_CHILD,
    WM_STATE_MP_PARENT,
    WM_STATE_MP_CHILD,
    WM_STATE_DCF_CHILD,
    WM_STATE_TESTMODE_RX,
    WM_STATE_MAX
} WMState;

#define WM_STATECODE_CONNECTED 7
#define WM_STATECODE_DISCONNECTED 9
#define WM_STATECODE_MPEND_IND 11
#define WM_STATECODE_MP_IND 12
#define WM_STATECODE_PORT_SEND 20
#define WM_STATECODE_PORT_RECV 21
#define WM_STATECODE_PORT_INIT 25
#define WM_STATECODE_DISCONNECTED_FROM_MYSELF 26

typedef enum WMLinkLevel {
    WM_LINK_LEVEL_0 = 0,
    WM_LINK_LEVEL_1,
    WM_LINK_LEVEL_2,
    WM_LINK_LEVEL_3,
    WM_LINK_LEVEL_MAX
} WMLinkLevel;

typedef enum WMDataSharingState {
    WM_DS_STATE_READY = 0,
    WM_DS_STATE_START,
    WM_DS_STATE_PAUSING,
    WM_DS_STATE_PAUSED,
    WM_DS_STATE_RETRY_SEND,
    WM_DS_STATE_ERROR
} WMDataSharingState;

#define WM_NUM_MAX_CHILD 15
#define WM_NUM_OF_PORT 16
#define WM_NUM_OF_SEQ_PORT 8
#define WM_SEND_QUEUE_NUM 32
#define WM_SEND_QUEUE_END ((u16)0xffff)
#define WM_PRIORITY_LEVEL 4
#define WM_PRIORITY_URGENT 0
#define WM_PRIORITY_HIGH 1
#define WM_PRIORITY_NORMAL 2
#define WM_PRIORITY_LOW 3

#define WM_SIZE_BSSID 6
#define WM_SIZE_SSID 32
#define WM_SIZE_USER_GAMEINFO 112
#define WM_SIZE_WL_VERSION 8
#define WM_SIZE_BBP_VERSION 4
#define WM_SIZE_MACADDR 6
#define WM_SIZE_WEPKEY 80
#define WM_SIZE_CHILD_SSID 24
#define WM_SIZE_MP_DATA_MAX 512
#define WM_SIZE_DS_PARENT_HEADER 4
#define WM_SIZE_KS_PARENT_DATA (2 * 16 + WM_SIZE_DS_PARENT_HEADER)
#define WM_SIZE_KS_CHILD_DATA 2
#define WM_SIZE_MP_PARENT_PADDING (WM_HEADER_SIZE + WM_HEADER_PARENT_MAX_SIZE)
#define WM_SIZE_MP_CHILD_PADDING (WM_HEADER_SIZE + WM_HEADER_CHILD_MAX_SIZE)
#define WM_PARENT_PARAM_SIZE 64

#define WM_HEADER_SIZE 2
#define WM_HEADER_PARENT_MAX_SIZE 4
#define WM_HEADER_CHILD_MAX_SIZE 2

#define WM_EXCEPTION_CB_MASK 0x0001

#define WM_ARM9WM_BUF_SIZE 512
#define WM_ARM7WM_BUF_SIZE (256 + 512)
#define WM_STATUS_BUF_SIZE 2048
#define WM_FIFO_BUF_SIZE 256
#define WM_SYSTEM_BUF_SIZE (WM_ARM9WM_BUF_SIZE + WM_ARM7WM_BUF_SIZE + WM_STATUS_BUF_SIZE + WM_FIFO_BUF_SIZE + WM_FIFO_BUF_SIZE)

#define WM_DS_HEADER_SIZE 4
#define WM_DS_DATA_SIZE 508
#define WM_DS_DATASET_NUM 4

#define WM_DEFAULT_BEACON_PERIOD 200
#define WM_DEFAULT_SCAN_PERIOD 30
#define WM_MAX_MP_PACKET_TIME 5600

typedef void (*WMCallbackFunc)(void *arg);

typedef struct WMDataSet {
    u16 aidBitmap;
    u16 receivedBitmap;
    u16 data[WM_DS_DATA_SIZE / sizeof(u16)];
} WMDataSet;

typedef struct WMDataSharingInfo {
    WMDataSet ds[WM_DS_DATASET_NUM];
    u16 seqNum[WM_DS_DATASET_NUM];
    u16 writeIndex;
    u16 sendIndex;
    u16 readIndex;
    u16 aidBitmap;
    u16 dataLength;
    u16 stationNumber;
    u16 dataSetLength;
    u16 port;
    u16 doubleMode;
    u16 currentSeqNum;
    u16 state;
    u16 reserved[1];
} WMDataSharingInfo;

typedef struct WMPortSendQueueData {
    u16 next;
    u16 port;
    u16 destBitmap;
    u16 restBitmap;
    u16 sentBitmap;
    u16 sendingBitmap;
    u16 padding;
    u16 size;
    u16 seqNo;
    u16 retryCount;
    const u16 *data;
    WMCallbackFunc callback;
    void *arg;
} WMPortSendQueueData;

typedef struct WMPortSendQueue {
    u16 head;
    u16 tail;
} WMPortSendQueue;

typedef struct WMMpRecvBuf {
    u16 rsv1[3];
    u16 length;
    u16 rsv2[1];
    u16 ackTimeStamp;
    u16 timeStamp;
    u16 rate_rssi;
    u16 rsv3[2];
    u16 rsv4[2];
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u16 rsv5[3];
    u16 seqCtrl;
    u16 txop;
    u16 bitmap;
    u16 wmHeader;
    u16 data[2];
} WMMpRecvBuf;

typedef struct WMMpRecvData {
    u16 length;
    u16 rate_rssi;
    u16 aid;
    u16 noResponse;
    u16 wmHeader;
    u16 cdata[1];
} WMMpRecvData;

typedef struct WMMpRecvHeader {
    u16 bitmap;
    u16 errBitmap;
    u16 count;
    u16 length;
    u16 txCount;
    WMMpRecvData data[1];
} WMMpRecvHeader;

typedef struct WMDcfRecvBuf WMDcfRecvBuf;

typedef struct WMParentParam {
    u16 *userGameInfo;
    u16 userGameInfoLength;
    u16 padding;
    u32 ggid;
    u16 tgid;
    u16 entryFlag;
    u16 maxEntry;
    u16 multiBootFlag;
    u16 KS_Flag;
    u16 CS_Flag;
    u16 beaconPeriod;
    u16 rsv1[4];
    u16 rsv2[8];
    u16 channel;
    u16 parentMaxSize;
    u16 childMaxSize;
    u16 rsv[4];
} WMParentParam;

typedef struct WMGameInfo {
    u16 magicNumber;
    u8 ver;
    u8 platform;
    u32 ggid;
    u16 tgid;
    u8 userGameInfoLength;
    u8 attribute;
    u16 parentMaxSize;
    u16 childMaxSize;
    u16 userGameInfo[WM_SIZE_USER_GAMEINFO / sizeof(u16)];
} WMGameInfo;

typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[WM_SIZE_BSSID];
    u16 ssidLength;
    u8 ssid[WM_SIZE_SSID];
    u16 capaInfo;
    struct {
        u16 basic;
        u16 support;
    } rateSet;
    u16 beaconPeriod;
    u16 dtimPeriod;
    u16 channel;
    u16 cfpPeriod;
    u16 cfpMaxDuration;
    u16 gameInfoLength;
    u16 otherElementCount;
    WMGameInfo gameInfo;
} WMBssDesc;

typedef struct WMScanParam {
    WMBssDesc *scanBuf;
    u16 channel;
    u16 maxChannelTime;
    u8 bssid[WM_SIZE_BSSID];
    u16 rsv[9];
} WMScanParam;

typedef struct WMScanExParam {
    WMBssDesc *scanBuf;
    u16 scanBufSize;
    u16 channelList;
    u16 maxChannelTime;
    u8 bssid[WM_SIZE_BSSID];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[WM_SIZE_SSID];
    u16 ssidMatchLength;
    u16 rsv2[7];
} WMScanExParam;

typedef struct WMMPParam {
    u32 mask;
    u16 minFrequency;
    u16 frequency;
    u16 maxFrequency;
    u16 parentSize;
    u16 childSize;
    u16 parentInterval;
    u16 childInterval;
    u16 parentVCount;
    u16 childVCount;
    u16 defaultRetryCount;
    u8 minPollBmpMode;
    u8 singlePacketMode;
    u8 ignoreFatalErrorMode;
    u8 ignoreSizePrecheckMode;
} WMMPParam;

typedef struct WMMPTmpParam {
    u32 mask;
    u16 minFrequency;
    u16 frequency;
    u16 maxFrequency;
    u16 defaultRetryCount;
    u8 minPollBmpMode;
    u8 singlePacketMode;
    u8 ignoreFatalErrorMode;
    u8 reserved[1];
} WMMPTmpParam;

#define WM_MP_TMP_PARAM_MIN_FREQUENCY 0x0001
#define WM_MP_TMP_PARAM_FREQUENCY 0x0002
#define WM_MP_TMP_PARAM_MAX_FREQUENCY 0x0004

typedef struct WMStatus {
    u16 state;                  // 0x000
    u16 BusyApiid;
    BOOL apiBusy;
    BOOL scan_continue;
    BOOL mp_flag;               // 0x00c
    BOOL dcf_flag;
    BOOL ks_flag;
    BOOL dcf_sendFlag;
    BOOL VSyncFlag;
    u8 wlVersion[WM_SIZE_WL_VERSION];
    u16 macVersion;
    u16 rfVersion;
    u16 bbpVersion[WM_SIZE_BBP_VERSION / sizeof(u16)];
    u16 mp_parentSize;
    u16 mp_childSize;
    u16 mp_parentMaxSize;
    u16 mp_childMaxSize;
    u16 mp_sendSize;
    u16 mp_recvSize;
    u16 mp_maxSendSize;
    u16 mp_maxRecvSize;
    u16 mp_parentVCount;
    u16 mp_childVCount;
    u16 mp_parentInterval;
    u16 mp_childInterval;
    OSTick mp_parentIntervalTick;
    OSTick mp_childIntervalTick;
    u16 mp_minFreq;
    u16 mp_freq;
    u16 mp_maxFreq;
    u16 mp_vsyncOrderedFlag;
    u16 mp_vsyncFlag;
    s16 mp_count;
    s16 mp_limitCount;
    u16 mp_resumeFlag;
    u16 mp_prevPollBitmap;
    u16 mp_prevWmHeader;
    u16 mp_prevTxop;
    u16 mp_prevDataLength;
    u16 mp_recvBufSel;
    u16 mp_recvBufSize;
    WMMpRecvBuf *mp_recvBuf[2];
    u32 *mp_sendBuf;
    u16 mp_sendBufSize;
    u16 mp_ackTime;
    u16 mp_waitAckFlag;
    u16 mp_readyBitmap;
    u16 mp_newFrameFlag;
    u16 mp_setDataFlag;
    u16 mp_sentDataFlag;
    u16 mp_bufferEmptyFlag;
    u16 mp_isPolledFlag;
    u16 mp_minPollBmpMode;
    u16 mp_singlePacketMode;
    u8 reserved_c[2];
    u16 mp_defaultRetryCount;
    u16 mp_ignoreFatalErrorMode;
    u16 mp_ignoreSizePrecheckMode;
    u16 mp_pingFlag;
    u16 mp_pingCounter;
    u8 dcf_destAdr[WM_SIZE_MACADDR];
    u16 *dcf_sendData;
    u16 dcf_sendSize;
    u16 dcf_recvBufSel;
    WMDcfRecvBuf *dcf_recvBuf[2];
    u16 dcf_recvBufSize;
    u16 curr_tgid;
    u16 linkLevel;
    u16 minRssi;
    u16 rssiCounter;
    u16 beaconIndicateFlag;
    u16 wepKeyId;
    u16 pwrMgtMode;
    u32 miscFlags;
    u16 VSyncBitmap;
    u16 valarm_queuedFlag;
    u32 v_tsf;
    u32 v_tsf_bak;
    u32 v_remain;
    u16 valarm_counter;
    u8 reserved_e[2];
    u8 MacAddress[WM_SIZE_MACADDR];
    u16 mode;
    WMParentParam pparam;
    u8 childMacAddress[WM_NUM_MAX_CHILD][WM_SIZE_MACADDR];
    u16 child_bitmap;
    WMBssDesc *pInfoBuf;
    u16 aid;
    u8 parentMacAddress[WM_SIZE_MACADDR];
    u16 scan_channel;
    u8 reserved_f[4];
    u16 wepMode;
    BOOL wep_flag;
    u16 wepKey[WM_SIZE_WEPKEY / sizeof(u16)];
    u16 rate;
    u16 preamble;
    u16 tmptt;
    u16 retryLimit;
    u16 enableChannel;
    u16 allowedChannel;
    u16 portSeqNo[WM_NUM_MAX_CHILD + 1][WM_NUM_OF_SEQ_PORT];
    WMPortSendQueueData sendQueueData[WM_SEND_QUEUE_NUM];
    WMPortSendQueue sendQueueFreeList;
    WMPortSendQueue sendQueue[WM_PRIORITY_LEVEL];
    WMPortSendQueue readyQueue[WM_PRIORITY_LEVEL];
    OSMutex sendQueueMutex;
    BOOL sendQueueInUse;
    OSTick mp_lastRecvTick[1 + WM_NUM_MAX_CHILD];
    OSTick mp_lifeTimeTick;
    u16 mp_current_minFreq;
    u16 mp_current_freq;
    u16 mp_current_maxFreq;
    u16 mp_current_minPollBmpMode;
    u16 mp_current_singlePacketMode;
    u16 mp_current_defaultRetryCount;
    u16 mp_current_ignoreFatalErrorMode;
    u8 reserved[2];
} WMStatus;

typedef struct WMArm7Buf WMArm7Buf;

typedef struct WMArm9Buf {
    WMArm7Buf *WM7;                                     // 0x000
    WMStatus *status;                                   // 0x004
    u32 *indbuf;                                        // 0x008
    u32 *fifo9to7;                                      // 0x00c
    u32 *fifo7to9;                                      // 0x010
    u16 dmaNo;                                          // 0x014
    u16 scanOnlyFlag;                                   // 0x016
    WMCallbackFunc CallbackTable[WM_NUM_OF_CALLBACK];   // 0x018
    WMCallbackFunc indCallback;                         // 0x0c8
    WMCallbackFunc portCallbackTable[WM_NUM_OF_PORT];   // 0x0cc
    void *portCallbackArgument[WM_NUM_OF_PORT];         // 0x10c
    u32 connectedAidBitmap;                             // 0x14c
    u16 myAid;                                          // 0x150
} WMArm9Buf;

typedef struct WMCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
} WMCallback;

typedef struct WMStartParentCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[WM_SIZE_MACADDR];
    u16 aid;
    u16 reason;
    u8 ssid[WM_SIZE_CHILD_SSID];
    u16 parentSize;
    u16 childSize;
} WMStartParentCallback;

typedef struct WMStartConnectCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 aid;
    u16 reason;
    u16 wlStatus;
    u8 macAddress[WM_SIZE_MACADDR];
    u16 parentSize;
    u16 childSize;
} WMStartConnectCallback;

typedef struct WMStartMPCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u8 reserved[2];
    WMMpRecvBuf *recvBuf;
    u16 timeStamp;
    u16 rate_rssi;
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u16 seqNum;
    u16 tmptt;
    u16 pollbmp;
    u16 reserved2;
} WMStartMPCallback;

typedef struct WMPortSendCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 port;
    u16 destBitmap;
    u16 restBitmap;
    u16 sentBitmap;
    u16 rsv;
    const u16 *data;
    union {
        u16 size;
        u16 length;
    };
    u16 seqNo;
    WMCallbackFunc callback;
    void *arg;
    u16 maxSendDataSize;
    u16 maxRecvDataSize;
} WMPortSendCallback;

typedef struct WMPortRecvCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 port;
    WMMpRecvBuf *recvBuf;
    u16 *data;
    u16 length;
    u16 aid;
    u8 macAddress[WM_SIZE_MACADDR];
    u16 seqNo;
    void *arg;
    u16 myAid;
    u16 connectedAidBitmap;
    u8 ssid[WM_SIZE_CHILD_SSID];
    u16 reason;
    u16 rsv;
    u16 maxSendDataSize;
    u16 maxRecvDataSize;
} WMPortRecvCallback;

typedef struct WMStartScanReq {
    u16 apiid;
    u16 channel;
    WMBssDesc *scanBuf;
    u16 maxChannelTime;
    u8 bssid[WM_SIZE_BSSID];
} WMStartScanReq;

typedef struct WMStartScanExReq {
    u16 apiid;
    u16 channelList;
    WMBssDesc *scanBuf;
    u16 scanBufSize;
    u16 maxChannelTime;
    u8 bssid[WM_SIZE_BSSID];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[WM_SIZE_SSID];
    u16 ssidMatchLength;
    u16 rsv[2];
} WMStartScanExReq;

typedef struct WMStartConnectReq {
    u16 apiid;
    u16 reserved;
    WMBssDesc *pInfo;
    u8 ssid[WM_SIZE_CHILD_SSID];
    BOOL powerSave;
    u16 reserved2;
    u16 authMode;
} WMStartConnectReq;

typedef struct WMMeasureChannelReq {
    u16 apiid;
    u16 ccaMode;
    u16 edThreshold;
    u16 channel;
    u16 measureTime;
} WMMeasureChannelReq;

typedef struct WMStartMPReq {
    u16 apiid;
    u16 rsv1;
    u32 *recvBuf;
    u32 recvBufSize;
    u32 *sendBuf;
    u32 sendBufSize;
    WMMPParam param;
    WMMPTmpParam tmpParam;
} WMStartMPReq;

// wm_system.c
WMErrCode WM_Init(void *wmSysBuf, u16 dmaNo);
WMErrCode WM_Finish(void);
void WMi_SetCallbackTable(WMApiid id, WMCallbackFunc callback);
WMErrCode WMi_SendCommand(WMApiid id, u16 paramNum, ...);
WMErrCode WMi_SendCommandDirect(void *data, u32 length);
WMArm9Buf *WMi_GetSystemWork(void);
WMErrCode WMi_CheckInitialized(void);
WMErrCode WMi_CheckIdle(void);
WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
u16 WM_GetAID(void);
u16 WM_GetConnectedAIDs(void);
void WMi_RegisterSleepCallback(void);
void WMi_DeleteSleepCallback(void);
BOOL func_0201fd30(void);

static inline WMErrCode WMi_CheckState(u32 state) {
    return WMi_CheckStateEx(1, state);
}

// wm_mp.c
WMErrCode WMi_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, WMMPTmpParam *tmpParam);

// wm_sync.c
int WM_GetMPSendBufferSize(void);
int WM_GetMPReceiveBufferSize(void);

// wm_standard.c
WMErrCode WM_Enable(WMCallbackFunc callback);
WMErrCode WM_PowerOn(WMCallbackFunc callback);
WMErrCode WMi_InitializeEx(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, u32 miscFlags);

// On TWL the wireless function can be disabled in the system settings
#define WM_CHECK_TWL_WIRELESS() \
    if (OS_IsRunOnTwl()) { \
        if (!func_0201fd30()) { \
            return WM_ERRCODE_WM_DISABLE; \
        } \
    }

#define WM_CHECK_RESULT(res) \
    if ((res) != WM_ERRCODE_SUCCESS) { \
        return (res); \
    }

// Other SDK functions used here
static inline u32 OS_GetVBlankCount(void) {
    return *(vu32 *)0x02fffc3c;
}

BOOL OS_IsRunOnTwl(void);
void OS_GetMacAddress(u8 *macAddress);
void PXI_Init(void);
void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL autoStart);

#ifdef __cplusplus
}
#endif

#endif
