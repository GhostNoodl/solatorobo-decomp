#ifndef MAIN_SYS_SYSTASK_H
#define MAIN_SYS_SYSTASK_H

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/Model.h"

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
    Model *unk_14;
} Unk0214a418;

typedef s32 (*Unk02097d4cFunc)(s32 arg);

extern Unk0214a418 *gUnk0214a418;
extern Unk02097d4cFunc gFadeFunc;
extern u32 gFadeFuncArg;
extern void *Heap_Alloc(u32 size);
extern void Heap_Free(void *ptr);
extern void Unk0214a418_Release(Unk0214a418 *p);
extern void *Model0218fe1c_FreeAnims(void *p);
extern void *ResSet_ReleaseAll(void *p);
extern s32 Unk0214a418_Run(Unk0214a418 *p, s32 arg);
s32 Unk0214a418_FadeFunc(s32 arg);

#ifdef __cplusplus
}
#endif

#endif
