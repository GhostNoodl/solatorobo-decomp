#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217dc0[];
extern char data_ov014_02217d8e[];
extern char data_ov014_02217d95[];
extern void func_ov000_0218e9c4(void *p);
extern void func_ov000_0218fe1c(void *p);
extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ea20(void *p);
extern void MIi_CpuClearFast(s32 v, void *p, u32 n);
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern s32 func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);

BOOL func_ov014_02212780(Ov014Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0xf0) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0xf0)) ? TRUE : FALSE;
    }
    return r;
}

BOOL func_ov014_022127b8(Ov014Actor *self) {
    return func_ov003_021d16cc(self);
}

extern char data_ov014_02217d9f[];
extern char data_ov014_02217da0[];
extern s32 func_ov000_021909a8(void *m, const char *a, const char *b);
extern void MTX_Identity43_(void *m);
extern void NNS_G3dRenderObjSetInitFunc(void *obj, void *fn);
extern void func_ov014_0220f8e4(u8 *self);

void func_ov014_022127c4(Ov014Actor *self) {
    Ov014Sub38 *m;
    func_ov003_021d112c(self);
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_3c != NULL) {
            Ov014V *v = self->unk_3c;
            if (v != NULL) {
                v->v04();
            }
            self->unk_3c = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->unk_48->unk_30 = 0;
    {
        Ov014Sub48 *q = self->unk_48;
        q->unk_9a_1 = 0;
        q->unk_9a_4 = 0;
    }
    {
        Ov014Sub48 *q = self->unk_48;
        q->unk_9a_2 = 0;
        q->unk_9a_5 = 0;
    }
    {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    FLD(s32, self, 0x314) = func_ov000_021909a8(self->unk_38, data_ov014_02217d9f, data_ov014_02217da0);
    MTX_Identity43_((u8 *)self + 0x318);
    m = self->unk_38;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)func_ov014_0220f8e4);
    m->unk_c2_5 = 0;
    self->unk_38->unk_c2_8 = 1;
    self->unk_38->unk_50 = &FLD(u8, self, 0x314);
    FLD(u8, self->unk_38, 0xbe) = 0;
    FLD(Ov014Flags, self->unk_38, 0xc2).b4 = 0;
}

}
