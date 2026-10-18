#include "ov000/LoCommon.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
} B8;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 11;
} B16;

typedef struct Obj021b1110 {
    u8 unk_00[0x8];
    struct Obj021b1110 *next;
    u8 unk_0c[0x87];
    B8 f93;
} Obj021b1110;

typedef struct {
    u8 unk_00[0xc];
    Obj021b1110 *head;
} Group021b1110;

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd30;
Group021b1110 *func_ov000_0218e4cc(void *mgr, u16 id);
void func_ov000_02172450(void *p, s32 a);
void func_ov000_021b1a54(void *self, s32 a);

static inline Obj021b1110 *GroupNext(Obj021b1110 *head, Obj021b1110 *cur) {
    return cur != NULL ? cur->next : head;
}

void func_ov000_021b1110(u8 *self, BOOL force) {
    u8 found = FALSE;
    {
        Group021b1110 *g = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
        Obj021b1110 *head = g->head;
        Obj021b1110 *cur;
        for (cur = head; cur != NULL; cur = GroupNext(head, cur)) {
            if (cur->f93.b4) {
                found = TRUE;
                break;
            }
        }
    }
    if (!found) {
        Group021b1110 *g = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000);
        Obj021b1110 *head = g->head;
        Obj021b1110 *cur;
        for (cur = head; cur != NULL; cur = GroupNext(head, cur)) {
            if (cur->f93.b4) {
                found = TRUE;
                break;
            }
        }
    }
    if (found && LFLD(u16, self, 0xb32) == 0 && *LFLD(u16 *, self, 0x50) != 0) {
        LFLD(u16, self, 0xb32)++;
    }
    if (force || !LFLD(B8, self, 0xb28).b2) {
        if (LFLD(B8, self, 0x93).b4 == found) {
            return;
        }
        if (found) {
            func_ov000_02172450(data_ov000_021ccd30, 1);
            LFLD(B8, self, 0x93).b4 = found;
            LFLD(u8, self, 0xb2a) = 0;
        } else {
            func_ov000_02172450(data_ov000_021ccd30, 2);
            LFLD(B8, self, 0x93).b4 = found;
        }
    } else {
        if (found) {
            return;
        }
        if (!LFLD(B16, self, 0xb22).b3) {
            return;
        }
        if (LFLD(B16, self, 0xb22).b4) {
            return;
        }
        if (LFLD(LoBits, self, 0xb24).b0) {
            return;
        }
        func_ov000_021b1a54(self, 1);
    }
}
}
