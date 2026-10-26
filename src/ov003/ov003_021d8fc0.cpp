#include "types.h"

typedef struct {
    u8 id;
    u8 op;
    u8 arg;
    u8 arg2;
    u8 a;
    u8 b;
} SeqEntry;

typedef struct {
    u8 active : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 pairA;
    u8 pairB;
    u16 timer;
    u16 index;
    u16 length;
    SeqEntry *entries;
} Seq;

extern "C" {

extern s32 func_02040498(s32 n);

#define SEQ_CUR(s) ((void)0, (s)->entries[(s)->index])
/* The target re-reads index (and, before Seq_Run, entries) instead of reusing the
   value loaded for the previous copy, so these reads go through separate views: a const one
   for entries, and a volatile one for index (Seq_Next increments it through VIDX too). */
#define VIDX(s) (*(volatile u16 *)&(s)->index)
#define VENT(s) (*(SeqEntry *const *)&(s)->entries)

static inline void Seq_Next(Seq *self) {
    VIDX(self)++;
    if (self->index == self->length) {
        self->index = 0;
    }
}

static inline void Seq_ClearFlags(Seq *self) {
    self->b1 = 0;
    self->b2 = 0;
    self->b3 = 0;
    self->b4 = 0;
}

static inline void Seq_JumpTo(Seq *self, u8 id) {
    do {
        Seq_Next(self);
    } while (self->entries[self->index].id != id);
}

static inline BOOL Seq_IsCtl(SeqEntry e) {
    BOOL r = FALSE;
    if (e.op != 0xff) {
        if (e.op & 0x80) {
            r = TRUE;
        }
    }
    return r;
}

static inline void Seq_SetPair(Seq *self, SeqEntry e) {
    self->pairA = e.a;
    self->pairB = e.b;
}

static inline void Seq_Count(Seq *self, SeqEntry e) {
    if (e.arg <= self->timer) {
        Seq_Next(self);
        self->timer = 0;
        Seq_ClearFlags(self);
    } else {
        self->timer++;
    }
}

static inline BOOL Seq_CurIsCtl(Seq *self) {
    u8 op = self->entries[VIDX(self)].op;
    if (op != 0xff && (op & 0x80)) {
        return TRUE;
    }
    return FALSE;
}

static inline void Seq_Run(Seq *self, SeqEntry *p) {
    SeqEntry e = *p;
    switch (e.op) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        if (!self->b2) {
            self->b1 = 1;
            self->b2 = 1;
            Seq_SetPair(self, *p);
        }
        break;
    case 4:
        if (!self->b2) {
            self->b1 = 1;
            self->b2 = 1;
            Seq_SetPair(self, *p);
        }
        break;
    case 5:
        if (self->timer == 0) {
            self->b1 = 1;
            Seq_SetPair(self, *p);
            self->timer++;
        } else {
            Seq_Count(self, *p);
        }
        break;
    }
}

static inline BOOL Seq_IsValid(const Seq *self) {
    BOOL r = FALSE;
    if (self->active) {
        r = self->entries != NULL;
    }
    return r;
}

void func_ov003_021d8fc0(Seq *self) {
    if (!self->active) {
        return;
    }
    if (!Seq_IsValid(self)) {
        return;
    }
    if (!self->b6) {
        self->b1 = 0;
        if (self->b2 && self->b3) {
            SeqEntry e = SEQ_CUR(self);
            switch (e.op) {
            case 3:
                Seq_Next(self);
                self->timer = 0;
                Seq_ClearFlags(self);
                break;
            case 4:
                if (self->b4) {
                    Seq_Next(self);
                } else {
                    SeqEntry ge = e;
                    Seq_JumpTo(self, ge.arg);
                }
                self->timer = 0;
                Seq_ClearFlags(self);
                break;
            }
        }
        while (Seq_IsCtl(SEQ_CUR(self))) {
            SeqEntry e = SEQ_CUR(self);
            switch (e.op) {
            case 0x81: {
                SeqEntry re = e;
                if (func_02040498(0xff) < re.arg) {
                    Seq_Next(self);
                } else {
                    SeqEntry t = self->entries[self->index];
                    Seq_JumpTo(self, t.arg2);
                }
                self->timer = 0;
                Seq_ClearFlags(self);
                break;
            }
            case 0x82: {
                SeqEntry ge = e;
                Seq_JumpTo(self, ge.arg);
                self->timer = 0;
                Seq_ClearFlags(self);
                break;
            }
            }
        }
        if (!self->b2 && !Seq_CurIsCtl(self)) {
            u16 i = VIDX(self);
            Seq_Run(self, &VENT(self)[i]);
        }
    }
    self->b6 = self->b5;
}

}
