#include "ov000/TaskList.h"

extern "C" {

bool func_ov000_021735e8(void) {
    return TaskList_HasTasks();
}

Task *func_ov000_02173610(s32 id) {
    Task *task;
    for (task = data_ov000_021ccd34.head; task != NULL; task = task->next) {
        if (task->id == id) {
            return task;
        }
    }
    return NULL;
}

void func_ov000_02173648(Task *task) {
    Task *cur = data_ov000_021ccd34.head;
    Task *prev;
    if (cur == NULL) {
        data_ov000_021ccd34.head = task;
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
                data_ov000_021ccd34.head = task;
            }
        }
    }
    task->vfunc_20();
}

void func_ov000_021736dc(void) {
    Task *task = data_ov000_021ccd34.head;
    Task *next;
    void *saved;
    if (task != NULL) {
        do {
            next = task->next;
            saved = data_02097dd0->current;
            data_02097dd0->current = data_02097dd0->unk_08;
            if (task != NULL) {
                if (task != NULL) {
                    task->vfunc_04();
                }
            }
            data_02097dd0->current = saved;
            task = next;
        } while (task != NULL);
    }
    data_ov000_021ccd34.unk_00 = 0;
    data_ov000_021ccd34.head = NULL;
    data_ov000_021ccd34.unk_0c = NULL;
}

VObj *func_ov000_02173754(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

#pragma force_active on
void func_ov000_02173784(void) {
    Task *task = data_ov000_021ccd34.head;
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
                data_ov000_021ccd34.head = next;
            }
            if (task->next != NULL) {
                task->next->prev = task->prev;
            }
            task->prev = NULL;
            task->next = NULL;
            saved = data_02097dd0->current;
            data_02097dd0->current = data_02097dd0->unk_08;
            if (task != NULL) {
                if (task != NULL) {
                    task->vfunc_04();
                }
            }
            data_02097dd0->current = saved;
        }
        task = next;
    } while (task != NULL);
}
#pragma force_active reset

VObj *func_ov000_02173824(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x90);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbce0);
        obj->vfunc_58();
    }
    obj->vfunc_08(1, 0);
    return obj;
}

void func_ov000_0217388c(void *a) {
    func_ov000_0214c1ac(a);
}

BOOL func_ov000_02173898(void) {
    Task *task = data_ov000_021ccd30->unk_11c->unk_54;
    BOOL ret = TRUE;
    if (task != NULL && !(*(s32 *)((u8 *)task + 4) == 4 ? TRUE : FALSE)) {
        ret = FALSE;
    }
    return ret;
}

}
