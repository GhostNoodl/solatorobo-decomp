#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_02149ef8;
extern void *data_02097ce0;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_02054f10(void *p, s32 a);
s32 func_02061d54(u16 a);
s32 func_0204c0e8(void *p, s32 a);
void func_ov000_0215c1bc(void *self, s32 id, s32 v);
void func_0203df0c(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, s32 f);

typedef struct {
    u8 pad[0x98];
    VObj *arr[12];
} LoArr98;

void func_ov000_0215cef8(void *self) {
    s32 i;
    LFLD(s32, self, 0x1c) = 4;
    LFLD(s32, self, 0x84) = 0x854;
    LFLD(u16, self, 0x88) = 0;
    LFLD(s32, self, 0x8c) = 0;
    LFLD(s32, self, 0x90) = 0;
    LFLD(s32, self, 0x94) = 0;
    for (i = 0; i < 12; i++) {
        LFLD(s32, (u8 *)self + i * 4, 0x98) = 0;
    }
}

void func_ov000_0215cf38(LoArr98 *self) {
    s32 i;
    for (i = 0; i < 12; i++) {
        u32 saved;
        VObj *p;
        LO_HEAP_PUSH(saved);
        p = self->arr[(u32)i];
        if (p != NULL) {
            if (p != NULL) {
                p->vfunc_04();
            }
            self->arr[i] = NULL;
        }
        LO_HEAP_POP(saved);
    }
    if (LFLD(void *, self, 0x8c) != NULL) {
        func_0203df0c(LFLD(void *, self, 0x8c));
        LFLD(void *, self, 0x8c) = NULL;
    }
    if (LFLD(void *, self, 0x90) != NULL) {
        func_0203df0c(LFLD(void *, self, 0x90));
        LFLD(void *, self, 0x90) = NULL;
    }
}

}
