#include "ov008/ov008.h"

struct Ov008MgrFlags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 rest : 27;
};

struct Ov008Sel {
    u8 unk_00[0x6];
    u16 id;
};

struct Ov008Mgr2 {
    Ov008MgrFlags flags;
    s32 state;
    u8 unk_08[0xec];
    void *unk_f4;
    u8 unk_f8[0x4];
    Ov008V *unk_fc;
    Ov008V *unk_100;
    u8 unk_104[0x4];
    Ov008Sel *unk_108;
    void *unk_10c;
    u16 unk_110;
    u16 unk_112;
    u8 unk_114[0x8];
    s32 unk_11c;
};

struct Ov008Shared {
    u8 unk_00[0x44];
    u16 unk_44;
    u8 unk_46[0x22];
    u16 unk_68;
};

extern "C" {

extern Ov008Mgr2 *data_ov008_021d0500;
extern void *data_02097e4c;
extern void *data_ov000_021ccd54;
extern Ov008Shared data_02fe1534;
extern s32 data_02149efc;
extern void *data_02fe152c;
void *func_02049a48(void *a, int b, int c, int d, int e);
void func_ov000_021865f8(void *p);
void func_02062524(void);
void func_ov000_02187b50(void *p);
void *func_0206e7d0(u8 id);
u16 func_020594bc(void *a, int b, int c, int d);
void *func_ov000_02154b58(void *a, u32 id);

s32 func_ov008_021cf780(void) {
    return 6;
}

s32 func_ov008_021cf788(void) {
    return 3;
}

BOOL func_ov008_021cf790(void *self, Ov008Sel *sel) {
    Ov008Mgr2 *m;
    if (sel == NULL) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        m = data_ov008_021d0500;
        if (!m->flags.b4) {
            m->flags.b4 = 1;
            m->unk_11c = 0x2000;
        }
        if (m->unk_100 != NULL) {
            FLD(u32, m->unk_100, 0xc) |= 2;
        }
        if (m->unk_10c != NULL) {
            FLD(u32, m->unk_10c, 0xc) |= 2;
        }
        func_ov000_021865f8(data_ov000_021ccd54);
        return FALSE;
    }
    data_ov008_021d0500->unk_108 = sel;
    data_ov008_021d0500->state = 0xb;
    return TRUE;
}

BOOL func_ov008_021cf844(void *self, Ov008Sel *sel) {
    Ov008Mgr2 *m;
    u16 id;
    if (sel == NULL) {
        return TRUE;
    }
    m = data_ov008_021d0500;
    id = sel->id;
    FLD(u16, m->unk_f4, 0x50) = id;
    m->unk_112 = id;
    return TRUE;
}

BOOL func_ov008_021cf878(void *self, Ov008Sel *sel) {
    u16 id;
    if (sel == NULL) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        return FALSE;
    }
    id = sel->id;
    if (id == 0) {
        BOOL b;
        data_02fe1534.unk_44 = 2;
        data_02fe1534.unk_68 = data_ov008_021d0500->unk_108->id;
        data_ov008_021d0500->unk_fc->v38(1);
        data_02fe1534.unk_44 = 0;
        data_02fe1534.unk_68 = 0;
        b = TRUE;
        if (data_02149efc == 0) {
            b = FALSE;
        }
        if (b) {
            func_02062524();
            func_ov000_02187b50(data_ov000_021ccd54);
            data_ov008_021d0500->flags.b1 = 1;
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        } else {
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        }
        return FALSE;
    }
    if (id != 1) {
        return TRUE;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    return FALSE;
}

#pragma force_active on
void func_ov008_021cf9b8(Ov008Mgr2 *m, u32 id) {
    void *e = func_0206e7d0(id);
    void *p;
    m->unk_100->v74(*(void **)e, id, 0xffff, 0xffff);
    if (!func_020594bc(data_02fe152c, 0, 0x201, id)) {
        return;
    }
    p = func_ov000_02154b58(m->unk_100, id);
    if (p != NULL) {
        FLD(u16, p, 0xa) = 10;
    }
}
#pragma force_active reset

}
