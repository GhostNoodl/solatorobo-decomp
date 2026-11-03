#include "types.h"
#include "ov000/VObj.h"

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

extern u8 Ov000ActVt_021cc7cc_vtbl[];
extern u8 Ov003ActVt_021fa5f8_vtbl[];
extern u8 Ov003ActVt_021fa5a0_vtbl[];
extern u8 Ov003ActVt_021fa548_vtbl[];
extern u8 Ov003ActVt_021fa4f0_vtbl[];
extern u8 Ov003ActVt_021fa498_vtbl[];
extern u8 Ov003ActVt_021fa390_vtbl[];
extern u8 Ov003ActVt_021fa440_vtbl[];
extern u8 Ov003ActVt_021fa3e8_vtbl[];
extern u8 Ov003ActVt_021fa338_vtbl[];
extern u8 Ov003ActVt_021fa2e0_vtbl[];
void *Heap_Alloc(u32 size);
Info021b4828 *func_020705fc(u16 id);
s32 Tbl_GetText(u16 id);
void *Actor_Ctor(void *p);
void *ResSet_Init(void *p);
void *ResSet_ReleaseAll(void *p);
void *Model0218fe1c_Init(void *p);
void *Model0218fe1c_FreeAnims(void *p);
void Actor_JoinGroup(void *p, u16 sub, u16 id, s32 a);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));

static inline void Base021b4828_Init(u8 *p) {
    Actor_Ctor(p);
    VOBJ_SET_VTABLE(p, Ov000ActVt_021cc7cc_vtbl);
    LFLD(s32, p, 0xac) = 0;
}

static inline void Init6b021b4828(u8 *p) {
    Base021b4828_Init(p);
    VOBJ_SET_VTABLE(p, Ov003ActVt_021fa5a0_vtbl);
    ResSet_Init(p + 0xb0);
    Model0218fe1c_Init(p + 0x1e8);
}

static inline u8 *Create021b4828(u16 id) {
    u8 *p;
    switch (id) {
    default:
        p = (u8 *)Heap_Alloc(0xb0);
        if (p != NULL) {
            Base021b4828_Init(p);
        }
        return p;
    case 0x6a00:
    case 0x6a01:
        p = (u8 *)Heap_Alloc(0x2d0);
        if (p != NULL) {
            Base021b4828_Init(p);
            VOBJ_SET_VTABLE(p, Ov003ActVt_021fa5f8_vtbl);
            ResSet_Init(p + 0xb0);
            Model0218fe1c_Init(p + 0x1e8);
        }
        return p;
    case 0x6b00:
        p = (u8 *)Heap_Alloc(0x2d4);
        if (p != NULL) {
            Base021b4828_Init(p);
            VOBJ_SET_VTABLE(p, Ov003ActVt_021fa5a0_vtbl);
            ResSet_Init(p + 0xb0);
            Model0218fe1c_Init(p + 0x1e8);
        }
        return p;
    case 0x601f:
        p = (u8 *)Heap_Alloc(0x1f0);
        if (p != NULL) {
            Base021b4828_Init(p);
            VOBJ_SET_VTABLE(p, Ov003ActVt_021fa548_vtbl);
            ResSet_Init(p + 0xb0);
        }
        return p;
    }
    return p;
}

#define NEW_BASIC(size, vt)                    \
    p = (u8 *)Heap_Alloc(size);             \
    if (p != NULL) {                           \
        Base021b4828_Init(p);                  \
        VOBJ_SET_VTABLE(p, vt);             \
    }

u8 *Factory_New6000(Spawn021b4828 *s) {
    u8 *p;
    switch (func_020705fc(s->id)->type) {
    default:
    case 0:
        p = Create021b4828(s->id);
        break;
    case 1:
        NEW_BASIC(0xb4, Ov003ActVt_021fa4f0_vtbl);
        break;
    case 2:
        NEW_BASIC(0xb4, Ov003ActVt_021fa498_vtbl);
        break;
    case 3:
        p = (u8 *)Heap_Alloc(0x1158);
        if (p != NULL) {
            Base021b4828_Init(p);
            VOBJ_SET_VTABLE(p, Ov003ActVt_021fa390_vtbl);
            __cxa_vec_ctor(p + 0xb0, 8, 0x138, (void (*)(void *))ResSet_Init, (void (*)(void *))ResSet_ReleaseAll);
            __cxa_vec_ctor(p + 0xa70, 6, 0xe8, (void (*)(void *))Model0218fe1c_Init, (void (*)(void *))Model0218fe1c_FreeAnims);
        }
        break;
    case 4:
        NEW_BASIC(0xb8, Ov003ActVt_021fa440_vtbl);
        break;
    case 5:
        NEW_BASIC(0xc0, Ov003ActVt_021fa3e8_vtbl);
        break;
    case 6:
        NEW_BASIC(0xb0, Ov003ActVt_021fa338_vtbl);
        break;
    case 7:
        NEW_BASIC(0xb0, Ov003ActVt_021fa2e0_vtbl);
        break;
    }
    Actor_JoinGroup(p, s->sub, s->id, Tbl_GetText(s->id));
    return p;
}

}
