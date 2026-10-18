#include "ov008/ov008.h"

struct Ov008Mgr3Flags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 cnt : 8;
    u32 rest : 19;
};

struct Ov008Mgr3 {
    Ov008Mgr3Flags flags;
    s32 state;
    Ov008V sub;
    u8 unk_0c[0xbc];
    void *unk_c8;
    void *unk_cc;
    void *unk_d0;
    void *unk_d4;
    void *unk_d8;
    void *unk_dc;
    void *unk_e0;
    void *unk_e4;
    void *unk_e8;
    void *unk_ec;
    void *unk_f0;
    void *unk_f4;
    void *unk_f8;
    void *unk_fc;
    Ov008V *unk_100;
    Ov008V *unk_104;
    void *unk_108;
    Ov008V *unk_10c;
    u16 unk_110;
    u16 unk_112;
    s32 unk_114;
    s32 unk_118;
    s32 unk_11c;
};


struct Ov008ObjFlags {
    u32 b0 : 2;
    u32 prio : 5;
    u32 pal : 6;
    u32 b13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
};

struct Ov008DrawBits {
    u8 b0 : 1;
    u8 rest : 7;
};

struct Ov008ItemFlags {
    u16 b0 : 1;
    u16 rest : 15;
};

struct Ov008ListInfo {
    void *item;
    s32 x;
    s32 y;
    s32 z;
    u32 pal;
};

static inline void *Ov008_GetTexIdx(void *res, void *anim, int idx) {
    if (anim != NULL && FLD(void *, anim, 0x4) != NULL) {
        return FLD(void *, FLD(void *, anim, 0x4), 0x30);
    }
    return NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), idx), 0xc));
}

static inline void Ov008_DrawModelIdx(void *m, int idx) {
    void *res = FLD(void *, m, 0x28);
    if (res != NULL) {
        void *anim = idx >= FLD(s32, m, 0x80) ? NULL : (u8 *)FLD(void *, m, 0x78) + idx * 0x28;
        func_02042628(m, Ov008_GetTexIdx(res, anim, idx), anim, 0);
    }
}

static inline BOOL Ov008_ListVisible(Ov008V *list, s32 y) {
    BOOL r;
    if (y < list->v34() + FLD(s16, list, 0x66) || y > FLD(s16, list, 0x66) + FLD(s32, list, 0x28) - list->v38() - 0xc) {
        r = FALSE;
    } else {
        r = TRUE;
    }
    return r;
}

static inline BOOL Ov008_ItemOn(void *item) {
    return FLD(Ov008ItemFlags, item, 0x30).b0 ? TRUE : FALSE;
}

struct Ov008Tbl5 {
    s32 v[5];
};

struct Ov008Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

static inline void Ov008_SetXY(void *o, s32 x, s32 y) {
    FLD(s32, o, 0xfc) = x;
    FLD(s32, o, 0x100) = y;
}

extern "C" {

extern u8 *data_02097d48;
extern const Ov008Tbl5 data_ov008_021d02e8;
BOOL func_02054f10(void *a, int b);
s32 func_02043d48(void *p);
void *func_ov000_02154b58(void *a, u32 id);
void func_02041c20(void *a, int b, int c);

void func_ov008_021cf040(Ov008Mgr3 *m) {
    void *p;
    void *item;
    Ov008Vec3 v;
    s32 x;
    s32 y;
    s32 i;
    p = m->unk_e0;
    if (p != NULL) {
        Ov008_DrawModelIdx(p, 0);
    }
    p = m->unk_f8;
    if (p != NULL) {
        switch (FLD(s32, p, 0)) {
        case 8:
        case 9:
        case 16:
        case 18:
            if (func_02054f10(FLD(void *, p, 0x50), 0xffff)) {
                s32 a = (u8)FLD(s32, p, 0x60);
                s32 px = (FLD(s32, p, 0x5c) + (FLD(s32, p, 0x54) + 0x3d000)) & ~0xfff;
                if (a > 0) {
                    FLD(Ov008ObjFlags, FLD(void *, p, 0x50), 0x6c).pal = func_02043d48(data_02097d48 + 0x8b0);
                    FLD(Ov008ObjFlags, FLD(void *, p, 0x50), 0x6c).prio = (u8)a;
                    Ov008_SetXY(FLD(void *, p, 0x50), px, -0x1a000);
                    Ov008_DrawModelIdx(FLD(void *, p, 0x50), 0);
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
            func_02041c20(m->unk_e8, 2, FLD(u16, item, 0x32));
        } else {
            func_02041c20(m->unk_e8, 2, 0);
        }
        Ov008_SetXY(m->unk_e8, x, y);
    }
    FLD(u8, m->unk_e8, 0x85) = (u8)(FLD(u8, m->unk_e8, 0x85) & 0xfe) | 1;
    FLD(u32, m->unk_e8, 0x6c) &= ~0x80000;
    FLD(u32, m->unk_e8, 0x6c) &= ~0x200000;
    FLD(u32, m->unk_e8, 0x6c) &= ~0x100000;
    FLD(s32, m->unk_e8, 0x150) = -0x2000;
    Ov008_DrawModelIdx(m->unk_e8, 1);
    FLD(s32, m->unk_e8, 0x150) = -0x1fc0;
    Ov008_DrawModelIdx(m->unk_e8, 2);
    FLD(u8, m->unk_e8, 0x85) &= 0xfe;
    if (item == NULL || m->unk_f0 == NULL || m->unk_ec == NULL) {
        return;
    }
    {
        Ov008Tbl5 t = data_ov008_021d02e8;
        x = v.x;
        y = v.y;
        FLD(s32, m->unk_ec, 0x150) = -0x1fc0;
        FLD(s32, m->unk_f0, 0x150) = -0x1fc0;
        for (i = 0; i < 5; i++) {
            if ((FLD(u16, item, 0x30) & (u16)(2 << i)) ? TRUE : FALSE) {
                void *e = m->unk_ec;
                Ov008_SetXY(e, (t.v[i] + (x >> 12) - 3) << 12, ((y >> 12) + 0x2f) << 12);
                Ov008_DrawModelIdx(m->unk_ec, 0xd);
                Ov008_SetXY(m->unk_f0, (t.v[i] + (x >> 12)) << 12, ((y >> 12) + 0x28) << 12);
                func_02041c20(m->unk_f0, 6, i + 1);
                Ov008_DrawModelIdx(m->unk_f0, 6);
            }
        }
    }
}



}
