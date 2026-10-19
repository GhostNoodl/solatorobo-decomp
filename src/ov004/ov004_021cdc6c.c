#include "types.h"

// DSProtect integrity checks: each one checksums a list of check routines, calls them and
// picks the real or the decoy callback depending on the result.

typedef struct {
    u32 (*ok)(u32 a, u32 b);
    u32 (*fn)(u32 a, u32 b);
    u32 a;
    u32 b;
    u32 result;
    u32 code;
} Ov004Call;

typedef s32 (*Ov004CheckFn)(Ov004Call *c);

extern u8 data_ov004_021cf868[];
extern u8 data_ov004_021cf86c[];
extern u8 func_ov004_021cd4c0[];
extern u8 func_ov004_021cd548[];
extern u8 func_ov004_021cd5d0[];
extern u8 func_ov004_021cd658[];
extern u8 func_ov004_021cf544[];
extern u8 func_ov004_021cf5cc[];
extern u8 func_ov004_021cf654[];
extern u8 func_ov004_021cf6dc[];

#define ENC(p) ((p) + 0x3200)
#define DEC(x) ((u32)(x) - 0x3200)

#pragma force_active on

u32 func_ov004_021cdc6c(u32 a, u32 b) {
    u32 list[32];
    Ov004Call ctx;
    u32 *lp;
    u32 sum;
    u32 *tbl;
    tbl = (u32 *)DEC(ENC(data_ov004_021cf86c));
    ctx.ok = (u32 (*)(u32, u32))tbl[*(u32 *)DEC(ENC(data_ov004_021cf868))];
    list[0] = (u32)ENC(func_ov004_021cf544);
    list[2] = 0;
    list[1] = (u32)ENC(func_ov004_021cd5d0);
    ctx.fn = (u32 (*)(u32, u32))tbl[*(u32 *)DEC(ENC(data_ov004_021cf868)) ^ 1];
    ctx.a = a;
    ctx.b = b;
    ctx.result = 0;
    ctx.code = 0;
    sum = 0x30eb87;
    lp = list;
    do {
        u32 k = 0x1c;
        u32 *q = (u32 *)DEC(*lp);
        u32 c = 0;
        s32 r;
        do {
            u32 w = *q;
            q++;
            c ^= (w >> k) | (w << (32 - k));
        } while (--k != 0);
        if (c != 0x786385f) {
            if (ctx.result != 0) {
                return ctx.result;
            }
            return ctx.fn(a, b);
        }
        r = ((Ov004CheckFn)DEC(*lp))(&ctx);
        if (r == 0 && ctx.code == 0) {
            if (ctx.result != 0) {
                return ctx.result;
            }
            return ctx.fn(a, b);
        }
        sum += r;
    } while (*++lp != 0);
    if (sum % 0xf1 == 0) {
        return ctx.ok(a, b);
    }
    if (ctx.code != 0) {
        return ctx.result;
    }
    return ctx.fn(a, b);
}

u32 func_ov004_021cde0c(u32 a, u32 b) {
    u32 list[32];
    Ov004Call ctx;
    u32 *lp;
    u32 sum;
    u32 *tbl;
    tbl = (u32 *)DEC(ENC(data_ov004_021cf86c));
    ctx.ok = (u32 (*)(u32, u32))tbl[*(u32 *)DEC(ENC(data_ov004_021cf868))];
    list[0] = (u32)ENC(func_ov004_021cf5cc);
    list[2] = 0;
    list[1] = (u32)ENC(func_ov004_021cd658);
    ctx.fn = (u32 (*)(u32, u32))tbl[*(u32 *)DEC(ENC(data_ov004_021cf868)) ^ 1];
    ctx.a = a;
    ctx.b = b;
    ctx.result = 0;
    ctx.code = 0;
    sum = 0x30eb87;
    lp = list;
    do {
        u32 k = 0x1c;
        u32 *q = (u32 *)DEC(*lp);
        u32 c = 0;
        s32 r;
        do {
            u32 w = *q;
            q++;
            c ^= (w >> k) | (w << (32 - k));
        } while (--k != 0);
        if (c != 0x786385f) {
            if (ctx.result != 0) {
                return ctx.result;
            }
            return ctx.fn(a, b);
        }
        r = ((Ov004CheckFn)DEC(*lp))(&ctx);
        if (r == 0 && ctx.code == 0) {
            if (ctx.result != 0) {
                return ctx.result;
            }
            return ctx.fn(a, b);
        }
        sum += r;
    } while (*++lp != 0);
    if (sum % 0xfb == 0) {
        return ctx.ok(a, b);
    }
    if (ctx.code != 0) {
        return ctx.result;
    }
    return ctx.fn(a, b);
}

u32 func_ov004_021cdfac(u32 a, u32 b) {
    u32 list[32];
    Ov004Call ctx;
    u32 *lp;
    u32 sum;
    u32 *tbl;
    tbl = (u32 *)DEC(ENC(data_ov004_021cf86c));
    ctx.ok = (u32 (*)(u32, u32))tbl[*(u32 *)DEC(ENC(data_ov004_021cf868))];
    list[0] = (u32)ENC(func_ov004_021cf654);
    list[2] = 0;
    list[1] = (u32)ENC(func_ov004_021cd4c0);
    ctx.fn = (u32 (*)(u32, u32))tbl[*(u32 *)DEC(ENC(data_ov004_021cf868)) ^ 1];
    ctx.a = a;
    ctx.b = b;
    ctx.result = 0;
    ctx.code = 0;
    sum = 0x30eb87;
    lp = list;
    do {
        u32 k = 0x1c;
        u32 *q = (u32 *)DEC(*lp);
        u32 c = 0;
        s32 r;
        do {
            u32 w = *q;
            q++;
            c ^= (w >> k) | (w << (32 - k));
        } while (--k != 0);
        if (c != 0x786385f) {
            if (ctx.result != 0) {
                return ctx.result;
            }
            return ctx.fn(a, b);
        }
        r = ((Ov004CheckFn)DEC(*lp))(&ctx);
        if (r == 0 && ctx.code == 0) {
            if (ctx.result != 0) {
                return ctx.result;
            }
            return ctx.fn(a, b);
        }
        sum += r;
    } while (*++lp != 0);
    if (sum % 0xf1 == 0) {
        return ctx.ok(a, b);
    }
    if (ctx.code != 0) {
        return ctx.result;
    }
    return ctx.fn(a, b);
}

u32 func_ov004_021ce14c(u32 a, u32 b) {
    u32 list[32];
    Ov004Call ctx;
    u32 *lp;
    u32 sum;
    u32 *tbl;
    tbl = (u32 *)DEC(ENC(data_ov004_021cf86c));
    ctx.ok = (u32 (*)(u32, u32))tbl[*(u32 *)DEC(ENC(data_ov004_021cf868))];
    list[0] = (u32)ENC(func_ov004_021cf6dc);
    list[2] = 0;
    list[1] = (u32)ENC(func_ov004_021cd548);
    ctx.fn = (u32 (*)(u32, u32))tbl[*(u32 *)DEC(ENC(data_ov004_021cf868)) ^ 1];
    ctx.a = a;
    ctx.b = b;
    ctx.result = 0;
    ctx.code = 0;
    sum = 0x30eb87;
    lp = list;
    do {
        u32 k = 0x1c;
        u32 *q = (u32 *)DEC(*lp);
        u32 c = 0;
        s32 r;
        do {
            u32 w = *q;
            q++;
            c ^= (w >> k) | (w << (32 - k));
        } while (--k != 0);
        if (c != 0x786385f) {
            if (ctx.result != 0) {
                return ctx.result;
            }
            return ctx.fn(a, b);
        }
        r = ((Ov004CheckFn)DEC(*lp))(&ctx);
        if (r == 0 && ctx.code == 0) {
            if (ctx.result != 0) {
                return ctx.result;
            }
            return ctx.fn(a, b);
        }
        sum += r;
    } while (*++lp != 0);
    if (sum % 0xfb == 0) {
        return ctx.ok(a, b);
    }
    if (ctx.code != 0) {
        return ctx.result;
    }
    return ctx.fn(a, b);
}

#pragma force_active reset
