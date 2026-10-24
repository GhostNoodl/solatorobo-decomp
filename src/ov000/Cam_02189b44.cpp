#include "ov000/VObj.h"
#include "ov000/Vec.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
} Bits9b44;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 mode : 2;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} Flags9b44;

typedef struct {
    VecFx32 pos;
    VecFx32 ofs;
    s32 dist;
    u16 ang[3];
    Bits9b44 flags;
    u8 pad;
} PathInfo9b44;

typedef struct {
    u8 pad_00[0x18];
    s32 len;
} PathNode9b44;

typedef struct {
    void *vtable;
    VecFx32 tgt;
    VecFx32 pos;
    u8 pad_1c[0x40 - 0x1c];
    s16 unk_40;
    u16 ang[3];
    s32 unk_48;
    s32 dist;
    s32 dist_spd;
    u16 cur_ang[3];
    u8 pad_5a[2];
    s32 ang_spd[3];
    u8 pad_68[0x78 - 0x68];
    VecFx32 cur_pos;
    s32 pos_spd;
    u8 pad_88[0x9c - 0x88];
    Bits9b44 unk_9c;
    u8 pad_9d[0xbc - 0x9d];
    VecFx32 unk_bc;
    PathNode9b44 *path;
    PathNode9b44 *cur_node;
    void *cur_data;
    u16 cur_idx;
    u16 path_n;
    Bits9b44 unk_d8;
    u8 timer;
    Flags9b44 unk_da;
    u8 pad_db;
    VecFx32 unk_dc;
    VecFx32 unk_e8;
    s32 unk_f4;
    u16 unk_f8[3];
    s16 unk_fe;
    s16 unk_100;
    u8 pad_102[2];
    s32 mn[3];
    s32 mx[3];
    s32 unk_11c;
} Cam9b44;

extern "C" {

extern u8 data_ov000_021c9d4c[];
extern u8 data_ov000_021c9d58[];
extern u8 data_ov000_021c9d64[];
void func_0204b43c(void *self);
void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *out);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
u16 FX_Atan2(s32 y, s32 x);
s32 FX_Sqrt(s32 x);
BOOL func_ov000_0218a670(Cam9b44 *self, PathNode9b44 *node, void *data, PathInfo9b44 *info);

static inline u16 Atan2r9b44(s32 x, s32 y) { return FX_Atan2(y, x); }
static inline s32 Scale9b44(s32 s, s32 v) {
    s32 r = v;
    if (s != 0x1000) {
        r = (s32)(((s64)s * v + 0x800) >> 12);
    }
    return r;
}

static inline void Approach9b44(VecFx32 *out, const VecFx32 *to, const VecFx32 *cur, s32 rate) {
    VecFx32 d;
    d.x = to->x - cur->x;
    d.y = to->y - cur->y;
    d.z = to->z - cur->z;
    VEC_MultAdd(rate, &d, cur, out);
}

static inline void Snap2(Cam9b44 *self, const VecFx32 *pos, const u16 *ang, s32 dist) {
    self->pos = *pos;
    self->cur_pos = *pos;
    self->pos_spd = 0x1000;
    self->ang[0] = ang[0];
    self->ang[1] = ang[1];
    self->ang[2] = ang[2];
    self->cur_ang[0] = ang[0];
    self->cur_ang[1] = ang[1];
    self->cur_ang[2] = ang[2];
    self->ang_spd[0] = 0x1000;
    self->ang_spd[1] = 0x1000;
    self->ang_spd[2] = 0x1000;
    self->unk_48 = dist;
    self->dist = dist;
    self->dist_spd = 0x1000;
}

static inline void Snap9b44(Cam9b44 *self) {
    Snap2(self, &self->unk_e8, self->unk_f8, self->unk_f4);
}

static inline void AngTo9b44(Cam9b44 *self, const u16 *ang, s32 step, s32 mode, s32 s0, s32 s1, s32 s2) {
    u16 d[3];
    u16 a0, a1, a2;
    d[0] = ang[0];
    d[0] = d[0] - self->cur_ang[0];
    d[1] = ang[1] - self->cur_ang[1];
    d[2] = ang[2] - self->cur_ang[2];
    a0 = func_01ffc128(d[0], 0, step, mode, 0x8000);
    a1 = func_01ffc128(d[1], 0, step, mode, 0x8000);
    a2 = func_01ffc128(d[2], 0, step, mode, 0x8000);
    self->cur_ang[0] = a0 + self->cur_ang[0];
    self->ang_spd[0] = s0;
    self->ang_spd[1] = s1;
    self->ang_spd[2] = s2;
    self->cur_ang[1] = a1 + self->cur_ang[1];
    self->cur_ang[2] = a2 + self->cur_ang[2];
}

static inline void DistToT9b44(Cam9b44 *self, s32 dist, s32 rate) {
    s32 d = dist;
    s32 cur = self->dist;
    d = d - cur;
    d = (s32)(((s64)d * rate + 0x800) >> 12);
    self->dist = d + cur;
    self->dist_spd = 0x733;
}

static inline void DistTo9b44(Cam9b44 *self, s32 dist, s32 rate) {
    s32 cur = self->dist;
    s32 d = dist;
    d = d - cur;
    d = (s32)(((s64)d * rate + 0x800) >> 12);
    self->dist = d + cur;
    self->dist_spd = 0x733;
}

void func_ov000_02189b44(Cam9b44 *self) {
    if (self->unk_d8.b0 || self->unk_9c.b1) {
        func_0204b43c(self);
        return;
    }
    if (self->timer != 0) {
        self->timer--;
        if (self->unk_9c.b0) {
            VecFx32 out;
            Approach9b44(&out, &self->unk_e8, &self->cur_pos, Scale9b44(self->unk_fe, 0x200));
            self->cur_pos = out;
            self->pos_spd = 0x733;
            AngTo9b44(self, self->unk_f8, Scale9b44(self->unk_100, 0x148), 1, 0x733, 0x733, 0x733);
            DistToT9b44(self, self->unk_f4, Scale9b44(self->unk_fe, 0x200));
        } else {
            Snap9b44(self);
        }
    } else if (self->unk_d8.b1) {
        if (self->unk_9c.b0) {
            VecFx32 v;
            v.x = self->unk_e8.x;
            v.y = self->unk_e8.y;
            v.z = self->unk_e8.z;
            if (self->unk_da.b0) {
                VEC_Add(&v, &self->unk_dc, &v);
            } else {
                VEC_Add(&v, (const VecFx32 *)data_ov000_021c9d4c, &v);
            }
            self->cur_pos = v;
            self->pos_spd = 0x1000;
            self->cur_ang[0] = self->unk_f8[0];
            self->cur_ang[1] = self->unk_f8[1];
            self->cur_ang[2] = self->unk_f8[2];
            self->ang_spd[0] = 0x266;
            self->ang_spd[1] = 0x266;
            self->ang_spd[2] = 0x266;
            self->dist = self->unk_f4;
            self->dist_spd = 0xe66;
        } else {
            Snap9b44(self);
        }
    } else {
        u16 i;
        PathInfo9b44 info;
        u16 n;
        s32 dx;
        PathNode9b44 *node;
        void *data;
        s32 s0, s1, s2;
        s32 dy, dz;
        info.pos = self->unk_bc;
        info.ofs.x = 0;
        info.ofs.y = 0x1400;
        info.ofs.z = 0;
        info.ang[0] = self->ang[0];
        info.ang[1] = self->ang[1];
        info.ang[2] = self->ang[2];
        info.dist = 0x8000;
        *(u16 *)&info.flags = 0;
        node = self->path;
        self->cur_node = NULL;
        self->cur_data = NULL;
        self->cur_idx = 0;
        n = self->path_n;
        self->mn[0] = (s32)0x80000000;
        self->mn[1] = (s32)0x80000000;
        self->mn[2] = (s32)0x80000000;
        self->mx[0] = 0x7fffffff;
        self->mx[1] = 0x7fffffff;
        self->mx[2] = 0x7fffffff;
        self->unk_11c = 0x8000;
        if (node == NULL || n == 0) {
            data = data_ov000_021c9d58;
            node = (PathNode9b44 *)data_ov000_021c9d64;
            n = 1;
        } else {
            data = (u8 *)node + 0x1c;
        }
        for (i = 0; i < n; i++) {
            if (func_ov000_0218a670(self, node, data, &info)) {
                self->cur_node = node;
                self->cur_data = data;
                self->cur_idx = i;
                break;
            }
            node = (PathNode9b44 *)((u8 *)data + node->len);
            data = (u8 *)node + 0x1c;
        }
        if (self->unk_da.b0) {
            info.ofs = self->unk_dc;
        }
        VEC_Add(&info.pos, &info.ofs, &info.pos);
        if (self->unk_da.b1) {
            info.pos = self->unk_e8;
        }
        s0 = 0x733;
        dx = info.pos.x - self->tgt.x;
        dy = info.pos.y - self->tgt.y;
        dz = info.pos.z - self->tgt.z;
        s1 = 0x733;
        s2 = 0x733;
        if (self->unk_da.b5) {
            info.ang[1] = self->unk_f8[1];
        } else if (info.flags.b1) {
            s1 = 0x1000;
            {
                s32 vx = self->pos.x;
                s32 vz = self->pos.z;
                vx = info.pos.x - vx;
                vz = info.pos.z - vz;
                info.ang[1] = Atan2r9b44(dz + vz * 4, dx + vx * 4);
            }
        }
        if (self->unk_da.b4) {
            info.ang[0] = self->unk_f8[0];
        } else if (info.flags.b0) {
            s0 = 0x1000;
            info.ang[0] = FX_Atan2(FX_Sqrt(dx * dx + dz * dz), dy);
        }
        if (self->unk_da.b6) {
            info.ang[2] = self->unk_f8[2];
        } else if (info.flags.b2) {
            s2 = 0x1000;
        }
        if (self->unk_da.mode == 1) {
            info.dist = self->unk_f4;
        } else if (self->unk_da.mode == 2) {
            info.dist += self->unk_f4;
        }
        if (self->unk_9c.b0) {
            VecFx32 out;
            s32 rate = 0x19a;
            if (info.flags.b1) {
                rate <<= 2;
            }
            Approach9b44(&out, &info.pos, &self->cur_pos, rate);
            self->cur_pos = out;
            self->pos_spd = 0x733;
            AngTo9b44(self, info.ang, 0x148, 0, s0, s1, s2);
            DistTo9b44(self, info.dist, 0x19a);
        } else {
            Snap2(self, &info.pos, info.ang, info.dist);
        }
    }
    *(u8 *)&self->unk_da = 0;
    self->unk_40 = 1;
    func_0204b43c(self);
}

}
