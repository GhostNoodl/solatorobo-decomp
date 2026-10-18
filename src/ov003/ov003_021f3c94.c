#include "types.h"

typedef struct {
    const char *name0;
    const char *name1;
    const char *name2;
    const char *name3;
    u8 unk_10[8];
    u8 flag;
} Ov003NameSet;

typedef struct {
    u8 unk_00[0xba0];
    Ov003NameSet *names;
} Ov003NmPlayer;

typedef struct {
    u8 unk_00[0x12];
    u16 unk_12_0 : 12;
    u16 unk_12_c : 2;
} Ov003NmInfo;

typedef struct {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03_0 : 1;
    u8 unk_03_1 : 1;
    u8 unk_03_2 : 1;
    u8 unk_04[0xc];
    char name0[0x20];
    char name1[0x1c];
    char name2[0x20];
    char name3[0x20];
} Ov003NmLabel;

typedef struct {
    u8 unk_00[0x18];
    u16 unk_18_0 : 1;
    u16 unk_18_1 : 2;
    u16 unk_18_3 : 4;
} Ov003NmSave;

typedef struct {
    u8 unk_00[0xe];
    u16 unk_0e;
    u8 unk_10[0x24];
    Ov003NmLabel *label;
    u8 unk_38[4];
    void *unk_3c;
    u8 unk_40[0x6c];
    u32 unk_ac;
    u16 unk_b0;
    u8 unk_b2;
    u8 unk_b3_0 : 1;
    u8 unk_b3_1 : 1;
    u8 unk_b3_2 : 1;
    u8 unk_b4[0x48];
    char name0[0x20];
    char name1[0xcc];
    u8 flag;
    u8 unk_1e9;
    u16 unk_1ea;
    u16 unk_1ec;
} Ov003NmObj;

extern Ov003NmSave *data_0214a424;
extern Ov003NmPlayer *func_ov000_0219bf90(void);
extern Ov003NmInfo *func_0206fef8(u16 id);
extern u32 func_020705fc(u16 id);
extern void *func_0203dd9c(u32 size);
extern Ov003NmLabel *func_ov000_0218e9c4(void *p);
extern void *func_ov000_021919c8(void *p);
extern void func_ov000_02191b70(void *p);
extern void STD_CopyString(char *dst, const char *src);

void func_ov003_021f3c94(Ov003NmObj *self) {
    Ov003NmInfo *info;
    Ov003NameSet *names;
    void *p;
    const char *a;
    const char *b;
    Ov003NmLabel *l;
    names = func_ov000_0219bf90()->names;
    info = func_0206fef8(self->unk_0e);
    self->unk_ac = func_020705fc(self->unk_0e);
    l = (Ov003NmLabel *)func_0203dd9c(0x138);
    if (l != NULL) {
        l = func_ov000_0218e9c4(l);
    }
    self->label = l;
    {
        a = names->name0;
        b = names->name1;
        STD_CopyString(l->name0, a);
        STD_CopyString(l->name1, b);
        l->unk_03_1 = 1;
    }
    l = self->label;
    {
        b = names->name3;
        a = names->name2;
        STD_CopyString(l->name2, a);
        STD_CopyString(l->name3, b);
        l->unk_03_2 = 1;
    }
    self->label->unk_00 = 0;
    if (names->flag) {
        a = names->name0;
        b = names->name1;
        STD_CopyString(self->name0, a);
        STD_CopyString(self->name1, b);
        self->unk_b0 = 0;
        self->unk_b3_2 = 1;
    }
    self->flag = names->flag;
    if (info->unk_12_c) {
        p = func_0203dd9c(0x1c);
        if (p != NULL) {
            p = func_ov000_021919c8(p);
        }
        self->unk_3c = p;
        func_ov000_02191b70(p);
    }
    self->unk_1ea = data_0214a424->unk_18_1;
    self->unk_1ec = data_0214a424->unk_18_3;
}
