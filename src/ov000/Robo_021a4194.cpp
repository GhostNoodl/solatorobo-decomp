#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 7;
    u32 b17 : 1;
    u32 rest : 14;
} B24_021a4194;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_021a4194;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 2;
    u8 b3 : 1;
    u8 rest : 4;
} B8_021a4194;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} W_021a4194;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021a4194;

extern "C" {
extern void *data_ov000_021ccd68;
extern char *data_ov000_021ca050[];
extern char *data_ov000_021ca040[];
extern char data_ov000_021cc64e[];
extern char data_ov000_021cc654[];
extern char data_ov000_021cc65a[];
extern char data_ov000_021cc660[];
extern char data_ov000_021cc61e[];
u8 *func_ov000_0218e640(void *mgr, u16 id);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL func_01ffc584(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
void func_ov000_021915a0(void *p);
void *func_ov000_02191318(void *a, s32 b);
void func_ov000_02191780(void *a);
BOOL func_ov000_02191120(void *a);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_0218d398(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void func_ov000_02199b88(void *a, void *b);
void func_ov000_0219a210(VecFx32 *pos, const VecFx32 *ofs, s32 angle);
void func_ov000_021bd300(void *p);
void func_ov000_021bd438(void *p, VecFx32 *v, s32 dy);

static inline u8 *FindActor_021a4194(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov000_021a4194(Robo021ca458 *self) {
    u8 *t;
    u8 *info;
    u8 *sub;
    BOOL hit;
    VecFx32 pos;
    VecFx32 o;
    VecFx32 p;
    Pose_021a4194 pose;

    LFLD(u16, self->unk_48, 0x9a) |= 0x20;
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    t = FindActor_021a4194(self->unk_90);
    info = NULL;
    if (t != NULL) {
        info = LFLD(u8 *, t, 0x4c);
    }
    if (info == NULL && LFLD(u16, self->unk_40, 0) < 0x14) {
        func_ov000_02198360(self->unk_40, 1, 0);
        return;
    }
    sub = self->unk_40;
    switch (LFLD(u16, sub, 0)) {
    case 0:
        if (LFLD(u8, info, 0) != 0x12) {
            u16 ang;
            if (t == NULL || t == (u8 *)self) {
                ang = self->unk_7e;
            } else {
                ang = FX_Atan2(LFLD(s32, t, 0x70) - self->unk_70.x, LFLD(s32, t, 0x78) - self->unk_70.z);
            }
            self->unk_98 = ang;
            self->unk_7e = func_01ffc128(self->unk_98, self->unk_7e, 0x400, 1, 0x8000);
            {
                u8 *s;
                pos.x = self->unk_70.x;
                pos.y = self->unk_70.y;
                pos.z = self->unk_70.z;
                pos.y -= 0x1000;
                s = self->unk_40;
                LFLD(u16, s, 2)++;
                if (LFLD(u16, s, 2) < 0x23 &&
                    !func_01ffc584(t + 0x70, &pos, LFLD(s32, t, 0x64) * 2 + 0x1000, 0x3800)) {
                    hit = FALSE;
                    func_ov000_02190cb0(self->unk_38, data_ov000_021ca050[LFLD(B24_021a4194, self, 0xb24).b5], 0x400, 0);
                    func_ov000_021915a0(self->unk_38);
                    self->unk_9c = 0x15c;
                    func_ov000_0218dbe0(self, 0);
                    func_ov000_021987b8(self->unk_48, 0, 0, 0);
                    if (LFLD(B24_021a4194, self, 0xb24).b1 && (LFLD(u32, self->unk_48, 0x54) & 0x400)) {
                        self->unk_98 = FX_Atan2(self->unk_af0 - self->unk_70.x, self->unk_af8 - self->unk_70.z);
                        self->unk_9c = 0x66;
                        self->unk_a4 = 0;
                        if (!LFLD(B24_021a4194, self, 0xb24).b17 || (LFLD(u32, self->unk_48, 0x50) & 0x40000000)) {
                            self->unk_a0 = 0x200;
                        }
                        self->unk_a8 = 0x52;
                        LFLD(B24_021a4194, self, 0xb24).b17 = 1;
                        hit = TRUE;
                    }
                    if (!hit) {
                        return;
                    }
                    func_ov000_02198360(self->unk_40, 4, 0);
                    {
                        u8 *a = FindActor_021a4194(self->unk_b1c);
                        if (a != NULL) {
                            pose.pos = self->unk_70;
                            pose.pos.y += self->unk_6c;
                            pose.rx = LFLD(u16, a, 0x7c);
                            pose.ry = LFLD(u16, a, 0x7e);
                            pose.rz = LFLD(u16, a, 0x80);
                            pose.unk = 0;
                            func_ov000_0218d398(a, self->unk_0c, 7, 1, 0x18, &pose);
                            func_ov000_0218d46c(a, self->unk_0c, 0xa);
                            if (LFLD(u8 *, a, 0x4c) != NULL) {
                                LFLD(B8_021a4194, LFLD(u8 *, a, 0x4c), 0x18).b0 = 0;
                            }
                        }
                    }
                    self->unk_b1c = 0xffff;
                    self->unk_b1e = 0xffff;
                    LFLD(B24_021a4194, self, 0xb24).b5 = 0;
                    LFLD(B24_021a4194, self, 0xb24).b7 = LFLD(B24_021a4194, self, 0xb24).b9;
                    return;
                }
            }
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
        }
        LFLD(u16, self->unk_40, 0)++;
    case 1: {
        char *anim;
        if (self->unk_b1c != 0xffff) {
            if (LFLD(B22_021a4194, self, 0xb22).b3) {
                func_ov000_02190cb0(self->unk_38, data_ov000_021cc64e, 0x555, 0);
                func_ov000_02191318(self->unk_38, 0xa000);
                func_ov000_02191780(self->unk_38);
                LFLD(u16, self->unk_40, 0)++;
                return;
            }
            if (LFLD(B24_021a4194, self, 0xb24).b5 == 2) {
                anim = data_ov000_021cc654;
            } else {
                anim = data_ov000_021cc65a;
            }
        } else {
            if (LFLD(u8, info, 0) == 0x12) {
                LFLD(u16, self->unk_40, 0) = 10;
                return;
            }
            if (!LFLD(B22_021a4194, self, 0xb22).b3) {
                if (LFLD(u8, info, 0) == 0xd) {
                    anim = data_ov000_021cc654;
                } else {
                    anim = LFLD(B24_021a4194, self, 0xb24).b1 ? data_ov000_021cc65a : data_ov000_021cc660;
                }
            } else {
                anim = data_ov000_021cc64e;
            }
        }
        func_ov000_02190cb0(self->unk_38, anim, 0x400, 0);
        LFLD(u16, self->unk_40, 0)++;
        return;
    }
    case 2: {
        s16 f = LFLD(s16, self->unk_38, 0xc4);
        u8 *a;
        if (f == 1 || LFLD(B22_021a4194, self, 0xb22).b3) {
            LFLD(u16, sub, 0) = 10;
            return;
        }
        if (f <= 1) {
            return;
        }
        a = FindActor_021a4194(self->unk_b1c);
        if (a != NULL) {
            if (LFLD(u8, LFLD(u8 *, a, 0x4c), 2) == 7) {
                if (LFLD(void *, a, 0x38) != NULL) {
                    func_ov000_02190cb0(LFLD(void *, a, 0x38), data_ov000_021cc660, 0x1000, 0);
                }
                LFLD(u16, self->unk_40, 2) = LFLD(s16, self->unk_38, 0xc4);
                LFLD(u16, self->unk_40, 0)++;
                return;
            }
        } else if (info != NULL && LFLD(u8, info, 2) == 7) {
            LFLD(u16, self->unk_40, 2) = LFLD(s16, self->unk_38, 0xc4);
            LFLD(u16, self->unk_40, 0)++;
            return;
        }
        LFLD(u16, self->unk_40, 0) = 10;
        return;
    }
    case 3:
        if (LFLD(u16, sub, 2) != 0) {
            LFLD(u16, sub, 2)--;
        }
        if (LFLD(u16, sub, 2) == 0) {
            LFLD(u16, self->unk_40, 0) = 10;
        }
        return;
    case 10:
        if (self->unk_b1c != 0xffff) {
            u8 *a = FindActor_021a4194(self->unk_b1c);
            if (a != NULL) {
                LFLD(u16, a, 0x90) = LFLD(u16, t, 0xc);
                func_ov000_0218d46c(a, self->unk_0c, 6);
            }
        } else {
            func_ov000_0218d46c(t, self->unk_0c, 6);
            LFLD(u16, t, 0x90) = 0xffff;
            func_ov000_02199b88(info, self);
            if (LFLD(u8, info, 2) == 6) {
                LFLD(B8_021a4194, self, 0xb29).b0 = 1;
            }
        }
        LFLD(u16, self->unk_40, 0)++;
        return;
    case 11:
        if (func_ov000_02191120(self->unk_38)) {
            if (LFLD(u8, info, 2) == 6) {
                if (LFLD(s16, t, 0x18) != 3) {
                    if (!LFLD(B24_021a4194, self, 0xb24).b1) {
                        LFLD(B8_021a4194, self, 0x93).b0 = 1;
                    } else {
                        func_ov000_02190cb0(self->unk_38, data_ov000_021cc61e, 0x400, 0);
                        func_ov000_021915a0(self->unk_38);
                    }
                    {
                        p.x = LFLD(s32, t, 0x70);
                        p.y = LFLD(s32, t, 0x74);
                        p.z = LFLD(s32, t, 0x78);
                        o.x = 0;
                        o.y = 0;
                        o.z = -0x800;
                        func_ov000_0219a210(&p, &o, LFLD(u16, t, 0x7e));
                        self->unk_98 = FX_Atan2(p.x - self->unk_70.x, p.z - self->unk_70.z);
                    }
                    self->unk_9c = 0x15c;
                    self->unk_a4 = 0;
                    self->unk_a8 = 0;
                    LFLD(u16, self->unk_40, 0) = 0x14;
                } else {
                    func_ov000_02198360(self->unk_40, 1, 0);
                }
            } else {
                func_ov000_02190cb0(self->unk_38, data_ov000_021ca040[LFLD(B24_021a4194, self, 0xb24).b5], 0xcd, 0);
                func_ov000_021915a0(self->unk_38);
                LFLD(u16, self->unk_40, 0) = 0x32;
            }
            self->unk_90 = 0xffff;
            LFLD(W_021a4194, self->unk_5c, 0).b1 = 0;
            func_ov000_021bd300(self->unk_5c);
            func_ov000_021bd438(self->unk_5c, (VecFx32 *)((u8 *)self + 0x70), 0);
        }
        self->unk_7e = func_01ffc128(self->unk_98, self->unk_7e, 0x400, 1, 0x8000);
        if (LFLD(u8, info, 2) == 6) {
            LFLD(B8_021a4194, self, 0xb29).b0 = 1;
            LFLD(B8_021a4194, self, 0xb29).b3 = 1;
        }
        return;
    case 0x14:
        self->unk_7e = func_01ffc128(self->unk_98, self->unk_7e, 0x400, 1, 0x8000);
        func_ov000_0218dbe0(self, 0);
        LFLD(B8_021a4194, self, 0xb29).b0 = 1;
        LFLD(B8_021a4194, self, 0xb29).b3 = 1;
        return;
    case 0x32:
        if (LFLD(u32, self->unk_48, 0x50) & 0x20000000) {
            self->unk_a0 = 0;
            return;
        }
        self->unk_a8 = 0x52;
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        break;
    }
}
}
