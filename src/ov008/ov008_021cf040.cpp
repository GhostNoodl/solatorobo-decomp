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

static inline void *Ov008_GetTexIdx(Ov008SprRes *res, Ov008SprAnim *anim, int idx) {
    if (anim != NULL && anim->unk_04 != NULL) {
        return anim->unk_04->unk_30;
    }
    return NNS_G2dGetCellDataByIdx(res->unk_04, **NNS_G2dGetAnimSequenceByIdx(res->unk_0c, idx)->unk_0c);
}

static inline void Ov008_DrawModelIdx(Ov008Sprite *m, int idx) {
    Ov008SprRes *res = m->unk_28;
    if (res != NULL) {
        Ov008SprAnim *anim = idx >= m->unk_80 ? NULL : &m->unk_78[idx];
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

static inline void Ov008_SetXY(Ov008Sprite *o, s32 x, s32 y) {
    o->unk_fc = x;
    o->unk_100 = y;
}

extern "C" {

extern Ov008Sys *data_02097d48;
extern const Ov008Tbl5 data_ov008_021d02e8;
BOOL func_02054f10(void *a, int b);
u8 func_02043d48(void *p);
Ov008Item *func_ov000_02154b58(void *a, u32 id);
void func_02041c20(void *a, int b, int c);

// One local holds first the sprite unk_e0 and then the panel unk_f8. Two typed locals
// (or a typed alias) change the register allocation, so it stays void * with casts.
void func_ov008_021cf040(Ov008Mgr *m) {
    void *p;
    Ov008Item *item;
    Ov008Vec3 v;
    s32 x;
    s32 y;
    s32 i;
    p = m->unk_e0;
    if (p != NULL) {
        Ov008_DrawModelIdx((Ov008Sprite *)p, 0);
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
                    ((Ov008Panel *)p)->unk_50->attr.pid = func_02043d48(&data_02097d48->unk_8b0);
                    ((Ov008Panel *)p)->unk_50->attr.alpha = (u8)a;
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
    m->unk_e8->unk_85 = (u8)(m->unk_e8->unk_85 & 0xfe) | 1;
    m->unk_e8->flags &= ~0x80000;
    m->unk_e8->flags &= ~0x200000;
    m->unk_e8->flags &= ~0x100000;
    m->unk_e8->unk_150 = -0x2000;
    Ov008_DrawModelIdx(m->unk_e8, 1);
    m->unk_e8->unk_150 = -0x1fc0;
    Ov008_DrawModelIdx(m->unk_e8, 2);
    m->unk_e8->unk_85 &= 0xfe;
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
                Ov008Sprite *e = m->unk_ec;
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
    Ov008Sprite *m;
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
        m->attr.b19 = 1;
        m->attr.b20 = 0;
        scroll = list->unk_d0 >> 12;
        m->unk_150 = info->z - 0xa0;
        sx = info->x + pos->unk_44 - 0x78 - scroll;
        sy = info->y + (pos->unk_48 >> 1) - 0x60;
        m->unk_fc = sx << 12;
        m->unk_100 = sy << 12;
        m->attr.pid = (u8)info->pid;
        m->attr.alpha = 0x1e;
        m->attr.b21 = 1;
        m->unk_85 = (u8)(m->unk_85 & 0xfe) | 1;
        Ov008_DrawModelIdx(m, 3);
        m->unk_85 &= 0xfe;
        break;
    }
}

}
