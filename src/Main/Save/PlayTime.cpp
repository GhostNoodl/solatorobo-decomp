#include "Main/Save/PlayTime.h"

extern "C" {

void func_02048be4(PlayTime *t) {
    t->hours = 0;
    t->minutes = 0;
    t->seconds = 0;
    t->millis = 0;
}

// The fields are stored through an inline with u16 parameters, so every result is narrowed to
// 16 bits before its store. The carries are written as `quotient + field`.
static inline void PlayTime_Set(PlayTime *t, u16 hours, u16 minutes, u16 seconds, u16 millis) {
    t->hours = hours;
    t->minutes = minutes;
    t->seconds = seconds;
    t->millis = millis;
}

// Carries millis into seconds, seconds into minutes and minutes into hours; hours saturate at 999.
// With toMinutes, the hours are folded into the minutes.
static inline void PlayTime_Normalize(PlayTime *t, BOOL toMinutes) {
    u16 ms = t->millis;
    u16 sec, min, h;
    int s, m;
    s = (u16)(ms / 1000);
    ms = ms % 1000;
    s += t->seconds;
    sec = s % 60;
    m = s / 60 + t->minutes;
    min = m % 60;
    h = m / 60 + t->hours;
    if (h >= 1000) {
        h = 999;
    }
    if (toMinutes) {
        min = h * 60 + min;
        h = 0;
    }
    PlayTime_Set(t, h, min, sec, ms);
}

void func_02048bfc(PlayTime *t, BOOL toMinutes) {
    PlayTime_Normalize(t, toMinutes);
}

static inline u32 PlayTime_ToMillis(const PlayTime *t) {
    return t->hours * 3600000 + t->minutes * 60000 + t->seconds * 1000 + t->millis;
}

// Caps the play time at the given value.
void func_02048cf0(PlayTime *t, u16 hours, u16 minutes, u16 seconds, u16 millis) {
    PlayTime cap;
    PlayTime_Set(&cap, hours, minutes, seconds, millis);
    if (PlayTime_ToMillis(t) > PlayTime_ToMillis(&cap)) {
        PlayTime_Set(t, hours, minutes, seconds, millis);
    }
}

// The millis and seconds sums go through int locals; written straight into the stores, the
// reciprocal of 1000 and the millis remainder swap registers.
void func_02048d58(PlayTime *dst, const PlayTime *a, const PlayTime *b) {
    int ms = a->millis + b->millis;
    int sec = a->seconds + b->seconds;
    dst->millis = ms;
    dst->seconds = sec;
    dst->minutes = a->minutes + b->minutes;
    dst->hours = a->hours + b->hours;
    PlayTime_Normalize(dst, FALSE);
}

#ifdef NONMATCHING
// 124 raw diffs: the fields are computed into locals and stored together, as in the target,
// but the register allocation and the schedule of the borrows still differ.
void func_02048e74(PlayTime *dst, const PlayTime *a, const PlayTime *b) {
    int ms, sec, min, h;
    int borrow;
    if (PlayTime_ToMillis(a) < PlayTime_ToMillis(b)) {
        PlayTime_Set(dst, 0, 0, 0, 0);
        return;
    }
    ms = (a->millis + (1000 - b->millis)) % 1000;
    borrow = a->millis < b->millis ? 1 : 0;
    sec = (a->seconds + (60 - b->seconds) - borrow) % 60;
    borrow = a->seconds - borrow < b->seconds ? 1 : 0;
    min = (a->minutes + (60 - b->minutes) - borrow) % 60;
    borrow = a->minutes - borrow < b->minutes ? 1 : 0;
    h = a->hours - b->hours - borrow;
    dst->millis = ms;
    dst->seconds = sec;
    dst->minutes = min;
    dst->hours = h;
    PlayTime_Normalize(dst, FALSE);
}
#endif

}
