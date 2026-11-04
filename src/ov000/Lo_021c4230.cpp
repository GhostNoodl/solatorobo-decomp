#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Sys/Pad.h"

extern "C" {
struct Win021c4460;
void Win021c4460_Update(struct Win021c4460 *self);
void func_ov000_021c4b00(void *self);
void func_ov000_0215f330(void *p);
void func_ov000_021c4c10(void *self);
extern void *gSndMgr;
void *SndMgr_PlayVolume(void *a, int b, int c, int d, int e);

void LoBase021ccb54_021ccbe0_PreUpdate(LoBase021ccb54_021ccbe0 *self) {
    s32 i;
    ListRow *n;

    switch (self->state) {
    case 0:
        if (self->flag4) {
            SndMgr_PlayVolume(gSndMgr, 0x27, -1, -1, -1);
        }
        break;
    case 2:
        if (self->hidden) {
            self->state = 1;
        }
        Win021c4460_Update((struct Win021c4460 *)self);
        func_ov000_021c4b00(self);
        self->unk_d4++;
        if (self->unk_d4 < 20) {
            self->unk_d8 += LO_FX_MUL(0x6000 - self->unk_d8, 0x19a);
        } else if (self->unk_d4 < 50) {
            self->unk_d8 += LO_FX_MUL(0 - self->unk_d8, 0xcd);
        } else {
            self->unk_d4 = 0;
            self->unk_d8 = 0;
        }
        break;
    case 1:
        if (self->flag4) {
            SndMgr_PlayVolume(gSndMgr, 0x28, -1, -1, -1);
        }
        break;
    }
    i = 0;
    for (n = self->unk_94; n != NULL; n = n->next) {
        BOOL on = FALSE;
        switch (self->unk_df) {
        case 0:
            on = i >= self->unk_9c && i <= self->unk_9c + (self->rows - 1);
            break;
        case 1:
            on = i >= self->unk_9c && i <= self->unk_9c + self->rows;
            break;
        case 2:
            on = i >= self->unk_9c - 1 && i <= self->unk_9c + self->rows - 1;
            break;
        }
        if (on) n->shown = 1; else n->shown = 0;
        n->focus = 0;
        n->vfunc_08();
        i++;
    }
    if (self->unk_a0 != NULL) {
        self->unk_a0->focus = 1;
    }
    func_ov000_021c4c10(self);
}
}

// Win021c4460_Update (round bgR2): the e4 callback takes the selected line as its second argument, like
// e8. With `self->unk_e4(self, n)` n is coalesced into the r1 argument, which gives the ROM's idx r0 / n r1 /
// callback r2 (every earlier draft called it with self only and stopped at 10 / 0).
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
    void (*unk_e4)(struct Win021c4460 *self, Line021c4460 *line);
    void (*unk_e8)(struct Win021c4460 *self, Line021c4460 *line);
} Win021c4460;

extern "C" {

extern void *gSndMgr;
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
void Win021c4964_MoveCursor(Win021c4460 *self, s32 up, u8 *moved, u8 *scrolled);
s32 Win021c4964_Scroll(Win021c4460 *self, s32 n);

void Win021c4460_Update(Win021c4460 *self) {
    u16 cur;
    u16 trig;
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
    cur = gPad->cur;
    trig = gPad->trig;
    key = self->unk_dd == 0 ? cur : 0;
    done = FALSE;
    moved = 0;
    scrolled = 0;
    changed = FALSE;
    if (self->unk_bc == 0) {
        if (key & 0x40) {
            Win021c4964_MoveCursor(self, 1, &moved, &scrolled);
        } else if (key & 0x80) {
            Win021c4964_MoveCursor(self, 0, &moved, &scrolled);
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
        self->unk_bc = Win021c4964_Scroll(self, self->unk_bc);
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
            SndMgr_PlayVolume(gSndMgr, 0x1d, -1, -1, -1);
        }
    }
    done = FALSE;
    busy = TRUE;
    if (!moved && !changed && !scrolled) {
        busy = FALSE;
    }
    if ((trig & 1) && !busy) {
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
            self->unk_e4(self, n);
        } else if (self->b4) {
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
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
    } else if (cur == 0) {
        self->unk_dc = 0;
    }
    if (self->unk_dc > 4) {
        self->unk_dc = 4;
    }
}

}
