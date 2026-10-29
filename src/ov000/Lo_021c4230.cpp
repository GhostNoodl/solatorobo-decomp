#include "ov000/LoCommon.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} NodeBits;

extern "C" {
struct Win021c4460;
void func_ov000_021c4460(struct Win021c4460 *self);
void func_ov000_021c4b00(void *self);
void func_ov000_0215f330(void *p);
void func_ov000_021c4c10(void *self);
extern void *data_02097e4c;
void func_02049a48(void *a, int b, int c, int d, int e);

void func_ov000_021c4230(u8 *self) {
    s32 i;
    u8 *n;

    switch (LFLD(s32, self, 0x4)) {
    case 0:
        if (LBIT(self, 0xc).b4) {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        }
        break;
    case 2:
        if (LBIT(self, 0xc).b1) {
            LFLD(s32, self, 0x4) = 1;
        }
        func_ov000_021c4460((struct Win021c4460 *)self);
        func_ov000_021c4b00(self);
        LFLD(s8, self, 0xd4)++;
        if (LFLD(s8, self, 0xd4) < 20) {
            LFLD(s32, self, 0xd8) += LO_FX_MUL(0x6000 - LFLD(s32, self, 0xd8), 0x19a);
        } else if (LFLD(s8, self, 0xd4) < 50) {
            LFLD(s32, self, 0xd8) += LO_FX_MUL(0 - LFLD(s32, self, 0xd8), 0xcd);
        } else {
            LFLD(s8, self, 0xd4) = 0;
            LFLD(s32, self, 0xd8) = 0;
        }
        break;
    case 1:
        if (LBIT(self, 0xc).b4) {
            func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        }
        break;
    }
    i = 0;
    for (n = LFLD(u8 *, self, 0x94); n != NULL; n = LFLD(u8 *, n, 0x28)) {
        BOOL on = FALSE;
        switch (LFLD(u8, self, 0xdf)) {
        case 0:
            on = i >= LFLD(s32, self, 0x9c) && i <= LFLD(s32, self, 0x9c) + (LFLD(s32, self, 0x20) - 1);
            break;
        case 1:
            on = i >= LFLD(s32, self, 0x9c) && i <= LFLD(s32, self, 0x9c) + LFLD(s32, self, 0x20);
            break;
        case 2:
            on = i >= LFLD(s32, self, 0x9c) - 1 && i <= LFLD(s32, self, 0x9c) + LFLD(s32, self, 0x20) - 1;
            break;
        }
        if (on) LFLD(NodeBits, n, 0x20).b0 = 1; else LFLD(NodeBits, n, 0x20).b0 = 0;
        LFLD(NodeBits, n, 0x20).b1 = 0;
        ((VObj *)n)->vfunc_08();
        i++;
    }
    if (LFLD(u8 *, self, 0xa0) != NULL) {
        LFLD(NodeBits, LFLD(u8 *, self, 0xa0), 0x20).b1 = 1;
    }
    func_ov000_021c4c10(self);
}
}

#ifdef NONMATCHING
// func_ov000_021c4460 (0x2d8 bytes, the window cursor/scroll input handler): 10 / 0 (raw / register-masked).
// The only misses are in the select-line walk: ROM n r1, idx r0, unk_e4 callback r2; ours n r0, idx r1,
// callback r1. ramerge (round qpH) has no single merge or renumbering for {idx:r0, n:r1, unk_e4 load:r2};
// round ovsmall2's two-move families need either the unk_e4 load temp numbered below the named locals or n
// and idx both numbered as temps above it. Tried with no change (all 10 / 0): Next/Sel/Head/Cur address and
// value accessors in every combination (raA/raB), a Decide inline for the callback (local, parameter or
// plain), i/idx in s32/u32/int, idx == i, for/while walk shapes, idx read before the head. u8/u16/s16
// counters give 77-78. Earlier drafts: cmA/o/r3/c4460/best.cpp (with an unused kq local, dropped here).

typedef struct Line021c4460 {
    u8 pad[0x28];
    struct Line021c4460 *next;
} Line021c4460;

struct Win021c4460;
typedef void (*WinCb021c4460)(struct Win021c4460 *self, ...);

typedef struct Win021c4460 {
    u8 pad[0xc];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 rest : 27;
    u8 pad10[0x10];
    s32 unk_20;
    u8 pad24[0x70];
    Line021c4460 *head;
    s32 unk_98;
    s32 unk_9c;
    Line021c4460 *unk_a0;
    Line021c4460 *unk_a4;
    s32 unk_a8;
    u8 padac[0x10];
    s32 unk_bc;
    u8 padc0[0x1c];
    s8 unk_dc;
    s8 unk_dd;
    u8 unk_de;
    u8 unk_df;
    u8 pade0[4];
    void (*unk_e4)(struct Win021c4460 *self);
    void (*unk_e8)(struct Win021c4460 *self, Line021c4460 *line);
} Win021c4460;

typedef struct {
    u8 pad[0x10];
    u16 trg;
    u16 cont;
} Pad021c4460;

extern "C" {

extern Pad021c4460 *data_02097dc8;
extern void *data_02097e4c;
void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_ov000_021c47bc(Win021c4460 *self, s32 up, u8 *moved, u8 *scrolled);
s32 func_ov000_021c4964(Win021c4460 *self, s32 n);

void func_ov000_021c4460(Win021c4460 *self) {
    u16 trg;
    u16 cont;
    u32 key;
    u8 moved;
    u8 scrolled;
    BOOL changed;
    BOOL done;
    BOOL busy;
    if (self->b2) {
        return;
    }
    if (self->b1 || self->unk_de != 0) {
        return;
    }
    trg = data_02097dc8->trg;
    cont = data_02097dc8->cont;
    key = self->unk_dd == 0 ? trg : 0;
    done = FALSE;
    moved = 0;
    scrolled = 0;
    changed = FALSE;
    if (self->unk_bc == 0) {
        if (key & 0x40) {
            func_ov000_021c47bc(self, 1, &moved, &scrolled);
        } else if (key & 0x80) {
            func_ov000_021c47bc(self, 0, &moved, &scrolled);
        } else if (key & 0x200) {
            if (self->unk_9c > 0) {
                changed = TRUE;
                self->unk_bc = -self->unk_20;
            }
        } else if (key & 0x100) {
            if (self->unk_9c < self->unk_98 - self->unk_20) {
                self->unk_bc = self->unk_20;
                changed = TRUE;
            }
        }
    } else {
        self->unk_bc = func_ov000_021c4964(self, self->unk_bc);
        changed = TRUE;
        if (self->unk_bc == 0) {
            done = TRUE;
        }
    }
    if (moved || changed) {
        self->unk_a4 = NULL;
    }
    if (moved || done) {
        if (self->unk_e8 != NULL) {
            self->unk_e8(self, self->unk_a0);
        } else if (self->b4) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    }
    done = FALSE;
    busy = TRUE;
    if (!moved && !changed && !scrolled) {
        busy = FALSE;
    }
    if ((cont & 1) && !busy) {
        Line021c4460 *n;
        s32 idx;
        s32 i;
        done = TRUE;
        n = self->head;
        idx = self->unk_a8;
        for (i = 0; n != NULL; n = n->next, i++) {
            if (i == idx) {
                break;
            }
        }
        self->unk_a4 = n;
        if (self->unk_e4 != NULL) {
            self->unk_e4(self);
        } else if (self->b4) {
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        }
    }
    if (done) {
        self->unk_dc = 0;
        self->unk_dd = 10;
        return;
    }
    if (moved || changed || scrolled) {
        self->unk_dd = 10 - self->unk_dc * 2;
    }
    self->unk_dd--;
    if (self->unk_dd < 0) {
        self->unk_dd = 0;
    }
    if (moved || changed || scrolled) {
        if (changed) {
            self->unk_dc += 2;
        } else {
            self->unk_dc += 1;
        }
    } else if (trg == 0) {
        self->unk_dc = 0;
    }
    if (self->unk_dc > 4) {
        self->unk_dc = 4;
    }
}

}
#endif
