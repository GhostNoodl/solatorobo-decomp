#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x44];
    u8 *unk_44;
} Sub021c55e8;

typedef struct {
    u8 unk_00[0x14];
    u8 *unk_14;
    u8 unk_18[0xc];
    Sub021c55e8 *unk_24;
    u8 unk_28[0x4];
} Obj0215f514;

typedef struct {
    u8 unk_00[0xf4];
    Obj0215f514 *unk_f4;
    Obj0215f514 *unk_f8;
    Obj0215f514 *unk_fc;
} Obj021c55e8;

extern "C" {

void *func_0203dd9c(u32 size);
void func_ov000_0215f514(Obj0215f514 *p);
void func_ov000_0215f0ec(Obj0215f514 *p, s32 a);

static inline Obj0215f514 *New0215f514(void) {
    Obj0215f514 *p = (Obj0215f514 *)func_0203dd9c(sizeof(Obj0215f514));
    if (p != NULL) {
        func_ov000_0215f514(p);
    }
    return p;
}

void func_ov000_021c55e8(Obj021c55e8 *self, s32 a) {
    self->unk_f4 = New0215f514();
    func_ov000_0215f0ec(self->unk_f4, a);
    self->unk_f4->unk_14 = self->unk_f4->unk_24->unk_44 + 0x10;
}

void func_ov000_021c5630(Obj021c55e8 *self, s32 a) {
    self->unk_f8 = New0215f514();
    func_ov000_0215f0ec(self->unk_f8, a);
    self->unk_f8->unk_14 = self->unk_f8->unk_24->unk_44 + 0x10;
}

void func_ov000_021c5678(Obj021c55e8 *self, s32 a) {
    self->unk_fc = New0215f514();
    func_ov000_0215f0ec(self->unk_fc, a);
    self->unk_fc->unk_14 = self->unk_fc->unk_24->unk_44 + 0x10;
}

}
