#include "ov006/Tasks.h"
#include "nitro/fx.h"

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern ov006_Unk02097e40 *data_02097e40;

void ov006_Slot_Pack(const ov006_Slot *self, ov006_SlotPacked *buf);
void ov006_Menu_SetOwnEntry(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
void func_ov000_02162a20(ov006_Actor58 *self);
void func_ov000_02162a58(ov006_Actor58 *self);
void func_ov006_021e0af4(ov006_Caption *self);
void func_ov006_021e0b80(ov006_Caption *self);
void func_ov006_021e10d0(ov006_Gauge *self);
void func_ov006_021e1180(ov006_Gauge *self);
void func_ov006_021e463c(ov006_Unk021ec888 *self);
void func_ov006_021cd580(int a, int b, int c);
void func_ov006_021d2ff0(ov006_TaskD1F *self);
void func_ov006_021d30d4(ov006_TaskD1F *self);
void func_ov006_021d3224(ov006_TaskD1F *self);
void func_ov006_021db258(void);
u16 func_ov006_021e60e8(int type, u16 mask);
void func_ov006_021e5e00(ov006_Unk021ec888 *self);

static inline void ov006_TaskD1F_Finish(ov006_TaskD1F *self) {
    self->unk54->flags |= 2;
    self->unk5C->flags |= 2;
    self->unk60->flags |= 2;
    self->unk64->flags |= 2;
    self->unk58->unk6B8 = 0x28;
    if (self->unk68->visible == 1) {
        self->unk68->visible = 2;
    }
    self->unk_04 |= 6;
}

static inline void ov006_TaskD1F_Exit(ov006_TaskD1F *self, int a) {
    ov006_TaskD1F_Finish(self);
    func_ov006_021cd580(4, a, self->param);
    self->step = 6;
    self->subStep = 0;
}

void func_ov006_021d2e48(ov006_TaskD1F *self) {
    if (self->step != 3 && data_ov006_021ec888->state == 9) {
        self->step = 3;
        self->subStep = 0;
        return;
    }
    switch (self->step) {
    case 0:
        break;
    case 1:
        func_ov006_021d2ff0(self);
        break;
    case 2:
        func_ov006_021d30d4(self);
        break;
    case 3:
        func_ov006_021d3224(self);
        break;
    case 4:
        ov006_TaskD1F_Exit(self, 1);
        break;
    case 5:
        ov006_TaskD1F_Exit(self, 0);
        break;
    case 6:
        break;
    }
}

void func_ov006_021d2ff0(ov006_TaskD1F *self) {
    switch (self->subStep) {
    case 0:
        self->unk54->flags |= 4;
        self->unk60->flags &= ~2;
        {
            Lo021cb0b8 *w = self->unk60;
            w->vfunc_a8(func_ov000_02154b58(w, 1));
        }
        self->subStep++;
        break;
    case 1:
        if (!ov006_Window_IsState5(self->unk60)) {
            return;
        }
        if (self->unk4C == 0) {
            if (self->param == 0) {
                self->step = 4;
                self->subStep = 0;
            } else {
                self->step = 2;
                self->subStep = 0;
            }
        } else {
            self->step = 0;
            self->subStep = 0;
            self->unk54->flags &= ~4;
        }
        break;
    }
}

static inline BOOL ov006_IsReady(int type) {
    BOOL r = TRUE;
    if (!func_ov006_021e60e8(type, 1)) {
        r = FALSE;
    }
    return r;
}

void func_ov006_021d30d4(ov006_TaskD1F *self) {
    switch (self->subStep) {
    case 0:
        self->unk64->flags &= ~2;
        self->unk64->vfunc_70();
        self->unk50 = (self->unk64->openLen >> 12) + 20;
        self->subStep++;
    case 1:
        if (self->unk50 < 0) {
            self->unk50 = 0;
            self->unk49 = 2;
            self->subStep++;
        } else {
            self->unk50--;
            return;
        }
    case 2:
        func_ov006_021db258();
        if (self->param == 1) {
            BOOL r = ov006_IsReady(3);
            if (!r) {
                u16 v = data_02097e40->unk32;
                if (v == func_ov006_021e60e8(2, v)) {
                    self->unk49 = 3;
                }
            }
            if (r) {
                self->step = 4;
                self->subStep = 0;
            }
        } else if (self->param == 2) {
            if (ov006_IsReady(3)) {
                self->step = 4;
                self->subStep = 0;
            }
        } else {
            self->step = 4;
            self->subStep = 0;
        }
        break;
    }
}

void func_ov006_021d3224(ov006_TaskD1F *self) {
    switch (self->subStep) {
    case 0:
        self->unk54->flags |= 4;
        self->unk5C->flags |= 4;
        self->unk60->flags |= 4;
        self->unk64->flags |= 2;
        self->unk60->flags |= 2;
        func_ov006_021e5e00(data_ov006_021ec888);
        self->subStep++;
    case 1:
        if (data_ov006_021ec888->state == 9) {
            return;
        }
        func_0203cc58(0x1e000, 0, 0);
        func_0203cc58(0x1e000, 0, 1);
        self->subStep++;
        break;
    case 2:
        if (!ov006_IsMode4()) {
            return;
        }
        if (!ov006_IsMode4b()) {
            return;
        }
        ov006_TaskD1F_Finish(self);
        func_ov000_0218084c(data_ov000_021ccd44, 0x26, 0);
        self->step = 6;
        self->subStep = 0;
        break;
    }
}

void func_ov006_021d33f4(ov006_TaskD1F *self) {
    int i;
    if (!self->vfunc_28()) {
        return;
    }
    self->unk54->vfunc_20();
    func_ov000_02162a58(self->unk58);
    self->unk5C->vfunc_20();
    self->unk60->vfunc_20();
    self->unk64->vfunc_20();
    func_ov006_021e0b80(self->unk68);
    for (i = 0; i < 4; i++) {
        func_ov006_021e1180(self->gauges[i]);
    }
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

}
