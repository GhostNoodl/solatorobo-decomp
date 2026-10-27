// The 3D object animation table. Its code is in TextWin.cpp (the TU with the string
// pool), but the table and its static initializer sit after other files' .data, so
// they were defined in a file of their own.
#include "types.h"

class Obj3DAnimCls;
struct Obj3DAnimSlot;

// Per-state handler of an animation slot (pointer to member of the owner).
typedef s32 (Obj3DAnimCls::*Obj3DAnimHandler)(s32 state, struct Obj3DAnimSlot *slot);

// The owner of the animation slots (an Obj3DAnim); its state handlers are members.
class Obj3DAnimCls {
public:
    s32 func_02052628(s32 state, Obj3DAnimSlot *slot);
    s32 func_020528ec(s32 state, Obj3DAnimSlot *slot);
    s32 func_02052bec(s32 state, Obj3DAnimSlot *slot);
};

typedef struct Obj3DAnimEnt {
    /* 0x00 */ const char *name;
    /* 0x04 */ u8 flip;
    /* 0x06 */ s16 ofs;
    /* 0x08 */ u8 unk_08[4];
    /* 0x0c */ Obj3DAnimHandler fn;
} Obj3DAnimEnt; // size 0x14

extern "C" {

// Animation names.
extern char data_0208b8cc[], data_0208b8cd[], data_0208b8d9[], data_0208b8e5[], data_0208b8f1[], data_0208b8fd[],
    data_0208b921[], data_0208b945[], data_0208b951[], data_0208b95d[], data_0208b969[], data_0208b975[],
    data_0208b981[], data_0208b98d[], data_0208b999[], data_0208b9a5[], data_0208b9b1[], data_0208b9bd[];

extern const Obj3DAnimEnt data_0208bc80[];

// Entry 11 has no handler: MWCC copies `__ptmf_null` into it at startup (`__sinit_Obj3D_2.cpp`).
const Obj3DAnimEnt data_0208bc80[] = {
    {data_0208b9b1, 0, -0x24, {0x17}, &Obj3DAnimCls::func_02052628},
    {data_0208b945, 0, -0x24, {0x16}, &Obj3DAnimCls::func_02052628},
    {data_0208b951, 0, -0x24, {0x17}, &Obj3DAnimCls::func_02052628},
    {data_0208b95d, 1, -0xf, {0x16}, &Obj3DAnimCls::func_02052628},
    {data_0208b969, 1, -0x4, {0x5}, &Obj3DAnimCls::func_02052628},
    {data_0208b975, 1, -0x6, {0x12}, &Obj3DAnimCls::func_02052628},
    {data_0208b981, 1, -0xe, {0x10}, &Obj3DAnimCls::func_02052628},
    {data_0208b98d, 1, 0x1a, {0xd}, &Obj3DAnimCls::func_02052628},
    {data_0208b999, 1, -0x4, {0x5}, &Obj3DAnimCls::func_02052628},
    {data_0208b9a5, 1, -0x24, {0x17}, &Obj3DAnimCls::func_02052628},
    {data_0208b9bd, 1, -0xf, {0x8}, &Obj3DAnimCls::func_02052628},
    {data_0208b8cc, 0, 0, {0}, 0},
    {data_0208b921, 0, 0, {0}, &Obj3DAnimCls::func_020528ec},
    {data_0208b8cd, 0, 0, {0}, &Obj3DAnimCls::func_020528ec},
    {data_0208b8d9, 0, 0, {0}, &Obj3DAnimCls::func_020528ec},
    {data_0208b8e5, 0, 0, {0}, &Obj3DAnimCls::func_02052bec},
    {data_0208b8f1, 0, 0xd, {0}, &Obj3DAnimCls::func_02052bec},
    {data_0208b8fd, 0, 0, {0}, &Obj3DAnimCls::func_02052bec},
};

}
