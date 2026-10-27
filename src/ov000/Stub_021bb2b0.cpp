#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "Main/Snd/SndMgr.h"

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
} Obj0219bf90;

typedef struct {
    u8 unk_00[0x1c];
    s32 state;
    u8 unk_20[0x1c];
    s32 unk_3c;
    u8 unk_40[0x180];
    void (*unk_1c0)(void *);
} Fx021bb33c;

typedef struct {
    s32 state;
    s32 unk_04;
    u8 unk_08;
    s32 unk_0c;
    Fx021bb33c *fx;
    VecFx32 pos;
} Obj021bb2b0;

extern "C" {

Obj0219bf90 *func_ov000_0219bf90(void);
extern void *data_02fe152c;
extern s32 data_02097d78[];
extern void *data_0214a420;
void func_ov000_021bb298(void *self);
u16 func_020594bc(void *res, u32 idx, int packed, int sub);
void func_0204aab0(SndQueue *queue, u16 value);
u16 func_0204aac4(SndQueue *queue);
void func_0204aa90(SndQueue *queue);
Fx021bb33c *func_02066df0(void);
Fx021bb33c *func_02066ec8(void);
Fx021bb33c *func_02066f90(void);
Fx021bb33c *func_02066c58(void);
Fx021bb33c *func_02067058(void);
Fx021bb33c *func_02067120(void);
Fx021bb33c *func_02065f88(s32 id, const VecFx32 *pos);
BOOL func_02065748(void *mgr, Fx021bb33c *fx);
void func_0203cb78(int duration, int mode, int ch);

void func_ov000_021bb2b0(Obj021bb2b0 *self, s32 a, s16 *v, u8 c) {
    self->unk_04 = 4;
    self->unk_0c = a;
    self->unk_08 = c;
    if (v == NULL) {
        Obj0219bf90 *p = func_ov000_0219bf90();
        if (p != NULL) {
            self->pos.x = p->pos.x;
            self->pos.y = p->pos.y;
            self->pos.z = p->pos.z;
        }
        if (a == 0x2717) {
            self->pos.y += 0x8000;
        }
        return;
    }
    self->pos.x = v[0] << 4;
    self->pos.y = v[1] << 4;
    self->pos.z = v[2] << 4;
}


static inline void Bgm021bb33c_Play(u16 id) {
    SndQueue *q = data_02097e48.queue;
    if (q->flag0) {
        if (!(q->unk_06 == 0xffff && q->unk_04 == id)) {
            if (q->unk_02 != 10 && q->unk_02 != 0) {
                if (q->unk_06 != 0xffff) {
                    func_0204aab0(q, q->unk_06);
                }
                q->unk_02 = 1;
            } else {
                q->unk_02 = 0;
            }
            q->unk_06 = id;
            q->unk_08 = 10;
        }
    }
}

static inline void Bgm021bb33c_Resume(void) {
    SndQueue *q = data_02097e48.queue;
    if (q->flag0) {
        u16 cur = func_0204aac4(q);
        if (!(q->unk_06 == 0xffff && q->unk_04 == cur)) {
            if (cur == 0xffff) {
                if (q->flag2 == 1 && q->flag3) {
                    q->unk_06 = 0x8000;
                    q->unk_08 = 10;
                    q->unk_02 = 0;
                }
            } else {
                q->unk_06 = cur;
                q->unk_08 = 10;
                q->unk_02 = 0;
            }
            func_0204aa90(q);
        }
    }
}

static inline void Bgm021bb33c_Start(void) {
    if (func_020594bc(data_02fe152c, 5, 1, 10) == 0) {
        Bgm021bb33c_Play(0xb);
    } else {
        Bgm021bb33c_Play(0x47);
    }
}

static inline BOOL Fx021bb33c_Ready(Fx021bb33c *fx) {
    return fx->state == 3 ? TRUE : FALSE;
}

static inline BOOL Game021bb33c_Is4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[0] == 4 ? TRUE : FALSE;
}

BOOL func_ov000_021bb33c(Obj021bb2b0 *self) {
    switch (self->state) {
    case 1: {
        Fx021bb33c *fx = NULL;
        switch (self->unk_04) {
        case 0:
            fx = func_02066df0();
            self->fx = fx;
            break;
        case 1:
            Bgm021bb33c_Start();
            fx = func_02066ec8();
            self->fx = fx;
            break;
        case 2:
            Bgm021bb33c_Resume();
            fx = func_02066f90();
            self->fx = fx;
            break;
        case 3:
            fx = func_02066c58();
            self->fx = fx;
            break;
        case 4:
            switch (self->unk_0c) {
            case 0x2711:
                fx = func_02066df0();
                self->fx = fx;
                break;
            case 0x2712:
                Bgm021bb33c_Start();
                fx = func_02066ec8();
                self->fx = fx;
                break;
            case 0x2713:
                Bgm021bb33c_Resume();
                fx = func_02066f90();
                self->fx = fx;
                break;
            case 0x2715:
                fx = func_02067058();
                self->fx = fx;
                break;
            case 0x2716:
                fx = func_02067120();
                self->fx = fx;
                break;
            case 0x2717:
                self->fx = func_02065f88(self->unk_0c, &self->pos);
                break;
            default:
                self->fx = func_02065f88(((const Obj021bb2b0 *)self)->unk_0c, &self->pos);
                break;
            }
            if (!self->unk_08) {
                self->fx = NULL;
                return FALSE;
            }
            break;
        }
        if (fx != NULL) {
            fx->unk_1c0 = func_ov000_021bb298;
        }
        self->fx->unk_3c = 0;
        self->state = 10;
        break;
    }
    case 10:
        if (Fx021bb33c_Ready(self->fx)) {
            if (Game021bb33c_Is4()) {
                func_0203cb78(0xa000, 2, 0);
            }
            self->fx->unk_3c = 0x1000;
            self->state = 0xb;
        }
        break;
    }
    if (func_02065748(data_0214a420, self->fx)) {
        return TRUE;
    }
    self->fx = NULL;
    return FALSE;
}

}
