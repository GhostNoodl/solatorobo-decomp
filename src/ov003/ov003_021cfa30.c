#include "types.h"

typedef struct {
    u16 unk_00;
    u16 unk_02;
} Ov003NodeSub;

typedef struct Ov003Node {
    u32 unk_00;
    struct Ov003Node *next;
    u8 pad_08[0x28];
    Ov003NodeSub sub;
} Ov003Node;

typedef struct {
    Ov003Node *head;
} Ov003NodeList;

extern Ov003NodeList *data_ov000_021ccd64;
extern void *data_02149ef0;
extern u8 OVERLAY_9_ID[];
extern u8 OVERLAY_10_ID[];
extern u8 OVERLAY_11_ID[];
extern u8 OVERLAY_12_ID[];
extern u8 OVERLAY_13_ID[];
extern u8 OVERLAY_14_ID[];
extern void func_0204b270(void *a, s32 b, s32 c);

s32 func_ov003_021cf77c(Ov003NodeSub *sub) {
    s32 r;
    if (sub == NULL) {
        return -1;
    }
    r = (s32)OVERLAY_9_ID;
    switch (sub->unk_00) {
    case 0x5800:
    case 0x5802:
    case 0x5815:
    case 0x5816:
        r = -1;
        break;
    case 0x5c04:
    case 0x5c05:
    case 0x5c06:
        r = (s32)OVERLAY_10_ID;
        break;
    case 0x5801:
    case 0x5805:
    case 0x5807:
    case 0x5812:
    case 0x5813:
    case 0x5814:
    case 0x5c11:
        r = (s32)OVERLAY_11_ID;
        break;
    case 0x5029:
    case 0x5036:
    case 0x5039:
    case 0x5057:
    case 0x5c00:
    case 0x5c01:
    case 0x5c02:
    case 0x5c03:
    case 0x5c13:
    case 0x5c14:
        r = (s32)OVERLAY_12_ID;
        break;
    case 0x540c:
    case 0x5419:
    case 0x541c:
    case 0x5c08:
    case 0x5c0a:
    case 0x5c17:
        r = (s32)OVERLAY_13_ID;
        break;
    case 0x580c:
    case 0x580d:
    case 0x580e:
    case 0x5c0c:
    case 0x5c0e:
    case 0x5c0f:
    case 0x5c15:
    case 0x5c16:
    case 0x5c19:
        r = (s32)OVERLAY_14_ID;
        break;
    }
    if (r != -1) {
        func_0204b270(data_02149ef0, r, 1);
    }
    return r;
}

static inline Ov003Node *Ov003_Next(Ov003NodeList *l, Ov003Node *n) { if (n != NULL) return n->next; return l->head; }
void func_ov003_021cfa30(void) {
    s32 r = -1;
    Ov003Node *n;
    for (n = data_ov000_021ccd64->head; n != NULL; n = Ov003_Next(data_ov000_021ccd64, n)) {
        if ((n->sub.unk_02 >> 12) == 5) {
            r = func_ov003_021cf77c(&n->sub);
            if (r != -1) {
                break;
            }
        }
    }
    if (r == -1) {
        func_0204b270(data_02149ef0, (s32)OVERLAY_9_ID, 1);
    }
}
