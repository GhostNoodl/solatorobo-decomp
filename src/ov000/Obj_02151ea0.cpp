#include "ov000/UiObj.h"

// The 0xe0-byte list subclasses (data_ov000_021cb4a8 and below).

extern "C" {

extern u8 data_ov000_021caa44[];
extern u8 data_ov000_021cc060[];

static inline BOOL IsState2(UiObj *self) {
    return self->state == 2 ? TRUE : FALSE;
}

VObj *Lo021caa44_Dtor(VObj *self) {
    *(void **)self = data_ov000_021caa44;
    self->vfunc_5c();
    *(void **)self = data_ov000_021cc060;
    self->vfunc_5c();
    return self;
}

void UiObj_DrawItem(UiObj *self, void *arg, void *arg2) {
    if (self->onDrawItem != NULL) {
        self->onDrawItem(arg, self, arg2);
    }
}

bool UiObj_IsShown(UiObj *self) {
    return IsState2(self);
}

BOOL UiList_OnChildDone(UiList *self) {
    BOOL ret;
    if (self->unk_90 == NULL) {
        return TRUE;
    }
    ret = self->unk_90(self, UiList_GetCurrent(self));
    self->unk_90 = NULL;
    return ret;
}

BOOL func_ov000_02151f84(UiList *self, UiListItem *arg) {
    if (self->unk_8c == NULL) {
        return TRUE;
    }
    return self->unk_8c(self, arg);
}

BOOL UiList_OnCursor(UiList *self, UiListItem *arg) {
    if (self->onCursor == NULL) {
        return TRUE;
    }
    return self->onCursor(self, arg);
}

BOOL UiList_OnDecide(UiList *self, UiListItem *arg) {
    if (self->onDecide == NULL) {
        return TRUE;
    }
    return self->onDecide(self, arg);
}

s32 func_ov000_02151fd8(UiList *self) {
    return self->unk_c1 * 8;
}

s32 UiList021cb4a8_GetHeight(UiObj *self) {
    s32 a = self->vfunc_40() * self->rows;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 UiObj_GetHeight(UiObj *self) {
    s32 a = self->vfunc_40() * self->rows;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 UiObj_GetPadTop(void) {
    return 0;
}

s32 UiObj_GetPadBottom(void) {
    return 0;
}

s32 UiList021cb4a8_GetLineSpacing(void) {
    return 4;
}

s32 UiList021cb4a8_GetPadBottom(void) {
    return 3;
}

s32 UiList021cb4a8_GetPadTop(void) {
    return 8;
}

s32 func_ov000_021520a4(UiList021cb4a8 *self) {
    return self->unk_dc + 0x12;
}

s32 func_ov000_021520b0(UiObj *self) {
    return (s32)(((s64)(self->width << 12) * 0xe7a + 0x800) >> 12) >> 12;
}

s32 UiList021cb4a8_GetPadLeft(void) {
    return 0xe;
}

}
