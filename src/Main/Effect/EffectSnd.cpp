#include "Main/Snd/SndMgr.h"


extern "C" {

typedef struct EffectSndCmd {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ s32 id;
} EffectSndCmd;

extern SndMgr *data_02097e4c;
extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);

BOOL func_02069f10(void *a, void *b, const EffectSndCmd *cmd) {
    func_02049a48(data_02097e4c, cmd->id, -1, -1, -1);
    return TRUE;
}

}
