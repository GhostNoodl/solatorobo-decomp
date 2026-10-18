#include "Main/Save/PlayTime.h"

extern "C" {

void func_02048be4(PlayTime *t) {
    t->hours = 0;
    t->minutes = 0;
    t->seconds = 0;
    t->millis = 0;
}

#ifdef NONMATCHING
static inline void PlayTime_Normalize(PlayTime *t, BOOL toMinutes) {
    u16 hours;
    u16 minutes;
    u16 millis = t->millis;
    int seconds = t->seconds + (u16)(millis / 1000);
    int mins;
    millis = millis % 1000;
    t->seconds = seconds % 60;
    mins = t->minutes + seconds / 60;
    minutes = mins % 60;
    hours = t->hours + mins / 60;
    if (hours >= 1000) {
        hours = 999;
    }
    if (toMinutes) {
        minutes = hours * 60 + minutes;
        hours = 0;
    }
    t->hours = hours;
    t->minutes = minutes;
    t->millis = millis;
}

static inline u32 PlayTime_ToMillis(const PlayTime *t) {
    return t->hours * 3600000 + t->minutes * 60000 + t->seconds * 1000 + t->millis;
}

void func_02048bfc(PlayTime *t, BOOL toMinutes) {
    PlayTime_Normalize(t, toMinutes);
}

void func_02048cf0(PlayTime *t, u16 hours, u16 minutes, u16 seconds, u16 millis) {
    if (PlayTime_ToMillis(t) > hours * 3600000 + minutes * 60000 + seconds * 1000 + millis) {
        t->hours = hours;
        t->minutes = minutes;
        t->seconds = seconds;
        t->millis = millis;
    }
}

void func_02048d58(PlayTime *dst, const PlayTime *a, const PlayTime *b) {
    dst->millis = a->millis + b->millis;
    dst->seconds = a->seconds + b->seconds;
    dst->minutes = a->minutes + b->minutes;
    dst->hours = a->hours + b->hours;
    PlayTime_Normalize(dst, FALSE);
}

void func_02048e74(PlayTime *dst, const PlayTime *a, const PlayTime *b) {
    int borrow;
    if (PlayTime_ToMillis(a) < PlayTime_ToMillis(b)) {
        func_02048be4(dst);
        return;
    }
    dst->millis = (a->millis + (1000 - b->millis)) % 1000;
    borrow = a->millis < b->millis ? 1 : 0;
    dst->seconds = (a->seconds + (60 - b->seconds) - borrow) % 60;
    borrow = a->seconds - borrow < b->seconds ? 1 : 0;
    dst->minutes = (a->minutes + (60 - b->minutes) - borrow) % 60;
    borrow = a->minutes - borrow < b->minutes ? 1 : 0;
    dst->hours = a->hours - b->hours - borrow;
    PlayTime_Normalize(dst, FALSE);
}
#endif

}
