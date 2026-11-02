#include "ov002/ov002.h"

extern "C" {

BOOL func_ov000_02191120(void *a);
void func_ov000_02191780(void *a);
s32 **func_ov000_02190a30(void *a, int b);

typedef struct Key021db9e8 {
    s16 t;
    s16 a;
    s16 b;
} Key021db9e8;

extern Key021db9e8 data_ov002_021eeffc[];

static inline void *ov002_Step_ctor(void *self) {
    *(VFunc **)self = data_ov002_021eff10;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = -1;
    FIELD(self, 0x20, u8) = 0;
    FIELD(self, 0x24, s32) = 0;
    FIELD(self, 0x28, s32) = 0;
    FIELD(self, 0x2c, s32) = 0;
    FIELD(self, 0x30, s32) = 0;
    FIELD(self, 0x34, u8) = 0;
    return self;
}

static inline void ov002_SetNext(void *self, void *a, s32 b) {
    FIELD(self, 0x10, void *) = a;
    FIELD(self, 0xc, s32) = b;
}

static inline u8 ov002_IsDone(void *p) {
    u8 r; if (FIELD(p, 0x4, s32) == 5) { r = TRUE; } else { r = FALSE; } return r;
}

static inline bool ov002_Ready(u8 *m) {
    return m[0x5d] != 0 && FIELD(m, 0x10, void *) != NULL && func_ov000_02191120(FIELD(m, 0x10, void *));
}

void func_ov002_021db9e8(Obj021eff50 *self) {
    switch (self->unk_14) {
    case 0:
        if (self->unk_34 <= 0 || ov002_Ready(FIELD(((u8 *)self->board), 0x4, u8 *))) {
            self->unk_34 = 20;
            self->unk_14++;
        } else {
            self->unk_34--;
            return;
        }
    case 1:
        if (self->unk_34 <= 0) {
            void *p = Heap_Alloc(0x134);
            if (p != NULL) {
                p = ov002_Step_ctor(p);
            }
            ov002_SetNext(self, p, 10);
        } else {
            self->unk_34--;
            return;
        }
    case 10:
    case 20:
    case 30:
        if (self->unk_0c != -1) {
            if (self->unk_18 != NULL) {
                self->unk_18->vfunc_10(self);
                {
                    void *saved;
                    HEAP_PUSH(saved);
                    DELETE_VOBJ(FIELD(self, 0x18, VObj *));
                    HEAP_POP(saved);
                }
            }
            self->unk_1c = self->unk_14;
            self->unk_18 = (VObj *)(self->unk_10);          self->unk_14 = self->unk_0c;
            self->unk_10 = NULL;
            self->unk_0c = -1;
            if (self->unk_18 != NULL) {
                self->unk_18->vfunc_08(self);
            }
        }
        if (self->unk_18 == NULL) {
            self->unk_08 = 0;
            self->unk_14 = 40;
            self->unk_20->flags |= 2;
            self->unk_24->flags |= 2;
        } else {
            self->unk_18->vfunc_0c(self);
        }
        self->unk_20->vfunc_1c();
        self->unk_24->vfunc_1c();
        break;
    case 40:
        self->unk_20->vfunc_1c();
        self->unk_24->vfunc_1c();
        if (!ov002_IsDone(self->unk_20)) {
            return;
        }
        if (!ov002_IsDone(self->unk_24)) {
            return;
        }
        {
            Key021db9e8 *k;
            u8 *m = FIELD(((u8 *)self->board), 0x4, u8 *);
            s32 x;
            func_ov000_02191780(FIELD(m, 0x10, void *));
            k = data_ov002_021eeffc;
            FIELD(m, 0x60, Key021db9e8 *) = k;
            {
                s32 **pp = func_ov000_02190a30(FIELD(m, 0x10, void *), 0);
                x = 0;
                if (*pp != NULL) {
                    x = **pp;
                }
            }
            while (k->t < (x + 0x1000) >> 12) {
                if (k->t < 0) {
                    k--;
                    break;
                }
                k++;
            }
            FIELD(m, 0x64, Key021db9e8 *) = k;
            m[0x5d] = 0;
            func_ov002_021d9c04(self->board);
            self->unk_14 = 50;
        }
        break;
    case 50:
        break;
    }
}

}
