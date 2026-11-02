#include "ov002/ov002.h"

extern "C" {

BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *a);
void Model0218fe1c_SetReverse(Model0218fe1c *a);
s32 **Model0218fe1c_GetAnimCtrl(Model0218fe1c *a, int b);

extern Ov002SndCue data_ov002_021eeffc[];

static inline Obj021eff10 *ov002_Step_ctor(Obj021eff10 *self) {
    *(VFunc **)self = data_ov002_021eff10;
    self->owner = NULL;
    self->unk_08 = NULL;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
    self->unk_18 = 0;
    self->unk_1c = -1;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = NULL;
    self->unk_30 = NULL;
    self->unk_34[0] = 0;
    return self;
}

static inline void ov002_SetNext(Obj021eff50 *self, VObj *a, s32 b) {
    self->unk_10 = a;
    self->unk_0c = b;
}

static inline u8 ov002_IsDone(UiObj *p) {
    u8 r; if (p->state == 5) { r = TRUE; } else { r = FALSE; } return r;
}

static inline bool ov002_Ready(Obj021efe4c *m) {
    return m->unk_5d != 0 && m->unk_10 != NULL && Model0218fe1c_IsAnimDone(m->unk_10);
}

void func_ov002_021db9e8(Obj021eff50 *self) {
    switch (self->unk_14) {
    case 0:
        if (self->unk_34 <= 0 || ov002_Ready(self->board->field)) {
            self->unk_34 = 20;
            self->unk_14++;
        } else {
            self->unk_34--;
            return;
        }
    case 1:
        if (self->unk_34 <= 0) {
            Obj021eff10 *p = (Obj021eff10 *)Heap_Alloc(sizeof(Obj021eff10));
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
                    DELETE_VOBJ(self->unk_18);
                    HEAP_POP(saved);
                }
            }
            self->unk_1c = self->unk_14;
            self->unk_18 = self->unk_10;
            self->unk_14 = self->unk_0c;
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
            Ov002SndCue *k;
            Obj021efe4c *m = self->board->field;
            s32 x;
            Model0218fe1c_SetReverse(m->unk_10);
            k = data_ov002_021eeffc;
            m->cues = k;
            {
                s32 **pp = Model0218fe1c_GetAnimCtrl(m->unk_10, 0);
                x = 0;
                if (*pp != NULL) {
                    x = **pp;
                }
            }
            while (k->time < (x + 0x1000) >> 12) {
                if (k->time < 0) {
                    k--;
                    break;
                }
                k++;
            }
            m->cue = k;
            m->unk_5d = 0;
            func_ov002_021d9c04(self->board);
            self->unk_14 = 50;
        }
        break;
    case 50:
        break;
    }
}

}
