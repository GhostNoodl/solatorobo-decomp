#include "ov008/ov008.h"

extern "C" {

extern Ov008Mgr *data_ov008_021d0500;
extern void *data_02097e4c;
extern void *data_ov000_021ccd54;
extern Ov008Shared data_02fe1534;
extern s32 data_02149efc;
extern Ov008Save *data_02fe152c;
void *func_02049a48(void *a, int b, int c, int d, int e);
void func_ov000_021865f8(void *p);
void func_02062524(void);
void func_ov000_02187b50(void *p);
Ov008Def *Lang_GetGroup(u8 id);
u16 func_020594bc(void *a, int b, int c, int d);
Ov008Item *func_ov000_02154b58(void *a, u32 id);

s32 func_ov008_021cf780(void) {
    return 6;
}

s32 func_ov008_021cf788(void) {
    return 3;
}

BOOL func_ov008_021cf790(void *self, Ov008Sel *sel) {
    Ov008Mgr *m;
    if (sel == NULL) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        m = data_ov008_021d0500;
        if (!m->flags.b4) {
            m->flags.b4 = 1;
            m->unk_11c = 0x2000;
        }
        if (m->menu != NULL) {
            m->menu->flags |= 2;
        }
        if (m->talk != NULL) {
            m->talk->flags |= 2;
        }
        func_ov000_021865f8(data_ov000_021ccd54);
        return FALSE;
    }
    data_ov008_021d0500->sel = sel;
    data_ov008_021d0500->state = 0xb;
    return TRUE;
}

BOOL func_ov008_021cf844(void *self, Ov008Sel *sel) {
    Ov008Mgr *m;
    u16 id;
    if (sel == NULL) {
        return TRUE;
    }
    m = data_ov008_021d0500;
    id = sel->id;
    m->caption->next = id;
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
        data_02fe1534.unk_68 = data_ov008_021d0500->sel->id;
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
void func_ov008_021cf9b8(Ov008Mgr *m, u32 id) {
    Ov008Def *e = Lang_GetGroup(id);
    Ov008Item *p;
    m->menu->v74(e->unk_00, id, 0xffff, 0xffff);
    if (!func_020594bc(data_02fe152c, 0, 0x201, id)) {
        return;
    }
    p = func_ov000_02154b58(m->menu, id);
    if (p != NULL) {
        p->unk_0a = 10;
    }
}
#pragma force_active reset

}
