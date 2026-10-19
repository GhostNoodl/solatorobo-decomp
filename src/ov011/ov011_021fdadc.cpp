#include "ov011/ov011.h"


struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

struct Ov011Ring {
    u8 b0 : 1;
    u8 rest : 7;
    u8 pad;
    u16 idx;
    u16 cap;
    u8 pad2[2];
    s32 *buf;
    s32 count;
};

static inline void Ov011Ring_Push(Ov011Ring *r, s32 v) {
    if (r->b0) {
        if (r->count == 0) {
            r->buf[0] = v;
            r->idx = 0;
        } else {
            r->idx++;
            if (r->idx >= r->cap) {
                r->idx = 0;
            }
            r->buf[r->idx] = v;
        }
        r->count++;
    }
}

extern "C" {

struct Ov011Link {
    u32 unk_00;
    Ov011Link *next;
};

Ov011Link *func_ov011_021fdadc(Ov011Link *head, Ov011Link *n) {
    Ov011Link *cur;
    Ov011Link *prev;
    if (head == NULL || n == NULL) {
        return head;
    }
    cur = head;
    prev = NULL;
    while (cur != NULL) {
        if (cur == n) {
            if (prev == NULL) {
                head = cur->next;
            } else {
                prev->next = cur->next;
            }
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}

void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void *func_ov011_021fb66c(void *self);
void func_ov011_02201b28(void *p);
void func_ov011_0220205c(void *p);
void func_ov011_02202fbc(void *p);
void func_ov011_021fab74(void *p);

void func_ov011_021fdb28(u8 *self) {
    s32 bit = FLD(u8, self, 0x33);
    if (FLD(s32, self, 4) != 0) {
        switch (FLD(s32, self, 4)) {
        case 1:
            bit = 3;
            break;
        case 2:
            bit = 4;
            break;
        case 3:
            bit = 5;
            break;
        case 4:
            bit = 6;
            break;
        case 6:
            bit = 8;
            break;
        case 7:
            bit = 9;
            break;
        case 5:
            bit = 7;
            break;
        }
        FLD(u16, self, 0x20) = 0;
        FLD(u16, self, 0x22) = 0;
        Ov011Ring_Push((Ov011Ring *)(self + 0x10), FLD(s32, self, 4));
    }
    if (FLD(Ov011Bit01, self, 0).b1) {
        bit = 0xa;
        func_ov011_02201b28(self + 0x34);
        FLD(Ov011Bit01, self, 0xb4).b1 = 0;
        FLD(u16, self, 0xb6) = 0;
        FLD(s32, self, 0xb8) = -1;
        {
            u32 saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->def;
            if (FLD(void *, self, 0xbc) != NULL) {
                __cxa_vec_delete(FLD(void *, self, 0xbc), 0x40, 8, func_ov011_021fb66c);
                FLD(void *, self, 0xbc) = NULL;
            }
            data_02097dd0->cur = saved;
        }
        func_ov003_021da48c(self + 0xc8, 0);
        func_ov011_0220205c(self + 0xdc);
        func_ov011_02202fbc(self + 0x194);
        FLD(Ov011Bit01, self, 0x1b4).b1 = 0;
        FLD(u16, self, 0x1b6) = 0xffff;
        FLD(s32, self, 0x1bc) = 0;
        func_ov003_021da48c(self + 0x1c0, 1);
        func_ov011_021fab74(self + 0x1d4);
    }
    FLD(u64, self, 0x24) |= (u64)1 << (u8)bit;
    func_ov003_021da40c(self + 0x20);
    FLD(s32, self, 4) = 0;
    FLD(Ov011Bit01, self, 0).b1 = 0;
}
}
