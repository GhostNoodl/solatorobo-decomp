#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u8 pad[0x258];
    VecFx32 camPos;
} Glb_021afaf8;

typedef struct {
    u16 a : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 mode : 3;
    u16 b9 : 2;
    u16 b11 : 1;
    u16 b12 : 1;
    u16 b13 : 1;
    u16 rest : 2;
} B22_021afaf8;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 1;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 9;
    u32 b19 : 1;
    u32 rest : 12;
} B24_021afaf8;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 4;
    u16 b7 : 2;
    u16 b9 : 1;
    u16 rest : 6;
} Sv18_021afaf8;

typedef struct {
    u8 b0 : 5;
    u8 b5 : 2;
    u8 b7 : 1;
} B93_021afaf8;

typedef struct {
    u8 b0 : 6;
    u8 b6 : 1;
    u8 b7 : 1;
} B190_021afaf8;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} H_021afaf8;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
} C_021afaf8;

typedef struct {
    s32 w[6];
    u8 alt;
    u8 pad[7];
} Def_021afaf8;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021afaf8;

namespace K021afaf8 {
extern "C" const char data_ov000_021cc729[];
extern "C" const char data_ov000_021cc733[];
extern "C" const char data_ov000_021cc73d[];
extern "C" const char data_ov000_021cc747[];
}

extern "C" {
extern Glb_021afaf8 NNS_G3dGlb;
extern u8 *data_0214a424;
extern Def_021afaf8 data_ov000_021ca398[];
extern Def_021afaf8 data_ov000_021ca248[];
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
u8 *func_0206ef10(u16 id);
u8 *func_02065f88(s32 id, void *pos);
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);
void *func_ov000_0218e9c4(void *p);
void *STD_CopyString(void *dst, const char *src);
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_0218d398(void *a, u16 id, s32 b, s32 c, s32 d, void *e);
void func_ov000_0218d46c(void *a, u16 id, s32 b);
void func_ov000_02191008(void *p);
void func_ov000_0218ec60(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218edf0(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218ef10(void *p, s32 a, s32 b, s32 c, s32 d);
void *NNS_G3dGetMdlSet(void *file);
void NNS_G3dReleaseMdlSet(void *mdl);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);

static inline BOOL GBusy_021afaf8(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle_021afaf8(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy_021afaf8(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline u8 *FindActor_021afaf8(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

struct Obj021afaf8 {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x2e];
    u8 *unk_3c;
    u8 *unk_40;
    u8 *unk_44;
    u8 unk_48[0x24];
    s32 unk_6c;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u8 unk_7c[0x14];
    u16 unk_90;
    u8 unk_92[0x1];
    B93_021afaf8 unk_93;
    u8 unk_94[0x18];
    u8 *unk_ac;
    u8 unk_b0[0xbe];
    H_021afaf8 unk_16e;
    u8 unk_170[0x2ba];
    H_021afaf8 unk_42a;
    u8 unk_42c[0x2e0];
    s32 unk_70c;
    u8 unk_710[0x4c];
    VecFx32 unk_75c;
    u8 unk_768[0xa];
    u8 unk_772;
    u8 unk_773;
    u8 unk_774;
    u8 unk_775[0x223];
    void *unk_998;
    void *unk_99c;
    u8 unk_9a0[0x6];
    u16 unk_9a6;
    u16 unk_9a8;
    u16 unk_9aa;
    u16 unk_9ac;
    u16 unk_9ae;
    u8 unk_9b0[0x140];
    s32 unk_af0;
    s32 unk_af4;
    s32 unk_af8;
    u8 unk_afc[0x20];
    u16 unk_b1c;
    u16 unk_b1e;
    u8 unk_b20[0x2];
    B22_021afaf8 unk_b22;
    B24_021afaf8 unk_b24;
    u8 unk_b28[0x4];
    u16 unk_b2c;
    u8 unk_b2e[0x2];
    u8 unk_b30;
    u8 unk_b31;
    u8 unk_b32[0x6e];
    Def_021afaf8 *unk_ba0;
    u8 *unk_ba4;
};

static inline BOOL SameRoom_021afaf8(Obj021afaf8 *self) {
    u8 *g = data_ov000_021ccd54;
    BOOL r = FALSE;
    if (g[0xca] == self->unk_772 && g[0xcb] == self->unk_773 && g[0xcc] == self->unk_774) {
        r = TRUE;
    }
    return r;
}

static inline void FreeModels_021afaf8(Obj021afaf8 *self) {
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_998 != NULL) {
            void *p = self->unk_998;
            if (p != NULL) {
                func_ov000_0218fee4(p);
                func_0203de1c(p);
            }
            self->unk_998 = NULL;
        }
        LO_HEAP_POP(saved);
    }
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_99c != NULL) {
            void *p = self->unk_99c;
            if (p != NULL) {
                func_ov000_0218ea20(p);
                func_0203de1c(p);
            }
            self->unk_99c = NULL;
        }
        LO_HEAP_POP(saved);
    }
}

void func_ov000_021afaf8(VObj *self_, u8 *anm, Def_021afaf8 *def) {
    Obj021afaf8 *self = (Obj021afaf8 *)self_;
    BOOL big;
    anm = NULL;
    s32 ofs;
    def = NULL;
    u8 *sv;
    u32 mode;
    u32 lock;
    u32 id;
    VecFx32 p_0;
    VecFx32 v;
    Pose_021afaf8 st;

    LFLD(H_021afaf8, self->unk_44, 0x22).b1 = 0;
    switch (LFLD(u16, self->unk_40, 0)) {
    case 0: {
        self->unk_b22.b9 = 2;
        self->unk_b2c = 0;
        self->unk_93.b5 = 0;
        sv = data_0214a424;
        big = FALSE;
        ofs = 0;
        mode = self->unk_b22.mode;
        lock = LFLD(Sv18_021afaf8, sv, 0x18).b1;
        id = LFLD(Sv18_021afaf8, sv, 0x18).b3;
        switch (mode) {
        case 0:
            if (lock != 0) {
                LFLD(Sv18_021afaf8, sv, 0x18).b1 = 0;
            }
            def = &data_ov000_021ca398[self->unk_b22.mode];
            ofs = 0x1000;
            break;
        case 1:
            if (lock != 0) {
                LFLD(Sv18_021afaf8, sv, 0x18).b1 = 0;
            }
            def = &data_ov000_021ca398[self->unk_b22.mode];
            self->unk_9ac = self->unk_9ae = 0x1770;
            big = TRUE;
            break;
        case 2:
            if (lock != 1) {
                LFLD(Sv18_021afaf8, sv, 0x18).b1 = 1;
            }
            anm = func_0206ef10(id | 0x8000);
            if (anm != NULL) {
                def = (Def_021afaf8 *)(anm + 0xc);
            }
            ofs = 0x1000;
            break;
        case 3:
            if (lock != 1) {
                LFLD(Sv18_021afaf8, sv, 0x18).b1 = 1;
            }
            anm = func_0206ef10(id | 0x8000);
            if (anm != NULL) {
                def = (Def_021afaf8 *)(anm + 0xc);
            }
            big = TRUE;
            if (self->unk_b22.a != 0) {
                ofs = 0x1000;
            }
            self->unk_9ac = self->unk_9ae = 0x2328;
            break;
        case 4:
            if (self->unk_b22.b3) {
                break;
            }
            self->unk_b22.b3 = 1;
            def = &data_ov000_021ca248[lock];
            if (GIdle_021afaf8() && !self->unk_b22.b13) {
                p_0.x = self->unk_70;
                p_0.y = self->unk_74;
                p_0.z = self->unk_78;
                p_0.y += 0x1800;
                func_02065f88(0x5e0, &p_0);
                func_02065f88(0x384, &p_0);
            }
            break;
        case 5:
            if (lock == 2) {
                break;
            }
            LFLD(Sv18_021afaf8, sv, 0x18).b1 = 2;
            def = &data_ov000_021ca398[self->unk_b22.mode];
            self->unk_af0 = self->unk_70 - NNS_G3dGlb.camPos.x;
            self->unk_af4 = self->unk_74 - NNS_G3dGlb.camPos.y;
            self->unk_af8 = self->unk_78 - NNS_G3dGlb.camPos.z;
            break;
        }
        self->unk_ba4 = anm;
        self->unk_ba0 = def;
        if (self->unk_b22.b3 && self->unk_b22.mode != 4) {
            ofs = self->unk_b22.b4 ? 0 : 0x1800;
            self->unk_b22.b3 = 0;
            self->unk_b22.b4 = 0;
        }
        if (!big && self->unk_b22.a != 0) {
            self->unk_b22.a = 0;
            LFLD(B190_021afaf8, data_ov000_021ccd54, 0x190).b6 = 0;
            self->unk_70c = 0xa000;
            LFLD(s32, self->unk_3c, 0xc) = 0xa000;
            FreeModels_021afaf8(self);
            ofs = 0;
        } else if (big) {
            const char *s1;
            const char *s2;
            u8 *r;
            self->unk_b22.a = 1;
            LFLD(B190_021afaf8, data_ov000_021ccd54, 0x190).b6 = 1;
            self->unk_70c = 0x14000;
            LFLD(s32, self->unk_3c, 0xc) = 0x14000;
            FreeModels_021afaf8(self);
            {
                void *p_1 = func_0203dd9c(0x138);
                if (p_1 != NULL) {
                    p_1 = func_ov000_0218e9c4(p_1);
                }
                self->unk_99c = p_1;
            }
            s1 = K021afaf8::data_ov000_021cc729;
            s2 = K021afaf8::data_ov000_021cc733;
            if (self->unk_b22.mode == 3) {
                s1 = K021afaf8::data_ov000_021cc73d;
                s2 = K021afaf8::data_ov000_021cc747;
            }
            r = (u8 *)self->unk_99c;
            STD_CopyString(r + 0x10, s1);
            STD_CopyString(r + 0x30, s2);
            LFLD(C_021afaf8, r, 3).b1 = 1;
            r = (u8 *)self->unk_99c;
            STD_CopyString(r + 0x4c, s1);
            STD_CopyString(r + 0x6c, s2);
            LFLD(C_021afaf8, r, 3).b2 = 1;
            LFLD(u16, self->unk_99c, 0) = 0;
            self->unk_9a6 = 0;
            self->unk_9a8 = 0;
            self->unk_9aa = 0;
            self->unk_b31 = 0;
            self->unk_b30 = 0;
        }
        if (def != NULL) {
            {
                u8 *a = FindActor_021afaf8(self->unk_b1c);
                if (a != NULL) {
                    st.pos.x = self->unk_70;
                    st.pos.y = self->unk_74;
                    st.pos.z = self->unk_78;
                    st.pos.y += self->unk_6c;
                    st.rx = LFLD(u16, a, 0x7c);
                    st.ry = LFLD(u16, a, 0x7e);
                    st.rz = LFLD(u16, a, 0x80);
                    st.unk = 0;
                    func_ov000_0218d398(a, self->unk_0c, 7, 1, 0x18, &st);
                    func_ov000_0218d46c(a, self->unk_0c, 0xa);
                    if (LFLD(u8 *, a, 0x4c) != NULL) {
                        LFLD(C_021afaf8, LFLD(u8 *, a, 0x4c), 0x18).b0 = 0;
                    }
                }
            }
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24.b5 = 0;
            self->unk_b24.b7 = self->unk_b24.b9;
            self->unk_90 = 0xffff;
            if (ofs != 0 && !self->unk_b22.b13) {
                if (self->unk_b24.b1 || (!(LFLD(Sv18_021afaf8, data_0214a424, 0x18).b9 ? TRUE : FALSE) && SameRoom_021afaf8(self))) {
                    if (!self->unk_b24.b1) {
                        ofs = 0xccd;
                    }
                    v = self->unk_75c;
                    v.y += ofs;
                    func_02065f88(0x5dc, &v);
                    func_02065f88(0x384, &v);
                }
            }
            self->unk_42a.b0 = 0;
            func_ov000_02191008((u8 *)self + 0x368);
            if ((u8 *)self->unk_998 != NULL) {
                LFLD(H_021afaf8, self->unk_998, 0xc2).b0 = 0;
            }
            self->unk_16e.b0 = 0;
            {
                void **res = LFLD(void **, self->unk_ac, 0xc);
                NNS_G3dReleaseMdlSet(NNS_G3dGetMdlSet(res != NULL ? *res : NULL));
            }
            func_ov000_0218ec60((u8 *)self + 0x450, def->w[0], def->w[1], 1, 1);
            func_ov000_0218edf0((u8 *)self + 0x450, def->w[2], def->w[3], 1, 1);
            func_ov000_0218ef10((u8 *)self + 0x450, def->w[4], def->w[5], 1, 1);
            if (def->alt != 0) {
                func_ov000_0218edf0((u8 *)self + 0x588, def->w[0], def->w[1], 1, 1);
            }
            self->unk_b22.b11 = 1;
            self->unk_b22.b12 = 1;
            LFLD(u16, self->unk_40, 0)++;
        } else {
            self->unk_b24.b19 = 1;
            self->unk_b22.b9 = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    case 1:
        if (!self_->vfunc_0c()) {
            return;
        }
        self->unk_b22.b13 = 0;
        self->unk_b22.b9 = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        return;
        break;
    }
}
}
