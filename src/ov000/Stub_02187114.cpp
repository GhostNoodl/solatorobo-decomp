#include "ov000/VObj.h"

extern "C" {

void func_ov006_021ccdc8();
extern void *data_ov007_021cfc60;
void func_ov007_021cd270(void *p);
void func_ov007_021cf1d8(void *p);

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void func_02049564(void *p, s32 a, s32 b);

static inline void Queue_Push(void *self, s32 cmd, s32 arg) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = cmd;
    ((s32 *)((u8 *)self + 0x50))[*index] = arg;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

void func_ov000_02187114(void) {
    func_ov006_021ccdc8();
}

void func_ov000_02187120(void) {
    func_ov007_021cd270(data_ov007_021cfc60);
}

void func_ov000_02187138(void) {
    func_ov007_021cf1d8(data_ov007_021cfc60);
}


void func_ov000_02187150(void *self, s32 arg) {
    func_02049564(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    Queue_Push(self, 0x26, 2);
    Queue_Push(self, 0x21, arg);
}

}
