#include "ov011/ov011.h"



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

void func_ov011_021fdb28(Ov011Scene *self) {
    s32 bit = self->seq.current;
    if (self->unk_04 != 0) {
        switch (self->unk_04) {
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
        self->seq.st = 0;
        self->seq.timer = 0;
        Ov011Ring_Push(&self->ring, self->unk_04);
    }
    if (self->b1) {
        bit = 0xa;
        func_ov011_02201b28(&self->fx);
        self->mgr2.b1 = 0;
        self->mgr2.count = 0;
        self->mgr2.unk_04 = -1;
        {
            void *saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->heapHi;
            if (self->mgr2.arr8 != NULL) {
                __cxa_vec_delete(self->mgr2.arr8, 0x40, 8, func_ov011_021fb66c);
                self->mgr2.arr8 = NULL;
            }
            data_02097dd0->cur = saved;
        }
        func_ov003_021da48c(&self->mgr2.state, 0);
        func_ov011_0220205c(self->mgr2.unk_28);
        func_ov011_02202fbc(&self->mgr2.mov);
        self->s1b4.b1 = 0;
        self->s1b4.id = 0xffff;
        self->s1b4.ent = NULL;
        func_ov003_021da48c(&self->s1b4.seq, 1);
        func_ov011_021fab74(&self->mgr);
    }
    self->seq.flags |= (u64)1 << (u8)bit;
    func_ov003_021da40c(&self->seq);
    self->unk_04 = 0;
    self->b1 = 0;
}
}
