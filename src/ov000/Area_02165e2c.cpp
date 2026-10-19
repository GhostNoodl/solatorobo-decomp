#include "types.h"

typedef struct {
    u8 pad[4];
    s32 lo;
    s32 hi;
    u8 pad0c[8];
    u8 key;
    u8 pad15[3];
} Ent02165e2c;

typedef struct {
    u8 pad[0xb];
    u8 count;
    u8 pad0c[0xc];
    Ent02165e2c *ents;
} Area02165e2c;

typedef struct {
    u8 pad[0x88];
    Area02165e2c *areas[32];
    u8 unk_108;
    u8 unk_109;
    u16 unk_10a;
    u16 unk_10c;
} Ctx02165e2c;

typedef struct {
    u8 pad[0xcdc];
    Ctx02165e2c *ctx;
} Sub02165e2c;

typedef struct {
    u8 pad[0x30];
    Sub02165e2c *sub;
} Obj02165e2c;

typedef struct {
    u8 pad[0x74];
    s32 unk_74;
} Pl02165e2c;

extern "C" {

Pl02165e2c *func_ov000_0219bf90(void);

static inline BOOL Active02165e2c(Ctx02165e2c *c) {
    if (c == NULL || c->unk_10a == 0) {
        return FALSE;
    }
    return TRUE;
}

Ent02165e2c *func_ov000_02165e2c(Obj02165e2c *self, Area02165e2c *area) {
    Ctx02165e2c *c;
    u8 j;
    u8 i;
    c = self->sub->ctx;
    j = 0;
    if (!Active02165e2c(c)) {
        Pl02165e2c *pl = func_ov000_0219bf90();
        if (pl == NULL) {
            return NULL;
        } else {
            Ent02165e2c *e;
            u8 k;
            s32 v;
            e = area->ents;
            v = pl->unk_74;
            for (k = 0; k < area->count; k++, e++) {
                if (e->lo <= v && v < e->hi) {
                    return e;
                }
            }
        }
    } else {
        Area02165e2c *next;
        Ent02165e2c *ents;
        s32 idx;
        ents = area->ents;
        next = NULL;
        for (i = 0; i < area->count; i++) {
            if (c->unk_109 == ents[i].key) {
                return &ents[i];
            }
        }
        idx = c->unk_10c + 1;
        if (idx < self->sub->ctx->unk_108) {
            next = c->areas[idx];
        }
        if (next == NULL) {
            return ents;
        }
        for (i = 0; i < area->count; i++) {
            for (j = 0; j < next->count; j++) {
                if (ents[i].key == next->ents[i].key) {
                    return &ents[i];
                }
            }
        }
        return ents;
    }
    return NULL;
}

}
