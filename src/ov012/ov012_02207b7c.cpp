#include "ov012/ov012.h"

extern "C" {

extern char data_ov012_0220b324[];
extern char data_ov012_0220b32e[];

void Ov012Names_Fill(Ov012Names *self, u16 kind) {
    char *a = func_0207011c(kind);
    char *b = func_020701d4(kind);
    TblActorParam *c = func_02070558(kind);
    char *t;
    STD_CopyString(self->mdlDir, a);
    STD_CopyString(self->mdlName, b);
    self->ownMdl = 1;
    {
        const char *s = data_ov012_0220b324;
        const char *u = data_ov012_0220b32e;
        if (s) {
            STD_CopyString(self->anmDir, s);
            STD_CopyString(self->anmName, u);
            self->ownAnm = 1;
            t = c->evName;
            if (t != NULL) {
                STD_CopyString(self->evDir, s);
                STD_CopyString(self->evName, t);
                self->ownEv = 1;
            }
        }
    }
    self->unk_00 = 0;
}

}
