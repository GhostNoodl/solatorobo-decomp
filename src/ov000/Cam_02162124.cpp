#include "ov000/LoCommon.h"
#include "nitro/mi.h"

extern "C" {

extern u8 data_ov000_021cabc8[];
extern u8 data_ov000_021cabd8[];
extern u8 data_ov000_021cac02[];
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218ea20(void *p);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void *func_ov000_0218fe1c(void *p);
void *GfxCamPos_Init(void *p);
void MTX_Identity44_(void *m);

struct Obj02162124 {
    void *unk_00;
    void *unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0a;
    u8 unk_0b[0x70];
    u8 unk_7b;
    u8 unk_7c[0x62c];
    s32 unk_6a8;
    s32 unk_6ac;
    s32 unk_6b0;
    s32 unk_6b4;
    s32 unk_6b8;
    u8 unk_6bc;
    u8 unk_6bd[0x3];
    void *unk_6c0;
    s32 unk_6c4;
    u16 unk_6c8;
    u8 unk_6ca[0x2];
    s32 unk_6cc;
    s32 unk_6d0;
    s32 unk_6d4;
    s32 unk_6d8;
    s32 unk_6dc;
    s32 unk_6e0;
    u16 unk_6e4;
    u16 unk_6e6;
    u16 unk_6e8;
    u8 unk_6ea[0x2];
    s32 unk_6ec;
    s32 unk_6f0;
    s32 unk_6f4;
    s32 unk_6f8;
    s32 unk_6fc;
    s32 unk_700;
    s32 unk_704;
};

u8 *func_ov000_02162124(Obj02162124 *self) {
    self->unk_00 = data_ov000_021cabc8;
    self->unk_04 = data_ov000_021cabd8;
    __cxa_vec_ctor((u8 *)self + 0x7c, 2, 0x138, (void (*)(void *))func_ov000_0218e9c4, (void (*)(void *))func_ov000_0218ea20);
    __cxa_vec_ctor((u8 *)self + 0x2ec, 2, 0x138, (void (*)(void *))func_ov000_0218e9c4, (void (*)(void *))func_ov000_0218ea20);
    self->unk_08 = 0x14;
    self->unk_09 = 0;
    self->unk_0a = 0;
    MI_CpuFill8((u8 *)self + 0xb, 0, 0x20);
    MI_CpuFill8((u8 *)self + 0x2b, 0, 0x18);
    MI_CpuFill8((u8 *)self + 0x43, 0, 0x20);
    MI_CpuFill8((u8 *)self + 0x63, 0, 0x18);
    self->unk_7b = 0;
    func_ov000_0218fe1c((u8 *)self + 0x55c);
    GfxCamPos_Init((u8 *)self + 0x644);
    MTX_Identity44_((u8 *)self + 0x668);
    self->unk_6a8 = 0;
    self->unk_6ac = 0;
    self->unk_6b0 = 0;
    self->unk_6b4 = 0x1000;
    self->unk_6b8 = 0;
    self->unk_6bc = 0;
    self->unk_6c0 = data_ov000_021cac02;
    self->unk_6c4 = 0;
    self->unk_6c8 = 0x1000;
    self->unk_6cc = 0;
    self->unk_6d0 = 0;
    self->unk_6d4 = 0;
    self->unk_6d8 = 0;
    self->unk_6dc = 0;
    self->unk_6e0 = 0;
    self->unk_6e4 = 0;
    self->unk_6e6 = 0;
    self->unk_6e8 = 0;
    self->unk_6ec = 0;
    self->unk_6f0 = 0;
    self->unk_6f4 = 0;
    self->unk_6f8 = 0;
    self->unk_6fc = 0;
    self->unk_700 = 0;
    self->unk_704 = 0;
    return (u8 *)self;
}

void func_ov000_0218ec60(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218edf0(void *p, s32 a, s32 b, s32 c, s32 d);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));
void *func_ov000_0218fee4(void *p);

// Same slot helpers as Slot_02161cd4.cpp (the camera's sub-object at +4).
static inline void StopSlot02162294(u8 *self, u8 i) {
    if (i > 2) {
        return;
    }
    func_ov000_0218ec60(self + 0x78 + i * 0x138, 0, 0, 1, 0);
    func_ov000_0218edf0((u8 *)self + 0x78 + i * 0x138, 0, 0, 1, 0);
    LFLD(u16, self + i * 0x138, 0x78) = 0;
    func_ov000_0218edf0(self + 0x2e8 + i * 0x138, 0, 0, 1, 0);
    LFLD(u16, (u8 *)self + i * 0x138, 0x2e8) = 0;
}

static inline void SlotDtor02162294(u8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cabd8);
    StopSlot02162294(self, LFLD(u8, self, 5));
    StopSlot02162294(self, (LFLD(u8, self, 5) & 1) ^ 1);
    __cxa_vec_cleanup(self + 0x2e8, 2, 0x138, (void (*)(void *))func_ov000_0218ea20);
    __cxa_vec_cleanup(self + 0x78, 2, 0x138, (void (*)(void *))func_ov000_0218ea20);
}

static inline void CamDtor02162294(u8 *self) {
    u8 *sub;
    VOBJ_SET_VTABLE(self, data_ov000_021cabc8);
    StopSlot02162294(self + 4, LFLD(u8, self + 4, 5));
    StopSlot02162294(self + 4, (LFLD(u8, self + 4, 5) & 1) ^ 1);
    func_ov000_0218fee4(self + 0x55c);
    sub = self + 4;
    SlotDtor02162294(sub);
}

u8 *func_ov000_02162294(Obj02162124 *self) {
    CamDtor02162294((u8 *)self);
    return (u8 *)self;
}

u8 *func_ov000_0216251c(Obj02162124 *self) {
    CamDtor02162294((u8 *)self);
    Heap_Free(self);
    return (u8 *)self;
}

}
