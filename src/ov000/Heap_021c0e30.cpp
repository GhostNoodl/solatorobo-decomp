#include "ov000/HeapScope.h"
#include "ov000/Vec.h"
#include "ov000/VObj.h"

typedef void (*VFunc)(void);

typedef struct Ov000Text021c0e30 {
    VFunc *vtbl;
    u32 flags;
    u8 pad08[0x1c];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 pad30[0x4];
    s16 unk_34;
    u8 pad36;
    s8 unk_37;
    s32 unk_38;
    u8 pad3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
} Ov000Text021c0e30;

typedef struct {
    u32 unk_00_0 : 1;
    u32 unk_00_1 : 1;
    u32 unk_00_2 : 1;
    u32 unk_00_3 : 1;
    u32 unk_00_4 : 28;
    u8 pad_04[0x14];
    void *unk_18;
    u8 pad_1c[0xc];
    s32 unk_28;
    u8 pad_2c[0x24];
    VecFx32 unk_50;
    u8 pad_5c[0xc];
    s32 unk_68;
    u8 pad_6c[0x14];
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    void *unk_8c;
    Ov000Text021c0e30 *unk_90;
    u16 unk_94;
    u16 unk_96;
    s32 unk_98;
} Obj021c0e30;

extern "C" {

extern VFunc data_0208ba70[];
extern u8 *data_02097ce0;
void *func_0203dd9c(u32 size);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void *func_0206ffa0(s32 id);
BOOL func_ov000_021bd374(Obj021c0e30 *self, s32 len);
void func_ov000_021bd474(Obj021c0e30 *self, VecFx32 *pos);

static inline BOOL Obj021c0e30_Wait(Obj021c0e30 *self) {
    if (!(self->unk_00_1 == 1 ? TRUE : FALSE) || (self->unk_00_3 == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->unk_68 = 10;
    return FALSE;
}

void func_ov000_021c0e30(Obj021c0e30 *self) {
    VecFx32 pos;
    switch (self->unk_68) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        HEAP_DELETE_VOBJ(self->unk_90);
        return;
    case 1:
        {
            void *model = self->unk_18;
            self->unk_18 = NULL;
            self->unk_8c = model;
        }
        self->unk_94 = 0;
        self->unk_90 = NULL;
        self->unk_68 = 3;
    case 3:
        HEAP_DELETE_VOBJ(self->unk_90);
        self->unk_84 = 0;
        self->unk_88 = 0;
        if (Obj021c0e30_Wait(self)) {
            return;
        }
        self->unk_68 = 2;
    case 2:
        {
            Ov000Text021c0e30 *t;
            void *str;
            self->unk_94 = self->unk_28;
            t = (Ov000Text021c0e30 *)func_0203dd9c(0xb8);
            if (t != NULL) {
                t->vtbl = data_0208ba70;
                func_0204c7d0(t);
            }
            self->unk_90 = t;
            t->unk_28 = 4;
            self->unk_90->unk_2c = 0;
            str = func_0206ffa0(self->unk_94);
            t = self->unk_90;
            t->unk_24 = (s32)str;
            t->unk_4c = func_0204c4fc(t->unk_28, t->unk_38, t->unk_24, &t->unk_44, &t->unk_48, t->unk_37 != 0);
            *(s32 *)(data_02097ce0 + 4) = t->unk_28;
            self->unk_90->flags |= 0x40;
            self->unk_90->flags |= 0x1000000;
            self->unk_90->flags |= 0x40000000;
            self->unk_90->flags |= 4;
            self->unk_98 = self->unk_90->unk_44;
            if (self->unk_98 > 0x28) {
                self->unk_96 = 0;
            } else {
                self->unk_96 = 1;
            }
        }
        self->unk_68 = 4;
    case 4:
        self->unk_84 = 0;
        self->unk_88 = 0;
        if (Obj021c0e30_Wait(self)) {
            self->unk_68 = 3;
            return;
        }
    case 10:
        if (func_ov000_021bd374(self, 0x6000)) {
            return;
        }
        pos = self->unk_50;
        func_ov000_021bd474(self, &pos);
        self->unk_80 = -0x2000;
        break;
    case 0:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
}

}
