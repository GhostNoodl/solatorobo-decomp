#define SND_DEFINE_GLOBALS
#include "Main/Snd/SndMgr.h"
#include "Main/Res/ResMgr.h"

extern "C" {

SndQueue *data_02097e48;
SndMgr *data_02097e4c;
#define SND_QUEUE data_02097e48
#define SND_MGR data_02097e4c

extern void *func_0203dd9c(u32 size);
extern void *func_0203dec8(u32 size, int align);
extern SndMgr *func_020492e0(SndMgr *mgr);
extern void func_02049344(SndMgr *mgr);
void func_0204a3b8(SndMgr *mgr, struct SndCmd *cmd);
void func_0204a924(SndQueue *queue);

typedef struct SndCmd {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 type;
    /* 0x4 */ s16 args[6];
} SndCmd;

void func_0204a87c(void) {
    if (SND_MGR == NULL) {
        SndMgr *mgr;
        data_02097dd0->cur = data_02097dd0->unk_04;
        mgr = (SndMgr *)func_0203dd9c(sizeof(SndMgr));
        if (mgr != NULL) {
            mgr = func_020492e0(mgr);
        }
        SND_MGR = mgr;
        data_02097dd0->cur = data_02097dd0->unk_08;
        func_02049344(SND_MGR);
    }
    if (SND_QUEUE == NULL) {
        SND_QUEUE = (SndQueue *)func_0203dec8(sizeof(SndQueue), 4);
        func_0204a924(SND_QUEUE);
    }
}

void func_0204a904(void) {
    NNS_SndPlayerStopSeqAll(0);
    func_0204a924(SND_QUEUE);
}

static inline void SndQueue_Reset(SndQueue *queue) {
    s32 i;
    queue->nodes[0].prev = &queue->nodes[1];
    queue->nodes[0].value = 0xffff;
    queue->nodes[0].next = &queue->nodes[SND_QUEUE_NODES - 1];
    for (i = 1; i < SND_QUEUE_NODES - 1; i++) {
        queue->nodes[i].value = 0xffff;
        queue->nodes[i].next = &queue->nodes[i - 1];
        queue->nodes[i].prev = &queue->nodes[i + 1];
    }
    queue->nodes[i].value = 0xffff;
    queue->nodes[i].next = &queue->nodes[i - 1];
    queue->nodes[i].prev = &queue->nodes[0];
    queue->cur = &queue->nodes[0];
}

void func_0204a924(SndQueue *queue);

void func_0204aa10(SndQueue *queue);

void func_0204aa90(SndQueue *queue);

void func_0204aab0(SndQueue *queue, u16 value);

u16 func_0204aac4(SndQueue *queue);

void func_0204aad0(SndQueue *queue);

void func_0204aaec(SndQueue *queue, SndCmd *cmd);

void func_0204ab54(SndQueue *queue);

}

extern "C" {

extern void NNS_SndMain(void);

static inline void SndQueue_Push(SndQueue *queue, u16 value) {
    queue->cur = queue->cur->prev;
    queue->cur->value = value;
}

void func_0204ab8c(SndQueue *queue);

}
