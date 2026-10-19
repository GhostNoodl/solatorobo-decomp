#include "ov002/ov002.h"

typedef struct ov002_StaffFlags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 paused : 1;
    u32 rest : 29;
} ov002_StaffFlags;

typedef struct ov002_Staff {
    s32 id;
    ov002_StaffFlags flags;
    s32 state;
    s32 next;
    s32 sub;
    s32 timer;
    s32 prevTimer;
    s32 step;
    s32 nextStep;
    VObject *loader;
    u8 unk28[4];
    u16 scroll;
} ov002_Staff;

typedef struct ov002_StaffConfig {
    u8 unk0[0x14];
    const char *pathFmt;
    const char *dir;
} ov002_StaffConfig;

typedef struct ov002_Disp021ee1a8 {
    u8 unk0[0xe];
    u8 unkE_0 : 2;
    u8 mode : 2;
    u8 unkE_4 : 4;
} ov002_Disp021ee1a8;

typedef struct ov002_Fade021ee1a8 {
    u8 unk0[4];
    s32 mode;
} ov002_Fade021ee1a8;

extern "C" {

extern char data_ov002_021f0e06[];
extern ov002_Disp021ee1a8 *data_ov000_021ccd54;

void func_0200779c(char *dst, const char *fmt, ...);
void func_02070874(char *dst, const char *fmt, ...);
void func_ov002_021ec2d8(VObject *obj);
BOOL func_ov002_021ee55c(ov002_Staff *self, u16 y, int h);
void func_ov002_021ee7f8(ov002_Staff *self);

static inline BOOL ov002_Staff_IsPaused(ov002_Staff *s) {
    return s->flags.paused == 1 ? TRUE : FALSE;
}

static inline void ov002_Staff_Update(ov002_Staff *s) {
    if (s->next != 0) {
        s->state = s->next;
        s->next = 0;
        s->sub = 0;
        s->timer = 0;
        s->prevTimer = -1;
        s->step = 0x1000;
    } else if (!ov002_Staff_IsPaused(s)) {
        s->prevTimer = s->timer;
        s->timer += s->step;
    }
}

static inline void ov002_Staff_SetNext(ov002_Staff *s, s32 state) {
    if (s->state != state) {
        s->next = state;
    }
}

void func_ov002_021ee1a8(void) {
    VObject *o;
    ov002_Staff *s = (ov002_Staff *)data_ov002_021f0fa0[1];

    ov002_Staff_Update(s);
    s->flags.paused = 0;
    switch (s->state) {
    case 1:
        ov002_Staff_SetNext(s, 4);
        break;
    case 4:
        switch (s->sub) {
        case 0:
            s->sub = 3;
            break;
        case 3: {
            char path[0x20];
            char num[8];
            char dir[0x20];
            s32 id;
            o = (VObject *)func_0203dd9c(0x50);
            if (o != NULL) {
                *(VFunc **)o = data_0208b318;
                o->v0x8();
                *(VFunc **)o = data_ov002_021f0f2c;
                o->v0x8();
            }
            s->loader = o;
            id = s->id;
            func_0206e900(dir, ((ov002_StaffConfig *)data_ov002_021f0d88)->dir);
            func_0200779c(num, data_ov002_021f0e06, id);
            func_02070874(path, ((ov002_StaffConfig *)data_ov002_021f0d88)->pathFmt, num);
            o->v0x24(dir, path);
            s->sub = 4;
        }
        case 4:
            if (!s->loader->v0x2c()) {
                break;
            }
            func_ov002_021ec2d8(s->loader);
            s->nextStep = 0x1000;
            ov002_Staff_SetNext(s, 6);
            break;
        }
        break;
    case 6:
        switch (s->sub) {
        case 0:
            data_ov000_021ccd54->mode = 2;
            func_0203cb78(1, 2, -1);
            s->scroll = 0;
            s->sub++;
        case 1:
            if (!func_ov002_021ee55c(s, s->scroll, 0x20)) {
                s->scroll += 0x20;
                break;
            }
            ((ov002_Fade021ee1a8 *)data_02097d48)->mode = 2;
            s->sub++;
            break;
        case 5:
            ov002_Staff_SetNext(s, 7);
            break;
        default:
            s->sub++;
            break;
        }
        break;
    case 3:
    case 7:
        func_ov002_021ee7f8(s);
        break;
    case 8:
        switch (s->sub) {
        case 0:
            ((ov002_Fade021ee1a8 *)data_02097d48)->mode = 1;
            s->sub++;
            return;
        case 5:
            func_0203cc58(1, 2, -1);
            ov002_Staff_SetNext(s, 2);
            return;
        default:
            s->sub++;
            return;
        }
    }
    s->step = s->nextStep;
}

}
