#ifndef OV004_H
#define OV004_H

#include "types.h"
#include "Main/Sys/SysState.h"
#include "Main/Res/StageCmd.h"

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

    // The 0xac ov000 object built by Actor_Ctor (allocated in Ov004_Create).
    u8 unk_04[0x12];
    u8 unk_16;
    u8 unk_17[0xb];
    u16 unk_22;
    u8 unk_24[0x14];
    void *model;
    u8 unk_3c[0x8];
    void *unk_44;
    void *unk_48;
    u8 unk_4c[0x60];
};
typedef char Ov004V_size_check[(sizeof(Ov004V) == 0xac) ? 1 : -1];

typedef void *(*Ov004Cb)(void *a, s32 b);

extern "C" {
extern Ov004Cb data_ov004_021cf860;
extern Ov004V *data_ov004_021cf864;
extern s32 data_ov004_021cf868;
extern void *data_ov004_021cf86c[2];
extern u8 Ov004ActVt_021cf808_vtbl[];
void *Heap_Alloc(u32 size);
void Heap_Free(void *p);
s32 func_0203db40(void *p);
void func_ov000_02176264(void *p);
void func_ov000_021761f0(void *p);
void *Actor_Ctor(void *p);
void *Actor_DtorBase(void *p);
void Obj021984c8_UpdatePos(void *p, s32 a, s32 b);
void ActorSub48_UpdatePos(void *p, s32 a, s32 b);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
void func_ov004_021ce50c(void);
}

#endif
