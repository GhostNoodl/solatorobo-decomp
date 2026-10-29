#ifndef MAIN_SYS_SYSTASK_H
#define MAIN_SYS_SYSTASK_H

#include "Main/Res/ResMgr.h"

struct SysTaskVObj {
    virtual void vf00(void);
    virtual void Delete(void);
};

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Unk0214a418 {
    u32 unk_00;
    u32 unk_04;
    void *unk_08;
    void *unk_0c;
    SysTaskVObj *unk_10;
    void *unk_14;
} Unk0214a418;

typedef s32 (*Unk02097d4cFunc)(s32 arg);

extern Unk0214a418 *data_0214a418;
extern Unk02097d4cFunc data_02097d4c;
extern u32 data_02097d44;
extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *ptr);
extern void func_02063374(Unk0214a418 *p);
extern void func_02041558(void *p);
extern void func_02041278(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0218ea20(void *p);
extern s32 func_02062ac8(Unk0214a418 *p, s32 arg);
s32 func_02062aa0(s32 arg);

#ifdef __cplusplus
}
#endif

#endif
