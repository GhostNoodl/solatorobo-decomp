#include "ov000/MessageQueue.h"
#include "Main/Gfx/SlideWin.h"
#include "ov000/ObjLayouts.h"
#include "ov000/LoTimer.h"
#include "ov000/LoTicker.h"
#include "ov000/Obj0216c954.h"
#include "ov000/Obj0216ad04.h"

extern "C" {
void MissionCard_Draw(void *p);
void SceneCondCard_Draw(void *p);
void MissionInfo_Draw(void *p);
void TextBox_Draw(void *p);
void PlaceNameCard_Draw(void *p);
void ImageCard_Draw(void *p);
void Lo0216b474_Draw(void *p);

void ListBuffer021cb940_Draw(ListBuffer021cb940 *self) {
    switch (self->state) {
    case 4:
        if (self->win != NULL) {
            self->win->Render();
        }
    case 10:
        if (self->unk_3c != NULL) {
            MissionCard_Draw(self->unk_3c);
        }
    case 11:
        if (self->dialog != NULL) {
            self->dialog->vfunc_20();
        }
        break;
    case 8:
        if (self->unk_40 != NULL) {
            SceneCondCard_Draw(self->unk_40);
        }
        break;
    case 9:
        if (self->unk_44 != NULL) {
            MissionInfo_Draw(self->unk_44);
        }
        break;
    case 5:
        if (self->unk_2c != NULL) {
            TextBox_Draw(self->unk_2c);
        }
        break;
    case 6:
        if (self->unk_30 != NULL) {
            self->unk_30->vfunc_20();
        }
        break;
    case 7:
        if (self->unk_38 != NULL) {
            PlaceNameCard_Draw(self->unk_38);
        }
        break;
    }
    if (self->unk_34 != NULL) {
        ImageCard_Draw(self->unk_34);
    }
    if (self->unk_50 != NULL) {
        Obj0216c954_Draw(self->unk_50);
    }
    if (self->unk_54 != NULL) {
        LoTimer_Draw(self->unk_54);
    }
    if (self->unk_58 != NULL) {
        self->unk_58->vfunc_10();
    }
    if (self->unk_5c != NULL) {
        self->unk_5c->vfunc_10();
    }
    if (self->unk_60 != NULL) {
        self->unk_60->vfunc_10();
    }
    if (self->unk_64 != NULL) {
        self->unk_64->vfunc_10();
    }
    if (self->unk_68 != NULL) {
        Lo0216b474_Draw(self->unk_68);
    }
    if (self->unk_78 != NULL) {
        Obj0216ad04_Draw(self->unk_78);
    }
    if (self->unk_6c != NULL) {
        self->unk_6c->vfunc_10();
    }
    if (self->unk_70 != NULL) {
        self->unk_70->vfunc_10();
    }
    if (self->unk_74 != NULL) {
        self->unk_74->vfunc_10();
    }
    if (self->ticker != NULL) {
        LoTicker_Draw(self->ticker);
    }
}
}
