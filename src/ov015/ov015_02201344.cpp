#include "ov015/ov015.h"
#include "nitro/std.h"

struct Ov015Mdl {
    u16 unk_00;
    u8 unk_02;
    u8 flags;
    u8 unk_04[0xc];
    char mdlDir[0x20];
    char mdlName[0x1c];
    char anmDir[0x20];
    char anmName[0xcc];
};

struct Ov015MdlPair {
    Ov015Mdl mdl;
    u8 anm[0xe8];
};

struct Ov015MdlSet {
    void *vt;
    Ov015MdlPair p[3];
};

extern "C" {

extern Ov015Shared *data_ov015_02213368;
extern u8 data_ov015_0221294c[];
extern u8 data_ov015_0221293c[];
extern char data_ov015_0221283b[];
extern char data_ov015_02212830[];
extern char data_ov015_02212851[];
extern char data_ov015_02212862[];
extern char data_ov015_02212857[];
extern char data_ov015_02212883[];
extern char data_ov015_02212878[];
extern char data_ov015_022128c1[];
u8 *func_ov015_0220765c(void *p);
void func_ov015_02207858(u8 *p);
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218fe1c(void *p);
void func_02041218(void *p);
void func_02041440(void *p, void *name, int c);
void *func_ov015_0220f448(void *p);
void func_ov015_0220f470(void *p);
void *func_020359d0(void *a, int b, int c);

static inline void *Ov015_NewTex(void) {
    u8 *t = (u8 *)func_0203dd9c(0x160);
    if (t != NULL) {
        func_02041218(t + 0x88);
        func_02041440(t, NULL, 0);
    }
    return t;
}

BOOL func_ov015_02201344(u8 *self) {
    u8 *o;
    u8 *q;
    o = (u8 *)func_0203dd9c(0xd58);
    if (o != NULL) {
        o = func_ov015_0220765c(o);
    }
    FLD(u8 *, self, 0x18) = o;
    func_ov015_02207858(o);
    FLD(u16, FLD(u8 *, self, 0x18), 0xd48) = data_ov015_02213368->unk_2c;
    o = (u8 *)func_0203dd9c(0x664);
    if (o != NULL) {
        SET_VT(o, data_ov015_0221294c);
        func_ov000_0218e9c4(o + 0x4);
        func_ov000_0218fe1c(o + 0x13c);
        func_ov000_0218e9c4(o + 0x224);
        func_ov000_0218fe1c(o + 0x35c);
        func_ov000_0218e9c4(o + 0x444);
        func_ov000_0218fe1c(o + 0x57c);
    }
    FLD(u8 *, self, 0x20) = o;
    {
        Ov015MdlSet *s = (Ov015MdlSet *)o;
        {
            const char *b = data_ov015_02212830;
            const char *a = data_ov015_0221283b;
            if (a) {
                STD_CopyString(s->p[0].mdl.mdlDir, a);
                STD_CopyString(s->p[0].mdl.mdlName, b);
                s->p[0].mdl.flags |= 2;
                {
                    const char *c = data_ov015_02212851;
                    if (c) {
                        STD_CopyString(s->p[0].mdl.anmDir, a);
                        STD_CopyString(s->p[0].mdl.anmName, c);
                        s->p[0].mdl.flags |= 4;
                    }
                }
            }
        }
        s->p[0].mdl.unk_00 = 0;
        {
            const char *b = data_ov015_02212857;
            const char *a = data_ov015_02212862;
            if (a) {
                STD_CopyString(s->p[1].mdl.mdlDir, a);
                STD_CopyString(s->p[1].mdl.mdlName, b);
                s->p[1].mdl.flags |= 2;
                {
                    const char *c = data_ov015_02212851;
                    if (c) {
                        STD_CopyString(s->p[1].mdl.anmDir, a);
                        STD_CopyString(s->p[1].mdl.anmName, c);
                        s->p[1].mdl.flags |= 4;
                    }
                }
            }
        }
        s->p[1].mdl.unk_00 = 0;
        {
            const char *b = data_ov015_02212878;
            const char *a = data_ov015_02212883;
            if (a) {
                STD_CopyString(s->p[2].mdl.mdlDir, a);
                STD_CopyString(s->p[2].mdl.mdlName, b);
                s->p[2].mdl.flags |= 2;
                {
                    const char *c = data_ov015_02212851;
                    if (c) {
                        STD_CopyString(s->p[2].mdl.anmDir, a);
                        STD_CopyString(s->p[2].mdl.anmName, c);
                        s->p[2].mdl.flags |= 4;
                    }
                }
            }
        }
        s->p[2].mdl.unk_00 = 0;
    }
    q = (u8 *)func_0203dd9c(0x30);
    if (q != NULL) {
        SET_VT(q, data_ov015_0221293c);
        FLD(s32, q, 0x4) = 0;
        FLD(s32, q, 0x8) = 0;
        FLD(s32, q, 0xc) = 0;
        FLD(s32, q, 0x10) = 3;
        FLD(s32, q, 0x14) = 1;
        FLD(s32, q, 0x1c) = 0;
        FLD(s32, q, 0x20) = 0x28;
        FLD(s32, q, 0x24) = 0;
        FLD(s32, q, 0x28) = 0;
        FLD(s32, q, 0x2c) = 0;
    }
    FLD(u8 *, self, 0x28) = q;
    FLD(void *, q, 0x24) = Ov015_NewTex();
    FLD(void *, q, 0x28) = Ov015_NewTex();
    {
        void *f = func_0203dd9c(0x14);
        if (f != NULL) {
            f = func_ov015_0220f448(f);
        }
        FLD(void *, self, 0x2c) = f;
        func_ov015_0220f470(f);
    }
    func_020359d0(data_ov015_022128c1, 7, 0);
    return TRUE;
}

}
