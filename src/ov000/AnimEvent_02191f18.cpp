#include "ov000/Vec.h"
#include "ov000/VObj.h"

typedef struct {
    s32 frame;
    s32 ratio;
    void *res;
    u8 unk_0c[0x74];
} AnmObj;

typedef struct {
    AnmObj *cur;
    AnmObj *prev;
    AnmObj obj_a;
    AnmObj obj_b;
    char name[0x8];
    u8 index;
    u8 playing : 1;
    u8 same : 1;
    u8 loop : 1;
    u8 paused : 1;
    u8 reverse : 1;
    u8 flags_5 : 3;
    s16 speed;
    s16 blend;
    u16 delay;
} AnimCtrl;

typedef struct {
    void *unk_00;
} ResHandle;

typedef struct {
    void *list[5];
} AnimList;

typedef struct {
    u8 unk_00[0xc];
    ResHandle *mdl_handle;
    char mdl_name[0x20];
    char mdl_ext[0x18];
    AnimList *anims;
} ResSet;

typedef struct {
    char name[0x8];
    s32 value;
} AnimEventEntry;

typedef struct {
    u16 count;
    u16 is_ptr;
    AnimEventEntry entries[1];
} AnimEventTable;

typedef struct {
    ResSet *res;
    void *mdl;
    void *tex;
    AnimCtrl *unk_0c;
    AnimCtrl *unk_10;
    AnimCtrl *unk_14;
    AnimCtrl *unk_18;
    AnimCtrl *unk_1c;
    ResSet *unk_20;
    u8 unk_24[0x54];
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    u8 unk_84[0x24];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u16 unk_b4;
    u8 unk_b6[0x4];
    u16 unk_ba;
    u16 unk_bc;
    u8 unk_be;
    u8 unk_bf;
    u8 unk_c0;
    u8 unk_c1;
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 1;
    u16 unk_c2_2 : 2;
    u16 unk_c2_4 : 1;
    u16 unk_c2_5 : 1;
    u16 unk_c2_6 : 1;
    u16 unk_c2_7 : 1;
    u16 unk_c2_8 : 1;
    u16 unk_c2_9 : 2;
    u16 unk_c2_11 : 5;
    u16 unk_c4;
    u16 unk_c6;
    u16 unk_c8;
    u16 unk_ca;
    s16 unk_cc;
    u16 unk_ce;
    AnimEventTable *unk_d0;
    s16 *unk_d4;
    s16 *unk_d8;
    s16 *unk_dc;
    void *unk_e0;
    u32 unk_e4;
} Model0218fe1c;


typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Rot_02191f18;

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_02049f44(void *a, s32 b, void *c, s32 d);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_02040498(s32 n);
s16 *func_ov000_0219122c(Model0218fe1c *self, s32 frame);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 mask, VecFx32 *ofs, void *rot, s32 r, s32 rr, s32 h, s32 i);
BOOL func_ov000_0219aca8(void *a, void *b, u16 c, u8 d, VecFx32 *ofs, u16 *box, s32 r, s32 hgt, s32 h, s32 i);
void func_ov000_0219a210(VecFx32 *pos, const VecFx32 *ofs, s32 angle);
VObj *func_02065f88(s32 id, VecFx32 *pos);
void func_ov000_0218996c(s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
u16 func_0204bfa8(void *cam);

static inline u8 *FindActor_02191f18(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void SetOfs_02191f18(u8 *a, s32 w, s32 x, s32 y, s32 z) {
    LFLD(s32, a, 0x9c) = w;
    LFLD(s32, a, 0xa0) = x;
    LFLD(s32, a, 0xa4) = y;
    LFLD(s32, a, 0xa8) = z;
}

static inline u16 CamYaw_02191f18(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return func_0204bfa8(cam);
}

static inline s32 AnimFrame_02191f18(AnimCtrl *a) {
    return a->cur != NULL ? a->cur->frame : 0;
}

s16 *func_ov000_02191f18(s16 *p, Model0218fe1c *m) {
    u16 f;
    AnimCtrl *a;
    s32 prev;
    s32 op = *p++;
    u8 *actor = FindActor_02191f18(m->unk_b4);

    switch (op) {
    case 0:
        m->unk_c4 = *p++;
        break;
    case 2:
        actor = NULL;
    case 25:
        if (actor != NULL) {
            VecFx32 v;
            v.x = LFLD(s32, actor, 0x70);
            v.y = LFLD(s32, actor, 0x74);
            v.z = LFLD(s32, actor, 0x78);
            func_02049f44(data_02097e4c, (u16)p[0], &v, 0);
        } else {
            func_02049a48(data_02097e4c, (u16)p[0], -1, -1, -1);
        }
        p += 1;
        break;
    case 3:
        actor = NULL;
    case 26: {
        u16 n = p[1];
        u16 id = p[0];
        if (n != 0) {
            id += (u16)func_02040498(n - 1);
        }
        if (actor != NULL) {
            VecFx32 v;
            v.x = LFLD(s32, actor, 0x70);
            v.y = LFLD(s32, actor, 0x74);
            v.z = LFLD(s32, actor, 0x78);
            func_02049f44(data_02097e4c, id, &v, 0);
        } else {
            func_02049a48(data_02097e4c, id, -1, -1, -1);
        }
        p += 2;
        break;
    }
    case 4: {
        s16 v = p[0];
        if (m->unk_0c != NULL) {
            m->unk_0c->speed = v;
        }
        if (m->unk_10 != NULL) {
            m->unk_10->speed = v;
        }
        if (m->unk_14 != NULL) {
            m->unk_14->speed = v;
        }
        if (m->unk_18 != NULL && !m->unk_c2_6) {
            m->unk_18->speed = v;
        }
        if (m->unk_1c != NULL) {
            m->unk_1c->speed = v;
        }
        p += 1;
        break;
    }
    case 5: {
        a = m->unk_0c;
        f = p[0];
        prev = 0;
        if (a != NULL && a->cur != NULL) {
            prev = a->cur->frame;
        }
        p = func_ov000_0219122c(m, f << 12);
        if (a != NULL && prev >= AnimFrame_02191f18(a)) {
            m->unk_e4 |= 0x20000000;
        }
        break;
    }
    case 6: {
        u16 d = (u8)(u16)p[0];
        if (m->unk_0c != NULL && m->unk_0c->delay < d) {
            m->unk_0c->delay = d;
        }
        if (m->unk_10 != NULL && m->unk_10->delay < d) {
            m->unk_10->delay = d;
        }
        if (m->unk_14 != NULL && m->unk_14->delay < d) {
            m->unk_14->delay = d;
        }
        if (m->unk_18 != NULL && !m->unk_c2_6 && m->unk_18->delay < d) {
            m->unk_18->delay = d;
        }
        if (m->unk_1c != NULL && m->unk_1c->delay < d) {
            m->unk_1c->delay = d;
        }
        p += 1;
        break;
    }
    case 7:
        if (actor != NULL) {
            LFLD(u16, actor, 0x98) = (u16)p[0] + LFLD(u16, actor, 0x7e);
            SetOfs_02191f18(actor, p[1] << 4, p[2] << 4, p[3] << 4, p[4] << 4);
        }
        p += 5;
        break;
    case 23:
        if (actor != NULL) {
            LFLD(u16, actor, 0x98) = (u16)p[0] + CamYaw_02191f18(data_ov000_021ccd54 + 0xf4);
            SetOfs_02191f18(actor, p[1] << 4, p[2] << 4, p[3] << 4, p[4] << 4);
        }
        p += 5;
        break;
    case 8:
        if (actor != NULL && (LFLD(u16 *, actor, 0x50) == NULL || *LFLD(u16 *, actor, 0x50) != 0)) {
            VecFx32 v;
            s32 h;
            BOOL k;
            s32 sc;
            u16 c;
            v.x = p[1] << 4;
            v.y = p[2] << 4;
            v.z = p[3] << 4;
            h = m->unk_cc;
            sc = (s16)m->unk_ce;
            if (h < 0) {
                h = 0x64;
            }
            k = FALSE;
            c = p[5];
            if (sc != 0 && sc != 0x1000) {
                k = TRUE;
            }
            c = k ? (u16)(((s64)c * sc + 0x800) >> 12) : c;
            if (func_ov000_0219aca8(actor, actor, c, (u16)p[0] & 0xff, &v, NULL, p[4] << 4, 0, h, 0x1000)) {
                m->unk_e4 |= 0x8000000;
            }
        }
        p += 6;
        break;
    case 9:
        if (actor != NULL && (LFLD(u16 *, actor, 0x50) == NULL || *LFLD(u16 *, actor, 0x50) != 0)) {
            VecFx32 v;
            s32 h;
            BOOL k;
            s32 sc;
            u16 c;
            v.x = p[1] << 4;
            v.y = p[2] << 4;
            v.z = p[3] << 4;
            h = m->unk_cc;
            sc = (s16)m->unk_ce;
            if (h < 0) {
                h = 0x64;
            }
            k = FALSE;
            c = p[6];
            if (sc != 0 && sc != 0x1000) {
                k = TRUE;
            }
            c = k ? (u16)(((s64)c * sc + 0x800) >> 12) : c;
            if (func_ov000_0219aca8(actor, actor, c, (u16)p[0] & 0xff, &v, NULL, p[4] << 4, p[5] << 4, h, 0x1000)) {
                m->unk_e4 |= 0x8000000;
            }
        }
        p += 7;
        break;
    case 10:
        if (actor != NULL && (LFLD(u16 *, actor, 0x50) == NULL || *LFLD(u16 *, actor, 0x50) != 0)) {
            VecFx32 v;
            s32 h;
            BOOL k;
            s32 sc;
            u16 c;
            v.x = p[1] << 4;
            v.y = p[2] << 4;
            v.z = p[3] << 4;
            h = m->unk_cc;
            sc = (s16)m->unk_ce;
            if (h < 0) {
                h = 0x64;
            }
            k = FALSE;
            c = p[9];
            if (sc != 0 && sc != 0x1000) {
                k = TRUE;
            }
            c = k ? (u16)(((s64)c * sc + 0x800) >> 12) : c;
            if (func_ov000_0219aca8(actor, actor, c, (u16)p[0] & 0xff, &v, (u16 *)(p + 4), p[7] << 4, p[8] << 4, h, 0x1000)) {
                m->unk_e4 |= 0x8000000;
            }
        }
        p += 10;
        break;
    case 11:
        if (actor != NULL && (LFLD(u16 *, actor, 0x50) == NULL || *LFLD(u16 *, actor, 0x50) != 0)) {
            s32 mask = LFLD(u16 *, actor, 0x50) != NULL ? LFLD(u16 *, actor, 0x50)[6] : 0;
            VecFx32 v;
            s32 h;
            BOOL k;
            s32 sc;
            u16 c;
            v.x = p[1] << 4;
            v.y = p[2] << 4;
            v.z = p[3] << 4;
            h = m->unk_cc;
            sc = (s16)m->unk_ce;
            if (h < 0) {
                h = 0x64;
            }
            k = FALSE;
            c = p[5];
            if (sc != 0 && sc != 0x1000) {
                k = TRUE;
            }
            c = k ? (u16)(((s64)c * sc + 0x800) >> 12) : c;
            if (func_ov000_0219aae8(actor, actor, c, (u16)p[0] & 0xff, mask, &v, NULL, p[4] << 4, 0, h, 0x1000)) {
                m->unk_e4 |= 0x8000000;
            }
        }
        p += 6;
        break;
    case 12:
        if (actor != NULL && (LFLD(u16 *, actor, 0x50) == NULL || *LFLD(u16 *, actor, 0x50) != 0)) {
            s32 mask = LFLD(u16 *, actor, 0x50) != NULL ? LFLD(u16 *, actor, 0x50)[6] : 0;
            VecFx32 v;
            s32 h;
            BOOL k;
            s32 sc;
            u16 c;
            v.x = p[1] << 4;
            v.y = p[2] << 4;
            v.z = p[3] << 4;
            h = m->unk_cc;
            sc = (s16)m->unk_ce;
            if (h < 0) {
                h = 0x64;
            }
            k = FALSE;
            c = p[6];
            if (sc != 0 && sc != 0x1000) {
                k = TRUE;
            }
            c = k ? (u16)(((s64)c * sc + 0x800) >> 12) : c;
            if (func_ov000_0219aae8(actor, actor, c, (u16)p[0] & 0xff, mask, &v, NULL, p[4] << 4, p[5] << 4, h, 0x1000)) {
                m->unk_e4 |= 0x8000000;
            }
        }
        p += 7;
        break;
    case 13:
        if (actor != NULL && (LFLD(u16 *, actor, 0x50) == NULL || *LFLD(u16 *, actor, 0x50) != 0)) {
            s32 mask = LFLD(u16 *, actor, 0x50) != NULL ? LFLD(u16 *, actor, 0x50)[6] : 0;
            VecFx32 v;
            s32 h;
            BOOL k;
            s32 sc;
            u16 c;
            v.x = p[1] << 4;
            v.y = p[2] << 4;
            v.z = p[3] << 4;
            h = m->unk_cc;
            sc = (s16)m->unk_ce;
            if (h < 0) {
                h = 0x64;
            }
            k = FALSE;
            c = p[9];
            if (sc != 0 && sc != 0x1000) {
                k = TRUE;
            }
            c = k ? (u16)(((s64)c * sc + 0x800) >> 12) : c;
            if (func_ov000_0219aae8(actor, actor, c, (u16)p[0] & 0xff, mask, &v, p + 4, p[7] << 4, p[8] << 4, h, 0x1000)) {
                m->unk_e4 |= 0x8000000;
            }
        }
        p += 10;
        break;
    case 14:
    case 17:
        p += 7;
        break;
    case 15:
    case 18:
        p += 8;
        break;
    case 16:
    case 19:
        p += 11;
        break;
    case 20:
        if (actor != NULL) {
            VecFx32 pos;
            VecFx32 ofs;
            VecFx32 sc;
            Rot_02191f18 r;
            VObj *e;
            ofs.x = p[1] << 4;
            ofs.y = p[2] << 4;
            ofs.z = p[3] << 4;
            pos.x = LFLD(s32, actor, 0x70);
            pos.y = LFLD(s32, actor, 0x74);
            pos.z = LFLD(s32, actor, 0x78);
            func_ov000_0219a210(&pos, &ofs, LFLD(u16, actor, 0x7e));
            e = func_02065f88(p[0], &pos);
            r = LFLD(Rot_02191f18, actor, 0x7c);
            r.x += p[4];
            r.y += p[5];
            r.z += p[6];
            e->vfunc_30(&r);
            sc.x = p[7] << 4;
            sc.y = p[8] << 4;
            sc.z = p[9] << 4;
            e->vfunc_10(&sc);
        }
        p += 10;
        break;
    case 21:
        func_ov000_0218996c((u16)p[0] & 0xff, (u16)p[1] & 0xff);
        p += 2;
        break;
    case 22:
        m->unk_c6 = p[0];
        m->unk_c8 = p[1];
        m->unk_ca = p[2];
        p += 3;
        break;
    case 24:
        if (actor != NULL) {
            func_020627a0(LFLD(u16, actor, 0xe), LFLD(u16, actor, 0xc));
            func_020627dc(5);
            LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
        }
        break;
    }
    m->unk_e4 |= 1 << op;
    return p;
}
}
