#include "types.h"

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
} Ov003PkOwner;

typedef struct {
    u8 unk_00[3];
    u8 type;
    u8 unk_04[4];
    u16 amount;
    u16 unk_0a;
    u8 unk_0c[0xc];
    u8 unk_18_0 : 6;
    u8 neg : 1;
    u8 unk_19[3];
    u16 unk_1c;
} Ov003PkItem;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003PkVec;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
    u8 unk_1a[0x32];
    Ov003PkItem *item;
    u8 unk_50[0x14];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
} Ov003Pickup;

typedef struct {
    u32 unk_00;
    s32 type;
    char str[0x1c];
} Ov003LogEntry;

typedef struct {
    Ov003LogEntry e[16];
    u8 unk_240[8];
    s32 n;
} Ov003Log;

typedef struct {
    u8 unk_00[0x7c];
    Ov003Log *log;
} Ov003LogOwner;

typedef struct {
    u8 unk_00[0x11c];
    Ov003LogOwner *unk_11c;
} Ov003Game30;

typedef struct {
    u8 unk_00[0xc];
    u32 money;
    u8 unk_10[0x10];
    u32 unk_20;
    u16 unk_24;
    u8 unk_26[0x5ee];
    u32 unk_614;
} Ov003Save;

typedef struct {
    u8 unk_00[0x4c];
    u8 *unk_4c;
} Ov003DataRes;

extern "C" {
extern Ov003Game30 *data_ov000_021ccd30;
extern void *data_ov000_021ccd54;
extern Ov003Save *data_0214a424;
extern void *data_02097e4c;
extern Ov003DataRes *data_02fe152c;
extern void *data_02149ef8;
Ov003PkOwner *func_ov000_02199ba0(Ov003PkItem *item);
void func_ov000_0219aae8(Ov003Pickup *self, Ov003PkOwner *owner, u16 a, u8 b, u16 mask, Ov003PkVec *v, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_ov000_0218d398(Ov003PkOwner *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_02040a98(void *buf, u32 n);
void STD_CopyString(char *dst, const char *src);
void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_02049bdc(void *a, s32 b, s32 c);
void func_ov003_021ce9c4(u16 id);
u32 func_0205975c(Ov003DataRes *res, u32 idx);
void *func_0205976c(Ov003DataRes *res, u32 idx);
u16 func_02059544(Ov003DataRes *res, void *block, void *entries, int packed, u32 id);
void func_0205c234(s32 a, s32 b);
BOOL func_0206f5e4(u16 id, int n);
BOOL func_0206f21c(u16 id, int n);
const char *func_0206ec48(u16 id);
void func_ov000_02184ee0(void *g, u16 id);
void func_ov000_02184ea4(void *g, u16 id);
const char *func_0204c0e8(void *a, s32 id);
}

static inline void Ov003Log_Push(s32 type, const char *s) {
    Ov003LogOwner *o = data_ov000_021ccd30->unk_11c;
    Ov003Log *log;
    if (o != NULL && (log = o->log) != NULL) {
        log->e[log->n].type = type;
        if (s != NULL) {
            STD_CopyString((char *)log + 8 + log->n * 0x24, s);
        } else {
            log->e[log->n].str[0] = 0;
        }
        if (++log->n >= 16) {
            log->n = 0;
        }
    }
}

static inline void Ov003Log_PushEmpty(s32 type) {
    Ov003LogOwner *o = data_ov000_021ccd30->unk_11c;
    Ov003Log *log;
    if (o != NULL && (log = o->log) != NULL) {
        log->e[log->n].type = type;
        log->e[log->n].str[0] = 0;
        if (++log->n >= 16) {
            log->n = 0;
        }
    }
}

static inline void Ov003Pk_VecSet(Ov003PkVec *v, s32 x, s32 y, s32 z) { v->x = x; v->y = y; v->z = z; }


static inline u16 Ov003Pk_Mask(Ov003PkOwner *o, u16 mask) {
    if (mask == 0) {
        mask = 0xffff;
    }
    if (o != NULL) {
        mask &= (u16)~(1 << ((u16)(o->unk_0c & 0xf000) >> 12));
    }
    return mask;
}

extern "C" void func_ov003_021f0c60(Ov003Pickup *self, u16 mask) {
    Ov003PkItem *item = self->item;
    Ov003PkOwner *owner = func_ov000_02199ba0(item);
    switch (item->type) {
    case 1: {
        s32 y = self->unk_64 + 0xccd;
        Ov003PkVec v;
        Ov003PkOwner *o;
        s32 f;
        if (y < 0x199a) {
            y = 0x199a;
        }
        Ov003Pk_VecSet(&v, 0, self->unk_6c, 0);
        o = func_ov000_02199ba0(item);
        mask = Ov003Pk_Mask(o, mask);
        f = 100;
        if (item->neg) {
            f = -1;
        }
        func_ov000_0219aae8(self, o, item->amount, item->unk_0a, mask, &v, 0, y, 0, f, 0x1000);
        item->unk_1c = 0xffff;
        break;
    }
    case 2: {
        Ov003PkOwner *o = func_ov000_02199ba0(item);
        mask = Ov003Pk_Mask(o, mask);
        s32 f = 100;
        if (item->neg) {
            f = -1;
        }
        func_ov000_0219aae8(self, o, item->amount, item->unk_0a, mask, NULL, 0, self->unk_64, self->unk_68, f, 0x1000);
        item->unk_1c = 0xffff;
        break;
    }
    case 3: {
        u16 amt = item->amount;
        char buf[0x20];
        func_ov000_0218d398(owner, self->unk_0c, 10, TRUE, 2, &amt);
        func_02040a98(buf, item->amount);
        Ov003Log_PushEmpty(6);
        break;
    }
    case 4: {
        char buf[0x20];
        {
            Ov003Save *g = data_0214a424;
            g->unk_20 += item->amount;
            if (g->unk_20 > 99999) {
                g->unk_20 = 99999;
            }
        }
        if (data_0214a424->money + item->amount >= 999999) {
            data_0214a424->money = 999999;
        } else {
            data_0214a424->money += item->amount;
        }
        func_02040a98(buf, item->amount);
        Ov003Log_Push(2, buf);
        func_02049a48(data_02097e4c, 0x31, -1, -1, -1);
        break;
    }
    case 6:
        func_ov003_021ce9c4(item->amount);
        break;
    case 5: {
        char buf[0x20];
        Ov003Save *g = data_0214a424;
        g->unk_24 += item->amount;
        if (g->unk_24 > 9999) {
            g->unk_24 = 9999;
        }
        func_02040a98(buf, item->amount);
        Ov003Log_Push(3, buf);
        func_02049bdc(data_02097e4c, 0x21, 2);
        break;
    }
    case 9: {
        char buf[0x20];
        s32 n = self->unk_18;
        u32 t;
        if (n <= 0 || n > 9999) {
            n = 1;
        }
        t = n + data_0214a424->unk_614;
        if (t > 9999) {
            t = 9999;
        }
        data_0214a424->unk_614 = t;
        func_02040a98(buf, n);
        Ov003Log_Push(4, buf);
        func_02049bdc(data_02097e4c, 0x89, 5);
        {
            u8 *base;
            BOOL found;
            u32 i;
            u32 count;
            void *tbl;
            count = func_0205975c(data_02fe152c, 8);
            base = data_02fe152c->unk_4c;
            tbl = func_0205976c(data_02fe152c, 8);
            found = FALSE;
            for (i = 0; i < count; i++) {
                if (func_02059544(data_02fe152c, base + 0x110, tbl, 1, (u16)i)) {
                    found = TRUE;
                    break;
                }
            }
            if (found) {
                func_0205c234(0x62, 0);
            }
        }
        break;
    }
    case 7: {
        u16 id = self->unk_18;
        if (item->amount != 5) {
            break;
        }
        if (id < 0x6000 || id >= 0x6040) {
            id += 0x6000;
            if (id < 0x6000 || id >= 0x6040) {
                break;
            }
        }
        func_0206f5e4(id, 1);
        func_ov000_02184ee0(data_ov000_021ccd54, id);
        break;
    }
    case 8: {
        u16 id = self->unk_18;
        if (id < 0x2000 || id >= 0x2053) {
            id += 0x2000;
            if (id < 0x2000 || id >= 0x2053) {
                id = 0x2000;
            }
        }
        if (func_0206f21c(id, 1)) {
            Ov003Log_Push(1, func_0206ec48(id));
        } else {
            func_ov000_02184ea4(data_ov000_021ccd54, id);
        }
        break;
    }
    case 10:
        Ov003Log_Push(0, func_0204c0e8(data_02149ef8, 0x63));
        func_02049bdc(data_02097e4c, 0x1e, -5);
        break;
    case 11:
        Ov003Log_Push(0, func_0204c0e8(data_02149ef8, 0x63));
        func_02049bdc(data_02097e4c, 0x1e, -5);
        break;
    }
}
