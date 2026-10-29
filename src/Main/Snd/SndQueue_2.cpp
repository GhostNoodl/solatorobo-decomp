#include "Main/Snd/SndMgr.h"
#include "Main/Res/ResMgr.h"

extern "C" {

#define SND_QUEUE data_02097e48.queue
#define SND_MGR data_02097e48.mgr

extern void *func_0203dd9c(u32 size);
extern void *func_0203dec8(u32 size, int align);
extern void *func_020492e0(SndMgr *mgr);
extern void func_02049344(SndMgr *mgr);
void func_0204a3b8(SndMgr *mgr, struct SndCmd *cmd);

typedef struct SndCmd {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 type;
    /* 0x4 */ s16 args[6];
} SndCmd;

void func_0204a87c(void);

void func_0204a904(void);

// The neighbour links are byte offsets from the node array: the target computes i * 12 once
// and adds -12 and +12 to it.
static inline void SndQueue_ResetNodes(SndQueue *queue) {
    int i;
    queue->nodes[0].value = 0xffff;
    queue->nodes[0].next = &queue->nodes[SND_QUEUE_NODES - 1];
    queue->nodes[0].prev = &queue->nodes[1];
    for (i = 1; i < SND_QUEUE_NODES - 1; i++) {
        u32 off = i * sizeof(SndQueueNode);
        queue->nodes[i].value = 0xffff;
        queue->nodes[i].next = (SndQueueNode *)((u8 *)queue->nodes + (off - sizeof(SndQueueNode)));
        queue->nodes[i].prev = (SndQueueNode *)((u8 *)queue->nodes + (off + sizeof(SndQueueNode)));
    }
    queue->nodes[i].value = 0xffff;
    queue->nodes[i].next = &queue->nodes[i - 1];
    queue->nodes[i].prev = &queue->nodes[0];
    queue->cur = &queue->nodes[0];
}

void func_0204a924(SndQueue *queue) {
    queue->flag0 = 1;
    queue->flag1 = 0;
    queue->flag2 = 0;
    queue->flag3 = 1;
    queue->unk_02 = 0;
    queue->unk_04 = 0xffff;
    queue->unk_06 = 0xffff;
    queue->unk_08 = 10;
    queue->unk_70 = 0;
    queue->unk_7c = 0;
    queue->unk_72 = 0xffff;
    queue->unk_74 = 0xffff;
    queue->unk_78 = -1;
    queue->unk_7e = 0xffff;
    queue->unk_80 = 0xffff;
    SndQueue_ResetNodes(queue);
}

void func_0204aa10(SndQueue *queue) {
    SndQueue_ResetNodes(queue);
}

void func_0204aa90(SndQueue *queue) {
    queue->cur->value = 0xffff;
    queue->cur = queue->cur->next;
}

void func_0204aab0(SndQueue *queue, u16 value) {
    queue->cur = queue->cur->prev;
    queue->cur->value = value;
}

u16 func_0204aac4(SndQueue *queue) {
    return queue->cur->value;
}

void func_0204aad0(SndQueue *queue) {
    SndMgr *mgr = SND_MGR;
    mgr->seqArcNext = 0;
    mgr->unk_9c = 0;
}

void func_0204aaec(SndQueue *queue, SndCmd *cmd) {
    switch (cmd->type) {
        case 0:
            if (!queue->flag0) {
                return;
            }
            queue->unk_04 = cmd->args[0];
            break;
        case 1:
        case 3:
            if (!queue->flag3) {
                return;
            }
            queue->unk_04 = 0xffff;
            break;
    }
    func_0204a3b8(SND_MGR, cmd);
}

void func_0204ab54(SndQueue *queue) {
    s32 i;
    SndMgr *mgr = SND_MGR;
    for (i = 0; i < 5; i++) {
        NNS_SndPlayerStopSeq(&mgr->seqArc[i], 0);
    }
}

}

extern "C" {

extern void NNS_SndMain(void);

static inline void SndQueue_Push(SndQueue *queue, u16 value) {
    queue->cur = queue->cur->prev;
    queue->cur->value = value;
}

void func_0204ab8c(SndQueue *queue) {
    NNS_SndMain();
    if (queue->unk_06 != 0xffff) {
        switch (queue->unk_02) {
            case 10:
                if (queue->flag1 == 1) {
                    break;
                }
                queue->unk_04 = queue->unk_06;
                queue->unk_06 = 0xffff;
                SndMgr_PlayBgm(SND_MGR, queue->unk_04);
                break;
            case 0:
                if (queue->unk_04 != 0xffff) {
                    NNS_SndPlayerStopSeqBySeqNo(queue->unk_04, queue->unk_08);
                    SndQueue_Push(queue, queue->unk_04);
                    queue->unk_04 = 0xffff;
                    queue->unk_02 = queue->unk_02 + 1;
                } else {
                    SndQueue_Push(queue, 0xffff);
                    queue->unk_02 = 10;
                }
                if (queue->unk_06 == 0x8000) {
                    queue->unk_06 = 0xffff;
                    queue->unk_02 = 0;
                }
                break;
            default:
                queue->unk_02++;
                break;
        }
    }
    if (queue->unk_74 != 0xffff) {
        switch (queue->unk_70) {
            case 10:
                if (queue->flag1 == 1) {
                    break;
                }
                queue->unk_72 = queue->unk_74;
                queue->unk_74 = 0xffff;
                queue->unk_78 = func_02049afc(SND_MGR, queue->unk_72);
                break;
            case 0:
                if (queue->unk_72 != 0xffff) {
                    SndMgr_StopSlot(SND_MGR, queue->unk_78);
                    queue->unk_72 = 0xffff;
                    queue->unk_78 = -1;
                    queue->unk_70 = queue->unk_70 + 1;
                } else {
                    queue->unk_70 = 10;
                }
                if (queue->unk_74 == 0x8000) {
                    queue->unk_74 = 0xffff;
                    queue->unk_78 = -1;
                    queue->unk_70 = 0;
                }
                break;
            default:
                queue->unk_70++;
                break;
        }
    }
    if (queue->unk_80 != 0xffff) {
        switch (queue->unk_7c) {
            case 10:
                if (queue->flag1 == 1) {
                    break;
                }
                queue->unk_7e = queue->unk_80;
                queue->unk_80 = 0xffff;
                func_0204a20c(SND_MGR, queue->unk_7e);
                SndMgr_SetStrmVolume(SND_MGR, 0x32, 0);
                break;
            case 0:
                if (queue->unk_7e != 0xffff) {
                    SndMgr_StopStrm(SND_MGR);
                    queue->unk_7e = 0xffff;
                    queue->unk_7c = queue->unk_7c + 1;
                } else {
                    queue->unk_7c = 10;
                }
                if (queue->unk_80 == 0x8000) {
                    queue->unk_80 = 0xffff;
                    queue->unk_7c = 0;
                }
                break;
            default:
                queue->unk_7c++;
                break;
        }
    }
}

}
