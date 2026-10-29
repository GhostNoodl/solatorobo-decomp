#include "ov015/ov015.h"
#include "nitro/std.h"

extern "C" {


struct Ov015Names {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03_0 : 1;
    u8 unk_03_1 : 1;
    u8 unk_03_2 : 1;
    u8 unk_03_3 : 1;
    u8 unk_03_4 : 1;
    u8 unk_03_5 : 3;
    u8 unk_04[0xc];
    char unk_10[0x20];
    char unk_30[0x1c];
    char unk_4c[0x20];
    char unk_6c[0x58];
    char unk_c4[0x20];
    char unk_e4[0x20];
};

static inline void Ov015Names_SetA(Ov015Names *n, const char *a, const char *b) {
    STD_CopyString(n->unk_10, a);
    STD_CopyString(n->unk_30, b);
    n->unk_03_1 = 1;
}

static inline void Ov015Names_SetB(Ov015Names *n, const char *a, const char *b) {
    STD_CopyString(n->unk_4c, a);
    STD_CopyString(n->unk_6c, b);
    n->unk_03_2 = 1;
}

static inline void Ov015Names_SetD(Ov015Names *n, const char *a, const char *b) {
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

void func_ov015_02209364(u8 *self) {
    Ov015Names *n1 = (Ov015Names *)(self + 0x10c);
    Ov015Names *n2 = (Ov015Names *)(self + 0x32c);
    {
        const char *a = data_ov015_02212dd9;
        const char *b = data_ov015_02212dce;
        if (a) {
            Ov015Names_SetA(n1, a, b);
            {
                const char *d = data_ov015_02212def;
                if (d) {
                    Ov015Names_SetB(n1, a, d);
                    Ov015Names_SetD(n1, a, d);
                }
            }
        }
    }
    {
        char *c = func_0207011c(FLD(u16, self, 0xc4));
        const char *a = data_ov015_02212df5;
        if (a) {
            Ov015Names_SetA(n2, a, c);
            Ov015Names_SetB(n2, a, data_ov015_02212db0[3]);
        }
    }
    n1->unk_00 = 0;
    n2->unk_00 = 0;
    func_ov000_02191b70(self + 0x54c);
}

}
