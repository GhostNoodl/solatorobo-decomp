#include "types.h"
#include "nitro/std.h"

typedef struct {
    u16 bit0 : 1;
    u16 bit1 : 1;
} ResFlags02193e5c;

typedef struct {
    u8 unk_00[0x12];
    ResFlags02193e5c flags;
} ResInfo02193e5c;

typedef struct {
    u16 unk_0 : 3;
    u16 bit3 : 1;
} ResFlags1a02193e5c;

typedef struct {
    u8 unk_00[0x1a];
    ResFlags1a02193e5c flags;
    char *path;
} ResParam02193e5c;

typedef struct {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[0xc];
    char unk_10[0x20];
    char unk_30[0x1c];
    char unk_4c[0x20];
    char unk_6c[0x1c];
    char unk_88[0x20];
    char unk_a8[0x1c];
    char unk_c4[0x20];
    char unk_e4[0x1c];
    char unk_100[0x20];
    char unk_120[0x20];
} Res02193e5c;

extern "C" {

extern char data_ov000_021cc454[];
ResInfo02193e5c *func_0206fef8(s32 id);
ResParam02193e5c *func_020704b4(s32 id);
char *func_0207011c(s32 id);
char *func_020701d4(s32 id);
char *func_0207005c(s32 id, s32 n);
char *func_02039674(const char *path);
void func_ov000_0218f074(Res02193e5c *p, char *name, s32 a, s32 b, s32 c, s32 d);

void func_ov000_02193e5c(Res02193e5c *res, s32 id) {
    ResParam02193e5c *param;
    ResInfo02193e5c *info;
    char *name;
    char *a;
    char *b;
    info = func_0206fef8(id);
    param = func_020704b4(id);
    if (!info->flags.bit0 && !info->flags.bit1 && !param->flags.bit3) {
        return;
    }
    name = func_0207011c(id);
    if (param->path != NULL) {
        char *alt;
        if (STD_SearchString(param->path, data_ov000_021cc454) != NULL) {
            alt = func_02039674(param->path);
            STD_CopyString(res->unk_c4, param->path);
            STD_CopyString(res->unk_e4, alt);
            res->unk_03 |= 0x10;
        } else {
            alt = param->path;
            STD_CopyString(res->unk_c4, name);
            STD_CopyString(res->unk_e4, alt);
            res->unk_03 |= 0x10;
        }
        alt = func_020701d4(id);
        if (info->flags.bit0) {
            STD_CopyString(res->unk_10, name);
            STD_CopyString(res->unk_30, alt);
            res->unk_03 |= 2;
        }
        if (info->flags.bit1) {
            STD_CopyString(res->unk_4c, name);
            STD_CopyString(res->unk_6c, alt);
            res->unk_03 |= 4;
        }
        if (param->flags.bit3) {
            STD_CopyString(res->unk_88, name);
            STD_CopyString(res->unk_a8, alt);
            res->unk_03 |= 8;
        }
    } else {
        func_ov000_0218f074(res, name, info->flags.bit0 != 0, info->flags.bit1 != 0, 0, param->flags.bit3 != 0);
    }
    a = func_0207005c(id, 0);
    b = func_0207005c(id, 1);
    if (a != NULL && b != NULL) {
        STD_CopyString(res->unk_100, a);
        STD_CopyString(res->unk_120, b);
        res->unk_03 |= 0x20;
    }
    res->unk_00 = 0;
}

}
