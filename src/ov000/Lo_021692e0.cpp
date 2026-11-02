#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern s32 data_02097d78[5];
BOOL func_02054f10(void *a, s32 b);
extern void *data_0208cc94;
extern void *data_0208cc88;
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);
extern u8 data_ov000_021c9ab0[];
extern s32 data_ov000_021c9bb4[];

typedef struct {
    s32 a;
    u8 **list;
} LoPair;

typedef struct {
    s32 a;
    s32 b;
} LoIdx2;

static inline BOOL LoGBusy(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL LoGIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (LoGBusy(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL LoD78Idle(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

void func_ov000_021692e0(Lo021cb7ec *self) {
    void *res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    u8 *m = (u8 *)Heap_Alloc(0x160);
    if (m) {
        void *nm = data_0208cc88;
        func_02041218((struct PlttRes *)(m + 0x88));
        func_02041440(m, nm, 0);
    }
    self->unk_9c = m;
    func_020417e0(m, res);
    LFLD(u32, self->unk_9c, 0x6c) |= 2;
    LFLD(u32, self->unk_9c, 0x6c) |= 0x200000;
    LFLD(u32, self->unk_9c, 0x6c) |= 0x80000;
    func_02041d9c(self->unk_9c, 0, 1);
    self->unk_30 = 0xc000;
    self->unk_50 = 0x30;
    self->unk_54 = 3;
    self->unk_28 = 0;
    self->unk_0c |= 0x360;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = 0xffffe333;
    func_ov000_0215fdfc(self, 2, data_ov000_021c9ab0);
}

BOOL func_ov000_021693e0(Lo021cb7ec *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        LBIT(self, 0xc).b1 = 1;
    }
    switch (self->unk_04) {
    case 6:
        if (!LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            self->unk_04 = 0;
            return TRUE;
        }
        return FALSE;
    case 1:
        if (!func_02054f10(self->unk_9c, 0xffff)) {
            return FALSE;
        }
        LBIT(self, 0xc).b3 = 1;
        break;
    }
    return TRUE;
}

}
