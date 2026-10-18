#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_022170d8[];
extern const u8 data_ov014_0221643a[];
extern const u8 data_ov014_02216480[];
extern const char *const data_ov014_02216430[];
extern void *data_02097e4c;
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_02035b90(void *a, s32 b);
extern void func_ov000_021903b4(void *p);
extern void func_0203f364(Ov014Sub48 *p);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov014Actor *self, const void *p);
extern void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov003_021cf1f0(void *a, s32 b, s32 c, const void *d);
extern Ov014Actor *func_ov000_0219bf90(void);
extern void func_ov003_021ceff4(void *p);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_021911c8(void *a, s32 b);

void func_ov014_021fad9c(Ov014Actor *self) {
    const char *anim;
    if (self->unk_40->state != 0) {
        return;
    }
    anim = data_ov014_02216430[0];
    func_ov000_02190cb0(self->unk_38, anim, 0x111, 0);
    func_ov000_021911c8(self->unk_38, 0x1ec);
    func_ov000_021915a0(self->unk_38);
    func_ov000_02190cb0((u8 *)self + 0x25c, anim, 0x111, 0);
    func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
    func_ov000_021915a0((u8 *)self + 0x25c);
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    self->unk_40->state++;
}

}
