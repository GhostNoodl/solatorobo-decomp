#ifndef OV004_H
#define OV004_H

#include "types.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov004V {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    virtual s32 v24(...);
};

#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))

struct Ov004Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

typedef void *(*Ov004Cb)(void *a, s32 b);

struct Ov004Global {
    Ov004Cb cb;
    Ov004V *obj;
};

extern "C" {
extern Ov004Heap *data_02097dd0;
extern Ov004Global data_ov004_021cf860;
extern s32 data_ov004_021cf868;
extern void *data_ov004_021cf86c[2];
extern u8 data_ov004_021cf808[];
void *func_0203dd9c(u32 size);
void func_0203de1c(void *p);
s32 func_0203db40(void *p);
void *func_ov000_0219bf90(void);
void func_ov000_02176264(void *p);
void func_ov000_021761f0(void *p);
void func_ov000_0218c2d4(void *p);
void func_ov000_0218c928(void *p);
void func_ov000_021984f4(void *p, s32 a, s32 b);
void func_ov000_0219864c(void *p, s32 a, s32 b);
void func_ov000_02190a80(void *a, s32 b);
void func_ov004_021ce50c(void);
}

#endif
