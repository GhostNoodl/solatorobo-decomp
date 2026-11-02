#include "types.h"

typedef void (*VFunc)(void *);

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    u16 unk_00;
    u16 unk_02;
} Ov003Work;

typedef struct {
    u8 unk_00[0x20];
    u16 unk_20;
    u8 unk_22[0x16];
    void *unk_38;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[0x8a];
    u16 unk_ce;
} Ov003Obj;

extern void *data_ov000_021ccd64;
extern char data_ov003_021f9fd0[];
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern void Heap_Free(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void *func_ov000_0219429c(void *p);
extern void *func_ov003_021dae44(void *p);

void *Ov003ActVt_021f99e8_DtorDelete(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xdc);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f99e8_Dtor(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xdc);
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9bb0_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f9bb0_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9c48_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f9c48_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9b18_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9b18_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f9a80_Dtor(void *self) {
    func_ov003_021dae44(self);
    return self;
}

void *Ov003ActVt_021f9a80_DtorDelete(void *self) {
    func_ov003_021dae44(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f9f40_Init(Ov003Obj *self) {
    Ov003Unit *unit;
    func_ov000_0219433c(self);
    self->unk_ce = 0;
    unit = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
}

void Ov003ActVt_021f9f40_Start(Ov003Obj *self) {
    func_ov000_02194758(self);
    if (self->unk_38 != NULL) {
        func_ov000_02190cb0(self->unk_38, data_ov003_021f9fd0, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0x4cd);
    }
    self->work->unk_02 = 10;
}
