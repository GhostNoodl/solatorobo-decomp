#ifndef NNSYS_SND_SNDARC_STREAM_H
#define NNSYS_SND_SNDARC_STREAM_H

#include "nnsys/fnd/list.h"
#include "nnsys/snd/sndarc.h"

#ifdef __cplusplus
extern "C" {
#endif

// NitroSystem sound archive stream player (NNS_SndArcStrm*).

typedef struct StrmHeader {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ u8 format;
    /* 0x19 */ u8 loop;
    /* 0x1a */ u8 channels;
    /* 0x1b */ u8 unk_1b;
    /* 0x1c */ u16 sampleRate;
    /* 0x1e */ u16 timer;
    /* 0x20 */ u8 unk_20[0x20];
} StrmHeader; // size 0x40

struct StrmHandle;

typedef struct StrmPlayer {
    /* 0x000 */ u8 strm[0x64];
    /* 0x064 */ u8 file[0x48];
    /* 0x0ac */ u32 fileOffset;
    /* 0x0b0 */ StrmHeader header;
    /* 0x0f0 */ SndFader fader;
    /* 0x100 */ u8 unk_100[0x18];
    /* 0x118 */ BOOL active : 1;
    /* 0x118 */ BOOL playing : 1;
    /* 0x118 */ BOOL startReq : 1;
    /* 0x118 */ BOOL stopReq : 1;
    /* 0x118 */ BOOL unk_118_4 : 1;
    /* 0x118 */ BOOL unk_118_5 : 1;
    /* 0x118 */ BOOL mono : 1;
    /* 0x11c */ int unk_11c;
    /* 0x120 */ volatile int unk_120;
    /* 0x124 */ int cmdCount;
    /* 0x128 */ int chRefCount;
    /* 0x12c */ u8 chNum;
    /* 0x12d */ u8 unk_12d;
    /* 0x12e */ u8 chList[6];
    /* 0x134 */ void *buffer;
    /* 0x138 */ u32 bufSize;
    /* 0x13c */ u32 unk_13c;
    /* 0x140 */ u32 unk_140;
    /* 0x144 */ BOOL (*callback)(u32 *arg0, u32 *arg1, u32 a, u32 b);
    /* 0x148 */ u32 callbackArg;
    /* 0x14c */ u32 strmNo;
    /* 0x150 */ int playerNo;
    /* 0x154 */ struct StrmHandle *handle;
    /* 0x158 */ int prio;
    /* 0x15c */ int volume;
    /* 0x160 */ int userVolume;
    /* 0x164 */ int curVolume;
    /* 0x168 */ u32 startOffset;
    /* 0x16c */ BOOL (*openFn)(struct StrmPlayer *player, u32 fileId);
    /* 0x170 */ void (*closeFn)(struct StrmPlayer *player);
    /* 0x174 */ u32 (*readFn)(struct StrmPlayer *player, void *buf, u32 size, u32 offset);
    /* 0x178 */ void (*stopFn)(struct StrmPlayer *player);
} StrmPlayer; // size 0x17c

typedef struct StrmHandle {
    /* 0x0 */ StrmPlayer *volatile player;
} StrmHandle;

typedef struct StrmCommand {
    /* 0x00 */ NNSFndLink link;
    /* 0x08 */ StrmPlayer *player;
    /* 0x0c */ int unk_0c;
    /* 0x10 */ int numBuffers;
    /* 0x14 */ void *buffers[6];
    /* 0x2c */ u32 size;
} StrmCommand; // size 0x30

typedef struct StrmThread {
    /* 0x0000 */ u8 thread[0xc0];
    /* 0x00c0 */ u8 stack[0x1000];
    /* 0x10c0 */ void *queueHead;
    /* 0x10c4 */ void *queueTail;
    /* 0x10c8 */ u8 mutex[0x18];
    /* 0x10e0 */ NNSFndList cmdList;
} StrmThread; // size 0x10ec

typedef struct StrmGlobals {
    /* 0x0 */ BOOL initialized;
    /* 0x4 */ StrmThread *altThread;
    /* 0x8 */ void *unk_8;
} StrmGlobals;

extern StrmGlobals data_0209622c;
extern NNSFndList data_02096238;
extern u8 data_02096244[0x18];
extern StrmCommand data_0209625c[8];
extern u8 data_020963e0[];
extern StrmPlayer data_020965e0[4];
extern StrmThread data_02096bd0;
extern u8 data_02097c98[0x18];
extern NNSFndList data_02097cb0;
extern const s16 data_02075210[];

extern u32 func_0201a7f0(void);
extern void func_0201a804(u32 state);
extern void func_02018fa8(void *mutex);
extern void func_02018fcc(void *mutex);
extern void func_0201901c(void *mutex);
extern void func_020184ac(void *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern void func_02018918(void *thread);
extern void func_020188b0(void *queue);
extern void func_02018860(void *queue);
extern void *func_02021d80(NNSFndList *list, void *object);
extern void func_02016fa0(const void *src, void *dst, u32 size);
extern void func_02016e28(void *dst, u32 value, u32 size);
extern void func_0200ed00(void *file);
extern void func_0202f480(void *strm);
extern BOOL func_0202f4f4(void *strm, int chNum, u8 *chList);
extern void func_0202f550(void *strm);
extern BOOL func_0202f578(void *strm, int format, void *buffer, u32 bufSize, u32 timer, int interval, void *callback, void *arg);
extern void func_0202f718(void *strm);
extern void func_0202f76c(void *strm);
extern void func_0202f788(void *strm, int volume);
extern void func_0202f7f4(void *strm, int ch, int pan);

typedef struct StrmCbInfo {
    /* 0x0 */ int playerNo;
    /* 0x4 */ u32 strmNo;
} StrmCbInfo;

typedef struct StrmCbNext {
    /* 0x0 */ u32 strmNo;
    /* 0x4 */ u32 offset;
} StrmCbNext;

typedef struct FSFileID {
    /* 0x0 */ void *arc;
    /* 0x4 */ u32 fileId;
} FSFileID;

extern FSFileID func_02030478(void);
extern void *func_020304dc(void);
extern u32 func_020304f0(void);
extern u32 func_02030504(void);
extern BOOL func_0200ee40(void *file, FSFileID id);
extern BOOL func_0200ee98(void *file, void *arc, u32 mode);
extern BOOL func_0200ef30(void *file, u32 top, u32 bottom);
extern BOOL func_0200ef1c(void *file);
extern BOOL func_0200f00c(void *file, int offset, int origin);
extern int func_0200f038(void *file, void *buf, u32 size);
extern BOOL func_0200ed2c(void *file);
extern void func_0203244c(StrmCommand *cmd);

void func_020316c0(u32 prio, GroupHeap *heap);
BOOL func_020317c4(GroupHeap *heap);
BOOL func_0203188c(StrmHandle *handle, int strmNo, u32 offset);
void func_020318e8(StrmHandle *handle);
BOOL func_02031904(StrmHandle *handle, int strmNo, u32 offset);
void func_0203192c(StrmHandle *handle, int frames);
void func_02031948(StrmHandle *handle, int volume);
void func_0203195c(StrmHandle *handle, int volume, int frames);
void func_02031990(StrmHandle *handle);
void func_0203199c(StrmHandle *handle);
void func_020319b4(void);
StrmThread *func_02031ac0(void);
StrmPlayer *func_02031acc(StrmHandle *handle, int playerNo, int prio);
void func_02031b58(StrmPlayer *player);
BOOL func_02031b84(StrmHandle *handle, NNSSndArcStrmInfo *info, int playerNo, int prio, u32 strmNo, u32 offset, u32 a6, u32 a7, void *a8, u32 a9);
void func_02031df0(StrmPlayer *player, int frames);
void func_02031e48(StrmPlayer *player);
void func_02031ee0(StrmPlayer *player);
BOOL func_02031f48(StrmPlayer *player, int chNum, u8 *chList);
void func_02031f80(StrmPlayer *player);
void func_02031fa4(StrmThread *thread, u32 prio);
void func_0203200c(NNSFndList *list, StrmPlayer *player);
StrmCommand *func_0203207c(NNSFndList *list);
StrmCommand *func_020320cc(void);
void func_02032110(StrmCommand *cmd);
void func_0203213c(void *data, u32 size, u32 arg0, u32 arg1);
void func_020321d4(int status, int numBuffers, void **buffers, u32 size, int format, void *arg);
void func_02032310(StrmPlayer *player);
void func_02032c54(StrmPlayer *player, u32 fileId);
BOOL func_02032cbc(StrmPlayer *player, u32 fileId);
void func_02032db4(StrmPlayer *player);
u32 func_02032dc4(StrmPlayer *player, void *buf, u32 size, u32 offset);
void func_02032dfc(StrmPlayer *player);
BOOL func_02032e0c(StrmPlayer *player, u32 fileId);
void func_02032e34(StrmPlayer *player);
u32 func_02032e38(StrmPlayer *player, void *buf, u32 size, u32 offset);
void func_02032e54(StrmPlayer *player);
void func_02032e58(void *arg);

#ifdef __cplusplus
}
#endif

#endif
