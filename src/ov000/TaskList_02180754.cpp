#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

class Task02180754 : public VObj {
public:
    u8 pad_04[8];
    s32 unk_0c;
    u8 pad_10[4];
    s32 unk_14;
    u8 pad_18[0x14];
    s32 unk_2c;
    u8 pad_30[8];
    Task02180754 *next;
};

typedef struct {
    u32 unk_00_0 : 2;
    u32 mode : 2;
    u32 unk_00_4 : 28;
    s32 unk_04;
    VObj res;
    u8 pad_0c[0x48];
    Task02180754 *unk_54;
} Holder02180754;

typedef struct {
    u8 unk_00;
    u32 unk_04;
    Task02180754 *head;
    Task02180754 *unk_0c;
    Holder02180754 *unk_10;
} TaskList02180754;

extern "C" {

extern TaskList02180754 data_ov000_021ccd34;
extern const u32 data_0208b318[];
extern Task02180754 *(*const data_ov000_021c9c6c[])(void);
void *func_0203dd9c(u32 size);

static inline Task02180754 *TaskList_Find02180754(s32 id) {
    Task02180754 *task;
    for (task = data_ov000_021ccd34.head; task != NULL; task = task->next) {
        if (task->unk_14 == id) {
            return task;
        }
    }
    return NULL;
}

void func_ov000_02180660(s32 id, s32 arg) {
    Holder02180754 *h = (Holder02180754 *)func_0203dd9c(sizeof(Holder02180754));
    s32 mode;
    if (h != NULL) {
        *(const u32 **)&h->res = data_0208b318;
        h->res.vfunc_08();
        *(u32 *)h = 0;
        h->unk_04 = 1;
        h->unk_54 = NULL;
    }
    data_ov000_021ccd34.unk_10 = h;
    data_ov000_021ccd34.unk_00 = 1;
    h->unk_54 = TaskList_Find02180754(id);
    if (h->unk_54 == NULL) {
        Task02180754 *(*fn)(void) = data_ov000_021c9c6c[id];
        h->unk_54 = fn != NULL ? fn() : NULL;
        h->unk_54->unk_0c = arg;
        h->unk_54->unk_2c = (s32)data_ov000_021ccd34.unk_0c;
        mode = 1;
    } else {
        mode = 2;
    }
    if (h->unk_54 != NULL) {
        h->mode = mode;
    }
}

void func_ov000_02180754(void) {
    Task02180754 *task;
    Task02180754 *next;
    void *saved;
    void *saved2;
    Holder02180754 *p;
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    p = data_ov000_021ccd34.unk_10;
    if (p != NULL) {
        if (p != NULL) {
            VOBJ_AT(p, 0x8)->vfunc_0c();
            task = data_ov000_021ccd34.head;
            while (task != NULL) {
                next = task->next;
                saved2 = data_02097dd0->current;
                data_02097dd0->current = data_02097dd0->unk_08;
                if (task != NULL) {
                    if (task != NULL) {
                        task->vfunc_04();
                    }
                    task = NULL;
                }
                data_02097dd0->current = saved2;
                task = next;
            }
            data_ov000_021ccd34.unk_00 = 0;
            data_ov000_021ccd34.head = NULL;
            data_ov000_021ccd34.unk_0c = NULL;
            *(const u32 **)((u8 *)p + 0x8) = data_0208b318;
            VOBJ_AT(p, 0x8)->vfunc_0c();
            func_0203de1c(p);
        }
        data_ov000_021ccd34.unk_10 = NULL;
    }
    data_02097dd0->current = saved;
}

}
