#include "types.h"
#include "nitro/std.h"

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
    u16 rest : 7;
} LdFlags021b6d28;

typedef struct {
    void *arc;
    char *name;
    s16 state;
    LdFlags021b6d28 flags;
    void *task0;
    void *task1;
    u32 *res0;
    u32 *res1;
    void *res2;
    void *res3;
} Loader021b6d28;

extern "C" {
extern char data_ov000_021cc84c[];
extern char data_ov000_021cc850[];
void *func_020359d0(void *a, s32 b, s32 c);
BOOL func_02035b90(void *a, s32 b);
void *func_02035d5c(void *a);
u32 *func_02034ec0(void *a, char *b);
u32 *func_02034f5c(void *a, char *b);
void *func_02034ff8(void *a, char *b);
void *func_02034c34(void *a, char *b, char *c);
BOOL func_0203ed04(char *name, u32 a);
void *func_0203ebf8(void);
BOOL func_0203e63c(void *a);
void func_02039494(u32 a);

static inline void *Load021b6d28(char *name, u32 *res) {
    if (res != NULL) {
        func_0203ed04(name, *res);
    }
    return func_0203ebf8();
}

BOOL func_ov000_021b6d28(Loader021b6d28 *self) {
    BOOL done = FALSE;
    BOOL again;
    void *h;
    u32 *r;
    char buf[32];

    do {
        again = FALSE;
        switch (self->state) {
        case 0:
            self->state = 10;
            again = TRUE;
            break;
        case 1:
            break;
        case 10:
            if (!self->flags.b0) {
                self->state = 100;
            } else {
                self->task0 = NULL;
                self->task1 = NULL;
                func_020359d0(self->arc, 7, 0);
                self->flags.b1 = 1;
                self->state++;
            }
            again = TRUE;
            break;
        case 11:
            if (!func_02035b90(self->arc, 7)) {
                break;
            }
            h = func_02035d5c(self->arc);
            if (self->flags.b2) {
                if ((self->res0 = func_02034ec0(h, self->name)) != NULL) {
                    self->task0 = Load021b6d28(self->name, self->res0);
                }
            }
            if (self->flags.b4) {
                STD_CopyString(buf, self->name);
                STD_ConcatenateString(buf, data_ov000_021cc84c);
                if ((self->res1 = func_02034f5c(h, buf)) != NULL) {
                    self->task1 = Load021b6d28(buf, self->res1);
                }
            }
            if (self->flags.b6) {
                self->res2 = func_02034ff8(h, self->name);
            }
            if (self->flags.b8) {
                self->res3 = func_02034c34(h, self->name, data_ov000_021cc850);
            }
            self->state++;
            again = TRUE;
            break;
        case 12:
            if (!func_0203e63c(self->task0)) {
                break;
            }
            if (!func_0203e63c(self->task1)) {
                break;
            }
            self->task0 = NULL;
            self->task1 = NULL;
            self->state++;
            break;
        case 13:
            self->state++;
            break;
        case 14:
            if (self->res0 != NULL) {
                func_02039494(*self->res0);
            }
            if (self->res1 != NULL) {
                func_02039494(*self->res1);
            }
            self->state = 100;
            again = TRUE;
            break;
        case 100:
            self->state = -1;
            done = TRUE;
            break;
        }
    } while (again);
    return done;
}
}
