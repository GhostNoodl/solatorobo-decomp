#include "types.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/Pad.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Movie/Movie.h"

extern "C" {

extern void *data_02097e48;

extern void func_0203d6b4(void);
extern void func_0203d1b4(void);
extern void func_0203d560(void);
extern void ResMgr_Create(void);
extern void GfxSys_Create(void);
extern void func_02039750(void);
extern void func_0204a87c(void);
extern void Movie_Create(void);
extern void func_02046c6c(void);
extern void func_0203e3e8(void);
extern void func_0204ae14(void);
extern void Sys_WaitVBlank(UnkSys *sys);
extern void func_0203e6bc(void);
extern void func_0203b96c(GfxSys *sys);
extern void func_0203ced8(int mode);
extern void func_0203baa4(GfxSys *sys);
extern void func_02039f84(GfxMgr *mgr);
extern void func_0203d8b0(void);
extern void func_0203d8e8(void);
extern void func_0203d298(Pad *pad);
extern void func_02043f70(Movie *movie);
extern void func_0204aee8(void);
extern void func_020364c0(ResMgr *mgr);
extern void func_0204ab8c(void *queue);
extern void func_0203dacc(UnkSys *sys);
extern void func_0203ba7c(GfxSys *sys);

int main(void) {
    func_0203d6b4();
    func_0203d1b4();
    func_0203d560();
    ResMgr_Create();
    GfxSys_Create();
    func_02039750();
    func_0204a87c();
    Movie_Create();
    func_02046c6c();
    func_0203e3e8();
    func_0204ae14();
    while (TRUE) {
        Sys_WaitVBlank(data_02097dd0);
        func_0203e6bc();
        func_0203b96c(data_02097d48);
        func_0203ced8(-1);
        func_0203baa4(data_02097d48);
        func_02039f84(data_02097ce0);
        func_0203d8b0();
        func_0203d8e8();
        func_0203d298(data_02097dc8);
        func_02043f70(data_02097e3c);
        func_0204aee8();
        func_0203ced8(2);
        func_020364c0(data_02097cdc);
        func_0204ab8c(data_02097e48);
        func_0203dacc(data_02097dd0);
        func_0203ba7c(data_02097d48);
    }
}

}
