#include "ov002/ov002.h"

extern "C" {

void *func_ov000_021c4014(void *list, int idx);
void func_ov000_021c414c(void *list, void *item);
void func_ov000_021c403c(void *list, int idx);
void func_ov002_021e331c(void *self);
void *func_ov002_021def98(void *self, u32 kind);
void *func_ov002_021e35c0(void *self, u16 id);
void func_ov002_021dec74(void *self);
void func_0206ecd4(int a, void *b, u16 c);

static inline bool isState5(void *p) {
    return FIELD(p, 0x4, s32) == 5;
}

static inline void ov002_Anim_Update(u8 *self) {
    s32 v = FIELD(self, 0x30, s32);
    if (FIELD(self, 0x24, s32 *) != NULL) {
        *FIELD(self, 0x24, s32 *) = v;
    }
    if (FIELD(self, 0x28, s32 *) != NULL) {
        *FIELD(self, 0x28, s32 *) = v;
    }
    if (FIELD(self, 0x2c, s32 *) != NULL) {
        *FIELD(self, 0x2c, s32 *) = v;
    }
    FIELD(self, 0x30, s32) = S32_MOD(FIELD(self, 0x30, s32) + 0x1000, FIELD(self, 0x34, s32));
}

static inline void ov002_SetFlag1(void *p) {
    FIELD(p, 0xc, Bits32).b1 = 1;
}

static inline void ov002_ClrFlag1(void *p) {
    FIELD(p, 0xc, Bits32).b1 = 0;
}

void func_ov002_021de544(void *self, u8 *a) {
    FIELD(self, 0x4, u8 *) = a;
    FIELD(self, 0x8, VObject *)->v0x1c();
    if (FIELD(self, 0xc, VObject *) != NULL) {
        FIELD(self, 0xc, VObject *)->v0x1c();
    }
    ov002_Anim_Update(FIELD(self, 0x10, u8 *));
    ov002_Anim_Update(FIELD(self, 0x14, u8 *));
    switch (FIELD(self, 0x1c, s32)) {
    case 0:
        if (FIELD(self, 0xc, void *) != NULL) {
            ov002_SetFlag1(FIELD(self, 0xc, void *));
        }
        {
            u8 *w = FIELD(a, 0x4, u8 *);
            FIELD(w, 0x74, u8) = 5;
            FIELD(w, 0x75, u8) = 1;
        }
        FIELD(self, 0x1c, s32)++;
    case 1: {
        s32 cnt[5];
        int i;
        u8 *w;
        if (FIELD(self, 0xc, void *) != NULL) {
            BOOL st = isState5(FIELD(self, 0xc, void *));
            if (!st) {
                break;
            }
        }
        MIi_CpuClear32(0, cnt, sizeof(cnt));
        w = FIELD(a, 0x4, u8 *) + 8;
        for (i = 0; i < 100; i++) {
            u8 *info = func_0206ede8(i + 0x2000);
            cnt[info[0]] += w[i];
        }
        for (i = 0; i < 5; i++) {
            u8 *o = (u8 *)func_ov000_021c4014(FIELD(self, 0x8, void *), i);
            FIELD(o, 0x44, u8) = cnt[i] != 0 ? TRUE : FALSE;
            func_ov002_021e331c(o);
        }
        ov002_ClrFlag1(FIELD(self, 0x8, void *));
        func_ov000_0215bb14(FIELD(a, 0x20, void *), FIELD(FIELD(FIELD(self, 0x8, u8 *), 0xa0, u8 *), 0x40, void *));
        FIELD(a, 0x20, VObject *)->v0x70();
        FIELD(self, 0x20, u8) = 0;
        FIELD(self, 0x21, u8) = 0;
        FIELD(self, 0x1c, s32)++;
        break;
    }
    case 2:
        if (FIELD(data_02097dc8, 0x12, u16) & 2) {
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
            FIELD(self, 0x1c, s32) = 0x1e;
        } else if (FIELD(self, 0x20, u8)) {
            FIELD(self, 0x20, u8) = 0;
            func_ov000_0215bb14(FIELD(a, 0x20, void *), FIELD(FIELD(FIELD(self, 0x8, u8 *), 0xa0, u8 *), 0x40, void *));
            FIELD(a, 0x20, VObject *)->v0x70();
        } else if (FIELD(self, 0x21, u8)) {
            u8 *l = FIELD(self, 0x8, u8 *);
            FIELD(self, 0x21, u8) = 0;
            FIELD(self, 0x28, s32) = FIELD(FIELD(l, 0xa4, u8 *), 0x4, s32);
            ov002_SetFlag1(l);
            FIELD(self, 0x1c, s32) = 10;
        }
        break;
    case 10:
        ov002_SetFlag1(FIELD(self, 0x8, void *));
        {
            u8 *w = FIELD(a, 0x4, u8 *);
            FIELD(w, 0x74, u8) = 6;
            FIELD(w, 0x75, u8) = 1;
        }
        FIELD(self, 0x1c, s32)++;
    case 11: {
        BOOL st = isState5(FIELD(self, 0x8, void *));
        if (!st) {
            break;
        }
        {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(FIELD(self, 0xc, VObject *));
            HEAP_POP(saved);
        }
        FIELD(self, 0xc, void *) = func_ov002_021def98(self, FIELD(self, 0x28, s32));
        if (FIELD(self, 0x18, u16) != 0xffff) {
            func_ov000_021c414c(FIELD(self, 0xc, void *), func_ov002_021e35c0(FIELD(self, 0xc, void *), FIELD(self, 0x18, u16)));
            FIELD(self, 0x18, u16) = 0xffff;
        } else {
            func_ov000_021c403c(FIELD(self, 0xc, void *), 0);
        }
        func_0206ecd4(0x100, (u8 *)self + 0x38, FIELD(FIELD(FIELD(self, 0xc, u8 *), 0xa0, u8 *), 0x38, u16));
        func_ov000_0215bb14(FIELD(a, 0x20, void *), (u8 *)self + 0x38);
        FIELD(a, 0x20, VObject *)->v0x70();
        FIELD(self, 0x22, u8) = 0;
        FIELD(self, 0x23, u8) = 0;
        ov002_ClrFlag1(FIELD(self, 0xc, void *));
        FIELD(self, 0x1c, s32)++;
        break;
    }
    case 12:
        func_ov002_021dec74(self);
        break;
    case 20:
        ov002_SetFlag1(FIELD(self, 0x8, void *));
        if (FIELD(self, 0xc, void *) != NULL) {
            ov002_SetFlag1(FIELD(self, 0xc, void *));
        }
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        FIELD(self, 0x1c, s32)++;
    case 21: {
        void *p;
        if (FIELD(self, 0xc, void *) != NULL) {
            BOOL st = isState5(FIELD(self, 0xc, void *));
            if (!st) {
                break;
            }
        }
        p = func_0203dd9c(0x30);
        if (p != NULL) {
            *(VFunc **)p = data_ov002_021eff30;
            FIELD(p, 0x4, s32) = 0;
            FIELD(p, 0x8, s32) = -1;
            FIELD(p, 0xc, s32) = 0;
            FIELD(p, 0x10, s32) = 0;
            FIELD(p, 0x14, s32) = 0;
            FIELD(p, 0x18, s32) = 0;
            FIELD(p, 0x20, s32) = 0;
            FIELD(p, 0x1c, s32) = 0;
            FIELD(p, 0x28, s32) = 0;
            FIELD(p, 0x24, s32) = 0;
            FIELD(p, 0x2c, u8) = 0;
        }
        FIELD(a, 0x10, void *) = p;
        FIELD(a, 0xc, s32) = 0x1e;
        FIELD(self, 0x1c, s32) = 0x1f;
        break;
    }
    case 30:
        ov002_SetFlag1(FIELD(self, 0x8, void *));
        if (FIELD(self, 0xc, void *) != NULL) {
            ov002_SetFlag1(FIELD(self, 0xc, void *));
        }
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        FIELD(self, 0x1c, s32)++;
    case 31: {
        void *p;
        BOOL st = isState5(FIELD(self, 0x8, void *));
        if (!st) {
            break;
        }
        p = func_0203dd9c(0x134);
        if (p != NULL) {
            *(VFunc **)p = data_ov002_021eff10;
            FIELD(p, 0x4, s32) = 0;
            FIELD(p, 0x8, s32) = 0;
            FIELD(p, 0xc, s32) = 0;
            FIELD(p, 0x10, s32) = 0;
            FIELD(p, 0x14, s32) = 0;
            FIELD(p, 0x18, s32) = 0;
            FIELD(p, 0x1c, s32) = -1;
            FIELD(p, 0x20, u8) = 0;
            FIELD(p, 0x24, s32) = 0;
            FIELD(p, 0x28, s32) = 0;
            FIELD(p, 0x2c, s32) = 0;
            FIELD(p, 0x30, s32) = 0;
            FIELD(p, 0x34, u8) = 0;
        }
        FIELD(a, 0x10, void *) = p;
        FIELD(a, 0xc, s32) = 10;
        FIELD(self, 0x1c, s32) = 0x1f;
        break;
    }
    }
    FIELD(self, 0x4, u8 *) = NULL;
}

}
