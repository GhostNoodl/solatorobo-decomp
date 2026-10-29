#include "types.h"
#include "nitro/std.h"

typedef struct {
    u8 pad[0x12];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 10;
    u16 b12 : 2;
    u16 b14 : 2;
} Info021b4adc;

typedef struct {
    u8 b0 : 5;
    u8 b5 : 1;
    u8 b6 : 2;
} Flags021b4adc;

typedef struct {
    u16 unk_00;
    u8 unk_02;
    u8 b0 : 5;
    u8 b5 : 1;
    u8 b6 : 2;
    u8 pad[0xfc];
    char name0[0x20];
    char name1[0x20];
} Obj021b4adc;

typedef struct {
    u8 pad[0x18];
    u8 cur : 4;
    u8 prev : 4;
} St021b4adc;

typedef struct {
    u8 pad[0xe];
    u16 id;
    u8 pad10[0x24];
    Obj021b4adc *obj;
    u8 pad38[4];
    St021b4adc *st;
    u8 pad40[0x6c];
    Flags021b4adc *flags;
} Self021b4adc;

extern "C" {

Info021b4adc *func_0206fef8(u16 id);
Flags021b4adc *func_020705fc(u16 id);
void *func_0207011c(u16 id);
char *func_0207005c(u16 id, s32 idx);
void *func_0203dd9c(u32 size);
Obj021b4adc *func_ov000_0218e9c4(void *p);
St021b4adc *func_ov000_021919c8(void *p);
void func_ov000_0218f074(Obj021b4adc *o, void *a, BOOL b, BOOL c, s32 d, BOOL e);
void func_ov000_02191b70(St021b4adc *s);

static inline void SetState(St021b4adc *s, s32 n) {
    s->prev = s->cur;
    s->cur = n;
}

void func_ov000_021b4adc(Self021b4adc *self) {
    Info021b4adc *info;
    void *res;
    char *s0;
    char *s1;
    Obj021b4adc *o;
    void *p;
    info = func_0206fef8(self->id);
    self->flags = func_020705fc(self->id);
    res = func_0207011c(self->id);
    p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    self->obj = (Obj021b4adc *)p;
    {
        BOOL f0 = info->b0 ? TRUE : FALSE;
        BOOL f1 = info->b1 ? TRUE : FALSE;
        BOOL f5 = self->flags->b5 ? TRUE : FALSE;
        func_ov000_0218f074(self->obj, res, f0, f1, 0, f5);
    }
    s0 = func_0207005c(self->id, 0);
    s1 = func_0207005c(self->id, 1);
    if (s0 != NULL && s1 != NULL) {
        o = self->obj;
        STD_CopyString(o->name0, s0);
        STD_CopyString(o->name1, s1);
        o->b5 = 1;
    }
    self->obj->unk_00 = 0;
    if (info->b12 == 0) {
        return;
    }
    p = func_0203dd9c(0x1c);
    if (p != NULL) {
        p = func_ov000_021919c8(p);
    }
    self->st = (St021b4adc *)p;
    if (info->b14 == 0) {
        SetState(self->st, 1);
    } else {
        SetState(self->st, 0);
    }
    func_ov000_02191b70(self->st);
}

}
