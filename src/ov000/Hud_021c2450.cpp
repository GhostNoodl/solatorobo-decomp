#include "ov000/TaskList.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 2;
    u32 lay : 5;
    u32 rest : 25;
} MdlFlags021c2450;

typedef struct {
    u32 b0 : 2;
    u32 vis : 1;
    u32 b3 : 5;
    u32 pri : 5;
    u32 rest : 19;
} TxtFlags021c2450;

class Txt021c2450 : public VObj {
public:
    TxtFlags021c2450 flags;
};

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} F021c2450;

extern "C" {
extern char *data_0208cc88;
extern char *data_0208cc94;
extern char *data_0208cb7c;
extern char data_0214b105[];
extern char data_ov000_021cc9bc[];
extern void *data_0208ba70[];
extern u8 *data_02097ce0;
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_02041c5c(Model *m, void *fn);
void *func_ov000_021c7608(u8 *self, u16 *cmd, void *arr, u16 *count);

static inline BOOL Txt_IsVis021c2450(Txt021c2450 *t) {
    return t->flags.vis ? TRUE : FALSE;
}

static inline void SetText021c2450(u8 *self, char *str0) {
    u8 *t;
    char *str = str0;
    if (LFLD(void *, self, 0x38) == NULL) {
        t = (u8 *)func_0203dd9c(0xb8);
        if (t != NULL) {
            *(void ***)t = data_0208ba70;
            func_0204c7d0(t);
        }
        LFLD(u8 *, self, 0x38) = t;
    }
    LFLD(VObj *, self, 0x38)->vfunc_08();
    LFLD(s32, LFLD(void *, self, 0x38), 0x28) = 8;
    t = LFLD(u8 *, self, 0x38);
    LFLD(char *, t, 0x24) = str;
    LFLD(s32, t, 0x4c) = func_0204c4fc(LFLD(s32, t, 0x28), LFLD(s32, t, 0x38), LFLD(s32, t, 0x24), t + 0x44, t + 0x48, LFLD(s8, t, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, t, 0x28);
    LFLD(Txt021c2450 *, self, 0x38)->flags.pri = 0x1e;
    LFLD(VObj *, self, 0x38)->vfunc_14();
    LFLD(u32, LFLD(void *, self, 0x38), 0x4) |= 0x40;
    LFLD(u32, LFLD(void *, self, 0x38), 0x4) |= 0x1000000;
    LFLD(u32, LFLD(void *, self, 0x38), 0x4) |= 0x400000;
    LFLD(u32, LFLD(void *, self, 0x38), 0x4) |= 0x200000;
    LFLD(u32, LFLD(void *, self, 0x38), 0x4) |= 0x4;
    LFLD(char *, self, 0x40) = str;
}

void func_ov000_021c2450(u8 *self) {
    Model *m;
    Model *m2;
    if (LFLD(u8, self, 0x44) == 0) {
        m = (Model *)func_0203dd9c(sizeof(Model));
        if (m != NULL) {
            char *name = data_0208cc94;
            char *a = data_0208cc88;
            func_02041218(m->unk_88);
            func_02041440(m, a, 0);
            STD_CopyString(m->unk_2c, name);
        }
        LFLD(Model *, self, 0x30) = m;
        func_020417e0(LFLD(Model *, self, 0x30), func_02034d88(func_02035d5c((char *)m->unk_2c), LFLD(Model *, self, 0x30)->unk_2c + 0x20));
        LFLD(Model *, self, 0x30)->unk_6c |= 2;
        func_02041d9c(LFLD(Model *, self, 0x30), 0, 6);
        func_02041c20(LFLD(Model *, self, 0x30), 6, LFLD(void *, self, 0x3c));
        func_02041c5c(LFLD(Model *, self, 0x30), (void *)func_ov000_021c7608);
        LFLD(Model *, self, 0x30)->unk_6c |= 0x80000;
        ((MdlFlags021c2450 *)&LFLD(Model *, self, 0x30)->unk_6c)->lay = 0x1e;
        LFLD(Model *, self, 0x30)->unk_6c |= 0x100000;

        m2 = (Model *)func_0203dd9c(sizeof(Model));
        if (m2 != NULL) {
            char *a = data_0208cb7c;
            func_02041218(m2->unk_88);
            func_02041440(m2, a, 0);
            STD_CopyString(m2->unk_2c, data_0214b105);
        }
        LFLD(Model *, self, 0x34) = m2;
        func_020417e0(LFLD(Model *, self, 0x34), func_02034d88(func_02035d5c((char *)m2->unk_2c), LFLD(Model *, self, 0x34)->unk_2c + 0x20));
        LFLD(Model *, self, 0x34)->unk_6c |= 2;
        func_02041d9c(LFLD(Model *, self, 0x34), 0, 4);
        LFLD(Model *, self, 0x34)->unk_6c |= 0x80000;
        ((MdlFlags021c2450 *)&LFLD(Model *, self, 0x34)->unk_6c)->lay = 0x1e;
        LFLD(Model *, self, 0x34)->unk_6c |= 0x100000;
        if (LFLD(void *, self, 0x38) == NULL) {
            SetText021c2450(self, data_ov000_021cc9bc);
        }
        LFLD(u8, self, 0x44) = 1;
        return;
    }
    if (LFLD(F021c2450, self, 0x20).b0) {
        if (Txt_IsVis021c2450(LFLD(Txt021c2450 *, self, 0x38))) {
            return;
        }
        SetText021c2450(self, LFLD(char *, self, 0x40));
    } else {
        if (!Txt_IsVis021c2450(LFLD(Txt021c2450 *, self, 0x38))) {
            return;
        }
        LFLD(VObj *, self, 0x38)->vfunc_08();
        LFLD(Txt021c2450 *, self, 0x38)->flags.vis = 0;
    }
}
}
