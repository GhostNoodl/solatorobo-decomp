#include "ov002/ov002.h"

extern "C" {

void Obj021efe4c_PlaySndCues(Obj021efe4c *self, s32 t, s32 range) {
    Ov002SndCue *p = self->cue;
    s32 v;
    if (p == NULL || self->cues == NULL) {
        return;
    }
    if (self->unk_5d) {
        v = p->time << 12;
        while (v >= 0 && v < t) {
            SndMgr_PlayVolume(gSndMgr, p->id, -1, -1, -1);
            p = ++self->cue;
            v = p->time << 12;
        }
    } else {
        s32 lo = t - range;
        v = p->time << 12;
        while (v < t && v >= lo) {
            SndMgr_PlayVolume(gSndMgr, p->id, -1, -1, -1);
            if (self->cue == self->cues) {
                return;
            }
            p = --self->cue;
            v = p->time << 12;
        }
    }
}

}
