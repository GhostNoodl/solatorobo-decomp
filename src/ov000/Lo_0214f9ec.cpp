#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *data_02fe152c;
extern u8 data_ov000_021ccd24[];
extern void *data_02097e4c;
void *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
u16 func_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL StageRes_IsAllLoaded(void *p);
void func_0204c7d0(void *p);
void *Task_FindById(s32 kind);
Robo021ca458 *func_ov000_0219bf90(void);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
} LoBits8;

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 7;
    u32 unk_04;
} LoOam;

static inline BOOL LoIsLoaded24(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(LFLD(void *, data_ov000_021ccd24, 8))) {
        r = FALSE;
    }
    return r;
}

void func_ov000_0214f9ec(Lo021caa44 *self) {
    s32 s;
    if (self->unk_24 == 0 || (s = self->unk_08) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (self->unk_4c != NULL) {
        self->unk_4c->vfunc_20();
    }
    if ((VObj *)self->unk_50 != NULL) {
        ((VObj *)self->unk_50)->vfunc_20();
    }
    if (self->unk_5c != NULL) {
        self->unk_5c->vfunc_20();
    }
    self->vfunc_78();
    if (self->unk_60 != NULL) {
        self->unk_60->vfunc_20();
    }
}

}
