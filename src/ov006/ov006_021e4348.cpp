#include "ov006/ov006.h"
#include "ov006/Model.h"

typedef struct ov006_TempBuffer {
    u32 unk0;
    u8 data[0x50];
} ov006_TempBuffer;

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x80];
    void *unk80;
} ov006_Unk02097e40;

typedef struct ov006_Stateful {
    ObjectVtbl *vtbl;
    int state;
} ov006_Stateful;

extern "C" {

extern void *data_ov006_021ec424;
extern void *data_ov006_021ec414;
extern ov006_Unk02097e40 *data_02097e40;

void func_ov006_021e3dd4(ov006_ModelHolder *self, int a);
void func_02044e38(ov006_Unk02097e40 *a, int b);
void func_02046a6c(ov006_Unk02097e40 *a, u32 b);
void func_02046a78(ov006_Unk02097e40 *a, void *b, u32 c);
void OS_GetOwnerInfo(void *a);
void MI_CpuCopy8(const void *src, void *dst, u32 size);
int WM_GetLinkLevel(void);
BOOL func_ov006_021e5ef0(const ov006_MenuData *data);
void func_ov006_021e5050(ov006_Unk021ec888 *self);
void func_ov006_021e5604(ov006_Unk021ec888 *self);
void func_ov006_021e51f8(ov006_Unk021ec888 *self);
void func_ov006_021e4d38(ov006_Unk021ec888 *self);
void func_ov006_021e4ed4(ov006_Unk021ec888 *self);
void func_ov006_021e58e4(ov006_Unk021ec888 *self);

static inline void ov006_Menu_SetState(ov006_Unk021ec888 *self, int state) {
    self->unk8 = state;
    self->unkC = 0;
}

static inline u32 ov006_GetOwnerName(void *dst, u32 size) {
    ov006_TempBuffer buf;
    OS_GetOwnerInfo(&buf);
    MI_CpuCopy8(buf.data, dst, size);
    return size;
}

static inline BOOL ov006_Stateful_IsDone(ov006_Stateful *s) {
    return s->state == 5 ? TRUE : FALSE;
}

void func_ov006_021e4348(ov006_Unk021ec888 *self) {
    ov006_ObjectHolder *h;
    switch (self->unk8) {
    case 0: {
        ov006_ModelHolder *mh = (ov006_ModelHolder *)func_0203dd9c(sizeof(ov006_ModelHolder));
        ov006_ObjectHolder *oh;
        if (mh != NULL) {
            mh->vtbl = &data_ov006_021ec424;
            mh->model = NULL;
            mh->unk8 = 1;
            mh->unkC = 0;
        }
        self->unk1D4 = mh;
        func_ov006_021e3dd4(self->unk1D4, 2);
        oh = (ov006_ObjectHolder *)func_0203dd9c(sizeof(ov006_ObjectHolder));
        if (oh != NULL) {
            oh->vtbl = &data_ov006_021ec414;
            oh->obj = NULL;
        }
        self->unk1D8 = oh;
        ov006_Menu_SetState(self, 1);
        break;
    }
    case 2:
        func_02044e38(data_02097e40, 0);
        func_02046a6c(data_02097e40, 0x401336);
        func_02046a78(data_02097e40, self->unkF4, ov006_GetOwnerName(self->unkF4, 0x16));
        data_02097e40->unk80 = (void *)func_ov006_021e5ef0;
        data_02097dd0->unk18 = 0;
        ov006_Menu_SetState(self, 3);
        break;
    case 4:
        func_ov006_021e5050(self);
        break;
    case 5:
        func_ov006_021e5604(self);
        break;
    case 6:
        func_ov006_021e51f8(self);
        break;
    case 7:
        func_ov006_021e4d38(self);
        break;
    case 8:
        func_ov006_021e4ed4(self);
        break;
    case 9:
        func_ov006_021e58e4(self);
        break;
    }
    if (data_ov006_021ec888->unk8 == 0) {
        return;
    }
    if ((u16)((u16)self->unk8 + 0xfffc) > 2) {
        self->unk1D4->unkC = 0xff;
    } else {
        self->unk1D4->unkC = WM_GetLinkLevel();
    }
    h = self->unk1D8;
    if (h->obj == NULL) {
        return;
    }
    h->obj->vtbl->unk1C(h->obj);
    if (!ov006_Stateful_IsDone((ov006_Stateful *)h->obj)) {
        return;
    }
    OV006_DELETE_OBJECT(h->obj);
}

}
