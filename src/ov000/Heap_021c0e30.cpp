#include "ov000/HeapScope.h"
#include "ov000/Vec.h"
#include "ov000/VObj.h"
#include "Main/Gfx/GfxMgr.h"
#include "ov000/ActorMarker.h"

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

struct Marker021c0e30 : ActorMarker {
    void *unk_8c;
    Ov000Text021c0e30 *unk_90;
    u16 unk_94;
    u16 unk_96;
    s32 unk_98;
};

extern "C" {

extern VFunc data_0208ba70[];
void *Heap_Alloc(u32 size);
void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void *Tbl_GetText(s32 id);

static inline BOOL Obj021c0e30_Wait(Marker021c0e30 *self) {
    if (!(self->show == 1 ? TRUE : FALSE) || (self->change == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->work.state = 10;
    return FALSE;
}

void func_ov000_021c0e30(Marker021c0e30 *self) {
    VecFx32 pos;
    switch (self->work.state) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        HEAP_DELETE_VOBJ(self->unk_90);
        return;
    case 1:
        {
            void *model = self->mdl[4];
            self->mdl[4] = NULL;
            self->unk_8c = model;
        }
        self->unk_94 = 0;
        self->unk_90 = NULL;
        self->work.state = 3;
    case 3:
        HEAP_DELETE_VOBJ(self->unk_90);
        self->work.fade = 0;
        self->work.alpha = 0;
        if (Obj021c0e30_Wait(self)) {
            return;
        }
        self->work.state = 2;
    case 2:
        {
            Ov000Text021c0e30 *t;
            void *str;
            self->unk_94 = self->unk_28[0];
            t = (Ov000Text021c0e30 *)Heap_Alloc(0xb8);
            if (t != NULL) {
                t->vtbl = data_0208ba70;
                TextWin_Init(t);
            }
            self->unk_90 = t;
            t->unk_28 = 4;
            self->unk_90->unk_2c = 0;
            str = Tbl_GetText(self->unk_94);
            t = self->unk_90;
            t->unk_24 = (s32)str;
            t->unk_4c = Text_Measure(t->unk_28, t->unk_38, t->unk_24, &t->unk_44, &t->unk_48, t->unk_37 != 0);
            data_02097ce0->unk_004 = t->unk_28;
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
        self->work.state = 4;
    case 4:
        self->work.fade = 0;
        self->work.alpha = 0;
        if (Obj021c0e30_Wait(self)) {
            self->work.state = 3;
            return;
        }
    case 10:
        if (ActorMarker_UpdateFade(self, 0x6000)) {
            return;
        }
        pos = self->unk_50;
        ActorMarker_UpdateScreenPos(self, &pos);
        self->work.z = -0x2000;
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
