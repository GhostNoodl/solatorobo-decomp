#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    u8 pad[0xcdc];
    void *unk_cdc;
} Sub02164420;

typedef struct {
    u8 pad[0x20];
    s32 unk_20;
    void *unk_24;
    void *unk_28;
    void *unk_2c;
    Sub02164420 *unk_30;
    u8 pad34[0xc];
    VObj *unk_40;
} Obj02164420;

extern "C" {

extern void *data_02097cdc;
extern char data_ov000_021cb8e0[];
void func_02036838(void *a, void *b, s32 c, s32 d);
void func_0206e900(char *dst, const char *src);
void func_0203df0c(void *p);
void func_ov000_021658e8(Obj02164420 *self);

void func_ov000_02164420(Obj02164420 *self) {
    Sub02164420 *s = self->unk_30;
    if (s != NULL && s->unk_cdc != NULL) {
        func_0203df0c(s->unk_cdc);
        s->unk_cdc = NULL;
    }
    func_ov000_021658e8(self);
    if (self->unk_20 >= 1) {
        char buf[0x20];
        func_0206e900(buf, data_ov000_021cb8e0);
        func_02036838(data_02097cdc, buf, 7, 0);
    }
    HEAP_DELETE_VOBJ(self->unk_40);
    HEAP_DELETE_MODEL(self->unk_24);
    HEAP_DELETE_MODEL(self->unk_28);
    HEAP_DELETE_MODEL(self->unk_2c);
}

}
