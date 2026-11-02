#include "ov008/ov008.h"
typedef struct Ov008Tag { u8 unk_00[0x30]; u16 id; u16 unk_32; u16 unk_34; u16 unk_36; } Ov008Tag;
typedef struct Ov008SaveEnt { u16 unk_00; u16 id; } Ov008SaveEnt;
extern "C" {
extern void *data_ov000_021ccd54;
extern Ov008Shared data_02fe1534;
extern Ov008Save *data_02fe152c;
Ov008Def *func_0206e7d0(u8 id);
u16 func_020594bc(void *a, int b, int c, int d);
Ov008Item *func_ov000_02154b58(void *a, u32 id);
BOOL func_ov008_021cf790(void *self, Ov008Sel *sel);
BOOL func_ov008_021cf844(void *self, Ov008Sel *sel);
extern void *data_02149ef8;
extern void *data_ov000_021cac60;
extern void *data_ov000_021caec8;
extern void *data_ov008_021d0368;
extern char *data_0208cb7c;
extern char data_0214b105[];
extern u8 *data_0214a424;
s32 MsgRes_GetString(void *p, s32 id);
BOOL func_020624d8(void);
void func_ov000_021547e8(void *a, void *b, void *c, int d);
Ov008SaveEnt *func_0205976c(void *res, u32 idx);
u32 func_0205975c(void *res, u32 idx);
u16 func_02059544(void *res, void *block, Ov008SaveEnt *entries, int packed, u32 id);
Ov008Chr *func_ov000_021824d0(void *p, s32 a);
void func_ov000_02153f90(Ov008Tag *t);
void func_ov000_02153fd8(Ov008Tag *t);
u32 func_ov000_0214c01c(u8 a);
u32 func_ov000_0214bf2c(u16 id);
const char *func_ov000_0214c064(u16 id);
void func_0204c6bc(const char *str, s32 maxLines, void *arg, void (*cb)(void *arg, s32 *tag));
void func_ov000_0214dc20(void *arg, s32 *tag);
void func_ov008_021cf5c8(s32 type, void *list, void *info);
static inline void Ov008_AddEntry(Ov008Mgr *m, u32 id) {
    Ov008Def *e = func_0206e7d0(id);
    Ov008Item *p;
    m->unk_100->v74(e->unk_00, id, 0xffff, 0xffff);
    if (!func_020594bc(data_02fe152c, 0, 0x201, id)) {
        return;
    }
    p = func_ov000_02154b58(m->unk_100, id);
    if (p != NULL) {
        p->unk_0a = 10;
    }
}
static inline BOOL Ov008Entry_Flag(Ov008Item *e) {
    return e->flags.b0 ? TRUE : FALSE;
}

static inline BOOL Ov008Entry_IsSet(Ov008Item *e) {
    return Ov008Entry_Flag(e) ? TRUE : FALSE;
}

// Whether a save entry counts as already known: hidden entries (flag 0x20) are new, others
// take the save's 0x301 bit, and the entry under the cursor is always known.
typedef enum Ov008EntState {
    OV008_ENT_NEW = 0,
    OV008_ENT_KNOWN = 1
} Ov008EntState;

void func_ov008_021cfa38(Ov008Mgr *m) {
    u16 i;
    Ov008Menu *p;
    void *res;
    Ov008Item *it;
    u8 *base;
    u32 cnt;
    Ov008Chr *cur;
    u32 flags;
    Ov008EntState ok;
    Ov008Tag tag;
    Ov008Item *e;
    Ov008SaveEnt *ents;
    res = data_02149ef8;
    p = (Ov008Menu *)Heap_Alloc(0xd4);
    if (p != NULL) {
        OV008_SET_VT(p, &data_ov000_021cac60);
        p->v28();
        OV008_SET_VT(p, &data_ov000_021caec8);
        p->v28();
        OV008_SET_VT(p, &data_ov008_021d0368);
    }
    m->unk_100 = p;
    m->unk_100->v10(MsgRes_GetString(res, 0x96));
    m->unk_100->v14(MsgRes_GetString(res, 0x97));
    m->unk_100->unk_08 = m;
    m->unk_100->unk_24 = 0x7a;
    m->unk_100->unk_20 = 5;
    {
        Ov008Menu *q = m->unk_100;
        q->unk_64 = 0;
        q->unk_66 = 0x14;
        q->unk_68 = -0x1000;
    }
    m->unk_100->unk_80 = (Ov008Cb)func_ov008_021cf5c8;
    m->unk_100->unk_84 = (Ov008Cb)func_ov008_021cf790;
    m->unk_100->unk_88 = (Ov008Cb)func_ov008_021cf844;
    data_02fe1534.unk_44 = 1;
    m->unk_fc->v38(1);
    data_02fe1534.unk_44 = 0;
    m->unk_110 = data_02fe1534.unk_68;
    if (m->unk_100->unk_9c == 0) {
        Ov008_AddEntry(m, 0);
    }
    if (func_020624d8()) {
        Ov008Menu *u = m->unk_100;
        u->va8(func_ov000_02154b58(u, data_02fe1534.unk_52));
    } else {
        Ov008Menu *u = m->unk_100;
        for (it = u->unk_98; it != NULL; it = it->next) {
            if (it->unk_0a == 10) {
                u->va8(func_ov000_02154b58(u, it->id));
                break;
            }
        }
        if (it != NULL) {
            m->unk_100->va8(it);
        } else {
            m->unk_100->va8(m->unk_100->unk_98);
        }
    }
    m->unk_100->v08();
    func_ov000_021547e8(m->unk_100, data_0214b105, data_0208cb7c, 10);
    base = data_02fe152c->unk_4c;
    ents = func_0205976c(data_02fe152c, 1);
    cnt = func_0205975c(data_02fe152c, 1);
    i = 0;
    cur = func_ov000_021824d0((u8 *)data_ov000_021ccd54 + 0xac, 0);
    func_ov000_02153f90(&tag);
    tag.id = 0;
    tag.unk_32 = 0;
    tag.unk_34 = 0;
    tag.unk_36 = 0;
    func_ov000_0214c01c(data_0214a424[0x639]);
    for (; i < cnt; i++) {
        flags = func_ov000_0214bf2c(ents[i].id);
        if (flags & 0x20) {
            ok = OV008_ENT_NEW;
        } else {
            ok = (Ov008EntState)func_02059544(data_02fe152c, base + 0x30, ents, 0x301, i);
        }
        if (cur != NULL && cur->unk_c6 == ents[i].id) {
            ok = OV008_ENT_KNOWN;
        }
        if (func_02059544(data_02fe152c, base + 0x30, ents, 1, i) == 1 && ok == OV008_ENT_NEW) {
            tag.id = 0xffff;
            func_0204c6bc(func_ov000_0214c064(ents[i].id), 1, &tag, func_ov000_0214dc20);
            ok = OV008_ENT_NEW;
            if (tag.id != 0xffff) {
                if (flags & 0x80) {
                    if (func_020594bc(data_02fe152c, 5, 1, 0x29)) {
                        ok = OV008_ENT_KNOWN;
                    }
                }
                if (ok == OV008_ENT_NEW) {
                    e = func_ov000_02154b58(m->unk_100, tag.id);
                    if (e != NULL) {
                        e->unk_32++;
                        if (!Ov008Entry_IsSet(e)) {
                            if (func_02059544(data_02fe152c, base + 0x30, ents, 0x101, i) == 1 && e->unk_0a == 0xffff) {
                                e->flags.b0 = 1;
                            }
                        }
                        if (tag.unk_36 != 0) {
                            e->unk_30 |= (u16)(2 << (tag.unk_36 - 1));
                        }
                    }
                }
            }
        }
    }
    func_ov000_02153fd8(&tag);
}
}
