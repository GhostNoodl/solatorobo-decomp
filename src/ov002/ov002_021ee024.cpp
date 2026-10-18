#include "ov002/ov002.h"

extern "C" {

extern void *data_ov002_021f0fac[];

void func_0204a284(void *a, int b);

void func_ov002_021ee024(void) {
    u32 saved;
    u8 *n;
    u8 *next;
    u32 s2;
    void *x;
    u32 s3;
    HEAP_PUSH(saved);
    x = data_ov002_021f0fa0[1];
    if (x != NULL) {
        if (x != NULL) {
            func_0204a284(data_02097e4c, -1);
            for (n = (u8 *)data_ov002_021f0fa0[0]; n != NULL; n = next) {
                s32 k = *FIELD(n, 0x20, s32 *);
                u8 *c;
                u8 *prev;
                next = FIELD(n, 0x2c, u8 *);
                prev = NULL;
                for (c = (u8 *)data_ov002_021f0fac[k]; c != NULL; c = FIELD(c, 0x30, u8 *)) {
                    if (c == n) {
                        if (prev == NULL) {
                            data_ov002_021f0fac[k] = FIELD(n, 0x30, void *);
                        } else {
                            FIELD(prev, 0x30, void *) = FIELD(n, 0x30, void *);
                        }
                        FIELD(n, 0x30, void *) = NULL;
                        break;
                    }
                    prev = c;
                }
                if (FIELD(n, 0x28, u8 *) != NULL) {
                    FIELD(FIELD(n, 0x28, u8 *), 0x2c, void *) = FIELD(n, 0x2c, void *);
                } else {
                    data_ov002_021f0fa0[0] = FIELD(n, 0x2c, void *);
                }
                if (FIELD(n, 0x2c, u8 *) != NULL) {
                    FIELD(FIELD(n, 0x2c, u8 *), 0x28, void *) = FIELD(n, 0x28, void *);
                } else {
                    data_ov002_021f0fa0[2] = FIELD(n, 0x28, void *);
                }
                FIELD(n, 0x28, void *) = NULL;
                FIELD(n, 0x2c, void *) = NULL;
                {
                    HEAP_PUSH(s2);
                    if (n != NULL) {
                        if (n != NULL) {
                            ((VObject *)n)->v0x4();
                        }
                    }
                    HEAP_POP(s2);
                }
            }
            {
                HEAP_PUSH(s3);
                DELETE_VOBJ(FIELD(x, 0x24, VObject *));
                HEAP_POP(s3);
            }
            func_0203de1c(x);
        }
        data_ov002_021f0fa0[1] = NULL;
    }
    HEAP_POP(saved);
}

}
