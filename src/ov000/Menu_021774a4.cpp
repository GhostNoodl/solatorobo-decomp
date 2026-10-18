#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad_00[0x3c];
    u8 *unk_3c;
    u8 *unk_40;
    u8 *unk_44;
    u8 *unk_48;
    u8 *unk_4c;
    u8 *unk_50;
    u8 pad_54[4];
    VObj *unk_58;
} Menu021774a4;

typedef struct {
    u8 pad_00[8];
    Menu021774a4 *unk_08;
} Self021774a4;

extern "C" {
extern void *data_02097e4c;
extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void *func_0203dd9c(u32 size);
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
s32 func_0204c0e8(void *msg, s32 id);
void func_ov000_0215c1bc(void *p, s32 a, s32 b);
void func_ov000_02152294(void *self, s32 a, s32 b, void *cb);
void func_ov000_02177bd8(void);

static inline u8 *List021774a4_Cur(u8 *list) {
    u8 *p = LFLD(u8 *, list, 0x98);
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = LFLD(s8, list, 0xb1);
    while (n-- != 0) {
        p = LFLD(u8 *, p, 0x2c);
    }
    return p;
}

#define SET_HIDE(x) if ((x) != NULL) LFLD(u32, (x), 0xc) |= 2

BOOL func_ov000_021774a4(Self021774a4 *self, BOOL ok) {
    Menu021774a4 *m = self->unk_08;
    u8 *item = List021774a4_Cur(m->unk_4c);

    if (!ok) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        SET_HIDE(m->unk_3c);
        SET_HIDE(m->unk_40);
        SET_HIDE(m->unk_44);
        SET_HIDE(m->unk_48);
        SET_HIDE(m->unk_4c);
        SET_HIDE(m->unk_50);
        SET_HIDE((u8 *)m->unk_58);
        return FALSE;
    }
    if (LFLD(s32, item, 0xc) == -1 ? TRUE : FALSE) {
        if (m->unk_58 == NULL) {
            VObj *o = (VObj *)func_0203dd9c(0xe8);
            if (o != NULL) {
                VOBJ_SET_VTABLE(o, data_ov000_021cac60);
                o->vfunc_28();
                VOBJ_SET_VTABLE(o, data_ov000_021cad50);
                o->vfunc_28();
            }
            m->unk_58 = o;
        }
        LFLD(s32, m->unk_58, 0x1c) = 4;
        m->unk_58->vfunc_08();
        LFLD(u32, m->unk_58, 0xc) |= 0x20000;
        func_ov000_0215c1bc(m->unk_58, 0x8000, func_0204c0e8(data_02149ef8, 0x9f));
        LFLD(s16, m->unk_58, 0x68) = -0x199a;
        m->unk_58->vfunc_70();
    } else {
        func_ov000_02152294(self, 0x90, 0x18, (void *)func_ov000_02177bd8);
    }
    return TRUE;
}
}
