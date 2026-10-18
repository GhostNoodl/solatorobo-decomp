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

void func_ov000_0215adbc(void *self) {
    LO_FREE_V(self, 0xd4);
}

void func_ov000_0215ae10(void *self) {
    switch (LFLD(s32, self, 4)) {
    case 0:
        LFLD(s32, self, 0x34) = 0x8000;
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        break;
    case 1:
        LFLD(s32, self, 0x34) = 0x8000;
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        break;
    }
}

}
