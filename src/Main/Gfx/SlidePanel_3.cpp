#include "Main/Gfx/SlidePanel.h"

extern "C" {

void func_020554e4(SlidePanel *panel);

void Model_SetPartPos(Model *model, int idx, ModelPos *pos) {
    ((ModelPos *)&model->x)[idx] = *pos;
}

void SlideCtrl_Lock(SlideCtrl *ctrl) {
    ctrl->flag11 = 1;
    ctrl->lock++;
}

void SlideCtrl_Unlock(SlideCtrl *ctrl) {
    if (ctrl->lock != 0) {
        ctrl->lock--;
    }
}

}
