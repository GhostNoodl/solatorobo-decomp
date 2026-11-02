#include "ov000/LoCommon.h"
#include "ov000/UiObj.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 pad : 5;
    u32 fade : 2;
    u32 rest : 23;
} Bits02152740;

typedef void (*LoCb02152740)(VObj *self);

extern "C" {
s32 FX_Div(s32 a, s32 b);



BOOL UiObj_Update(UiObj *self) {
    self->vfunc_54();
    switch (self->state) {
    case 5:
        if (!self->hidden) {
            self->state = 0;
            return TRUE;
        }
        return FALSE;
    case 0:
        self->busy = 1;
        if (self->hidden == 1) {
            self->state = 5;
            break;
        }
        if (((LoCb02152740)self->onState) != NULL) {
            ((LoCb02152740)self->onState)(self);
        }
        self->state = 3;
    case 3:
        if (!self->vfunc_4c()) {
            break;
        }
        self->openTime += 0x1000;
        self->openRatio = FX_Div(self->openTime, self->openLen);
        if (self->openRatio < 0x1000) {
            break;
        }
        if ((void *)self->child == NULL) {
            self->busy = 0;
        }
        self->openTime = self->openLen;
        self->openRatio = 0x1000;
        if (((LoCb02152740)self->onState) != NULL) {
            ((LoCb02152740)self->onState)(self);
        }
        self->state = 2;
        break;
    case 1:
        self->busy = 1;
        if (((LoCb02152740)self->onState) != NULL) {
            ((LoCb02152740)self->onState)(self);
        }
        self->state = 4;
    case 4:
        self->openTime -= 0x1000;
        self->openRatio = FX_Div(self->openTime, self->openLen);
        if (self->openRatio > 0) {
            break;
        }
        self->openTime = 0;
        self->openRatio = 0;
        if (((LoCb02152740)self->onState) != NULL) {
            ((LoCb02152740)self->onState)(self);
        }
        self->state = 5;
        return FALSE;
    case 2:
        self->openTime = self->openLen;
        self->openRatio = 0x1000;
        {
            u32 f = self->fade;
            if (f == 0) {
            } else if (f == 1) {
                self->fadeTime += 0x1000;
                self->fadeRatio = FX_Div(self->fadeTime, self->fadeLen);
                if (self->fadeRatio >= 0x1000) {
                    self->fadeTime = self->fadeLen;
                    self->fadeRatio = 0x1000;
                    self->fade = 2;
                }
            } else if (f == 3) {
                self->fadeTime -= 0x1000;
                self->fadeRatio = FX_Div(self->fadeTime, self->fadeLen);
                if (self->fadeRatio <= 0) {
                    self->fadeTime = 0;
                    self->fadeRatio = 0;
                    self->fade = 0;
                }
            }
        }
        break;
    }
    if (self->child != NULL && !self->child->vfunc_1c()) {
        LO_FREE_V(self, 0x74);
        if (self->child == NULL) {
            self->busy = 0;
        }
        if (!self->vfunc_50()) {
            self->hidden = 1;
        }
    }
    self->vfunc_58();
    if (self->scrollLen != 0) {
        s32 n = self->scrollLen << 12;
        self->scrollPos += 0x666;
        if (self->scrollPos >= n + 0x7c000) {
            self->scrollPos -= n;
        }
    }
    return TRUE;
}

}

