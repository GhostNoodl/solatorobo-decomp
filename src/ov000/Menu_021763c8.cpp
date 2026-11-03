// ov000 task-list and Menu translation unit: .text 0x02172f7c..0x021814dc, the task list's .bss
// (0x021ccd34..0x021ccd50) and the Menu string pool (.data 0x021cba18..0x021cbac0). The former
// files are kept as they were, each in its own namespace, so that their local typedefs, inlines
// and extern declarations do not clash.
#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MessageQueue.h"
#include "ov000/VObj.h"
#include "ov000/TaskList.h"
#include "ov000/MenuTask.h"
#include "Main/Res/StageFlags.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Gfx/SlideWin.h"
#include "Main/Gfx/GfxMgr.h"
#include "types.h"
#include "ov000/ModelPart.h"
#include "nitro/fx.h"
#include "ov000/HeapScope.h"
#include "Main/Sys/Pad.h"
#include "ov000/Actor.h"
#include "ov000/UiObj.h"
#include "Main/Save/GameSave.h"

extern "C" {

// The TU's .bss. Every function here reaches these through the 0x021ccd34 pool literal plus an
// offset; other TUs name 021ccd34, 021ccd38, 021ccd40 and 021ccd44 directly. The first function
// (Task_Exit) already reads 021ccd34/3c/40/44 through the pool, so those are defined
// before it, together with 021ccd35 and 021ccd38, which lie between them. Objects defined before
// a TU's first function are not laid out in definition order; this order gives the ROM layout.
// The shop script and the save-object factory (021ccd48, 021ccd4c) are defined after Task_Exit.
s32 data_ov000_021ccd38;         // id of the last task that finished
u8 data_ov000_021ccd34;          // a task switch is pending
void *data_ov000_021ccd3c;       // task list, sorted by priority (linked through +0x38)
s8 data_ov000_021ccd35;          // users of the shop script
void *data_ov000_021ccd40;       // task that is finishing (its id is at +0x14)
TaskHost *data_ov000_021ccd44;   // task host

}

#define LO_FREE_VAR(var)                              \
    do {                                              \
        u32 saved;                                    \
        LO_HEAP_PUSH(saved);                          \
        if ((var) != NULL) {                          \
            VObj *p_ = (var);                         \
            if (p_ != NULL) {                         \
                p_->vfunc_04();                       \
            }                                         \
            (var) = NULL;                             \
        }                                             \
        LO_HEAP_POP(saved);                           \
    } while (0)

static inline Task *LoFindTask(s32 kind) {
    Task *t;
    for (t = (Task *)data_ov000_021ccd3c; t != NULL; t = t->next) {
        if (t->id == kind) {
            return t;
        }
    }
    return NULL;
}

static inline Task *LoSwitchTaskC(s32 kind, s32 c) {
    TaskHost *cur = data_ov000_021ccd44;
    s32 st;
    data_ov000_021ccd34 = 1;
    cur->task = LoFindTask(kind);
    if (cur->task == NULL) {
        LoCreateFn fn = data_ov000_021c9c6c[kind];
        cur->task = fn != NULL ? (Task *)fn() : NULL;
        cur->task->param = c;
        cur->task->parent = (Task *)data_ov000_021ccd40;
        st = 1;
    } else {
        st = 2;
    }
    if (cur->task != NULL) {
        cur->mode = st;
    }
    return cur->task;
}

static inline void LoResumeTask(s32 kind) {
    TaskHost *cur = data_ov000_021ccd44;
    Task *t;
    data_ov000_021ccd34 = 1;
    t = LoFindTask(kind);
    if (t != NULL) {
        t->vfunc_50();
        t->unk_04 |= 6;
        cur->mode = 2;
    }
}

static inline Task *LoSwitchTask(s32 kind) {
    return LoSwitchTaskC(kind, 0);
}

static inline VObj *LoTaskObj(void) {
    return &data_ov000_021ccd44->res;
}

// ---- Lo_02172f7c
namespace m_Lo_02172f7c {

extern "C" {

static inline TaskHost *GetCur02172f7c(void) {
    return data_ov000_021ccd44;
}

void Task_Exit(Task *self, void *arg) {
    BOOL fl = FALSE;
    if (self->unk_04_7 == 1) {
        fl = TRUE;
    }
    self->unk_04 |= 4;
    if (self->parent != NULL) {
        LoSwitchTaskC(self->parent->id, 0);
        self->parent->pendingId = (s32)arg;
    } else if (arg == NULL) {
        s32 kind = self->id;
        TaskHost *cur = GetCur02172f7c();
        data_ov000_021ccd34 = 1;
        arg = LoFindTask(kind);
        if (arg != NULL) {
            ((Task *)arg)->vfunc_50();
            ((Task *)arg)->unk_04 |= 6;
            cur->mode = 2;
        }
    } else {
        LoSwitchTaskC((s32)arg, 0);
        fl = FALSE;
    }
    if (fl) {
        data_ov000_021ccd34 = 1;
        data_ov000_021ccd44->unk_00_0 = 1;
    }
    self->parent = NULL;
}

}

}  // namespace m_Lo_02172f7c

extern "C" {

VObj *data_ov000_021ccd48;       // shop script
LoCreateFn data_ov000_021ccd4c;  // save-object factory (func_ov000_021761a0 / func_ov000_02176208)

}

// ---- Lo_021731a0
struct LoTimedBufferDtorSelf : public TimedBuffer {
    ListBuffer *unk_30;
};

namespace m_Lo_021731a0 {

extern "C" {

extern u8 data_ov000_021cb920[];
extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb9b0[];
void Heap_FreeHi(void *p);

static inline void LoListBufferDtor(ListBuffer *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb6d0);
    if ((self->flags & 0x20) && self->unk_0c != 0) {
        Heap_FreeHi((void *)self->unk_0c);
    }
    self->flags = 0;
    self->priority = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->prev = NULL;
    self->next = NULL;
}

static inline void LoMQRemove(MessageQueue *self, ListBuffer *buf) {
    if (buf == NULL) {
        return;
    }
    BufferList_Remove(&self->list, buf);
    if (buf != NULL) {
        buf->vfunc_04();
    }
}

static inline void LoTimedBufferDtor(LoTimedBufferDtorSelf *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb920);
    if (self->unk_30 != NULL) {
        LoMQRemove((MessageQueue *)self->unk_0c, self->unk_30);
    }
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
    LoListBufferDtor(self);
}

static inline void LoMessageQueueDtor(MessageQueue *self) {
    ListBuffer *buf;
    u32 i;
    VOBJ_SET_VTABLE(self, data_ov000_021cb9b0);
    buf = self->list.head;
    if (buf != NULL) {
        do {
            ListBuffer *next = BufferList_Remove(&self->list, buf);
            if (buf->flags & 0x10) {
                u32 saved;
                LO_HEAP_PUSH(saved);
                if (buf != NULL) {
                    if (buf != NULL) {
                        buf->vfunc_04();
                    }
                }
                LO_HEAP_POP(saved);
            }
            buf = next;
        } while (buf != NULL);
    }
    self->unk_04 = 0;
    self->list.head = NULL;
    for (i = 0; i < MESSAGE_QUEUE_LEN; i++) {
        self->messages[i].id = -1;
    }
    self->readIndex = 0;
    self->writeIndex = 0;
}

void Task_Init(Task *self) {
    self->unk_04 = 0;
    self->state = 0;
    self->param = 0;
    self->priority = 0;
    self->id = 0;
    self->pendingId = 0;
    self->fadeCur = 0;
    self->fadeLen = 0xc000;
    self->fadeRatio = 0;
    self->fadeSin = 0;
    self->parent = 0;
    self->callback = 0;
    self->prev = 0;
    self->next = 0;
}

}

}  // namespace m_Lo_021731a0

// ---- Stub_021731e4
namespace m_Stub_021731e4 {

extern "C" {

s32 Task_Release(VObj *self) {
    return self->vfunc_58();
}

}

}  // namespace m_Stub_021731e4

// ---- Lo_021731f8
namespace m_Lo_021731f8 {

extern "C" {

extern u8 data_ov000_021cb920[];
extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb9b0[];
void Heap_FreeHi(void *p);

static inline void LoListBufferDtor(ListBuffer *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb6d0);
    if ((self->flags & 0x20) && self->unk_0c != 0) {
        Heap_FreeHi((void *)self->unk_0c);
    }
    self->flags = 0;
    self->priority = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->prev = NULL;
    self->next = NULL;
}

static inline void LoMQRemove(MessageQueue *self, ListBuffer *buf) {
    if (buf == NULL) {
        return;
    }
    BufferList_Remove(&self->list, buf);
    if (buf != NULL) {
        buf->vfunc_04();
    }
}

static inline void LoTimedBufferDtor(LoTimedBufferDtorSelf *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb920);
    if (self->unk_30 != NULL) {
        LoMQRemove((MessageQueue *)self->unk_0c, self->unk_30);
    }
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
    LoListBufferDtor((ListBuffer *)self);
}

static inline void LoMessageQueueDtor(MessageQueue *self) {
    ListBuffer *buf;
    u32 i;
    VOBJ_SET_VTABLE(self, data_ov000_021cb9b0);
    buf = self->list.head;
    if (buf != NULL) {
        do {
            ListBuffer *next = BufferList_Remove(&self->list, buf);
            if (buf->flags & 0x10) {
                u32 saved;
                LO_HEAP_PUSH(saved);
                if (buf != NULL) {
                    if (buf != NULL) {
                        buf->vfunc_04();
                    }
                }
                LO_HEAP_POP(saved);
            }
            buf = next;
        } while (buf != NULL);
    }
    self->unk_04 = 0;
    self->list.head = NULL;
    for (i = 0; i < MESSAGE_QUEUE_LEN; i++) {
        self->messages[i].id = -1;
    }
    self->readIndex = 0;
    self->writeIndex = 0;
}

void Task_SwitchTo(void *self, s32 kind) {
    LoSwitchTask(kind);
}

}

}  // namespace m_Lo_021731f8

// ---- Fade_021732a8
namespace m_Fade_021732a8 {

extern "C" {

s32 FX_Div(s32 a, s32 b);

static inline BOOL Fade_IsOff(Task *self) {
    return self->unk_04_0 == 0 ? TRUE : FALSE;
}

static inline BOOL Fade_IsIdle(Task *self) {
    BOOL r = FALSE;
    if (data_ov000_021ccd34 == 0 && Fade_IsOff(self)) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Fade_IsReady(Task *self) {
    BOOL r = FALSE;
    if (Fade_IsIdle(self) && self->vfunc_54()) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Fade_CanShow(Task *self) {
    BOOL r = FALSE;
    if (Fade_IsReady(self) && !self->unk_04_2) {
        r = TRUE;
    }
    return r;
}

void Task_Update(Task *self) {
    self->vfunc_6c();
    switch (self->state) {
    case 0:
        self->unk_04_6 = 0;
        self->unk_04_5 = self->unk_04_6;
        if (!self->unk_04_1) {
            if (self->vfunc_1c()) {
                self->state = 8;
            }
        }
        break;
    case 8:
        self->unk_04_0 = 1;
        self->state = 9;
    case 9:
        self->fadeCur += 0x1000;
        self->fadeRatio = FX_Div(self->fadeCur, self->fadeLen);
        if (self->fadeRatio >= 0x1000) {
            self->fadeCur = self->fadeLen;
            self->fadeRatio = 0x1000;
            self->state = 12;
        }
        break;
    case 10:
        self->unk_04_0 = 1;
        self->state = 11;
    case 11:
        self->fadeCur -= 0x1000;
        self->fadeRatio = FX_Div(self->fadeCur, self->fadeLen);
        if (self->fadeRatio <= 0) {
            self->fadeCur = 0;
            self->fadeRatio = 0;
            if (self->vfunc_4c()) {
                self->state = 0;
            }
        }
        break;
    case 12:
        self->unk_04_0 = 0;
        self->state = 13;
    case 13:
        self->fadeCur = self->fadeLen;
        self->fadeRatio = 0x1000;
        if (self->unk_04_1) {
            self->unk_04_0 = 1;
            self->state = 10;
        }
        break;
    }
    if (self->pendingId != 0 && self->vfunc_54()) {
        self->vfunc_60(self->pendingId, 0);
        self->pendingId = 0;
    }
    if (Fade_CanShow(self)) {
        self->vfunc_64();
    }
    self->vfunc_70();
}

}

}  // namespace m_Fade_021732a8

// ---- TaskList_02173528
namespace m_TaskList_02173528 {

extern "C" {

void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

void Task_PreUpdate(void) {
}

BOOL Task_TryReleaseCurrent(Task *self) {
    if (self->vfunc_54()) {
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd38 = ((Task *)data_ov000_021ccd40)->id;
        } else {
            data_ov000_021ccd38 = 0;
        }
        data_ov000_021ccd40 = NULL;
    }
    return TRUE;
}

void Task_UpdateActive(void) {
}

void Task_PostUpdate(void) {
}

void Task_Draw(Task *self) {
    VecFx32 scale;
    Gfx3D_SendDL(data_02097d48->unk_8b0, 0);
    scale.x = 0x1000;
    scale.y = 0x1000;
    scale.z = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
    self->fadeSin = FX_SinCosTable_[((self->fadeRatio << 14) >> 16) * 2];
}

}

}  // namespace m_TaskList_02173528

// ---- TaskList_021735e8
namespace m_TaskList_021735e8 {

typedef struct {
    u8 unk_00[0x54];
    Task *unk_54;
} Data021ccd30Sub;

typedef struct {
    u8 unk_00[0x11c];
    Data021ccd30Sub *unk_11c;
} Data021ccd30;

extern "C" {
extern Data021ccd30 *data_ov000_021ccd30;
}

extern "C" {

bool TaskList_HasTasks_021735e8(void) {
    return TaskList_HasTasks();
}

Task *Task_FindById(s32 id) {
    Task *task;
    for (task = (Task *)data_ov000_021ccd3c; task != NULL; task = task->next) {
        if (task->id == id) {
            return task;
        }
    }
    return NULL;
}

void TaskList_Insert(Task *task) {
    Task *cur = (Task *)data_ov000_021ccd3c;
    Task *prev;
    if (cur == NULL) {
        data_ov000_021ccd3c = task;
    } else {
        prev = NULL;
        while (cur != NULL) {
            if (task->priority < cur->priority) {
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL) {
            task->prev = prev;
            task->next = NULL;
            prev->next = task;
        } else {
            task->prev = cur->prev;
            task->next = cur;
            cur->prev = task;
            if (task->prev != NULL) {
                task->prev->next = task;
            } else {
                data_ov000_021ccd3c = task;
            }
        }
    }
    task->vfunc_20();
}

void func_ov000_021736dc(void) {
    Task *task = (Task *)data_ov000_021ccd3c;
    Task *next;
    void *saved;
    if (task != NULL) {
        do {
            next = task->next;
            saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->heapHi;
            if (task != NULL) {
                if (task != NULL) {
                    task->vfunc_04();
                }
            }
            data_02097dd0->cur = saved;
            task = next;
        } while (task != NULL);
    }
    data_ov000_021ccd34 = 0;
    data_ov000_021ccd3c = NULL;
    data_ov000_021ccd40 = NULL;
}

VObj *Task_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

#pragma force_active on
void func_ov000_02173784(void) {
    Task *task = (Task *)data_ov000_021ccd3c;
    void *saved;
    Task *next;
    if (task == NULL) {
        return;
    }
    do {
        next = task->next;
        if (task->unk_04_2) {
            if (task->prev != NULL) {
                task->prev->next = next;
            } else {
                data_ov000_021ccd3c = next;
            }
            if (task->next != NULL) {
                task->next->prev = task->prev;
            }
            task->prev = NULL;
            task->next = NULL;
            saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->heapHi;
            if (task != NULL) {
                if (task != NULL) {
                    task->vfunc_04();
                }
            }
            data_02097dd0->cur = saved;
        }
        task = next;
    } while (task != NULL);
}
#pragma force_active reset

VObj *Task021cbce0_New(void) {
    Task021cbce0 *obj = (Task021cbce0 *)Heap_Alloc(0x90);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbce0);
        obj->vfunc_58();
    }
    obj->vfunc_08(1, 0);
    return obj;
}

void Task021cbce0_Load(void *a) {
    func_ov000_0214c1ac();
}

BOOL Task021cbce0_IsReady(void) {
    Task *task = data_ov000_021ccd30->unk_11c->unk_54;
    BOOL ret = TRUE;
    if (task != NULL && !(*(s32 *)((u8 *)task + 4) == 4 ? TRUE : FALSE)) {
        ret = FALSE;
    }
    return ret;
}

}

}  // namespace m_TaskList_021735e8

// ---- Lo_021738d4
namespace m_Lo_021738d4 {

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern void *data_0208cca0;
extern void *data_0208ccc0;
void *Heap_Alloc(u32 size);
void TexObj_Init(void *p, void *name, s32 c);
void *ResMgr_GetArcList(void *a);
void *ResList_FindType2(void *a, void *b);
void TexObj_SetRes(void *model, void *a);
void TexObj_SelectImage(void *model, s32 a, s32 b);
void func_02041c20(void *model, s32 a, void *b);
void *STD_CopyString(void *dst, void *src);
void func_ov000_02173d9c(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx);
void TaskList_Insert(VObj *self);

static inline void Init(u8 *m, void *s, void *nm) {
    PlttRes_Init_02041218((struct PlttRes *)(m + 0x88));
    TexObj_Init(m, nm, 0);
    STD_CopyString(m + 0x2c, s);
}

void Task021cbce0_Start(Task021cbce0 *self) {
    void *res;
    u8 *m;
    self->unk_04 &= ~2;
    if (self->vfunc_28() != 0) {
        return;
    }
    res = ResList_FindType2(ResMgr_GetArcList(data_0208cca0), data_0208ccc0);
    m = (u8 *)Heap_Alloc(0x160);
    if (m) {
        Init(m, data_0208cca0, data_0208ccc0);
    }
    self->unk_4c = (Model *)m;
    TexObj_SetRes(m, res);
    self->unk_4c->flags |= 2;
    TexObj_SelectImage(self->unk_4c, 0, 0);
    self->unk_4c->unk_158 = (void *)func_ov000_02173d9c;
    func_02041c20(self->unk_4c, 0, self);
    self->unk_3c = -0xcd;
    TaskList_Insert(self);
}

}

}  // namespace m_Lo_021738d4

// ---- TaskList_021739c4
namespace m_TaskList_021739c4 {

extern "C" {

void MTX_Identity44_(void *a);

void Task021cbce0_Init(Task021cbce0 *self) {
    self->fadeLen = 0x10000;
    self->unk_3c = -0xcd;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = NULL;
    MTX_Identity44_(&self->unk_50);
}

void Task021cbce0_Release(Task021cbce0 *self) {
    void *saved;
    Model *model;
    func_ov000_0214c210();
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    model = self->unk_4c;
    if (model != NULL) {
        if (model != NULL) {
            TexObj_Release(model);
            PlttRes_Release(&model->pltt);
            Heap_Free(model);
        }
        self->unk_4c = NULL;
    }
    data_02097dd0->cur = saved;
}

}

}  // namespace m_TaskList_021739c4

// ---- Task_02173a5c
namespace m_Task_02173a5c {

typedef struct {
    u8 pad[0xe];
    u8 b0 : 2;
    u8 b2 : 2;
    u8 b4 : 4;
} Player02173a5c;

extern "C" {

extern Task *(*const data_ov000_021c9c6c[])(void);
extern void *data_02097e4c;
extern Player02173a5c *data_ov000_021ccd54;
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
void SndMgr_PauseAll(void *a);
void SndMgr_ResumeAll(void *a);
void Gfx3DState_Apply(void *p);

static inline Task *TaskList_Find(s32 id) {
    Task *task;
    for (task = (Task *)data_ov000_021ccd3c; task != NULL; task = task->next) {
        if (task->id == id) {
            return task;
        }
    }
    return NULL;
}

static inline void TaskList_Start(s32 id, s32 arg) {
    TaskHost *h = data_ov000_021ccd44;
    s32 mode;
    data_ov000_021ccd34 = 1;
    h->task = TaskList_Find(id);
    if (h->task == NULL) {
        Task *(*fn)(void) = data_ov000_021c9c6c[id];
        h->task = fn != NULL ? fn() : NULL;
        h->task->param = arg;
        h->task->parent = (Task *)data_ov000_021ccd40;
        mode = 1;
    } else {
        mode = 2;
    }
    if (h->task != NULL) {
        h->mode = mode;
    }
}

void Task021cbce0_PreUpdate(Task021cbce0 *self) {
    switch (self->state) {
    case 8:
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        SndMgr_PauseAll(data_02097e4c);
        break;
    case 10:
        self->unk_3c = -0xcd;
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        SndMgr_ResumeAll(data_02097e4c);
        Gfx3DState_Apply(data_02097d48->unk_8b0);
        data_ov000_021ccd54->b2 = 0;
        break;
    case 12:
        self->unk_3c = (s32)0xfffe019a;
        data_ov000_021ccd54->b2 = 2;
        TaskList_Start(2, 0);
        self->vfunc_48();
        break;
    }
}

}

}  // namespace m_Task_02173a5c

// ---- Obj_02173bec
namespace m_Obj_02173bec {

extern "C" {

void Task021cbce0_PostUpdate(Task021cbce0 *self) {
    if (self->state != 0xd) {
        return;
    }
    self->unk_40 += 0x8000;
    self->unk_44 += 0x8000;
    if (self->unk_40 >= 0x1000000) {
        self->unk_40 -= 0x1000000;
    }
    if (self->unk_44 >= 0x1000000) {
        self->unk_44 -= 0x1000000;
    }
}

}

}  // namespace m_Obj_02173bec

// ---- Obj_02173c30
namespace m_Obj_02173c30 {

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
extern const s16 FX_SinCosTable_[];
void Gfx3D_SendDL(void *obj, int a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline Task *FindTask(s32 kind) {
    Task *t;
    for (t = (Task *)data_ov000_021ccd3c; t != NULL; t = t->next) {
        if (t->id == kind) {
            return t;
        }
    }
    return NULL;
}

void Task021cbce0_Draw(Task021cbce0 *self) {
    if (self->fadeRatio == 0) {
        return;
    }
    if (FindTask(0x1a) != NULL) {
        return;
    }
    Gfx3D_SendDL(data_02097d48->unk_8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    self->fadeSin = FX_SinCosTable_[((s32)(self->fadeRatio << 14) >> 16) * 2];
    {
        s32 c = self->unk_3c;
        Model_SetPos(self->unk_4c, 0, LO_FX_MUL(0x1000 - FX_SinCosTable_[((s32)(self->fadeRatio << 14) >> 16) * 2], -0xc0000));
        self->unk_4c->unk_150 = c;
    }
    Model_PlayPart(self->unk_4c, 0);
}

}

}  // namespace m_Obj_02173c30

// ---- Lo_02173d9c
namespace m_Lo_02173d9c {

typedef struct {
    u32 y : 8;
    u32 attr0hi : 8;
    u32 x : 9;
    u32 attr1hi : 7;
    u32 charName : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 attr3 : 16;
} Oam02173d9c;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} ImgAttr02173d9c;

typedef struct {
    u8 pad[0x40];
    s32 x;
    s32 y;
} Ctx02173d9c;

extern "C" {

extern u32 data_ov000_021c9c08[];
void Oam_GetSize(const Oam02173d9c *attr, u32 *w, u32 *h);
void NNS_G3dGeBufferOP_N(u32 op, const u32 *args, u32 num);

#define REG_TEXIMAGE_PARAM (*(vu32 *)0x40004a8)
#define REG_TEXPLTT_BASE (*(vu32 *)0x40004ac)

static inline void G3_Cmd1(u32 cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline void G3_Vec(u32 cmd, u32 x, u32 y, u32 z) {
    u32 v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd2(u32 cmd, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(cmd, v, 2);
}

// ctx is read through a const view of the stack parameter: that read is not copy-propagated to
// c's uses, so ctx is loaded where c is set, as in the target.
void func_ov000_02173d9c(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const Oam02173d9c *oam,
                         const ImgAttr02173d9c *img, u32 charBase, u32 plttBase, s32 unused2, const Ctx02173d9c *ctx) {
    const Ctx02173d9c *c;
    s32 px;
    u32 pal;
    u32 h;
    s32 py;
    u32 w;
    s32 shift;
    u32 fmt;
    u16 charName;

    c = *(const Ctx02173d9c *const *)&ctx;
    charName = (u16)oam->charName;
    shift = ((s32)(img->mappingType & 0x700000) >> 20) + 5;
    Oam_GetSize(oam, &w, &h);
    REG_TEXIMAGE_PARAM = ((charBase + (charName << shift)) >> 3) | (img->fmt << 26) | 0x40000000 | (w << 20) |
                         (h << 23) | 0x30000 | (img->plttUse << 29);
    fmt = data_ov000_021c9c08[(*(u32 *)oam << 18) >> 31];
    if (img->bExtendedPlt != 0) {
        pal = (u16)oam->pal << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->pal << 5;
    }
    REG_TEXPLTT_BASE = (plttBase + pal) >> (4 - (fmt == 2));
    px = c->x & ~0xfff;
    py = c->y & ~0xfff;
    G3_Cmd1(0x10, 3);
    G3_Vec(0x1c, px, py, 0);
    G3_Cmd1(0x10, 2);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x - 0x80000, y - 0x60000, z);
    G3_Vec(0x1b, 0x100000, 0xc0000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_Cmd1(0x20, 0x2214);
    G3_Cmd1(0x22, 0xc000000);
    G3_Cmd2(0x23, 0x10000000, 0);
    G3_Cmd1(0x22, 0xc001000);
    G3_Cmd1(0x25, 0x10001000);
    G3_Cmd1(0x20, 0x7fff);
    G3_Cmd1(0x22, 0x1000);
    G3_Cmd1(0x25, 0x1000);
    G3_Cmd1(0x22, 0);
    G3_Cmd1(0x25, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}

}

}  // namespace m_Lo_02173d9c
#undef REG_TEXIMAGE_PARAM
#undef REG_TEXPLTT_BASE

// ---- Lo_021740b0
namespace m_Lo_021740b0 {

extern "C" {

extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbbe0[];
extern u8 data_0208ba70[];
extern const s16 FX_SinCosTable_[];
void TextWin_Init(void *p);
void GfxSys_StartFadeOut(s32 a, s32 b, s32 c);
s32 FX_Div(s32 a, s32 b);
void Gfx3D_SendDL(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_ov000_0217558c(void *self);

VObj *Task021cbbe0_New(void) {
    Task021cbbe0 *obj = (Task021cbbe0 *)Heap_Alloc(0x4b0);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbbe0);
        VOBJ_SET_VTABLE((u8 *)obj + 0x60, data_0208ba70);
        TextWin_Init((u8 *)obj + 0x60);
        VOBJ_SET_VTABLE((u8 *)obj + 0x118, data_0208ba70);
        TextWin_Init((u8 *)obj + 0x118);
        VOBJ_SET_VTABLE((u8 *)obj + 0x1d0, data_0208ba70);
        TextWin_Init((u8 *)obj + 0x1d0);
        VOBJ_SET_VTABLE((u8 *)obj + 0x288, data_0208ba70);
        TextWin_Init((u8 *)obj + 0x288);
        VOBJ_SET_VTABLE((u8 *)obj + 0x340, data_0208ba70);
        TextWin_Init((u8 *)obj + 0x340);
        VOBJ_SET_VTABLE((u8 *)obj + 0x3f8, data_0208ba70);
        TextWin_Init((u8 *)obj + 0x3f8);
        obj->vfunc_58();
    }
    obj->vfunc_08(2, 100);
    return obj;
}

}

}  // namespace m_Lo_021740b0

// ---- Lo_02174168
namespace m_Lo_02174168 {

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 22;
} Glyph02174168;

extern "C" {

struct Lo02174168 {
    u8 unk_00[0x70];
    u32 unk_70;
};

Glyph02174168 *func_ov000_02174168(Lo02174168 *self, u16 *cmd, Glyph02174168 *arr, u16 *count) {
    u16 n = *count;
    Glyph02174168 *last = &arr[n - 1];
    if (*cmd == 6) {
        u32 base;
        u32 v;
        BOOL started;
        s32 x;
        u32 div;
        s32 digits;
        s32 i;
        u32 d;
        digits = LFLD(s32, cmd, 0x8);
        started = FALSE;
        x = started;
        n = started;
        base = last->chr;
        v = self->unk_70;
        div = 1;
        for (i = started; i < digits - 1; i++) {
            div *= 10;
        }
        if (v >= div * 10) {
            v = div * 10 - 1;
        }
        for (; digits != 0; digits--) {
            d = v / div;
            if ((digits == 1 && !started) || started || d != 0) {
                arr[n].x = (u16)x;
                arr[n].a = 0;
                arr[n].chr = base - d;
                n++;
                started = TRUE;
            }
            v -= d * div;
            div /= 10;
            x += 7;
        }
    }
    *count = n;
    return arr;
}

}

}  // namespace m_Lo_02174168

// ---- Obj_021742b4
namespace m_Obj_021742b4 {

typedef struct {
    u8 unk_00[0x4c];
    s32 unk_4c;
} Sub021742b4;

typedef struct {
    u8 unk_00[0x6];
    u16 unk_06;
    u8 unk_08[0x1c];
    s32 unk_24;
} Msg021742c8;

typedef struct {
    u32 unk_00;
    s32 unk_04;
    void *unk_08;
} Obj021742b4;

typedef struct {
    u8 unk_00[0x8];
    VObj unk_08;
} Sub02174380;

extern "C" {

extern void *data_02097e4c;

void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov000_0214c270(void);

void Task021cbbe0_List40OnState(Obj021742b4 *self) {
    Sub021742b4 *sub = (Sub021742b4 *)self->unk_08;
    if (self->unk_04 == 3) {
        sub->unk_4c = 1;
    }
}

BOOL Task021cbbe0_List40OnDecide(Obj021742b4 *self, Msg021742c8 *msg) {
    VObj *obj = (VObj *)self->unk_08;
    if (msg == NULL) {
        obj->vfunc_0c(0);
        return TRUE;
    }
    if (msg->unk_06 != 0xffff) {
        if (msg->unk_24 != 0xe) {
            obj->vfunc_60(msg->unk_06, 1);
            SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
        } else {
            SndMgr_PlayVolume(data_02097e4c, 0x20, -1, -1, -1);
        }
    } else {
        SndMgr_PlayVolume(data_02097e4c, 0x20, -1, -1, -1);
    }
    return TRUE;
}

}

}  // namespace m_Obj_021742b4

// ---- Obj_0217437c
namespace m_Obj_0217437c {

typedef struct {
    u8 unk_00[0x4c];
    s32 unk_4c;
} Sub021742b4;

typedef struct {
    u8 unk_00[0x6];
    u16 unk_06;
    u8 unk_08[0x1c];
    s32 unk_24;
} Msg021742c8;

typedef struct {
    u32 unk_00;
    s32 unk_04;
    void *unk_08;
} Obj021742b4;

typedef struct {
    u8 unk_00[0x8];
    VObj unk_08;
} Sub02174380;

extern "C" {

extern void *data_02097e4c;

void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov000_0214c270(void);

void Task021cbbe0_Load(void) {
}

BOOL Task021cbbe0_IsLoaded(void) {
    BOOL ret = TRUE;
    if (!data_ov000_021ccd44->res.vfunc_2c()) {
        ret = FALSE;
    }
    if (!func_ov000_0214c270()) {
        ret = FALSE;
    }
    return ret;
}

}

// Task021cbbe0_Start: the item search is written out with the caller's own locals (round bgL); as a
// static inline its objects are numbered below g and every callee-saved register rotates by one.
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Bits021743bc;

struct Glyph02174168;

// Item ids of the +0x40 list; the first item is also the default cursor position.
typedef enum {
    MENU021743BC_ITEM_TOP = 0x1a
} MenuItem021743bc;

class MenuList021743bc {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void Show();
    virtual void vf0c();
    virtual void SetTitleId(s32 id);
    virtual void SetTitle(const char *src);
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void *AddItem(const char *name, u16 id, u16 a, u32 b);
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void Select(void *e);
};

class MenuBox021743bc {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void Show();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void SetText(s32 b, const void *c);
};

extern "C" {
void *Heap_Alloc(u32 size);
void TaskList_Insert(void *self);
extern void *data_02149ef8;
extern void *data_02fe152c;
extern u8 *data_ov000_021ccd54;
extern u8 *data_02097ce0;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021ca94c[];
extern u8 data_0208ba70[];
extern u8 data_ov000_021c9c28[];
extern void *data_0208ccc8;
extern u8 data_ov000_021cba0c[];
extern void *data_0208cc94;
extern void *data_0208cc88;
extern s32 data_02097d78[];
void *MsgRes_GetString(void *g, s32 id);
void *UiList_GetItemById(void *p, u16 a);
u16 DataRes_ReadEntry(void *a, u32 b, s32 c, s32 d);
void *SceneStage_GetScript(void *a, u16 b);
void *DataRes_GetTable(void *a, u32 b);
u32 DataRes_GetCount(void *a, u32 b);
u16 DataRes_ReadBitsAt_02059544(void *a, void *b, void *c, s32 d, u16 e);
void *ResMgr_GetArcList(void *a);
void *ResList_FindType2(void *a, void *b);
void TexObj_Init(void *p, void *name, u8 c);
char *STD_CopyString(void *dst, void *src);
void TexObj_SetRes(void *model, void *a);
void TexObj_SelectImage(void *model, s32 a, u32 b);
void func_02041c5c(void *model, int fn);
void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, const char *c, s32 *d, s32 *e, bool f);
void TextWin_RenderToVram(void *p);
void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);
void Task021cbbe0_List40OnState(Obj021742b4 *self);
BOOL Task021cbbe0_List40OnDecide(Obj021742b4 *self, Msg021742c8 *msg);
struct Glyph02174168 *func_ov000_02174168(u8 *self, u16 *cmd, struct Glyph02174168 *arr, u16 *count);

static inline BOOL IsMode4_021743bc(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 4;
    }
    return r;
}

// p is a TextWin, used through casts: a TextWin * local or parameter changes the register use
#define W ((TextWin *)p)
static inline void InitWin021743bc(u8 *p, void *s) {
    ((VObj *)p)->vfunc_08();
    W->str = (u32)s;
    W->font = 4;
    W->unk_4c = Text_Measure(W->font, W->spacing, (const char *)W->str, (s32 *)(p + 0x44), (s32 *)(p + 0x48), *(s8 *)&W->unk_37 != 0); // &width, &height; unk_37 read signed
    LFLD(s32, data_02097ce0, 0x4) = W->font;
    W->flags |= 0x40;
    W->flags |= 0x41000000;
    W->unk_78 = 0x8000;
    W->color0 = 0x4fdf;
    W->color1 = 0x1e1e;
    W->flags |= 4;
    TextWin_RenderToVram(p);
    W->posZ = -0x1cad;
}
#undef W

void Task021cbbe0_Start(Task021cbbe0 *self) {
    void *sub;
    BOOL has;
    u16 i;
    void *g;
    void *a;
    u32 n;
    u8 *m2;
    VObj *o;
    u8 *m;
    void *res;
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    self->vfunc_3c();
    g = data_02149ef8;
    o = (VObj *)Heap_Alloc(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    self->unk_44 = (Lo021cb5a8 *)o;
    ((Lo021cb5a8 *)o)->flags |= 0x4000000;
    self->unk_44->slideMode = 1;
    {
        Lo021cb5a8 *s_0 = self->unk_44;
        s_0->slideX = 0x80;
        s_0->slideY = 0;
        s_0->slideZ = 0;
    }
    {
        Lo021cb5a8 *s_1 = self->unk_44;
        s_1->posX = 0;
        s_1->posY = 0x10;
        s_1->posZ = -0x1ccd;
    }
    self->unk_44->flags |= 0x20000000;
    ((MenuBox021743bc *)self->unk_44)->SetText(1, MsgRes_GetString(g, 0x32));
    ((MenuBox021743bc *)self->unk_44)->SetText(2, MsgRes_GetString(g, 0x33));
    ((MenuBox021743bc *)self->unk_44)->Show();
    o = (VObj *)Heap_Alloc(0xd4);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
    }
    self->unk_40 = (UiList *)o;
    ((MenuList021743bc *)self->unk_40)->SetTitleId((s32)MsgRes_GetString(g, 0xb8));
    ((MenuList021743bc *)self->unk_40)->SetTitle((const char *)MsgRes_GetString(g, 0xb9));
    self->unk_40->openLen = 0x6000;
    self->unk_40->owner = self;
    self->unk_40->width = 0x6c;
    self->unk_40->rows = 5;
    {
        UiList *s_2 = self->unk_40;
        s_2->posX = 0;
        s_2->posY = 0x14;
        s_2->posZ = -0x1ccd;
    }
    self->unk_40->flags &= ~0x20000;
    self->unk_40->flags &= ~0x40000;
    self->unk_40->flags &= ~0x10000;
    self->unk_40->onState = (UiStateFn)Task021cbbe0_List40OnState;
    self->unk_40->onDecide = (UiItemFn)Task021cbbe0_List40OnDecide;
    ((MenuList021743bc *)self->unk_40)->AddItem((const char *)MsgRes_GetString(g, 0xba), 0x1a, 0xffff, 0xffff);
    ((MenuList021743bc *)self->unk_40)->AddItem((const char *)MsgRes_GetString(g, 0xc2), 6, 0xffff, 0xffff);
    ((MenuList021743bc *)self->unk_40)->AddItem((const char *)MsgRes_GetString(g, 0x112), 0xf, 0xffff, 0xffff);
    ((MenuList021743bc *)self->unk_40)->AddItem((const char *)MsgRes_GetString(g, 0x118), 5, 0xffff, 0xffff);
    if (DataRes_ReadEntry(data_02fe152c, 5, 1, 0) == 0) {
        LFLD(s32, UiList_GetItemById(self->unk_40, 0x1a), 0x24) = 0xe;
    }
    if (SceneStage_GetScript(data_ov000_021ccd54 + 0xac, 0) == 0) {
        LFLD(s32, UiList_GetItemById(self->unk_40, 0xf), 0x24) = 0xe;
    }
    sub = LFLD(void *, data_02fe152c, 0x4c);
    a = DataRes_GetTable(data_02fe152c, 3);
    n = DataRes_GetCount(data_02fe152c, 3);
    for (i = 0; i < n; i++) {
        if (DataRes_ReadBitsAt_02059544(data_02fe152c, (u8 *)sub + 0x70, a, 1, i) != 0) {
            has = TRUE;
            goto found;
        }
    }
    has = FALSE;
found:
    if (!has) {
        LFLD(s32, UiList_GetItemById(self->unk_40, 5), 0x24) = 0xe;
    }
    {
        MenuList021743bc *t = (MenuList021743bc *)self->unk_40;
        if (data_ov000_021ccd38 == 0) {
            MenuItem021743bc id = MENU021743BC_ITEM_TOP;
            t->Select(UiList_GetItemById(t, id));
        } else {
            t->Select(UiList_GetItemById(t, (u16)data_ov000_021ccd38));
        }
    }
    ((MenuList021743bc *)self->unk_40)->Show();
    {
        UiList *s_3 = self->unk_40;
        s_3->shape = (VecFx16 *)data_ov000_021c9c28;
        s_3->shapeCount = 5;
    }
    res = ResList_FindType2(ResMgr_GetArcList(data_0208ccc8), data_ov000_021cba0c);
    m = (u8 *)Heap_Alloc(0x160);
    if (m != NULL) {
        void *file = data_0208ccc8;
        void *nm = data_ov000_021cba0c;
        PlttRes_Init_02041218((struct PlttRes *)(m + 0x88));
        TexObj_Init(m, nm, 0);
        STD_CopyString(m + 0x2c, file);
    }
    self->unk_58 = (Model *)m;
    TexObj_SetRes(m, res);
    self->unk_58->flags |= 2;
    TexObj_SelectImage(self->unk_58, 0, 0xffff);
    self->unk_58->unk_150 = -0x1cbd;
    res = ResList_FindType2(ResMgr_GetArcList(data_0208cc94), data_0208cc88);
    m2 = (u8 *)Heap_Alloc(0x160);
    if (m2 != NULL) {
        void *file = data_0208cc94;
        void *nm = data_0208cc88;
        PlttRes_Init_02041218((struct PlttRes *)(m2 + 0x88));
        TexObj_Init(m2, nm, 0);
        STD_CopyString(m2 + 0x2c, file);
    }
    self->unk_5c = (Model *)m2;
    TexObj_SetRes(m2, res);
    self->unk_5c->flags |= 2;
    TexObj_SelectImage(self->unk_5c, 0, 6);
    TexObj_SelectImage(self->unk_5c, 0, 9);
    TexObj_SelectImage(self->unk_5c, 0, 0xa);
    self->unk_5c->flags |= 0x80000;
    self->unk_5c->flags = (self->unk_5c->flags & ~0x7c) | 0x78;
    self->unk_5c->unk_150 = -0x1c9d;
    func_02041c5c(self->unk_5c, (int)func_ov000_02174168);
    InitWin021743bc((u8 *)self + 0x60, MsgRes_GetString(g, 0xba));
    InitWin021743bc((u8 *)self + 0x118, MsgRes_GetString(g, 0x48));
    InitWin021743bc((u8 *)self + 0x1d0, MsgRes_GetString(g, 0x49));
    InitWin021743bc((u8 *)self + 0x288, MsgRes_GetString(g, 0x4a));
    InitWin021743bc((u8 *)self + 0x340, MsgRes_GetString(g, 0x4b));
    InitWin021743bc((u8 *)self + 0x3f8, MsgRes_GetString(g, 0x4c));
    o = (VObj *)Heap_Alloc(0x21c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021ca94c;
        LFLD(void *, (UiObj *)o, 0x90) = data_0208ba70;
        TextWin_Init((u8 *)o + 0x90);
        LFLD(void *, (UiObj *)o, 0x148) = data_0208ba70;
        TextWin_Init((u8 *)o + 0x148);
        o->vfunc_28();
    }
    self->unk_48 = (UiObj *)o;
    o->vfunc_08();
    self->unk_48->flag4 = 0;
    self->unk_48->posZ = -0x1ccd;
    if (IsMode4_021743bc()) {
        GfxSys_StartFadeIn(self->fadeLen, 0, -1);
    }
    TaskList_Insert(self);
}

}

}  // namespace m_Obj_0217437c

// ---- Lo_02174ea0
namespace m_Lo_02174ea0 {

extern "C" {

extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbbe0[];
extern u8 data_0208ba70[];
extern const s16 FX_SinCosTable_[];
void TextWin_Init(void *p);
void GfxSys_StartFadeOut(s32 a, s32 b, s32 c);
s32 FX_Div(s32 a, s32 b);
void Gfx3D_SendDL(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_ov000_0217558c(Task021cbbe0 *self);

void Task021cbbe0_Init(Task021cbbe0 *self) {
    self->fadeLen = 0x10000;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = -1;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
}

void Task021cbbe0_Release(Task021cbbe0 *self) {
    VOBJ_AT(self, 0x60)->vfunc_08();
    VOBJ_AT(self, 0x118)->vfunc_08();
    VOBJ_AT(self, 0x1d0)->vfunc_08();
    VOBJ_AT(self, 0x288)->vfunc_08();
    VOBJ_AT(self, 0x340)->vfunc_08();
    VOBJ_AT(self, 0x3f8)->vfunc_08();
    LO_FREE_M(self, 0x58);
    LO_FREE_M(self, 0x5c);
    LO_FREE_V(self, 0x40);
    LO_FREE_V(self, 0x44);
    LO_FREE_V(self, 0x48);
}

void Task021cbbe0_SwitchTo(Task021cbbe0 *self, s32 kind) {
    switch (kind) {
    case 0x1a: {
        Task *t;
        t = LoSwitchTask(0x1a);
        t->parent = NULL;
        LFLD(s32, t, 0x3c) = self->id;
        self->vfunc_50();
        self->unk_04 |= 6;
        GfxSys_StartFadeOut(self->fadeLen, 2, -1);
        return;
    }
    case 0xf:
        LoSwitchTaskC(kind, 0xffff);
        return;
    case 7:
        data_0214a424->unk_009 = 0xff;
    default:
        LoSwitchTask(kind);
        break;
    }
}

}

}  // namespace m_Lo_02174ea0

// ---- Stub_021752cc
namespace m_Stub_021752cc {

extern "C" {

void Task021cbbe0_UpdateActive(Task021cbbe0 *self) {
    if (*(s32 *)((u8 *)self + 0x4c) == -1) {
        u8 *p = *(u8 **)((u8 *)self + 0x40);
        if (p != NULL) {
            *(u32 *)(p + 0xc) &= ~4;
        }
    }
}

}

}  // namespace m_Stub_021752cc

// ---- Lo_021752f0
namespace m_Lo_021752f0 {

extern "C" {

extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbbe0[];
extern u8 data_0208ba70[];
extern const s16 FX_SinCosTable_[];
void TextWin_Init(void *p);
void GfxSys_StartFadeOut(s32 a, s32 b, s32 c);
s32 FX_Div(s32 a, s32 b);
void Gfx3D_SendDL(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_ov000_0217558c(Task021cbbe0 *self);

void Task021cbbe0_PreUpdate(Task021cbbe0 *self) {
    switch (self->state) {
    case 8:
        self->parent = (Task *)LoFindTask(1);
        if ((void *)self->unk_40 != NULL) {
            self->unk_40->hidden = 0;
        }
        if ((void *)self->unk_44 != NULL) {
            self->unk_44->hidden = 0;
        }
        if ((void *)self->unk_48 != NULL) {
            self->unk_48->hidden = 0;
        }
        break;
    case 0xa:
        if (self->vfunc_54()) {
            self->unk_4c = 0;
        }
        break;
    }
}

void Task021cbbe0_PostUpdate(Task021cbbe0 *self) {
    s32 m = self->unk_4c;
    if (m == 1) {
        s32 v;
        self->unk_50 += 0x1000;
        v = FX_Div(self->unk_50, self->unk_40->openLen);
        self->unk_54 = v;
        if (v >= 0x1000) {
            self->unk_54 = 0x1000;
            self->unk_4c = -1;
        }
    } else if (m == 0) {
        s32 v;
        self->unk_50 -= 0x1000;
        v = FX_Div(self->unk_50, self->unk_40->openLen);
        self->unk_54 = v;
        if (v <= 0) {
            self->unk_54 = 0;
            self->unk_4c = -1;
            if ((void *)self->unk_40 != NULL) {
                self->unk_40->hidden = 1;
            }
            if ((void *)self->unk_44 != NULL) {
                self->unk_44->hidden = 1;
            }
            if ((void *)self->unk_48 != NULL) {
                self->unk_48->hidden = 1;
            }
        }
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_1c();
        self->unk_40->flag2 = 1;
    }
    if (self->unk_44 != NULL) {
        self->unk_44->vfunc_1c();
    }
    if (self->unk_48 != NULL) {
        self->unk_48->vfunc_1c();
    }
}

void Task021cbbe0_Draw(Task021cbbe0 *self) {
    s32 scale[3];
    if (self->fadeRatio == 0) {
        return;
    }
    Gfx3D_SendDL(data_02097d48->unk_8b0, 0);
    scale[0] = 0x1000;
    scale[1] = 0x1000;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    self->fadeSin = FX_SinCosTable_[((self->fadeRatio << 14) >> 16) * 2];
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
    if (self->unk_44 != NULL) {
        self->unk_44->vfunc_20();
    }
    func_ov000_0217558c(self);
    if (self->unk_48 != NULL) {
        self->unk_48->vfunc_20();
    }
}

}

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern const s16 FX_SinCosTable_[];
BOOL Model_IsReady(void *p, s32 id);
Robo021ca458 *ActorMgr_FindPlayer(void);
u8 Gfx3DState_NextPolyId(void *p);
void func_02041c20(Model *m, s32 a, s32 b);
void func_02041c18(Model *m, s32 v);
void func_ov000_021c95fc(void *p);

typedef struct {
    s16 a[5];
    s16 b[5];
} Counts;

static inline s32 Clamp99(s16 v) {
    if (v < 0) {
        v = 0;
    } else if (v > 99) {
        v = 99;
    }
    return v;
}

// The text windows embedded at 0x60 + 0xb8 * n are TextWins. Main/Gfx/TextWin.h clashes with
// LoCommon.h here, so this is its vtable up to Render (0x90). SetPos (0x20) and Render return void.
struct LoTextWin {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void unk_vf08();
    virtual void OnSkip();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20(int a, int b);
    virtual char *unk_vf24(char *p);
    virtual char *unk_vf28(char *p);
    virtual char *unk_vf2c(char *p);
    virtual char *unk_vf30(char *p);
    virtual char *unk_vf34(char *p);
    virtual char *unk_vf38(char *p);
    virtual char *unk_vf3c(char *p);
    virtual char *unk_vf40(char *p);
    virtual char *unk_vf44(char *p);
    virtual char *unk_vf48(char *p);
    virtual char *ParseEscape(char *p);
    virtual char *unk_vf50(char *p);
    virtual char *unk_vf54(char *p);
    virtual char *unk_vf58(char *p);
    virtual char *unk_vf5c(char *p);
    virtual char *unk_vf60(char *p);
    virtual char *unk_vf64(char *p);
    virtual char *unk_vf68(char *p);
    virtual char *unk_vf6c(char *p);
    virtual char *unk_vf70(char *p);
    virtual char *unk_vf74(char *p);
    virtual char *unk_vf78(char *p);
    virtual void unk_vf7c();
    virtual void unk_vf80();
    virtual void unk_vf84();
    virtual void unk_vf88();
    virtual void unk_vf8c();
    virtual void Render();
};

#define TEXT(off) ((LoTextWin *)((u8 *)self + (off)))

static inline void Model_PlayPartChk(Model *model, s32 idx) {
    ModelRes *res;
    ModelPart *part;
    void *anim;
    if (model->res == NULL) {
        return;
    }
    res = model->res;
    part = Model_GetPart(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    TexObj_DrawCell(model, anim, part, 0);
}

void func_ov000_0217558c(Task021cbbe0 *self) {
    Model *m;
    s32 x;
    u8 *g;
    s32 xi;
    Counts c;
    if ((void *)self->unk_40 == NULL || self->unk_58 == NULL) {
        return;
    }
    if (!Model_IsReady(self->unk_58, 0xffff)) {
        return;
    }
    if (!Model_IsReady(self->unk_5c, 0xffff)) {
        return;
    }
    x = (s32)(((s64)(0x1000 - FX_SinCosTable_[((s32)(self->unk_54 << 14) >> 16) * 2]) * 0x80000 + 0x800) >> 12);
    g = data_02097d48->unk_8b0;
    Model_SetPos((Model *)self->unk_58, x & ~0xfff, 0);
    m = (Model *)self->unk_58;
    Model_PlayPart(m, 1);
    ActorMgr_FindPlayer();
    MODEL_FLAGS(((Model *)self->unk_5c))->polygon_id = Gfx3DState_NextPolyId(g);
    xi = x >> 12;
    TEXT(0x60)->unk_vf20(xi + 0xc2 - (self->unk_a4 >> 1), 0x30);
    TEXT(0x60)->Render();
    TEXT(0x118)->unk_vf20(0x92 + xi, 0x3e);
    TEXT(0x118)->Render();
    TEXT(0x1d0)->unk_vf20(xi + 0x92, 0x4c);
    TEXT(0x1d0)->Render();
    TEXT(0x288)->unk_vf20(xi + 0x92, 0x5a);
    TEXT(0x288)->Render();
    TEXT(0x340)->unk_vf20(xi + 0x92, 0x68);
    TEXT(0x340)->Render();
    TEXT(0x3f8)->unk_vf20(xi + 0x92, 0x76);
    TEXT(0x3f8)->Render();
    func_02041c20(((Model *)self->unk_5c), 6, 2);
    x = xi + 0x5a;
    Model_SetPos(((Model *)self->unk_5c), x << 12, -0x18000);
    Model_PlayPart(((Model *)self->unk_5c), 9);
    Model_SetPos(((Model *)self->unk_5c), x << 12, -0xa000);
    Model_PlayPart(((Model *)self->unk_5c), 9);
    Model_SetPos(((Model *)self->unk_5c), x << 12, 0x4000);
    Model_PlayPart(((Model *)self->unk_5c), 9);
    Model_SetPos(((Model *)self->unk_5c), x << 12, 0x12000);
    Model_PlayPart(((Model *)self->unk_5c), 9);
    Model_SetPos(((Model *)self->unk_5c), x << 12, 0x20000);
    ((Model *)self->unk_5c)->x += 0x15000;
    Model_PlayPart(((Model *)self->unk_5c), 10);
    func_ov000_021c95fc(&c);
    func_02041c18(((Model *)self->unk_5c), (s8)Clamp99(c.a[0] + c.b[0]));
    Model_SetPos(((Model *)self->unk_5c), (x + 7) << 12, -0x21000);
    Model_PlayPartChk(((Model *)self->unk_5c), 6);
    func_02041c18(((Model *)self->unk_5c), (s8)Clamp99(c.a[1] + c.b[1]));
    Model_SetPos(((Model *)self->unk_5c), (x + 7) << 12, -0x13000);
    Model_PlayPartChk(((Model *)self->unk_5c), 6);
    func_02041c18(((Model *)self->unk_5c), (s8)Clamp99(c.a[2] + c.b[2]));
    Model_SetPos(((Model *)self->unk_5c), (x + 7) << 12, -0x5000);
    Model_PlayPartChk(((Model *)self->unk_5c), 6);
    func_02041c18(((Model *)self->unk_5c), (s8)Clamp99(c.a[3] + c.b[3]));
    Model_SetPos(((Model *)self->unk_5c), (x + 7) << 12, 0x9000);
    Model_PlayPartChk(((Model *)self->unk_5c), 6);
    func_02041c18(((Model *)self->unk_5c), (s8)Clamp99(c.a[4] + c.b[4]));
    Model_SetPos(((Model *)self->unk_5c), (x + 7) << 12, 0x17000);
    Model_PlayPartChk(((Model *)self->unk_5c), 6);
}

}

}  // namespace m_Lo_021752f0
#undef TEXT

// ---- Dtor_02175e04
namespace m_Dtor_02175e04 {

extern "C" {

extern u8 data_ov000_021cbfe0[];
extern u8 data_ov000_021cc060[];
void *Heap_Alloc(u32 size);

VObj *Task021cbfe0_New(void) {
    Task021cbfe0 *obj = (Task021cbfe0 *)Heap_Alloc(0x48);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbfe0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x3, 0x3e8);
    return obj;
}

}

}  // namespace m_Dtor_02175e04

// ---- Lo_02175e6c
namespace m_Lo_02175e6c {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0206f66c(void *p);
s32 Param_Get(void *p);
s32 func_0206f080(void *p);
s32 Param_GetValue(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd48)) {
        r = FALSE;
    }
    return r;
}


BOOL func_ov000_02175e6c(UiList *self, UiListItem *msg) {
    Task021cbfe0 *o = (Task021cbfe0 *)self->owner;
    s32 v;
    if (msg == NULL) {
        if (self->flags & 0x4000000) {
            SndMgr_PlayVolume(data_02097e4c, 0x20, -1, -1, -1);
            return TRUE;
        }
        v = 0xff;
    } else {
        v = msg->id;
    }
    o->unk_44 = v;
    if (o->callback(o, 2)) {
        SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
    } else {
        ((VObj *)o)->vfunc_0c(0);
        SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
    }
    return FALSE;
}

void Task021cbfe0_Start(Task021cbfe0 *self) {
    self->unk_04_1 = 0;
    if (self->vfunc_28()) {
        return;
    }
    self->callback(self, 0);
    TaskList_Insert(self);
}

}

}  // namespace m_Lo_02175e6c

// ---- Stub_02175f78
namespace m_Stub_02175f78 {

extern "C" {

void Task021cbfe0_Init(Task021cbfe0 *self) {
    *(s32 *)((u8 *)self + 0x20) = 0x1000;
    *(s32 *)((u8 *)self + 0x3c) = 0;
    *(s32 *)((u8 *)self + 0x40) = 0;
    *(s16 *)((u8 *)self + 0x44) = 0;
}

}

}  // namespace m_Stub_02175f78

// ---- Lo_02175f94
namespace m_Lo_02175f94 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0206f66c(void *p);
s32 Param_Get(void *p);
s32 func_0206f080(void *p);
s32 Param_GetValue(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd48)) {
        r = FALSE;
    }
    return r;
}

void Task021cbfe0_Release(Task021cbfe0 *self) {
    LO_FREE_V(self, 0x3c);
    LO_FREE_V(self, 0x40);
}

}

}  // namespace m_Lo_02175f94

// ---- Stub_02176028
namespace m_Stub_02176028 {

extern "C" {

void Task021cbfe0_UpdateActive(void) {
}

void Task021cbfe0_PreUpdate(void) {
}

}

}  // namespace m_Stub_02176028

// ---- Lo_02176030
namespace m_Lo_02176030 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0206f66c(void *p);
s32 Param_Get(void *p);
s32 func_0206f080(void *p);
s32 Param_GetValue(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd48)) {
        r = FALSE;
    }
    return r;
}

void Task021cbfe0_PostUpdate(Task021cbfe0 *self) {
    BOOL a = FALSE;
    BOOL b = a;
    if (self->unk_3c != NULL) {
        if (!self->unk_3c->vfunc_1c()) {
            LO_FREE_V(self, 0x3c);
        } else {
            a = TRUE;
        }
    }
    if (self->unk_40 != NULL) {
        if (!self->unk_40->vfunc_1c()) {
            u32 saved;
            LO_HEAP_PUSH(saved);
            if (self->unk_40 != NULL) {
                VObj *p = self->unk_40;
                if (p != NULL) {
                    p->vfunc_04();
                }
                self->unk_40 = NULL;
            }
            b = TRUE;
            LO_HEAP_POP(saved);
        } else {
            a = TRUE;
        }
    }
    if (self->unk_04_2) {
        return;
    }
    if (a) {
        self->callback(self, 3);
    }
    if (b) {
        self->callback(self, 1);
    }
}

void Task021cbfe0_Draw(Task021cbfe0 *self) {
    if (self->unk_3c != NULL) {
        self->unk_3c->vfunc_20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
}

GameSave *func_ov000_021761a0(void) {
    GameSave *obj = (GameSave *)Heap_Alloc(0x4c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b614);
        obj->Init();
        VOBJ_SET_VTABLE(obj, data_0208ca9c);
        obj->Init();
    }
    return obj;
}

}

}  // namespace m_Lo_02176030

// ---- Stub_021761f0
namespace m_Stub_021761f0 {

extern "C" {

GameSave *func_ov000_021761a0(void);

void func_ov000_021761f0(void *self) {
    data_ov000_021ccd4c = (LoCreateFn)func_ov000_021761a0;
}

}

}  // namespace m_Stub_021761f0

// ---- Lo_02176208
namespace m_Lo_02176208 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0206f66c(void *p);
s32 Param_Get(void *p);
s32 func_0206f080(void *p);
s32 Param_GetValue(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd48)) {
        r = FALSE;
    }
    return r;
}

GameSave *func_ov000_02176208(void) {
    GameSave *obj = (GameSave *)Heap_Alloc(0x4c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b614);
        obj->Init();
        VOBJ_SET_VTABLE(obj, data_0208ca9c);
        obj->Init();
        VOBJ_SET_VTABLE(obj, data_0208ca18);
    }
    return obj;
}

}

}  // namespace m_Lo_02176208

// ---- Stub_02176264
namespace m_Stub_02176264 {

extern "C" {

extern u8 data_ov000_021cbee0[];
extern u8 data_ov000_021cc060[];
GameSave *func_ov000_02176208(void);
void *Heap_Alloc(u32 size);

void func_ov000_02176264(void *self) {
    data_ov000_021ccd4c = (LoCreateFn)func_ov000_02176208;
}

VObj *Task021cbee0_New(void) {
    Task021cbee0 *obj = (Task021cbee0 *)Heap_Alloc(0x15c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbee0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x4, 0xc8);
    return obj;
}

}

}  // namespace m_Stub_02176264

// ---- Lo_021762e4
namespace m_Lo_021762e4 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0206f66c(void *p);
s32 Param_Get(void *p);
s32 func_0206f080(void *p);
s32 Param_GetValue(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd48)) {
        r = FALSE;
    }
    return r;
}

void func_ov000_021762e4(void *a, s32 mode) {
    Task *t = LoFindTask(4);
    VObj *m;
    void *r;
    if (mode == 1 && func_0206f66c(a)) {
        return;
    }
    m = LFLD(VObj *, t, 0x4c);
    r = (void *)m->vfunc_74(Param_Get(a), a, (u16)func_0206f080(a), Param_GetValue(a));
    if (mode == 1 && func_0206f66c(a)) {
        mode = 0;
        LFLD(s32, r, 0x10) = mode;
        LFLD(s32, r, 0xc) = -1;
        LFLD(s32, r, 0x24) = 0xe;
    }
    LFLD(s32, r, 0x10) = mode;
}

}

}  // namespace m_Lo_021762e4

namespace m_Lo_021763c8 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern void *data_02149ef8;
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
void StageRes_Init(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void StageRes_Open(void *p, void *buf, const void *s);
void *MsgRes_GetString(void *p, s32 a);
void Obj0215bb14_SetText(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 StageFlags_CountEntries(void *a, u16 b);
void Gfx3D_SendDL(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

void func_ov000_021763c8(void) {
    u8 buf[0x20];
    if (data_ov000_021ccd35 == 0) {
        VObj *obj;
        LO_FREE_VAR(data_ov000_021ccd48);
        obj = (VObj *)Heap_Alloc(0xc4);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_0208b318);
            obj->vfunc_08();
            VOBJ_SET_VTABLE(obj, data_0208bf54);
            StageRes_Init(obj);
        }
        data_ov000_021ccd48 = obj;
        STD_CopyString(buf, "script/");
        STD_ConcatenateString(buf, "shpinfo");
        StageRes_Open(data_ov000_021ccd48, buf, "shop.ccscp");
    }
    data_ov000_021ccd35 = data_ov000_021ccd35 + 1;
}

}

}  // namespace m_Lo_021763c8

// ---- Lo_021764c4
namespace m_Lo_021764c4 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0206f66c(void *p);
s32 Param_Get(void *p);
s32 func_0206f080(void *p);
s32 Param_GetValue(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd48)) {
        r = FALSE;
    }
    return r;
}

void func_ov000_021764c4(void) {
    data_ov000_021ccd35 = data_ov000_021ccd35 - 1;
    if (data_ov000_021ccd35 != 0) {
        return;
    }
    LO_FREE_VAR(data_ov000_021ccd48);
}

}

}  // namespace m_Lo_021764c4

// ---- Stub_02176538
namespace m_Stub_02176538 {

extern "C" {

extern u8 data_02fe1534[];
s32 StageRes_IsAllLoaded(void *p);
BOOL StageRes_Bind(void *p);

BOOL func_ov000_02176538(void) {
    BOOL result = TRUE;
    if (StageRes_IsAllLoaded(data_ov000_021ccd48) == 0) {
        result = FALSE;
    }
    return result;
}

void func_ov000_02176560(void) {
    if (data_ov000_021ccd48->vfunc_34() == 0) {
        StageRes_Bind(data_ov000_021ccd48);
    }
}

void func_ov000_02176590(s16 v) {
    *(s16 *)(data_02fe1534 + 0x7a) = v;
    data_ov000_021ccd48->vfunc_38(1);
    *(s16 *)(data_02fe1534 + 0x7a) = 0;
}
}

}  // namespace m_Stub_02176538

// ---- Lo_021765c8
namespace m_Lo_021765c8 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern void *data_02149ef8;
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
void StageRes_Init(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void StageRes_Open(void *p, void *buf, const void *s);
void *MsgRes_GetString(void *p, s32 a);
void Obj0215bb14_SetText(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 StageFlags_CountEntries(void *a, u16 b);
void Gfx3D_SendDL(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

void Task021cbee0_Load(void) {
    u8 buf[0x20];
    if (data_ov000_021ccd35 == 0) {
        VObj *obj;
        LO_FREE_VAR(data_ov000_021ccd48);
        obj = (VObj *)Heap_Alloc(0xc4);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_0208b318);
            obj->vfunc_08();
            VOBJ_SET_VTABLE(obj, data_0208bf54);
            StageRes_Init(obj);
        }
        data_ov000_021ccd48 = obj;
        STD_CopyString(buf, "script/");
        STD_ConcatenateString(buf, "shpinfo");
        StageRes_Open(data_ov000_021ccd48, buf, "shop.ccscp");
    }
    data_ov000_021ccd35 = data_ov000_021ccd35 + 1;
}

}

}  // namespace m_Lo_021765c8

// ---- Lo_021766c4
namespace m_Lo_021766c4 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0206f66c(void *p);
s32 Param_Get(void *p);
s32 func_0206f080(void *p);
s32 Param_GetValue(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd48)) {
        r = FALSE;
    }
    return r;
}

BOOL Task021cbee0_IsLoaded(void) {
    BOOL r = TRUE;
    if (!LoIsLoaded()) {
        r = FALSE;
    }
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}

}  // namespace m_Lo_021766c4

// ---- Lo_02176714
namespace m_Lo_02176714 {

typedef struct {
    u8 unk_00[0x7a];
    u16 unk_7a;
} Shared02fe1534;

extern "C" {
extern void *data_02149ef8;
extern void *data_02fe152c;
extern Shared02fe1534 data_02fe1534;
extern void *data_0208ccc8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cae48[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb2a8[];
void *MsgRes_GetString(void *g, u32 id);
BOOL StageRes_Bind(void *p);
void func_ov000_0215d980(void *a, s32 b, s32 c);
void Obj0215d990_SetMsg(void *self, s32 a);
void Obj0215bb14_SetText(void *o, void *s);
void UiList021cb4a8_SetLabel(void *self, void *a);
void UiList021cb4a8_SetCenteredLabel(void *self, void *arg);
void func_ov000_021546ec(void *a, const void *b, const char *c, u16 d);
s32 func_ov000_02184a04(s32 x);
u8 *DataRes_GetTable(void *a, s32 b);
u32 DataRes_GetCount(void *a, s32 b);
u16 DataRes_ReadBitsAt_02059544(void *a, void *b, void *c, int d, u16 e);
void *Param_Get(u32 id);
s32 func_0206f080(u32 id);
u32 Param_GetValue(u32 id);
BOOL Task021cbee0_List4cOnDecide(void);
s32 Task021cbee0_List4cOnCursor(void);

typedef struct { u16 a; u16 b; } Pair02176714;

void Task021cbee0_Start(Task021cbee0 *self) {
    void *g;
    VObj *o;
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    TaskList_Insert(self);
    if (!data_ov000_021ccd48->vfunc_34()) {
        StageRes_Bind(data_ov000_021ccd48);
    }
    g = data_02149ef8;
    o = (VObj *)Heap_Alloc(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    self->unk_3c = (Lo021cb5a8 *)o;
    ((Lo021cb5a8 *)o)->flags |= 0x4000000;
    self->unk_3c->slideMode = 1;
    {
        Lo021cb5a8 *s = self->unk_3c;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = 0;
    }
    {
        Lo021cb5a8 *s = self->unk_3c;
        s->posX = 0;
        s->posY = 0x11;
        s->posZ = -0x1ccd;
    }
    self->unk_3c->flags |= 0x20000000;
    self->unk_3c->vfunc_f4(1, MsgRes_GetString(g, 0x32));
    self->unk_3c->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_3c->vfunc_08();
    o = (VObj *)Heap_Alloc(0x98);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cae48;
        o->vfunc_28();
    }
    self->unk_40 = (Lo021cae48 *)o;
    ((Lo021cae48 *)o)->posX = 0x86;
    ((Lo021cae48 *)o)->posY = 0x78;
    ((Lo021cae48 *)o)->posZ = -0x1ccd;
    func_ov000_0215d980(self->unk_40, data_0214a424->unk_020, 0);
    self->unk_40->slideMode = 1;
    {
        Lo021cae48 *s = self->unk_40;
        s->slideX = 0x80;
        s->slideY = 0;
        s->slideZ = 0;
    }
    self->unk_40->vfunc_08();
    o = (VObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_50 = (Lo021cadcc *)o;
    ((Lo021cadcc *)o)->width = 0xf8;
    self->unk_50->rows = 2;
    {
        Lo021cadcc *s = self->unk_50;
        s->posX = 8;
        s->posY = 0x95;
        s->posZ = -0x1ccd;
    }
    self->unk_50->color = 0xb;
    self->unk_50->slideMode = 1;
    {
        Lo021cadcc *s = self->unk_50;
        s->slideX = 0;
        s->slideY = 0x40;
        s->slideZ = 0;
    }
    self->unk_50->vfunc_08();
    switch (func_ov000_02184a04(self->param)) {
    case 0:
        o = (VObj *)Heap_Alloc(0x98);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021cae48;
            o->vfunc_28();
        }
        self->unk_44 = (Lo021cae48 *)o;
        ((Lo021cae48 *)o)->style = 4;
        {
            Lo021cae48 *s = self->unk_44;
            s->posX = 0x1a;
            s->posY = 0x78;
            s->posZ = -0x1ccd;
        }
        func_ov000_0215d980(self->unk_44, 0, 0);
        self->unk_44->slideMode = 1;
        {
            Lo021cae48 *s = self->unk_44;
            s->slideX = 0x80;
            s->slideY = 0;
            s->slideZ = 0;
        }
        self->unk_44->vfunc_08();
        Obj0215d990_SetMsg(self->unk_44, 0x120);
        self->unk_44->width = 0x66;
        self->unk_44->height = 0x19;
        o = (VObj *)Heap_Alloc(0x98);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021cae48;
            o->vfunc_28();
        }
        self->unk_48 = (Lo021cae48 *)o;
        ((Lo021cae48 *)o)->style = 4;
        {
            Lo021cae48 *s = self->unk_48;
            s->posX = 0x1a;
            s->posY = 0x83;
            s->posZ = -0x1ccd;
        }
        func_ov000_0215d980(self->unk_48, 0, 0);
        self->unk_48->slideMode = 1;
        {
            Lo021cae48 *s = self->unk_48;
            s->slideX = 0x80;
            s->slideY = 0;
            s->slideZ = 0;
        }
        self->unk_48->vfunc_08();
        Obj0215d990_SetMsg(self->unk_48, 0x121);
        self->unk_48->width = 0x66;
        self->unk_48->height = 0;
        o = (VObj *)Heap_Alloc(0xe0);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021caec8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb4a8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb2a8;
        }
        self->unk_4c = (UiList021cb4a8 *)o;
        self->unk_4c->vfunc_10(MsgRes_GetString(g, 0x98));
        self->unk_4c->vfunc_14(MsgRes_GetString(g, 0x99));
        UiList021cb4a8_SetLabel(self->unk_4c, MsgRes_GetString(g, 0xa1));
        UiList021cb4a8_SetCenteredLabel(self->unk_4c, MsgRes_GetString(g, 0x3e));
        func_ov000_021546ec(self->unk_4c, data_0208ccc8, "cem3d1icn00", 0xffff);
        break;
    case 1:
        o = (VObj *)Heap_Alloc(0xe0);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021caec8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb4a8;
            o->vfunc_28();
        }
        self->unk_4c = (UiList021cb4a8 *)o;
        self->unk_4c->vfunc_10(MsgRes_GetString(g, 0xa9));
        self->unk_4c->vfunc_14(MsgRes_GetString(g, 0x99));
        UiList021cb4a8_SetLabel(self->unk_4c, MsgRes_GetString(g, 0xa3));
        UiList021cb4a8_SetCenteredLabel(self->unk_4c, MsgRes_GetString(g, 0x3e));
        {
            u8 *base;
            u16 i;
            u32 n;
            base = LFLD(u8 *, data_02fe152c, 0x4c) + 0x130;
            o = (VObj *)DataRes_GetTable(data_02fe152c, 9);
            n = DataRes_GetCount(data_02fe152c, 9);
            for (i = 0; i < n; i++) {
                BOOL a = DataRes_ReadBitsAt_02059544(data_02fe152c, base, o, 1, i) & 1 ? TRUE : FALSE;
                BOOL b = DataRes_ReadBitsAt_02059544(data_02fe152c, base, o, 0x101, i) == 0 ? TRUE : FALSE;
                if ((a & b) ? TRUE : FALSE) {
                    u16 id = ((Pair02176714 *)o)[i].b;
                    void *x = Param_Get(id);
                    s32 y = func_0206f080(id);
                    self->unk_4c->vfunc_74(x, ((Pair02176714 *)o)[i].b, (u16)y, Param_GetValue(id));
                }
            }
        }
        break;
    case 3:
        o = (VObj *)Heap_Alloc(0xe0);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021caec8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb4a8;
            o->vfunc_28();
        }
        self->unk_4c = (UiList021cb4a8 *)o;
        self->unk_4c->vfunc_10(MsgRes_GetString(g, 0xaa));
        self->unk_4c->vfunc_14(MsgRes_GetString(g, 0x99));
        UiList021cb4a8_SetLabel(self->unk_4c, MsgRes_GetString(g, 0xa6));
        UiList021cb4a8_SetCenteredLabel(self->unk_4c, MsgRes_GetString(g, 0x3e));
        func_ov000_021546ec(self->unk_4c, data_0208ccc8, "cem3d1icn00", 0xffff);
        break;
    }
    data_02fe1534.unk_7a = self->param;
    data_ov000_021ccd48->vfunc_38(1);
    data_02fe1534.unk_7a = 0;
    self->unk_4c->owner = self;
    self->unk_4c->rows = 4;
    {
        UiList021cb4a8 *s = self->unk_4c;
        s->posX = 0;
        s->posY = 0x2c;
        s->posZ = -0x1ccd;
    }
    self->unk_4c->unk_c0 = 0x78;
    self->unk_4c->flags |= 0x400000;
    self->unk_4c->onDecide = (UiItemFn)Task021cbee0_List4cOnDecide;
    self->unk_4c->onCursor = (UiItemFn)Task021cbee0_List4cOnCursor;
    {
        UiList021cb4a8 *t = self->unk_4c;
        t->vfunc_a8(LFLD(s32, t, 0x98));
    }
    self->unk_4c->vfunc_08();
    if ((void *)self->unk_50 == NULL) {
        return;
    }
    if (self->unk_4c->itemCount != 0) {
        return;
    }
    Obj0215bb14_SetText(self->unk_50, MsgRes_GetString(g, 0x9d));
    self->unk_50->vfunc_70();
}

}

}  // namespace m_Lo_02176714

// ---- Lo_02176ff4
namespace m_Lo_02176ff4 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0206f66c(void *p);
s32 Param_Get(void *p);
s32 func_0206f080(void *p);
s32 Param_GetValue(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd48)) {
        r = FALSE;
    }
    return r;
}

void Task021cbee0_Init(Task021cbee0 *self) {
    self->fadeLen = 0x1000;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c[0] = 0;
}

}

}  // namespace m_Lo_02176ff4

// ---- Lo_02177028
namespace m_Lo_02177028 {

extern "C" {

void Task021cbee0_Release(Task021cbee0 *self) {
    LO_FREE_V(self, 0x58);
    LO_FREE_V(self, 0x3c);
    LO_FREE_V(self, 0x40);
    LO_FREE_V(self, 0x44);
    LO_FREE_V(self, 0x48);
    LO_FREE_V(self, 0x4c);
    LO_FREE_V(self, 0x50);
    data_ov000_021ccd35 = data_ov000_021ccd35 - 1;
    if (data_ov000_021ccd35 != 0) {
        return;
    }
    LO_FREE_VAR(data_ov000_021ccd48);
}
}

}  // namespace m_Lo_02177028

// ---- Stub_02177224
namespace m_Stub_02177224 {

extern "C" {

void Task021cbee0_UpdateActive(Task021cbee0 *self) {
    u8 *p = *(u8 **)((u8 *)self + 0x4c);
    if (p != NULL) {
        *(u32 *)(p + 0xc) &= ~4;
    }
}

void Task021cbee0_PreUpdate(void) {
}

}

}  // namespace m_Stub_02177224

// ---- Lo_02177240
namespace m_Lo_02177240 {

extern "C" {

static inline void SetFlag02177240(Task021cbee0 *self) {
    UiList021cb4a8 *p = self->unk_4c;
    if (p != NULL) {
        p->flags |= 4;
    }
}

static inline BOOL IsBusy02177240(VObj *o) {
    return o != NULL && o->vfunc_1c();
}

void Task021cbee0_PostUpdate(Task021cbee0 *self) {
    s32 n;
    if (self->state == 0xd) {
        VObj *o = self->unk_58;
        if (o != NULL) {
            if (o->vfunc_1c()) {
                SetFlag02177240(self);
            } else {
                HEAP_DELETE(VObj *, self->unk_58, p->vfunc_04());
            }
        }
        n = 0;
        if (self->unk_3c != NULL && self->unk_3c->vfunc_1c()) {
            n++;
        }
        if (self->unk_40 != NULL && self->unk_40->vfunc_1c()) {
            n++;
        }
        if (self->unk_44 != NULL && self->unk_44->vfunc_1c()) {
            n++;
        }
        if (self->unk_48 != NULL && self->unk_48->vfunc_1c()) {
            n++;
        }
        if (self->unk_4c != NULL && self->unk_4c->vfunc_1c()) {
            n++;
        }
        if (self->unk_50 != NULL && self->unk_50->vfunc_1c()) {
            n++;
        }
        if (n == 0) {
            self->vfunc_0c(0);
        }
    }
    SetFlag02177240(self);
}
}

}  // namespace m_Lo_02177240

// ---- Lo_021773cc
namespace m_Lo_021773cc {

extern "C" {

extern u8 *data_ov000_021ccd54;
Robo021ca458 *ActorMgr_FindPlayer(void);
BOOL Actor_IsDead(void);
void func_020627fc(u16 a);
void func_0206280c(u16 a);
void func_ov000_02182590(void *p);

void Task021cbee0_Draw(Task021cbee0 *self) {
    s32 s;
    if (self->fadeRatio == 0 || (s = self->state) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (self->unk_3c) {
        self->unk_3c->vfunc_20();
    }
    if (self->unk_40) {
        self->unk_40->vfunc_20();
    }
    if (self->unk_44) {
        self->unk_44->vfunc_20();
    }
    if (self->unk_48) {
        self->unk_48->vfunc_20();
    }
    if (self->unk_4c) {
        self->unk_4c->vfunc_20();
    }
    if (self->unk_50) {
        self->unk_50->vfunc_20();
    }
    if (self->unk_58) {
        self->unk_58->vfunc_20();
    }
}

}

}  // namespace m_Lo_021773cc

// ---- Menu_021774a4
namespace m_Menu_021774a4 {


typedef struct {
    u8 pad_00[8];
    Task021cbee0 *unk_08;
} Self021774a4;

extern "C" {
extern void *data_02097e4c;
extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void *Heap_Alloc(u32 size);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
s32 MsgRes_GetString(void *msg, s32 id);
void Obj0215c1bc_SetText(void *p, s32 a, s32 b);
void func_ov000_02152294(void *self, s32 a, s32 b, void *cb);
s32 func_ov000_02177bd8(void);

static inline UiListItem *List021774a4_Cur(UiList021cb4a8 *list) {
    UiListItem *p = list->topItem;
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = list->cursor;
    while (n-- != 0) {
        p = p->next;
    }
    return p;
}

#define SET_HIDE(x) if ((x) != NULL) (x)->hidden = 1

BOOL Task021cbee0_List4cOnDecide(Self021774a4 *self, BOOL ok) {
    Task021cbee0 *m = self->unk_08;
    UiListItem *item = List021774a4_Cur(m->unk_4c);

    if (!ok) {
        SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
        SET_HIDE(m->unk_3c);
        SET_HIDE(m->unk_40);
        SET_HIDE(m->unk_44);
        SET_HIDE(m->unk_48);
        SET_HIDE(m->unk_4c);
        SET_HIDE(m->unk_50);
        SET_HIDE(m->unk_58);
        return FALSE;
    }
    if (((s32)item->unk_0c) == -1 ? TRUE : FALSE) {
        if (m->unk_58 == NULL) {
            Lo021cad50 *o = (Lo021cad50 *)Heap_Alloc(0xe8);
            if (o != NULL) {
                VOBJ_SET_VTABLE(o, data_ov000_021cac60);
                o->vfunc_28();
                VOBJ_SET_VTABLE(o, data_ov000_021cad50);
                o->vfunc_28();
            }
            m->unk_58 = o;
        }
        m->unk_58->font = 4;
        m->unk_58->vfunc_08();
        m->unk_58->flags |= 0x20000;
        Obj0215c1bc_SetText(m->unk_58, 0x8000, MsgRes_GetString(data_02149ef8, 0x9f));
        m->unk_58->posZ = -0x199a;
        m->unk_58->vfunc_70();
    } else {
        func_ov000_02152294(self, 0x90, 0x18, (void *)func_ov000_02177bd8);
    }
    return TRUE;
}
}

}  // namespace m_Menu_021774a4
#undef SET_HIDE

// ---- Lo_02177698
namespace m_Lo_02177698 {

typedef struct {
    u8 unk_00[0x72];
    u16 unk_72;
} Data02fe1534;

extern "C" {
extern Data02fe1534 data_02fe1534;
extern void *data_02097e4c;
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 StageFlags_CountEntries(void *a, u16 b);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

static inline UiListItem *GetNth(UiList *m) {
    UiListItem *p = m->topItem;
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = m->cursor;
    while (n-- != 0) {
        p = p->next;
    }
    return p;
}

}

extern "C" {
extern void *data_02149ef8;
void *MsgRes_GetString(void *p, s32 a);
void Obj0215bb14_SetText(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);


s32 Task021cbee0_List4cOnCursor(UiList *self, UiListItem *item) {
    Task021cbee0 *o = (Task021cbee0 *)self->owner;
    VObj *t = o->unk_50;
    if (t != NULL) {
        if (item != NULL) {
            u16 id;
            Lo021cae48 *a;
            func_0206ecd4(0x100, o->unk_5c, item->id);
            Obj0215bb14_SetText(t, o->unk_5c);
            t->vfunc_70();
            id = item->id;
            a = o->unk_44;
            if (id & 0x2000) {
                Lo021cae48 *b;
                if (a != NULL) {
                    func_ov000_0215d980(a, data_0214a424->items[(u16)(id & 0xfff)], 1);
                    a->flags &= ~0x20;
                }
                b = o->unk_48;
                if (b != NULL) {
                    func_ov000_0215d980(b, StageFlags_CountEntries(data_0214a424, item->id), 1);
                    b->flags &= ~0x20;
                }
            } else {
                if (a != NULL) {
                    a->flags |= 0x20;
                }
                if ((u8 *)o->unk_48 != NULL) {
                    o->unk_48->flags |= 0x20;
                }
            }
        } else {
            Obj0215bb14_SetText(t, MsgRes_GetString(data_02149ef8, 0x9d));
            t->vfunc_70();
        }
    }
    return 1;
}

s32 func_ov000_021777d4(Task021cbee0 *self, u16 id) {
    UiList021cb4a8 *m = self->unk_4c;
    void *obj = self->unk_40;
    UiListItem *node = GetNth(m);
    StageFlags *g = data_0214a424;
    u32 t;
    data_02fe1534.unk_72 = id;
    t = node->unk_0c;
    g->unk_020 = g->unk_020 > t ? g->unk_020 - t : 0;
    func_ov000_0215d980(obj, data_0214a424->unk_020, 0);
    if (id & 0x2000) {
        if (self->unk_44 != NULL) {
            func_ov000_0215d980(self->unk_44, data_0214a424->items[(u16)(id & 0xfff)], 1);
        }
        void *o48 = self->unk_48;
        if (o48 != NULL) {
            func_ov000_0215d980(o48, StageFlags_CountEntries(data_0214a424, id), 1);
        }
    }
    SndMgr_PlayVolume(data_02097e4c, 0x31, -1, -1, -1);
    return 0;
}
}

extern "C" {
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
BOOL Item_Give(u16 a, s32 b);
void Obj0215c1bc_SetText(void *self, s32 id, void *v);
void Obj02153c48_CreateText(UiListItem *self, s32 a, BOOL show, BOOL center, u8 d);

static inline void ShowMsg021778f0(Task021cbee0 *self, s32 msg) {
    if (self->unk_58 == NULL) {
        Lo021cad50 *o = (Lo021cad50 *)Heap_Alloc(0xe8);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac60);
            o->vfunc_28();
            VOBJ_SET_VTABLE(o, data_ov000_021cad50);
            o->vfunc_28();
        }
        self->unk_58 = o;
    }
    self->unk_58->font = 4;
    self->unk_58->vfunc_08();
    self->unk_58->flags |= 0x20000;
    Obj0215c1bc_SetText(self->unk_58, 0x8000, MsgRes_GetString(data_02149ef8, msg));
    self->unk_58->posZ = -0x199a;
    self->unk_58->vfunc_70();
}

static inline BOOL IsCost021778f0(u32 c) {
    return c == (u32)-1;
}

static inline void Snd021778f0(s32 id) {
    SndMgr_PlayVolume(data_02097e4c, id, -1, -1, -1);
}

static inline void SetBit021778f0(UiObj *p) {
    if (p != NULL) {
        p->hidden = 1;
    }
}

static inline void AddCount021778f0(u16 n) {
    StageFlags *g = data_0214a424;
    g->unk_024 += n;
    if (g->unk_024 > 9999) {
        g->unk_024 = 9999;
    }
}

static inline void ResetItem021778f0(UiListItem *item) {
    if (((s32)item->unk_10) == 1) {
        item->unk_10 = 0;
        item->unk_0c = -1;
        item->unk_24 = 0xe;
        if (((void *)item->label) != NULL) {
            Obj02153c48_CreateText(item, 8, TRUE, 0, 0);
        }
    }
}

BOOL func_ov000_021778f0(Task021cbee0 *self, UiListItem *item) {
    u16 id = item->id;
    switch (((id >> 12) & 0xffff) - 1) {
    case 0:
        if (!func_ov000_021777d4(self, id)) {
            if (id == 0x1002) {
                AddCount021778f0(1);
            } else if (id == 0x1003) {
                AddCount021778f0(5);
            }
            return FALSE;
        }
        return TRUE;
    case 1:
        if (Item_Give(id, TRUE)) {
            if (func_ov000_021777d4(self, id)) {
                Item_Give(id, FALSE);
                return TRUE;
            }
            ResetItem021778f0(item);
        } else {
            ShowMsg021778f0(self, 0x9e);
        }
        break;
    case 4:
        if (Item_Give(id, TRUE)) {
            if (func_ov000_021777d4(self, id)) {
                Item_Give(id, FALSE);
                return TRUE;
            }
            self->unk_4c->vfunc_70(item);
        }
        break;
    case 7:
        if (Item_Give(id, TRUE)) {
            if (func_ov000_021777d4(self, id)) {
                Item_Give(id, FALSE);
                return TRUE;
            }
            ResetItem021778f0(item);
        }
        break;
    }
    return FALSE;
}

static inline Lo021cae48 *GetObj02177bd8(Task021cbee0 *o) {
    return o->unk_40;
}

s32 func_ov000_02177bd8(UiObj *self, UiListItem *item) {
    Task021cbee0 *o = (Task021cbee0 *)self->owner;
    UiList021cb4a8 *m = o->unk_4c;
    Lo021cae48 *obj = GetObj02177bd8(o);
    UiListItem *node = GetNth(m);
    u16 type;
    if (item == NULL) {
        Snd021778f0(0x1f);
        return 0;
    }
    type = item->id;
    if (type == 0) {
        u32 cost = node->unk_0c;
        if (IsCost021778f0(cost)) {
            ShowMsg021778f0(o, 0x9f);
        } else if (obj->value >= cost) {
            if (func_ov000_021778f0(o, node)) {
                SetBit021778f0(o->unk_3c);
                SetBit021778f0(o->unk_40);
                SetBit021778f0(o->unk_44);
                SetBit021778f0(o->unk_48);
                SetBit021778f0(o->unk_4c);
                SetBit021778f0(o->unk_50);
                SetBit021778f0(o->unk_58);
                ((VObj *)o)->vfunc_3c();
                return 0;
            }
        } else {
            Snd021778f0(0x20);
            ShowMsg021778f0(o, 0x9b);
        }
        return 0;
    }
    if (type != 1) {
        return 1;
    }
    Snd021778f0(0x1f);
    return 0;
}
}

}  // namespace m_Lo_02177698

// ---- Lo_02177ec4
namespace m_Lo_02177ec4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern void *data_02149ef8;
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
void StageRes_Init(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void StageRes_Open(void *p, void *buf, const void *s);
void *MsgRes_GetString(void *p, s32 a);
void Obj0215bb14_SetText(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 StageFlags_CountEntries(void *a, u16 b);
void Gfx3D_SendDL(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

VObj *Task021cbe60_New(void) {
    Task021cbe60 *obj = (Task021cbe60 *)Heap_Alloc(0x158);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbe60);
        obj->unk_3c = NULL;
        obj->unk_40 = NULL;
        obj->unk_44 = NULL;
        obj->unk_48 = NULL;
        obj->unk_4c = NULL;
        obj->unk_50 = NULL;
        obj->unk_54 = NULL;
        obj->unk_58[0] = 0;
    }
    obj->vfunc_08(0xa, 0xc8);
    return obj;
}

}

}  // namespace m_Lo_02177ec4

// ---- Lo_02177f40
namespace m_Lo_02177f40 {

extern "C" {

extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);


BOOL Task021cbe60_List3cOnDecide(UiList *self, UiListItem *msg) {
    u16 id;
    Task021cbe60 *o;
    if (msg == NULL) {
        return FALSE;
    }
    id = msg->id;
    o = (Task021cbe60 *)self->owner;
    if (((u32)(id << 4) >> 16) - 1 == 1) {
        s32 c;
        u32 v;
        v = data_0214a424->items[(u16)(id & 0xfff)];
        c = ((s32)msg->unk_0c);
        {
            u16 *p = &o->unk_54->max;
            *p = v > 1 ? v : 1;
        }
        o->unk_54->price = c;
        o->unk_54->flag2 = 0;
        o->unk_54->hidden = 0;
        o->unk_54->count = 1;
        o->unk_3c->flag2 = 1;
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
    }
    return TRUE;
}

}

}  // namespace m_Lo_02177f40

// ---- Lo_02178010
namespace m_Lo_02178010 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern void *data_02149ef8;
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
void StageRes_Init(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void StageRes_Open(void *p, void *buf, const void *s);
void *MsgRes_GetString(void *p, s32 a);
void Obj0215bb14_SetText(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 StageFlags_CountEntries(void *a, u16 b);
void Gfx3D_SendDL(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);


BOOL Task021cbe60_List3cOnCursor(UiList *self, UiListItem *msg) {
    void *o = (Task021cbe60 *)self->owner; // reused below for the 0x4c window
    if (msg == NULL || msg->id == 0xffff) {
        VObj *p = LFLD(VObj *, o, 0x40);
        Obj0215bb14_SetText(p, MsgRes_GetString(data_02149ef8, 0x9d));
        p->vfunc_70();
    } else {
        VObj *p = LFLD(VObj *, o, 0x40);
        func_0206ecd4(0x100, (u8 *)o + 0x58, msg->id);
        Obj0215bb14_SetText(p, (u8 *)o + 0x58);
        p->vfunc_70();
        if (LFLD(void *, o, 0x48) != NULL) {
            func_ov000_0215d980(LFLD(void *, o, 0x48), data_0214a424->items[(u16)(msg->id & 0xfff)], 1);
        }
        o = LFLD(void *, o, 0x4c);
        if (o != NULL) {
            func_ov000_0215d980(o, StageFlags_CountEntries(data_0214a424, msg->id), 1);
        }
    }
    return TRUE;
}

}

}  // namespace m_Lo_02178010

// ---- Lo_02178100
namespace m_Lo_02178100 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
s32 UiList_GetItemById(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void Obj0215bb14_SetText(void *a, void *b);
BOOL Item_Give(u16 a, s32 b);
void *ResMgr_Load(void *a, s32 b, s32 c);
s32 ResMgr_IsLoaded(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);


void func_ov000_02178100(Lo021cacd8 *self, BOOL add) {
    func_ov000_02178dcc(self->owner, add);
}

}

}  // namespace m_Lo_02178100

// ---- Lo_02178110
namespace m_Lo_02178110 {

extern "C" {

void Task021cbe60_FreeWindows(Task021cbe60 *self) {
    HEAP_DELETE(VObj *, self->unk_3c, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_40, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_44, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_48, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_4c, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_50, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_54, p->vfunc_04());
}
}

}  // namespace m_Lo_02178110

// ---- Stub_021782b0
namespace m_Stub_021782b0 {

extern "C" {

void Task021cbe60_Load(void) {
}

BOOL Task021cbe60_IsLoaded(void) {
    VObj *obj = &data_ov000_021ccd44->res;
    return obj->vfunc_2c() ? TRUE : FALSE;
}

}

}  // namespace m_Stub_021782b0

// ---- Lo_021782e0
namespace m_Lo_021782e0 {

extern "C" {
extern void *data_02149ef8;
extern void *data_0208ccc8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cae48[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb2a8[];
void *MsgRes_GetString(void *g, u32 id);
void Obj0215bb14_SetText(void *o, void *s);
void func_ov000_0215d980(void *a, s32 b, s32 c);
void Obj0215d990_SetMsg(void *self, s32 a);
void func_ov000_02160fc8(void *self);
void UiList021cb4a8_SetLabel(void *self, void *a);
void UiList021cb4a8_SetCenteredLabel(void *self, void *arg);
void func_ov000_021546ec(void *a, const void *b, const char *c, u16 d);
s32 UiList_GetItemById(void *p, s32 a);
s32 Param_Get(u16 id);
s32 func_0206f080(u16 id);
u32 Param_GetValue(u16 id);
u8 *Param_GetEntry(u16 id);
void func_ov000_02178100(Lo021cacd8 *self, BOOL add);
BOOL Task021cbe60_List3cOnDecide(void);
BOOL Task021cbe60_List3cOnCursor(void);

static inline u16 ItemIdx021782e0(u16 v) { return v & 0xfff; }
/* `g` is an unused register parameter reused as a local: as a parameter its value
 * gets the target's register order (g r4, 1 r6, vtable r8). The loop's task object
 * reuses `o`, so it is a split web of `o` (numbered below the other webs). */
void Task021cbe60_Start(Task021cbe60 *self, void *g) {
    s32 i;
    s32 a;
    s32 b;
    u16 id;
    u8 *e;
    VObj *o;
    g = data_02149ef8;
    TaskList_Insert(self);
    o = (VObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_40 = (Lo021cadcc *)o;
    ((Lo021cadcc *)o)->width = 0xf8;
    self->unk_40->rows = 2;
    {
        Lo021cadcc *s = self->unk_40;
        s->posX = 4;
        s->posY = 0x95;
        s->posZ = -0x1ccd;
    }
    {
        Lo021cadcc *s = self->unk_40;
        s->slideX = 0;
        s->slideY = 0x54;
        s->slideZ = -0x1ccd;
    }
    self->unk_40->slideMode = 1;
    self->unk_40->color = 0xb;
    self->unk_40->vfunc_08();
    Obj0215bb14_SetText(self->unk_40, MsgRes_GetString(g, 0x9d));
    self->unk_40->vfunc_70();
    o = (VObj *)Heap_Alloc(0x98);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cae48;
        o->vfunc_28();
    }
    self->unk_44 = (Lo021cae48 *)o;
    ((Lo021cae48 *)o)->posX = 0x86;
    ((Lo021cae48 *)o)->posY = 0x78;
    ((Lo021cae48 *)o)->posZ = -0x199a;
    {
        Lo021cae48 *s = self->unk_44;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_44->slideMode = 1;
    func_ov000_0215d980(self->unk_44, data_0214a424->unk_020, 0);
    self->unk_44->vfunc_08();
    o = (VObj *)Heap_Alloc(0x98);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cae48;
        o->vfunc_28();
    }
    self->unk_48 = (Lo021cae48 *)o;
    ((Lo021cae48 *)o)->style = 4;
    {
        Lo021cae48 *s = self->unk_48;
        s->posX = 0x1a;
        s->posY = 0x78;
        s->posZ = -0x1ccd;
    }
    func_ov000_0215d980(self->unk_48, 0, 0);
    self->unk_48->slideMode = 1;
    {
        Lo021cae48 *s = self->unk_48;
        s->slideX = 0x80;
        s->slideY = 0;
        s->slideZ = 0;
    }
    self->unk_48->vfunc_08();
    Obj0215d990_SetMsg(self->unk_48, 0x120);
    self->unk_48->width = 0x66;
    self->unk_48->height = 0x19;
    o = (VObj *)Heap_Alloc(0x98);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cae48;
        o->vfunc_28();
    }
    self->unk_4c = (Lo021cae48 *)o;
    ((Lo021cae48 *)o)->style = 4;
    {
        Lo021cae48 *s = self->unk_4c;
        s->posX = 0x1a;
        s->posY = 0x83;
        s->posZ = -0x1ccd;
    }
    func_ov000_0215d980(self->unk_4c, 0, 0);
    self->unk_4c->slideMode = 1;
    {
        Lo021cae48 *s = self->unk_4c;
        s->slideX = 0x80;
        s->slideY = 0;
        s->slideZ = 0;
    }
    self->unk_4c->vfunc_08();
    Obj0215d990_SetMsg(self->unk_4c, 0x121);
    self->unk_4c->width = 0x66;
    self->unk_4c->height = 0;
    o = (VObj *)Heap_Alloc(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    self->unk_50 = (Lo021cb5a8 *)o;
    ((Lo021cb5a8 *)o)->flags |= 0x4000000;
    self->unk_50->slideMode = 1;
    {
        Lo021cb5a8 *s = self->unk_50;
        s->posX = 0;
        s->posY = 0x11;
        s->posZ = -0x199a;
    }
    self->unk_50->flags |= 0x20000000;
    {
        Lo021cb5a8 *s = self->unk_50;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_50->vfunc_f4(1, MsgRes_GetString(g, 0x32));
    self->unk_50->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_50->vfunc_08();
    o = (VObj *)Heap_Alloc(0xa0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cacd8;
        func_ov000_02160fc8(o);
    }
    self->unk_54 = (Lo021cacd8 *)o;
    ((Lo021cacd8 *)o)->posX = 0x64;
    ((Lo021cacd8 *)o)->posY = 0x50;
    ((Lo021cacd8 *)o)->posZ = -0x1666;
    self->unk_54->owner = self;
    self->unk_54->onDone = func_ov000_02178100;
    self->unk_54->vfunc_08();
    self->unk_54->flags |= 2;
    self->unk_54->flags |= 4;
    o = (VObj *)Heap_Alloc(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb4a8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb2a8;
    }
    self->unk_3c = (UiList021cb4a8 *)o;
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0x11e));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0x11f));
    self->unk_3c->rows = 4;
    self->unk_3c->width = 0xf8;
    {
        UiList021cb4a8 *s = self->unk_3c;
        s->posX = 0;
        s->posY = 0x2c;
        s->posZ = -0x1ccd;
    }
    {
        UiList021cb4a8 *s = self->unk_3c;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = -0x1ccd;
    }
    self->unk_3c->slideMode = 1;
    self->unk_3c->flags |= 0x400000;
    self->unk_3c->flags &= ~0x800000;
    self->unk_3c->unk_c1 = 5;
    self->unk_3c->unk_c0 = 0x78;
    UiList021cb4a8_SetLabel(self->unk_3c, MsgRes_GetString(g, 0x9a));
    UiList021cb4a8_SetCenteredLabel(self->unk_3c, MsgRes_GetString(g, 0x3e));
    self->unk_3c->onDecide = (UiItemFn)Task021cbe60_List3cOnDecide;
    self->unk_3c->onCursor = (UiItemFn)Task021cbe60_List3cOnCursor;
    self->unk_3c->owner = self;
    func_ov000_021546ec(self->unk_3c, data_0208ccc8, "cem3d1icn00", 0xffff);
    for (i = 0; i < 0x53; i++) {
        id = i + 0x2000;
        if (data_0214a424->items[ItemIdx021782e0(id)] != 0) {
            o = LFLD(VObj *, LoFindTask(10), 0x3c);
            a = Param_Get(id);
            b = func_0206f080(id);
            e = (u8 *)o->vfunc_74(a, id, (u16)b, Param_GetValue(id) >> 2);
            LFLD(s32, e, 0x10) = *Param_GetEntry(id);
        }
    }
    {
        VObj *t = self->unk_3c;
        t->vfunc_a8(UiList_GetItemById(t, 0));
    }
    self->unk_3c->vfunc_08();
}

}

}  // namespace m_Lo_021782e0

// ---- Lo_02178a5c
namespace m_Lo_02178a5c {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern void *data_02149ef8;
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
void StageRes_Init(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void StageRes_Open(void *p, void *buf, const void *s);
void *MsgRes_GetString(void *p, s32 a);
void Obj0215bb14_SetText(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 StageFlags_CountEntries(void *a, u16 b);
void Gfx3D_SendDL(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

void Task021cbe60_UpdateActive(Task021cbe60 *self) {
    u16 v;
    if (self->unk_54->state != 5) {
        return;
    }
    v = data_02097dc8->trig;
    if (v & 1) {
        func_ov000_0215d980(self->unk_44, self->unk_44->value, 1);
        return;
    }
    if (!(v & 2)) {
        return;
    }
    self->unk_3c->hidden = 1;
    self->unk_40->hidden = 1;
    self->unk_44->hidden = 1;
    if ((void *)self->unk_48 != NULL) {
        self->unk_48->hidden = 1;
    }
    if ((void *)self->unk_4c != NULL) {
        self->unk_4c->hidden = 1;
    }
    self->unk_50->hidden = 1;
}

}

}  // namespace m_Lo_02178a5c

// ---- Lo_02178b10
namespace m_Lo_02178b10 {

extern "C" {
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 id, s32 a, s32 b, s32 c);

void Task021cbe60_PreUpdate(Task021cbe60 *self) {
    switch (self->state) {
    case 8:
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 13: {
        bool done;
        self->unk_54->vfunc_1c();
        if (self->unk_54->state == 5) {
            self->unk_3c->flags &= ~4;
        } else {
            self->unk_3c->flags |= 4;
        }
        done = true;
        done &= !self->unk_3c->vfunc_1c();
        done &= !self->unk_40->vfunc_1c();
        done &= !self->unk_44->vfunc_1c();
        if (self->unk_48 != NULL) {
            done &= !self->unk_48->vfunc_1c();
        }
        if (self->unk_4c != NULL) {
            done &= !self->unk_4c->vfunc_1c();
        }
        done &= !self->unk_50->vfunc_1c();
        if (done) {
            self->vfunc_0c(0);
        }
        break;
    }
    case 10:
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
}
}

}  // namespace m_Lo_02178b10

// ---- Stub_02178ccc
namespace m_Stub_02178ccc {

extern "C" {

void Task021cbe60_PostUpdate(void) {
}

}

}  // namespace m_Stub_02178ccc

// ---- Lo_02178cd0
namespace m_Lo_02178cd0 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern void *data_02149ef8;
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
void StageRes_Init(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void StageRes_Open(void *p, void *buf, const void *s);
void *MsgRes_GetString(void *p, s32 a);
void Obj0215bb14_SetText(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 StageFlags_CountEntries(void *a, u16 b);
void Gfx3D_SendDL(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_0206f3f0(u16 id, s32 v);
u16 StageFlags_CountItems(void *a);

void Task021cbe60_Draw(Task021cbe60 *self) {
    s32 scale[3];
    if (self->fadeRatio == 0) {
        return;
    }
    Gfx3D_SendDL(data_02097d48->unk_8b0, 0);
    scale[0] = 0x1000;
    scale[1] = 0x1000;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    self->fadeSin = FX_SinCosTable_[((self->fadeRatio << 14) >> 16) * 2];
    self->unk_3c->vfunc_20();
    self->unk_40->vfunc_20();
    self->unk_44->vfunc_20();
    if (self->unk_48 != NULL) {
        self->unk_48->vfunc_20();
    }
    if (self->unk_4c != NULL) {
        self->unk_4c->vfunc_20();
    }
    self->unk_50->vfunc_20();
    self->unk_54->vfunc_20();
}

static inline u16 ItemKind(u16 v) { return v >> 12; }
static inline u16 ItemIdx(u16 v) { return v & 0xfff; }


void func_ov000_02178dcc(void *p, BOOL on) {
    Task021cbe60 *self = (Task021cbe60 *)p;
    u32 n;
    if (on && (n = self->unk_54->price * self->unk_54->count) != 0) {
        s32 rest;
        UiListItem *node;
        UiListItem *list;
        {
            StageFlags *g = data_0214a424;
            if ((g->unk_020 += n) > 99999) {
                g->unk_020 = 99999;
            }
        }
        node = NULL;
        func_ov000_0215d980(self->unk_44, data_0214a424->unk_020, 0);
        SndMgr_PlayVolume(data_02097e4c, 0x30, -1, -1, -1);
        list = (UiListItem *)((u8 *)self->unk_3c->topItem);
        if (list != NULL) {
            s32 i = self->unk_3c->cursor;
            while (i-- != 0) {
                list = (UiListItem *)((u8 *)list->next);
            }
            node = (UiListItem *)list;
        }
        rest = self->unk_54->max - self->unk_54->count;
        if (ItemKind(node->id) - 1 == 1) {
            s32 c = rest;
            if (c < 0) {
                c = 0;
            }
            func_0206f3f0(node->id, c);
            StageFlags_CountItems(data_0214a424);
        }
        if (self->unk_48 != NULL) {
            func_ov000_0215d980(self->unk_48, data_0214a424->items[ItemIdx(node->id)], 1);
        }
        if (self->unk_4c != NULL) {
            func_ov000_0215d980(self->unk_4c, StageFlags_CountEntries(data_0214a424, node->id), 1);
        }
        if (rest <= 0) {
            self->unk_3c->vfunc_70(node);
        }
    }
    self->unk_54->flags |= 4;
    self->unk_54->flags |= 2;
    self->unk_3c->flags &= ~4;
}

}

}  // namespace m_Lo_02178cd0

// ---- Dtor_02178f70
namespace m_Dtor_02178f70 {

extern "C" {

extern u8 data_ov000_021cbde0[];
extern u8 data_ov000_021cc060[];
void *Heap_Alloc(u32 size);

VObj *Task021cbde0_New(void) {
    Task021cbde0 *obj = (Task021cbde0 *)Heap_Alloc(0x54);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbde0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x5, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_02178f70

// ---- Lo_02178fd8
namespace m_Lo_02178fd8 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern void *data_02097e4c;
void MsgRes_Reset_0204bfcc(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void MsgRes_OpenLocalized(void *p, void *buf, const void *s);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

void Task021cbde0_Load(Task021cbde0 *self) {
    u8 buf[0x20];
    VObj *obj = (VObj *)Heap_Alloc(0x58);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
        VOBJ_SET_VTABLE(obj, data_0208ba30);
        MsgRes_Reset_0204bfcc(obj);
    }
    self->unk_3c = obj;
    STD_CopyString(buf, "script/");
    STD_ConcatenateString(buf, "other");
    MsgRes_OpenLocalized(self->unk_3c, buf, "help.ccmes");
}

BOOL Task021cbde0_IsLoaded(Task021cbde0 *self) {
    BOOL r = TRUE;
    if (!self->unk_3c->vfunc_2c()) {
        r = FALSE;
    }
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

extern void *data_02149ef8;
extern u8 *data_02fe152c;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021ccbe0[];
extern u8 data_ov000_021cbac8[];
extern u8 data_ov000_021cca10[];
void TaskList_Insert(void *self);
BOOL MsgRes_Bind(void *p);
void *MsgRes_GetString(void *g, s32 id);
void func_ov000_021c3af4(void *self);
void ListRow_Init(ListRow *self);
void func_ov000_021c2334(Hud021cca10 *self);
void Hud021cca10_SetText(Hud021cca10 *self, char *str);
void LoBase021ccb54_021ccbe0_AppendRow(LoBase021ccb54_021ccbe0 *list, ListRow *row);
BOOL func_ov000_02179910(void);
void *DataRes_GetTable(void *mgr, s32 kind);
u32 DataRes_GetCount(void *mgr, s32 kind);
u16 DataRes_ReadBitsAt_02059544(void *mgr, void *a, void *tbl, s32 b, u16 i);
void *func_02062138(u16 id);
void MI_CpuFill8(void *dst, u8 val, u32 size);

void Task021cbde0_Start(Task021cbde0 *self) {
    VObj *p;
    void *g;
    UiObj *s;
    self->unk_04 &= ~2;
    if (((VObj *)self)->vfunc_28()) {
        return;
    }
    TaskList_Insert(self);
    MsgRes_Bind(self->unk_3c);
    g = data_02149ef8;
    p = (VObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_ov000_021cac60);
        p->vfunc_28();
        VOBJ_SET_VTABLE(p, data_ov000_021caec8);
        p->vfunc_28();
        VOBJ_SET_VTABLE(p, data_ov000_021cb5a8);
        p->vfunc_28();
    }
    self->unk_40 = (Lo021cb5a8 *)p;
    ((Lo021cb5a8 *)p)->flags |= 0x4000000;
    self->unk_40->slideMode = 1;
    s = (UiObj *)self->unk_40;
    s->slideX = 0x100;
    s->slideY = 0;
    s->slideZ = 0;
    s = (UiObj *)self->unk_40;
    s->posX = 0;
    s->posY = 0x11;
    s->posZ = -0x1ccd;
    self->unk_40->flags |= 0x20000000;
    self->unk_40->flags |= 0x80000000;
    self->unk_40->vfunc_f4(1, MsgRes_GetString(g, 0x34));
    self->unk_40->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_40->vfunc_08();
    p = (VObj *)Heap_Alloc(0xf4);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_ov000_021cac60);
        p->vfunc_28();
        VOBJ_SET_VTABLE(p, data_ov000_021ccbe0);
        func_ov000_021c3af4(p);
    }
    self->unk_44 = (LoBase021ccb54_021ccbe0 *)p;
    self->unk_44->vfunc_10(MsgRes_GetString(g, 0x118));
    self->unk_44->vfunc_14(MsgRes_GetString(g, 0x119));
    self->unk_44->owner = self;
    self->unk_44->rows = 7;
    self->unk_44->width = 0xf9;
    s = (UiObj *)self->unk_44;
    s->posX = 4;
    s->posY = 0x23;
    s->posZ = -0x1ccd;
    self->unk_44->onDecide = (void *)func_ov000_02179910;
    {
        u8 *base = LFLD(u8 *, data_02fe152c, 0x4c);
        u16 i;
        u8 *tbl = (u8 *)DataRes_GetTable(data_02fe152c, 3);
        u32 n = DataRes_GetCount(data_02fe152c, 3);
        u16 used[0x40];
        MI_CpuFill8(used, 0, sizeof(used));
        for (i = 0; i < n; i++) {
            if (DataRes_ReadBitsAt_02059544(data_02fe152c, base + 0x70, tbl, 1, i)) {
                used[LFLD(u16, tbl + i * 4, 2)] = i + 1;
            }
        }
        for (i = 0; i < 0x40; i++) {
            if (used[i] != 0) {
                Hud021cca10 *it = (Hud021cca10 *)Heap_Alloc(sizeof(Hud021cca10));
                if (it != NULL) {
                    VOBJ_SET_VTABLE(it, data_ov000_021cbac8);
                    ListRow_Init(it);
                    VOBJ_SET_VTABLE(it, data_ov000_021cca10);
                    func_ov000_021c2334(it);
                }
                it->index = i;
                it->unk_3c = i + 1;
                Hud021cca10_SetText(it, (char *)func_02062138(i));
                LoBase021ccb54_021ccbe0_AppendRow(self->unk_44, it);
            }
        }
    }
    self->unk_44->vfunc_08();
}

}

}  // namespace m_Lo_02178fd8

// ---- Lo_0217942c
namespace m_Lo_0217942c {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern void *data_02097e4c;
void MsgRes_Reset_0204bfcc(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void MsgRes_OpenLocalized(void *p, void *buf, const void *s);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

void Task021cbde0_Init(Task021cbde0 *self) {
    self->fadeLen = 0x1000;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_50 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0xffff;
}

void Task021cbde0_Release(Task021cbde0 *self) {
    LO_FREE_V(self, 0x50);
    LO_FREE_V(self, 0x40);
    LO_FREE_V(self, 0x44);
    LO_FREE_V(self, 0x3c);
}

}

}  // namespace m_Lo_0217942c

// ---- Dtor_02179560
namespace m_Dtor_02179560 {

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021ccbe0[];
void Heap_Free(void *ptr);
void LoBase021ccb54_021ccbe0_Release(void *ptr);

VObj *Ov000Vt_021ccbe0_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccbe0);
    LoBase021ccb54_021ccbe0_Release(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

}

}  // namespace m_Dtor_02179560

// ---- Lo_021795a4
namespace m_Lo_021795a4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern void *data_02097e4c;
void MsgRes_Reset_0204bfcc(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void MsgRes_OpenLocalized(void *p, void *buf, const void *s);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

void Task021cbde0_UpdateActive(Task021cbde0 *self) {
    void *p = self->unk_44;
    u16 v;
    if (p == NULL) {
        return;
    }
    LBIT(p, 0xc).b2 = 0;
    if ((self->unk_44->busy == 0 ? TRUE : FALSE) == FALSE) {
        return;
    }
    if (self->unk_4c != 0xffff) {
        return;
    }
    v = data_02097dc8->trig;
    if (v & 1) {
        return;
    }
    if (!(v & 2)) {
        return;
    }
    SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
    if ((void *)self->unk_40 != NULL) {
        self->unk_40->hidden = 1;
    }
    if ((void *)self->unk_44 != NULL) {
        self->unk_44->hidden = 1;
    }
}

}

}  // namespace m_Lo_021795a4

// ---- Stub_02179680
namespace m_Stub_02179680 {

extern "C" {

void Task021cbde0_PreUpdate(void) {
}

}

}  // namespace m_Stub_02179680

// ---- Win_02179684
namespace m_Win_02179684 {

extern "C" {
extern u8 data_0208ba70[];
extern u8 data_0208bbc8[];
void *Heap_Alloc(u32 size);
s32 MsgRes_GetLines(void *res, u16 id, s32 *out, s32 d);
void TextWin_Init(void *p);
void TwScene_Init(void *p);

void Task021cbde0_PostUpdate(Task021cbde0 *self) {
    if (self->state == 0xd) {
        switch (self->unk_48) {
        case 0: {
            s32 busy = 0;
            if (self->unk_40 != NULL && self->unk_40->vfunc_1c()) {
                busy++;
            }
            if (self->unk_44 != NULL && self->unk_44->vfunc_1c()) {
                busy++;
            }
            if (busy != 0) {
                break;
            }
            if (self->unk_4c != 0xffff) {
                s32 ofs;
                s32 n = MsgRes_GetLines(self->unk_3c, self->unk_4c, &ofs, 1);
                VObj *o = (VObj *)Heap_Alloc(0xb80);
                if (o != NULL) {
                    VOBJ_SET_VTABLE(o, data_0208ba70);
                    TextWin_Init(o);
                    VOBJ_SET_VTABLE(o, data_0208bbc8);
                    TwScene_Init(o);
                }
                self->unk_50 = o;
                ((SlideWin *)o)->font = 8;
                {
                    SlideWin *p = (SlideWin *)self->unk_50;
                    p->text = (const char *)ofs;
                    p->unk_b70 = 0;
                    p->numLines = n;
                }
                ((SlideWin *)self->unk_50)->mode = 4;
                LFLD(u32, self->unk_50, 0xbc) |= 0x80;
                ((SlideWin *)self->unk_50)->flags |= 4;
                self->unk_4c = 0xffff;
                self->unk_48 = 1;
            } else {
                self->vfunc_0c(0);
            }
            break;
        }
        case 1:
            if (!self->unk_50->vfunc_8c()) {
                HEAP_DELETE_VOBJ(self->unk_50);
                if (self->unk_40 != NULL) {
                    self->unk_40->flags &= ~2;
                }
                if (self->unk_44 != NULL) {
                    self->unk_44->flags &= ~2;
                }
                self->unk_48 = 0;
            }
            break;
        }
    }
    if (self->unk_44 != NULL) {
        self->unk_44->flags |= 4;
    }
}
}

}  // namespace m_Win_02179684

// ---- Lo_0217987c
namespace m_Lo_0217987c {

extern "C" {

extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0216f23c(void *p, s32 a);

void Task021cbde0_Draw(Task021cbde0 *self) {
    s32 s;
    if (self->fadeRatio == 0 || (s = self->state) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    switch (self->unk_48) {
    case 0:
        if (self->unk_40 != NULL) {
            self->unk_40->vfunc_20();
        }
        if (self->unk_44 != NULL) {
            self->unk_44->vfunc_20();
        }
        break;
    case 1:
        if (self->unk_50 != NULL) {
            self->unk_50->vfunc_90();
        }
        break;
    }
}


BOOL func_ov000_02179910(UiList *self, UiListItem *msg) {
    Task021cbde0 *o = (Task021cbde0 *)self->owner;
    if (msg == NULL) {
        return FALSE;
    }
    o->unk_4c = LFLD(s32, msg, 4);
    if (o->unk_40 != NULL) {
        o->unk_40->hidden = 1;
    }
    if (o->unk_44 != NULL) {
        o->unk_44->hidden = 1;
    }
    SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
    return TRUE;
}

}

}  // namespace m_Lo_0217987c

// ---- Dtor_0217997c
namespace m_Dtor_0217997c {

extern "C" {

extern u8 data_ov000_021cbd60[];
extern u8 data_ov000_021cc060[];
void *Heap_Alloc(u32 size);

VObj *Task021cbd60_New(void) {
    Task021cbd60 *obj = (Task021cbd60 *)Heap_Alloc(0x48);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbd60);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x6, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_0217997c

// ---- Lo_021799e4
namespace m_Lo_021799e4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern void *data_02097e4c;
void MsgRes_Reset_0204bfcc(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void MsgRes_OpenLocalized(void *p, void *buf, const void *s);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

void Task021cbd60_Load(Task021cbd60 *self) {
    u8 buf[0x20];
    VObj *obj = (VObj *)Heap_Alloc(0x58);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
        VOBJ_SET_VTABLE(obj, data_0208ba30);
        MsgRes_Reset_0204bfcc(obj);
    }
    self->unk_3c = obj;
    STD_CopyString(buf, "script/");
    STD_ConcatenateString(buf, "other");
    MsgRes_OpenLocalized(self->unk_3c, buf, "memory.ccmes");
}

BOOL Task021cbd60_IsLoaded(Task021cbd60 *self) {
    BOOL r = TRUE;
    if (!self->unk_3c->vfunc_2c()) {
        r = FALSE;
    }
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}

}  // namespace m_Lo_021799e4

// ---- Obj_02179ab8
namespace m_Obj_02179ab8 {

extern "C" {
extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021c9c46[];
void *Heap_Alloc(u32 size);
BOOL MsgRes_Bind(void *p);
void *MsgRes_GetString(void *g, u32 id);
void Obj0215bb14_SetText(void *o, void *s);
void TaskList_Insert(void *self);

void Task021cbd60_Start(Task021cbd60 *self) {
    VObj *o;
    void *g;
    u16 n;
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    MsgRes_Bind(self->unk_3c);
    g = data_02149ef8;
    o = (VObj *)Heap_Alloc(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    self->unk_44 = (Lo021cb5a8 *)o;
    ((Lo021cb5a8 *)o)->flags |= 0x4000000;
    self->unk_44->slideMode = 1;
    {
        Lo021cb5a8 *s = self->unk_44;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = 0;
    }
    {
        Lo021cb5a8 *s = self->unk_44;
        s->posX = 0;
        s->posY = 0;
        s->posZ = -0x1ccd;
    }
    self->unk_44->flags |= 0x20000000;
    self->unk_44->flags |= 0x80000000;
    self->unk_44->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_44->vfunc_08();
    o = (VObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_40 = (Lo021cadcc *)o;
    ((Lo021cadcc *)o)->unk_88 = 0xe;
    self->unk_40->width = 0xf8;
    self->unk_40->rows = 6;
    {
        Lo021cadcc *s = self->unk_40;
        s->posX = 4;
        s->posY = 0x2e;
        s->posZ = -0x1ccd;
    }
    self->unk_40->color = 0;
    self->unk_40->flags |= 0x10;
    self->unk_40->slideMode = 1;
    {
        Lo021cadcc *s = self->unk_40;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = 0;
    }
    self->unk_40->vfunc_10(MsgRes_GetString(g, 0xc2));
    self->unk_40->vfunc_14(MsgRes_GetString(g, 0xc3));
    self->unk_40->vfunc_08();
    self->unk_40->flags |= 0x80000;
    n = data_0214a424->unk_518_8;
    if (n != 0) {
        Obj0215bb14_SetText(self->unk_40, MsgRes_GetString(self->unk_3c, (u16)(n - 1)));
    }
    {
        Lo021cadcc *s = self->unk_40;
        s->shape = (VecFx16 *)data_ov000_021c9c46;
        s->shapeCount = 6;
    }
    TaskList_Insert(self);
}
}

}  // namespace m_Obj_02179ab8

// ---- Lo_02179d78
namespace m_Lo_02179d78 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern void *data_02097e4c;
void MsgRes_Reset_0204bfcc(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void MsgRes_OpenLocalized(void *p, void *buf, const void *s);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

void Task021cbd60_Init(Task021cbd60 *self) {
    self->fadeLen = 0x1000;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
}

void Task021cbd60_Release(Task021cbd60 *self) {
    LO_FREE_V(self, 0x40);
    LO_FREE_V(self, 0x44);
    LO_FREE_V(self, 0x3c);
}

void Task021cbd60_UpdateActive(Task021cbd60 *self) {
    if (!(data_02097dc8->trig & 2)) {
        return;
    }
    SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
    if ((void *)self->unk_40 != NULL) {
        self->unk_40->hidden = 1;
    }
    if ((void *)self->unk_44 != NULL) {
        self->unk_44->hidden = 1;
    }
    self->unk_04_0 = 1;
}

}

}  // namespace m_Lo_02179d78

// ---- Stub_02179ef0
namespace m_Stub_02179ef0 {

extern "C" {

void Task021cbd60_PreUpdate(void) {
}

}

}  // namespace m_Stub_02179ef0

// ---- Lo_02179ef4
namespace m_Lo_02179ef4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern void *data_02097e4c;
void MsgRes_Reset_0204bfcc(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void MsgRes_OpenLocalized(void *p, void *buf, const void *s);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

void Task021cbd60_PostUpdate(Task021cbd60 *self) {
    s32 n;
    VObj *p;
    if (self->state != 0xd) {
        return;
    }
    n = 0;
    p = self->unk_40;
    if (p != NULL && p->vfunc_1c()) {
        n++;
    }
    p = self->unk_44;
    if (p != NULL && p->vfunc_1c()) {
        n++;
    }
    if (n != 0) {
        return;
    }
    self->vfunc_0c(0);
}

void Task021cbd60_Draw(Task021cbd60 *self) {
    s32 s;
    if (self->fadeRatio == 0 || (s = self->state) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
    if (self->unk_44 != NULL) {
        self->unk_44->vfunc_20();
    }
}

}

}  // namespace m_Lo_02179ef4

// ---- Dtor_02179fcc
namespace m_Dtor_02179fcc {

extern "C" {

extern u8 data_ov000_021cbc60[];
extern u8 data_ov000_021cc060[];
void *Heap_Alloc(u32 size);

VObj *Task021cbc60_New(void) {
    Task021cbc60 *obj = (Task021cbc60 *)Heap_Alloc(0x50);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbc60);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x7, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_02179fcc

// ---- Win_0217a034
namespace m_Win_0217a034 {

class Win0217a034 : public VObj {
public:
    void *owner_pad;
    void *owner;
    u8 pad0c[0x3c];
    u16 unk_48;
    u8 pad4a[0x1e];
    s16 unk_68;
    u8 pad6a[0x1a];
    void *cb;
    u8 pad88[0x154];
    void *unk_1dc;
    u16 unk_1e0;
};

typedef struct {
    u8 pad[0x4c];
    s32 unk_4c;
} Sub0217a034;

class Obj0217a034 : public VObj {
public:
    u32 b0 : 1;
    u32 rest : 31;
    u8 pad08[0x24];
    Sub0217a034 *sub;
    u8 pad30[0xc];
    Win0217a034 *win;
    u8 pad40[4];
    u16 unk_44;
};

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *MsgRes_GetString(void *a, s32 b);
void *Heap_Alloc(u32 size);
void *UiList_GetItemById(Win0217a034 *w, s32 b);
BOOL func_ov000_02175e6c(void);

BOOL Task021cbc60_Task3Callback(Obj0217a034 *self, s32 msg) {
    Sub0217a034 *sub = self->sub;
    Win0217a034 *w;
    void *a;
    void *b;
    switch (msg) {
    case 0: {
        void *res = data_02149ef8;
        a = MsgRes_GetString(res, 0x1b);
        b = MsgRes_GetString(res, 0x8d);
        w = (Win0217a034 *)Heap_Alloc(0x1e4);
        if (w != NULL) {
            VOBJ_SET_VTABLE(w, data_ov000_021cac60);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021caec8);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb1b0);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb0b8);
            w->vfunc_28();
        }
        self->win = w;
        w->vfunc_10(b);
        self->win->unk_1dc = a;
        self->win->unk_1e0 = 1;
        self->win->owner = self;
        self->win->cb = (void *)func_ov000_02175e6c;
        self->win->vfunc_08();
        self->win->unk_68 = -0x1666;
        self->b0 = 1;
        w = self->win;
        w->vfunc_a8(UiList_GetItemById(w, 0));
        w->unk_48 = 0x2803;
        break;
    }
    case 2:
        if (self->unk_44 == 0) {
            sub->unk_4c = self->unk_44;
            self->vfunc_0c(0);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

}

}  // namespace m_Win_0217a034

// ---- Lo_0217a1d8
namespace m_Lo_0217a1d8 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern void *data_02097e4c;
void MsgRes_Reset_0204bfcc(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void MsgRes_OpenLocalized(void *p, void *buf, const void *s);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

void Task021cbc60_IsLoaded(void) {
    LoTaskObj()->vfunc_2c();
}

}

}  // namespace m_Lo_0217a1d8

// ---- Lo_0217a1f8
namespace m_Lo_0217a1f8 {

// The text argument of func_ov000_0217a328 is a string id, -1 (all bits set) for "no text"
// (it tests b != -1). It is built as the complement of an empty id mask: the backend folds
// the `mvn` of the known zero into `mvn r2, #0` only after the local CSE, so the -1 is not
// derived from the 0x78 before it (a literal -1 gives sub r2, r1, #0x79). See round pmB.
typedef enum { LO_TEXT_MASK_EMPTY = 0 } LoTextMask;

extern "C" {
GameSave *func_ov000_02176208(void);
void func_ov000_0217a328(Task021cbc60 *self, s32 a, s32 b);
void TaskList_Insert(VObj *self);

void Task021cbc60_Start(Task021cbc60 *self) {
    GameSave *o;
    LoTextMask mask;
    self->unk_04 &= ~2;
    if (self->vfunc_28() != 0) {
        return;
    }
    mask = LO_TEXT_MASK_EMPTY;
    func_ov000_0217a328(self, 0x78, ~mask);
    {
        LoCreateFn fn = data_ov000_021ccd4c;
        if (fn == NULL) {
            data_ov000_021ccd4c = fn = (LoCreateFn)func_ov000_02176208;
        }
        o = (GameSave *)fn();
    }
    self->unk_44 = o;
    o->Setup();
    TaskList_Insert(self);
}

}

}  // namespace m_Lo_0217a1f8

namespace m_Lo_0217a26c {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern void *data_02097e4c;
void MsgRes_Reset_0204bfcc(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void MsgRes_OpenLocalized(void *p, void *buf, const void *s);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

void Task021cbc60_Init(Task021cbc60 *self) {
    self->fadeLen = 0x1000;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = -1;
}

void Task021cbc60_Release(Task021cbc60 *self) {
    LO_FREE_V(self, 0x48);
    LO_FREE_V(self, 0x44);
}

}

}  // namespace m_Lo_0217a26c

// ---- Lo_0217a328
namespace m_Lo_0217a328 {

extern "C" {
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
extern void *data_02149ef8;
void *MsgRes_GetString(void *p, u16 a);
void Obj0215c1bc_SetText(void *a, s32 b, void *c);
void Obj0215c1bc_SetMsg(void *a, s32 b);

void func_ov000_0217a328(Task021cbc60 *self, s32 a, s32 b) {
    if (self->unk_48 == NULL) {
        VObj *o = (VObj *)Heap_Alloc(0xe8);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac60);
            o->vfunc_28();
            VOBJ_SET_VTABLE(o, data_ov000_021cad50);
            o->vfunc_28();
        }
        self->unk_48 = (Lo021cad50 *)o;
    }
    if (a == 0x79 || b == 0x77) {
        self->unk_48->flags |= 0x10000;
    } else {
        self->unk_48->flags &= ~0x10000;
    }
    if (self->param != 1) {
        self->unk_48->color = 0x2803;
    } else {
        Lo021cad50 *o = self->unk_48;
        o->flags |= 8;
        o->color = 0x14a5;
        o->unk_54 = 0x1c;
    }
    self->unk_48->font = 4;
    self->unk_48->vfunc_08();
    if (b != -1) {
        Obj0215c1bc_SetText(self->unk_48, 0x8000, MsgRes_GetString(data_02149ef8, b));
    } else {
        Obj0215c1bc_SetMsg(self->unk_48, a);
    }
    self->unk_48->posZ = -0x1ccd;
    self->unk_48->vfunc_70();
}
}

}  // namespace m_Lo_0217a328

// ---- Stub_0217a478
namespace m_Stub_0217a478 {

extern "C" {

void Task021cbc60_UpdateActive(void) {
}

void Task021cbc60_PreUpdate(void) {
}

}

}  // namespace m_Stub_0217a478

// ---- Lo_0217a480
namespace m_Lo_0217a480 {

extern "C" {
extern void *data_02097e4c;
void func_0206c620(void *p);
void func_0206c670(void *p);
void func_ov000_0217a328(Task021cbc60 *self, s32 a, s32 b);
BOOL Task021cbc60_Task3Callback(void *self, s32 msg);
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);

static inline u8 Raw0217a480(StageFlags *g) {
    return g->unk_518_16;
}

static inline u8 Lvl0217a480(StageFlags *g) {
    return Raw0217a480(g) & ~0xc0;
}

static inline BOOL IsB1_0217a480(GameSave *p) {
    return p->bits.flag1 ? TRUE : FALSE;
}

static inline BOOL IsB2_0217a480(GameSave *p) {
    return p->bits.flag2 ? TRUE : FALSE;
}

void Task021cbc60_PostUpdate(Task021cbc60 *self) {
    if (self->unk_48 != NULL && !self->unk_48->vfunc_1c()) {
        LO_FREE_V(self, 0x48);
    }
    if (self->unk_44 != NULL) {
        self->unk_44->Update();
    }
    switch (self->unk_3c) {
    case 0:
        if (self->param == 0) {
            if (self->unk_48 != NULL) {
                return;
            }
            LoSwitchTaskC(3, 0)->callback = (TaskCallback)Task021cbc60_Task3Callback;
            ((VObj *)self)->vfunc_48();
            self->unk_3c = 1;
        } else if (self->param == 1) {
            self->unk_3c = 2;
        }
        break;
    case 1:
        if (self->unk_04_1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (self->unk_4c != -1) {
            self->unk_3c = 2;
            return;
        }
        ((VObj *)self)->vfunc_0c(0);
        self->unk_3c = 6;
        break;
    case 2: {
        StageFlags *g;
        data_02097dd0->unk_31 = 1;
        self->unk_40 = 0;
        if (self->param == 0) {
            func_0206c620(data_0214a424);
        } else if (self->param == 1) {
            func_0206c670(data_0214a424);
        }
        self->unk_44->bits.active = TRUE;
        self->unk_44->flags |= 0x20;
        g = data_0214a424;
        if (Lvl0217a480(g) > 0x14) {
            u16 n = g->unk_008;
            GameSave *q = self->unk_44;
            q->flags |= 0x210;
            q->curSlot = n;
        } else {
            u16 n = g->unk_008;
            GameSave *q = self->unk_44;
            q->flags |= 0x200;
            q->curSlot = n;
        }
        func_ov000_0217a328(self, 0x79, -1);
        self->unk_3c = 3;
        break;
    }
    case 3:
        self->unk_40++;
        if (IsB1_0217a480(self->unk_44)) {
            if (self->unk_40 <= 0x3c) {
                return;
            }
            self->unk_48->flags |= 0x40000;
            self->unk_3c = 4;
        } else {
            if (!IsB2_0217a480(self->unk_44)) {
                return;
            }
            func_ov000_0217a328(self, 0x8000, 0x77);
            self->unk_3c = 5;
        }
        break;
    case 4:
        if (self->unk_48 != NULL) {
            return;
        }
        if (self->param == 0) {
            SndMgr_PlayVolume(data_02097e4c, 0x85, -1, -1, -1);
            func_ov000_0217a328(self, 0x7a, -1);
        }
        self->unk_3c = 5;
        break;
    case 5:
        data_02097dd0->unk_31 = 0;
        if (self->unk_48 != NULL) {
            return;
        }
        ((VObj *)self)->vfunc_0c(0);
        self->unk_3c = 6;
        break;
    }
}

}

}  // namespace m_Lo_0217a480

// ---- Dtor_0217a88c
namespace m_Dtor_0217a88c {

extern "C" {

extern u8 data_ov000_021cbb60[];
extern u8 data_ov000_021cc060[];
void *Heap_Alloc(u32 size);

void Task021cbc60_Draw(Task021cbc60 *self) {
    VObj *obj = *(VObj **)((u8 *)self + 0x48);
    if (obj != NULL) {
        obj->vfunc_20();
    }
}

VObj *Task021cbb60_New(void) {
    Task021cbb60 *obj = (Task021cbb60 *)Heap_Alloc(0xc4);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbb60);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x8, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_0217a88c

// ---- Win_0217a8f4
namespace m_Win_0217a8f4 {

class Win0217a8f4 : public VObj {
public:
    void *owner_pad;
    void *owner;
    u32 unk_0c;
    u8 pad10[0x38];
    u16 unk_48;
    u8 pad4a[0xa];
    s32 unk_54;
    u8 pad58[0x10];
    s16 unk_68;
    u8 pad6a[0x1a];
    void *cb;
    u8 pad88[0x154];
    void *unk_1dc;
    u16 unk_1e0;
};

typedef struct {
    u8 pad[0x4c];
    s32 unk_4c;
    u8 pad50[4];
    u32 unk_54;
} Sub0217a8f4;

class Obj0217a8f4 : public VObj {
public:
    u32 b0 : 1;
    u32 rest : 31;
    u8 pad08[0x24];
    Sub0217a8f4 *sub;
    u8 pad30[0xc];
    Win0217a8f4 *win;
    u8 pad40[4];
    u16 unk_44;
};

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *MsgRes_GetString(void *a, s32 b);
void *Heap_Alloc(u32 size);
BOOL func_ov000_02175e6c(void);

BOOL Task021cbb60_Task3Callback(Obj0217a8f4 *self, s32 msg) {
    Sub0217a8f4 *sub = self->sub;
    s32 idx = sub->unk_4c;
    u16 lo = sub->unk_54;
    u16 hi = sub->unk_54 >> 16;
    Win0217a8f4 *w;
    void *a;
    void *b;
    s32 id;
    switch (msg) {
    case 0: {
        switch (idx) {
        case 1: id = 0x91; break;
        case 2: id = 0x92; break;
        case 3: id = 0x93; break;
        case 4: if (hi == 0) id = 0x94; else id = 0x95; break;
        default: id = 0x8d; break;
        }
        void *res = data_02149ef8;
        a = MsgRes_GetString(res, 0x18);
        b = MsgRes_GetString(res, id);
        w = (Win0217a8f4 *)Heap_Alloc(0x1e4);
        if (w != NULL) {
            VOBJ_SET_VTABLE(w, data_ov000_021cac60);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021caec8);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb1b0);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb0b8);
            w->vfunc_28();
        }
        self->win = w;
        w->unk_0c |= 8;
        w->unk_48 = 0x14a5;
        w->unk_54 = 0x1c;
        self->win->vfunc_10(b);
        self->win->unk_1dc = a;
        self->win->unk_1e0 = lo;
        self->win->owner = self;
        self->win->cb = (void *)func_ov000_02175e6c;
        self->win->vfunc_08();
        self->win->unk_68 = -0x1666;
        self->b0 = 1;
        break;
    }
    case 1:
        break;
    case 2: {
        u16 c = self->unk_44;
        self->vfunc_0c(0);
        if (c == 0) {
            sub->unk_54 = c;
            self->vfunc_0c(0);
            return TRUE;
        }
        sub->unk_54 = -1;
        self->vfunc_0c(0);
        return FALSE;
    }
    }
    return FALSE;
}

}

}  // namespace m_Win_0217a8f4

// ---- Lo_0217ab30
namespace m_Lo_0217ab30 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
s32 UiList_GetItemById(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void Obj0215bb14_SetText(void *a, void *b);
BOOL Item_Give(u16 a, s32 b);
void *ResMgr_Load(void *a, s32 b, s32 c);
s32 ResMgr_IsLoaded(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void Task021cbb60_Load(Task021cbb60 *self) {
    VObj *obj = (VObj *)Heap_Alloc(0x4c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
    }
    self->unk_3c = obj;
    LFLD(s32, obj, 0x44) = 7;
    self->unk_3c->vfunc_1c(data_0208cc9c);
}

BOOL Task021cbb60_IsLoaded(Task021cbb60 *self) {
    BOOL r = TRUE;
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    if (!self->unk_3c->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}

}  // namespace m_Lo_0217ab30

// ---- Lo_0217abd8
namespace m_Lo_0217abd8 {

extern "C" {
extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
extern void *data_0208cb78;
extern void *data_0208cc9c;
void TexObj_Init(void *p, void *name, s32 c);
void *ResMgr_GetArcList(void *a);
void *ResList_FindType2(void *a, void *b);
void TexObj_SetRes(void *model, void *a);
void TexObj_SelectImage(void *model, s32 a, s32 b);
void *STD_CopyString(void *dst, void *src);
GameSave *func_ov000_02176208(void);

static inline void ModelInit(u8 *m, void *s, void *nm) {
    PlttRes_Init_02041218((struct PlttRes *)(m + 0x88));
    TexObj_Init(m, nm, 0);
    STD_CopyString(m + 0x2c, s);
}

void Task021cbb60_Start(Task021cbb60 *self) {
    u8 *m;
    GameSave *o;
    self->unk_04 &= ~2;
    if (self->vfunc_28() != 0) {
        return;
    }
    {
        LoCreateFn fn = data_ov000_021ccd4c;
        if (fn == NULL) {
            data_ov000_021ccd4c = fn = (LoCreateFn)func_ov000_02176208;
        }
        o = (GameSave *)fn();
    }
    self->unk_5c = o;
    o->Setup();
    m = (u8 *)Heap_Alloc(0x160);
    if (m) {
        ModelInit(m, data_0208cc9c, data_0208cb78);
    }
    self->unk_a0 = (Model *)m;
    TexObj_SetRes((u8 *)self->unk_a0, ResList_FindType2(ResMgr_GetArcList(m + 0x2c), (u8 *)self->unk_a0 + 0x4c));
    self->unk_a0->flags |= 2;
    TexObj_SelectImage((u8 *)self->unk_a0, 0, 1);
    TexObj_SelectImage((u8 *)self->unk_a0, 0, 2);
    TexObj_SelectImage((u8 *)self->unk_a0, 0, 3);
    TexObj_SelectImage((u8 *)self->unk_a0, 0, 4);
    self->unk_a0->flags |= 0x200000;
    self->unk_a0->flags |= 0x80000;
    self->unk_a0->flags = (self->unk_a0->flags & ~0x7c) | 0x78;
    TaskList_Insert(self);
    self->unk_04 |= 0x10000;
    if (self->unk_44 != 7) {
        self->unk_44 = 1;
        self->unk_48 = 0;
    }
}

}

}  // namespace m_Lo_0217abd8

// ---- Lo_0217ad54
namespace m_Lo_0217ad54 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
s32 UiList_GetItemById(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void Obj0215bb14_SetText(void *a, void *b);
BOOL Item_Give(u16 a, s32 b);
void *ResMgr_Load(void *a, s32 b, s32 c);
s32 ResMgr_IsLoaded(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void Task021cbb60_Init(Task021cbb60 *self) {
    s32 i;
    self->fadeLen = 0x1000;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
    self->unk_60 = 0;
    self->unk_64 = 0;
    self->unk_68 = 0;
    self->unk_6c = 0;
    self->unk_70 = 0;
    self->unk_71 = 0;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_80 = 0;
    self->unk_7c = 0;
    self->unk_88 = 0;
    self->unk_84 = 0;
    self->unk_90 = 0;
    self->unk_8c = 0;
    self->unk_98 = 0;
    self->unk_94 = 0;
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    for (i = 0; i < 4; i++) {
        ((s32 *)((u8 *)self + 0xa8))[i] = 0;
    }
    self->unk_b8 = 0;
    self->unk_ba = 0;
    self->unk_bc = 0;
    self->unk_c0 = 0;
}

}

}  // namespace m_Lo_0217ad54

// ---- Lo_0217adfc
namespace m_Lo_0217adfc {

typedef struct {
    u8 pad[0xa8];
    VObj *objs[4];
} Arr0217adfc;

extern "C" {
void *func_ov000_0214b724(void *p);

void Task021cbb60_Release(Task021cbb60 *self) {
    s32 i;
    LO_FREE_V(self, 0x60);
    LO_FREE_V(self, 0x5c);
    LO_FREE_V(self, 0x64);
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_6c != NULL) {
            void *p = self->unk_6c;
            if (p != NULL) {
                func_ov000_0214b724(p);
                Heap_Free(p);
            }
            self->unk_6c = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x74);
    LO_FREE_V(self, 0x78);
    LO_FREE_V(self, 0x7c);
    LO_FREE_V(self, 0x80);
    LO_FREE_V(self, 0x84);
    LO_FREE_V(self, 0x88);
    LO_FREE_V(self, 0x8c);
    LO_FREE_V(self, 0x90);
    LO_FREE_V(self, 0x94);
    LO_FREE_V(self, 0x98);
    LO_FREE_V(self, 0x9c);
    self->unk_71 = 0;
    LO_FREE_M(self, 0xa0);
    for (i = 0; i < 4; i++) {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (((Arr0217adfc *)self)->objs[i] != NULL) {
            VObj *p_ = ((Arr0217adfc *)self)->objs[i];
            if (p_ != NULL) {
                p_->vfunc_04();
            }
            ((Arr0217adfc *)self)->objs[(u32)i] = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x3c);
}
}

}  // namespace m_Lo_0217adfc

// ---- Lo_0217b230
namespace m_Lo_0217b230 {

class Obj0217b230 : public VObj {
public:
    u32 b0 : 2;
    u32 b2 : 1;
    u32 b3 : 3;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 5;
    u32 b13 : 9;
    u32 b22 : 1;
    u32 b23 : 1;
    u32 b24 : 1;
    u32 b25 : 7;
    u8 pad_08[0x1c];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2c[0xa];
    u8 unk_36;
    s8 unk_37;
    s32 unk_38;
    u8 pad_3c[8];
    u8 unk_44[4];
    u8 unk_48[4];
    s32 unk_4c;
    u8 pad_50[0x20];
    s32 unk_70;
    s16 unk_74;
    s16 unk_76;
    s32 unk_78;
};

typedef struct {
    s32 unk_00;
    s32 unk_04;
} Data02097ce0;

extern "C" {
extern u8 data_0208ba70[];
extern Data02097ce0 *data_02097ce0;
void *Heap_Alloc(u32 size);
void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, s32 f);
void TextWin_RenderToVram(void *p);

Obj0217b230 *func_ov000_0217b230(void *unused, s32 a1, s32 a2) {
    Obj0217b230 *o = (Obj0217b230 *)Heap_Alloc(0xb8);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208ba70);
        TextWin_Init(o);
    }
    o->unk_37 = 1;
    o->unk_28 = a2;
    o->unk_24 = a1;
    o->unk_4c = Text_Measure(o->unk_28, o->unk_38, o->unk_24, o->unk_44, o->unk_48, o->unk_37 ? 1 : 0);
    data_02097ce0->unk_04 = o->unk_28;
    o->unk_70 = -0x1c8d;
    o->b8 = 0x1e;
    o->unk_74 = 0x7fff;
    o->unk_76 = 0x2adf;
    o->unk_78 = 0x8000;
    o->unk_36 = 1;
    o->b6 = 1;
    o->b22 = 1;
    o->b24 = 1;
    o->vfunc_14();
    o->b2 = 1;
    TextWin_RenderToVram(o);
    return o;
}

}

}  // namespace m_Lo_0217b230

// ---- Menu_0217b324
namespace m_Menu_0217b324 {

typedef struct {
    u16 language_color;
    u16 birthday;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OwnerInfo;

typedef struct {
    u8 unk_00;
    u8 flags;
    u8 pad_02[6];
    u32 time;
    s32 unk_0c;
    u32 lo : 8;
    u32 lv : 8;
    u32 b16 : 8;
    u32 b24 : 4;
    u32 hi : 4;
} SaveRec;

typedef struct {
    u8 unk_00[0x28];
    u8 *recs;
    u8 pad_2c[4];
    s32 stride;
} SaveList;

typedef struct {
    u8 b70;
    u8 b71;
    u8 pad_72[2];
    VObj *p74;
    VObj *p78;
    VObj *p7c;
    VObj *p80;
    VObj *p84;
    VObj *p88;
    VObj *p8c;
    VObj *p90;
    VObj *p94;
    VObj *p98;
    VObj *p9c;
} Slot;

typedef struct {
    u8 pad_00[0x70];
    s32 unk_70;
    s16 unk_74;
    s16 unk_76;
    u8 pad_78[0x20];
    char name[0x20];
} Item;

typedef struct {
    u8 pad_00[0x5c];
    SaveList *list;
    u8 pad_60[0x10];
    Slot slots[1];
    u8 pad_a0[8];
    Item *items[4];
    s16 count;
    s16 unk_ba;
} Self;

extern "C" {
extern void *data_02149ef8;
char *MsgRes_GetString(void *msg, s32 id);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void func_02040a98(char *dst, s32 n);
void Tbl_Format_02070874(char *dst, const char *src, const char *arg);
char *func_02061df0(u16 lv);
char *func_020620ac(u16 id);
int func_0200779c(char *dst, const char *fmt, ...);
void OS_GetOwnerInfo(OwnerInfo *info);
void func_02040b0c(char *dst, s32 *dstLen, const u16 *src, s32 *srcLen);
BOOL OS_IsRunOnTwl(void);
Item *func_ov000_0217b230(Self *self, const char *str, s32 a2);

#define FREE_SLOT(f)                         \
    do {                                     \
        u32 saved;                           \
        LO_HEAP_PUSH(saved);                 \
        if (self->slots[idx].f != NULL) {               \
            VObj *p_ = self->slots[idx].f;              \
            if (p_ != NULL) {                \
                p_->vfunc_04();              \
            }                                \
            self->slots[idx].f = NULL;                  \
        }                                    \
        LO_HEAP_POP(saved);                  \
    } while (0)

#define ADD_ITEM(id, str)                                                                  \
    self->items[self->count] = func_ov000_0217b230(self, MsgRes_GetString(msg, id), 4);       \
    STD_CopyString(self->items[self->count]->name, str);                                   \
    self->items[self->count]->unk_74 = 0x7fff;                                             \
    self->items[self->count]->unk_76 = 0x7fff;                                             \
    self->items[self->count]->unk_70 = -0x1c4d;                                            \
    self->count++

// The three time parts reuse the scratch variable n (the level number above). Its first two defs are then
// not forwarded into the calls, so the division is listed before the num/format arguments, as in the ROM
// (round pmA). STD_CopyString is void in this TU; its char * form adds a result copy that moves the
// automatic 100-instruction block split from before OS_GetOwnerInfo to after it.
void func_ov000_0217b324(Self *self, s32 idx) {
    char buf[0x80];
    char tmp[0x80];
    OwnerInfo info;
    char num[0x10];
    s32 max;
    s32 len;
    BOOL flag;
    SaveRec *rec;
    u8 lv;
    void *msg;
    s32 n;
    long i;

    msg = data_02149ef8;
    rec = (SaveRec *)(self->list->recs + (idx * self->list->stride + 0x14));
    flag = FALSE;
    FREE_SLOT(p74);
    FREE_SLOT(p78);
    FREE_SLOT(p7c);
    FREE_SLOT(p80);
    FREE_SLOT(p84);
    FREE_SLOT(p88);
    FREE_SLOT(p8c);
    FREE_SLOT(p90);
    FREE_SLOT(p94);
    FREE_SLOT(p98);
    FREE_SLOT(p9c);
    self->slots[idx].b71 = 0;
    self->slots[idx].b70 = rec->flags;
    self->slots[idx].b71 = rec->hi;
    lv = rec->lv & ~0xc0;
    if (lv > 20) {
        buf[0] = 0;
    } else if (lv <= 10) {
        buf[0] = 0;
    } else {
        STD_CopyString(buf, MsgRes_GetString(msg, 0xb3));
        func_02040a98(num, 2);
        Tbl_Format_02070874(buf, buf, num);
        STD_ConcatenateString(buf, " ");
    }
    STD_CopyString(tmp, MsgRes_GetString(msg, 0xb4));
    if (lv > 21) {
        n = -1;
    } else if (lv > 20) {
        n = lv - 20;
        if (rec->hi) {
            flag = TRUE;
        }
    } else {
        n = lv > 10 ? lv - 10 : lv;
    }
    if (n != -1) {
        if (flag) {
            STD_CopyString(tmp, MsgRes_GetString(msg, 0xb7));
        } else if (n != 0) {
            func_02040a98(num, n);
            Tbl_Format_02070874(tmp, tmp, num);
        } else {
            STD_CopyString(tmp, MsgRes_GetString(msg, 0xb5));
        }
        STD_ConcatenateString(buf, tmp);
        self->slots[idx].p74 = (VObj *)func_ov000_0217b230(self, buf, 4);
        STD_CopyString(buf, func_02061df0(lv));
        self->slots[idx].p78 = (VObj *)func_ov000_0217b230(self, buf, 8);
    }
    func_0200779c(buf, "%d", rec->lo);
    self->slots[idx].p80 = (VObj *)func_ov000_0217b230(self, buf, 4);
    self->slots[idx].p7c = (VObj *)func_ov000_0217b230(self, MsgRes_GetString(msg, 0xae), 4);
    func_0200779c(buf, "%d", rec->unk_0c);
    self->slots[idx].p88 = (VObj *)func_ov000_0217b230(self, buf, 4);
    self->slots[idx].p84 = (VObj *)func_ov000_0217b230(self, MsgRes_GetString(msg, 0xaf), 4);
    {
        u8 b = rec->b16;
        if (b == 0xff) {
            self->slots[idx].p90 = (VObj *)func_ov000_0217b230(self, "DEBUG", 4);
        } else {
            self->slots[idx].p90 = (VObj *)func_ov000_0217b230(self, func_020620ac(b), 4);
        }
    }
    self->slots[idx].p8c = (VObj *)func_ov000_0217b230(self, MsgRes_GetString(msg, 0xb0), 4);
    STD_CopyString(buf, MsgRes_GetString(msg, 0xb2));
    n = rec->time / 216000;
    func_0200779c(num, "%.2d", n);
    Tbl_Format_02070874(buf, buf, num);
    n = rec->time % 216000 / 3600;
    func_0200779c(num, "%.2d", n);
    Tbl_Format_02070874(buf, buf, num);
    n = rec->time % 216000 % 3600 / 60;
    func_0200779c(num, "%.2d", n);
    Tbl_Format_02070874(buf, buf, num);
    self->slots[idx].p98 = (VObj *)func_ov000_0217b230(self, buf, 4);
    self->slots[idx].p94 = (VObj *)func_ov000_0217b230(self, MsgRes_GetString(msg, 0xb1), 4);
    OS_GetOwnerInfo(&info);
    max = 0x80;
    len = info.nickNameLength;
    func_02040b0c(buf, &max, info.nickName, &len);
    self->slots[idx].p9c = (VObj *)func_ov000_0217b230(self, buf, 4);
    ((Item *)self->slots[idx].p9c)->unk_70 = -0x1c4d;
    self->count = 0;
    for (i = 0; i < 4; i++) {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->items[i] != NULL) {
            VObj *p_ = (VObj *)self->items[i];
            if (p_ != NULL) {
                p_->vfunc_04();
            }
            self->items[i] = NULL;
        }
        LO_HEAP_POP(saved);
    }
    if (rec->flags & 8) {
        ADD_ITEM(0xab, "3");
        self->unk_ba = 1;
    }
    ADD_ITEM(0xac, "1");
    if (OS_IsRunOnTwl()) {
        ADD_ITEM(0xad, "2");
    }
    ADD_ITEM(0x19c, "4");
}

}

}  // namespace m_Menu_0217b324

namespace m_Win_0217bd88 {

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void *MsgRes_GetString(void *a, u16 b);
void *Heap_Alloc(u32 size);
void Obj0215c1bc_SetText(Lo021cad50 *w, s32 a, void *b);
void Obj0215c1bc_SetMsg(Lo021cad50 *w, s32 a);

static inline BOOL Win_IsHidden(Lo021cad50 *w) {
    return (w->flags & 0x10000) == 0 ? TRUE : FALSE;
}

BOOL func_ov000_0217bd88(Task021cbb60 *self, s32 a, s32 id) {
    Lo021cad50 *w;
    if (self->unk_64 != NULL) {
        BOOL busy = FALSE;
        if (self->unk_68 != 0) {
            busy = TRUE;
        }
        if (self->unk_64 != NULL && Win_IsHidden(self->unk_64)) {
            busy = TRUE;
        }
        if (!busy) {
            self->unk_64->flags |= 0x40000;
        }
        return FALSE;
    }
    self->unk_68 = 0x3c;
    w = (Lo021cad50 *)Heap_Alloc(0xe8);
    if (w != NULL) {
        VOBJ_SET_VTABLE(w, data_ov000_021cac60);
        w->vfunc_28();
        VOBJ_SET_VTABLE(w, data_ov000_021cad50);
        w->vfunc_28();
    }
    self->unk_64 = w;
    if (id == 0x6f || id == 0x74 || id == 0x86 || id == 0x82 || id == 0x84 || id == 0x75 || id == 0x76 || id == 0x6d) {
        self->unk_64->flags |= 0x10000;
    } else {
        w->flags &= ~0x10000;
    }
    w = self->unk_64;
    w->flags |= 8;
    w->color = 0x14a5;
    w->unk_54 = 0x1c;
    self->unk_64->flags |= 0x20000;
    self->unk_64->font = 4;
    self->unk_64->vfunc_08();
    if (id != -1) {
        Obj0215c1bc_SetText(self->unk_64, 0x8000, MsgRes_GetString(data_02149ef8, id));
    } else {
        Obj0215c1bc_SetMsg(self->unk_64, a);
    }
    self->unk_64->posZ = -0x199a;
    self->unk_64->vfunc_70();
    return TRUE;
}

}

}  // namespace m_Win_0217bd88

// ---- Lo_0217bf34
namespace m_Lo_0217bf34 {

struct LoDE { s32 d; s32 *e; };
extern "C" {

u32 Rand_GetGlobal(void);
void Obj0215fdfc_SetRange(void *self, s32 a, s32 b);
void func_ov000_021c216c(void *p);
void func_ov000_0216c954(void *self, u16 a, s32 b);

BOOL func_ov000_0217bf34(Task021cbb60 *self) {
    VObj *o = self->unk_64;
    if (o == NULL) {
        return FALSE;
    }
    if (!o->vfunc_1c()) {
        self->unk_68 = 0;
        LO_FREE_V(self, 0x64);
    } else {
        if (!self->unk_64->vfunc_0c()) {
            return TRUE;
        }
        if (--self->unk_68 < 0) {
            self->unk_68 = 0;
        }
    }
    return FALSE;
}

}

}  // namespace m_Lo_0217bf34

// ---- Stub_0217c004
namespace m_Stub_0217c004 {

extern "C" {

BOOL Task021cbb60_UpdateActive(Task021cbb60 *self) {
    if (*(void **)((u8 *)self + 0x64) != NULL) {
        return (BOOL)self;
    }
    return (*(u32 *)((u8 *)self + 0x4) & 0x10000) ? TRUE : FALSE;
}

void Task021cbb60_PreUpdate(void) {
}

}

}  // namespace m_Stub_0217c004

// ---- Lo_0217c008
namespace m_Lo_0217c008 {

extern "C" {
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);
BOOL Task021cbb60_Task3Callback(void);
BOOL func_ov000_0217bf34(Task021cbb60 *self);
void func_ov000_0217c3b0(Task021cbb60 *self);
void func_ov000_0217c5a8(Task021cbb60 *self);
void func_ov000_0217c7b8(Task021cbb60 *self);
void func_ov000_0217cddc(Task021cbb60 *self);
void func_ov000_0217cf10(Task021cbb60 *self);
void func_ov000_0217d0c4(Task021cbb60 *self);
void func_ov000_0217d66c(Task021cbb60 *self);
void func_ov000_0217dba4(Task021cbb60 *self);
void func_ov000_0217ddd4(Task021cbb60 *self);
extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208c994[];

static inline BOOL Lo0217c3b0_Busy(Task021cbb60 *self) {
    Lo021cad50 *p = self->unk_64;
    if (p == NULL) {
        return FALSE;
    }
    if (self->unk_68 == 0) {
        if (!((p->flags & 0x10000) == 0 ? TRUE : FALSE)) {
            p->flags |= 0x40000;
        }
    }
    return TRUE;
}

static inline void Lo0217c008_SetMode(Task021cbb60 *self, s32 m) {
    if (self->unk_44 != 7) {
        self->unk_44 = m;
        self->unk_48 = 0;
    }
}

static inline BOOL Lo0217c008_Flag(GameSave *o) {
    return o->bits.flag2 ? TRUE : FALSE;
}

void Task021cbb60_PostUpdate(Task021cbb60 *self) {
    if (self->state != 0xd) {
        return;
    }
    if (!(self->unk_04 & 0x20000)) {
        self->unk_40 += 0x1000;
        if (self->unk_40 >= 0x5a000) {
            self->unk_40 -= 0x5a000;
        }
    }
    if (func_ov000_0217bf34(self)) {
        return;
    }
    switch (self->unk_4c) {
    case 1:
        func_ov000_0217c3b0(self);
        break;
    case 2:
        switch (self->unk_50) {
        case 0:
            self->unk_54 = 0;
            LoSwitchTask(3)->callback = (TaskCallback)Task021cbb60_Task3Callback;
            ((VObj *)self)->vfunc_48();
            self->unk_50 = 1;
            break;
        case 1:
            if (!(self->unk_04_0 == 0 ? TRUE : FALSE)) {
                break;
            }
            if (self->unk_04_1 ? TRUE : FALSE) {
                break;
            }
            if (!((VObj *)self)->vfunc_54()) {
                break;
            }
            if (self->unk_54 == 0) {
                self->unk_04 |= 0x800000;
                Lo0217c008_SetMode(self, 5);
            }
            self->unk_4c = 0;
            self->unk_50 = 0;
            self->unk_58 = -1;
            self->unk_54 = 0;
            break;
        }
        break;
    case 3:
        func_ov000_0217c5a8(self);
        break;
    case 4:
        func_ov000_0217c7b8(self);
        break;
    }
    if (self->unk_5c != NULL) {
        self->unk_5c->Update();
        if (Lo0217c008_Flag(self->unk_5c)) {
            Lo0217c008_SetMode(self, 7);
        } else if (self->unk_60 != NULL) {
            self->unk_60->Update();
            if (Lo0217c008_Flag(self->unk_60)) {
                Lo0217c008_SetMode(self, 7);
            }
        }
    }
    switch (self->unk_44) {
    case 1:
        func_ov000_0217cddc(self);
        break;
    case 2:
        func_ov000_0217cf10(self);
        break;
    case 3:
        func_ov000_0217d0c4(self);
        break;
    case 4:
        func_ov000_0217d66c(self);
        break;
    case 5:
        func_ov000_0217dba4(self);
        break;
    case 6:
        if (self->unk_48 != 0) {
            break;
        }
        if (Lo0217c3b0_Busy(self)) {
            break;
        }
        if (self->unk_bc != NULL) {
            self->unk_bc(self, self->unk_c0);
        }
        ((VObj *)self)->vfunc_0c(0);
        Lo0217c008_SetMode(self, 8);
        break;
    case 7:
        func_ov000_0217ddd4(self);
        break;
    }
}

void func_ov000_0217c3b0(Task021cbb60 *self) {
    switch (self->unk_50) {
    case 0:
        if (func_ov000_0217bd88(self, 0x8000, 0x72)) {
            self->unk_50 = 2;
        }
        break;
    case 2:
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        self->unk_54 = 1;
        LoSwitchTask(3)->callback = (TaskCallback)Task021cbb60_Task3Callback;
        ((VObj *)self)->vfunc_48();
        self->unk_50 = 3;
        break;
    case 3:
        if (!(self->unk_04_0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (self->unk_04_1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (self->unk_54 == 0) {
            self->unk_04 |= 0x8000000;
            if (self->unk_44 != 7) {
                self->unk_44 = 5;
                self->unk_48 = 0;
            }
        }
        self->unk_4c = 0;
        self->unk_50 = 0;
        self->unk_58 = -1;
        self->unk_54 = 0;
        break;
    }
}

void func_ov000_0217c5a8(Task021cbb60 *self) {
    switch (self->unk_50) {
    case 0:
        if (func_ov000_0217bd88(self, 0x8000, 0x7f)) {
            self->unk_50 = 1;
        }
        break;
    case 1:
        if (func_ov000_0217bd88(self, 0x8000, 0x80)) {
            self->unk_50 = 2;
        }
        break;
    case 2:
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        self->unk_54 = 1;
        LoSwitchTask(3)->callback = (TaskCallback)Task021cbb60_Task3Callback;
        ((VObj *)self)->vfunc_48();
        self->unk_50 = 3;
        break;
    case 3:
        if (!(self->unk_04_0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (self->unk_04_1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (self->unk_54 == 0) {
            self->unk_04 |= 0x400000;
            if (self->unk_44 != 7) {
                self->unk_44 = 5;
                self->unk_48 = 0;
            }
        }
        self->unk_4c = 0;
        self->unk_50 = 0;
        self->unk_58 = -1;
        self->unk_54 = 0;
        break;
    }
}

static inline void Lo0217c7b8_Reset(Task021cbb60 *self) {
    self->unk_4c = 0;
    self->unk_50 = 0;
    self->unk_58 = -1;
    self->unk_54 = 0;
}

void func_ov000_0217c7b8(Task021cbb60 *self) {
    switch (self->unk_50) {
    case 0:
        if (self->unk_58 == 1) {
            self->unk_50 = 1;
        } else {
            self->unk_50 = 5;
        }
        break;
    case 1:
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        self->unk_54 = 1;
        LoSwitchTask(3)->callback = (TaskCallback)Task021cbb60_Task3Callback;
        ((VObj *)self)->vfunc_48();
        self->unk_50 = 2;
        break;
    case 2:
        if (!(self->unk_04_0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (self->unk_04_1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (self->unk_54 == 0) {
            self->unk_50 = 3;
            return;
        }
        Lo0217c7b8_Reset(self);
        break;
    case 3:
        self->unk_54 = 0x10001;
        LoSwitchTask(3)->callback = (TaskCallback)Task021cbb60_Task3Callback;
        ((VObj *)self)->vfunc_48();
        self->unk_50 = 4;
        break;
    case 4:
        if (!(self->unk_04_0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (self->unk_04_1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (self->unk_54 == 0) {
            self->unk_50 = 5;
            return;
        }
        Lo0217c7b8_Reset(self);
        break;
    case 5:
        if (!func_ov000_0217bd88(self, 0x8000, 0x82)) {
            return;
        }
        data_02097dd0->unk_31 = 1;
        self->unk_04 |= 0x10000000;
        self->unk_50 = 6;
    case 6: {
        GameSave *p = self->unk_5c;
        p->flags |= 0x4000;
        p->curSlot = 0;
        self->unk_50 = 7;
        break;
    }
    case 7:
        if (!(self->unk_5c->bits.flag1 ? TRUE : FALSE)) {
            return;
        }
        if (self->unk_58 == 1) {
            self->unk_50 = 9;
            return;
        }
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        func_ov000_0217bd88(self, 0x8000, 0x83);
        self->unk_50 = 8;
        break;
    case 8:
        data_02097dd0->unk_31 = 0;
        if (!((self->unk_04 & 0x4000000) ? TRUE : FALSE)) {
            Lo0217c008_SetMode(self, 5);
        }
        Lo0217c7b8_Reset(self);
        break;
    case 9: {
        GameSave0208c994 *o = (GameSave0208c994 *)Heap_Alloc(0x58);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_0208b614);
            o->Init();
            VOBJ_SET_VTABLE(o, data_0208ca9c);
            o->Init();
            VOBJ_SET_VTABLE(o, data_0208c994);
            o->Init();
        }
        self->unk_60 = o;
        o->Setup();
        self->unk_60->flags |= 0x40;
        self->unk_60->bits.active = 1;
        self->unk_50 = 10;
    }
    case 10: {
        GameSave *p = self->unk_60;
        if (!(p->bits.flag7 ? TRUE : FALSE)) {
            return;
        }
        p->flags |= 0x4000;
        p->curSlot = 0;
        self->unk_50 = 11;
        break;
    }
    case 11:
        if (!(self->unk_60->bits.flag1 ? TRUE : FALSE)) {
            return;
        }
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        LO_FREE_V(self, 0x60);
        func_ov000_0217bd88(self, 0x8000, 0x83);
        self->unk_50 = 8;
        break;
    }
}
}

}  // namespace m_Lo_0217c008

// ---- Lo_0217cddc
namespace m_Lo_0217cddc {

extern "C" {

extern void *data_ov000_021c9bf4[];
void *Heap_Alloc(u32 size);
void func_ov000_0214b810(void *p);
void *func_ov000_0214b724(void *p);
void *Twl0214b6d8_Init(void *p);
void Loader_Start(void *p, void *name);
BOOL Loader_IsDone(void *p);
u8 func_ov000_0214b8f4(void *p);
s32 func_ov000_0214b6d0(void *p);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

static inline BOOL HasFlag0217cddc(Task021cbb60 *self, u32 bit) {
    return (self->unk_04 & bit) ? TRUE : FALSE;
}

static inline BOOL Has2_0217cddc(Task021cbb60 *self, u32 bit) {
    return HasFlag0217cddc(self, bit) ? TRUE : FALSE;
}

void func_ov000_0217cddc(Task021cbb60 *self) {
    switch (self->unk_48) {
    case 0:
        if (self->param != 3) {
            if (!func_ov000_0217bd88(self, 0x8000, 0x6f)) {
                break;
            }
        }
        self->unk_04 &= 0xc00fffff;
        self->unk_5c->vf74();
        if (self->param == 1) {
            self->unk_04 |= 0x1000000;
        } else if (self->param == 2) {
            self->unk_04 |= 0x2000000;
        } else if (self->param == 3) {
            self->unk_04 |= 0x4000000;
        }
        self->unk_48 = 1;
        break;
    case 1:
        if (Has2_0217cddc(self, 0x1000000) | Has2_0217cddc(self, 0x2000000) | Has2_0217cddc(self, 0x4000000)) {
            if (self->unk_44 != 7) {
                self->unk_44 = 3;
                self->unk_48 = 0;
            }
        } else {
            if (self->unk_44 != 7) {
                self->unk_44 = 2;
                self->unk_48 = 0;
            }
        }
        break;
    }
}

static inline BOOL IsSet0217cf10(Task021cbb60 *self) {
    return self->unk_4c != 0 ? TRUE : FALSE;
}

void func_ov000_0217cf10(Task021cbb60 *self) {
    if (self->unk_6c != NULL) {
        func_ov000_0214b810(self->unk_6c);
    }
    switch (self->unk_48) {
    case 0: {
        void *p;
        HEAP_DELETE(void *, self->unk_6c, func_ov000_0214b724(p); Heap_Free(p));
        p = Heap_Alloc(0x3c);
        if (p != NULL) {
            p = Twl0214b6d8_Init(p);
        }
        self->unk_6c = p;
        Loader_Start(p, data_ov000_021c9bf4[1]);
        self->unk_48 = 1;
        break;
    }
    case 1:
        if (!Loader_IsDone(self->unk_6c)) {
            break;
        }
        if (!func_ov000_0214b8f4(self->unk_6c)) {
            if (func_ov000_0214b6d0((u8 *)self->unk_6c + 0x20) == 3) {
                self->unk_48 = 3;
            } else {
                self->unk_48 = 2;
            }
            break;
        }
        if (self->unk_44 != 7) {
            self->unk_44 = 3;
            self->unk_48 = 0;
        }
        break;
    case 3:
        if (func_ov000_0217bd88(self, 0x8000, 0x70)) {
            self->unk_48 = 2;
        }
        break;
    case 2:
        if (!func_ov000_0217bd88(self, 0x8000, 0x71)) {
            break;
        }
        self->unk_4c = 1;
        self->unk_50 = 0;
        self->unk_58 = -1;
        self->unk_54 = 0;
        self->unk_48 = 4;
        break;
    case 4:
        if (IsSet0217cf10(self)) {
            break;
        }
        func_ov000_0217bd88(self, 0x8000, 0x6f);
        if (self->unk_44 != 7) {
            self->unk_44 = 3;
            self->unk_48 = 0;
        }
        break;
    }
}

}

}  // namespace m_Lo_0217cddc

// ---- Lo_0217d0c4
namespace m_Lo_0217d0c4 {

extern "C" {

void StageFlags_Reset(void *p);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

static inline BOOL Ready0217d0c4(Lo021cad50 *o) {
    return (o->flags & 0x10000) ? FALSE : TRUE;
}

static inline BOOL Busy0217d0c4(Task021cbb60 *self) {
    Lo021cad50 *o = self->unk_64;
    if (o == NULL) {
        return FALSE;
    }
    if (self->unk_68 == 0) {
        if (!Ready0217d0c4(o)) {
            o->flags |= 0x40000;
        }
    }
    return TRUE;
}

static inline BOOL Flag0217d0c4(u32 flags, u32 bit) {
    return (flags & bit) ? TRUE : FALSE;
}

static inline BOOL Waiting0217d0c4(Task021cbb60 *self) {
    return self->unk_4c != 0 ? TRUE : FALSE;
}

static inline BOOL B7_0217d0c4(GameSave *o) { return o->bits.flag7 ? TRUE : FALSE; }
static inline BOOL B11_0217d0c4(GameSave *o) { return o->bits.flag11 ? TRUE : FALSE; }
static inline BOOL B1_0217d0c4(GameSave *o) { return o->bits.flag1 ? TRUE : FALSE; }
static inline BOOL B13_0217d0c4(GameSave *o) { return o->bits.flag13 ? TRUE : FALSE; }
static inline BOOL B3_0217d0c4(GameSave *o) { return o->bits.flag3 ? TRUE : FALSE; }

static inline void Exit0217d0c4(Task021cbb60 *self, s32 next) {
    if (self->unk_44 != 7) {
        self->unk_44 = next;
        self->unk_48 = 0;
    }
}

void func_ov000_0217d0c4(Task021cbb60 *self) {
    switch (self->unk_48) {
    case 0:
        SaveBase_SetState_020473ac(self->unk_5c, 1);
        self->unk_5c->flags |= 0x40;
        self->unk_5c->bits.active = 1;
        self->unk_48 = 1;
        break;
    case 1: {
        GameSave *o = self->unk_5c;
        SaveHeader *q;
        u32 flags;
        u8 b;
        if (!B7_0217d0c4(o)) {
            return;
        }
        q = o->header;
        if (B11_0217d0c4(o)) {
            self->unk_48 = 9;
            return;
        }
        flags = self->unk_04;
        if (Flag0217d0c4(flags, 0x4000000)) {
            self->unk_48 = 0x13;
            return;
        }
        b = ((SaveSlot *)q->slots)->flags;
        if (!(b & 1)) {
            if (Flag0217d0c4(flags, 0x1000000)) {
                self->unk_48 = 0x16;
                return;
            }
            if (Flag0217d0c4(flags, 0x2000000)) {
                self->unk_48 = 0x16;
            } else {
                self->unk_48 = 2;
            }
        } else {
            if (b & 4) {
                self->unk_48 = 6;
            } else {
                self->unk_48 = 7;
            }
        }
        break;
    }
    case 2: {
        BOOL busy = FALSE;
        Lo021cad50 *o = self->unk_64;
        if (self->unk_68 != 0) {
            busy = TRUE;
        }
        if (o != NULL && Ready0217d0c4(o)) {
            busy = TRUE;
        }
        if (busy) {
            return;
        }
        o->flags |= 0x40000;
        self->unk_04 |= 0x100000;
        StageFlags_Reset(data_0214a424);
        Exit0217d0c4(self, 5);
        break;
    }
    case 6:
        self->unk_04 |= 0x200000;
        StageFlags_Reset(data_0214a424);
        Exit0217d0c4(self, 4);
        break;
    case 7: {
        GameSave *o = self->unk_5c;
        o->flags |= 0x400;
        o->curSlot = 0;
        self->unk_48 = 8;
        break;
    }
    case 8: {
        GameSave *o = self->unk_5c;
        if (B1_0217d0c4(o)) {
            Exit0217d0c4(self, 4);
            return;
        }
        if (B11_0217d0c4(o)) {
            self->unk_48 = 9;
        }
        break;
    }
    case 9:
        if (func_ov000_0217bd88(self, 0x8000, 0x85)) {
            self->unk_48 = 0xa;
        }
        break;
    case 10:
        if (func_ov000_0217bd88(self, 0x8000, 0x86)) {
            self->unk_48 = 0xb;
        }
        break;
    case 11:
        self->unk_5c->flags |= 0x1000;
        self->unk_48 = 0xc;
        break;
    case 12: {
        GameSave *o;
        if (Busy0217d0c4(self)) {
            return;
        }
        o = self->unk_5c;
        if (B1_0217d0c4(o)) {
            func_ov000_0217bd88(self, 0x8000, 0x87);
            self->unk_48 = 0xd;
            return;
        }
        if (B13_0217d0c4(o)) {
            func_ov000_0217bd88(self, 0x8000, 0x88);
            self->unk_48 = 0xe;
        }
        break;
    }
    case 13:
        Exit0217d0c4(self, 4);
        break;
    case 14:
        self->unk_5c->vf74();
        SaveBase_SetState_020473ac(self->unk_5c, 4);
        self->unk_48 = 0xf;
        break;
    case 15:
        self->unk_4c = 4;
        self->unk_50 = 0;
        self->unk_58 = 0;
        self->unk_54 = 0;
        self->unk_48 = 0x11;
        break;
    case 17:
        if (Waiting0217d0c4(self)) {
            return;
        }
        Exit0217d0c4(self, 4);
        break;
    case 19:
        if (!(self->unk_5c->formatted == 0 ? TRUE : FALSE)) {
            self->unk_48 = 0x14;
            return;
        }
        Exit0217d0c4(self, 6);
        break;
    case 20:
        if (!func_ov000_0217bd88(self, 0x8000, 0x6d)) {
            return;
        }
        self->unk_5c->flags |= 0x8;
        self->unk_48 = 0x15;
        break;
    case 21:
        if (B3_0217d0c4(self->unk_5c)) {
            return;
        }
        if (Busy0217d0c4(self)) {
            return;
        }
        Exit0217d0c4(self, 6);
        break;
    case 22:
        if (func_ov000_0217bd88(self, 0x8000, 0x174)) {
            self->unk_48 = 0x17;
        }
        break;
    case 23:
        if (Flag0217d0c4(self->unk_04, 0x1000000)) {
            if (!func_ov000_0217bd88(self, 0x8000, 0x148)) {
                break;
            }
        } else {
            if (!func_ov000_0217bd88(self, 0x8000, 0x175)) {
                break;
            }
        }
        Exit0217d0c4(self, 6);
        break;
    }
}

}

}  // namespace m_Lo_0217d0c4

// ---- Lo_0217d66c
namespace m_Lo_0217d66c {

extern "C" {

extern void *data_02097e4c;
BOOL Vram_IsIdle(void);
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_ov000_0217b324(void *self, s32 a);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

static inline BOOL Ready0217d66c(Lo021cad50 *o) {
    return (o->flags & 0x10000) ? FALSE : TRUE;
}

static inline BOOL Busy0217d66c(Task021cbb60 *self) {
    Lo021cad50 *o = self->unk_64;
    if (o == NULL) {
        return FALSE;
    }
    if (self->unk_68 == 0) {
        if (!Ready0217d66c(o)) {
            o->flags |= 0x40000;
        }
    }
    return TRUE;
}

static inline BOOL Flag0217d66c(u32 flags, u32 bit) {
    return (flags & bit) ? TRUE : FALSE;
}

static inline BOOL Waiting0217d66c(Task021cbb60 *self) {
    return self->unk_4c != 0 ? TRUE : FALSE;
}

static inline void SePlay0217d66c(s32 id) {
    SndMgr_PlayVolume(data_02097e4c, id, -1, -1, -1);
}

void func_ov000_0217d66c(Task021cbb60 *self) {
    switch (self->unk_48) {
    case 0: {
        u32 flags;
        if (Busy0217d66c(self)) {
            return;
        }
        flags = self->unk_04;
        if (Flag0217d66c(flags, 0x4000000)) {
            if (self->unk_44 != 7) {
                self->unk_44 = 6;
                self->unk_48 = 0;
            }
            return;
        }
        if (Flag0217d66c(flags, 0x1000000) || Flag0217d66c(flags, 0x2000000)) {
            if (self->unk_44 != 7) {
                self->unk_44 = 5;
                self->unk_48 = 0;
            }
            return;
        }
        self->unk_5c->vf74();
        SaveBase_SetState_020473ac(self->unk_5c, 4);
        func_ov000_0217b324(self, 0);
        self->unk_48 = 1;
        break;
    }
    case 1:
        if (!Vram_IsIdle()) {
            return;
        }
        SePlay0217d66c(0x27);
        self->unk_48 = 2;
        break;
    case 2:
        self->unk_a4 += 0x1000;
        if (self->unk_a4 < 0x18000) {
            return;
        }
        self->unk_a4 = 0x18000;
        self->unk_04 &= ~0x10000;
        self->unk_48 = 3;
        break;
    case 3: {
        Pad *pad;
        if (Flag0217d66c(self->unk_04, 0x10000)) {
            return;
        }
        pad = data_02097dc8;
        if ((pad->cur & 0x548) == 0x548) {
            self->unk_48 = 0xc;
            return;
        }
        if (pad->trig & 1) {
            switch (LFLD(s8, LFLD(u8 *, (u8 *)self + self->unk_ba * 4, 0xa8), 0x98)) {
            case '1':
                self->unk_48 = 4;
                return;
            case '2':
                self->unk_48 = 6;
                return;
            case '3':
                self->unk_48 = 8;
                return;
            case '4':
                self->unk_48 = 10;
                return;
            }
            break;
        }
        if (pad->trig & 2) {
            SePlay0217d66c(0x28);
            self->unk_04 |= 0x20000000;
            if (self->unk_44 != 7) {
                self->unk_44 = 5;
                self->unk_48 = 0;
            }
            return;
        }
        if (pad->repeat & 0x80) {
            self->unk_ba++;
            if (self->unk_ba >= self->unk_b8) {
                self->unk_ba = self->unk_b8 - 1;
                return;
            }
            SePlay0217d66c(0x1d);
            return;
        }
        if (pad->repeat & 0x40) {
            self->unk_ba--;
            if (self->unk_ba < 0) {
                self->unk_ba = 0;
                return;
            }
            SePlay0217d66c(0x1d);
        }
        break;
    }
    case 4:
        self->unk_4c = 2;
        self->unk_50 = 0;
        self->unk_58 = -1;
        self->unk_54 = 0;
        self->unk_48 = 5;
        break;
    case 5:
        if (!Waiting0217d66c(self)) {
            self->unk_48 = 3;
        }
        break;
    case 6:
        self->unk_4c = 1;
        self->unk_50 = 0;
        self->unk_58 = -1;
        self->unk_54 = 0;
        self->unk_48 = 7;
        break;
    case 7:
        if (!Waiting0217d66c(self)) {
            self->unk_48 = 3;
        }
        break;
    case 8:
        self->unk_4c = 3;
        self->unk_50 = 0;
        self->unk_58 = -1;
        self->unk_54 = 0;
        self->unk_48 = 9;
        break;
    case 9:
        if (!Waiting0217d66c(self)) {
            self->unk_48 = 3;
        }
        break;
    case 10:
        if (func_ov000_0217bd88(self, 0x8000, 0x19d)) {
            self->unk_48 = 0xb;
        }
        break;
    case 11:
        if (self->unk_64 != NULL && self->unk_64->vfunc_0c() &&
            (data_02097dc8->cur & 0x548) == 0x548) {
            self->unk_64->flags |= 0x40000;
            self->unk_48 = 0xc;
            return;
        }
        if (!Busy0217d66c(self)) {
            self->unk_48 = 3;
        }
        break;
    case 12:
        if (Busy0217d66c(self)) {
            return;
        }
        self->unk_4c = 4;
        self->unk_50 = 0;
        self->unk_58 = 1;
        self->unk_54 = 0;
        self->unk_48 = 9;
        break;
    case 13:
        if (!Waiting0217d66c(self)) {
            self->unk_48 = 3;
        }
        break;
    }
}

}

}  // namespace m_Lo_0217d66c

// ---- Lo_0217dba4
namespace m_Lo_0217dba4 {

extern "C" {
extern void *data_ov000_021ccd54;
void StageFlags_Restore(void *p);
void SceneCmd_Push1c(void *p, s32 a);
void SceneCmd_Push24(void *p, s32 a);
void SceneCmd_Push23(void *p);
void func_ov000_0218283c(void *p, s32 a);
void func_ov000_02182920(void *p);
void func_ov000_021829f8(void *p);

static inline BOOL Bit(u32 f, u32 m) {
    return (f & m) ? TRUE : FALSE;
}

static inline BOOL IsFree(Lo021cad50 *sub) {
    return (sub->flags & 0x10000) ? FALSE : TRUE;
}

static inline BOOL CheckSub(Task021cbb60 *self) {
    Lo021cad50 *sub = self->unk_64;
    if (sub == NULL) {
        return FALSE;
    }
    if (self->unk_68 == 0) {
        if (!IsFree(sub)) {
            sub->flags |= 0x40000;
        }
    }
    return TRUE;
}

void func_ov000_0217dba4(Task021cbb60 *self) {
    u32 f;
    self->unk_04 |= 0x10000;
    if (CheckSub(self)) {
        return;
    }
    if (self->unk_a4 != 0) {
        self->unk_a4 -= 0x1000;
        if (self->unk_a4 <= 0) {
            self->unk_a4 = 0;
        }
        return;
    }
    self->unk_5c->vf74();
    f = self->unk_04;
    if (f & 0x10000000) {
        if (self->unk_44 != 7) {
            self->unk_44 = 1;
            self->unk_48 = 0;
        }
        return;
    }
    if (!(f & 0x20000000)) {
        if (Bit(f, 0x1000000)) {
            if (!Bit(f, 0x200000)) {
                StageFlags_Restore(data_0214a424);
            }
            SceneCmd_Push1c(data_ov000_021ccd54, 0);
        } else if (Bit(f, 0x2000000)) {
            if (!Bit(f, 0x200000)) {
                StageFlags_Restore(data_0214a424);
            }
            SceneCmd_Push24(data_ov000_021ccd54, 0);
        } else if (Bit(f, 0x8000000)) {
            SceneCmd_Push23(data_ov000_021ccd54);
        } else if (Bit(f, 0x100000) || Bit(f, 0x200000)) {
            func_ov000_0218283c(data_ov000_021ccd54, 0);
        } else if (Bit(f, 0x400000)) {
            func_ov000_02182920(data_ov000_021ccd54);
        } else if (Bit(f, 0x800000)) {
            func_ov000_021829f8(data_ov000_021ccd54);
        }
        data_ov000_021ccd34 = 1;
        data_ov000_021ccd44->unk_00_0 = 1;
    }
    self->vfunc_0c(0);
    if (self->unk_44 != 7) {
        self->unk_44 = 8;
        self->unk_48 = 0;
    }
}
}

}  // namespace m_Lo_0217dba4

// ---- Lo_0217ddd4
namespace m_Lo_0217ddd4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
s32 UiList_GetItemById(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void Obj0215bb14_SetText(void *a, void *b);
BOOL Item_Give(u16 a, s32 b);
void *ResMgr_Load(void *a, s32 b, s32 c);
s32 ResMgr_IsLoaded(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217ddd4(Task021cbb60 *self) {
    switch (self->unk_48) {
    case 0: {
        u32 fl;
        s32 k;
        self->unk_5c->vf74();
        if (self->unk_60 != NULL) {
            self->unk_60->vf74();
        }
        fl = self->unk_04;
        if (fl & 0x10000000) {
            k = func_ov000_0217bd88(self, 0x8000, 0x84);
        } else if (fl & 0x100000) {
            k = func_ov000_0217bd88(self, 0x8000, 0x75);
        } else {
            k = func_ov000_0217bd88(self, 0x8000, 0x76);
        }
        if (!k) {
            return;
        }
        self->unk_48 = 1;
    }
    case 1:
        data_02097dd0->unk_31 = 0;
        break;
    }
}

extern s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
void func_ov000_0217df5c(Task021cbb60 *self, VecFx32 *v);
void func_ov000_0217e560(Task021cbb60 *self, VecFx32 *v);

void Task021cbb60_Draw(Task021cbb60 *self) {
    s32 st;
    if (self->fadeRatio == 0) {
        return;
    }
    st = self->unk_44;
    if ((st == 4 || st == 5 || st == 7) && self->unk_a4 != 0) {
        s32 t = FX_Div(self->unk_a4, 0x18000);
        s32 c = 0x1000 - FX_SinCosTable_[((t * 0x4000) >> 16) * 2];
        VecFx32 v;
        v.x = LO_FX_MUL(c, 0x140000);
        v.y = 0;
        v.x &= ~0xfff;
        v.y &= ~0xfff;
        func_ov000_0217df5c(self, &v);
        func_ov000_0217e560(self, &v);
    }
    if (self->unk_64 != NULL) {
        self->unk_64->vfunc_20();
    }
}

}

}  // namespace m_Lo_0217ddd4

// ---- Lo_0217df5c
namespace m_Lo_0217df5c {

extern "C" {

extern u8 data_0208b3d0[];
extern VecFx32 data_ov000_021c9c10;
u8 Gfx3DState_NextPolyId(void *p);
void Gfx3D_SendDL(void *p, s32 a);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void TexObj_DrawCell(void *a, void *b, void *c, int d);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);
s32 func_ov000_0214b8ec(void *p);
void func_ov000_0214b1a0(VecFx32 *pos, VecFx32 *col, s32 a, s32 b);

// Model_SetPos from a vector, storing each coordinate as it is read.
static inline void SetPosV0217df5c(Model *m, VecFx32 *p) {
    m->x = p->x;
    m->y = p->y;
}

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

void func_ov000_0217df5c(Task021cbb60 *self, VecFx32 *pos) {
    VecFx32 v;
    u8 *g = (u8 *)data_02097d48;
    u32 size;
    u8 i;
    MODEL_FLAGS(self->unk_a0)->unk_19 = 1;
    MODEL_FLAGS(self->unk_a0)->polygon_id = Gfx3DState_NextPolyId(g + 0x8b0);
    MODEL_FLAGS(self->unk_a0)->alpha = 0x1c;
    SetPosV0217df5c(self->unk_a0, pos);
    self->unk_a0->unk_150 = -0x1ccd;
    Model_PlayPart(self->unk_a0, 1);
    if (self->unk_71 != 0) {
        v.x = pos->x - 0x6f000;
        v.y = pos->y - 0x4a000;
        v.z = pos->z;
        MODEL_FLAGS(self->unk_a0)->unk_19 = 0;
        MODEL_FLAGS(self->unk_a0)->alpha = 0x1f;
        for (i = 0; i < 3; i++) {
            self->unk_a0->unk_150 = -0x1c8d;
            SetPosV0217df5c(self->unk_a0, &v);
            Model_PlayPart(self->unk_a0, 2);
            if (i < self->unk_71) {
                self->unk_a0->unk_150 = -0x1c4d;
                SetPosV0217df5c(self->unk_a0, &v);
                Model_PlayPart(self->unk_a0, 3);
            }
            v.x += 0xc000;
        }
    }
    Gfx3D_SendDL(g + 0x8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0x1f00d0);
    G3_Cmd1(0x20, 0);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0x80000, pos->y + 0x16000, -0x1c8d);
    G3_Vec(0x1b, 0xea000, 0xc000, 0x1000);
    size = *(u32 *)0x020828f8;
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xc000, pos->y + 0x60000, -0x1c8d);
    G3_Vec(0x1b, 0x2000, 0xa0000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xf4000, pos->y + 0x60000, -0x1c8d);
    G3_Vec(0x1b, 0x2000, 0xa0000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0x80000, pos->y + 0xaf000, -0x1c8d);
    G3_Vec(0x1b, 0xea000, 0x2000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xbe000, pos->y + 0x74000, -0x1c8d);
    G3_Vec(0x1b, 0x66000, 0x71000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    {
    VecFx32 c = data_ov000_021c9c10;
    v.x = pos->x + 0xbe000;
    v.y = pos->y + 0x6e000;
    v.z = -0x1c4d;
    func_ov000_0214b1a0(&v, &c, 0x1f, func_ov000_0214b8ec(self->unk_6c));
    }
}

}

}  // namespace m_Lo_0217df5c

// ---- Lo_0217e560
namespace m_Lo_0217e560 {

extern "C" {

u8 Gfx3DState_NextPolyId(void *p);
extern s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void TexObj_DrawCell(void *a, void *b, void *c, int d);

// The menu items (func_ov000_0217b230) are 0xb8-byte TextWins. Main/Gfx/TextWin.h clashes with
// LoCommon.h, so this is its vtable up to Render (0x90). SetPos (0x20) and Render return void.
struct LoTextWin {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void unk_vf08();
    virtual void OnSkip();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20(int a, int b);
    virtual char *unk_vf24(char *p);
    virtual char *unk_vf28(char *p);
    virtual char *unk_vf2c(char *p);
    virtual char *unk_vf30(char *p);
    virtual char *unk_vf34(char *p);
    virtual char *unk_vf38(char *p);
    virtual char *unk_vf3c(char *p);
    virtual char *unk_vf40(char *p);
    virtual char *unk_vf44(char *p);
    virtual char *unk_vf48(char *p);
    virtual char *ParseEscape(char *p);
    virtual char *unk_vf50(char *p);
    virtual char *unk_vf54(char *p);
    virtual char *unk_vf58(char *p);
    virtual char *unk_vf5c(char *p);
    virtual char *unk_vf60(char *p);
    virtual char *unk_vf64(char *p);
    virtual char *unk_vf68(char *p);
    virtual char *unk_vf6c(char *p);
    virtual char *unk_vf70(char *p);
    virtual char *unk_vf74(char *p);
    virtual char *unk_vf78(char *p);
    virtual void unk_vf7c();
    virtual void unk_vf80();
    virtual void unk_vf84();
    virtual void unk_vf88();
    virtual void unk_vf8c();
    virtual void Render();
};
#define OBJ(off) LFLD(LoTextWin *, self, off)

static inline void Row0217e560(Task021cbb60 *self, int off, s32 x, s32 y) {
    OBJ(off)->unk_vf20(x + 0x12, y);
    OBJ(off)->Render();
    OBJ(off + 4)->unk_vf20(x + 0x87 - LFLD(s32, OBJ(off + 4), 0x44), y);
    OBJ(off + 4)->Render();
}
void func_ov000_0217e560(Task021cbb60 *self, s32 *pos) {
    s32 x = pos[0] >> 12;
    u8 *g = (u8 *)data_02097d48;
    s32 step;
    s32 a;
    s32 s;
    s16 i;
    s32 y = pos[1] >> 12;
    s32 y0;
    s32 t;
    s32 lx;
    if (OBJ(0x74) != NULL) {
        OBJ(0x74)->unk_vf20(x + 0x80 - (LFLD(s32, OBJ(0x74), 0x44) >> 1), y + 0x1e);
        OBJ(0x74)->Render();
    }
    if (OBJ(0x78) != NULL) {
        OBJ(0x78)->unk_vf20(x + 0x80 - (LFLD(s32, OBJ(0x78), 0x44) >> 1), y + 0x2b);
        OBJ(0x78)->Render();
    }
    Row0217e560(self, 0x7c, x, y + 0x3d);
    Row0217e560(self, 0x84, x, y + 0x4a);
    Row0217e560(self, 0x8c, x, y + 0x57);
    Row0217e560(self, 0x94, x, y + 0x64);
    OBJ(0x9c)->unk_vf20(x + 0xbd - (LFLD(s32, OBJ(0x9c), 0x44) >> 1), y + 0xa0);
    OBJ(0x9c)->Render();
    t = self->unk_40 % 0x5a000;
    if (t <= 0x1e000) {
        s32 r = FX_Div(t, 0x1e000);
        if (r > 0x1000) {
            r = 0x1000;
        }
        s = FX_SinCosTable_[((r << 14) >> 16) * 2];
    } else if (t <= 0x5a000) {
        s32 r = FX_Div(t - 0x1e000, 0x3c000);
        if (r > 0x1000) {
            r = 0x1000;
        }
        s = FX_SinCosTable_[((r << 14) >> 16) * 2 + 1];
    } else {
        s = 0;
    }
    a = (LO_FX_MUL(s, 0x10000) >> 12) + 0xf;
    lx = x + 0x4c;
    step = 0;
    if (self->unk_b8 == 4) {
        y0 = y + 0x75;
        step = 0xe;
    } else if (self->unk_b8 == 3) {
        y0 = y + 0x79;
        step = 0x10;
    } else if (self->unk_b8 == 2) {
        y0 = y + 0x80;
        step = 0x12;
    } else {
        y0 = y + 0x89;
    }
    for (i = 0; i < self->unk_b8; i++) {
        ((LoTextWin **)((u8 *)self + 0xa8))[i]->unk_vf20(lx - (LFLD(s32, ((LoTextWin **)((u8 *)self + 0xa8))[i], 0x44) >> 1), y0 + i * step);
        ((LoTextWin **)((u8 *)self + 0xa8))[i]->Render();
    }
    {
        s32 py = (self->unk_ba * step + y0 - 0x5a) << 12;
        MODEL_FLAGS(self->unk_a0)->unk_19 = 1;
        MODEL_FLAGS(self->unk_a0)->polygon_id = Gfx3DState_NextPolyId(g + 0x8b0);
        MODEL_FLAGS(self->unk_a0)->alpha = (u8)a;
        Model_SetPos(self->unk_a0, (lx - 0x80) << 12, py);
    }
    self->unk_a0->unk_150 = -0x1c8d;
    Model_PlayPart(self->unk_a0, 4);
}

}

}  // namespace m_Lo_0217e560

// ---- Dtor_0217e9c8
namespace m_Dtor_0217e9c8 {

extern "C" {

extern u8 data_ov000_021cbae0[];
extern u8 data_ov000_021cc060[];
void *Heap_Alloc(u32 size);

VObj *Task021cbae0_New(void) {
    Task021cbae0 *obj = (Task021cbae0 *)Heap_Alloc(0x58);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbae0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x9, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_0217e9c8

// ---- Lo_0217ea30
namespace m_Lo_0217ea30 {

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Bits0217ea30;

extern "C" {
extern void *data_02149ef8;
extern void *data_02fe152c;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *MsgRes_GetString(void *g, u32 id);
BOOL StageFlags_IsValid(void);
u16 DataRes_ReadBitRange(void *a, s32 b, s32 c, s32 d);
BOOL func_ov000_02175e6c(void);

class Obj0217ea30 {
public:
    u8 data[0x1e4];
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
    Obj0217ea30() {
        *(void **)this = data_ov000_021cac60;
        ((VObj *)this)->vfunc_28();
        *(void **)this = data_ov000_021caec8;
        ((VObj *)this)->vfunc_28();
        *(void **)this = data_ov000_021cb1b0;
        ((VObj *)this)->vfunc_28();
        *(void **)this = data_ov000_021cb0b8;
        ((VObj *)this)->vfunc_28();
    }
};

/* The two message strings fetched in each arm of case 0. Kept in a local struct:
 * its fields are scalarized into compiler temps, which gives them the target's
 * register order (plain locals are numbered above the `new` results). */
struct Text0217ea30 {
    void *desc;
    void *title;
};

// Each arm ends with its own copy of the `new`/store/`vfunc_10` tail to get the
// target's branch layout.
struct Lo0217ea30 : public VObj {
    Bits0217ea30 unk_04;
    u8 unk_08[0x24];
    u8 *unk_2c;
    u8 unk_30[0xc];
    VObj *unk_3c;
    u8 unk_40[0x4];
    u16 unk_44;
};

s32 Task021cbae0_Task3Callback(Lo0217ea30 *self, s32 msg) {
    u8 *p = self->unk_2c;
    void *g;
    VObj *o;
    struct Text0217ea30 text;
    switch (msg) {
    case 0:
        if (StageFlags_IsValid()) {
            if (DataRes_ReadBitRange(data_02fe152c, 5, 1, 4)) {
                g = data_02149ef8;
                text.desc = MsgRes_GetString(g, 0x1d);
                text.title = MsgRes_GetString(g, 0x8d);
                o = (VObj *)new Obj0217ea30;
                self->unk_3c = o;
                o->vfunc_10(text.title);
            } else {
                g = data_02149ef8;
                text.desc = MsgRes_GetString(g, 0x1c);
                text.title = MsgRes_GetString(g, 0x8d);
                o = (VObj *)new Obj0217ea30;
                self->unk_3c = o;
                o->vfunc_10(text.title);
            }
        } else {
            g = data_02149ef8;
            text.desc = MsgRes_GetString(g, 0x1e);
            text.title = MsgRes_GetString(g, 0x8d);
            o = (VObj *)new Obj0217ea30;
            self->unk_3c = o;
            o->vfunc_10(text.title);
        }
        LFLD(void *, self->unk_3c, 0x1dc) = text.desc;
        LFLD(s16, self->unk_3c, 0x1e0) = 0;
        LFLD(void *, self->unk_3c, 0x8) = self;
        LFLD(void *, self->unk_3c, 0x84) = (void *)func_ov000_02175e6c;
        self->unk_3c->vfunc_08();
        LFLD(s16, self->unk_3c, 0x68) = -0x1666;
        self->unk_04.b0 = true;
        LFLD(u32, self->unk_3c, 0xc) |= 0x4000000;
        break;
    case 2:
        if (StageFlags_IsValid()) {
            if (DataRes_ReadBitRange(data_02fe152c, 5, 1, 4)) {
                if (self->unk_44 == 0) {
                    LFLD(s32, p, 0x44) = 0;
                } else if (self->unk_44 == 1) {
                    LFLD(s32, p, 0x44) = 1;
                } else {
                    return 0;
                }
                self->vfunc_0c(0);
                return 1;
            } else {
                if (self->unk_44 == 0) {
                    LFLD(s32, p, 0x44) = 0;
                } else {
                    return 0;
                }
                self->vfunc_0c(0);
                return 1;
            }
        }
        LFLD(s32, p, 0x44) = 2;
        break;
    }
    return 0;
}

}

}  // namespace m_Lo_0217ea30

// ---- Lo_0217ed94
namespace m_Lo_0217ed94 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
s32 UiList_GetItemById(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void Obj0215bb14_SetText(void *a, void *b);
BOOL Item_Give(u16 a, s32 b);
void *ResMgr_Load(void *a, s32 b, s32 c);
s32 ResMgr_IsLoaded(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void Task021cbae0_IsLoaded(void) {
    LoTaskObj()->vfunc_2c();
}

void Task021cbae0_Start(Task021cbae0 *self) {
    self->unk_04_1 = 0;
    if (self->vfunc_28()) {
        return;
    }
    TaskList_Insert(self);
}

void Task021cbae0_Init(Task021cbae0 *self) {
    self->fadeLen = 0x8000;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = -1;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
    self->unk_54 = 0;
}

void Task021cbae0_Release(Task021cbae0 *self) {
    LO_FREE_V(self, 0x48);
    LO_FREE_M(self, 0x4c);
    LO_FREE_V(self, 0x50);
    LO_FREE_M(self, 0x54);
}

}

}  // namespace m_Lo_0217ed94

// ---- Stub_0217ef34
namespace m_Stub_0217ef34 {

extern "C" {

void Task021cbae0_UpdateActive(void) {
}

void Task021cbae0_PreUpdate(void) {
}

}

}  // namespace m_Stub_0217ef34

// ---- Lo_0217ef3c
namespace m_Lo_0217ef3c {

extern "C" {

extern s32 data_02097d78[];
extern u8 *data_02097e48;
extern void *data_02fe152c;
extern u8 *data_ov000_021ccd30;
extern u8 *data_ov000_021ccd54;
extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd64;
extern u8 data_0208b318[];
extern void *data_02097e4c;
u16 DataRes_ReadBitRange(void *p, s32 a, s32 b, s32 c);
s32 Task021cbae0_Task3Callback(VObj *self, s32 msg);
void MessageQueue_FreeBuffer(void *a, void *b);
void EffectMgr_FreeAll(void *p);
void ActorMgr_ClearGroup(void *p, s32 a);
void LangData_LocalizePath(char *dst, const char *src);
void TexObj_Init(void *p, void *name, s32 c);
void *STD_CopyString(void *dst, void *src);
void TexObj_SetRes(void *model, void *a);
void TexObj_SelectImage(void *model, s32 a, s32 b);
void func_0204a2e0(void *mgr, s32 a);
void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);
void func_0204aab0(void *p);
void GfxSys_StartFadeOut(s32 a, s32 b, s32 c);
void SceneCmd_Push21(void *p, s32 a);
void func_ov000_02182b0c(void *p);
Robo021ca458 *ActorMgr_FindPlayer(void);
void Robo021ca458_RestoreHp(void);
void func_020623fc(void);
void func_ov000_02182590(void *p);

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
} SndBits;

typedef struct {
    u8 b0 : 2;
    u8 b2 : 2;
} Bits0e;

typedef struct {
    u8 b0 : 1;
} LoBits8;

static inline BOOL FadeIs4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[0] == 4 ? TRUE : FALSE;
}

static inline BOOL FadeIs3(void) {
    BOOL r = FALSE;
    if (data_02097d78[3] == 3) {
        r = TRUE;
    } else if (data_02097d78[0] == 3) {
        r = TRUE;
    }
    return r;
}

static inline BOOL FadeIdle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline void SndStop(void) {
    u8 *p = data_02097e48;
    if (LFLD(SndBits, p, 0).b3) {
        LFLD(u16, p, 6) = 0x8000;
        LFLD(u16, p, 8) = 0x3c;
        LFLD(u16, p, 2) = 0;
    }
    p = data_02097e48;
    LFLD(u16, p, 0x74) = 0x8000;
    LFLD(u16, p, 0x70) = 0;
}

static inline BOOL LoBit1(Task021cbae0 *self) {
    return self->unk_04_1 ? TRUE : FALSE;
}

static inline VObj *NewLoader(void) {
    VObj *o = (VObj *)Heap_Alloc(0x4c);
    if (o != NULL) {
        *(void **)o = data_0208b318;
        o->vfunc_08();
    }
    return o;
}

static inline u8 *NewWorldMapModel(void) {
    u8 *m = (u8 *)Heap_Alloc(0x160);
    if (m) {
        char *n = "cewor1map00";
        char *a = "menu/worldmap";
        PlttRes_Init_02041218((struct PlttRes *)(m + 0x88));
        TexObj_Init(m, n, 0);
        STD_CopyString(m + 0x2c, a);
    }
    return m;
}

void Task021cbae0_PostUpdate(Task021cbae0 *self) {
    char buf[0x20];
    switch (self->unk_3c) {
    case 0:
        if (DataRes_ReadBitRange(data_02fe152c, 5, 1, 3)) {
            LoSwitchTaskC(3, 0)->callback = (TaskCallback)Task021cbae0_Task3Callback;
            self->vfunc_48();
            self->unk_3c = 1;
        } else {
            self->unk_3c = 3;
        }
        return;
    case 1:
        if (LoBit1(self)) {
            return;
        }
        if (!self->vfunc_54()) {
            return;
        }
        if (self->unk_44 == 2) {
            self->unk_3c = 2;
        } else if (self->unk_44 == -1) {
            self->unk_3c = 3;
        } else if (self->unk_44 == 0) {
            self->unk_3c = 8;
        } else if (self->unk_44 == 1) {
            self->unk_3c = 10;
        }
        return;
    case 2:
    case 3:
        SndStop();
        if (!FadeIs3() && !FadeIs4()) {
            GfxSys_StartFadeOut(0xb4000, 1, -1);
        }
        if (self->unk_3c == 3) {
            self->unk_3c = 4;
        } else {
            self->unk_3c = 7;
            return;
        }
        self->unk_40 = 0;
    case 4: {
        VObj *o;
        if (!FadeIs4()) {
            return;
        }
        {
            u8 **pmq = &data_ov000_021ccd30;
            u8 *mq = *pmq;
            MessageQueue_FreeBuffer(mq, LFLD(void *, mq, 0x11c));
            LFLD(void *, mq, 0x11c) = NULL;
            mq = *pmq;
            MessageQueue_FreeBuffer(mq, LFLD(void *, mq, 0x118));
            LFLD(void *, mq, 0x118) = NULL;
        }
        LFLD(Bits0e, data_ov000_021ccd54, 0xe).b2 = 2;
        EffectMgr_FreeAll(data_0214a420);
        ActorMgr_ClearGroup(data_ov000_021ccd68, 0xf000);
        LFLD(LoBits8, data_ov000_021ccd64, 0xc).b0 = 0;
        LangData_LocalizePath(buf, "pic/title");
        o = NewLoader();
        self->unk_48 = o;
        LFLD(s32, o, 0x44) = 2;
        self->unk_48->vfunc_24(buf, "celog1gov00");
        o = NewLoader();
        self->unk_50 = o;
        LFLD(s32, o, 0x44) = 2;
        self->unk_50->vfunc_24(buf, "celog1gov01");
        self->unk_3c = 5;
    }
    case 5: {
        BOOL ok = TRUE;
        u8 *m;
        u8 *p;
        if (!self->unk_48->vfunc_2c()) {
            ok = FALSE;
        }
        if (!self->unk_50->vfunc_2c()) {
            ok = FALSE;
        }
        if (!ok) {
            return;
        }
        if (++self->unk_40 < 0x1e) {
            return;
        }
        self->unk_40 = 0;
        m = NewWorldMapModel();
        self->unk_4c = (Model *)m;
        TexObj_SetRes(self->unk_4c, (void *)self->unk_48->vfunc_10());
        TexObj_SelectImage(self->unk_4c, 2, 0xffff);
        m = NewWorldMapModel();
        self->unk_54 = (Model *)m;
        TexObj_SetRes(self->unk_54, (void *)self->unk_50->vfunc_10());
        TexObj_SelectImage(self->unk_54, 0, 0xffff);
        self->unk_54->unk_150 = -0x1ccd;
        func_0204a2e0(data_02097e4c, 0);
        GfxSys_StartFadeIn(0x3c000, 0, -1);
        p = data_02097e48;
        if (LFLD(SndBits, p, 0).b0) {
            if (LFLD(u16, p, 6) != 0xffff || LFLD(u16, p, 4) != 0x2f) {
                if (LFLD(u16, p, 2) != 10 && LFLD(u16, p, 2) != 0) {
                    if (LFLD(u16, p, 6) != 0xffff) {
                        func_0204aab0(p);
                    }
                    LFLD(u16, p, 2) = 1;
                } else {
                    LFLD(u16, p, 2) = 0;
                }
                LFLD(u16, p, 6) = 0x2f;
                LFLD(u16, p, 8) = 10;
            }
        }
        self->unk_3c = 6;
    }
    case 6:
        if (!FadeIdle()) {
            return;
        }
        if (++self->unk_40 <= 600) {
            if (!(data_02097dc8->trig & 3)) {
                return;
            }
        }
        GfxSys_StartFadeOut(0xf000, 1, -1);
        self->unk_3c = 7;
        return;
    case 7:
        if (!FadeIs4()) {
            return;
        }
        self->fadeLen = 0x1000;
        self->vfunc_0c(0);
        SceneCmd_Push21(data_ov000_021ccd54, 0);
        self->unk_3c = 12;
        return;
    case 8:
        SndStop();
        GfxSys_StartFadeOut(0x3c000, 1, -1);
        self->unk_3c = 9;
    case 9:
        if (!FadeIs4()) {
            return;
        }
        self->fadeLen = 0x1000;
        self->vfunc_0c(0);
        func_ov000_02182b0c(data_ov000_021ccd54);
        self->unk_3c = 12;
        return;
    case 10:
        SndStop();
        GfxSys_StartFadeOut(0x3c000, 1, -1);
        self->unk_3c = 11;
    case 11:
        if (!FadeIs4()) {
            return;
        }
        self->fadeLen = 0x1000;
        self->vfunc_0c(0);
        if (ActorMgr_FindPlayer()) {
            Robo021ca458_RestoreHp();
        }
        func_020623fc();
        { u8 *q = data_ov000_021ccd54; q[0xac] = 1;
        func_ov000_02182590(q + 0xac); }
        self->unk_3c = 12;
        break;
    }
}

}

}  // namespace m_Lo_0217ef3c

// ---- Lo_0217f778
namespace m_Lo_0217f778 {

extern "C" {
extern const s16 FX_SinCosTable_[];
void Gfx3D_SendDL(void *obj, int a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

void Task021cbae0_Draw(Task021cbae0 *self) {
    Model *m;
    if (self->fadeRatio == 0) {
        return;
    }
    Gfx3D_SendDL(data_02097d48->unk_8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    self->fadeSin = FX_SinCosTable_[((s32)(self->fadeRatio << 14) >> 16) * 2];
    m = self->unk_4c;
    if (m != NULL) {
        Model_PlayPart(m, 0);
    }
    {
        Model *m2 = self->unk_54;
        if (m2 != NULL) {
            Model_PlayPart(m2, 0);
        }
    }
}

}

}  // namespace m_Lo_0217f778

// ---- Lo_0217f8d0
namespace m_Lo_0217f8d0 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
s32 UiList_GetItemById(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void Obj0215bb14_SetText(void *a, void *b);
BOOL Item_Give(u16 a, s32 b);
void *ResMgr_Load(void *a, s32 b, s32 c);
s32 ResMgr_IsLoaded(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

VObj *Task021cbf60_New(void) {
    Task021cbf60 *obj = (Task021cbf60 *)Heap_Alloc(0x160);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbf60);
        obj->unk_3c = NULL;
        obj->unk_40 = NULL;
        obj->unk_44 = NULL;
        obj->unk_48 = NULL;
        obj->unk_4c = NULL;
        obj->unk_50 = 0;
        obj->unk_54 = 0;
        obj->unk_58 = 0;
        obj->unk_5c = 0;
        obj->unk_5e = 0;
        obj->unk_5f[0] = 0;
    }
    obj->vfunc_08(0xc, 0xc8);
    return obj;
}


BOOL Task021cbf60_List3cOnDecide(UiList *self, UiListItem *msg) {
    if (msg != NULL) {
        Task021cbf60 *o = (Task021cbf60 *)self->owner;
        VObj *p;
        o->unk_3c->flag2 = 1;
        o->unk_44->hidden = 0;
        o->unk_44->flag2 = 0;
        p = o->unk_44;
        p->vfunc_a8(UiList_GetItemById(p, 1));
        SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
    }
    return TRUE;
}


BOOL Task021cbf60_List3cOnCursor(UiList *self, UiListItem *msg) {
    if (msg != NULL) {
        Task021cbf60 *o = (Task021cbf60 *)self->owner;
        func_0206ecd4(0x100, o->unk_5f, msg->id);
        if (o->unk_40 != NULL) {
            Obj0215bb14_SetText(o->unk_40, o->unk_5f);
            o->unk_40->vfunc_70();
        }
    }
    return TRUE;
}


BOOL Task021cbf60_List44OnDecide(UiList *self, UiListItem *msg) {
    Task021cbf60 *o = (Task021cbf60 *)self->owner;
    if (msg != NULL) {
        if (msg->id == 0) {
            UiList *a = o->unk_3c;
            UiListItem *n = (UiListItem *)((void *)a->topItem);
            if (n == NULL) {
                n = NULL;
            } else {
                s32 c = a->cursor;
                while (c-- != 0) {
                    n = (UiListItem *)((void *)n->next);
                }
            }
            if (n->id != o->unk_5c) {
                Item_Give(n->id, 0);
                if (o->unk_5c != 0) {
                    Item_Give(o->unk_5c, 1);
                }
            }
            o->unk_44->hidden = 1;
            o->unk_5e = 1;
        }
        o->unk_44->hidden = 1;
        o->unk_44->flag2 = 1;
        SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
    } else {
        o->unk_44->hidden = 1;
        o->unk_44->flag2 = 1;
        SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
    }
    return FALSE;
}

}

}  // namespace m_Lo_0217f8d0

// ---- Heap_0217fb44
namespace m_Heap_0217fb44 {

extern "C" {

extern void *data_02097cdc;
extern void *data_0208cca0;
extern void *data_0208cc94;
void ResMgr_ReleaseByName(void *a, void *b, s32 c, s32 d);

void Task021cbf60_FreeWindows(Task021cbf60 *self) {
    HEAP_DELETE_VOBJ(self->unk_3c);
    HEAP_DELETE_VOBJ(self->unk_40);
    HEAP_DELETE_VOBJ(self->unk_44);
    HEAP_DELETE_VOBJ(self->unk_48);
    HEAP_DELETE_MODEL(self->unk_4c);
    ResMgr_ReleaseByName(data_02097cdc, data_0208cca0, 7, 0);
    ResMgr_ReleaseByName(data_02097cdc, data_0208cc94, 7, 0);
}

}

}  // namespace m_Heap_0217fb44

// ---- Lo_0217fcc4
namespace m_Lo_0217fcc4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
s32 UiList_GetItemById(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void Obj0215bb14_SetText(void *a, void *b);
BOOL Item_Give(u16 a, s32 b);
void *ResMgr_Load(void *a, s32 b, s32 c);
s32 ResMgr_IsLoaded(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void Task021cbf60_Load(void) {
    ResMgr_Load(data_0208cca0, 7, 0);
    ResMgr_Load(data_0208cc94, 7, 0);
}

BOOL Task021cbf60_IsLoaded(void) {
    BOOL r = LoTaskObj()->vfunc_2c() ? TRUE : FALSE;
    r = (r & ResMgr_IsLoaded(data_0208cca0, 7)) ? TRUE : FALSE;
    return (r & ResMgr_IsLoaded(data_0208cc94, 7)) ? TRUE : FALSE;
}

}

}  // namespace m_Lo_0217fcc4

// ---- Lo_0217fd70
namespace m_Lo_0217fd70 {

extern "C" {
extern void *data_02149ef8;
extern void *data_0208cb7c;
extern u8 data_0214b105[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb2a8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cafc0[];
void *Heap_Alloc(u32 size);
void *MsgRes_GetString(void *g, u32 id);
void Obj0215bb14_SetText(void *o, void *s);
void TaskList_Insert(void *self);
void func_ov000_021547e8(void *a, void *b, void *c, int d);
void func_ov000_021546ec(void *a, const void *b, const char *c, u16 d);
s32 UiList_GetItemById(void *p, s32 a);
s32 Param_Get(u16 id);
s32 func_0206f080(u16 id);
u8 *Param_GetEntry(u16 id);
BOOL Task021cbf60_List3cOnDecide(void);
BOOL Task021cbf60_List3cOnCursor(void);
BOOL Task021cbf60_List44OnDecide(void);

static inline s32 ItemCat0217fd70(u16 id) {
    return ((u16)(id & 0xf000) >> 12) - 1;
}

void Task021cbf60_Start(Task021cbf60 *self) {
    u8 *e;
    s32 i;
    s32 b;
    s32 n;
    u16 id;
    VObj *o;
    u16 iid;
    void *g;
    u8 *base;
    s32 a;
    if (self->vfunc_28()) {
        return;
    }
    g = data_02149ef8;
    o = (VObj *)Heap_Alloc(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb4a8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb2a8;
    }
    self->unk_3c = (UiList021cb4a8 *)o;
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0x11a));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0x11b));
    self->unk_3c->rows = 5;
    {
        UiList021cb4a8 *s = self->unk_3c;
        s->posX = 0;
        s->posY = 0x2c;
        s->posZ = -0xccd;
    }
    {
        UiList021cb4a8 *s = self->unk_3c;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0xccd;
    }
    self->unk_3c->flags |= 0x400000;
    self->unk_3c->flags |= 0x800000;
    self->unk_3c->unk_c0 = 0x80;
    self->unk_3c->unk_c1 = 3;
    func_ov000_021547e8(self->unk_3c, data_0214b105, data_0208cb7c, 0xb);
    func_ov000_021546ec(self->unk_3c, "menu/menu3d", "cem3d1icn00", 0xffff);
    if (self->param != 0) {
        self->unk_5c = self->param;
    }
    id = self->unk_5c;
    if (ItemCat0217fd70(id) == 1) {
        a = Param_Get(id);
        b = func_0206f080(id);
        e = (u8 *)self->unk_3c->vfunc_74(a, id, (u16)b, 1);
        LFLD(s32, e, 0x10) = *Param_GetEntry(self->unk_5c);
        LFLD(s16, e, 0xa) = 0xb;
        LFLD(s32, e, 0x24) = 4;
    }
    {
        base = data_0214a424->items;
        for (i = 0; i < 100; i++) {
            n = base[i];
            iid = i | 0x2000;
            if (n > 0) {
                a = Param_Get(iid);
                b = func_0206f080(iid);
                e = (u8 *)self->unk_3c->vfunc_74(a, iid, (u16)b, n);
                LFLD(s32, e, 0x10) = *Param_GetEntry(self->unk_5c);
            }
        }
    }
    self->unk_3c->owner = self;
    self->unk_3c->onDecide = (UiItemFn)Task021cbf60_List3cOnDecide;
    self->unk_3c->onCursor = (UiItemFn)Task021cbf60_List3cOnCursor;
    {
        VObj *t = self->unk_3c;
        t->vfunc_a8(UiList_GetItemById(t, 0));
    }
    self->unk_3c->vfunc_08();
    self->unk_3c->flags &= ~2;
    o = (VObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_40 = (Lo021cadcc *)o;
    ((Lo021cadcc *)o)->rows = 2;
    self->unk_40->width = 0xf8;
    {
        Lo021cadcc *s = self->unk_40;
        s->posX = 4;
        s->posY = 0x96;
        s->posZ = -0xccd;
    }
    {
        Lo021cadcc *s = self->unk_40;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0xccd;
    }
    self->unk_40->slideMode = 1;
    Obj0215bb14_SetText(self->unk_40, MsgRes_GetString(g, 0x11d));
    self->unk_40->vfunc_70();
    self->unk_40->vfunc_08();
    o = (VObj *)Heap_Alloc(0x1e4);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb1b0;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb0b8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cafc0;
        o->vfunc_28();
    }
    self->unk_44 = (LoBase021cafc0_021cb0b8 *)o;
    self->unk_44->vfunc_10(MsgRes_GetString(g, 0x11c));
    self->unk_44->posZ = -0x666;
    self->unk_44->vfunc_08();
    self->unk_44->owner = self;
    self->unk_44->onDecide = (UiItemFn)Task021cbf60_List44OnDecide;
    self->unk_44->flags |= 2;
    self->unk_44->flags |= 4;
    o = (VObj *)Heap_Alloc(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    self->unk_48 = (Lo021cb5a8 *)o;
    ((Lo021cb5a8 *)o)->flags |= 0x4000000;
    self->unk_48->slideMode = 1;
    {
        Lo021cb5a8 *s = self->unk_48;
        s->posX = 0xa5;
        s->posY = 0x12;
        s->posZ = -0x99a;
    }
    {
        Lo021cb5a8 *s = self->unk_48;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = -0x99a;
    }
    self->unk_48->flags |= 0x20000000;
    self->unk_48->vfunc_f4(1, MsgRes_GetString(g, 0x32));
    self->unk_48->vfunc_08();
    TaskList_Insert(self);
}

}

}  // namespace m_Lo_0217fd70

// ---- Stub_02180350
namespace m_Stub_02180350 {

extern "C" {
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
}

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    u8 pad_08[4];
    u32 unk_0c_0 : 1;
    u32 unk_0c_1 : 1;
    u32 unk_0c_2 : 30;
} Inner02180350;

typedef struct {
    u8 pad_00[0xc];
    u32 unk_0c;
} Sub02180350;

extern "C" {

void Task021cbf60_UpdateActive(Task021cbf60 *self) {
    Inner02180350 *in = (Inner02180350 *)self->unk_44;
    u16 trig = data_02097dc8->trig;
    BOOL ok = FALSE;
    if (in->unk_0c_1 ? TRUE : FALSE) {
        if (in->unk_04 == 5 ? TRUE : FALSE) {
            ok = TRUE;
        }
    }
    if (!ok) {
        self->unk_3c->flags |= 4;
        return;
    }
    self->unk_3c->flags &= ~4;
    if (self->unk_5e != 0) {
        return;
    }
    if (trig & 2) {
        SndMgr_PlayVolume(data_02097e4c, 0x20, -1, -1, -1);
    }
}

}

}  // namespace m_Stub_02180350

// ---- Lo_02180400
namespace m_Lo_02180400 {

extern "C" {

void Task021cbf60_PreUpdate(Task021cbf60 *self) {
    switch (self->state) {
    case 8:
        self->unk_5e = 0;
        break;
    case 0xd: {
        bool ok;
        self->unk_44->vfunc_1c();
        ok = true;
        ok = ok & (self->unk_3c->vfunc_1c() == 0);
        ok = ok & (self->unk_40->vfunc_1c() == 0);
        ok = ok & (self->unk_48->vfunc_1c() == 0);
        if (ok) {
            self->vfunc_0c(0);
        }
        break;
    }
    }
    self->unk_50 += 0x8000;
    self->unk_54 += 0x8000;
    self->unk_50 = self->unk_50 < 0 ? 0x1000000 : self->unk_50;
    self->unk_54 = self->unk_54 < 0 ? 0x1000000 : self->unk_54;
    self->unk_50 %= 0x1000000;
    self->unk_54 %= 0x1000000;
}
}

}  // namespace m_Lo_02180400

// ---- Lo_02180524
namespace m_Lo_02180524 {

typedef void (*VoidFn)(void);
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 5; } B8;
extern "C" {
extern void *data_ov000_021ccd6c;
extern void *data_ov000_021ccd68;
extern void *data_0214a420;
extern void *data_ov000_021ccd70;
extern void *data_02149f0c;
extern u8 data_ov000_021ccd50[];
extern VObj *data_ov000_021ccd30;
void func_ov000_021b53a8(void *p);
void ActorMgr_Draw(void *p);
void EffectMgr_Draw(void *p);
void func_ov000_021bc6c0(void *p);
void func_0205a69c(void *p);

void Task021cbf60_PostUpdate(Task021cbf60 *self) {
    s32 ok;
    LoBase021cafc0_021cb0b8 *p;
    if (self->unk_5e == 0) {
        return;
    }
    p = self->unk_44;
    ok = 0;
    if (p->hidden ? 1 : 0) {
        if (p->state == 5 ? 1 : 0) {
            ok = 1;
        }
    }
    if (ok == 0) {
        return;
    }
    self->unk_3c->flags |= 2;
    self->unk_40->flags |= 2;
    self->unk_48->flags |= 2;
}

}

}  // namespace m_Lo_02180524

// ---- Model_021805a8
namespace m_Model_021805a8 {

extern "C" {

void Task021cbf60_Draw(Task021cbf60 *self) {
    Model *m = self->unk_4c;
    if (m != NULL) {
        Model_PlayPart(m, 0);
    }
    self->unk_3c->vfunc_20();
    self->unk_40->vfunc_20();
    self->unk_48->vfunc_20();
    self->unk_44->vfunc_20();
}

}

}  // namespace m_Model_021805a8

// ---- TaskList_02180754
namespace m_TaskList_02180754 {

extern "C" {

extern const u32 data_0208b318[];
extern Task *(*const data_ov000_021c9c6c[])(void);
void *Heap_Alloc(u32 size);

static inline Task *TaskList_Find02180754(s32 id) {
    Task *task;
    for (task = (Task *)data_ov000_021ccd3c; task != NULL; task = task->next) {
        if (task->id == id) {
            return task;
        }
    }
    return NULL;
}

void TaskHost_Create(s32 id, s32 arg) {
    TaskHost *h = (TaskHost *)Heap_Alloc(sizeof(TaskHost));
    s32 mode;
    if (h != NULL) {
        *(const u32 **)&h->res = data_0208b318;
        h->res.vfunc_08();
        h->unk_00 = 0;
        h->unk_04 = 1;
        h->task = NULL;
    }
    data_ov000_021ccd44 = h;
    data_ov000_021ccd34 = 1;
    h->task = TaskList_Find02180754(id);
    if (h->task == NULL) {
        Task *(*fn)(void) = data_ov000_021c9c6c[id];
        h->task = fn != NULL ? fn() : NULL;
        h->task->param = arg;
        h->task->parent = (Task *)data_ov000_021ccd40;
        mode = 1;
    } else {
        mode = 2;
    }
    if (h->task != NULL) {
        h->mode = mode;
    }
}

void TaskHost_Destroy(void) {
    Task *task;
    Task *next;
    void *saved;
    void *saved2;
    TaskHost *p;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    p = data_ov000_021ccd44;
    if (p != NULL) {
        if (p != NULL) {
            p->res.vfunc_0c();
            task = (Task *)data_ov000_021ccd3c;
            while (task != NULL) {
                next = task->next;
                saved2 = data_02097dd0->cur;
                data_02097dd0->cur = data_02097dd0->heapHi;
                if (task != NULL) {
                    if (task != NULL) {
                        task->vfunc_04();
                    }
                    task = NULL;
                }
                data_02097dd0->cur = saved2;
                task = next;
            }
            data_ov000_021ccd34 = 0;
            data_ov000_021ccd3c = NULL;
            data_ov000_021ccd40 = NULL;
            *(const u32 **)&p->res = data_0208b318;
            p->res.vfunc_0c();
            Heap_Free(p);
        }
        data_ov000_021ccd44 = NULL;
    }
    data_02097dd0->cur = saved;
}

}

}  // namespace m_TaskList_02180754

// ---- Stub_02180838
namespace m_Stub_02180838 {

extern "C" {

s32 func_ov000_02180838(void *self) {
    return VOBJ_AT(self, 0x8)->vfunc_2c();
}

}

}  // namespace m_Stub_02180838

// ---- Lo_0218084c
namespace m_Lo_0218084c {

typedef struct {
    VecFx32 pos;
    u16 unk_0c;
    u16 mask;
    u16 kind;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 exclude;
    u8 flags;
} Query;

typedef struct {
    Query *query;
} Finder;

extern "C" {
s32 Finder_CollectParts(Finder *self, Query *q, void **out, s32 max);
s32 Finder_CollectActors(Finder *self, Query *q, void **out, s32 max);
BOOL History_SetState(void *a, s32 b, s32 c);

void *TaskHost_RequestSwitch(TaskHost *cur, s32 kind, s32 c) {
    s32 st;
    data_ov000_021ccd34 = 1;
    cur->task = LoFindTask(kind);
    if (cur->task == NULL) {
        LoCreateFn fn = data_ov000_021c9c6c[kind];
        cur->task = fn != NULL ? (Task *)fn() : NULL;
        cur->task->param = c;
        cur->task->parent = (Task *)data_ov000_021ccd40;
        st = 1;
    } else {
        st = 2;
    }
    if (cur->task != NULL) {
        cur->mode = st;
    }
    return cur->task;
}

static inline Actor *MgrFind(ActorMgr *mgr, u16 id) {
    ActorGroup *group;
    Actor *actor;
    Actor *ret = NULL;
    if (id != 0xffff) {
        group = ActorMgr_FindGroupIn(mgr, id);
        if (group != NULL) {
            for (actor = group->head; actor != NULL; actor = actor->next) {
                if (id == actor->id) {
                    ret = actor;
                    break;
                }
            }
        }
    }
    return ret;
}

static inline Actor *FindActor2(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    return mgr != NULL ? MgrFind(mgr, id) : NULL;
}

extern u8 data_0208ccc8[];

static inline BOOL LoTakeMode(TaskHost *self) {
    VObj *cur = (VObj *)data_ov000_021ccd40;
    if (self->mode != 0) {
        if (cur != NULL) {
            LFLD(u32, cur, 4) |= 2;
        }
        if (self->mode == 1) {
            self->unk_04 = 5;
        } else {
            self->unk_04 = 7;
        }
        self->mode = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_02180900(TaskHost *self) {
    Task *t;
    VObj *cur;
    u32 saved;
    Task *next;
    if (self->unk_04 == 0) {
        return FALSE;
    }
    cur = (VObj *)data_ov000_021ccd40;
    switch (self->unk_04) {
    case 1:
        self->unk_04 = 2;
    case 2:
        self->unk_04 = 3;
    case 3:
        self->unk_4c = 7;
        self->res.vfunc_1c(LFLD(void *, data_0208ccc8, 0));
        self->unk_04 = 12;
        break;
    case 12:
        if (!LoTakeMode(self)) {
            if (self->unk_00_0) {
                if (cur != NULL) {
                    cur->vfunc_0c(0);
                }
            } else {
                data_ov000_021ccd34 = 0;
            }
        }
        break;
    case 5:
        self->task->vfunc_10();
        self->unk_04 = 6;
    case 6:
        if (!self->task->vfunc_14()) {
            break;
        }
        self->unk_04 = 7;
    case 7:
        if (cur != NULL) {
            break;
        }
        for (t = (Task *)data_ov000_021ccd3c; t != NULL; t = next) {
            next = t->next;
            if (t->unk_04_2) {
                if (t->prev != NULL) {
                    t->prev->next = next;
                } else {
                    data_ov000_021ccd3c = next;
                }
                if (t->next != NULL) {
                    t->next->prev = t->prev;
                }
                t->prev = NULL;
                t->next = NULL;
                LO_HEAP_PUSH(saved);
                if (t != NULL) {
                    if (t != NULL) {
                        t->vfunc_04();
                    }
                }
                LO_HEAP_POP(saved);
            }
        }
        if (!LoTakeMode(self)) {
            if (self->task != NULL) {
                self->task->vfunc_50();
                self->task->vfunc_18();
                self->task = NULL;
                self->unk_04 = 12;
                break;
            }
            data_ov000_021ccd38 = 0;
            self->unk_04 = 0;
            self->unk_00_1 = 1;
            return FALSE;
        }
        break;
    }
    for (t = (Task *)data_ov000_021ccd3c; t != NULL; t = next) {
        next = t->next;
        t->vfunc_68();
    }
    return TRUE;
}

}

}  // namespace m_Lo_0218084c

// ---- Obj_02180bec
namespace m_Obj_02180bec {

class Obj021810e8 : public VObj {
public:
    s32 unk_04;
    u8 unk_08[0x30];
    VObj *unk_38;
    s32 unk_3c;
    Obj021810e8 *unk_40;
    Obj021810e8 *unk_44;
    Obj021810e8 *unk_48;
};

extern "C" {

extern u8 data_ov000_021cbae0[];
extern u8 data_ov000_021cbb60[];
extern u8 data_ov000_021cbc60[];
extern u8 data_ov000_021cbd60[];
extern u8 data_ov000_021cbde0[];
extern u8 data_ov000_021cbe60[];
extern u8 data_ov000_021cbee0[];
extern u8 data_ov000_021cbf60[];
extern u8 data_ov000_021cbfe0[];
extern u8 data_ov000_021cc060[];
extern u8 data_0208ba70[];
extern u8 data_ov000_021cbac8[];
extern u8 data_ov000_021cbbe0[];
extern u8 data_ov000_021cbce0[];
void ListRow_Unlink(void *ptr);

void Heap_Free(void *ptr);
void Task021cbf60_FreeWindows(Task021cbf60 *self);
void Task021cbe60_FreeWindows(VObj *self);

void Task_Load(void) {
}

BOOL Task_IsLoaded(void) {
    return TRUE;
}

void Task_Start(void) {
}

void func_ov000_02180bfc(Obj021810e8 *self) {
    Obj021810e8 *obj;
    Obj021810e8 *next;
    if (self->unk_04 == 0 || (obj = (Obj021810e8 *)data_ov000_021ccd3c) == NULL) {
        return;
    }
    do {
        next = (Obj021810e8 *)obj->unk_38;
        obj->vfunc_74();
        obj = next;
    } while (obj != NULL);
}

VObj *Task021cbf60_DtorDelete(Task021cbf60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbf60);
    Task021cbf60_FreeWindows(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

VObj *Task021cbf60_Dtor(Task021cbf60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbf60);
    Task021cbf60_FreeWindows(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbae0_DtorDelete(Task021cbae0 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbae0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

VObj *Task021cbae0_Dtor(Task021cbae0 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbae0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbb60_DtorDelete(Task021cbb60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbb60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

VObj *Task021cbb60_Dtor(Task021cbb60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbb60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbc60_DtorDelete(Task021cbc60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbc60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

VObj *Task021cbc60_Dtor(Task021cbc60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbc60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbd60_DtorDelete(Task021cbd60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbd60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

VObj *Task021cbd60_Dtor(Task021cbd60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbd60);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbde0_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbde0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

VObj *Task021cbde0_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbde0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbe60_DtorDelete(Task021cbe60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbe60);
    Task021cbe60_FreeWindows(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

VObj *Task021cbe60_Dtor(Task021cbe60 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbe60);
    Task021cbe60_FreeWindows(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbee0_DtorDelete(Task021cbee0 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbee0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

VObj *Task021cbee0_Dtor(Task021cbee0 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbee0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbfe0_DtorDelete(Task021cbfe0 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbfe0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

BOOL Task021cbfe0_TryReleaseCurrent(Obj021810e8 *self) {
    if (self->unk_3c != 0) {
        return FALSE;
    }
    if (self->vfunc_54()) {
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd38 = ((Task *)data_ov000_021ccd40)->id;
        } else {
            data_ov000_021ccd38 = 0;
        }
        data_ov000_021ccd40 = NULL;
    }
    return TRUE;
}

VObj *Task021cbfe0_Dtor(Task021cbfe0 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbfe0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbbe0_DtorDelete(Task021cbbe0 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbbe0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x3f8), data_0208ba70);
    VOBJ_AT(self, 0x3f8)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x340), data_0208ba70);
    VOBJ_AT(self, 0x340)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x288), data_0208ba70);
    VOBJ_AT(self, 0x288)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x1d0), data_0208ba70);
    VOBJ_AT(self, 0x1d0)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x118), data_0208ba70);
    VOBJ_AT(self, 0x118)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x60), data_0208ba70);
    VOBJ_AT(self, 0x60)->vfunc_08();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

static inline BOOL IsState5(Obj021810e8 *obj) {
    return obj->unk_04 == 5 ? TRUE : FALSE;
}

BOOL Task021cbbe0_TryReleaseCurrent(Obj021810e8 *self) {
    if (self->unk_40 != NULL && !IsState5(self->unk_40)) {
        return FALSE;
    }
    if (self->unk_44 != NULL && !IsState5(self->unk_44)) {
        return FALSE;
    }
    if (self->unk_48 != NULL && !IsState5(self->unk_48)) {
        return FALSE;
    }
    if (self->vfunc_54()) {
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd38 = ((Task *)data_ov000_021ccd40)->id;
        } else {
            data_ov000_021ccd38 = 0;
        }
        data_ov000_021ccd40 = NULL;
    }
    return TRUE;
}

VObj *Task021cbbe0_Dtor(Task021cbbe0 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbbe0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x3f8), data_0208ba70);
    VOBJ_AT(self, 0x3f8)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x340), data_0208ba70);
    VOBJ_AT(self, 0x340)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x288), data_0208ba70);
    VOBJ_AT(self, 0x288)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x1d0), data_0208ba70);
    VOBJ_AT(self, 0x1d0)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x118), data_0208ba70);
    VOBJ_AT(self, 0x118)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x60), data_0208ba70);
    VOBJ_AT(self, 0x60)->vfunc_08();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Task021cbce0_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbce0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

VObj *Task021cbce0_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbce0);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *Ov000Vt_021cbac8_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbac8);
    ListRow_Unlink(self);
    Heap_Free(self);
    return self;
}

void func_ov000_0218148c(void) {
}

void func_ov000_02181490(void) {
}

VObj *Ov000Vt_021cbac8_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbac8);
    ListRow_Unlink(self);
    return self;
}

VObj *Task_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

}

}  // namespace m_Obj_02180bec
