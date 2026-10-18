#ifndef MAIN_NET_WH_H
#define MAIN_NET_WH_H

#include "types.h"
#include "Main/Res/ResMgr.h"

#ifdef __cplusplus
extern "C" {
#endif

// Wireless helper (based on the NitroSDK "wh" sample library), kept in one heap block.

typedef struct WhScanParam {
    /* 0x00 */ void *scanBuf;
    /* 0x04 */ u16 channel;
    /* 0x06 */ u16 maxChannelTime;
    /* 0x08 */ u16 bssid[3];
    /* 0x0e */ u16 unk_0e[9];
} WhScanParam; // size 0x20

typedef struct WhParentParam {
    /* 0x00 */ void *userGameInfo;
    /* 0x04 */ u16 userGameInfoLength;
    /* 0x06 */ u16 padding;
    /* 0x08 */ u32 ggid;
    /* 0x0c */ u16 tgid;
    /* 0x0e */ u16 entryFlag;
    /* 0x10 */ u16 maxEntry;
    /* 0x12 */ u16 multiBootFlag;
    /* 0x14 */ u16 KS_Flag;
    /* 0x16 */ u16 CS_Flag;
    /* 0x18 */ u16 beaconPeriod;
    /* 0x1a */ u16 rsv1[12];
    /* 0x32 */ u16 channel;
    /* 0x34 */ u16 parentMaxSize;
    /* 0x36 */ u16 childMaxSize;
    /* 0x38 */ u16 rsv[4];
} WhParentParam; // size 0x40

typedef struct WhConfig {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 maxChildren;
    /* 0x06 */ u16 dsDataSize;
    /* 0x08 */ u16 parentSize;
    /* 0x0a */ u16 childSize;
    /* 0x0c */ u16 mpFreq;
    /* 0x0e */ u16 unk_0e;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 dsPort;
    /* 0x14 */ u16 doubleMode;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ u32 parentRecvSize;
    /* 0x1c */ u32 parentSendSize;
    /* 0x20 */ u32 childRecvSize;
    /* 0x24 */ u32 childSendSize;
} WhConfig; // size 0x28

typedef struct WhMgr {
    union {
        u32 flags;
        struct {
            /* 0x0000 */ u32 initialized : 1;
            /* 0x0000 */ u32 busy : 1;
            /* 0x0000 */ u32 unk_00_2 : 30;
        };
    };
    /* 0x0004 */ WhConfig cfg;
    /* 0x002c */ int sysState;
    /* 0x0030 */ u16 unk_30;
    /* 0x0032 */ u16 childBitmap;
    /* 0x0034 */ int errCode;
    /* 0x0038 */ int connectMode;
    /* 0x003c */ u8 unk_3c;
    /* 0x003e */ u16 channel;
    /* 0x0040 */ u16 bestBusyRatio;
    /* 0x0042 */ u16 channelBitmap;
    /* 0x0044 */ u16 scanChannel;
    /* 0x0046 */ u16 unk_46;
    /* 0x0048 */ void *recvBufRaw;
    /* 0x004c */ void *recvBuf;
    /* 0x0050 */ u32 recvSize;
    /* 0x0054 */ void *sendBufRaw;
    /* 0x0058 */ void *sendBuf;
    /* 0x005c */ u32 sendSize;
    /* 0x0060 */ u8 unk_60[0x18];
    /* 0x0078 */ void (*indicateCb)(void *arg);
    /* 0x007c */ void (*resultCb)(BOOL ok);
    /* 0x0080 */ u32 unk_80;
    /* 0x0084 */ u32 unk_84;
    /* 0x0088 */ u32 unk_88;
    /* 0x008c */ BOOL (*judgeCb)(void *arg);
    /* 0x0090 */ void (*portCb)(void *arg);
    /* 0x0094 */ u8 unk_94[0xc];
    /* 0x00a0 */ u8 wmBuf[0xf00];
    /* 0x0fa0 */ u8 bssDesc[0xc0];
    /* 0x1060 */ WhScanParam scanParam;
    /* 0x1080 */ WhParentParam parentParam;
    /* 0x10c0 */ u8 dsInfo[0x820];
    /* 0x18e0 */ u8 unk_18e0[0x200];
} WhMgr; // size 0x1ae0

extern WhMgr *data_02097e40;


extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *ptr);
extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_02016e28(void *dst, u32 value, u32 size);
extern int func_0201fd58(void (*cb)(void *arg));
extern u32 func_0201ffb0(void);
extern int func_02020080(void);
extern u16 func_02020114(void);
extern int func_0202021c(void *buf, void (*cb)(void *arg), u16 dmaNo);
extern int func_02020294(void (*cb)(void *arg));
extern int func_020202d0(void (*cb)(void *arg));
extern int func_02020314(void (*cb)(void *arg), WhParentParam *param);
extern int func_020204d8(void (*cb)(void *arg));
extern int func_020204e8(void (*cb)(void *arg));
extern int func_0202052c(void (*cb)(void *arg), WhScanParam *param);
extern int func_02020768(void (*cb)(void *arg), u16 aid);
extern int func_020209d8(void (*cb)(void *arg), void *recvBuf, u16 recvSize, void *sendBuf, u16 sendSize, u16 freq);
extern int func_02020b78(void (*cb)(void *arg));
extern int func_02020bf0(void *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode);
extern int func_02020e30(void *dsInfo);
extern int func_02021740(void (*cb)(void *arg), void *info, u16 length, u32 ggid, u16 tgid, u8 attr);
extern int func_02021804(void (*cb)(void *arg), u16 a, u16 b, u16 channel, u16 time);
extern int func_02021880(void (*cb)(void *arg));
extern u32 func_0204045c(void);

typedef struct WhCbArg {
    /* 0x00 */ u16 apiid;
    /* 0x02 */ u16 errcode;
    /* 0x04 */ u16 state;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0a */ u16 unk_0a;
    /* 0x0c */ u16 unk_0c[2];
    /* 0x10 */ u16 aid;
} WhCbArg;

static inline void WH_SetError(int code) {
    WhMgr *wh = data_02097e40;
    if (wh->sysState != 8 && wh->sysState != 9) {
        wh->errCode = code;
    }
}

static inline void WH_ChangeSysState(int state) {
    data_02097e40->sysState = state;
}

static inline BOOL WH_CheckResult(int result) {
    if (result != 2) {
        WH_SetError(result);
        return FALSE;
    }
    return TRUE;
}

static inline void WH_CalcBufferSizes(WhConfig *cfg) {
    cfg->parentRecvSize = (((cfg->childSize + 0xe) * cfg->maxChildren + 0x29) & ~0x1f) << 1;
    cfg->parentSendSize = (cfg->parentSize + 0x23) & ~0x1f;
    cfg->childRecvSize = ((cfg->parentSize + 0x55) & ~0x1f) << 1;
    cfg->childSendSize = (cfg->childSize + 0x21) & ~0x1f;
}

void func_02044fc0(WhCbArg *arg);
void func_02044a80(void);
extern void func_0201a98c(u8 *macAddr);
void func_02045004(WhCbArg *arg);
void func_02045530(WhCbArg *arg);
void func_02044cb8(WhMgr *wh);
void func_02045d98(void *arg);
u16 func_02045674(WhMgr *wh, u16 channel);
void func_02045770(WhCbArg *arg);
void func_02045ab4(WhCbArg *arg);
void func_02045b68(WhCbArg *arg);
void func_02045d58(WhCbArg *arg);
void func_02045ef8(WhCbArg *arg);
void func_020461e4(WhCbArg *arg);
void func_020468d0(WhCbArg *arg);

extern void DC_InvalidateRange(const void *addr, u32 size);
extern void func_02016fa0(const void *src, void *dst, u32 size);
extern void DC_FlushRange(const void *addr, u32 size);
extern void func_020192b8(void);
extern int func_02020638(void (*cb)(void *arg));
extern int func_0202067c(void (*cb)(void *arg), void *bssDesc, void *ssl, BOOL powerSave, int authMode);
extern int func_02020e7c(void *dsInfo, const void *data, void *recv);
extern void *func_020216bc(void *dsInfo, void *recv, u16 aid);
void func_02046418(WhCbArg *arg);
void func_020465c8(WhCbArg *arg);
void func_02046774(WhCbArg *arg);
void func_020467b4(WhCbArg *arg);
BOOL func_020460d0(WhMgr *wh);
void func_02045094(WhMgr *wh);

static inline BOOL WH_StateInReset(void) {
    WH_ChangeSysState(3);
    return WH_CheckResult(func_02020294((void (*)(void *))func_02045530));
}

static inline void WH_Reset(WhMgr *wh, void (*cb)(BOOL)) {
    wh->resultCb = cb;
    if (wh->sysState == 5) {
        int result = func_02020e30(wh->dsInfo);
        if (result != 0) {
            WH_SetError(result);
        }
    }
    if (!WH_StateInReset()) {
        WH_ChangeSysState(9);
    }
}

static inline BOOL WH_Destroy(WhMgr *wh) {
    void *heap;
    if (wh == NULL) {
        return TRUE;
    }
    if ((wh->busy == TRUE ? TRUE : FALSE)) {
        return FALSE;
    }
    if (wh->sysState != 0) {
        WhMgr *w = data_02097e40;
        w->busy = TRUE;
        WH_Reset(w, (void (*)(BOOL))func_02044a80);
        return FALSE;
    }
    heap = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    wh = data_02097e40;
    if (wh != NULL) {
        if (wh != NULL) {
            if (wh->recvBufRaw != NULL) {
                func_0203df0c(wh->recvBufRaw);
                wh->recvBufRaw = NULL;
            }
            if (wh->sendBufRaw != NULL) {
                func_0203df0c(wh->sendBufRaw);
                wh->sendBufRaw = NULL;
            }
            func_0203de1c(wh);
        }
        data_02097e40 = NULL;
    }
    data_02097dd0->cur = heap;
    return TRUE;
}

static inline BOOL WH_IsStopped(WhMgr *wh) {
    if (wh == NULL) {
        return TRUE;
    }
    return (wh->sysState == 0 ? TRUE : FALSE) ? TRUE : FALSE;
}

typedef struct WhScanCbArg {
    /* 0x00 */ u16 apiid;
    /* 0x02 */ u16 errcode;
    /* 0x04 */ u16 wlCmdID;
    /* 0x06 */ u16 wlResult;
    /* 0x08 */ u16 state;
    /* 0x0a */ u8 unk_0a[0x2c];
    /* 0x36 */ u16 gameInfoLength;
    /* 0x38 */ u16 magicNumber;
    /* 0x3a */ u16 ver;
    /* 0x3c */ u32 ggid;
    /* 0x40 */ u16 tgid;
    /* 0x42 */ u8 userGameInfoLength;
    /* 0x43 */ u8 attribute;
} WhScanCbArg;


#ifdef __cplusplus
}
#endif

#endif
