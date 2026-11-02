#include "ov015/ov015.h"
#include "nitro/std.h"

extern "C" {

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
void *ResSet_Init(void *p);
void *Model0218fe1c_Init(void *p);

static inline Model *Ov015_NewTex(void) {
    Model *t = (Model *)Heap_Alloc(0x160);
    if (t != NULL) {
        PlttRes_Init_02041218(&t->pltt);
        TexObj_Init(t, (char *)NULL, 0);
    }
    return t;
}

BOOL func_ov015_02201344(Ov015Game *self) {
    Ov015Ship *s;
    Ov015MdlSet *o;
    Ov015Hud *q;
    s = (Ov015Ship *)Heap_Alloc(0xd58);
    if (s != NULL) {
        s = (Ov015Ship *)func_ov015_0220765c(s);
    }
    self->ship = s;
    func_ov015_02207858(s);
    self->ship->modelIdx = data_ov015_02213368->unk_2c;
    o = (Ov015MdlSet *)Heap_Alloc(sizeof(Ov015MdlSet));
    if (o != NULL) {
        SET_VT(o, data_ov015_0221294c);
        ResSet_Init(&o->p[0].res);
        Model0218fe1c_Init(&o->p[0].mdl);
        ResSet_Init(&o->p[1].res);
        Model0218fe1c_Init(&o->p[1].mdl);
        ResSet_Init(&o->p[2].res);
        Model0218fe1c_Init(&o->p[2].mdl);
    }
    self->unk_20 = o;
    {
        Ov015MdlSet *s = o;
        {
            const char *b = data_ov015_02212830;
            const char *a = data_ov015_0221283b;
            if (a) {
                STD_CopyString(s->p[0].res.mdlDir, a);
                STD_CopyString(s->p[0].res.mdlName, b);
                s->p[0].res.ownMdl = 1;
                {
                    const char *c = data_ov015_02212851;
                    if (c) {
                        STD_CopyString(s->p[0].res.anmDir, a);
                        STD_CopyString(s->p[0].res.anmName, c);
                        s->p[0].res.ownAnm = 1;
                    }
                }
            }
        }
        s->p[0].res.unk_00 = 0;
        {
            const char *b = data_ov015_02212857;
            const char *a = data_ov015_02212862;
            if (a) {
                STD_CopyString(s->p[1].res.mdlDir, a);
                STD_CopyString(s->p[1].res.mdlName, b);
                s->p[1].res.ownMdl = 1;
                {
                    const char *c = data_ov015_02212851;
                    if (c) {
                        STD_CopyString(s->p[1].res.anmDir, a);
                        STD_CopyString(s->p[1].res.anmName, c);
                        s->p[1].res.ownAnm = 1;
                    }
                }
            }
        }
        s->p[1].res.unk_00 = 0;
        {
            const char *b = data_ov015_02212878;
            const char *a = data_ov015_02212883;
            if (a) {
                STD_CopyString(s->p[2].res.mdlDir, a);
                STD_CopyString(s->p[2].res.mdlName, b);
                s->p[2].res.ownMdl = 1;
                {
                    const char *c = data_ov015_02212851;
                    if (c) {
                        STD_CopyString(s->p[2].res.anmDir, a);
                        STD_CopyString(s->p[2].res.anmName, c);
                        s->p[2].res.ownAnm = 1;
                    }
                }
            }
        }
        s->p[2].res.unk_00 = 0;
    }
    q = (Ov015Hud *)Heap_Alloc(0x30);
    if (q != NULL) {
        SET_VT(q, data_ov015_0221293c);
        q->unk_04 = 0;
        q->frame = 0;
        q->unk_0c = 0;
        q->unk_10 = 3;
        q->unk_14 = 1;
        q->unk_1c = 0;
        q->unk_20 = 0x28;
        q->mdl0 = NULL;
        q->mdl1 = NULL;
        q->unk_2c = 0;
    }
    self->hud = q;
    q->mdl0 = Ov015_NewTex();
    q->mdl1 = Ov015_NewTex();
    {
        Ov015Result *f = (Ov015Result *)Heap_Alloc(sizeof(Ov015Result));
        if (f != NULL) {
            f = Ov015Result_Ctor(f);
        }
        self->result = f;
        func_ov015_0220f470(f);
    }
    ResMgr_Load(data_ov015_022128c1, 7, 0);
    return TRUE;
}

}
