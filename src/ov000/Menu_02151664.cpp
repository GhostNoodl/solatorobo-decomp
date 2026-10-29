#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
extern u8 data_02fe1534[];
extern char data_ov000_021ca940[];
extern void *data_02097e4c;
extern void *data_ov000_021ccd54;
void func_ov000_0215ce8c(void *self, s32 id);
void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
u8 *func_ov000_0219bf90(void);
void func_ov000_021b4774(void *p);
char *func_02061f08(u16 id);
char *STD_SearchString(const char *s, const char *t);
int func_02060898(u16 a, s32 b, s32 c);
void func_ov000_021837f8(void *p, u16 id, s32 a, s32 b, s32 c, s32 d, s32 e);

static inline void Beep02151664(void) {
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
}

static inline void Show02151664(VObj *self, s32 id) {
    if (LFLD(VObj *, self, 0x58) == NULL) {
        VObj *p = (VObj *)func_0203dd9c(0xe8);
        if (p) {
            VOBJ_SET_VTABLE(p, data_ov000_021cac60);
            p->vfunc_28();
            VOBJ_SET_VTABLE(p, data_ov000_021cad50);
            p->vfunc_28();
        }
        LFLD(VObj *, self, 0x58) = p;
    }
    LFLD(s32, LFLD(VObj *, self, 0x58), 0x1c) = 4;
    LFLD(VObj *, self, 0x58)->vfunc_08();
    func_ov000_0215ce8c(LFLD(VObj *, self, 0x58), id);
    LFLD(s16, LFLD(VObj *, self, 0x58), 0x68) = -0x1666;
    LFLD(VObj *, self, 0x58)->vfunc_70();
}

static inline BOOL Check02151664(VObj *self) {
    char *s;
    if (LBIT(func_ov000_0219bf90(), 0xb24).b1) {
        return TRUE;
    }
    s = func_02061f08(LFLD(u16, LFLD(u8 *, self, 0x54), 6));
    if (s == NULL) {
        return FALSE;
    }
    return STD_SearchString(s, data_ov000_021ca940) != NULL ? TRUE : FALSE;
}

BOOL func_ov000_02151664(void *p, u8 *msg) {
    VObj *o = LFLD(VObj *, p, 8);
    if (msg == NULL) {
        Beep02151664();
        return FALSE;
    }
    if (LFLD(u16, msg, 6) == 0) {
        u8 *info = LFLD(u8 *, o, 0x54);
        if (LFLD(u16, data_02fe1534, 0x46) != LFLD(u16, info, 0x30)) {
            Beep02151664();
            Show02151664(o, 0x68);
        } else if (LFLD(u16, data_02fe1534, 0x58) < LFLD(u16, info, 0x34)) {
            Beep02151664();
            Show02151664(o, 0x69);
            LFLD(s32, o, 0x5c) = 0x6a;
        } else if (!Check02151664(o)) {
            Beep02151664();
            Show02151664(o, 0x6c);
        } else {
            u8 *pl = func_ov000_0219bf90();
            if (pl != NULL) {
                func_ov000_021b4774(pl);
            }
            func_02060898(LFLD(u16, o, 0x40), 0, -1);
            func_ov000_021837f8(data_ov000_021ccd54, LFLD(u16, LFLD(u8 *, o, 0x54), 6), 10, 0, 0, 0, 0);
            if (LFLD(VObj *, o, 0x4c) != NULL) {
                LFLD(u32, LFLD(VObj *, o, 0x4c), 0xc) |= 2;
            }
            if (LFLD(VObj *, o, 0x50) != NULL) {
                LFLD(u32, LFLD(VObj *, o, 0x50), 0xc) |= 2;
            }
            if (LFLD(VObj *, o, 0x58) != NULL) {
                LFLD(u32, LFLD(VObj *, o, 0x58), 0xc) |= 2;
            }
            o->vfunc_3c();
        }
        return FALSE;
    } else if (LFLD(u16, msg, 6) == 1) {
        Beep02151664();
        return FALSE;
    }
    return TRUE;
}

}
