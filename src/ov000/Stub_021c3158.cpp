#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 b0 : 1;
    u8 b1 : 7;
} Flag021c3158;

typedef struct {
    u8 unk_00[0x14];
    s32 unk_14;
    u8 unk_18[0x8];
    Flag021c3158 unk_20;
    u8 unk_21[0xf];
    char *unk_30;
    char *unk_34;
    u8 *unk_38;
    u8 *unk_3c;
    void *unk_40;
    s32 unk_44;
    u8 unk_48[0x4];
    u16 unk_4c;
    u16 unk_4e;
    u8 unk_50;
    u8 unk_51;
    u8 unk_52;
    u8 unk_53;
    u8 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c;
} Obj021c3158;

extern "C" {

extern char data_ov000_021cc9d3[];
extern char data_ov000_021cc9dc[];
void func_ov000_021c8408(void);
void func_ov000_021c2f90(Obj021c3158 *self);
BOOL func_02054f10(void *m, u32 a);
void func_020359fc(const char *arc, const char *name, s32 a, s32 b);
BOOL func_02035bd4(const char *arc, const char *name, s32 a);
void *func_02035f30(const char *arc, const char *name, s32 a);
void *func_02034d88(void *a, const char *name);
void *func_0203dd9c(u32 size);
void func_02041218(void *p);
void func_02041440(void *m, const char *name, s32 a);
void STD_CopyString(char *dst, const char *src);
void func_020417e0(void *m, void *res);
void func_02041d9c(void *m, s32 a, u16 b);
s32 FX_Div(s32 n, s32 d);
s32 func_02049130(s32 t, s32 a, s32 b);

static inline char *ObjName021c3158(Obj021c3158 *o) {
    return o->unk_34;
}

static inline void *LoadObjRes021c3158(Obj021c3158 *o) {
    return func_02035f30(o->unk_30, o->unk_34, 2);
}

static inline u8 *NewModel021c3158(char *arc, char *name) {
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m != NULL) {
        func_02041218(m + 0x88);
        func_02041440(m, name, 0);
        STD_CopyString((char *)m + 0x2c, arc);
    }
    return m;
}

static inline u8 *NewModelObj021c3158(Obj021c3158 *self) {
    char *arc;
    u8 *m;
    m = (u8 *)func_0203dd9c(0x160);
    if (m != NULL) {
        char *name = ObjName021c3158(self);
        arc = self->unk_30;
        func_02041218(m + 0x88);
        func_02041440(m, name, 0);
        STD_CopyString((char *)m + 0x2c, arc);
    }
    return m;
}

void func_ov000_021c3158(Obj021c3158 *self) {
    if (self->unk_68 != 0 && !self->unk_20.b0) {
        if (self->unk_38 == NULL) {
            return;
        }
        if (!func_02054f10(self->unk_38, 0xffff)) {
            return;
        }
        func_ov000_021c2f90(self);
        self->unk_68 = 0;
        return;
    }
    switch (self->unk_68) {
    case 0:
        if (!self->unk_20.b0) {
            return;
        }
        self->unk_68 = 10;
    case 10:
        self->unk_5c = 0;
        self->unk_60 = 0;
        func_020359fc(self->unk_30, self->unk_34, 2, 0);
        func_020359fc(data_ov000_021cc9d3, data_ov000_021cc9dc, 2, 0);
        self->unk_68++;
        return;
    case 11:
        if (!func_02035bd4(self->unk_30, self->unk_34, 2)) {
            return;
        }
        if (!func_02035bd4(data_ov000_021cc9d3, data_ov000_021cc9dc, 2)) {
            return;
        }
        self->unk_68 = 20;
    case 20: {
        s32 i;
        s32 n;
        s32 mask;
        {
            u8 *m_0;
            void *res_0 = LoadObjRes021c3158(self);
            res_0 = func_02034d88(res_0, self->unk_34);
            m_0 = NewModelObj021c3158(self);
            self->unk_38 = m_0;
            func_020417e0(m_0, res_0);
        }
        LFLD(u32, self->unk_38, 0x6c) |= 2;
        LFLD(u32, self->unk_38, 0x6c) |= 0x80000;
        LFLD(void *, self->unk_38, 0x158) = (void *)func_ov000_021c8408;
        {
            void *res_1;
            u8 *m_1;
            char *arc = data_ov000_021cc9d3;
            char *name = data_ov000_021cc9dc;
            res_1 = func_02035f30(arc, name, 2);
            res_1 = func_02034d88(res_1, name);
            m_1 = NewModel021c3158(arc, name);
            self->unk_3c = m_1;
            func_020417e0(m_1, res_1);
        }
        LFLD(u32, self->unk_3c, 0x6c) |= 2;
        LFLD(u32, self->unk_3c, 0x6c) |= 0x80000;
        LFLD(void *, self->unk_3c, 0x158) = (void *)func_ov000_021c8408;

        n = self->unk_51;
        mask = self->unk_4e;
        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                func_02041d9c(self->unk_38, 0, i);
            } else {
                func_02041d9c(self->unk_3c, 0, i);
            }
        }
        self->unk_68 = 30;
        return;
    }
    case 30: {
        u8 a;
        s32 t;
        self->unk_54 += 2;
        if (self->unk_6c != 0 || (a = self->unk_54) >= 0x1f) {
            a = 0x1f;
        }
        self->unk_54 = a;
        if (self->unk_6c != 0) {
            self->unk_58 = self->unk_58 >= 0x1000 ? 0x1000 : self->unk_58 + 0x111;
        } else {
            self->unk_58 = self->unk_58 > 0x99a ? self->unk_58 - 0x111 : 0x99a;
        }
        {
            t = FX_Div(self->unk_58 - 0x99a, 0x1000 - 0x99a);
            self->unk_5c = 0;
            self->unk_60 = func_02049130(t, 0xa000, 0);
        }
        if (self->unk_58 >= 0x1000) {
            self->unk_64 = 0x334 - 0x99a;
            return;
        }
        self->unk_64 = self->unk_14;
        return;
    }
    }
}

}
