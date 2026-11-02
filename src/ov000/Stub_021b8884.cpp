#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"

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
SIZE_ASSERT(Obj021b8884, 0x34);

typedef struct {
    u8 unk_00[0x24];
    VObj *unk_24;
    u8 unk_28[0x8];
    void *unk_30;
} Obj021b88d8;

extern "C" {

void func_0203caf8(s32 a);
void func_0203c9e8(s32 a, s32 b);
void func_02041558(void *p);
void func_02041278(void *p);
void Heap_Free(void *p);

extern char data_ov000_021cc87b[];
Obj0206e7d0 *Lang_GetGroup(u8 a);
void func_02070874(char *dst, const char *fmt, ...);
void func_0203cc58(s32 a, s32 b, s32 c);

void func_ov000_021b8884(Obj021b8884 *self, u16 a) {
    self->unk_00 = 0;
    func_02070874(self->unk_04, data_ov000_021cc87b, Lang_GetGroup(a)->unk_04);
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

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    p = self->unk_30;
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            Heap_Free(p);
        }
        self->unk_30 = NULL;
    }
    data_02097dd0->cur = saved;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_24 != NULL) {
        if (self->unk_24 != NULL) {
            self->unk_24->vfunc_04();
        }
        self->unk_24 = NULL;
    }
    data_02097dd0->cur = saved;

    func_0203c9e8(0x3f, 0);
}

}
