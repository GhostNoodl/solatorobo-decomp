#include "Main/Save/PlayTime.h"

extern "C" {

static inline u32 PlayTime_ToMillis(const PlayTime *t) {
    return t->hours * 3600000 + t->minutes * 60000 + t->seconds * 1000 + t->millis;
}

// Caps the play time at the given value. The target reloads millis from the stack for the store.
void func_02048cf0(PlayTime *t, u16 hours, u16 minutes, u16 seconds, volatile u16 millis) {
    if (PlayTime_ToMillis(t) > hours * 3600000 + minutes * 60000 + seconds * 1000 + millis) {
        t->hours = hours;
        t->minutes = minutes;
        t->seconds = seconds;
        t->millis = millis;
    }
}

}
