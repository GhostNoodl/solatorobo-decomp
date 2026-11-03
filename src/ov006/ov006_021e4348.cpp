#include "ov006/ov006.h"
#include "ov006/Model.h"
#include "ov000/ObjLayouts.h"

typedef struct ov006_TempBuffer {
    u32 unk0;
    u8 data[0x50];
} ov006_TempBuffer;

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x80];
    void *unk80;
} ov006_Unk02097e40;

extern "C" {

extern void *ov006_ModelHolder_vtbl;
extern void *ov006_ObjectHolder_vtbl;
extern ov006_Unk02097e40 *gWhMgr;

void ov006_ModelHolder_Load(ov006_ModelHolder *self, int a);
BOOL func_02044e38(ov006_Unk02097e40 *a, int b);
void Wh_SetGgid(ov006_Unk02097e40 *a, u32 b);
void func_02046a78(ov006_Unk02097e40 *a, void *b, u32 c);
void OS_GetOwnerInfo(void *a);
int WM_GetLinkLevel(void);
BOOL ov006_Menu_ReceiveData(const ov006_MenuData *data);
void ov006_Menu_State04(ov006_Menu *self);
void ov006_Menu_State05(ov006_Menu *self);
void ov006_Menu_State06(ov006_Menu *self);
void ov006_Menu_State07(ov006_Menu *self);
void ov006_Menu_State08(ov006_Menu *self);
void ov006_Menu_State09(ov006_Menu *self);

static inline void ov006_Menu_SetState(ov006_Menu *self, int state) {
    self->state = state;
    self->stateTime = 0;
}

static inline u32 ov006_GetOwnerName(void *dst, u32 size) {
    ov006_TempBuffer buf;
    OS_GetOwnerInfo(&buf);
    MI_CpuCopy8(buf.data, dst, size);
    return size;
}

static inline BOOL ov006_Stateful_IsDone(UiObj *s) {
    return s->state == 5 ? TRUE : FALSE;
}

void ov006_Menu_Load(ov006_Menu *self) {
    ov006_ObjectHolder *h;
    switch (self->state) {
    case 0: {
        ov006_ModelHolder *mh = (ov006_ModelHolder *)Heap_Alloc(sizeof(ov006_ModelHolder));
        ov006_ObjectHolder *oh;
        if (mh != NULL) {
            mh->vtbl = &ov006_ModelHolder_vtbl;
            mh->model = NULL;
            mh->unk8 = 1;
            mh->unkC = 0;
        }
        self->unk1D4 = mh;
        ov006_ModelHolder_Load(self->unk1D4, 2);
        oh = (ov006_ObjectHolder *)Heap_Alloc(sizeof(ov006_ObjectHolder));
        if (oh != NULL) {
            oh->vtbl = &ov006_ObjectHolder_vtbl;
            oh->obj = NULL;
        }
        self->unk1D8 = oh;
        ov006_Menu_SetState(self, 1);
        break;
    }
    case 2:
        func_02044e38(gWhMgr, 0);
        Wh_SetGgid(gWhMgr, 0x401336);
        func_02046a78(gWhMgr, self->unkF4, ov006_GetOwnerName(self->unkF4, 0x16));
        gWhMgr->unk80 = (void *)ov006_Menu_ReceiveData;
        gSysState->vblankFunc = NULL;
        ov006_Menu_SetState(self, 3);
        break;
    case 4:
        ov006_Menu_State04(self);
        break;
    case 5:
        ov006_Menu_State05(self);
        break;
    case 6:
        ov006_Menu_State06(self);
        break;
    case 7:
        ov006_Menu_State07(self);
        break;
    case 8:
        ov006_Menu_State08(self);
        break;
    case 9:
        ov006_Menu_State09(self);
        break;
    }
    if (gOv006Menu->state == 0) {
        return;
    }
    if ((u16)((u16)self->state + 0xfffc) > 2) {
        self->unk1D4->unkC = 0xff;
    } else {
        self->unk1D4->unkC = WM_GetLinkLevel();
    }
    h = self->unk1D8;
    if (h->obj == NULL) {
        return;
    }
    h->obj->vfunc_1c();
    if (!ov006_Stateful_IsDone(h->obj)) {
        return;
    }
    OV006_DELETE_OBJECT(h->obj);
}

}
