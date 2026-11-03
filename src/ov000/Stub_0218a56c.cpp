#include "ov000/VObj.h"
#include "ov000/FieldCam.h"

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

extern "C" {

s32 FX_Div(s32 a, s32 b);
u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);

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
        r = Angle_Approach(self->y1, self->y0, FX_Div(v - x0, x1 - x0), 1, 0x8000);
    }
    return r;
}


// Runs the path node's command list if the position is inside the node's box: each command word is an
// opcode followed by its operands (a value, a Lerp0218a56c or a LerpAngle0218a5ec).
// The command stream is a const parameter, so its loads are not ordered against the stores; with the
// ofs zero store written first, it is issued in the load latency slot in cases 20 to 22 (round swA).
BOOL func_ov000_0218a670(FieldCam *self, const FieldCamZone *box, const u32 *code, FieldCamZoneResult *st) {
    const u32 *end;
    if (st->pos.x < box->min.x || st->pos.x > box->max.x || st->pos.y < box->min.y ||
        st->pos.y > box->max.y || st->pos.z < box->min.z || st->pos.z > box->max.z) {
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
            self->clampDist = st->dist = *(const s32 *)a;
            break;
        case 2:
            code = a + 4;
            self->clampDist = st->dist = func_ov000_0218a56c((const Lerp0218a56c *)a, st->pos.x);
            break;
        case 3:
            code = a + 4;
            self->clampDist = st->dist = func_ov000_0218a56c((const Lerp0218a56c *)a, st->pos.y);
            break;
        case 4:
            code = a + 4;
            self->clampDist = st->dist = func_ov000_0218a56c((const Lerp0218a56c *)a, st->pos.z);
            break;
        case 5:
            code = a + 1;
            st->ang.x = *(const u16 *)a;
            break;
        case 6:
            code = a + 1;
            st->ang.y = *(const u16 *)a;
            break;
        case 7:
            code = a + 1;
            st->ang.z = *(const u16 *)a;
            break;
        case 8:
            st->flags.aimPitch = TRUE;
            break;
        case 9:
            st->flags.aimYaw = TRUE;
            break;
        case 10:
            st->flags.snapRoll = TRUE;
            break;
        case 11:
            code = a + 3;
            st->ang.x = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos.x);
            break;
        case 12:
            code = a + 3;
            st->ang.x = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos.y);
            break;
        case 13:
            code = a + 3;
            st->ang.x = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos.z);
            break;
        case 14:
            code = a + 3;
            st->ang.y = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos.x);
            break;
        case 15:
            code = a + 3;
            st->ang.y = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos.y);
            break;
        case 16:
            code = a + 3;
            st->ang.y = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos.z);
            break;
        case 17:
            code = a + 3;
            st->ang.z = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos.x);
            break;
        case 18:
            code = a + 3;
            st->ang.z = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos.y);
            break;
        case 19:
            code = a + 3;
            st->ang.z = func_ov000_0218a5ec((const LerpAngle0218a5ec *)a, st->pos.z);
            break;
        case 20:
            st->ofs.x = 0;
            self->clampMin.x = st->pos.x = *(const s32 *)a;
            self->clampMax.x = st->pos.x;
            code = a + 1;
            break;
        case 21:
            st->ofs.y = 0;
            self->clampMin.y = st->pos.y = *(const s32 *)a;
            self->clampMax.y = st->pos.y;
            code = a + 1;
            break;
        case 22:
            st->ofs.z = 0;
            self->clampMin.z = st->pos.z = *(const s32 *)a;
            self->clampMax.z = st->pos.z;
            code = a + 1;
            break;
        case 23: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos.x < v) {
                st->pos.x = v;
                self->clampMin.x = v;
            }
            break;
        }
        case 24: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos.x > v) {
                st->pos.x = v;
                self->clampMax.x = v;
            }
            break;
        }
        case 25: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos.y < v) {
                st->pos.y = v;
                self->clampMin.y = v;
            }
            break;
        }
        case 26: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos.y > v) {
                st->pos.y = v;
                self->clampMax.y = v;
            }
            break;
        }
        case 27: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos.z < v) {
                st->pos.z = v;
                self->clampMin.z = v;
            }
            break;
        }
        case 28: {
            s32 v = *(const s32 *)a;
            code = a + 1;
            if (st->pos.z > v) {
                st->pos.z = v;
                self->clampMax.z = v;
            }
            break;
        }
        case 29:
            code = a + 1;
            st->ofs.x = *(const s32 *)a;
            break;
        case 30:
            code = a + 1;
            st->ofs.y = *(const s32 *)a;
            break;
        case 31:
            code = a + 1;
            st->ofs.z = *(const s32 *)a;
            break;
        }
    }
    return TRUE;
}

}
