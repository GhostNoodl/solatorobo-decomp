#include "ov000/FieldCam.h"
#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    VecFx32 pos;
    u16 unk_0c;
    u16 mask;
    u16 kind;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 exclude;
    union {
        u8 flags;
        struct {
            u8 b0 : 1;
            u8 rest : 7;
        } bits;
    };
} Query_021b2f08;

typedef struct {
    Query_021b2f08 *query;
} Finder_021b2f08;

typedef struct {
    Finder_021b2f08 finder;
    Query_021b2f08 q;
} FQ_021b2f08;

typedef struct {
    u8 unk_00[0x22];
    u16 b0 : 2;
    u16 prio : 2;
    u16 rest : 12;
} Part_021b2f08;

typedef struct {
    u8 unk_00[0xc];
    u16 id;
    u16 kind;
    u8 unk_10[0x3c];
    u8 *sub;
} Act_021b2f08;

extern "C" {
s32 func_ov000_02199554(Finder_021b2f08 *f, Query_021b2f08 *q, Part_021b2f08 **list, s32 max);
s32 func_ov000_02199454(Finder_021b2f08 *f, Query_021b2f08 *q, Part_021b2f08 **list, s32 count);
Act_021b2f08 *Obj021984c8_GetActor(Part_021b2f08 *p);
BOOL func_ov000_02199c70(void *sub, u16 kind);
void *Target_Get(void *p);

static inline void Init_021b2f08(FQ_021b2f08 *fq) {
    fq->q.mask = 0;
    fq->q.kind = 0xffff;
    fq->q.exclude = 0xffff;
    fq->q.unk_12 = 0;
    fq->q.unk_14 = 0;
    fq->q.unk_18 = 0;
    fq->q.unk_1c = 0;
    fq->q.unk_20 = 0;
    fq->q.unk_24 = 0;
    fq->q.flags = 0;
}

static inline void SetRange_021b2f08(FQ_021b2f08 *fq, s32 lo, s32 hi) {
    fq->q.unk_20 = lo;
    fq->q.unk_24 = hi;
    fq->q.flags |= 8;
}

static inline Act_021b2f08 *Get_021b2f08(Robo021ca458 *self, Part_021b2f08 *p) {
    Act_021b2f08 *a;
    if (p == NULL) {
        return NULL;
    }
    a = Obj021984c8_GetActor(p);
    if (a == NULL) {
        return NULL;
    }
    if (self->unk_b20 != 0xffff && self->unk_b20 == a->id) {
        return NULL;
    }
    return a;
}

Part_021b2f08 *func_ov000_021b2f08(Robo021ca458 *self, u16 tgt, void *sub, u8 flag) {
    FQ_021b2f08 fq;
    u8 *s;
    Part_021b2f08 *list[0x20];
    Part_021b2f08 *list2[0x20];
    s32 cnt;
    s32 m;
    s32 d;
    s32 y;
    Part_021b2f08 *res = NULL;
    s32 h;
    s32 x;
    s32 n;
    long j;
    s32 z;
    u16 ang;
    Act_021b2f08 *a;
    s32 n2;
    s32 i;
    s32 i2;
    s32 cnt2;
    s32 r;

    Init_021b2f08(&fq);
    fq.q.exclude = self->id;
    x = self->pos.x;
    y = self->pos.y;
    ang = self->rot_y;
    z = self->pos.z;
    r = self->radius;
    if (self->unk_b29_2) {
        flag = TRUE;
    }
    if (flag) {
        FieldCam *cam = &data_ov000_021ccd54->cam;
        ang = FieldCam_GetYaw(cam);
        r += 0x18ccd;
        if (self->unk_b22_0 != 0) {
            r += 0xc666;
        }
        fq.q.bits.b0 = 1;
        if (self->fsm->current == 0xf) {
            fq.q.mask = 0x20;
            fq.q.kind = 0xffff;
        }
        SetRange_021b2f08(&fq, -0xf000, self->height + 0xf000);
    } else {
        s32 w;
        w = 0x2400;
        if (self->unk_b24_1) {
            if (self->unk_b2c_4 >= 2) {
                r = 0x8000;
                d = 0x1800;
            } else if (self->unk_b22_3) {
                r += 0x44cd;
                d = 0xccd;
                w = 0x3000;
            } else {
                r += 0x34cd;
                d = 0xccd;
            }
            fq.q.unk_12 = -w;
            fq.q.unk_14 = w;
        } else {
            fq.q.unk_12 = 0xc800;
            fq.q.unk_14 = 0x3800;
            r += 0x1000;
            d = 0;
        }
        if (d != 0) {
            x -= LO_FX_MUL(d, FX_SinCosTable_[(ang >> 4) * 2]);
            z -= LO_FX_MUL(d, FX_SinCosTable_[(ang >> 4) * 2 + 1]);
        }
        if (tgt != 0) {
            fq.q.mask = tgt;
            fq.q.kind = 0xffff;
            h = self->height;
            if (self->unk_b24_1) {
                h += 0x800;
            }
            SetRange_021b2f08(&fq, -0x59a, h);
        } else {
            SetRange_021b2f08(&fq, -0x2800, self->height + 0x4000);
        }
    }
    fq.q.unk_18 = 0;
    fq.q.pos.x = x;
    fq.q.unk_0c = ang;
    fq.q.pos.y = y;
    fq.q.pos.z = z;
    fq.q.unk_1c = r;
    fq.q.flags |= 6;
    fq.finder.query = NULL;
    n = func_ov000_02199554(&fq.finder, &fq.q, list, 0x20);
    if (n == 0) {
        return NULL;
    }
    if (tgt != 0) {
        for (i = 0; i < n; i++) {
            a = Get_021b2f08(self, list[i]);
            if (a != NULL && func_ov000_02199c70(sub, a->kind)) {
                res = list[i];
                break;
            }
        }
    } else if (flag) {
        for (i2 = 0; i2 < n; i2++) {
            a = Get_021b2f08(self, list[i2]);
            if (a != NULL) {
                if (res == NULL || res->prio < list[i2]->prio) {
                    res = list[i2];
                }
            }
        }
    } else {
        cnt = 0;
        for (i = 0; i < n; i++) {
            u8 k;
            a = Get_021b2f08(self, list[i]);
            if (a == NULL || (s = a->sub) == NULL || Target_Get(s) == self) {
                continue;
            }
            k = s[0];
            if (k == 0 || k == 1 || k == 2) {
                continue;
            }
            if (self->unk_b24_1) {
                if (k == 0xb) {
                    continue;
                }
                if (self->unk_93_4) {
                    if (k == 6 || k == 7 || k == 8 || k == 9 || k == 10) {
                        continue;
                    }
                }
                if (self->unk_b2c_4 >= 2) {
                    if (!(k == 5 || k == 0xe || k == 0xf || k == 0x11 || k == 0x12 || k == 0x13 || k == 0x14)) {
                        continue;
                    }
                }
                if (self->unk_b22_3) {
                    if (k == 0x10) {
                        continue;
                    }
                }
            } else {
                if (self->unk_93_4) {
                    if (k == 0xc || k == 0xd || k == 0x10 || k == 0x12 || k == 0x14 || k == 0x15) {
                        continue;
                    }
                }
            }
            if (k == 0x15 && (self->unk_b1c == 0xffff || !self->unk_b24_1)) {
                continue;
            }
            if (((u32)(u16)(a->id & 0xf000) >> 12) == 5 && k == 0xf) {
                res = list[i];
                break;
            }
            list2[cnt] = list[i];
            cnt++;
        }
        if (res != NULL) {
            return res;
        }
        if (cnt == 0) {
            return NULL;
        }
        Init_021b2f08(&fq);
        SetRange_021b2f08(&fq, -0x59a, self->height + 0x800);
        n2 = func_ov000_02199454(&fq.finder, &fq.q, list2, cnt);
        cnt2 = 0;
        for (j = 0; j < n2; j++) {
            u16 kk;
            u8 k;
            a = Obj021984c8_GetActor(list2[j]);
            kk = (u32)(u16)(a->id & 0xf000) >> 12;
            k = a->sub[0];
            if (kk == 5 || (kk == 4 && k == 0xe && self->unk_b24_1)) {
                res = list2[j];
                break;
            }
            if (kk == 4 && (k == 4 || (!self->unk_b24_1 && (k == 6 || k == 9 || k == 10)))) {
                if (res == NULL) {
                    res = list2[j];
                }
            } else if (kk == 2 || kk == 3) {
                if (res == NULL) {
                    res = list2[j];
                }
            } else {
                list[cnt2] = list2[j];
                cnt2++;
            }
        }
        if (res != NULL) {
            return res;
        }
        if (cnt2 == 0) {
            return NULL;
        }
        Init_021b2f08(&fq);
        h = -0x533;
        if (self->unk_b22_3) {
            h = 0;
        }
        SetRange_021b2f08(&fq, 0x29, h + self->height);
        n2 = func_ov000_02199454(&fq.finder, &fq.q, list, cnt2);
        for (m = 0; m < n2; m++) {
            u16 kk;
            u8 k;
            a = Obj021984c8_GetActor(list[m]);
            kk = (u32)(u16)(a->id & 0xf000) >> 12;
            k = a->sub[0];
            if (kk != 4) {
                res = list[m];
                break;
            }
            if (k == 5 || (self->unk_b24_1 && (k == 0xd || k == 0xf || k == 0x10)) ||
                (!self->unk_b24_1 && (k == 7 || k == 8))) {
                res = list[m];
                break;
            }
            if (res == NULL) {
                res = list[m];
            }
        }
    }
    return res;
}
}
