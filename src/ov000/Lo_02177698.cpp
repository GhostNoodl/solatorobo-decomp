#include "ov000/LoCommon.h"

typedef struct {
    u8 unk_00[0x72];
    u16 unk_72;
} Data02fe1534;

extern "C" {
extern Data02fe1534 data_02fe1534;
extern u8 *data_0214a424;
extern void *data_02097e4c;
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

static inline u8 *GetNth(u8 *m) {
    u8 *p = LFLD(u8 *, m, 0x98);
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = LFLD(s8, m, 0xb1);
    while (n-- != 0) {
        p = LFLD(u8 *, p, 0x2c);
    }
    return p;
}


}

extern "C" {
extern void *data_02149ef8;
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);

s32 func_ov000_02177698(u8 *self, u8 *item) {
    u8 *o = LFLD(u8 *, self, 0x8);
    VObj *t = LFLD(VObj *, o, 0x50);
    if (t != NULL) {
        if (item != NULL) {
            u16 id;
            u8 *a;
            func_0206ecd4(0x100, o + 0x5c, LFLD(u16, item, 6));
            func_ov000_0215bb14(t, o + 0x5c);
            t->vfunc_70();
            id = LFLD(u16, item, 6);
            a = LFLD(u8 *, o, 0x44);
            if (id & 0x2000) {
                u8 *b;
                if (a != NULL) {
                    func_ov000_0215d980(a, LFLD(u8, data_0214a424 + (u16)(id & 0xfff), 0x2a), 1);
                    LFLD(u32, a, 0xc) &= ~0x20;
                }
                b = LFLD(u8 *, o, 0x48);
                if (b != NULL) {
                    func_ov000_0215d980(b, func_0206d1d4(data_0214a424, LFLD(u16, item, 6)), 1);
                    LFLD(u32, b, 0xc) &= ~0x20;
                }
            } else {
                if (a != NULL) {
                    LFLD(u32, a, 0xc) |= 0x20;
                }
                if (LFLD(u8 *, o, 0x48) != NULL) {
                    LFLD(u32, LFLD(u8 *, o, 0x48), 0xc) |= 0x20;
                }
            }
        } else {
            func_ov000_0215bb14(t, func_0204c0e8(data_02149ef8, 0x9d));
            t->vfunc_70();
        }
    }
    return 1;
}

s32 func_ov000_021777d4(u8 *self, u16 id) {
    u8 *m = LFLD(u8 *, self, 0x4c);
    void *obj = LFLD(void *, self, 0x40);
    u8 *node = GetNth(m);
    u8 *g = data_0214a424;
    u32 t;
    data_02fe1534.unk_72 = id;
    t = LFLD(u32, node, 0xc);
    LFLD(u32, g, 0x20) = LFLD(u32, g, 0x20) > t ? LFLD(u32, g, 0x20) - t : 0;
    func_ov000_0215d980(obj, LFLD(u32, data_0214a424, 0x20), 0);
    if (id & 0x2000) {
        if (LFLD(void *, self, 0x44) != NULL) {
            func_ov000_0215d980(LFLD(void *, self, 0x44), LFLD(u8, data_0214a424 + (u16)(id & 0xfff), 0x2a), 1);
        }
        void *o48 = LFLD(void *, self, 0x48);
        if (o48 != NULL) {
            func_ov000_0215d980(o48, func_0206d1d4(data_0214a424, id), 1);
        }
    }
    func_02049a48(data_02097e4c, 0x31, -1, -1, -1);
    return 0;
}
}

extern "C" {
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
BOOL func_0206f21c(u16 a, s32 b);
void func_ov000_0215c1bc(void *self, s32 id, void *v);
void func_ov000_02153c48(u8 *self, s32 a, BOOL show, BOOL center, u8 d);

static inline void ShowMsg021778f0(u8 *self, s32 msg) {
    if (LFLD(VObj *, self, 0x58) == NULL) {
        VObj *o = (VObj *)func_0203dd9c(0xe8);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac60);
            o->vfunc_28();
            VOBJ_SET_VTABLE(o, data_ov000_021cad50);
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x58) = o;
    }
    LFLD(s32, LFLD(VObj *, self, 0x58), 0x1c) = 4;
    LFLD(VObj *, self, 0x58)->vfunc_08();
    LFLD(u32, LFLD(VObj *, self, 0x58), 0xc) |= 0x20000;
    func_ov000_0215c1bc(LFLD(VObj *, self, 0x58), 0x8000, func_0204c0e8(data_02149ef8, msg));
    LFLD(s16, LFLD(VObj *, self, 0x58), 0x68) = -0x199a;
    LFLD(VObj *, self, 0x58)->vfunc_70();
}

static inline BOOL IsUnset021778f0(u8 *p) {
    return LFLD(s32, p, 0xc) == -1;
}

static inline BOOL IsCost021778f0(u32 c) {
    return c == (u32)-1;
}

static inline void Snd021778f0(s32 id) {
    func_02049a48(data_02097e4c, id, -1, -1, -1);
}

static inline void SetBit021778f0(void *p) {
    if (p != NULL) {
        LFLD(u32, p, 0xc) |= 2;
    }
}

static inline void AddCount021778f0(u16 n) {
    u8 *g = data_0214a424;
    LFLD(u16, g, 0x24) += n;
    if (LFLD(u16, g, 0x24) > 9999) {
        LFLD(u16, g, 0x24) = 9999;
    }
}

static inline void ResetItem021778f0(u8 *item) {
    if (LFLD(s32, item, 0x10) == 1) {
        LFLD(s32, item, 0x10) = 0;
        LFLD(s32, item, 0xc) = -1;
        LFLD(s32, item, 0x24) = 0xe;
        if (LFLD(void *, item, 0x1c) != NULL) {
            func_ov000_02153c48(item, 8, TRUE, 0, 0);
        }
    }
}

BOOL func_ov000_021778f0(u8 *self, u8 *item) {
    u16 id = LFLD(u16, item, 6);
    switch (((id >> 12) & 0xffff) - 1) {
    case 0:
        if (!func_ov000_021777d4(self, id)) {
            if (id == 0x1002) {
                AddCount021778f0(1);
            } else if (id == 0x1003) {
                AddCount021778f0(5);
            }
            return FALSE;
        }
        return TRUE;
    case 1:
        if (func_0206f21c(id, TRUE)) {
            if (func_ov000_021777d4(self, id)) {
                func_0206f21c(id, FALSE);
                return TRUE;
            }
            ResetItem021778f0(item);
        } else {
            ShowMsg021778f0(self, 0x9e);
        }
        break;
    case 4:
        if (func_0206f21c(id, TRUE)) {
            if (func_ov000_021777d4(self, id)) {
                func_0206f21c(id, FALSE);
                return TRUE;
            }
            LFLD(VObj *, self, 0x4c)->vfunc_70(item);
        }
        break;
    case 7:
        if (func_0206f21c(id, TRUE)) {
            if (func_ov000_021777d4(self, id)) {
                func_0206f21c(id, FALSE);
                return TRUE;
            }
            ResetItem021778f0(item);
        }
        break;
    }
    return FALSE;
}

s32 func_ov000_02177bd8(VObj *self, u8 *item) {
    u8 *o = LFLD(u8 *, self, 8);
    u8 *m = LFLD(u8 *, o, 0x4c);
    u8 *obj = (0, LFLD(u8 *, o, 0x40));
    u8 *node = GetNth(m);
    u16 type;
    if (item == NULL) {
        Snd021778f0(0x1f);
        return 0;
    }
    type = LFLD(u16, item, 6);
    if (type == 0) {
        u32 cost = LFLD(u32, node, 0xc);
        if (IsCost021778f0(cost)) {
            ShowMsg021778f0(o, 0x9f);
        } else if (LFLD(u32, obj, 0x8c) >= cost) {
            if (func_ov000_021778f0(o, node)) {
                SetBit021778f0(LFLD(void *, o, 0x3c));
                SetBit021778f0(LFLD(void *, o, 0x40));
                SetBit021778f0(LFLD(void *, o, 0x44));
                SetBit021778f0(LFLD(void *, o, 0x48));
                SetBit021778f0(LFLD(void *, o, 0x4c));
                SetBit021778f0(LFLD(void *, o, 0x50));
                SetBit021778f0(LFLD(void *, o, 0x58));
                ((VObj *)o)->vfunc_3c();
                return 0;
            }
        } else {
            Snd021778f0(0x20);
            ShowMsg021778f0(o, 0x9b);
        }
        return 0;
    }
    if (type != 1) {
        return 1;
    }
    Snd021778f0(0x1f);
    return 0;
}
}
