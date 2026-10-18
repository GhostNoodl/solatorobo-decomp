#include "ov000/HeapScope.h"

typedef struct Node021b4f28 {
    struct Node021b4f28 *prev;
    struct Node021b4f28 *next;
} Node021b4f28;

typedef struct {
    u8 pad_00[0x14];
    s32 unk_14;
    s32 unk_18;
    Node021b4f28 *head;
    Node021b4f28 *tail;
    u8 pad_24[0x1d0];
    u8 unk_1f4[1];
} Obj021b4f28;

typedef struct {
    u8 pad_00[0xc8];
    s32 unk_c8;
    u8 pad_cc[0xa];
    u16 unk_d6;
} Sub021b4f28;

typedef struct {
    u8 pad_00[0xca];
    u8 unk_ca;
    u8 pad_cb[0x29];
    Sub021b4f28 unk_f4;
} Game021b4f28;

typedef struct {
    u8 pad_00[8];
    void *unk_08;
} Info021b4f28;

extern "C" {

extern Obj021b4f28 *data_ov000_021ccd6c;
extern Game021b4f28 *data_ov000_021ccd54;
Info021b4f28 *func_0206e7d0(u32 id);
void func_0206dfd4(char *buf, u8 *src);
void func_02035acc(void *a, void *b, s32 c);
void func_ov000_021b6994(Obj021b4f28 *self, s32 a);
void func_ov000_021b7a7c(Node021b4f28 *node);
void func_0203f864(void *obj);
void func_0206e6c0(void);

static inline void Obj021b4f28_Delete(Obj021b4f28 *o) {
    Node021b4f28 *node;
    if (o->unk_14 != 0) {
        Game021b4f28 *g = data_ov000_021ccd54;
        Info021b4f28 *info = func_0206e7d0(g->unk_ca);
        char buf[0x20];
        func_0206dfd4(buf, &g->unk_ca);
        func_02035acc(info->unk_08, buf, 0);
        {
            Sub021b4f28 *sub = &data_ov000_021ccd54->unk_f4;
            sub->unk_c8 = 0;
            sub->unk_d6 = 0;
        }
        o->unk_14 = 0;
    }
    o->unk_18 = 0;
    func_ov000_021b6994(o, 1);
    while ((node = o->head) != NULL) {
        Node021b4f28 *prev = node->prev;
        Node021b4f28 *next = node->next;
        if (node != NULL) {
            func_ov000_021b7a7c(node);
            func_0203de1c(node);
        }
        if (prev != NULL) {
            prev->next = next;
        } else {
            o->head = next;
        }
        if (next != NULL) {
            next->prev = prev;
        } else {
            o->tail = prev;
        }
    }
    func_0203f864(o->unk_1f4);
    func_0203de1c(o);
}

void func_ov000_021b4f28(void) {
    Obj021b4f28 *p;
    void *saved;
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    p = data_ov000_021ccd6c;
    if (p != NULL) {
        if (p != NULL) {
            Obj021b4f28_Delete(p);
        }
        data_ov000_021ccd6c = NULL;
    }
    data_02097dd0->current = saved;
    func_0206e6c0();
}

}
