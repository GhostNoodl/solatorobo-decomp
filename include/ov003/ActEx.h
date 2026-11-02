#ifndef OV003_ACTEX_H
#define OV003_ACTEX_H

// ov003 actors of the ActorEx family (dtor func_ov000_0219429c) that keep members in place
// (round acC). The sizes and member offsets come from their allocations in func_ov000_02192b24,
// which constructs the members right after ActorEx_Ctor; the dtors destroy them in reverse order.
// The ov003 actors allocated with NEW_BASIC(0xd0, ...) are plain ActorEx objects.

#include "ov000/ObjLayouts.h"
#include "ov000/Model0218fe1c.h"

// A HitMesh embedded in an actor (0x98 bytes; its dtor func_ov003_021e75bc detaches it with
// HitMesh_Detach).
typedef struct Ov003HitMesh {
    u8 unk_00[0x98];
} Ov003HitMesh;

// One ActorRes after the ActorEx part (vtables 021f8c28 and 021f89c8 are this size; 021f8a60
// (0x20c), 021f8768 (0x214) and 021f8638 (0x218) add fields after it).
class Ov003ActExRes : public ActorEx {
public:
    ActorRes res; // ctor func_ov000_0218e9c4, dtor func_ov000_0218ea20
};
SIZE_ASSERT(Ov003ActExRes, 0x208);

// An ActorRes and a model (vtables 021f9834 and 021f979c; 021f9704 is 0x314 bytes and clears a
// u16 at 0x2fc when it is built).
class Ov003ActExResMdl : public Ov003ActExRes {
public:
    Model0218fe1c mdl; // ctor func_ov000_0218fe1c, dtor func_ov000_0218fee4
    u8 unk_2f0[0x14];
};
SIZE_ASSERT(Ov003ActExResMdl, 0x304);

// A model after the ActorEx part (vtable 021f953c).
class Ov003ActExMdl : public ActorEx {
public:
    Model0218fe1c mdl;
    u8 unk_1b8[0x8];
};
SIZE_ASSERT(Ov003ActExMdl, 0x1c0);

// Vtable 021f8af8: two ActorRes, a model and three HitMesh arrays.
class Ov003ActExMesh : public ActorEx {
public:
    ActorRes res;
    ActorRes res2;
    Model0218fe1c mdl;
    u8 unk_428[0x44];
    Ov003HitMesh meshA[4];
    Ov003HitMesh meshB[4];
    Ov003HitMesh meshC[3];
    u8 unk_af4[0x28];
};
SIZE_ASSERT(Ov003ActExMesh, 0xb1c);

extern "C" {
ActorEx *func_ov000_0219429c(ActorEx *self); // ActorEx dtor
ActorRes *func_ov000_0218ea20(ActorRes *self); // ActorRes dtor
Model0218fe1c *func_ov000_0218fee4(Model0218fe1c *self); // Model0218fe1c dtor
}

#endif
