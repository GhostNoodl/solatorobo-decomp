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
BOOL func_0205a9c8(void *p);
void func_0204c7d0(void *p);
void *func_ov000_02173610(s32 kind);
void *func_ov000_0219bf90(void);
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
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd24, 8))) {
        r = FALSE;
    }
    return r;
}

void func_ov000_02150c38(Lo021ca9c4 *self) {
    self->unk_20 = 0x1000;
    self->unk_3c = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0xffff;
    func_0204c7d0((u8 *)self + 0x60);
    func_0204c7d0((u8 *)self + 0x118);
    func_0204c7d0((u8 *)self + 0x1d0);
    func_0204c7d0((u8 *)self + 0x288);
    func_0204c7d0((u8 *)self + 0x340);
    func_0204c7d0((u8 *)self + 0x3f8);
    self->unk_40 = 0xffff;
    self->unk_42 = 0xffff;
}

}
