#include "ov015/ov015.h"
#include "nitro/std.h"

extern "C" {


static inline void Ov015Anim_SetA(Ov015Anim *n, const char *a, const char *b) {
    STD_CopyString(n->mdlDir, a);
    STD_CopyString(n->mdlName, b);
    n->ownMdl = 1;
}

static inline void Ov015Anim_SetAnm(Ov015Anim *n, const char *a, const char *b) {
    STD_CopyString(n->anmDir, a);
    STD_CopyString(n->anmName, b);
    n->ownAnm = 1;
}

extern char data_ov015_02212dd9[];
extern char data_ov015_02212def[];
extern char data_ov015_02212df5[];
extern char *data_ov015_02212db0[];

BOOL func_ov015_0220df48(u8 *self) {
    Ov015Anim *n1 = (Ov015Anim *)(self + 0x4c);
    Ov015Anim *n2 = (Ov015Anim *)(self + 0x26c);
    {
        const char *a = data_ov015_02212dd9;
        if (a) {
            Ov015Anim_SetA(n1, a, FLD(char *, self, 0x514));
            const char *d = data_ov015_02212def;
            if (d) {
                Ov015Anim_SetAnm(n1, a, d);
            }
        }
    }
    {
        const char *a = data_ov015_02212df5;
        if (a) {
            Ov015Anim_SetA(n2, a, FLD(char *, self, 0x510));
            Ov015Anim_SetAnm(n2, a, data_ov015_02212db0[3]);
        }
    }
    n1->unk_00 = 0;
    n2->unk_00 = 0;
    return TRUE;
}

}
