#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_0221729c[];
extern char data_ov009_022172a7[];

void Ov009ActVt_02217844_Init(Ov009ActVt_02217844 *self) {
    Ov003Actor_Init(self);
    {
        const char *a = data_ov009_0221729c;
        const char *b = data_ov009_022172a7;
        Ov009Names *n = &self->anim;
        if (a) {
            STD_CopyString(n->mdlDir, a);
            STD_CopyString(n->mdlName, b);
            n->ownMdl = 1;
            STD_CopyString(n->anmDir, a);
            STD_CopyString(n->anmName, b);
            n->ownAnm = 1;
        }
        n->unk_00 = 0;
    }
}

}
