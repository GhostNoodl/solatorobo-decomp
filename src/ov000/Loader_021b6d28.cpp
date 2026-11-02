#include "types.h"
#include "nitro/std.h"
#include "ov000/FieldMgr.h"

extern "C" {
extern char data_ov000_021cc84c[];
extern char data_ov000_021cc850[];
void *ResMgr_Load(const char *path, s32 type, s32 toFront);
BOOL ResMgr_IsLoaded(const char *path, s32 type);
void *ResMgr_GetArcList(const char *path);
void **ResList_FindType4(void *list, const char *name);
void **ResList_FindType5(void *list, const char *name);
void **ResList_FindType6(void *list, const char *name);
void **ResList_FindPath(void *list, const char *name, const char *ext);
BOOL func_0203ed04(const char *name, void *data);
u32 func_0203ebf8(void);
BOOL Vram_IsTransferDone(u32 task);
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
                ResMgr_Load(self->path, 7, 0);
                self->flag1 = 1;
                self->state++;
            }
            again = TRUE;
            break;
        case 11:
            if (!ResMgr_IsLoaded(self->path, 7)) {
                break;
            }
            h = ResMgr_GetArcList(self->path);
            if (self->flag2) {
                if ((self->mdl = ResList_FindType4(h, self->name)) != NULL) {
                    self->task0 = Load021b6d28(self->name, self->mdl);
                }
            }
            if (self->flag4) {
                STD_CopyString(buf, self->name);
                STD_ConcatenateString(buf, data_ov000_021cc84c);
                if ((self->tex = ResList_FindType5(h, buf)) != NULL) {
                    self->task1 = Load021b6d28(buf, self->tex);
                }
            }
            if (self->flag6) {
                self->anm = ResList_FindType6(h, self->name);
            }
            if (self->flag8) {
                self->hit = ResList_FindPath(h, self->name, data_ov000_021cc850);
            }
            self->state++;
            again = TRUE;
            break;
        case 12:
            if (!Vram_IsTransferDone(self->task0)) {
                break;
            }
            if (!Vram_IsTransferDone(self->task1)) {
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
