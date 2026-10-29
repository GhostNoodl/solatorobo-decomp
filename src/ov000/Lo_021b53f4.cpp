#include "types.h"

typedef struct Node021b53f4 {
    struct Node021b53f4 *prev;
    struct Node021b53f4 *next;
} Node021b53f4;

typedef struct {
    u8 pad[8];
    u8 unk_08;
    u8 pad09[2];
    u8 unk_0b;
    u8 pad0c[8];
    s32 unk_14;
    s32 unk_18;
    Node021b53f4 *head;
    Node021b53f4 *tail;
    u8 pad24[0x1f2 - 0x24];
    u16 unk_1f2;
} Mgr021b53f4;

typedef struct {
    u8 pad[0xc8];
    s32 unk_c8;
    u8 padcc[0xa];
    u16 unk_d6;
} PSub021b53f4;

typedef struct {
    u8 pad[0xc9];
    u8 unk_c9;
    u8 unk_ca[3];
    u8 padcd[3];
    u8 unk_d0[3];
    u8 padd3[0x21];
    PSub021b53f4 sub;
} Player021b53f4;

typedef struct {
    u8 pad[0x11c];
    u8 unk_11c[0x74];
    u8 b0 : 6;
    u8 b6 : 1;
    u8 b7 : 1;
    u8 pad191[0x3c];
    u8 unk_1cd;
    u8 unk_1ce;
} PlayerB021b53f4;

typedef struct {
    u8 pad[8];
    void *unk_08;
} Ent021b53f4;

extern "C" {

extern u8 *data_02097d48;
extern Player021b53f4 *data_ov000_021ccd54;
void func_02043904(void *p);
void func_02043b20(void *p);
void func_020434e0(void *p);
void func_ov000_021b65ec(Mgr021b53f4 *self);
void *func_ov000_021b7a7c(Node021b53f4 *n);
void func_0203de1c(void *p);
Ent021b53f4 *func_0206e7d0(u8 id);
void func_0206dfd4(char *buf, u8 *ids);
void func_02035acc(void *a, char *buf, s32 c);
void func_ov000_021b6994(Mgr021b53f4 *self, s32 a);

void func_ov000_021b53f4(Mgr021b53f4 *self) {
    PlayerB021b53f4 *pb;
    Node021b53f4 *prev;
    Node021b53f4 *next;
    Node021b53f4 *n;
    u8 *d48 = data_02097d48;
    func_02043904(d48 + 0x8b0);
    func_02043b20(d48 + 0x8b0);
    pb = (PlayerB021b53f4 *)data_ov000_021ccd54;
    func_020434e0(pb->unk_11c);
    pb->b6 = 0;
    pb->unk_1ce = 0;
    pb->unk_1cd = 0;
    if (self->unk_18 != 0 && self->unk_0b != 0xff) {
        func_ov000_021b65ec(self);
    }
    while ((n = self->head) != NULL) {
        prev = n->prev;
        next = n->next;
        if (n != NULL) {
            func_ov000_021b7a7c(n);
            func_0203de1c(n);
        }
        if (prev != NULL) {
            prev->next = next;
        } else {
            self->head = next;
        }
        if (next != NULL) {
            next->prev = prev;
        } else {
            self->tail = prev;
        }
    }
    if (self->unk_14 != 0) {
        Player021b53f4 *p = data_ov000_021ccd54;
        u8 *ids = p->unk_d0;
        Ent021b53f4 *e;
        char buf[0x20];
        if (ids[0] == 0xff || ids[1] == 0xff || ids[2] == 0xff) {
            ids = p->unk_ca;
        }
        e = func_0206e7d0(ids[0]);
        func_0206dfd4(buf, ids);
        func_02035acc(e->unk_08, buf, 0);
        {
            PSub021b53f4 *sub = &data_ov000_021ccd54->sub;
            sub->unk_c8 = 0;
            sub->unk_d6 = 0;
        }
        self->unk_14 = 0;
    }
    self->unk_18 = 0;
    {
        Player021b53f4 *p = data_ov000_021ccd54;
        if (p->unk_ca[0] != p->unk_d0[0] || p->unk_ca[1] != p->unk_d0[1] || p->unk_c9 != 0) {
            func_ov000_021b6994(self, 0);
        }
    }
    self->unk_1f2 = 0;
    self->unk_08 = 0;
}

}
