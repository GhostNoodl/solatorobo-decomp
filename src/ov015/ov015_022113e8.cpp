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

// `budget` is volatile so it is loaded where it is first used, and the loop index `j` is an extra
// trailing parameter (callers pass five arguments); both only steer register allocation.
void func_ov015_022113e8(void *self, Ov015ItemEnt *list, s32 n, u16 a, volatile s32 budget, s32 j) {
    s32 cnt;
    s32 rnd;
    s32 i;
    s32 id;
    s32 start;
    s32 price;
    s32 num;
    s32 sub;
    BOOL found[1];
    s32 rest[1]; // one-element array: register allocation
    if (list == NULL || n <= 0) {
        return;
    }
    cnt = 0;
    MI_CpuFill8(list, 0, n * 8);
    rnd = func_02040528(budget) + 0x1000;
    rest[0] = (s32)(((s64)(a << 12) * rnd + 0x800) >> 12) >> 12;
    while (rest[0] > 0 && cnt < n) {
        id = 0xffff;
        if (rest[0] < 20) {
            id = Ov015_Pick(data_ov015_0221265c, 1, 2, rest[0], id);
        } else if (rest[0] < 200) {
            id = Ov015_Pick(data_ov015_02212660, 4, 5, rest[0], id);
        } else if (rest[0] < 2000) {
            id = Ov015_Pick(data_ov015_0221267a, 8, 9, rest[0], id);
        } else {
            id = Ov015_Pick(data_ov015_0221266a, 7, 8, rest[0], id);
        }
        found[0] = FALSE;
        for (j = 0; j < cnt; j++) {
            if (list[j].id != 0xffff && id == list[j].id) {
                found[0] = TRUE;
            }
        }
        if (found[0]) {
            continue;
        }
        if (id != 0xffff) {
            price = FLD(u16, func_0206ee20(id), 0x2);
            found[0] = FALSE;
            for (j = 0; j < 8; j++) {
                if (id == data_ov015_0221266a[j]) {
                    found[0] = TRUE;
                    break;
                }
            }
            if (found[0]) {
                num = rest[0] / price;
                if (num >= 2) {
                    num = 2;
                }
                sub = price * num;
            } else {
                found[0] = FALSE;
                for (j = 0; j < 9; j++) {
                    if (id == data_ov015_0221267a[j]) {
                        found[0] = TRUE;
                        break;
                    }
                }
                if (found[0]) {
                    num = func_02040498(5) + 15;
                    if (num > rest[0] / price) {
                        num = rest[0] / price;
                    }
                    sub = price * num;
                } else {
                    num = rest[0] / price;
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
        rest[0] -= sub;
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
