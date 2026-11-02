#include "ov008/ov008.h"


struct Ov008DrawBits {
    u8 b0 : 1;
    u8 rest : 7;
};

struct Ov008ListInfo {
    Ov008Item *item;
    s32 x;
    s32 y;
    s32 z;
    u32 pid;
};

static inline void *Ov008_GetTexIdx(ModelRes *res, ModelPart *anim, int idx) {
    if (anim != NULL && anim->res != NULL) {
        return anim->res->tex;
    }
    return NNS_G2dGetCellDataByIdx(res->texRes, **((Ov008SprSeq *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx))->unk_0c);
}

static inline void Ov008_DrawModelIdx(Model *m, int idx) {
    ModelRes *res = m->res;
    if (res != NULL) {
        ModelPart *anim = idx >= m->numParts ? NULL : &m->parts[idx];
        func_02042628(m, Ov008_GetTexIdx(res, anim, idx), anim, 0);
    }
}

static inline BOOL Ov008_ListVisible(Ov008Menu *list, s32 y) {
    BOOL r;
    if (y < list->v34() + list->unk_66 || y > list->unk_66 + list->unk_28 - list->v38() - 0xc) {
        r = FALSE;
    } else {
        r = TRUE;
    }
    return r;
}

static inline BOOL Ov008_ItemOn(Ov008Item *item) {
    return item->flags.b0 ? TRUE : FALSE;
}

struct Ov008Tbl5 {
    s32 v[5];
};

static inline void Ov008_SetXY(Model *o, s32 x, s32 y) {
    o->x = x;
    o->y = y;
}

extern "C" {

extern Ov008Sys *data_02097d48;
extern const Ov008Tbl5 data_ov008_021d02e8;
BOOL func_02054f10(void *a, int b);
u8 Gfx3DState_NextPolyId(void *p);
Ov008Item *func_ov000_02154b58(void *a, u32 id);
void func_02041c20(void *a, int b, int c);

// One local holds first the sprite unk_e0 and then the panel unk_f8. Two typed locals
// (or a typed alias) change the register allocation, so it stays void * with casts.
void func_ov008_021cf040(Ov008Mgr *m) {
    void *p;
    Ov008Item *item;
    VecFx32 v;
    s32 x;
    s32 y;
    s32 i;
    p = m->unk_e0;
    if (p != NULL) {
        Ov008_DrawModelIdx((Model *)p, 0);
    }
    p = m->unk_f8;
    if (p != NULL) {
        switch (((Ov008Panel *)p)->state) {
        case 8:
        case 9:
        case 16:
        case 18:
            if (func_02054f10(((Ov008Panel *)p)->unk_50, 0xffff)) {
                s32 a = (u8)((Ov008Panel *)p)->unk_60;
                s32 px = (((Ov008Panel *)p)->unk_5c + (((Ov008Panel *)p)->unk_54 + 0x3d000)) & ~0xfff;
                if (a > 0) {
                    MODEL_FLAGS(((Ov008Panel *)p)->unk_50)->polygon_id = Gfx3DState_NextPolyId(&data_02097d48->unk_8b0);
                    MODEL_FLAGS(((Ov008Panel *)p)->unk_50)->alpha = (u8)a;
                    Ov008_SetXY(((Ov008Panel *)p)->unk_50, px, -0x1a000);
                    Ov008_DrawModelIdx(((Ov008Panel *)p)->unk_50, 0);
                }
            }
            break;
        }
    }
    if (m->unk_10c == NULL || m->unk_e8 == NULL) {
        return;
    }
    item = NULL;
    if (m->unk_100 != NULL && m->unk_112 != 0xffff) {
        item = func_ov000_02154b58(m->unk_100, m->unk_112);
    }
    v.x = 0;
    v.y = 0;
    v.z = 0;
    m->unk_10c->v18(&v, 0, -1);
    {
        x = v.x;
        y = v.y;
        if (item != NULL) {
            func_02041c20(m->unk_e8, 2, item->unk_32);
        } else {
            func_02041c20(m->unk_e8, 2, 0);
        }
        Ov008_SetXY(m->unk_e8, x, y);
    }
    m->unk_e8->unk_085 = (u8)(m->unk_e8->unk_085 & 0xfe) | 1;
    m->unk_e8->flags &= ~0x80000;
    m->unk_e8->flags &= ~0x200000;
    m->unk_e8->flags &= ~0x100000;
    m->unk_e8->unk_150 = -0x2000;
    Ov008_DrawModelIdx(m->unk_e8, 1);
    m->unk_e8->unk_150 = -0x1fc0;
    Ov008_DrawModelIdx(m->unk_e8, 2);
    m->unk_e8->unk_085 &= 0xfe;
    if (item == NULL || m->unk_f0 == NULL || m->unk_ec == NULL) {
        return;
    }
    {
        Ov008Tbl5 t = data_ov008_021d02e8;
        x = v.x;
        y = v.y;
        m->unk_ec->unk_150 = -0x1fc0;
        m->unk_f0->unk_150 = -0x1fc0;
        for (i = 0; i < 5; i++) {
            if ((item->unk_30 & (u16)(2 << i)) ? TRUE : FALSE) {
                Model *e = m->unk_ec;
                Ov008_SetXY(e, (t.v[i] + (x >> 12) - 3) << 12, ((y >> 12) + 0x2f) << 12);
                Ov008_DrawModelIdx(m->unk_ec, 0xd);
                Ov008_SetXY(m->unk_f0, (t.v[i] + (x >> 12)) << 12, ((y >> 12) + 0x28) << 12);
                func_02041c20(m->unk_f0, 6, i + 1);
                Ov008_DrawModelIdx(m->unk_f0, 6);
            }
        }
    }
}


void func_ov008_021cf5c8(s32 type, Ov008Menu *list, Ov008ListInfo *info) {
    s32 yy;
    s32 sx;
    Ov008Mgr *mgr;
    s32 sy;
    Ov008Item *item;
    Model *m;
    Ov008Win *pos;
    s32 scroll;
    mgr = list->unk_08;
    switch (type) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        item = info->item;
        m = mgr->unk_e8;
        pos = item->unk_1c;
        if (!Ov008_ItemOn(item)) {
            break;
        }
        yy = info->y;
        if (!Ov008_ListVisible(list, yy)) {
            break;
        }
        MODEL_FLAGS(m)->unk_19 = 1;
        MODEL_FLAGS(m)->unk_20 = 0;
        scroll = list->unk_d0 >> 12;
        m->unk_150 = info->z - 0xa0;
        sx = info->x + pos->unk_44 - 0x78 - scroll;
        sy = info->y + (pos->unk_48 >> 1) - 0x60;
        m->x = sx << 12;
        m->y = sy << 12;
        MODEL_FLAGS(m)->polygon_id = (u8)info->pid;
        MODEL_FLAGS(m)->alpha = 0x1e;
        MODEL_FLAGS(m)->unk_21 = 1;
        m->unk_085 = (u8)(m->unk_085 & 0xfe) | 1;
        Ov008_DrawModelIdx(m, 3);
        m->unk_085 &= 0xfe;
        break;
    }
}

}
