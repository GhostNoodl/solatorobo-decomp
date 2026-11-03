#include "ov002/ov002.h"

extern "C" {

void Ov002Task_SetCurrent(void *p) {
    if (gFinishingTask != NULL) {
        gLastTaskId = FIELD(gFinishingTask, 0x14, s32);
    } else {
        gLastTaskId = 0;
    }
    gFinishingTask = p;
}

}
