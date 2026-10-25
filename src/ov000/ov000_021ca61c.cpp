#include <nitro/fx.h>

// A self-referencing name block, like ov000_021ca678.cpp, plus a zero rotation and a zero vector
// copied in at startup. The vector is its own object after the block.
//
// The block's dynamic fields are given with designated initialisers in the order the target
// fills them: the three pointers, then the rotation. MWCC evaluates designated initialisers in
// the order written, not in member order.
//
// The original TU had functions before these definitions, so its variables kept definition
// order instead of MWCC's size sort (the block, 0x24 bytes, comes before the 12-byte vector).
// The empty asm function stands in for them: it emits no code.
struct Ov000Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov000PhotoCfg {
    const char *photo;
    Ov000Rot rot;
    const char *photoB;
    const char *photoA;
    char photo0[8];
    char photo1[8];
};

extern "C" {
extern Ov000PhotoCfg data_ov000_021ca880;
extern const VecFx32 data_ov000_021ca8a4;
extern const char *const data_ov000_021c981c;
extern const char *const data_ov000_021c9820;
extern const Ov000Rot data_ov000_021c9824;
extern const VecFx32 data_ov000_021c982c;

static asm void ov000_021ca61c_order() {
}

Ov000PhotoCfg data_ov000_021ca880 = {
    .photo = data_ov000_021c981c,
    .photoB = data_ov000_021c9820,
    .photoA = data_ov000_021c981c,
    .rot = data_ov000_021c9824,
    .photo0 = "photo00",
    .photo1 = "photo01",
};
const VecFx32 data_ov000_021ca8a4 = data_ov000_021c982c;
const char *const data_ov000_021c981c = data_ov000_021ca880.photo1;
const char *const data_ov000_021c9820 = data_ov000_021ca880.photo0;
const Ov000Rot data_ov000_021c9824 = {0, 0, 0};
const VecFx32 data_ov000_021c982c = {0, 0, 0};
}
