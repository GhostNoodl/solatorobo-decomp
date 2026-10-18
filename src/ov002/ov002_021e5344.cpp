#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e5344(void) {
    return TRUE;
}

}

extern "C" {
extern char data_ov002_021f0640[];
void *func_02034ec0(void *a, void *b);
void *func_02034f5c(void *a, void *b);
void *func_02035ccc(void *a);
void func_02035cfc(void *a);
void func_02039494(u32 a);
void *NNS_G3dGetResDataByName(void *a, char *name);
void NNSi_G3dModifyMatFlag(void *mdl, BOOL a, u32 flag);
void STD_ConcatenateString(char *dst, const char *src);
BOOL func_0203ed04(const char *name, u32 res);
u32 func_0203ebf8(void);
void NNS_G3dBindMdlTex(void *mdl, void *tex);
void NNS_G3dBindMdlPltt(void *mdl, void *tex);

typedef struct Ent021e534c {
    s32 kind;
    void *arc;
    char *name;
    u32 task;
    u32 *res;
    u8 loaded;
    u8 alt;
    u32 *res2;
} Ent021e534c;

static inline void *ov002_021e534c_getMdl(u8 *set, char *name) {
    u32 *e;
    if (set != NULL && (e = (u32 *)NNS_G3dGetResDataByName(set + 8, name)) != NULL) {
        return set + *e;
    }
    return NULL;
}

static inline void *ov002_021e534c_mdlName(void *self) {
    return FIELD(self, 0x58, void *) != NULL ? FIELD(self, 0x58, void *) : FIELD(self, 0x54, void *);
}

static inline u32 *ov002_021e534c_res(Ent021e534c *e) {
    return e->alt ? e->res2 : e->res;
}

BOOL func_ov002_021e534c(void *self) {
    BOOL done = FALSE;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        if (FIELD(self, 0x50, void *) != NULL) {
            func_020359fc(FIELD(self, 0x50, void *), FIELD(self, 0x54, void *), 4, 0);
        } else {
            func_020359d0(FIELD(self, 0x54, void *), 4, 0);
        }
        FIELD(self, 0x14, s32) = 1;
        FIELD(self, 0x10, s32) = 10;
    case 10: {
        void *res;
        if (FIELD(self, 0x50, void *) != NULL) {
            if (!func_02035bd4(FIELD(self, 0x50, void *), FIELD(self, 0x54, void *), 4)) {
                break;
            }
            void *p = func_02035f30(FIELD(self, 0x50, void *), FIELD(self, 0x54, void *), 4);
            res = func_02034ec0(p, FIELD(self, 0x54, void *));
        } else {
            if (!func_02035b90(FIELD(self, 0x54, void *), 4)) {
                break;
            }
            res = func_02035ccc(FIELD(self, 0x54, void *));
        }
        FIELD(self, 0x5c, void *) = res;
        FIELD(self, 0x10, s32)++;
    }
    case 11: {
        char name[16];
        char path[32];
        MI_CpuFill8(name, 0, sizeof(name));
        if (FIELD(self, 0x58, void *) != NULL) {
            STD_CopyLString(name, FIELD(self, 0x58, void *), sizeof(name));
        } else {
            STD_CopyLString(name, FIELD(self, 0x54, void *), sizeof(name));
        }
        FIELD(self, 0x60, void *) = ov002_021e534c_getMdl((u8 *)NNS_G3dGetMdlSet((void *)*FIELD(self, 0x5c, u32 *)), name);
        STD_CopyLString(path, data_ov002_021f0640, sizeof(path));
        STD_ConcatenateString(path, FIELD(self, 0x54, char *));
        if (FIELD(self, 0x5c, u32 *) != NULL) {
            func_0203ed04(path, *FIELD(self, 0x5c, u32 *));
        }
        FIELD(self, 0xbc, u32) = func_0203ebf8();
        NNSi_G3dModifyMatFlag(FIELD(self, 0x60, void *), FALSE, 0x40);
        NNSi_G3dModifyMatFlag(FIELD(self, 0x60, void *), FALSE, 0x80);
        NNSi_G3dModifyMatFlag(FIELD(self, 0x60, void *), FALSE, 0x200);
        NNSi_G3dModifyMatFlag(FIELD(self, 0x60, void *), FALSE, 0x400);
        FIELD(self, 0x10, s32)++;
    }
    case 12:
        if (func_0203e63c((void *)FIELD(self, 0xbc, u32))) {
            FIELD(self, 0xbc, u32) = 0;
            FIELD(self, 0x10, s32)++;
        }
        break;
    case 13:
        func_02039494(*FIELD(self, 0x5c, u32 *));
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->arc != NULL) {
                func_020359fc(e->arc, e->name, 5, 0);
            } else {
                func_020359d0(e->name, 5, 0);
            }
            e->loaded = 1;
        }
        FIELD(self, 0x10, s32) = 20;
    case 20: {
        BOOL ok = TRUE;
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            BOOL r;
            if (e->arc != NULL) {
                r = func_02035bd4(e->arc, e->name, 5);
            } else {
                r = func_02035b90(e->name, 5);
            }
            ok = (ok & r) ? TRUE : FALSE;
        }
        if (!ok) {
            break;
        }
        FIELD(self, 0x10, s32)++;
    }
    case 21:
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->arc != NULL) {
                void *p = func_02035f30(e->arc, e->name, 5);
                u32 *r = (u32 *)func_02034f5c(p, e->name);
                if (r == NULL) {
                    func_02035acc(e->arc, e->name, 5);
                    func_020359fc(e->arc, e->name, 4, 0);
                    e->alt = 1;
                }
                e->res = r;
            } else {
                func_02035cfc(e->name);
            }
        }
        FIELD(self, 0x10, s32)++;
    case 22: {
        BOOL ok = TRUE;
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->alt) {
                ok = (ok & func_02035bd4(e->arc, e->name, 4)) ? TRUE : FALSE;
            }
        }
        if (!ok) {
            break;
        }
        FIELD(self, 0x10, s32)++;
    }
    case 23:
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->alt) {
                void *p = func_02035f30(e->arc, e->name, 4);
                e->res2 = (u32 *)func_02034ec0(p, e->name);
            }
        }
        FIELD(self, 0x10, s32) = 30;
    case 30:
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            char path[32];
            void *tex;
            path[0] = 0;
            STD_CopyLString(path, data_ov002_021f0640, sizeof(path));
            STD_ConcatenateString(path, e->name);
            tex = NNS_G3dGetTex((void *)*ov002_021e534c_res(e));
            if (e->alt) {
                if (e->res2 != NULL) {
                    func_0203ed04(path, *e->res2);
                }
            } else {
                if (e->res != NULL) {
                    func_0203ed04(path, *e->res);
                }
            }
            NNS_G3dBindMdlTex(FIELD(self, 0x60, void *), tex);
            NNS_G3dBindMdlPltt(FIELD(self, 0x60, void *), tex);
            e->task = func_0203ebf8();
        }
        FIELD(self, 0x10, s32)++;
    case 31: {
        BOOL ok = TRUE;
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            if (!func_0203e63c((void *)((Ent021e534c *)((u8 *)self + 0xc0))[i].task)) {
                ok = FALSE;
                break;
            }
        }
        if (ok) {
            FIELD(self, 0x10, s32)++;
        }
        break;
    }
    case 32:
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->task != 0) {
                func_02039494(*(e->alt ? e->res2 : e->res));
            }
            e->task = 0;
        }
        FIELD(self, 0x10, s32) = 0x28;
    case 0x28:
        done = TRUE;
        break;
    default:
        FIELD(self, 0x10, s32) = 0x28;
        break;
    }
    return done;
}
}
