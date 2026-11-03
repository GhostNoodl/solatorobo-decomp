#include "types.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/Pad.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Movie/Movie.h"

extern "C" {

extern void *gSndQueue;

extern void func_0203d6b4(void);
extern void func_0203d1b4(void);
extern void Touch_Create(void);
extern void ResMgr_Create(void);
extern void GfxSys_Create(void);
extern void func_02039750(void);
extern void Snd_Create(void);
extern void Movie_Create(void);
extern void func_02046c6c(void);
extern void func_0203e3e8(void);
extern void func_0204ae14(void);
extern void Sys_WaitVBlank(UnkSys *sys);
extern void func_0203e6bc(void);
extern void GfxSys_EndFrame(GfxSys *sys);
extern void GfxSys_ApplyFade(int mode);
extern void GfxSys_FlipTextBg(GfxSys *sys);
extern void func_02039f84(GfxMgr *mgr);
extern void func_0203d8b0(void);
extern void func_0203d8e8(void);
extern void func_0203d298(Pad *pad);
extern void func_02043f70(Movie *movie);
extern void func_0204aee8(void);
extern void func_020364c0(ResMgr *mgr);
extern void SndQueue_Update(void *queue);
extern void Sys_WaitFrame(UnkSys *sys);
extern void GfxSys_SwapBuffers(GfxSys *sys);

int main(void) {
    func_0203d6b4();
    func_0203d1b4();
    Touch_Create();
    ResMgr_Create();
    GfxSys_Create();
    func_02039750();
    Snd_Create();
    Movie_Create();
    func_02046c6c();
    func_0203e3e8();
    func_0204ae14();
    while (TRUE) {
        Sys_WaitVBlank(gSysState);
        func_0203e6bc();
        GfxSys_EndFrame(gGfxSys);
        GfxSys_ApplyFade(-1);
        GfxSys_FlipTextBg(gGfxSys);
        func_02039f84(gGfxMgr);
        func_0203d8b0();
        func_0203d8e8();
        func_0203d298(gPad);
        func_02043f70(gMovie);
        func_0204aee8();
        GfxSys_ApplyFade(2);
        func_020364c0(gResMgr);
        SndQueue_Update(gSndQueue);
        Sys_WaitFrame(gSysState);
        GfxSys_SwapBuffers(gGfxSys);
    }
}

}
