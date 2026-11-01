#include "ov000/VObj.h"

typedef struct {
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
} Lerp0218a56c;

typedef struct {
    s32 x0;
    s32 x1;
    u16 y0;
    u16 y1;
} LerpAngle0218a5ec;

typedef struct {
    s32 min[3];
    s32 max[3];
    u32 len;
} PathBox0218a670;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
} PathFlags0218a670;

typedef struct {
    s32 pos[3];
    s32 ofs[3];
    s32 dist;
    u16 ang[3];
    PathFlags0218a670 flags;
} PathInfo0218a670;

typedef struct {
    u8 pad_00[0x104];
    s32 mn[3];
    s32 mx[3];
    s32 dist;
} PathCam0218a670;

extern "C" {

s32 FX_Div(s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

static inline s32 FX_Mul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

s32 func_ov000_0218a56c(const Lerp0218a56c *self, s32 v) {
    s32 x0 = self->x0;
    s32 x1 = self->x1;
    s32 r = 0;
    if (x0 < x1) {
        if (v < x0) {
            r = self->y0;
        } else if (v > x1) {
            r = self->y1;
        }
    } else {
        if (v > x0) {
            r = self->y0;
        } else if (v < x1) {
            r = self->y1;
        }
    }
    if (r != 0) {
        return r;
    }
    return self->y0 + FX_Mul(self->y1 - self->y0, FX_Div(v - x0, x1 - x0));
}

/* The angle form of the lerp above; the const pointee lets the 0x8000 stack argument go out before the
 * two halfword loads. */
u16 func_ov000_0218a5ec(const LerpAngle0218a5ec *self, s32 v) {
    s32 x0 = self->x0;
    s32 x1 = self->x1;
    u16 r = 0;
    if (x0 < x1) {
        if (v < x0) {
            r = self->y0;
        } else if (v > x1) {
            r = self->y1;
        }
    } else {
        if (v > x0) {
            r = self->y0;
        } else if (v < x1) {
            r = self->y1;
        }
    }
    if (r == 0) {
        r = func_01ffc128(self->y1, self->y0, FX_Div(v - x0, x1 - x0), 1, 0x8000);
    }
    return r;
}


// Runs the path node's command list if the position is inside the node's box: each command word is an
// opcode followed by its operands (a value, a Lerp0218a56c or a LerpAngle0218a5ec).
// The command stream is a const parameter, so its loads are not ordered against the stores; with the
// ofs zero store written first, it is issued in the load latency slot in cases 20 to 22 (round swA).
BOOL func_ov000_0218a670(PathCam0218a670 *self, const PathBox0218a670 *box, const u32 *code, PathInfo0218a670 *st) {
    const u32 *end;
    if (st->pos[0] < box->min[0] || st->pos[0] > box->max[0] || st->pos[1] < box->min[1] ||
        st->pos[1] > box->max[1] || st->pos[2] < box->min[2] || st->pos[2] > box->max[2]) {
        return FALSE;
    }
    end = (const u32 *)((const u8 *)code + box->len);
    while (code < end) {
        u32 op = *code;
        const u32 *a = code + 1;
        code = a;
        switch (op) {
        case 0:
            break;
        case 1:
            code = a + 1;
            self->dist = st->dist = *(const s32 *)a;
            break;
        case 2:
            code = a + 4;
            self->dist = st->dist = func_ov000_0218a56c((const Lerp0218a56c *)a, st->pos[0]);
            break;
        case 3:
            code = a + 4;
            self->dist = st->dist = func_ov000_0218a56c((const Lerp0218a56c *)a, st->pos[1]);
            break;
        case 4:
            code = a + 4;
            self->dist = st->dist = func_ov000_0218a56c((const Lerp0218a56c *)a, st->pos[2]);
            break;
        case 5:
            code = a + 1;
            st->ang[0] = *(const u16 *)a;
            break;
        case 6:
            code = a + 1;
            st->ang[1] = *(const u16 *)a;
            break;
        case 7:
            code = a + 1;
            st->ang[2] = *(const u16 *)a;
            break;
        case 8:
            st->flags.b0 = TRUE;
            break;
        case 9:
            st->flags.b1 = TRUE;
            break;
        case 10:
            st->flags.b2 = TRUE;
            break;
        case 11:
            code = a + 3;
            st->ang[0] = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos[0]);
            break;
        case 12:
            code = a + 3;
            st->ang[0] = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos[1]);
            break;
        case 13:
            code = a + 3;
            st->ang[0] = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos[2]);
            break;
        case 14:
            code = a + 3;
            st->ang[1] = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos[0]);
            break;
        case 15:
            code = a + 3;
            st->ang[1] = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos[1]);
            break;
        case 16:
            code = a + 3;
            st->ang[1] = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos[2]);
            break;
        case 17:
            code = a + 3;
            st->ang[2] = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos[0]);
            break;
        case 18:
            code = a + 3;
            st->ang[2] = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos[1]);
            break;
        case 19:
            code = a + 3;
            st->ang[2] = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos[2]);
            break;
        case 20:
            st->ofs[0] = 0;
            self->mn[0] = st->pos[0] = *(const s32 *)a;
            self->mx[0] = st->pos[0];
            code = a + 1;
            break;
        case 21:
            st->ofs[1] = 0;
            self->mn[1] = st->pos[1] = *(const s32 *)a;
            self->mx[1] = st->pos[1];
            code = a + 1;
            break;
        case 22:
            st->ofs[2] = 0;
            self->mn[2] = st->pos[2] = *(const s32 *)a;
            self->mx[2] = st->pos[2];
            code = a + 1;
            break;
        case 23: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos[0] < v) {
                st->pos[0] = v;
                self->mn[0] = v;
            }
            break;
        }
        case 24: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos[0] > v) {
                st->pos[0] = v;
                self->mx[0] = v;
            }
            break;
        }
        case 25: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos[1] < v) {
                st->pos[1] = v;
                self->mn[1] = v;
            }
            break;
        }
        case 26: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos[1] > v) {
                st->pos[1] = v;
                self->mx[1] = v;
            }
            break;
        }
        case 27: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos[2] < v) {
                st->pos[2] = v;
                self->mn[2] = v;
            }
            break;
        }
        case 28: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos[2] > v) {
                st->pos[2] = v;
                self->mx[2] = v;
            }
            break;
        }
        case 29:
            code = a + 1;
            st->ofs[0] = *(const s32 *)a;
            break;
        case 30:
            code = a + 1;
            st->ofs[1] = *(const s32 *)a;
            break;
        case 31:
            code = a + 1;
            st->ofs[2] = *(const s32 *)a;
            break;
        }
    }
    return TRUE;
}

}
