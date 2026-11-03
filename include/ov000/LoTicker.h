#ifndef OV000_LOTICKER_H
#define OV000_LOTICKER_H

// The field message ticker (ctor LoTicker_Init, 0x3d8 bytes, allocated by ListBuffer021cb940_Update,
// which builds res[] with __cxa_vec_ctor at 0x360). Messages are queued in the ring msgs[read..write),
// moved one at a time into a free slot (func_ov000_0216c018), slid in and dropped out by
// func_ov000_0216c310 and drawn by func_ov000_0216c6fc between the two icon texts of their kind.

#include "types.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Effect/Effect.h"

#ifdef __cplusplus
extern "C" {
#endif

// A text window shared by several users (func_ov000_0216bae4 creates it or counts one more user).
typedef struct LoTextHolder {
    s32 count;
    void *text; // the string (TextWin::str)
    TextWin *win;
} LoTextHolder;

// A queued message: kind indexes data_ov000_021c9bb4 (the two res[] icons), text is drawn when not empty.
typedef struct LoTickerMsg {
    s32 kind;
    char text[0x20];
} LoTickerMsg;

// A message on screen, linked from LoTicker::head to tail. flags: 1 used, 2 sliding in, 4 dropping.
typedef struct LoTickerSlot LoTickerSlot;
struct LoTickerSlot {
    u32 flags;
    s32 kind;
    TextWin *text;
    s32 t;
    s32 drop;
    s32 x;
    s32 y;
    s32 base;
    s32 timer;
    Effect3D *eff;
    LoTickerSlot *next;
};

typedef struct LoTicker {
    s32 speed;
    LoTickerMsg msgs[16];
    s32 read;
    s32 write;
    LoTickerSlot *head;
    LoTickerSlot *tail;
    LoTickerSlot slots[6];
    LoTickerSlot *cur;
    LoTextHolder res[10];
} LoTicker;
SIZE_ASSERT(LoTicker, 0x3d8);

// The icon pair (res[] indices) of a message kind.
typedef struct LoTickerIcons {
    s32 a;
    s32 b;
} LoTickerIcons;

extern const LoTickerIcons data_ov000_021c9bb4[];

void LoTextHolder_Init(LoTextHolder *self);
LoTextHolder *LoTextHolder_Dtor(LoTextHolder *self);
void func_ov000_0216bae4(LoTextHolder *self, void *text);
void LoTicker_InitTexts(LoTicker *self);
void LoTicker_Clear(LoTicker *self);
void func_ov000_0216be58(LoTicker *self);
void func_ov000_0216be94(LoTicker *self);
void LoTicker_Init(LoTicker *self);
void LoTicker_Release(LoTicker *self);
void func_ov000_0216c018(LoTicker *self);
void func_ov000_0216c310(LoTicker *self);
void func_ov000_0216c6fc(LoTicker *self);

#ifdef __cplusplus
}
#endif

#endif
