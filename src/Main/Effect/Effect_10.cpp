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

void func_02069184(EffectEmitterSub *sub) {
    sub->funcs[0] = data_0208c908;
    sub->funcs[1] = data_0208c910;
    sub->funcs[2] = data_0208c918;
    sub->funcs[3] = data_0208c920;
    sub->funcs[4] = data_0208c928;
    sub->funcs[5] = data_0208c930;
    sub->funcs[6] = data_0208c938;
    sub->funcs[7] = data_0208c940;
}

void func_02069248(EffectEmitterSub *sub) {
}

BOOL func_0206924c(EffectEmitterSub *sub, EffectPtcl *p) {
    BOOL done = FALSE;
    EffectPtclCmd *cmds = p->cmds;
    s32 i;
    s32 n = p->numCmds;
    s32 t = p->time;
    BOOL ok = TRUE;
    EffectPtclCmd *cmd;
    for (i = 0; i < n; i++) {
        cmd = &cmds[i];
        if (t < cmd->start) {
            done = FALSE;
            break;
        }
        if (t >= cmd->start + cmd->len) {
            done = TRUE;
        } else {
            done = FALSE;
            ok = (sub->*(sub->funcs[cmd->type]))(p, cmd);
        }
    }
    return (ok && !done) ? TRUE : FALSE;
}

}
