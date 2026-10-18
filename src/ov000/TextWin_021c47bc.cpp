#include "nitro/fx.h"

typedef struct Line021c4964 {
    u8 pad[0x18];
    s32 unk_18;
    u8 pad1c[0xc];
    struct Line021c4964 *next;
    struct Line021c4964 *prev;
} Line021c4964;

typedef struct {
    u8 pad[0x20];
    s32 unk_20;
    u8 pad24[0x70];
    Line021c4964 *head;
    s32 unk_98;
    s32 unk_9c;
    Line021c4964 *unk_a0;
    u8 pada4[4];
    s32 unk_a8;
    u16 unk_ac;
    u8 padae[0x16];
    s32 unk_c4;
    s32 unk_c8;
    u8 padcc[0x12];
    u8 unk_de;
    u8 unk_df;
} Win021c4964;

extern "C" {

static inline void Win021c4964_Update(Win021c4964 *self) {
    Line021c4964 *node;
    s32 j;
    s32 i;
    s32 idx;
    node = self->head;
    i = 0;
    idx = self->unk_a8;
    if (node == NULL) {
        self->unk_a0 = NULL;
    } else {
        while (node != NULL) {
            if (i == idx) {
                break;
            }
            node = node->next;
            i++;
        }
        self->unk_a0 = node;
        self->unk_ac = 7;
        for (j = idx - 1; j >= self->unk_9c; j--) {
            self->unk_ac += (u16)node->unk_18;
            node = node->prev;
        }
    }
    if (self->unk_98 < self->unk_20) {
        self->unk_c8 = 0x1000;
    } else {
        self->unk_c8 = FX_Div(self->unk_20 << 12, self->unk_98 << 12);
    }
    self->unk_c4 = FX_Div(self->unk_9c << 12, self->unk_98 << 12);
}

void func_ov000_021c47bc(Win021c4964 *self, s32 up, u8 *moved, u8 *scrolled) {
    if (up != 0) {
        if (--self->unk_a8 < 0) {
            self->unk_a8 = 0;
        } else {
            *moved = 1;
        }
    } else {
        self->unk_a8++;
        if (self->unk_a8 > self->unk_98 - 1) {
            self->unk_a8 = self->unk_98 - 1;
        } else {
            *moved = 1;
        }
    }
    if (*moved == 0) {
        return;
    }
    if (self->unk_a8 < self->unk_9c + 1) {
        *scrolled = 1;
        if (--self->unk_9c < 0) {
            self->unk_9c = 0;
        } else {
            self->unk_df = 1;
            self->unk_de = 4;
        }
    } else if (self->unk_a8 >= self->unk_9c + self->unk_20 - 1) {
        *scrolled = 1;
        self->unk_9c++;
        if (self->unk_9c > self->unk_98 - self->unk_20) {
            self->unk_9c = self->unk_98 - self->unk_20;
        } else {
            self->unk_df = 2;
            self->unk_de = 4;
        }
    }
    Win021c4964_Update(self);
}

s32 func_ov000_021c4964(Win021c4964 *self, s32 n) {
    if (n < 0) {
        if (self->unk_9c <= 0) {
            n = 0;
        } else {
            self->unk_9c--;
            self->unk_a8--;
            self->unk_df = 1;
            self->unk_de = 2;
            n++;
        }
    } else if (n > 0) {
        if (self->unk_9c >= self->unk_98 - self->unk_20) {
            n = 0;
        } else {
            self->unk_9c++;
            self->unk_a8++;
            self->unk_df = 2;
            self->unk_de = 2;
            n--;
        }
    }
    Win021c4964_Update(self);
    return n;
}

}
