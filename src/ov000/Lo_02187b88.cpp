#include "ov000/CmdObj.h"
#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    u8 c[3];
} Id3;

typedef struct {
    u8 b0 : 2;
    u8 mode : 2;
    u8 b4 : 4;
} Bits0e;

class CmdEx : public CmdObj {
public:
    u8 unk_ac;
    u8 pad_ad[3];
    VObj *unk_b0;
    u16 unk_b4;
    u8 pad_b6[0x14];
    Id3 unk_ca;
    Id3 unk_cd;
    Id3 unk_d0;
    u8 pad_d3[0xb9];
    u8 unk_18c;
    u8 unk_18d;
    u8 unk_18e;
    u8 unk_18f;
};

#define BITS0E(self) (*(Bits0e *)((u8 *)(self) + 0xe))

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
} Obj02097e48;

typedef struct {
    void *vtable;
    u32 unk_04;
} Task;

typedef struct {
    u8 pad_00[0x28];
    s32 unk_28;
    u8 pad_2c[4];
    s32 unk_30;
} Task118;

typedef struct {
    u8 pad_00[0x7c];
    void *unk_7c;
} Task11c;

typedef struct {
    u8 pad_00[0x118];
    Task118 *unk_118;
    Task11c *unk_11c;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0x46];
    u16 unk_46;
    u16 unk_48;
    u16 unk_4a;
} Dtcm02fe1534;

extern "C" {
extern Mgr021ccd30 *data_ov000_021ccd30;
extern s32 data_02097d78[];
extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb940[];
extern u8 data_ov000_021cb920[];
extern void *data_ov000_021ccd68;
extern Dtcm02fe1534 data_02fe1534;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a420;
extern void *data_ov000_021ccd6c;
extern void *data_ov000_021ccd64;
extern void *data_02149f0c;
extern void *data_02149ef0;

void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void *func_0203dd9c(u32 size);
void func_ov000_0216f144(Task *self);
void func_ov000_0216faac(Task *self);
void func_ov000_0216f828(Task *self);
void func_ov000_0216f398(Mgr021ccd30 *mgr, Task *task, s32 a, Mgr021ccd30 *b);
void func_ov000_0218e514(void *p, s32 a);
void func_0204aa10(void *p);
void func_ov000_0216bcbc(void *p);
void func_ov000_021645a4(s32 a);
void func_020656b4(void *p);
void func_ov000_021b53f4(void *p);
void func_ov000_0218be9c(void *p);
void func_ov000_0218e894(void *p);
void func_ov000_0216f42c(Mgr021ccd30 *mgr, void *task);
void func_0206222c(void);
void func_ov000_021819a4(u8 *p);
void func_0205b1b4(void);
void func_02059974(void *p);
void func_0204b270(void *p, s32 a, s32 b);

static inline BOOL IsIdle(s32 i) {
    return data_02097d78[3] == 0 && data_02097d78[i] == 0;
}

static inline BOOL IsMode4(s32 i) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[i] == 4;
    }
    return r;
}

static inline s32 TaskVal(Task118 *t) {
    return t->unk_28 != 1 ? 0 : t->unk_30;
}

static inline BOOL TaskHasVal(Task118 *t) {
    return (TaskVal(t) != 0 ? TRUE : FALSE) ? TRUE : FALSE;
}

s32 func_ov000_02187b88(CmdEx *self) {
    u16 mode = self->unk_a4;
    switch (mode) {
    case 0:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (IsIdle(0)) {
                func_0203c9e8(0x3f, -1);
                func_0203cc58(0, 2, -1);
            }
            self->step++;
            break;
        case 2:
            if (IsMode4(0)) {
                Mgr021ccd30 *mgr = data_ov000_021ccd30;
                if (mgr->unk_11c == NULL) {
                    Task *task = (Task *)func_0203dd9c(0x80);
                    if (task != NULL) {
                        task->vtable = data_ov000_021cb6d0;
                        func_ov000_0216f144(task);
                        task->vtable = data_ov000_021cb940;
                        func_ov000_0216faac(task);
                    }
                    mgr->unk_11c = (Task11c *)task;
                    func_ov000_0216f398(mgr, task, 0x10000, mgr);
                    ((Task *)mgr->unk_11c)->unk_04 |= 0x10;
                }
                mgr = data_ov000_021ccd30;
                if (mgr->unk_118 == NULL) {
                    Task *task = (Task *)func_0203dd9c(0x34);
                    if (task != NULL) {
                        task->vtable = data_ov000_021cb6d0;
                        func_ov000_0216f144(task);
                        task->vtable = data_ov000_021cb920;
                        func_ov000_0216f828(task);
                    }
                    mgr->unk_118 = (Task118 *)task;
                    func_ov000_0216f398(mgr, task, 0x10000, mgr);
                    ((Task *)mgr->unk_118)->unk_04 |= 0x10;
                }
                CmdObj_Done(self);
            }
            break;
        }
        break;
    case 1:
    case 2:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (IsIdle(0)) {
                func_0203c9e8(0x3f, 0);
                func_0203cc58(0x1e000, 2, 0);
            }
            if (IsIdle(1)) {
                func_0203c9e8(0x3f, 1);
                func_0203cc58(0x1e000, 2, 1);
            }
            self->step++;
            return 1;
        case 2:
            if (!IsMode4(0)) {
                return 1;
            }
            if (!IsMode4(1)) {
                return 1;
            }
            self->step++;
            break;
        case 3: {
            Id3 id;
            id.c[0] = 0xff;
            id.c[1] = 0xff;
            id.c[2] = 0xff;
            self->unk_cd = id;
            func_ov000_0218e514(data_ov000_021ccd68, 0xf000);
            data_02fe1534.unk_46 = 0xffff;
            data_02fe1534.unk_48 = 0xffff;
            data_02fe1534.unk_4a = 0xffff;
            HEAP_DELETE_VOBJ(self->unk_b0);
            self->unk_b4 = 0xffff;
            func_0204aa10(data_02097e48);
            data_02097e48->b2 = 0;
            self->unk_d0 = self->unk_ca;
            self->unk_ca = self->unk_cd;
            BITS0E(self).mode = 2;
            if (data_ov000_021ccd30->unk_11c != NULL && data_ov000_021ccd30->unk_11c->unk_7c != NULL) {
                func_ov000_0216bcbc(data_ov000_021ccd30->unk_11c->unk_7c);
            }
            {
                Mgr021ccd30 *mgr = data_ov000_021ccd30;
                BOOL has;
                if (mgr->unk_118 == NULL) {
                    has = FALSE;
                } else {
                    has = TaskHasVal(mgr->unk_118);
                }
                if (has) {
                    func_ov000_021645a4(TaskVal(mgr->unk_118));
                }
            }
            self->unk_18c = 0;
            self->unk_18d = 0;
            self->unk_18e = 0;
            self->unk_18f = 0;
            func_020656b4(data_0214a420);
            func_ov000_021b53f4(data_ov000_021ccd6c);
            func_ov000_0218be9c(data_ov000_021ccd64);
            func_ov000_0218e894(data_ov000_021ccd68);
            {
                Mgr021ccd30 *mgr = data_ov000_021ccd30;
                func_ov000_0216f42c(mgr, mgr->unk_11c);
                mgr->unk_11c = NULL;
            }
            {
                Mgr021ccd30 *mgr = data_ov000_021ccd30;
                func_ov000_0216f42c(mgr, mgr->unk_118);
                mgr->unk_118 = NULL;
            }
            if (mode == 2) {
                func_0206222c();
                func_ov000_021819a4(&self->unk_ac);
                func_0205b1b4();
                func_02059974(data_02149f0c);
                func_0204b270(data_02149ef0, -1, 0);
            }
            CmdObj_Done(self);
            return 1;
        }
        }
        break;
    }
    return 0;
}
}
