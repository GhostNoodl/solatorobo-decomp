#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 pad[0x258];
    VecFx32 camPos;
} Glb_021afaf8;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 4;
    u16 b7 : 2;
    u16 b9 : 1;
    u16 rest : 6;
} Sv18_021afaf8;

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
Actor *ActorMgr_GetActor(void *mgr, u16 id);
void Actor_SendMsg(void *a, u16 id, s32 b, s32 c, s32 d, void *e);
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

static inline Actor *FindActor_021afaf8(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL SameRoom_021afaf8(Robo021ca458 *self) {
    u8 *g = data_ov000_021ccd54;
    BOOL r = FALSE;
    if (g[0xca] == self->unk_772 && g[0xcb] == self->unk_773 && g[0xcc] == self->unk_774) {
        r = TRUE;
    }
    return r;
}

static inline void FreeModels_021afaf8(Robo021ca458 *self) {
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_998 != NULL) {
            void *p = self->unk_998;
            if (p != NULL) {
                func_ov000_0218fee4(p);
                Heap_Free(p);
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
                Heap_Free(p);
            }
            self->unk_99c = NULL;
        }
        LO_HEAP_POP(saved);
    }
}

void func_ov000_021afaf8(VObj *self_, u8 *anm, Def_021afaf8 *def) {
    Robo021ca458 *self = (Robo021ca458 *)self_;
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
    switch (self->unk_40->st) {
    case 0: {
        self->unk_b22_9 = 2;
        self->unk_b2c = 0;
        self->unk_93_5 = 0;
        sv = data_0214a424;
        big = FALSE;
        ofs = 0;
        mode = self->unk_b22_6;
        lock = LFLD(Sv18_021afaf8, sv, 0x18).b1;
        id = LFLD(Sv18_021afaf8, sv, 0x18).b3;
        switch (mode) {
        case 0:
            if (lock != 0) {
                LFLD(Sv18_021afaf8, sv, 0x18).b1 = 0;
            }
            def = &data_ov000_021ca398[self->unk_b22_6];
            ofs = 0x1000;
            break;
        case 1:
            if (lock != 0) {
                LFLD(Sv18_021afaf8, sv, 0x18).b1 = 0;
            }
            def = &data_ov000_021ca398[self->unk_b22_6];
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
            if (self->unk_b22_0 != 0) {
                ofs = 0x1000;
            }
            self->unk_9ac = self->unk_9ae = 0x2328;
            break;
        case 4:
            if (self->unk_b22_3) {
                break;
            }
            self->unk_b22_3 = 1;
            def = &data_ov000_021ca248[lock];
            if (GIdle_021afaf8() && !self->unk_b22_13) {
                p_0.x = self->pos.x;
                p_0.y = self->pos.y;
                p_0.z = self->pos.z;
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
            def = &data_ov000_021ca398[self->unk_b22_6];
            self->unk_af0 = self->pos.x - NNS_G3dGlb.camPos.x;
            self->unk_af4 = self->pos.y - NNS_G3dGlb.camPos.y;
            self->unk_af8 = self->pos.z - NNS_G3dGlb.camPos.z;
            break;
        }
        self->unk_ba4 = anm;
        self->unk_ba0 = (u8 *) def;
        if (self->unk_b22_3 && self->unk_b22_6 != 4) {
            ofs = self->unk_b22_4 ? 0 : 0x1800;
            self->unk_b22_3 = 0;
            self->unk_b22_4 = 0;
        }
        if (!big && self->unk_b22_0 != 0) {
            self->unk_b22_0 = 0;
            LFLD(B190_021afaf8, data_ov000_021ccd54, 0x190).b6 = 0;
            self->unk_70c = 0xa000;
            LFLD(s32, self->unk_3c, 0xc) = 0xa000;
            FreeModels_021afaf8(self);
            ofs = 0;
        } else if (big) {
            const char *s1;
            const char *s2;
            u8 *r;
            self->unk_b22_0 = 1;
            LFLD(B190_021afaf8, data_ov000_021ccd54, 0x190).b6 = 1;
            self->unk_70c = 0x14000;
            LFLD(s32, self->unk_3c, 0xc) = 0x14000;
            FreeModels_021afaf8(self);
            {
                void *p_1 = Heap_Alloc(0x138);
                if (p_1 != NULL) {
                    p_1 = func_ov000_0218e9c4(p_1);
                }
                self->unk_99c = p_1;
            }
            s1 = K021afaf8::data_ov000_021cc729;
            s2 = K021afaf8::data_ov000_021cc733;
            if (self->unk_b22_6 == 3) {
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
                Actor *a = FindActor_021afaf8(self->unk_b1c);
                if (a != NULL) {
                    st.pos.x = self->pos.x;
                    st.pos.y = self->pos.y;
                    st.pos.z = self->pos.z;
                    st.pos.y += self->unk_6c;
                    st.rx = a->rot_x;
                    st.ry = a->rot_y;
                    st.rz = a->rot_z;
                    st.unk = 0;
                    Actor_SendMsg(a, self->id, 7, 1, 0x18, &st);
                    func_ov000_0218d46c(a, self->id, 0xa);
                    if (((u8 *)a->unk_4c) != NULL) {
                        LFLD(C_021afaf8, ((u8 *)a->unk_4c), 0x18).b0 = 0;
                    }
                }
            }
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24_5 = 0;
            self->unk_b24_7 = self->unk_b24_9;
            self->target = 0xffff;
            if (ofs != 0 && !self->unk_b22_13) {
                if (self->unk_b24_1 || (!(LFLD(Sv18_021afaf8, data_0214a424, 0x18).b9 ? TRUE : FALSE) && SameRoom_021afaf8(self))) {
                    if (!self->unk_b24_1) {
                        ofs = 0xccd;
                    }
                    v = self->unk_75c;
                    v.y += ofs;
                    func_02065f88(0x5dc, &v);
                    func_02065f88(0x384, &v);
                }
            }
            self->unk_42a_0 = 0;
            func_ov000_02191008((u8 *)self + 0x368);
            if ((u8 *)self->unk_998 != NULL) {
                LFLD(H_021afaf8, self->unk_998, 0xc2).b0 = 0;
            }
            self->unk_16e_0 = 0;
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
            self->unk_b22_11 = 1;
            self->unk_b22_12 = 1;
            self->unk_40->st++;
        } else {
            self->unk_b24_19 = 1;
            self->unk_b22_9 = 0;
            func_ov000_02198360(((u8 *)self->unk_40), 1, 0);
        }
        break;
    }
    case 1:
        if (!self_->vfunc_0c()) {
            return;
        }
        self->unk_b22_13 = 0;
        self->unk_b22_9 = 0;
        func_ov000_02198360(((u8 *)self->unk_40), 1, 0);
        return;
        break;
    }
}
}
