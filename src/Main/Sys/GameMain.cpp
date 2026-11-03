#include "types.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/Pad.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Movie/Movie.h"

extern "C" {

extern void *gSndQueue;

extern void Sys_InitHw(void);
extern void Pad_Create(void);
extern void Touch_Create(void);
extern void ResMgr_Create(void);
extern void GfxSys_Create(void);
extern void GfxMgr_Create(void);
extern void Snd_Create(void);
extern void Movie_Create(void);
extern void SysCard_Create(void);
extern void Vram_InitTransfers(void);
extern void SceneMgr_Create(void);
extern void Sys_WaitVBlank(UnkSys *sys);
extern void Vram_FlushTransfers(void);
extern void GfxSys_EndFrame(GfxSys *sys);
extern void GfxSys_ApplyFade(int mode);
extern void GfxSys_FlipTextBg(GfxSys *sys);
extern void GfxMgr_Update(GfxMgr *mgr);
extern void func_0203d8b0(void);
extern void Sys_UpdateFold(void);
extern void Pad_Update(Pad *pad);
extern void Movie_Update(Movie *movie);
extern void SceneMgr_Run(void);
extern void ResMgr_Update(ResMgr *mgr);
extern void SndQueue_Update(void *queue);
extern void Sys_WaitFrame(UnkSys *sys);
extern void GfxSys_SwapBuffers(GfxSys *sys);

int main(void) {
    Sys_InitHw();
    Pad_Create();
    Touch_Create();
    ResMgr_Create();
    GfxSys_Create();
    GfxMgr_Create();
    Snd_Create();
    Movie_Create();
    SysCard_Create();
    Vram_InitTransfers();
    SceneMgr_Create();
    while (TRUE) {
        Sys_WaitVBlank(gSysState);
        Vram_FlushTransfers();
        GfxSys_EndFrame(gGfxSys);
        GfxSys_ApplyFade(-1);
        GfxSys_FlipTextBg(gGfxSys);
        GfxMgr_Update(gGfxMgr);
        func_0203d8b0();
        Sys_UpdateFold();
        Pad_Update(gPad);
        Movie_Update(gMovie);
        SceneMgr_Run();
        GfxSys_ApplyFade(2);
        ResMgr_Update(gResMgr);
        SndQueue_Update(gSndQueue);
        Sys_WaitFrame(gSysState);
        GfxSys_SwapBuffers(gGfxSys);
    }
}

}
