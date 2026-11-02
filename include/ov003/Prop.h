#ifndef OV003_PROP_H
#define OV003_PROP_H

// The actors func_ov000_021b4828 builds for ov003 (round acC): an ov000 Actor with one more word
// (vtable data_ov000_021cc7cc, 0xb0 bytes, methods Ov000ActVt_021cc7cc_*), and the ov003
// subclasses whose members the factory constructs in place. Their dtors destroy those members and
// then call the Actor dtor func_ov000_0218c928. The subclasses without members only add words
// (vtables 021fa4f0 and 021fa498: 0xb4, 021fa440: 0xb8, 021fa3e8: 0xc0; 021fa338 and 021fa2e0
// are 0xb0).

#include "ov000/ActorBase.h"

class Ov003Prop : public Actor {
public:
    s32 unk_ac; // cleared by the factory
};
SIZE_ASSERT(Ov003Prop, 0xb0);

// One ActorRes (vtable 021fa548 is 0x1f0 bytes and adds two words).
class Ov003PropRes : public Ov003Prop {
public:
    ActorRes res; // ctor func_ov000_0218e9c4, dtor func_ov000_0218ea20
};
SIZE_ASSERT(Ov003PropRes, 0x1e8);

// An ActorRes and a model (vtable 021fa5f8, kinds 0x6a00 / 0x6a01; vtable 021fa5a0, kind 0x6b00,
// is 0x2d4 bytes).
class Ov003PropResMdl : public Ov003PropRes {
public:
    Model0218fe1c mdl; // ctor func_ov000_0218fe1c, dtor func_ov000_0218fee4
};
SIZE_ASSERT(Ov003PropResMdl, 0x2d0);

// Eight ActorRes and six models, built with __cxa_vec_ctor (vtable 021fa390).
class Ov003PropMulti : public Ov003Prop {
public:
    ActorRes res[8];
    Model0218fe1c mdl[6];
    u8 unk_fe0[0x178];
};
SIZE_ASSERT(Ov003PropMulti, 0x1158);

extern "C" {
Actor *func_ov000_0218c928(Actor *self); // Actor dtor
ActorRes *func_ov000_0218ea20(ActorRes *self); // ActorRes dtor
Model0218fe1c *func_ov000_0218fee4(Model0218fe1c *self); // Model0218fe1c dtor
}

#endif
