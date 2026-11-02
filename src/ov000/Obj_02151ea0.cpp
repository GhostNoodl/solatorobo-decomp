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

void func_ov000_02151ee4(UiObj *self, void *arg, void *arg2) {
    if (self->onDrawItem != NULL) {
        self->onDrawItem(arg, self, arg2);
    }
}

bool func_ov000_02151f08(UiObj *self) {
    return IsState2(self);
}

BOOL func_ov000_02151f28(UiList *self) {
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

BOOL func_ov000_02151fa0(UiList *self, UiListItem *arg) {
    if (self->onCursor == NULL) {
        return TRUE;
    }
    return self->onCursor(self, arg);
}

BOOL func_ov000_02151fbc(UiList *self, UiListItem *arg) {
    if (self->onDecide == NULL) {
        return TRUE;
    }
    return self->onDecide(self, arg);
}

s32 func_ov000_02151fd8(UiList *self) {
    return self->unk_c1 * 8;
}

s32 func_ov000_02151fe4(UiObj *self) {
    s32 a = self->vfunc_40() * self->rows;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 func_ov000_02152030(UiObj *self) {
    s32 a = self->vfunc_40() * self->rows;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 func_ov000_0215207c(void) {
    return 0;
}

s32 func_ov000_02152084(void) {
    return 0;
}

s32 func_ov000_0215208c(void) {
    return 4;
}

s32 func_ov000_02152094(void) {
    return 3;
}

s32 func_ov000_0215209c(void) {
    return 8;
}

s32 func_ov000_021520a4(UiList021cb4a8 *self) {
    return self->unk_dc + 0x12;
}

s32 func_ov000_021520b0(UiObj *self) {
    return (s32)(((s64)(self->width << 12) * 0xe7a + 0x800) >> 12) >> 12;
}

s32 func_ov000_021520e4(void) {
    return 0xe;
}

}
