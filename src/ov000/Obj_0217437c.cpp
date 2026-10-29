#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x4c];
    s32 unk_4c;
} Sub021742b4;

typedef struct {
    u8 unk_00[0x6];
    u16 unk_06;
    u8 unk_08[0x1c];
    s32 unk_24;
} Msg021742c8;

typedef struct {
    u32 unk_00;
    s32 unk_04;
    void *unk_08;
} Obj021742b4;

typedef struct {
    u8 unk_00[0x8];
    VObj unk_08;
} Sub02174380;

typedef struct {
    u8 unk_00[0x10];
    Sub02174380 *unk_10;
} Data021ccd34;

extern "C" {

extern void *data_02097e4c;
extern Data021ccd34 data_ov000_021ccd34;

void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov000_0214c270(void);

void func_ov000_0217437c(void) {
}

BOOL func_ov000_02174380(void) {
    BOOL ret = TRUE;
    if (!data_ov000_021ccd34.unk_10->unk_08.vfunc_2c()) {
        ret = FALSE;
    }
    if (!func_ov000_0214c270()) {
        ret = FALSE;
    }
    return ret;
}

}

// func_ov000_021743bc: the item search is written out with the caller's own locals (round bgL); as a
// static inline its objects are numbered below g and every callee-saved register rotates by one.
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Bits021743bc;

struct Glyph02174168;

// Item ids of the +0x40 list; the first item is also the default cursor position.
typedef enum {
    MENU021743BC_ITEM_TOP = 0x1a
} MenuItem021743bc;

class MenuList021743bc {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void Show();
    virtual void vf0c();
    virtual void SetTitleId(s32 id);
    virtual void SetTitle(const char *src);
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void *AddItem(const char *name, u16 id, u16 a, u32 b);
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void Select(void *e);
};

class MenuBox021743bc {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void Show();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void SetText(s32 b, const void *c);
};

extern "C" {
void *func_0203dd9c(u32 size);
void func_ov000_02173648(void *self);
extern void *data_02149ef8;
extern void *data_02fe152c;
extern u8 *data_ov000_021ccd54;
extern u8 *data_02097ce0;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021ca94c[];
extern u8 data_0208ba70[];
extern u8 data_ov000_021c9c28[];
extern void *data_0208ccc8;
extern u8 data_ov000_021cba0c[];
extern void *data_0208cc94;
extern void *data_0208cc88;
extern s32 data_02097d78[];
void *func_0204c0e8(void *g, s32 id);
void *func_ov000_02154b58(void *p, u16 a);
u16 func_020594bc(void *a, u32 b, s32 c, s32 d);
void *func_ov000_021824d0(void *a, u16 b);
void *func_0205976c(void *a, u32 b);
u32 func_0205975c(void *a, u32 b);
u16 func_02059544(void *a, void *b, void *c, s32 d, u16 e);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_02041218(void *a);
void func_02041440(void *p, void *name, u8 c);
char *STD_CopyString(void *dst, void *src);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, u32 b);
void func_02041c5c(void *model, int fn);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, const char *c, s32 *d, s32 *e, bool f);
void func_0204ca70(void *p);
void func_0203cb78(s32 a, s32 b, s32 c);
void func_ov000_021742b4(Obj021742b4 *self);
BOOL func_ov000_021742c8(Obj021742b4 *self, Msg021742c8 *msg);
struct Glyph02174168 *func_ov000_02174168(u8 *self, u16 *cmd, struct Glyph02174168 *arr, u16 *count);

static inline BOOL IsMode4_021743bc(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 4;
    }
    return r;
}

static inline void InitWin021743bc(u8 *p, void *s) {
    ((VObj *)p)->vfunc_08();
    LFLD(void *, p, 0x24) = s;
    LFLD(s32, p, 0x28) = 4;
    LFLD(s32, p, 0x4c) = func_0204c4fc(LFLD(s32, p, 0x28), LFLD(s32, p, 0x38), LFLD(const char *, p, 0x24), (s32 *)(p + 0x44), (s32 *)(p + 0x48), LFLD(s8, p, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, p, 0x28);
    LFLD(u32, p, 0x4) |= 0x40;
    LFLD(u32, p, 0x4) |= 0x41000000;
    LFLD(s32, p, 0x78) = 0x8000;
    LFLD(u16, p, 0x74) = 0x4fdf;
    LFLD(u16, p, 0x76) = 0x1e1e;
    LFLD(u32, p, 0x4) |= 4;
    func_0204ca70(p);
    LFLD(s32, p, 0x70) = -0x1cad;
}

void func_ov000_021743bc(VObj *self) {
    void *sub;
    BOOL has;
    u16 i;
    void *g;
    void *a;
    u32 n;
    u8 *m2;
    VObj *o;
    u8 *m;
    void *res;
    LFLD(u32, self, 0x4) &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    self->vfunc_3c();
    g = data_02149ef8;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x44) = o;
    LFLD(u32, o, 0xc) |= 0x4000000;
    LFLD(s32, LFLD(void *, self, 0x44), 0x2c) = 1;
    {
        u8 *s_0 = LFLD(u8 *, self, 0x44);
        LFLD(s32, s_0, 0x58) = 0x80;
        LFLD(s32, s_0, 0x5c) = 0;
        LFLD(s32, s_0, 0x60) = 0;
    }
    {
        u8 *s_1 = LFLD(u8 *, self, 0x44);
        LFLD(s16, s_1, 0x64) = 0;
        LFLD(s16, s_1, 0x66) = 0x10;
        LFLD(s16, s_1, 0x68) = -0x1ccd;
    }
    LFLD(u32, LFLD(void *, self, 0x44), 0xc) |= 0x20000000;
    LFLD(MenuBox021743bc *, self, 0x44)->SetText(1, func_0204c0e8(g, 0x32));
    LFLD(MenuBox021743bc *, self, 0x44)->SetText(2, func_0204c0e8(g, 0x33));
    LFLD(MenuBox021743bc *, self, 0x44)->Show();
    o = (VObj *)func_0203dd9c(0xd4);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x40) = o;
    LFLD(MenuList021743bc *, self, 0x40)->SetTitleId((s32)func_0204c0e8(g, 0xb8));
    LFLD(MenuList021743bc *, self, 0x40)->SetTitle((const char *)func_0204c0e8(g, 0xb9));
    LFLD(s32, LFLD(void *, self, 0x40), 0x34) = 0x6000;
    LFLD(void *, LFLD(void *, self, 0x40), 0x8) = self;
    LFLD(s32, LFLD(void *, self, 0x40), 0x24) = 0x6c;
    LFLD(s32, LFLD(void *, self, 0x40), 0x20) = 5;
    {
        u8 *s_2 = LFLD(u8 *, self, 0x40);
        LFLD(s16, s_2, 0x64) = 0;
        LFLD(s16, s_2, 0x66) = 0x14;
        LFLD(s16, s_2, 0x68) = -0x1ccd;
    }
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) &= ~0x20000;
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) &= ~0x40000;
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) &= ~0x10000;
    LFLD(void *, LFLD(void *, self, 0x40), 0x78) = (void *)func_ov000_021742b4;
    LFLD(void *, LFLD(void *, self, 0x40), 0x84) = (void *)func_ov000_021742c8;
    LFLD(MenuList021743bc *, self, 0x40)->AddItem((const char *)func_0204c0e8(g, 0xba), 0x1a, 0xffff, 0xffff);
    LFLD(MenuList021743bc *, self, 0x40)->AddItem((const char *)func_0204c0e8(g, 0xc2), 6, 0xffff, 0xffff);
    LFLD(MenuList021743bc *, self, 0x40)->AddItem((const char *)func_0204c0e8(g, 0x112), 0xf, 0xffff, 0xffff);
    LFLD(MenuList021743bc *, self, 0x40)->AddItem((const char *)func_0204c0e8(g, 0x118), 5, 0xffff, 0xffff);
    if (func_020594bc(data_02fe152c, 5, 1, 0) == 0) {
        LFLD(s32, func_ov000_02154b58(LFLD(void *, self, 0x40), 0x1a), 0x24) = 0xe;
    }
    if (func_ov000_021824d0(data_ov000_021ccd54 + 0xac, 0) == 0) {
        LFLD(s32, func_ov000_02154b58(LFLD(void *, self, 0x40), 0xf), 0x24) = 0xe;
    }
    sub = LFLD(void *, data_02fe152c, 0x4c);
    a = func_0205976c(data_02fe152c, 3);
    n = func_0205975c(data_02fe152c, 3);
    for (i = 0; i < n; i++) {
        if (func_02059544(data_02fe152c, (u8 *)sub + 0x70, a, 1, i) != 0) {
            has = TRUE;
            goto found;
        }
    }
    has = FALSE;
found:
    if (!has) {
        LFLD(s32, func_ov000_02154b58(LFLD(void *, self, 0x40), 5), 0x24) = 0xe;
    }
    {
        MenuList021743bc *t = LFLD(MenuList021743bc *, self, 0x40);
        if (LFLD(s32, &data_ov000_021ccd34, 4) == 0) {
            MenuItem021743bc id = MENU021743BC_ITEM_TOP;
            t->Select(func_ov000_02154b58(t, id));
        } else {
            t->Select(func_ov000_02154b58(t, (u16)LFLD(s32, &data_ov000_021ccd34, 4)));
        }
    }
    LFLD(MenuList021743bc *, self, 0x40)->Show();
    {
        u8 *s_3 = LFLD(u8 *, self, 0x40);
        LFLD(void *, s_3, 0x6c) = data_ov000_021c9c28;
        LFLD(s32, s_3, 0x70) = 5;
    }
    res = func_02034d88(func_02035d5c(data_0208ccc8), data_ov000_021cba0c);
    m = (u8 *)func_0203dd9c(0x160);
    if (m != NULL) {
        void *file = data_0208ccc8;
        void *nm = data_ov000_021cba0c;
        func_02041218(m + 0x88);
        func_02041440(m, nm, 0);
        STD_CopyString(m + 0x2c, file);
    }
    LFLD(u8 *, self, 0x58) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(void *, self, 0x58), 0x6c) |= 2;
    func_02041d9c(LFLD(void *, self, 0x58), 0, 0xffff);
    LFLD(s32, LFLD(void *, self, 0x58), 0x150) = -0x1cbd;
    res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    m2 = (u8 *)func_0203dd9c(0x160);
    if (m2 != NULL) {
        void *file = data_0208cc94;
        void *nm = data_0208cc88;
        func_02041218(m2 + 0x88);
        func_02041440(m2, nm, 0);
        STD_CopyString(m2 + 0x2c, file);
    }
    LFLD(u8 *, self, 0x5c) = m2;
    func_020417e0(m2, res);
    LFLD(u32, LFLD(void *, self, 0x5c), 0x6c) |= 2;
    func_02041d9c(LFLD(void *, self, 0x5c), 0, 6);
    func_02041d9c(LFLD(void *, self, 0x5c), 0, 9);
    func_02041d9c(LFLD(void *, self, 0x5c), 0, 0xa);
    LFLD(u32, LFLD(void *, self, 0x5c), 0x6c) |= 0x80000;
    LFLD(u32, LFLD(void *, self, 0x5c), 0x6c) = (LFLD(u32, LFLD(void *, self, 0x5c), 0x6c) & ~0x7c) | 0x78;
    LFLD(s32, LFLD(void *, self, 0x5c), 0x150) = -0x1c9d;
    func_02041c5c(LFLD(void *, self, 0x5c), (int)func_ov000_02174168);
    InitWin021743bc((u8 *)self + 0x60, func_0204c0e8(g, 0xba));
    InitWin021743bc((u8 *)self + 0x118, func_0204c0e8(g, 0x48));
    InitWin021743bc((u8 *)self + 0x1d0, func_0204c0e8(g, 0x49));
    InitWin021743bc((u8 *)self + 0x288, func_0204c0e8(g, 0x4a));
    InitWin021743bc((u8 *)self + 0x340, func_0204c0e8(g, 0x4b));
    InitWin021743bc((u8 *)self + 0x3f8, func_0204c0e8(g, 0x4c));
    o = (VObj *)func_0203dd9c(0x21c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021ca94c;
        LFLD(void *, o, 0x90) = data_0208ba70;
        func_0204c7d0((u8 *)o + 0x90);
        LFLD(void *, o, 0x148) = data_0208ba70;
        func_0204c7d0((u8 *)o + 0x148);
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x48) = o;
    o->vfunc_08();
    LFLD(Bits021743bc, LFLD(void *, self, 0x48), 0xc).b4 = 0;
    LFLD(s16, LFLD(void *, self, 0x48), 0x68) = -0x1ccd;
    if (IsMode4_021743bc()) {
        func_0203cb78(LFLD(s32, self, 0x20), 0, -1);
    }
    func_ov000_02173648(self);
}

}
