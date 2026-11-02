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

// The flickering / moving props (vtables 021fa4f0 and 021fa498, ov003_021f1ce0.cpp). Actor::unk_18
// picks the entry of data_ov003_021f7560 (021fa498) or two animation frames (021fa4f0); unk_1a and
// unk_1c bound the random animation speed and unk_1e the wait between restarts.
class Ov003PropFlicker : public Ov003Prop {
public:
    u16 timer; // 021fa4f0: frames until the next restart; 021fa498: the current point of the entry
    s16 unk_b2; // 021fa498: speed, eased toward the entry's
};
SIZE_ASSERT(Ov003PropFlicker, 0xb4);

// The light that shows and hides as the player comes near (vtable 021fa440, ov003_021f2f60.c and
// ov003_021f3198.c). Actor::unk_18 holds four 4-bit steps (high nibble first) that phase walks
// through (read unsigned, as are the two angle pairs in unk_1a / unk_1c); radius is unk_1e << 4.
class Ov003PropBlink : public Ov003Prop {
public:
    s32 radius;
    u16 phase;
};
SIZE_ASSERT(Ov003PropBlink, 0xb8);

// The light that drifts around pos and pulses (vtable 021fa3e8, ov003_021f3198.c).
class Ov003PropDrift : public Ov003Prop {
public:
    VecFx32 offset; // from pos, eased toward a random point each frame
    s32 phase; // grows by a random step up to 0x1000; scales and fades the model
};
SIZE_ASSERT(Ov003PropDrift, 0xc0);

// One ActorRes (vtable 021fa548 is 0x1f0 bytes and adds two words).
class Ov003PropRes : public Ov003Prop {
public:
    ActorRes res; // ctor func_ov000_0218e9c4, dtor func_ov000_0218ea20
};
SIZE_ASSERT(Ov003PropRes, 0x1e8);

// Vtable 021fa548 (ov003_021f3dd4.cpp): Actor::unk_34 holds the main resources and res, when
// altFrame is not 0, the animation that is set to that frame on model layer 3. unk_1ea / unk_1ec
// are the save values the resources were last chosen for.
class Ov003Prop021fa548 : public Ov003PropRes {
public:
    u8 altFrame;
    u8 unk_1e9;
    u16 unk_1ea;
    u16 unk_1ec;
};
SIZE_ASSERT(Ov003Prop021fa548, 0x1f0);

// An ActorRes and a model (vtable 021fa5f8, kinds 0x6a00 / 0x6a01; vtable 021fa5a0, kind 0x6b00,
// is 0x2d4 bytes).
class Ov003PropResMdl : public Ov003PropRes {
public:
    Model0218fe1c mdl; // ctor func_ov000_0218fe1c, dtor func_ov000_0218fee4
};
SIZE_ASSERT(Ov003PropResMdl, 0x2d0);

// Vtable 021fa5a0 (kind 0x6b00; ov003_021f3954.cpp, ov003_021f3a94.cpp, Init in ov003_021f371c.cpp).
class Ov003Prop021fa5a0 : public Ov003PropResMdl {
public:
    u16 unk_2d0; // frames; cleared by Start, counted by func_ov003_021f3b30 for its effects
};
SIZE_ASSERT(Ov003Prop021fa5a0, 0x2d4);

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
void Ov000ActVt_021cc7cc_Start(Ov003Prop *self);
BOOL func_ov000_0218cf5c(Actor *self); // IsReady of the props
void func_ov000_021b4adc(Ov003Prop *self); // Init of the props
BOOL func_ov000_0218cea4(Actor *self); // draws the model
}

#endif
