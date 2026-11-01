#include "ov015/ov015.h"
#include "nitro/std.h"

extern "C" {


static inline void Ov015Anim_SetA(Ov015Anim *n, const char *a, const char *b) {
    STD_CopyString(n->unk_10, a);
    STD_CopyString(n->unk_30, b);
    n->unk_03_1 = 1;
}

static inline void Ov015Anim_SetB(Ov015Anim *n, const char *a, const char *b) {
    STD_CopyString(n->unk_4c, a);
    STD_CopyString(n->unk_6c, b);
    n->unk_03_2 = 1;
}

static inline void Ov015Anim_SetD(Ov015Anim *n, const char *a, const char *b) {
    STD_CopyString(n->unk_c4, a);
    STD_CopyString(n->unk_e4, b);
    n->unk_03_4 = 1;
}

extern char data_ov015_02212dce[];
extern char data_ov015_02212dd9[];
extern char data_ov015_02212def[];
extern char data_ov015_02212df5[];
extern char *data_ov015_02212db0[];
char *func_0207011c(u16 id);
void func_ov000_02191b70(void *p);

void func_ov015_02209364(Ov015Fish *self) {
    Ov015Anim *n1 = (Ov015Anim *)&self->unk_10c;
    Ov015Anim *n2 = (Ov015Anim *)&self->unk_32c;
    {
        const char *a = data_ov015_02212dd9;
        const char *b = data_ov015_02212dce;
        if (a) {
            Ov015Anim_SetA(n1, a, b);
            {
                const char *d = data_ov015_02212def;
                if (d) {
                    Ov015Anim_SetB(n1, a, d);
                    Ov015Anim_SetD(n1, a, d);
                }
            }
        }
    }
    {
        char *c = func_0207011c(self->unk_c0.unk_04);
        const char *a = data_ov015_02212df5;
        if (a) {
            Ov015Anim_SetA(n2, a, c);
            Ov015Anim_SetB(n2, a, data_ov015_02212db0[3]);
        }
    }
    n1->unk_00 = 0;
    n2->unk_00 = 0;
    func_ov000_02191b70(&self->unk_54c);
}

}
