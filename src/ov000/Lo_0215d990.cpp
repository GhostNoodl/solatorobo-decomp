#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_02149ef8;
extern void *data_02097ce0;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_02054f10(void *p, s32 a);
u16 func_02061d54(u16 a);
s32 func_0204c0e8(void *p, s32 a);
void func_ov000_0215c1bc(void *self, s32 id, s32 v);
void func_0203df0c(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, s32 f);

typedef struct {
    u8 pad[0x98];
    VObj *arr[12];
} LoArr98;

struct Obj0215d990 {
    u8 unk_00[0x94];
    void *unk_94;
};

void func_ov000_0215d990(Obj0215d990 *self, s32 a) {
    void *p;
    if (self->unk_94 == NULL) {
        return;
    }
    {
        s32 v = func_0204c0e8(data_02149ef8, a);
        p = self->unk_94;
        LFLD(s32, p, 0x24) = v;
    }
    LFLD(s32, p, 0x4c) = func_0204c4fc(LFLD(s32, p, 0x28), LFLD(s32, p, 0x38), LFLD(s32, p, 0x24), (u8 *)p + 0x44, (u8 *)p + 0x48, LFLD(s8, p, 0x37) != 0 ? 1 : 0);
    LFLD(s32, data_02097ce0, 4) = LFLD(s32, p, 0x28);
}

}
