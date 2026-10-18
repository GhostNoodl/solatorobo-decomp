#include "Main/Gfx/SlidePanel.h"

extern "C" {

void func_020554e4(SlidePanel *panel);

void func_0205563c(Model *model, int idx, ModelPos *pos) {
    ((ModelPos *)&model->x)[idx] = *pos;
}

void func_02055654(SlideCtrl *ctrl) {
    ctrl->flag11 = 1;
    ctrl->lock++;
}

void func_0205567c(SlideCtrl *ctrl) {
    if (ctrl->lock != 0) {
        ctrl->lock--;
    }
}

}
