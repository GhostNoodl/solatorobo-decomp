#include "ov000/ObjLayouts.h"
#include "Main/Sys/Pad.h"

extern "C" {
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);

void Lo021cacd8_PostUpdate(Lo021cacd8 *self) {
    u32 rep;
    u32 trg;
    if (self->flag2) {
        return;
    }
    trg = data_02097dc8->trig;
    rep = data_02097dc8->repeat;
    if (trg & 1) {
        SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
        if (self->onDone != NULL) {
            self->onDone(self, TRUE);
        }
    } else if (trg & 2) {
        SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
        if (self->onDone != NULL) {
            self->onDone(self, FALSE);
        }
    } else if (rep & 0x40) {
        u16 old = self->count;
        s32 v = old + 1;
        if (v >= self->max) {
            v = self->max;
        }
        self->count = v;
        if (old != self->count) {
            SndMgr_PlayVolume(data_02097e4c, 0x1d, -1, -1, -1);
        }
    } else if (rep & 0x80) {
        u16 old = self->count;
        s32 v = old - 1;
        self->count = v <= 1 ? 1 : v;
        if (old != self->count) {
            SndMgr_PlayVolume(data_02097e4c, 0x1d, -1, -1, -1);
        }
    } else if (rep & 0x20) {
        u16 old = self->count;
        s32 v = old + 10;
        if (v >= self->max) {
            v = self->max;
        }
        self->count = v;
        if (old != self->count) {
            SndMgr_PlayVolume(data_02097e4c, 0x1d, -1, -1, -1);
        }
    } else if (rep & 0x10) {
        u16 old = self->count;
        s32 v = old - 10;
        self->count = v <= 1 ? 1 : v;
        if (old != self->count) {
            SndMgr_PlayVolume(data_02097e4c, 0x1d, -1, -1, -1);
        }
    }
    self->unk_94++;
    self->unk_94 %= 60;
    if (self->count != self->max) {
        s32 x = self->upAlpha += 3;
        self->upAlpha = x >= 0x1f ? 0x1f : x;
    } else {
        s32 x = self->upAlpha -= 3;
        self->upAlpha = x <= 0 ? 0 : x;
    }
    if (self->count != 1) {
        s32 x = self->downAlpha += 3;
        self->downAlpha = x >= 0x1f ? 0x1f : x;
    } else {
        s32 x = self->downAlpha -= 3;
        self->downAlpha = x <= 0 ? 0 : x;
    }
}
}
