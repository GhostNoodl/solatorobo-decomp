#include "types.h"
#include "nitro/mi.h"
#include "ov000/VObj.h"

#define V(n) virtual void v##n();

class Ov003Scene {
public:
    V(00) V(04) V(08) V(0c) V(10) V(14) V(18) V(1c) V(20) V(24) V(28) V(2c) V(30) V(34) V(38) V(3c)
    V(40) V(44) V(48) V(4c) V(50)
    virtual BOOL IsDone();
    V(58)
    virtual void Release();
};

typedef struct {
    u8 unk_00[0x14];
    u32 unk_14;
} Ov003Current;

typedef struct {
    void *vtbl;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
} Ov003FlagSet;

extern "C" {

extern void *gMsgRes;
extern Ov003Current *gFinishingTask;
extern u32 gLastTaskId;
extern u32 Ov003TaskVt_021f78f4_vtbl;
extern u32 Task_vtbl;
extern const char *MsgRes_GetString(void *mgr, s32 id);
extern void Heap_Free(void *p);

void Ov003_FormatMsg(void *self, char *dst, u32 size, const char *arg) {
    u32 n = 0;
    const char *fmt;
    u32 max;
    MI_CpuFill8(dst, 0, size);
    max = size - 1;
    fmt = MsgRes_GetString(gMsgRes, 0x5c);
    while (*fmt != 0 && n < max) {
        if (*fmt == '%') {
            while (*arg != 0 && n < max) {
                *dst++ = *arg++;
                n++;
            }
            fmt++;
        } else {
            *dst++ = *fmt++;
            n++;
        }
    }
    *dst = 0;
}

bool Ov003Task_IsCurrent(void *p) {
    BOOL r = (gFinishingTask == p);
    return r;
}

void Ov003Task_SetCurrent(Ov003Current *p) {
    if (gFinishingTask != NULL) {
        gLastTaskId = gFinishingTask->unk_14;
    } else {
        gLastTaskId = 0;
    }
    gFinishingTask = p;
}

BOOL Ov003Task_TryReleaseCurrent(Ov003Scene *self) {
    if (self->IsDone()) {
        if (gFinishingTask != NULL) {
            gLastTaskId = gFinishingTask->unk_14;
        } else {
            gLastTaskId = 0;
        }
        gFinishingTask = NULL;
    }
    return TRUE;
}

void Ov003Task_ReleaseCurrent(Ov003Scene *self) {
    if (self->IsDone()) {
        if (gFinishingTask != NULL) {
            gLastTaskId = gFinishingTask->unk_14;
        } else {
            gLastTaskId = 0;
        }
        gFinishingTask = NULL;
    }
}

bool Ov003Task_TestFlags(u32 *self, u32 mask) {
    BOOL r = (self[1] & mask) ? TRUE : FALSE;
    return r;
}

void Ov003Task_ClearFlag7(Ov003FlagSet *self) {
    self->b7 = 0;
}

void Ov003Task_SetFlag7(Ov003FlagSet *self) {
    self->b7 = 1;
}

bool Ov003Task_GetFlag6(Ov003FlagSet *self) {
    BOOL r = self->b6 ? TRUE : FALSE;
    return r;
}

void Ov003Task_SetFlag6(Ov003FlagSet *self) {
    self->b6 = 1;
}

bool Ov003Task_GetFlag5(Ov003FlagSet *self) {
    BOOL r = self->b5 ? TRUE : FALSE;
    return r;
}

void Ov003Task_SetFlag5(Ov003FlagSet *self) {
    self->b5 = 1;
}

void Ov003Task_ClearFlag4(Ov003FlagSet *self) {
    self->b4 = 0;
}

void Ov003Task_SetFlag4(Ov003FlagSet *self) {
    self->b4 = 1;
}

BOOL Ov003Task_IsReady(void) {
    return TRUE;
}

Ov003Scene *Ov003TaskVt_021f78f4_DtorDelete(Ov003Scene *self) {
    *(void **)self = &Ov003TaskVt_021f78f4_vtbl;
    self->Release();
    *(void **)self = &Task_vtbl;
    self->Release();
    Heap_Free(self);
    return self;
}

Ov003Scene *Ov003TaskVt_021f78f4_Dtor(Ov003Scene *self) {
    *(void **)self = &Ov003TaskVt_021f78f4_vtbl;
    self->Release();
    *(void **)self = &Task_vtbl;
    self->Release();
    return self;
}

// The deleting destructor (slot 0x04) of the object at 0x60 of Ov003Scene (vtable Ov003Vt_021f78e4_vtbl).
void *Ov003Vt_021f78e4_DtorDelete(VObj *self) {
    Heap_Free(self);
    return self;
}

s32 Ov003_SurfaceSoundId(u32 color) {
    u32 c = color & 0xf0f0f0;
    if (c == 0xb06010) {
        return 3;
    }
    if (c == 0x80d0f0) {
        return 6;
    }
    if (c == 0xe0e000) {
        return 0x3b;
    }
    if (c == 0x606060) {
        return 4;
    }
    if (c == 0x5000) {
        return 2;
    }
    return (c == 0x400) ? 0x3d : 1;
}

}
