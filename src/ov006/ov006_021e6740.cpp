#include "ov006/Tasks.h"
#include "nitro/fx.h"

#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} Bits8_6740;

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} Bits16_6740;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    u8 pad[4];
} Node6740;

extern "C" {

void *func_0206fef8(u16 id);
void *func_0203dd9c(u32 size);
void *func_ov000_0218fe1c(void *p);
void func_ov000_0218ffdc(void *p, void *a, int b, int c);
s32 **func_ov000_02190a30(void *p, int idx);
void func_ov000_02191920(void *p, int a, s32 b, int c);
void *func_ov000_021985e8(void *p);
void func_ov000_02198c8c(void *p, u16 id);
void func_0203f324(void *p);
void *func_ov000_021984c8(void *p);
void *func_ov000_02198328(void *p);
void *func_ov006_021dc714(void *p);
void func_ov006_021dc8f8(void *p);
void func_ov006_021dcc9c(void *p, int idx, u8 flag);

void func_ov006_021e6740(u8 *self) {
    u8 *info;
    void *p;
    s32 v;
    s32 **a;
    ov006_Slot *slot;
    slot = func_ov006_021db060(data_ov006_021ec884, self[0x19e]);
    FIELD(self, 0x16, Bits8_6740).b0 = 1;
    info = (u8 *)func_0206fef8(FIELD(self, 0xe, u16));
    FIELD(self, 0x64, s32) = FIELD(info, 0x14, s16) << 4;
    FIELD(self, 0x68, s32) = FIELD(info, 0x16, s16) << 4;
    FIELD(self, 0x6c, s32) = FIELD(self, 0x68, s32) >> 1;
    p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    FIELD(self, 0x38, void *) = p;
    func_ov000_0218ffdc(p, FIELD(self, 0x34, void *), 0, 1);
    FIELD(FIELD(self, 0x38, u8 *), 0xb4, u16) = FIELD(self, 0xc, u16);
    {
        a = func_ov000_02190a30(FIELD(self, 0x38, void *), 3);
        if (a != NULL) {
            FIELD(FIELD(self, 0x38, u8 *), 0xc2, u16) |= 0x40;
            func_ov000_02191920(FIELD(self, 0x38, void *), 0, 0x1000, 0);
            if (*a != NULL) {
                **a = 0;
            }
            FIELD(a, 0x111, u8) |= 8;
        }
    }
    func_ov000_0218ffdc(self + 0xb0, FIELD(self, 0x34, void *), 1, 0);
    FIELD(self, 0x164, u16) = FIELD(self, 0xc, u16);
    v = FIELD(self, 0x64, s32);
    p = func_0203dd9c(0x9c);
    if (p != NULL) {
        p = func_ov000_021985e8(p);
    }
    FIELD(self, 0x48, void *) = p;
    func_ov000_02198c8c(p, FIELD(self, 0xc, u16));
    FIELD(FIELD(self, 0x48, u8 *), 0x38, s32) = v;
    {
        u8 *q = FIELD(self, 0x48, u8 *);
        FIELD(q, 0x9a, Bits16_6740).b0 = 1;
        FIELD(q, 0x9a, u16) |= 8;
        func_0203f324(q);
    }
    FIELD(FIELD(self, 0x48, u8 *), 0x30, u32) = 0xe0000000;
    FIELD(FIELD(self, 0x48, u8 *), 0x28, s32) = 0x80;
    FIELD(FIELD(self, 0x48, u8 *), 0x9a, u16) |= 0x200;
    p = func_0203dd9c(0x24);
    if (p != NULL) {
        p = func_ov000_021984c8(p);
    }
    FIELD(self, 0x44, void *) = p;
    FIELD(p, 0x20, u16) = FIELD(self, 0xc, u16);
    FIELD(FIELD(self, 0x44, u8 *), 0x1c, s32) = v;
    {
        u8 *q = FIELD(self, 0x44, u8 *);
        FIELD(q, 0x22, Bits16_6740).b0 = 1;
        FIELD(q, 0x22, u16) |= 2;
    }
    p = func_0203dd9c(0x14);
    if (p != NULL) {
        p = func_ov000_02198328(p);
    }
    FIELD(self, 0x40, void *) = p;
    self[0x15] = 1;
    p = func_0203dd9c(0x34);
    if (p != NULL) {
        p = func_ov006_021dc714(p);
    }
    FIELD(self, 0x198, void *) = p;
    func_ov006_021dc8f8(p);
    func_ov006_021dcc9c(FIELD(self, 0x198, void *), self[0x19e], slot->unk8 == 0);
    {
        u8 *q = FIELD(self, 0x198, u8 *);
        s32 z = FIELD(q, 0x28, s32);
        FIELD(q, 0x20, s32) = 0;
        FIELD(q, 0x24, s32) = -0x6000;
        FIELD(q, 0x28, s32) = z;
    }
    FIELD(self, 0x1ae, u16) = FIELD(self, 0x7c, u16);
    FIELD(self, 0x1b0, u16) = FIELD(self, 0x7e, u16);
    FIELD(self, 0x1b2, u16) = FIELD(self, 0x80, u16);
    FIELD(self, 0x1ba, u16) = FIELD(self, 0x7c, u16);
    FIELD(self, 0x1bc, u16) = FIELD(self, 0x7e, u16);
    FIELD(self, 0x1be, u16) = FIELD(self, 0x80, u16);
    FIELD(self, 0x20c, u16) = 0;
    FIELD(self, 0x20e, u16) = 0;
    FIELD(self, 0x210, u16) = 0;
    {
        Node6740 *b;
        Node6740 *a;
        a = FIELD(self, 0x200, Node6740 *) + self[0x209];
        b = FIELD(self, 0x200, Node6740 *) + self[0x20a];
        if (a != NULL && b != NULL) {
            s32 dx;
            s32 dz;
            s64 sq;
            FIELD(self, 0x20e, u16) = FX_Atan2(b->x - a->x, b->z - a->z);
            dx = a->x - b->x;
            dz = a->z - b->z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            REG_SQRTCNT = 1;
            REG_SQRT_PARAM = (u64)(sq * 4);
            while (REG_SQRTCNT & 0x8000) {
            }
            FIELD(self, 0x20c, u16) = -FX_Atan2(b->y - a->y, (s32)(REG_SQRT_RESULT + 1) >> 1);
        }
    }
}

}
