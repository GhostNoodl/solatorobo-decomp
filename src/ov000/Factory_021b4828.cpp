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
    VOBJ_SET_VTABLE(p, data_ov000_021cc7cc);
    LFLD(s32, p, 0xac) = 0;
}

static inline void Init6b021b4828(u8 *p) {
    Base021b4828_Init(p);
    VOBJ_SET_VTABLE(p, data_ov003_021fa5a0);
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
            VOBJ_SET_VTABLE(p, data_ov003_021fa5f8);
            ResSet_Init(p + 0xb0);
            Model0218fe1c_Init(p + 0x1e8);
        }
        return p;
    case 0x6b00:
        p = (u8 *)Heap_Alloc(0x2d4);
        if (p != NULL) {
            Base021b4828_Init(p);
            VOBJ_SET_VTABLE(p, data_ov003_021fa5a0);
            ResSet_Init(p + 0xb0);
            Model0218fe1c_Init(p + 0x1e8);
        }
        return p;
    case 0x601f:
        p = (u8 *)Heap_Alloc(0x1f0);
        if (p != NULL) {
            Base021b4828_Init(p);
            VOBJ_SET_VTABLE(p, data_ov003_021fa548);
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
        NEW_BASIC(0xb4, data_ov003_021fa4f0);
        break;
    case 2:
        NEW_BASIC(0xb4, data_ov003_021fa498);
        break;
    case 3:
        p = (u8 *)Heap_Alloc(0x1158);
        if (p != NULL) {
            Base021b4828_Init(p);
            VOBJ_SET_VTABLE(p, data_ov003_021fa390);
            __cxa_vec_ctor(p + 0xb0, 8, 0x138, (void (*)(void *))ResSet_Init, (void (*)(void *))ResSet_ReleaseAll);
            __cxa_vec_ctor(p + 0xa70, 6, 0xe8, (void (*)(void *))Model0218fe1c_Init, (void (*)(void *))Model0218fe1c_FreeAnims);
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
    Actor_JoinGroup(p, s->sub, s->id, Tbl_GetText(s->id));
    return p;
}

}
