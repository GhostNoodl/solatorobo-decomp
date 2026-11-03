#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Vec.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
} Obj0219bf90;

typedef struct {
    s32 state;
    s32 unk_04;
    u8 unk_08;
    s32 unk_0c;
    EffectObj *fx;
    VecFx32 pos;
} Obj021bb2b0;

extern "C" {

Obj0219bf90 *ActorMgr_FindPlayer(void);
extern void *data_02fe152c;
extern s32 data_02097d78[];
void func_ov000_021bb298(NNSG3dRS *self);
u16 DataRes_ReadEntry(void *res, u32 idx, int packed, int sub);
void SndQueue_Push_0204aab0(SndQueue *queue, u16 value);
u16 SndQueue_Peek(SndQueue *queue);
void SndQueue_Pop(SndQueue *queue);
void GfxSys_StartFadeIn(int duration, int mode, int ch);

void func_ov000_021bb2b0(Obj021bb2b0 *self, s32 a, s16 *v, u8 c) {
    self->unk_04 = 4;
    self->unk_0c = a;
    self->unk_08 = c;
    if (v == NULL) {
        Obj0219bf90 *p = ActorMgr_FindPlayer();
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
                    SndQueue_Push_0204aab0(q, q->unk_06);
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
        u16 cur = SndQueue_Peek(q);
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
            SndQueue_Pop(q);
        }
    }
}

static inline void Bgm021bb33c_Start(void) {
    if (DataRes_ReadEntry(data_02fe152c, 5, 1, 10) == 0) {
        Bgm021bb33c_Play(0xb);
    } else {
        Bgm021bb33c_Play(0x47);
    }
}

static inline BOOL Fx021bb33c_Ready(EffectObj *fx) {
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
        Effect3D *fx = NULL;
        switch (self->unk_04) {
        case 0:
            fx = EffectHud_New2711();
            self->fx = fx;
            break;
        case 1:
            Bgm021bb33c_Start();
            fx = EffectHud_New2712();
            self->fx = fx;
            break;
        case 2:
            Bgm021bb33c_Resume();
            fx = EffectHud_New2713();
            self->fx = fx;
            break;
        case 3:
            fx = EffectHud_New2710();
            self->fx = fx;
            break;
        case 4:
            switch (self->unk_0c) {
            case 0x2711:
                fx = EffectHud_New2711();
                self->fx = fx;
                break;
            case 0x2712:
                Bgm021bb33c_Start();
                fx = EffectHud_New2712();
                self->fx = fx;
                break;
            case 0x2713:
                Bgm021bb33c_Resume();
                fx = EffectHud_New2713();
                self->fx = fx;
                break;
            case 0x2715:
                fx = EffectHud_New2715();
                self->fx = fx;
                break;
            case 0x2716:
                fx = EffectHud_New2716();
                self->fx = fx;
                break;
            case 0x2717:
                self->fx = Effect_SpawnId(self->unk_0c, &self->pos);
                break;
            default:
                self->fx = Effect_SpawnId(((const Obj021bb2b0 *)self)->unk_0c, &self->pos);
                break;
            }
            if (!self->unk_08) {
                self->fx = NULL;
                return FALSE;
            }
            break;
        }
        if (fx != NULL) {
            fx->initCallback = (NNSG3dSbcCallBackFunc)func_ov000_021bb298;
        }
        self->fx->speed = 0;
        self->state = 10;
        break;
    }
    case 10:
        if (Fx021bb33c_Ready(self->fx)) {
            if (Game021bb33c_Is4()) {
                GfxSys_StartFadeIn(0xa000, 2, 0);
            }
            self->fx->speed = 0x1000;
            self->state = 0xb;
        }
        break;
    }
    if (EffectMgr_Contains(data_0214a420, self->fx)) {
        return TRUE;
    }
    self->fx = NULL;
    return FALSE;
}

}
