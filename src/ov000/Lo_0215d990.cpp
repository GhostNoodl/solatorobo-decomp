#include "ov000/LoCommon.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_02149ef8;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_02054f10(void *p, s32 a);
u16 func_02061d54(u16 a);
s32 MsgRes_GetString(void *p, s32 a);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, s32 f);

typedef struct {
    u8 pad[0x98];
    VObj *arr[12];
} LoArr98;

struct Obj0215d990 {
    u8 unk_00[0x94];
    TextWin *unk_94;
};

void func_ov000_0215d990(Obj0215d990 *self, s32 a) {
    TextWin *p;
    if (self->unk_94 == NULL) {
        return;
    }
    {
        s32 v = MsgRes_GetString(data_02149ef8, a);
        p = self->unk_94;
        p->str = v;
    }
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0 ? 1 : 0);
    data_02097ce0->unk_004 = ((s32)p->font);
}

}
