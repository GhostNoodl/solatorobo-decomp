#include "ov000/MessageQueue.h"

extern "C" {

void BufferList_Run(BufferList *list, BOOL mode);
extern void *gTaskHost;
void TaskHost_DrawTasks(void *p);

void MessageQueue021cb980_Draw(MessageQueue021cb980 *self) {
    BufferList_Run(&self->list, 1);
    if (gTaskHost != NULL) {
        TaskHost_DrawTasks(gTaskHost);
    }
}

void MessageQueue021cb980_Push05(VObj *self) {
    self->vfunc_0c(0, 5, 0, 0);
}

void MessageQueue021cb980_Push06(VObj *self, s32 a, s32 b, s32 c) {
    self->vfunc_0c(0, 6, b, (a << 16) | c);
}

void MessageQueue021cb980_Push07(VObj *self, s32 a, s32 b) {
    self->vfunc_0c(0, 7, a, b);
}

void MessageQueue021cb980_Push08(VObj *self, s32 a, s32 b, s32 c) {
    self->vfunc_0c(0, 8, c, (a << 16) | b);
}


void MessageQueue021cb980_Push09_0a(VObj *self, s32 flag, s32 a) {
    if (flag) {
        self->vfunc_0c(0, 9, a, 0);
    } else {
        self->vfunc_0c(0, 10, a, 0);
    }
}
}
