#include "Main/Save/PlayTime.h"

extern "C" {

void func_02049088(PlayTime *t, u32 frames) {
    t->hours = frames / 216000;
    t->minutes = (frames % 216000) / 3600;
    t->seconds = (frames % 3600) / 60;
    t->millis = ((frames % 60) * 0x10aac) >> 12;
}

}
