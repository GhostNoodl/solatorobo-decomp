#include "types.h"
#include "ov000/VObj.h"
#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))
typedef struct Ov008Sel { u8 unk_00[0x6]; u16 id; } Ov008Sel;
typedef struct Ov008Mgr2 {
    u32 flags;
    s32 state;
    u8 unk_08[0xec];
    void *unk_f4;
    u8 unk_f8[0x4];
    VObj *unk_fc;
    VObj *unk_100;
    u8 unk_104[0x4];
    Ov008Sel *unk_108;
    void *unk_10c;
    u16 unk_110;
} Ov008Mgr2;
typedef struct Ov008Shared {
    u8 unk_00[0x44];
    u16 unk_44;
    u8 unk_46[0xc];
    u16 unk_52;
    u8 unk_54[0x14];
    u16 unk_68;
} Ov008Shared;
typedef struct Ov008Entry {
    u8 unk_00[0x6];
    u16 id;
    u8 unk_08[2];
    u16 unk_0a;
    u8 unk_0c[0x20];
    struct Ov008Entry *next;
    u16 unk_30_0 : 1;
    u16 unk_30_1 : 15;
    u16 unk_32;
} Ov008Entry;
typedef struct Ov008Tag { u8 unk_00[0x30]; u16 id; u16 unk_32; u16 unk_34; u16 unk_36; } Ov008Tag;
typedef struct Ov008SaveEnt { u16 unk_00; u16 id; } Ov008SaveEnt;
extern "C" {
extern void *data_ov000_021ccd54;
extern Ov008Shared data_02fe1534;
extern void *data_02fe152c;
void *func_0206e7d0(u8 id);
BOOL func_020594bc(void *a, int b, int c, int d);
void *func_ov000_02154b58(void *a, u32 id);
BOOL func_ov008_021cf790(void *self, Ov008Sel *sel);
BOOL func_ov008_021cf844(void *self, Ov008Sel *sel);
extern void *data_02149ef8;
extern void *data_ov000_021cac60;
extern void *data_ov000_021caec8;
extern void *data_ov008_021d0368;
extern char *data_0208cb7c;
extern char data_0214b105[];
extern u8 *data_0214a424;
void *func_0203dd9c(u32 size);
s32 func_0204c0e8(void *p, s32 id);
BOOL func_020624d8(void);
void func_ov000_021547e8(void *a, void *b, void *c, int d);
Ov008SaveEnt *func_0205976c(void *res, u32 idx);
u32 func_0205975c(void *res, u32 idx);
u16 func_02059544(void *res, void *block, Ov008SaveEnt *entries, int packed, u32 id);
u8 *func_ov000_021824d0(void *p, s32 a);
void func_ov000_02153f90(Ov008Tag *t);
void func_ov000_02153fd8(Ov008Tag *t);
void func_ov000_0214c01c(u8 a);
u32 func_ov000_0214bf2c(u16 id);
const char *func_ov000_0214c064(u16 id);
void func_0204c6bc(const char *str, s32 maxLines, void *arg, void (*cb)(void *arg, s32 *tag));
void func_ov000_0214dc20(void *arg, s32 *tag);
BOOL func_ov008_021cf5c8(void *self, Ov008Sel *sel);
static inline void Ov008_AddEntry(Ov008Mgr2 *m, u32 id) {
    void *e = func_0206e7d0(id);
    void *p;
    m->unk_100->vfunc_74(*(void **)e, id, 0xffff, 0xffff);
    if (!func_020594bc(data_02fe152c, 0, 0x201, id)) {
        return;
    }
    p = func_ov000_02154b58(m->unk_100, id);
    if (p != NULL) {
        FLD(u16, p, 0xa) = 10;
    }
}
static inline BOOL Ov008Entry_Flag(Ov008Entry *e) {
    return e->unk_30_0 ? TRUE : FALSE;
}

static inline BOOL Ov008Entry_IsSet(Ov008Entry *e) {
    return Ov008Entry_Flag(e) ? TRUE : FALSE;
}

// Whether a save entry counts as already known: hidden entries (flag 0x20) are new, others
// take the save's 0x301 bit, and the entry under the cursor is always known.
typedef enum Ov008EntState {
    OV008_ENT_NEW = 0,
    OV008_ENT_KNOWN = 1
} Ov008EntState;

void func_ov008_021cfa38(Ov008Mgr2 *m) {
    u16 i;
    VObj *p;
    void *res;
    Ov008Entry *it;
    u8 *base;
    u32 cnt;
    u8 *cur;
    u32 flags;
    Ov008EntState ok;
    Ov008Tag tag;
    Ov008Entry *e;
    Ov008SaveEnt *ents;
    res = data_02149ef8;
    p = (VObj *)func_0203dd9c(0xd4);
    if (p != NULL) {
        FLD(void *, p, 0) = &data_ov000_021cac60;
        p->vfunc_28();
        FLD(void *, p, 0) = &data_ov000_021caec8;
        p->vfunc_28();
        FLD(void *, p, 0) = &data_ov008_021d0368;
    }
    m->unk_100 = p;
    m->unk_100->vfunc_10(func_0204c0e8(res, 0x96));
    m->unk_100->vfunc_14(func_0204c0e8(res, 0x97));
    FLD(void *, m->unk_100, 0x8) = m;
    FLD(s32, m->unk_100, 0x24) = 0x7a;
    FLD(s32, m->unk_100, 0x20) = 5;
    {
        u8 *q = (u8 *)m->unk_100;
        FLD(s16, q, 0x64) = 0;
        FLD(s16, q, 0x66) = 0x14;
        FLD(s16, q, 0x68) = -0x1000;
    }
    FLD(void *, m->unk_100, 0x80) = (void *)func_ov008_021cf5c8;
    FLD(void *, m->unk_100, 0x84) = (void *)func_ov008_021cf790;
    FLD(void *, m->unk_100, 0x88) = (void *)func_ov008_021cf844;
    data_02fe1534.unk_44 = 1;
    m->unk_fc->vfunc_38(1);
    data_02fe1534.unk_44 = 0;
    m->unk_110 = data_02fe1534.unk_68;
    if (FLD(s16, m->unk_100, 0x9c) == 0) {
        Ov008_AddEntry(m, 0);
    }
    if (func_020624d8()) {
        VObj *u = m->unk_100;
        u->vfunc_a8(func_ov000_02154b58(u, data_02fe1534.unk_52));
    } else {
        VObj *u = m->unk_100;
        for (it = FLD(Ov008Entry *, u, 0x98); it != NULL; it = it->next) {
            if (it->unk_0a == 10) {
                u->vfunc_a8(func_ov000_02154b58(u, it->id));
                break;
            }
        }
        if (it != NULL) {
            m->unk_100->vfunc_a8(it);
        } else {
            m->unk_100->vfunc_a8(FLD(Ov008Entry *, m->unk_100, 0x98));
        }
    }
    m->unk_100->vfunc_08();
    func_ov000_021547e8(m->unk_100, data_0214b105, data_0208cb7c, 10);
    base = FLD(u8 *, data_02fe152c, 0x4c);
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
        if (cur != NULL && FLD(u16, cur, 0xc6) == ents[i].id) {
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
                    e = (Ov008Entry *)func_ov000_02154b58(m->unk_100, tag.id);
                    if (e != NULL) {
                        e->unk_32++;
                        if (!Ov008Entry_IsSet(e)) {
                            if (func_02059544(data_02fe152c, base + 0x30, ents, 0x101, i) == 1 && e->unk_0a == 0xffff) {
                                e->unk_30_0 = 1;
                            }
                        }
                        if (tag.unk_36 != 0) {
                            FLD(u16, e, 0x30) |= (u16)(2 << (tag.unk_36 - 1));
                        }
                    }
                }
            }
        }
    }
    func_ov000_02153fd8(&tag);
}
}
