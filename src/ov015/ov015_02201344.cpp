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
u8 *func_ov015_0220765c(Ov015Ship *p);
void func_ov015_02207858(Ov015Ship *p);
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218fe1c(void *p);
void *Ov015Result_Ctor(void *p);
void func_ov015_0220f470(void *p);

static inline void *Ov015_NewTex(void) {
    u8 *t = (u8 *)Heap_Alloc(0x160);
    if (t != NULL) {
        func_02041218((PlttRes *)(t + 0x88));
        func_02041440((Model *)t, (char *)NULL, 0);
    }
    return t;
}

BOOL func_ov015_02201344(Ov015Game *self) {
    Ov015Ship *s;
    u8 *o;
    u8 *q;
    s = (Ov015Ship *)Heap_Alloc(0xd58);
    if (s != NULL) {
        s = (Ov015Ship *)func_ov015_0220765c(s);
    }
    self->unk_18 = s;
    func_ov015_02207858(s);
    self->unk_18->unk_d48 = data_ov015_02213368->unk_2c;
    o = (u8 *)Heap_Alloc(0x664);
    if (o != NULL) {
        SET_VT(o, data_ov015_0221294c);
        func_ov000_0218e9c4(o + 0x4);
        func_ov000_0218fe1c(o + 0x13c);
        func_ov000_0218e9c4(o + 0x224);
        func_ov000_0218fe1c(o + 0x35c);
        func_ov000_0218e9c4(o + 0x444);
        func_ov000_0218fe1c(o + 0x57c);
    }
    self->unk_20 = o;
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
    q = (u8 *)Heap_Alloc(0x30);
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
    self->unk_28 = q;
    FLD(void *, q, 0x24) = Ov015_NewTex();
    FLD(void *, q, 0x28) = Ov015_NewTex();
    {
        void *f = Heap_Alloc(0x14);
        if (f != NULL) {
            f = Ov015Result_Ctor(f);
        }
        self->unk_2c = (u8 *)f;
        func_ov015_0220f470(f);
    }
    func_020359d0(data_ov015_022128c1, 7, 0);
    return TRUE;
}

}
