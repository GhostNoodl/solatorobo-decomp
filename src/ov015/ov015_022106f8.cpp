#include "ov015/ov015.h"

extern "C" {

s32 Interp_QuadLerp(s32 t, s32 a, s32 b);

BOOL func_ov015_022106f8(Ov015Msg *self) {
    BOOL r = FALSE;
    switch (self->step) {
    case 0:
        self->timer = self->unk_08;
        self->step++;
    case 1:
        if (--self->timer < 0) {
            self->timer = 0x28;
            self->step++;
            self->unk_04 = 1;
        }
        break;
    case 2: {
        s32 t = FX_Div(self->timer << 12, 0x28000);
        self->posX = 0x50000;
        self->posY = Interp_QuadLerp(t, -0x46000, -0x66000);
        self->posZ = -0x333;
        if (--self->timer >= 0) {
            break;
        }
        self->timer = 0;
        self->step++;
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
    }
    case 3: {
        s32 y = FX_Mul(FX_SinCosTable_[((self->timer * 0x3fff / 40) >> 4) * 2], 0x6000) - 0x46000;
        self->posX = 0x50000;
        self->posY = y;
        self->posZ = -0x333;
        self->timer++;
        if (self->timer > 0x28) {

            self->timer = 0x28;
            r = TRUE;
        }
        break;
    }
    }
    return r;
}


s32 func_0204c2f4(void *p, s32 n, void *src);
void Obj0215bb14_SetText(void *a, void *b);
void func_ov015_0220866c(Ov015UiText *self, void *msg);

BOOL func_ov015_02210860(Ov015Msg *self) {
    BOOL r = TRUE;
    self->posX = 0x50000;
    self->posY = FX_Mul(FX_SinCosTable_[((self->timer * 0x3fff / 80) >> 4) * 2], 0x6000) - 0x46000;
    self->posZ = -0x333;
    self->timer = (self->timer + 1) % 80;
    self->label->vfunc_1c();
    self->textBox->vfunc_1c();
    if (self->label->vfunc_0c() && (data_02097dc8->trig & 1)) {
        s32 n = ++self->page;
        if (n < self->pageCount) {
            if (self->label != NULL && self->pages[n] != NULL) {
                Lo021cadcc *o;
                func_0204c2f4(self->text, 0x80, self->pages[n]);
                Obj0215bb14_SetText(self->label, self->text);
                self->label->vfunc_70();
                FLD(u32, self->label->unk_84, 0x4) |= 0x4000000;
                o = self->label;
                o->unk_84->vfunc_1c(o->posX + o->width - 0x14, o->posY + o->height - 0xc, -0xcbd);
                func_ov015_0220866c(self->textBox, self->pages[n]);
            }
        } else {
            r = FALSE;
        }
    }
    return r;
}

}
