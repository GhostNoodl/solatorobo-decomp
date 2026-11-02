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

static inline void Ov015Anim_SetD(Ov015Anim *n, const char *a, const char *b) {
    STD_CopyString(n->evDir, a);
    STD_CopyString(n->evName, b);
    n->ownEv = 1;
}

extern char data_ov015_02212dce[];
extern char data_ov015_02212dd9[];
extern char data_ov015_02212def[];
extern char data_ov015_02212df5[];
extern char *data_ov015_02212db0[];
char *func_0207011c(u16 id);
void Shadow_Load(void *p);

void func_ov015_02209364(Ov015Fish *self) {
    Ov015Anim *n1 = (Ov015Anim *)&self->res;
    Ov015Anim *n2 = (Ov015Anim *)&self->res2;
    {
        const char *a = data_ov015_02212dd9;
        const char *b = data_ov015_02212dce;
        if (a) {
            Ov015Anim_SetA(n1, a, b);
            {
                const char *d = data_ov015_02212def;
                if (d) {
                    Ov015Anim_SetAnm(n1, a, d);
                    Ov015Anim_SetD(n1, a, d);
                }
            }
        }
    }
    {
        char *c = func_0207011c(self->info.id);
        const char *a = data_ov015_02212df5;
        if (a) {
            Ov015Anim_SetA(n2, a, c);
            Ov015Anim_SetAnm(n2, a, data_ov015_02212db0[3]);
        }
    }
    n1->unk_00 = 0;
    n2->unk_00 = 0;
    Shadow_Load(&self->shadow);
}

}
