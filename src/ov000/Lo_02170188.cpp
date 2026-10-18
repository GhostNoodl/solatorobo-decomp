#include "ov000/VObj.h"

typedef struct {
    u8 pad[4];
    u32 flags;
    u8 pad08[0x20];
    s32 unk_28;
    u8 pad2c[0x8c];
    u32 b0 : 4;
    u32 rest : 28;
    u8 padbc[0xb70 - 0xbc];
    s32 unk_b70;
    void *unk_b74;
    u8 padb78[4];
    s32 unk_b7c;
} Ent02170188;

typedef struct {
    u8 pad[0x24];
    s32 state;
    Ent02170188 *ent;
} Obj02170188;

typedef struct {
    u8 pad[0x98];
    s32 mode;
} Player02170188;

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Flag02170188;

extern "C" {

extern Player02170188 *data_ov000_021ccd54;
extern void *data_0214a420;
extern Flag02170188 *data_ov000_021ccd70;
extern u8 data_0208ba70[];
extern u8 data_0208bbc8[];
BOOL func_ov000_02184498(Player02170188 *p);
BOOL func_020658cc(void *a, s32 id);
void *func_0204c08c(s32 a, u16 b, s32 *out, s32 c);
void *func_0203dd9c(u32 size);
void func_0204c7d0(void *p);
void func_02050f70(void *p);

static inline void Ent_Init(Ent02170188 *e, s32 out, void *res) {
    e->unk_b7c = out;
    e->unk_b70 = 0;
    e->unk_b74 = res;
}

static inline BOOL IsFlag(void) {
    return data_ov000_021ccd70->b0 == 1 ? TRUE : FALSE;
}

BOOL func_ov000_02170188(Obj02170188 *self, s32 a, u32 arg) {
    Player02170188 *p;
    s32 out;
    u16 hi;
    void *res;
    Ent02170188 *e;
    p = data_ov000_021ccd54;
    if ((u32)(p->mode - 0x11) > 2) {
        return FALSE;
    }
    if (self->state != 3) {
        return FALSE;
    }
    if (self->ent != NULL) {
        return FALSE;
    }
    if (!func_ov000_02184498(p)) {
        return FALSE;
    }
    if (func_020658cc(data_0214a420, 0x2712) || func_020658cc(data_0214a420, 0x2713) || func_020658cc(data_0214a420, 0x191)) {
        return FALSE;
    }
    if (IsFlag()) {
        return FALSE;
    }
    hi = arg >> 16;
    res = func_0204c08c(a, arg, &out, 1);
    e = (Ent02170188 *)func_0203dd9c(0xb80);
    if (e != NULL) {
        VOBJ_SET_VTABLE(e, data_0208ba70);
        func_0204c7d0(e);
        VOBJ_SET_VTABLE(e, data_0208bbc8);
        func_02050f70(e);
    }
    self->ent = e;
    e->unk_28 = 8;
    Ent_Init(self->ent, out, res);
    self->ent->b0 = hi & 0xf;
    self->ent->flags |= 4;
    self->state = 4;
    return TRUE;
}

}
