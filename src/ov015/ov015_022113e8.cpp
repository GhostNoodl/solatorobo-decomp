#include "ov015/ov015.h"

extern "C" {

void MI_CpuFill8(void *dst, u32 value, u32 size);
u8 *func_0206ee20(u16 id);
s32 func_02040498(s32 max);
s32 func_02040528(s32 max);
extern const u16 data_ov015_0221265c[];
extern const u16 data_ov015_02212660[];
extern const u16 data_ov015_0221267a[];
extern const u16 data_ov015_0221266a[];

struct Ov015ItemEnt {
    u16 id;
    u16 pad;
    s32 count;
};

static inline s32 Ov015_Pick(const u16 *tbl, s32 max, s32 mod, s32 amt, s32 id) {
    s32 start = func_02040498(max);
    s32 i;
    for (i = (start + 1) % mod; i != start; i = (i + 1) % mod) {
        id = tbl[i];
        if (amt == 0 || FLD(u16, func_0206ee20(id), 0x2) < amt) {
            break;
        }
    }
    return id;
}

static inline BOOL Ov015_InList(const Ov015ItemEnt *list, s32 cnt, s32 id) {
    s32 j;
    BOOL found = FALSE;
    for (j = 0; j < cnt; j++) {
        if (list[j].id != 0xffff && id == list[j].id) {
            found = TRUE;
        }
    }
    return found;
}

static inline BOOL Ov015_InTable(const u16 *tbl, s32 n, s32 id) {
    BOOL found = FALSE;
    s32 j;
    for (j = 0; j < n; j++) {
        if (id == tbl[j]) {
            found = TRUE;
            break;
        }
    }
    return found;
}

void func_ov015_022113e8(void *self, Ov015ItemEnt *list, s32 n, u16 a, s32 budget) {
    s32 cnt;
    s32 i;
    s32 j;
    s32 rest;
    s32 price;
    s32 num;
    s32 sub;
    s32 id;
    if (list == NULL || n <= 0) {
        return;
    }
    cnt = 0;
    MI_CpuFill8(list, 0, n * 8);
    // rest first holds the random scale (fx32, 1.0 and up), then the amount it scales
    rest = func_02040528(budget) + 0x1000;
    rest = (s32)(((s64)(a << 12) * rest + 0x800) >> 12) >> 12;
    while (rest > 0 && cnt < n) {
        id = 0xffff;
        if (rest < 20) {
            id = Ov015_Pick(data_ov015_0221265c, 1, 2, rest, id);
        } else if (rest < 200) {
            id = Ov015_Pick(data_ov015_02212660, 4, 5, rest, id);
        } else if (rest < 2000) {
            id = Ov015_Pick(data_ov015_0221267a, 8, 9, rest, id);
        } else {
            id = Ov015_Pick(data_ov015_0221266a, 7, 8, rest, id);
        }
        if (Ov015_InList(list, cnt, id)) {
            continue;
        }
        if (id != 0xffff) {
            price = FLD(u16, func_0206ee20(id), 0x2);
            if (Ov015_InTable(data_ov015_0221266a, 8, id)) {
                num = rest / price;
                if (num >= 2) {
                    num = 2;
                }
                sub = price * num;
            } else {
                if (Ov015_InTable(data_ov015_0221267a, 9, id)) {
                    num = func_02040498(5) + 15;
                    if (num > rest / price) {
                        num = rest / price;
                    }
                    sub = price * num;
                } else {
                    num = rest / price;
                    sub = price * num;
                }
            }
        } else {
            num = 0;
            sub = num;
        }
        list[cnt].id = id;
        list[cnt].count = num;
        cnt++;
        rest -= sub;
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > 1; j--) {
            u16 lo = list[j - 1].id;
            u16 hi = list[j].id;
            if (hi > lo) {
                s32 c = list[j].count;
                list[j].id = lo;
                list[j].count = list[j - 1].count;
                list[j - 1].id = hi;
                list[j - 1].count = c;
            }
        }
    }
}

}
