#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x4];
    char *unk_04;
} Obj0206e7d0;

typedef struct {
    s32 unk_00;
    char unk_04[0x20];
    s32 unk_24;
    s32 unk_28;
    u16 unk_2c;
    s32 unk_30;
} Obj021b8884;

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

typedef struct {
    u8 unk_00[0x24];
    VObj *unk_24;
    u8 unk_28[0x8];
    void *unk_30;
} Obj021b88d8;

extern "C" {

extern HeapState *data_02097dd0;
void func_0203caf8(s32 a);
void func_0203c9e8(s32 a, s32 b);
void func_02041558(void *p);
void func_02041278(void *p);
void func_0203de1c(void *p);

extern char data_ov000_021cc87b[];
Obj0206e7d0 *func_0206e7d0(u8 a);
void func_02070874(char *dst, const char *fmt, ...);
void func_0203cc58(s32 a, s32 b, s32 c);

void func_ov000_021b8884(Obj021b8884 *self, u16 a) {
    self->unk_00 = 0;
    func_02070874(self->unk_04, data_ov000_021cc87b, func_0206e7d0(a)->unk_04);
    self->unk_2c = a;
    self->unk_24 = 0;
    self->unk_28 = 1;
    self->unk_30 = 0;
    func_0203cc58(0, 1, 2);
}

void func_ov000_021b88d8(Obj021b88d8 *self) {
    void *saved;
    void *p;

    func_0203caf8(0);
    func_0203caf8(2);

    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    p = self->unk_30;
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        self->unk_30 = NULL;
    }
    data_02097dd0->current = saved;

    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (self->unk_24 != NULL) {
        if (self->unk_24 != NULL) {
            self->unk_24->vfunc_04();
        }
        self->unk_24 = NULL;
    }
    data_02097dd0->current = saved;

    func_0203c9e8(0x3f, 0);
}

}
