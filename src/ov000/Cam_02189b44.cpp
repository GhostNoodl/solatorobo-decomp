#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/FieldCam.h"

extern "C" {

extern const VecFx32 data_ov000_021c9d4c; // added to the look-at point when no offset is set
extern const u32 data_ov000_021c9d58[];   // the default zone's commands
extern const FieldCamZone data_ov000_021c9d64; // the default zone
void Camera_Apply(Camera *cam);
void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *out);
u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);
u16 FX_Atan2(s32 y, s32 x);
s32 FX_Sqrt(s32 x);

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

static inline void Snap2(FieldCam *self, const VecFx32 *pos, const Rot16 *ang, s32 dist) {
    self->base.at = *pos;
    self->base.atTarget = *pos;
    self->base.atRate = 0x1000;
    self->base.pitch = ang->x;
    self->base.yaw = ang->y;
    self->base.roll = ang->z;
    self->base.pitchTarget = ang->x;
    self->base.yawTarget = ang->y;
    self->base.rollTarget = ang->z;
    self->base.pitchRate = 0x1000;
    self->base.yawRate = 0x1000;
    self->base.rollRate = 0x1000;
    self->base.dist = dist;
    self->base.distTarget = dist;
    self->base.distRate = 0x1000;
}

static inline void Snap9b44(FieldCam *self) {
    Snap2(self, &self->unk_e8, &self->unk_f8, self->unk_f4);
}

static inline void AngTo9b44(FieldCam *self, const Rot16 *ang, s32 step, s32 mode, s32 s0, s32 s1, s32 s2) {
    u16 d[3];
    u16 a0, a1, a2;
    d[0] = ang->x;
    d[0] = d[0] - self->base.pitchTarget;
    d[1] = ang->y - self->base.yawTarget;
    d[2] = ang->z - self->base.rollTarget;
    a0 = Angle_Approach(d[0], 0, step, mode, 0x8000);
    a1 = Angle_Approach(d[1], 0, step, mode, 0x8000);
    a2 = Angle_Approach(d[2], 0, step, mode, 0x8000);
    self->base.pitchTarget = a0 + self->base.pitchTarget;
    self->base.pitchRate = s0;
    self->base.yawRate = s1;
    self->base.rollRate = s2;
    self->base.yawTarget = a1 + self->base.yawTarget;
    self->base.rollTarget = a2 + self->base.rollTarget;
}

static inline void DistToT9b44(FieldCam *self, s32 dist, s32 rate) {
    s32 d = dist;
    s32 cur = self->base.distTarget;
    d = d - cur;
    d = (s32)(((s64)d * rate + 0x800) >> 12);
    self->base.distTarget = d + cur;
    self->base.distRate = 0x733;
}

static inline void DistTo9b44(FieldCam *self, s32 dist, s32 rate) {
    s32 cur = self->base.distTarget;
    s32 d = dist;
    d = d - cur;
    d = (s32)(((s64)d * rate + 0x800) >> 12);
    self->base.distTarget = d + cur;
    self->base.distRate = 0x733;
}

void FieldCam_Apply(FieldCam *self) {
    if (self->unk_d8_0 || self->base.animated) {
        Camera_Apply(&self->base);
        return;
    }
    if (self->timer != 0) {
        self->timer--;
        if (self->base.smooth) {
            VecFx32 out;
            Approach9b44(&out, &self->unk_e8, &self->base.atTarget, Scale9b44(self->unk_fe, 0x200));
            self->base.atTarget = out;
            self->base.atRate = 0x733;
            AngTo9b44(self, &self->unk_f8, Scale9b44(self->unk_100, 0x148), 1, 0x733, 0x733, 0x733);
            DistToT9b44(self, self->unk_f4, Scale9b44(self->unk_fe, 0x200));
        } else {
            Snap9b44(self);
        }
    } else if (self->unk_d8_1) {
        if (self->base.smooth) {
            VecFx32 v;
            v.x = self->unk_e8.x;
            v.y = self->unk_e8.y;
            v.z = self->unk_e8.z;
            if (self->unk_da_0) {
                VEC_Add(&v, &self->unk_dc, &v);
            } else {
                VEC_Add(&v, &data_ov000_021c9d4c, &v);
            }
            self->base.atTarget = v;
            self->base.atRate = 0x1000;
            self->base.pitchTarget = self->unk_f8.x;
            self->base.yawTarget = self->unk_f8.y;
            self->base.rollTarget = self->unk_f8.z;
            self->base.pitchRate = 0x266;
            self->base.yawRate = 0x266;
            self->base.rollRate = 0x266;
            self->base.distTarget = self->unk_f4;
            self->base.distRate = 0xe66;
        } else {
            Snap9b44(self);
        }
    } else {
        u16 i;
        FieldCamZoneResult info;
        u16 n;
        s32 dx;
        const FieldCamZone *node;
        const u32 *code;
        s32 s0, s1, s2;
        s32 dy, dz;
        info.pos = self->unk_bc;
        info.ofs.x = 0;
        info.ofs.y = 0x1400;
        info.ofs.z = 0;
        info.ang.x = self->base.pitch;
        info.ang.y = self->base.yaw;
        info.ang.z = self->base.roll;
        info.dist = 0x8000;
        info.flags.all = 0;
        node = self->zones;
        self->zone = NULL;
        self->zoneCode = NULL;
        self->zoneIdx = 0;
        n = self->zoneCount;
        self->clampMin.x = (s32)0x80000000;
        self->clampMin.y = (s32)0x80000000;
        self->clampMin.z = (s32)0x80000000;
        self->clampMax.x = 0x7fffffff;
        self->clampMax.y = 0x7fffffff;
        self->clampMax.z = 0x7fffffff;
        self->clampDist = 0x8000;
        if (node == NULL || n == 0) {
            code = data_ov000_021c9d58;
            node = &data_ov000_021c9d64;
            n = 1;
        } else {
            code = (const u32 *)(node + 1);
        }
        for (i = 0; i < n; i++) {
            if (FieldCam_ApplyZone(self, node, code, &info)) {
                self->zone = node;
                self->zoneCode = code;
                self->zoneIdx = i;
                break;
            }
            node = (const FieldCamZone *)((const u8 *)code + node->len);
            code = (const u32 *)(node + 1);
        }
        if (self->unk_da_0) {
            info.ofs = self->unk_dc;
        }
        VEC_Add(&info.pos, &info.ofs, &info.pos);
        if (self->unk_da_1) {
            info.pos = self->unk_e8;
        }
        s0 = 0x733;
        dx = info.pos.x - self->base.eye.x;
        dy = info.pos.y - self->base.eye.y;
        dz = info.pos.z - self->base.eye.z;
        s1 = 0x733;
        s2 = 0x733;
        if (self->unk_da_5) {
            info.ang.y = self->unk_f8.y;
        } else if (info.flags.aimYaw) {
            s1 = 0x1000;
            {
                s32 vx = self->base.at.x;
                s32 vz = self->base.at.z;
                vx = info.pos.x - vx;
                vz = info.pos.z - vz;
                info.ang.y = Atan2r9b44(dz + vz * 4, dx + vx * 4);
            }
        }
        if (self->unk_da_4) {
            info.ang.x = self->unk_f8.x;
        } else if (info.flags.aimPitch) {
            s0 = 0x1000;
            info.ang.x = FX_Atan2(FX_Sqrt(dx * dx + dz * dz), dy);
        }
        if (self->unk_da_6) {
            info.ang.z = self->unk_f8.z;
        } else if (info.flags.snapRoll) {
            s2 = 0x1000;
        }
        if (self->unk_da_2 == 1) {
            info.dist = self->unk_f4;
        } else if (self->unk_da_2 == 2) {
            info.dist += self->unk_f4;
        }
        if (self->base.smooth) {
            VecFx32 out;
            s32 rate = 0x19a;
            if (info.flags.aimYaw) {
                rate <<= 2;
            }
            Approach9b44(&out, &info.pos, &self->base.atTarget, rate);
            self->base.atTarget = out;
            self->base.atRate = 0x733;
            AngTo9b44(self, &info.ang, 0x148, 0, s0, s1, s2);
            DistTo9b44(self, info.dist, 0x19a);
        } else {
            Snap2(self, &info.pos, &info.ang, info.dist);
        }
    }
    self->unk_da = 0;
    self->base.mode = 1;
    Camera_Apply(&self->base);
}

}
