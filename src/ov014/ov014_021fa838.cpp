#include "ov014/ov014.h"

extern "C" {

extern char data_ov014_022170d8[];
extern char data_ov014_022170e7[];
extern char data_ov014_022170f4[];
extern void *data_02097e4c;
extern void SndMgr_LoadHeapState(void *a, s32 b, s32 c);
extern void func_ov000_02187a20(void *a, s32 b);
extern void *func_020359d0(const char *a, s32 b, s32 c);

void Ov014Act_021fa6a0_Init(Ov014Act_021fa6a0 *self) {
    func_ov003_021d0fc0(self);
    {
        const char *a = data_ov014_022170e7;
        const char *b = data_ov014_022170f4;
        Ov014Names *n = &self->unk_124;
        if (a) {
            STD_CopyString(n->mdlDir, a);
            STD_CopyString(n->mdlName, b);
            n->ownMdl = 1;
            STD_CopyString(n->anmDir, a);
            STD_CopyString(n->anmName, b);
            n->ownAnm = 1;
        }
        n->unk_00 = 0;
    }
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 9);
    func_ov000_02187a20(data_ov000_021ccd54, 10);
    func_020359d0(data_ov014_022170d8, 7, 0);
}

}
