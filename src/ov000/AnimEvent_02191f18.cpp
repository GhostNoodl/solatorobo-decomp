#include "ov000/FieldCam.h"
#include "ov000/Vec.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorBase.h"
#include "ov000/VObj.h"
#include "ov000/Model0218fe1c.h"
#include "Main/Effect/Effect.h"


#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
Actor *ActorMgr_GetActor(void *mgr, u16 id);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 Rand_UpTo(s32 n);
s16 *func_ov000_0219122c(Model0218fe1c *self, s32 frame);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 mask, VecFx32 *ofs, void *rot, s32 r, s32 rr, s32 h, s32 i);
BOOL func_ov000_0219aca8(void *a, void *b, u16 c, u8 d, VecFx32 *ofs, u16 *box, s32 r, s32 hgt, s32 h, s32 i);
void func_ov000_0219a210(VecFx32 *pos, const VecFx32 *ofs, s32 angle);
void func_ov000_0218996c(s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);

static inline Actor *FindActor_02191f18(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void SetOfs_02191f18(Actor *a, s32 w, s32 x, s32 y, s32 z) {
    a->speed = w;
    a->velY = x;
    a->friction = y;
    a->gravity = z;
}

static inline s32 AnimFrame_02191f18(AnimCtrl *a) {
    return a->cur != NULL ? a->cur->frame : 0;
}

s16 *func_ov000_02191f18(s16 *p, Model0218fe1c *m) {
    u16 f;
    AnimCtrl *a;
    s32 prev;
    s32 op = *p++;
    Actor *actor = FindActor_02191f18(m->actor_id);

    switch (op) {
    case 0:
        m->anim_state = *p++;
        break;
    case 2:
        actor = NULL;
    case 25:
        if (actor != NULL) {
            VecFx32 v;
            v.x = actor->pos.x;
            v.y = actor->pos.y;
            v.z = actor->pos.z;
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
            id += (u16)Rand_UpTo(n - 1);
        }
        if (actor != NULL) {
            VecFx32 v;
            v.x = actor->pos.x;
            v.y = actor->pos.y;
            v.z = actor->pos.z;
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
            actor->moveYaw = (u16)p[0] + actor->rot_y;
            SetOfs_02191f18(actor, p[1] << 4, p[2] << 4, p[3] << 4, p[4] << 4);
        }
        p += 5;
        break;
    case 23:
        if (actor != NULL) {
            actor->moveYaw = (u16)p[0] + FieldCam_GetYaw(&data_ov000_021ccd54->cam);
            SetOfs_02191f18(actor, p[1] << 4, p[2] << 4, p[3] << 4, p[4] << 4);
        }
        p += 5;
        break;
    case 8:
        if (actor != NULL && (actor->hp == NULL || *actor->hp != 0)) {
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
        if (actor != NULL && (actor->hp == NULL || *actor->hp != 0)) {
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
        if (actor != NULL && (actor->hp == NULL || *actor->hp != 0)) {
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
        if (actor != NULL && (actor->hp == NULL || *actor->hp != 0)) {
            s32 mask = actor->hp != NULL ? actor->hp[6] : 0;
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
        if (actor != NULL && (actor->hp == NULL || *actor->hp != 0)) {
            s32 mask = actor->hp != NULL ? actor->hp[6] : 0;
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
        if (actor != NULL && (actor->hp == NULL || *actor->hp != 0)) {
            s32 mask = actor->hp != NULL ? actor->hp[6] : 0;
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
            Rot16 r;
            EffectObj *e;
            ofs.x = p[1] << 4;
            ofs.y = p[2] << 4;
            ofs.z = p[3] << 4;
            pos.x = actor->pos.x;
            pos.y = actor->pos.y;
            pos.z = actor->pos.z;
            func_ov000_0219a210(&pos, &ofs, actor->rot_y);
            e = func_02065f88(p[0], &pos);
            r = actor->rot;
            r.x += p[4];
            r.y += p[5];
            r.z += p[6];
            e->SetRot(&r);
            sc.x = p[7] << 4;
            sc.y = p[8] << 4;
            sc.z = p[9] << 4;
            e->SetScale(&sc);
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
            func_020627a0(actor->kind, actor->id);
            func_020627dc(5);
            data_ov000_021ccd54->stageFlags = 1;
        }
        break;
    }
    m->unk_e4 |= 1 << op;
    return p;
}
}
