#include "types.h"

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02_0 : 3;
    u16 unk_02_3 : 1;
} Ov003PropDef;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0xe];
    u16 unk_0e;
    u8 unk_10[0x10];
    u16 unk_20;
    u8 unk_22[0x8e];
    Ov003PropDef *unk_b0;
    u8 unk_b4[0x1c];
    s16 unk_d0;
    u8 unk_d2;
    u8 unk_d3;
    u8 unk_d4[0x84];
    char unk_158[0x20];
    char unk_178[0x20];
} Ov003Prop;

extern BOOL func_ov000_021946f8(void *self);
extern void *data_ov000_021ccd64;
extern char data_ov003_021f857a[];
extern void func_ov000_0219433c(void *self);
extern char *func_0207011c(u16 id);
extern char *func_02039674(char *p);
extern void func_0201e520(char *dst, const char *src);
extern void func_0201e78c(char *dst, const char *s);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021e2a44(Ov003Prop *self) {
    Ov003PropDef *def;
    Ov003Unit *u;
    func_ov000_0219433c(self);
    def = self->unk_b0;
    if (def->unk_02_3 && def->unk_01 == 1) {
        char buf[0x18];
        char *name = func_0207011c(self->unk_0e);
        func_0201e520(buf, func_02039674(name));
        func_0201e78c(buf, data_ov003_021f857a);
        func_0201e520(self->unk_158, name);
        func_0201e520(self->unk_178, buf);
        self->unk_d3 |= 8;
        self->unk_d0 = 0;
    }
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

extern BOOL func_ov000_0218f110(s16 *p);

BOOL func_ov003_021e2afc(Ov003Prop *self) {
    BOOL r = func_ov000_021946f8(self);
    Ov003PropDef *def = self->unk_b0;
    if (def->unk_02_3 && def->unk_01 == 1 && self->unk_d0 >= 0) {
        if (!func_ov000_0218f110(&self->unk_d0)) {
            r = FALSE;
        }
    }
    return r;
}
