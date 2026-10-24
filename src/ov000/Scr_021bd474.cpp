#pragma optimization_level 2
#include "ov000/VObj.h"
#include "ov000/Vec.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 moved : 1;
    u32 rest : 29;
} Flags021bd474;

typedef struct {
    Flags021bd474 flags;
    u8 unk_04[0x48];
    s32 unk_4c;
    u8 unk_50[0xc];
    s32 unk_5c;
    u8 unk_60[8];
    s32 unk_68;
    VecFx32 unk_6c;
    s32 unk_78;
    s32 unk_7c;
} Obj021bd474;

typedef struct {
    s32 x;
    s32 y;
} Scr021bd474;

#define FXM(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {

int func_0204061c(Scr021bd474 *out, const VecFx32 *pos);

void func_ov000_021bd474(Obj021bd474 *self, VecFx32 *v) {
    Scr021bd474 scr;
    VecFx32 p;
    if (self->flags.moved) {
        self->flags.moved = 0;
        p = self->unk_6c;
        p.y = p.y + (self->unk_5c + 0x19a);
        func_0204061c(&scr, &p);
        scr.x <<= 12;
        scr.y <<= 12;
        self->unk_78 = scr.x;
        self->unk_7c = scr.y;
    } else {
        s32 dx;
        s32 dy;
        s32 d;
        s32 k;
        s64 ex; // widened copies; assigning ey first orders the hoisted sign words
        s64 ey;
        p = *v;
        p.y = p.y + (self->unk_5c + 0x19a);
        func_0204061c(&scr, &p);
        scr.x <<= 12;
        scr.y <<= 12;
        dx = scr.x - self->unk_78;
        dy = scr.y - self->unk_7c;
        ey = dy;
        ex = dx;
        d = FXM(dx, dx);
        d += FXM(dy, dy);
        k = self->unk_4c;
        if (k == 0x1000) {
            if ((d < 0 ? -d : d) > 0x800000) {
                k = 0x1000;
            } else if ((d < 0 ? -d : d) > 0x400000) {
                k = 0xc00;
            } else {
                k = 0x800;
            }
        }
        self->unk_78 += (s32)((ex * k + 0x800) >> 12);
        self->unk_7c += (s32)((ey * k + 0x800) >> 12);
    }
}

}
