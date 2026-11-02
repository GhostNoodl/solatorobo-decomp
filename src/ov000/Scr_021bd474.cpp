#pragma optimization_level 2
#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ActorMarker.h"

typedef struct {
    s32 x;
    s32 y;
} Scr021bd474;

#define FXM(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {

int Math_ProjectToScreen(Scr021bd474 *out, const VecFx32 *pos);

void ActorMarker_UpdateScreenPos(ActorMarker *self, VecFx32 *v) {
    Scr021bd474 scr;
    VecFx32 p;
    if (self->snap) {
        self->snap = 0;
        p = self->work.pos;
        p.y = p.y + (self->height + 0x19a);
        Math_ProjectToScreen(&scr, &p);
        scr.x <<= 12;
        scr.y <<= 12;
        self->work.x = scr.x;
        self->work.y = scr.y;
    } else {
        s32 dx;
        s32 dy;
        s32 d;
        s32 k;
        s64 ex; // widened copies; assigning ey first orders the hoisted sign words
        s64 ey;
        p = *v;
        p.y = p.y + (self->height + 0x19a);
        Math_ProjectToScreen(&scr, &p);
        scr.x <<= 12;
        scr.y <<= 12;
        dx = scr.x - self->work.x;
        dy = scr.y - self->work.y;
        ey = dy;
        ex = dx;
        d = FXM(dx, dx);
        d += FXM(dy, dy);
        k = self->rate;
        if (k == 0x1000) {
            if ((d < 0 ? -d : d) > 0x800000) {
                k = 0x1000;
            } else if ((d < 0 ? -d : d) > 0x400000) {
                k = 0xc00;
            } else {
                k = 0x800;
            }
        }
        self->work.x += (s32)((ex * k + 0x800) >> 12);
        self->work.y += (s32)((ey * k + 0x800) >> 12);
    }
}

}
