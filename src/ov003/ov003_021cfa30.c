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
extern s32 func_ov003_021cf77c(Ov003NodeSub *sub);
extern void func_0204b270(void *a, s32 b, s32 c);

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
