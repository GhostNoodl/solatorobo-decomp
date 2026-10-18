#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_02149ef8;
extern void *data_02097ce0;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_02054f10(void *p, s32 a);
s32 func_02061d54(u16 a);
s32 func_0204c0e8(void *p, s32 a);
void func_ov000_0215c1bc(void *self, s32 id, s32 v);
void func_0203df0c(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, s32 f);

typedef struct {
    u8 pad[0x98];
    VObj *arr[12];
} LoArr98;

void func_ov000_0215ce8c(void *self, s32 id) {
    func_ov000_0215c1bc(self, id, func_0204c0e8(data_02149ef8, func_02061d54(id & 0x3ff)));
}

}
