#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0xa];
    s16 unk_0a;
    s16 unk_0c;
    s16 unk_0e;
    s16 unk_10;
    s16 unk_12;
} Obj021c95ac;

extern "C" {

void MI_CpuFill8(void *dst, s32 val, u32 size);
s8 *func_0206ef10(u16 a);

typedef struct Node021c9544 {
    u8 unk_00[0x48];
    u16 unk_48;
    u8 unk_4a;
    u8 unk_4b[0x21];
    u8 unk_6c;
    u8 unk_6d[3];
    struct Node021c9544 *next;
} Node021c9544;

u8 *func_0206ede8(u16 id);

void func_ov000_021c9544(s16 *out, Node021c9544 *n) {
    MI_CpuFill8(out, 0, 10);
    for (; n != NULL; n = n->next) {
        if (n->unk_4a != 2 && n->unk_6c == 0) {
            u8 *p = func_0206ede8(n->unk_48);
            out[p[0]] += p[2];
        }
    }
}

static inline void Obj021c95ac_Init(Obj021c95ac *self, u16 a) {
    s8 *p;
    MI_CpuFill8(&self->unk_0a, 0, 10);
    p = func_0206ef10(a);
    self->unk_0a = p[0];
    self->unk_0c = p[1];
    self->unk_0e = p[2];
    self->unk_10 = p[3];
    self->unk_12 = 0;
}

static inline void Obj021c95ac_InitKind(Obj021c95ac *self, u32 kind) {
    s8 *p;
    MI_CpuFill8(&self->unk_0a, 0, 10);
    p = func_0206ef10(kind | 0x8000);
    self->unk_0a = p[0];
    self->unk_0c = p[1];
    self->unk_0e = p[2];
    self->unk_10 = p[3];
    self->unk_12 = 0;
}

void func_ov000_021c95ac(Obj021c95ac *self, u16 a) {
    Obj021c95ac_Init(self, a);
}

typedef struct {
    u16 id;
    u16 flags_0 : 8;
    u16 flags_8 : 1;
    u16 flags_9 : 7;
} Slot021c95fc;

typedef struct {
    u8 unk_00[0x18];
    u16 unk_18_0 : 1;
    u16 unk_18_1 : 2;
    u16 unk_18_3 : 4;
    u16 unk_18_7 : 9;
    u8 unk_1a[0x74];
    Slot021c95fc slots[0x25];
} Data0214a424;

extern Data0214a424 *data_0214a424;

void func_ov000_021c95fc(s16 *out) {
    s32 i;
    Slot021c95fc *slots;
    MI_CpuFill8(out, 0, 0x14);
    slots = data_0214a424->slots;
    for (i = 0; i < 0x25; i++) {
        if (slots[i].id != 0xffff && !slots[i].flags_8) {
            u8 *p = func_0206ede8(slots[i].id);
            if (p[0] < 5) {
                out[p[0]] += p[2];
            }
        }
    }
    if (data_0214a424->unk_18_1 == 1) {
        Obj021c95ac_InitKind((Obj021c95ac *)out, data_0214a424->unk_18_3);
    }
}

}
