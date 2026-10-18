#include "Main/Effect/Effect.h"

extern "C" {

extern const u8 data_02082ba4[0x38];
extern EffectPtclHandler data_0208c908;
extern EffectPtclHandler data_0208c910;
extern EffectPtclHandler data_0208c918;
extern EffectPtclHandler data_0208c920;
extern EffectPtclHandler data_0208c928;
extern EffectPtclHandler data_0208c930;
extern EffectPtclHandler data_0208c938;
extern EffectPtclHandler data_0208c940;

void func_02068da8(EffectPtcl *p) {
    p->unk_58 = -1;
    MIi_CpuCopyFast(data_02082ba4, p->dl, sizeof(p->dl));
    p->tex = NULL;
    p->polyAttr = 0x21200000;
    p->texAddr = -1;
    p->unk_a0 = 0x3f;
    p->cmds = NULL;
    p->numCmds = 0;
    p->time = 0;
    p->unk_b4 = 0x1000;
    p->unk_b8 = -1;
    p->pos.x = 0;
    p->pos.y = 0;
    p->pos.z = 0;
    p->dir.x = 0;
    p->dir.y = 0;
    p->dir.z = 0;
    p->speed = 0;
    p->unk_14 = 0;
    p->unk_16 = 0;
    p->unk_18 = 0;
    p->rot.x = 0;
    p->rot.y = 0;
    p->rot.z = 0;
    p->scale.x = 0x1000;
    p->scale.y = 0x1000;
    p->scale.z = 0x1000;
    p->alpha = 0x1f;
    p->color = 0x7fff;
    p->unk_50 = 0;
    p->texIdx = 0;
    p->next = NULL;
    p->prev = NULL;
}

}
