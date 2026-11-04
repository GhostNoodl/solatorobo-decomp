#include "ov003/Vec.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "nitro/std.h"

struct Ov003Save {
    u8 unk_00[0x18];
    u16 unk_18_0 : 1;
    u16 mode : 2;
    u16 area : 4;
    u8 level;
    u32 exp;
    u8 unk_20[6];
    u16 unk_26;
    u8 unk_28[0x4f0];
    u32 unk_518_0 : 16;
    u32 rank : 8;
    u32 unk_518_24 : 4;
    u32 bonus : 4;
};

struct Ov003PlayerRes {
    u8 unk_00[0x50];
    u32 color;
};

struct Ov003Hp;

struct Ov003Player {
    u8 unk_00[0x48];
    Ov003PlayerRes *res;
    u8 unk_4c[4];
    Ov003Hp *hp;
    u8 unk_54[0x1c];
    Ov003Vec pos;
    u8 unk_7c[0xaa6];
    u16 unk_b22_0 : 3;
    u16 boosted : 1;
    u32 unk_b24_0 : 1;
    u32 hard : 1;
    u8 unk_b28[0xa];
    u16 unk_b32;
    u16 unk_b34;
    u8 unk_b36[0xe];
    s32 unk_b44;
};

struct Ov003Hit {
    u8 unk_00[0xe4];
    u32 flags;
};

struct Ov003Game30;
extern "C" Ov003Game30 *gMessageQueue;

struct Ov003Slot3 {
    MtxFx43 sub[3]; // current matrices captured during the draw
    u8 id[3];
    union {
        u8 doneMask;
        struct {
            u8 done0 : 1;
            u8 done1 : 1;
            u8 done2 : 1;
        };
    };
    union {
        u8 wantMask;
        struct {
            u8 want0 : 1;
            u8 want1 : 1;
            u8 want2 : 1;
        };
    };
};

struct Ov003SlotOwner {
    u8 unk_00[0x2c];
    Ov003Slot3 *slots;
};

struct Ov003SlotUser;
typedef void (*Ov003SlotFunc)(Ov003SlotUser *self);

struct Ov003SlotUser {
    u8 unk_00[4];
    Ov003SlotOwner *owner;
    u32 flags;
    u8 unk_0c[0x18];
    Ov003SlotFunc func;
    u8 unk_28[0x6a];
    u8 state;
    u8 unk_93[0x1b];
    u8 slot;
};

struct Ov003LogEntry {
    s32 type;
    char text[0x20];
};

struct Ov003Log {
    u32 unk_00;
    Ov003LogEntry entries[16];
    u32 unk_244;
    s32 idx;
};

struct Ov003Hud {
    u8 unk_00[0x7c];
    Ov003Log *log;
};

struct Ov003Game30 {
    u8 unk_00[0x11c];
    Ov003Hud *hud;
};

struct Ov003Area {
    u8 unk_00[5];
    u8 bonus : 4;
    u8 meter : 4;
};

struct Ov003Hp {
    u16 cur;
    u16 max;
    u8 unk_04[6];
    u16 unk_0a;
};

static inline void Ov003Log_Add(s32 type, const char *text) {
    Ov003Log *log;
    if (gMessageQueue->hud != NULL && (log = gMessageQueue->hud->log) != NULL) {
        log->entries[log->idx].type = type;
        if (text == NULL) {
            log->entries[log->idx].text[0] = 0;
        } else {
            STD_CopyString(log->entries[log->idx].text, text);
        }
        log->idx++;
        if (log->idx >= 16) {
            log->idx = 0;
        }
    }
}

extern "C" Ov003Save *gStageFlags;
extern "C" s32 SndMgr_PlayPan(void *mgr, s32 a, s32 b);

static inline void Ov003_AddMeter(u16 add) {
    u16 c;
    if (gStageFlags->mode != 1) {
        return;
    }
    c = gStageFlags->unk_26;
    if (c < 0x2d0) {
        c += add;
        if (c >= 0x2d0) {
            SndMgr_PlayPan(gSndMgr, 0x44, 5);
            c = 0x2d0;
        }
    } else {
        c = 0x2d0;
    }
    gStageFlags->unk_26 = c;
}

static inline void Ov003Log_AddEmpty(s32 type) {
    Ov003Log *log;
    if (gMessageQueue->hud != NULL && (log = gMessageQueue->hud->log) != NULL) {
        log->entries[log->idx].type = type;
        log->entries[log->idx].text[0] = 0;
        log->idx++;
        if (log->idx >= 16) {
            log->idx = 0;
        }
    }
}

extern "C" {

extern Ov003Save *gStageFlags;
extern Ov003Player *ActorMgr_FindPlayer(void);
extern s16 *AnimEvent_Exec(s16 *p, Ov003Hit *hit);
extern s32 Ov003_SurfaceSoundId(u32 color);
extern u8 StageFlags_GetCounter(Ov003Save *save, s32 a);
extern u16 Ov003_ScaleDamage(u16 v);
extern u8 data_ov000_021c9fe4;
extern void *gMsgRes;
extern BOOL func_020621f8(void);
extern Ov003Area *Param_GetRecord(u16 id);
extern s32 SndMgr_PlayPan(void *mgr, s32 a, s32 b);
extern void Str_FormatInt(char *buf, u16 v);
extern u32 *func_ov000_0219bf7c(void);
extern const char *MsgRes_GetString(void *mgr, s32 id);
extern void Ov003_AddLevels(s32 n);

s16 *func_ov003_021ce630(s16 *p, Ov003Hit *hit) {
    Ov003Player *pl;
    u32 color;
    ActorMgr_FindPlayer();
    if (*p != 1) {
        p = AnimEvent_Exec(p, hit);
    } else {
        p++;
        pl = ActorMgr_FindPlayer();
        color = pl->res->color;
        if (color & 0x20000000) {
            Ov003Vec pos = pl->pos;
            s32 id;
            if (pl->hard) {
                SndMgr_PlayAt(gSndMgr, 0, &pos, 0);
            }
            id = Ov003_SurfaceSoundId(color);
            if (id >= 0) {
                SndMgr_PlayAtPitch(gSndMgr, id, &pos, -5);
            }
        }
        hit->flags |= 2;
    }
    return p;
}

static inline u16 Ov003Save_Bonus(Ov003Save *save) {
    u16 n = (u8)save->bonus;
    if (n != 0) {
        u8 rank = save->rank;
        if ((u8)(rank & ~0xc0) > 0x14) {
            n--;
        }
    }
    return n;
}

u16 Ov003_ScaleDamage(u16 v) {
    u16 n;
    if (v == 0) {
        return v;
    }
    if (ActorMgr_FindPlayer()->hard) {
        u16 a = StageFlags_GetCounter(gStageFlags, 0);
        v = a + v;
    }
    n = (u8)gStageFlags->bonus;
    if (n != 0) {
        u8 rank = gStageFlags->rank;
        if ((u8)(rank & ~0xc0) > 0x14) {
            n--;
        }
        if (n >= 2) {
            if (v > 0x1e) {
                v -= 0x1e;
            } else {
                v = 1;
            }
        }
    }
    return v;
}

u16 Ov003_ScaleDamageHalf(u16 v) {
    u16 r = Ov003_ScaleDamage(v);
    if (r == 0) {
        return r;
    }
    r = r >> 1;
    if (r == 0) {
        r = 1;
    }
    return r;
}

u16 Ov003_ScaleReward(u16 v) {
    u16 base;
    Ov003Player *pl;
    BOOL hard;
    u16 n;
    if (v == 0) {
        return v;
    }
    base = 0;
    pl = ActorMgr_FindPlayer();
    hard = pl->hard ? TRUE : base;
    if (!hard) {
        v = v + (((u32)v << 15) >> 16);
    } else {
        base = StageFlags_GetCounter(gStageFlags, 1);
        if (gStageFlags->mode == 1 && pl->boosted) {
            base += 0x32;
        }
    }
    n = (u8)gStageFlags->bonus;
    if (n != 0) {
        u8 rank = gStageFlags->rank;
        if ((u8)(rank & ~0xc0) > 0x14) {
            n--;
        }
        if (n >= 2) {
            v += 100;
        } else if (n >= 1) {
            v += 0x50;
        }
    }
    if (v > base) {
        return v - base;
    }
    return 1;
}

void Ov003SlotUser_CaptureMtx(Ov003SlotUser *self) {
    Ov003Slot3 *slots = self->owner->slots;
    s32 slot = (self->flags & 0x10) ? self->slot : -1;
    if (slot == slots->id[0] && slots->want0) {
        NNS_G3dGetCurrentMtx(&slots->sub[0], NULL);
        slots->done0 = 1;
    } else if (slot == slots->id[1] && slots->want1) {
        NNS_G3dGetCurrentMtx(&slots->sub[1], NULL);
        slots->done1 = 1;
    } else if (slot == slots->id[2] && slots->want2) {
        NNS_G3dGetCurrentMtx(&slots->sub[2], NULL);
        slots->done2 = 1;
    }
    if (slots->doneMask == slots->wantMask) {
        self->func = NULL;
        self->state = 0;
        slots->doneMask = 0;
        slots->wantMask = 0;
    }
}

void Ov003SlotUser_StartCapture(Ov003SlotUser *self) {
    self->func = Ov003SlotUser_CaptureMtx;
    self->state = 3;
}

void Ov003_AddExp(u16 exp) {
    Ov003Area *area;
    u16 bonus;
    BOOL boosted;
    char buf[0x20];
    if (func_020621f8()) {
        return;
    }
    if (exp == 0) {
        return;
    }
    boosted = FALSE;
    bonus = 0;
    if (gStageFlags->mode == 1) {
        area = Param_GetRecord(gStageFlags->area | 0x8000);
        if (area != NULL) {
            Ov003Player *pl;
            bonus = area->bonus;
            pl = ActorMgr_FindPlayer();
            if (pl != NULL) {
                if (pl->boosted) {
                    boosted = TRUE;
                }
                if (!boosted) {
                    Ov003_AddMeter((u16)((exp >> 3) + 0x2d) + area->meter);
                }
            }
        }
    }
    bonus += exp;
    Str_FormatInt(buf, bonus);
    Ov003Log_Add(5, buf);
    {
        Ov003Save *s = gStageFlags;
        s->exp += bonus;
        if (s->exp > 99999) {
            s->exp = 99999;
        }
    }
    {
        u16 n = 0;
        s32 lv = gStageFlags->level;
        u32 e = gStageFlags->exp;
        u32 *tbl;
        if ((u32)lv < 1) {
            lv = 1;
        }
        tbl = func_ov000_0219bf7c();
        for (; lv < data_ov000_021c9fe4; lv++) {
            if (e < tbl[lv]) {
                break;
            }
            n++;
        }
        Ov003_AddLevels(n);
    }
}

void Ov003_AddLevels(s32 n) {
    u8 lv;
    Ov003Player *pl;
    if (n == 0) {
        return;
    }
    lv = gStageFlags->level;
    if (lv >= data_ov000_021c9fe4) {
        return;
    }
    if (lv + n > data_ov000_021c9fe4) {
        n = (u8)(data_ov000_021c9fe4 - lv);
    }
    pl = ActorMgr_FindPlayer();
    if (pl != NULL) {
        Ov003Vec pos = pl->pos;
        EffectObj *fx = Effect_SpawnId(0x191, &pos);
        Ov003Hp *hp;
        fx->SetScaleAll(0x1400);
        pl->unk_b44 = fx->id;
        Ov003Log_AddEmpty(7);
        if (gMsgRes != NULL) {
            Ov003Log_Add(0, MsgRes_GetString(gMsgRes, 0x4e));
        }
        hp = pl->hp;
        hp->unk_0a = 0x78;
        if (pl->unk_b32 < 0x5a) {
            pl->unk_b32 = 0x5a;
        }
        pl->unk_b34 = 0;
        {
            u16 m = hp->max + (u16)(n * 100);
            hp->max = m;
            hp->cur = m;
        }
    }
    lv += (u8)n;
    gStageFlags->level = lv;
    {
        u32 *tbl = func_ov000_0219bf7c();
        Ov003Save *s = gStageFlags;
        if (s->exp < tbl[lv - 1]) {
            s->exp = tbl[lv - 1];
        }
    }
}

}
