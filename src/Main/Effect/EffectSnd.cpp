#include "Main/Snd/SndMgr.h"


extern "C" {

typedef struct EffectSndCmd {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ s32 id;
} EffectSndCmd;

extern SndMgr *gSndMgr;
extern SndHandle *SndMgr_PlayVolume(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);

BOOL EffectPtclCmd_PlaySnd(void *a, void *b, const EffectSndCmd *cmd) {
    SndMgr_PlayVolume(gSndMgr, cmd->id, -1, -1, -1);
    return TRUE;
}

}
