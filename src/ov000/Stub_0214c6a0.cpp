#include "ov000/VObj.h"

typedef struct {
    const void *vtbl;
    u32 unk_04;
    u8 unk_08[0x20];
    s32 unk_28;
    u8 unk_2c[0x8c];
    u32 unk_b8_0 : 4;
    u32 unk_b8_4 : 28;
    u8 unk_bc[0xab4];
    s32 unk_b70;
    s32 unk_b74;
    u8 unk_b78[0x4];
    s32 unk_b7c;
} Obj0214c6b4;

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x74];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    u8 unk_90[0xb8];
    u8 unk_148[0xb8];
    Obj0214c6b4 *unk_200;
    s32 unk_204;
    u16 unk_208;
    u16 unk_20a;
    s32 unk_20c;
    s32 unk_210;
    s32 unk_214;
    s32 unk_218;
} Obj0214c668;

typedef struct {
    u8 unk_00[0x5a];
    u16 unk_5a;
} Shared02fe1534;

extern "C" {

extern const u8 data_0208ba70[];
extern const u8 data_0208bbc8[];
extern Shared02fe1534 data_02fe1534;

void *func_0203dd9c(u32 size);
void func_0204c7d0(void *obj);
void func_02050f70(void *obj);

static inline void Obj0214c6b4_SetParams(Obj0214c6b4 *obj, s32 a, s32 b) {
    obj->unk_b7c = a;
    obj->unk_b70 = 0;
    obj->unk_b74 = b;
}

void func_ov000_0214c668(Obj0214c668 *self, u16 delay) {
    if (self->unk_20a != 0) {
        self->unk_20a += delay;
        return;
    }
    self->unk_0c |= 0x10000;
    self->unk_20a = delay;
    self->unk_20c = 0;
    self->unk_210 = 0;
}

BOOL func_ov000_0214c6a0(void *self) {
    return (*(u32 *)((u8 *)self + 0xc) & 0x30000) != 0;
}

void func_ov000_0214c6b4(Obj0214c668 *self, s32 a, s32 b, s32 c) {
    Obj0214c6b4 *obj;

    self->unk_204 = c;
    obj = (Obj0214c6b4 *)func_0203dd9c(0xb80);
    if (obj != NULL) {
        obj->vtbl = data_0208ba70;
        func_0204c7d0(obj);
        obj->vtbl = data_0208bbc8;
        func_02050f70(obj);
    }
    self->unk_200 = obj;
    obj->unk_28 = 8;
    Obj0214c6b4_SetParams(self->unk_200, a, b);
    self->unk_200->unk_b8_0 = 4;
    self->unk_200->unk_04 |= 4;
    self->unk_0c |= 2;
}

void func_ov000_0214c750(Obj0214c668 *self) {
    self->unk_84 = 0;
    self->unk_88 = 0;
    self->unk_8c = 0;
    func_0204c7d0(self->unk_90);
    func_0204c7d0(self->unk_148);
    self->unk_200 = NULL;
    self->unk_204 = 0;
    self->unk_208 = data_02fe1534.unk_5a;
    self->unk_20a = 0;
    self->unk_20c = 0;
    self->unk_210 = 0;
    self->unk_214 = 0;
    self->unk_218 = 0;
}

}
