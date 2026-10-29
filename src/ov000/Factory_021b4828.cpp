#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 type : 5;
    u8 rest : 3;
} Info021b4828;

typedef struct {
    u16 id;
    u16 sub;
} Spawn021b4828;

extern "C" {

extern u8 data_ov000_021cc7cc[];
extern u8 data_ov003_021fa5f8[];
extern u8 data_ov003_021fa5a0[];
extern u8 data_ov003_021fa548[];
extern u8 data_ov003_021fa4f0[];
extern u8 data_ov003_021fa498[];
extern u8 data_ov003_021fa390[];
extern u8 data_ov003_021fa440[];
extern u8 data_ov003_021fa3e8[];
extern u8 data_ov003_021fa338[];
extern u8 data_ov003_021fa2e0[];
void *func_0203dd9c(u32 size);
Info021b4828 *func_020705fc(u16 id);
s32 func_0206ffa0(u16 id);
void *func_ov000_0218c2d4(void *p);
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218ea20(void *p);
void *func_ov000_0218fe1c(void *p);
void *func_ov000_0218fee4(void *p);
void func_ov000_0218d1c0(void *p, u16 sub, u16 id, s32 a);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));

static inline void Base021b4828_Init(u8 *p) {
    func_ov000_0218c2d4(p);
    LFLD(void *, p, 0) = data_ov000_021cc7cc;
    LFLD(s32, p, 0xac) = 0;
}

static inline void Init6b021b4828(u8 *p) {
    Base021b4828_Init(p);
    LFLD(void *, p, 0) = data_ov003_021fa5a0;
    func_ov000_0218e9c4(p + 0xb0);
    func_ov000_0218fe1c(p + 0x1e8);
}

static inline u8 *Create021b4828(u16 id) {
    u8 *p;
    switch (id) {
    default:
        p = (u8 *)func_0203dd9c(0xb0);
        if (p != NULL) {
            Base021b4828_Init(p);
        }
        return p;
    case 0x6a00:
    case 0x6a01:
        p = (u8 *)func_0203dd9c(0x2d0);
        if (p != NULL) {
            Base021b4828_Init(p);
            LFLD(void *, p, 0) = data_ov003_021fa5f8;
            func_ov000_0218e9c4(p + 0xb0);
            func_ov000_0218fe1c(p + 0x1e8);
        }
        return p;
    case 0x6b00:
        p = (u8 *)func_0203dd9c(0x2d4);
        if (p != NULL) {
            Base021b4828_Init(p);
            LFLD(void *, p, 0) = data_ov003_021fa5a0;
            func_ov000_0218e9c4(p + 0xb0);
            func_ov000_0218fe1c(p + 0x1e8);
        }
        return p;
    case 0x601f:
        p = (u8 *)func_0203dd9c(0x1f0);
        if (p != NULL) {
            Base021b4828_Init(p);
            LFLD(void *, p, 0) = data_ov003_021fa548;
            func_ov000_0218e9c4(p + 0xb0);
        }
        return p;
    }
    return p;
}

#define NEW_BASIC(size, vt)                    \
    p = (u8 *)func_0203dd9c(size);             \
    if (p != NULL) {                           \
        Base021b4828_Init(p);                  \
        LFLD(void *, p, 0) = (vt);             \
    }

u8 *func_ov000_021b4828(Spawn021b4828 *s) {
    u8 *p;
    switch (func_020705fc(s->id)->type) {
    default:
    case 0:
        p = Create021b4828(s->id);
        break;
    case 1:
        NEW_BASIC(0xb4, data_ov003_021fa4f0);
        break;
    case 2:
        NEW_BASIC(0xb4, data_ov003_021fa498);
        break;
    case 3:
        p = (u8 *)func_0203dd9c(0x1158);
        if (p != NULL) {
            Base021b4828_Init(p);
            LFLD(void *, p, 0) = data_ov003_021fa390;
            __cxa_vec_ctor(p + 0xb0, 8, 0x138, (void (*)(void *))func_ov000_0218e9c4, (void (*)(void *))func_ov000_0218ea20);
            __cxa_vec_ctor(p + 0xa70, 6, 0xe8, (void (*)(void *))func_ov000_0218fe1c, (void (*)(void *))func_ov000_0218fee4);
        }
        break;
    case 4:
        NEW_BASIC(0xb8, data_ov003_021fa440);
        break;
    case 5:
        NEW_BASIC(0xc0, data_ov003_021fa3e8);
        break;
    case 6:
        NEW_BASIC(0xb0, data_ov003_021fa338);
        break;
    case 7:
        NEW_BASIC(0xb0, data_ov003_021fa2e0);
        break;
    }
    func_ov000_0218d1c0(p, s->sub, s->id, func_0206ffa0(s->id));
    return p;
}

}
