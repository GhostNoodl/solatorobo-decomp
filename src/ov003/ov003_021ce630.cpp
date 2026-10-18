#include "ov003/Vec.h"

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
extern "C" Ov003Game30 *data_ov000_021ccd30;
extern "C" void STD_CopyString(char *dst, const char *src);

struct Ov003Slot3 {
    u8 sub[3][0x30];
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

class Ov003Effect {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetTime(s32 t);
    u8 unk_04[0x20];
    s32 handle;
};

static inline void Ov003Log_Add(s32 type, const char *text) {
    Ov003Log *log;
    if (data_ov000_021ccd30->hud != NULL && (log = data_ov000_021ccd30->hud->log) != NULL) {
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

extern "C" Ov003Save *data_0214a424;
extern "C" void *data_02097e4c;
extern "C" void func_02049bdc(void *mgr, s32 a, s32 b);

static inline void Ov003_AddMeter(u16 add) {
    u16 c;
    if (data_0214a424->mode != 1) {
        return;
    }
    c = data_0214a424->unk_26;
    if (c < 0x2d0) {
        c += add;
        if (c >= 0x2d0) {
            func_02049bdc(data_02097e4c, 0x44, 5);
            c = 0x2d0;
        }
    } else {
        c = 0x2d0;
    }
    data_0214a424->unk_26 = c;
}

static inline void Ov003Log_AddEmpty(s32 type) {
    Ov003Log *log;
    if (data_ov000_021ccd30->hud != NULL && (log = data_ov000_021ccd30->hud->log) != NULL) {
        log->entries[log->idx].type = type;
        log->entries[log->idx].text[0] = 0;
        log->idx++;
        if (log->idx >= 16) {
            log->idx = 0;
        }
    }
}

extern "C" {

extern Ov003Save *data_0214a424;
extern void *data_02097e4c;
extern Ov003Player *func_ov000_0219bf90(void);
extern s16 *func_ov000_02191f18(s16 *p, Ov003Hit *hit);
extern s32 func_ov003_021ce5b8(u32 color);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_0204a028(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern u16 func_0206d37c(Ov003Save *save, s32 a);
extern u16 func_ov003_021ce6fc(u16 v);
extern void NNS_G3dGetCurrentMtx(void *p, s32 a);
extern u8 data_ov000_021c9fe4;
extern void *data_02149ef8;
extern BOOL func_020621f8(void);
extern Ov003Area *func_0206ef10(u16 id);
extern void func_02049bdc(void *mgr, s32 a, s32 b);
extern void func_02040a98(char *buf, u16 v);
extern u32 *func_ov000_0219bf7c(void);
extern Ov003Effect *func_02065f88(s32 id, const Ov003Vec *pos);
extern const char *func_0204c0e8(void *mgr, s32 id);
extern void func_ov003_021cebe8(s32 n);

s16 *func_ov003_021ce630(s16 *p, Ov003Hit *hit) {
    Ov003Player *pl;
    u32 color;
    func_ov000_0219bf90();
    if (*p != 1) {
        p = func_ov000_02191f18(p, hit);
    } else {
        p++;
        pl = func_ov000_0219bf90();
        color = pl->res->color;
        if (color & 0x20000000) {
            Ov003Vec pos = pl->pos;
            s32 id;
            if (pl->hard) {
                func_02049f44(data_02097e4c, 0, &pos, 0);
            }
            id = func_ov003_021ce5b8(color);
            if (id >= 0) {
                func_0204a028(data_02097e4c, id, &pos, -5);
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

u16 func_ov003_021ce6fc(u16 v) {
    u16 n;
    if (v == 0) {
        return v;
    }
    if (func_ov000_0219bf90()->hard) {
        u16 a = func_0206d37c(data_0214a424, 0);
        v = a + v;
    }
    n = (u8)data_0214a424->bonus;
    if (n != 0) {
        u8 rank = data_0214a424->rank;
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

u16 func_ov003_021ce79c(u16 v) {
    u16 r = func_ov003_021ce6fc(v);
    if (r == 0) {
        return r;
    }
    r = r >> 1;
    if (r == 0) {
        r = 1;
    }
    return r;
}

u16 func_ov003_021ce7c0(u16 v) {
    u16 base;
    Ov003Player *pl;
    BOOL hard;
    u16 n;
    if (v == 0) {
        return v;
    }
    base = 0;
    pl = func_ov000_0219bf90();
    hard = pl->hard ? TRUE : base;
    if (!hard) {
        v = v + (((u32)v << 15) >> 16);
    } else {
        base = func_0206d37c(data_0214a424, 1);
        if (data_0214a424->mode == 1 && pl->boosted) {
            base += 0x32;
        }
    }
    n = (u8)data_0214a424->bonus;
    if (n != 0) {
        u8 rank = data_0214a424->rank;
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

void func_ov003_021ce8c8(Ov003SlotUser *self) {
    Ov003Slot3 *slots = self->owner->slots;
    s32 slot = (self->flags & 0x10) ? self->slot : -1;
    if (slot == slots->id[0] && slots->want0) {
        NNS_G3dGetCurrentMtx(slots->sub[0], 0);
        slots->done0 = 1;
    } else if (slot == slots->id[1] && slots->want1) {
        NNS_G3dGetCurrentMtx(slots->sub[1], 0);
        slots->done1 = 1;
    } else if (slot == slots->id[2] && slots->want2) {
        NNS_G3dGetCurrentMtx(slots->sub[2], 0);
        slots->done2 = 1;
    }
    if (slots->doneMask == slots->wantMask) {
        self->func = NULL;
        self->state = 0;
        slots->doneMask = 0;
        slots->wantMask = 0;
    }
}

void func_ov003_021ce9ac(Ov003SlotUser *self) {
    self->func = func_ov003_021ce8c8;
    self->state = 3;
}

void func_ov003_021ce9c4(u16 exp) {
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
    if (data_0214a424->mode == 1) {
        area = func_0206ef10(data_0214a424->area | 0x8000);
        if (area != NULL) {
            Ov003Player *pl;
            bonus = area->bonus;
            pl = func_ov000_0219bf90();
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
    func_02040a98(buf, bonus);
    Ov003Log_Add(5, buf);
    {
        Ov003Save *s = data_0214a424;
        s->exp += bonus;
        if (s->exp > 99999) {
            s->exp = 99999;
        }
    }
    {
        u16 n = 0;
        s32 lv = data_0214a424->level;
        u32 e = data_0214a424->exp;
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
        func_ov003_021cebe8(n);
    }
}

void func_ov003_021cebe8(s32 n) {
    u8 lv;
    Ov003Player *pl;
    if (n == 0) {
        return;
    }
    lv = data_0214a424->level;
    if (lv >= data_ov000_021c9fe4) {
        return;
    }
    if (lv + n > data_ov000_021c9fe4) {
        n = (u8)(data_ov000_021c9fe4 - lv);
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        Ov003Vec pos = pl->pos;
        Ov003Effect *fx = func_02065f88(0x191, &pos);
        Ov003Hp *hp;
        fx->SetTime(0x1400);
        pl->unk_b44 = fx->handle;
        Ov003Log_AddEmpty(7);
        if (data_02149ef8 != NULL) {
            Ov003Log_Add(0, func_0204c0e8(data_02149ef8, 0x4e));
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
    data_0214a424->level = lv;
    {
        u32 *tbl = func_ov000_0219bf7c();
        Ov003Save *s = data_0214a424;
        if (s->exp < tbl[lv - 1]) {
            s->exp = tbl[lv - 1];
        }
    }
}

}
