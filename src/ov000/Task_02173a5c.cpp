#include "ov000/VObj.h"

class Task02173a5c : public VObj {
public:
    u8 pad_04[8];
    s32 unk_0c;
    u8 pad_10[4];
    s32 unk_14;
    u8 pad_18[0x14];
    s32 unk_2c;
    u8 pad_30[8];
    Task02173a5c *next;
};

typedef struct {
    u32 unk_00_0 : 2;
    u32 mode : 2;
    u32 unk_00_4 : 28;
    u8 pad_04[0x50];
    Task02173a5c *unk_54;
} Holder02173a5c;

typedef struct {
    u8 unk_00;
    u32 unk_04;
    Task02173a5c *head;
    Task02173a5c *unk_0c;
    Holder02173a5c *unk_10;
} TaskList02173a5c;

typedef struct {
    u8 pad[0xe];
    u8 b0 : 2;
    u8 b2 : 2;
    u8 b4 : 4;
} Player02173a5c;

class Obj02173a5c : public VObj {
public:
    u8 pad_04[4];
    s32 state;
    u8 pad_0c[0x30];
    s32 unk_3c;
};

extern "C" {

extern TaskList02173a5c data_ov000_021ccd34;
extern Task02173a5c *(*const data_ov000_021c9c6c[])(void);
extern void *data_02097e4c;
extern u8 *data_02097d48;
extern Player02173a5c *data_ov000_021ccd54;
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_0204a160(void *a);
void func_0204a1c4(void *a);
void func_02043b20(void *p);

static inline Task02173a5c *TaskList_Find(s32 id) {
    Task02173a5c *task;
    for (task = data_ov000_021ccd34.head; task != NULL; task = task->next) {
        if (task->unk_14 == id) {
            return task;
        }
    }
    return NULL;
}

static inline void TaskList_Start(s32 id, s32 arg) {
    Holder02173a5c *h = data_ov000_021ccd34.unk_10;
    s32 mode;
    data_ov000_021ccd34.unk_00 = 1;
    h->unk_54 = TaskList_Find(id);
    if (h->unk_54 == NULL) {
        Task02173a5c *(*fn)(void) = data_ov000_021c9c6c[id];
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

void func_ov000_02173a5c(Obj02173a5c *self) {
    switch (self->state) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        func_0204a160(data_02097e4c);
        break;
    case 10:
        self->unk_3c = -0xcd;
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        func_0204a1c4(data_02097e4c);
        func_02043b20(data_02097d48 + 0x8b0);
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
