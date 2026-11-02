#include "types.h"
#include "nitro/std.h"
#include "ov000/FieldMgr.h"

extern "C" {
extern char data_ov000_021cc84c[];
extern char data_ov000_021cc850[];
void *func_020359d0(const char *path, s32 type, s32 toFront);
BOOL func_02035b90(const char *path, s32 type);
void *func_02035d5c(const char *path);
void **func_02034ec0(void *list, const char *name);
void **func_02034f5c(void *list, const char *name);
void **func_02034ff8(void *list, const char *name);
void **ResList_FindPath(void *list, const char *name, const char *ext);
BOOL func_0203ed04(const char *name, void *data);
u32 func_0203ebf8(void);
BOOL func_0203e63c(u32 task);
void func_02039494(void *data);

static inline u32 Load021b6d28(const char *name, void **res) {
    if (res != NULL) {
        func_0203ed04(name, *res);
    }
    return func_0203ebf8();
}

BOOL func_ov000_021b6d28(FieldPropLoader *self) {
    BOOL done = FALSE;
    BOOL again;
    void *h;
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
            if (!self->flag0) {
                self->state = 100;
            } else {
                self->task0 = 0;
                self->task1 = 0;
                func_020359d0(self->path, 7, 0);
                self->flag1 = 1;
                self->state++;
            }
            again = TRUE;
            break;
        case 11:
            if (!func_02035b90(self->path, 7)) {
                break;
            }
            h = func_02035d5c(self->path);
            if (self->flag2) {
                if ((self->mdl = func_02034ec0(h, self->name)) != NULL) {
                    self->task0 = Load021b6d28(self->name, self->mdl);
                }
            }
            if (self->flag4) {
                STD_CopyString(buf, self->name);
                STD_ConcatenateString(buf, data_ov000_021cc84c);
                if ((self->tex = func_02034f5c(h, buf)) != NULL) {
                    self->task1 = Load021b6d28(buf, self->tex);
                }
            }
            if (self->flag6) {
                self->anm = func_02034ff8(h, self->name);
            }
            if (self->flag8) {
                self->hit = ResList_FindPath(h, self->name, data_ov000_021cc850);
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
            self->task0 = 0;
            self->task1 = 0;
            self->state++;
            break;
        case 13:
            self->state++;
            break;
        case 14:
            if (self->mdl != NULL) {
                func_02039494(*self->mdl);
            }
            if (self->tex != NULL) {
                func_02039494(*self->tex);
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
