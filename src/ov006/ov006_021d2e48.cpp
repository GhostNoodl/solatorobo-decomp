#include "ov006/Tasks.h"
#include "nitro/fx.h"

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern ov006_Unk02097e40 *data_02097e40;

void func_ov006_021dabcc(ov006_Slot *self, void *buf);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
void func_ov000_02162a20(ov006_Actor58 *self);
void func_ov000_02162a58(ov006_Actor58 *self);
void func_ov006_021e0af4(ov006_Unk68 *self);
void func_ov006_021e0b80(ov006_Unk68 *self);
void func_ov006_021e10d0(ov006_Unk021e139c *self);
void func_ov006_021e1180(ov006_Unk021e139c *self);
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
    if (self->unk68->unk4 == 1) {
        self->unk68->unk4 = 2;
    }
    self->base.flags |= 6;
}

static inline void ov006_TaskD1F_Exit(ov006_TaskD1F *self, int a) {
    ov006_TaskD1F_Finish(self);
    func_ov006_021cd580(4, a, self->base.unkC);
    self->base.state = 6;
    self->base.subState = 0;
}

void func_ov006_021d2e48(ov006_TaskD1F *self) {
    if (self->base.state != 3 && data_ov006_021ec888->unk8 == 9) {
        self->base.state = 3;
        self->base.subState = 0;
        return;
    }
    switch (self->base.state) {
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
    switch (self->base.subState) {
    case 0:
        self->unk54->flags |= 4;
        self->unk60->flags &= ~2;
        {
            ov006_Window *w = self->unk60;
            VCALL(w, A8, func_ov000_02154b58(w, 1));
        }
        self->base.subState++;
        break;
    case 1:
        if (!ov006_Window_IsState5(self->unk60)) {
            return;
        }
        if (self->unk4C == 0) {
            if (self->base.unkC == 0) {
                self->base.state = 4;
                self->base.subState = 0;
            } else {
                self->base.state = 2;
                self->base.subState = 0;
            }
        } else {
            self->base.state = 0;
            self->base.subState = 0;
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
    switch (self->base.subState) {
    case 0:
        self->unk64->flags &= ~2;
        VCALL(self->unk64, 70);
        self->unk50 = (self->unk64->unk34 >> 12) + 20;
        self->base.subState++;
    case 1:
        if (self->unk50 < 0) {
            self->unk50 = 0;
            self->unk49 = 2;
            self->base.subState++;
        } else {
            self->unk50--;
            return;
        }
    case 2:
        func_ov006_021db258();
        if (self->base.unkC == 1) {
            BOOL r = ov006_IsReady(3);
            if (!r) {
                u16 v = data_02097e40->unk32;
                if (v == func_ov006_021e60e8(2, v)) {
                    self->unk49 = 3;
                }
            }
            if (r) {
                self->base.state = 4;
                self->base.subState = 0;
            }
        } else if (self->base.unkC == 2) {
            if (ov006_IsReady(3)) {
                self->base.state = 4;
                self->base.subState = 0;
            }
        } else {
            self->base.state = 4;
            self->base.subState = 0;
        }
        break;
    }
}

void func_ov006_021d3224(ov006_TaskD1F *self) {
    switch (self->base.subState) {
    case 0:
        self->unk54->flags |= 4;
        self->unk5C->flags |= 4;
        self->unk60->flags |= 4;
        self->unk64->flags |= 2;
        self->unk60->flags |= 2;
        func_ov006_021e5e00(data_ov006_021ec888);
        self->base.subState++;
    case 1:
        if (data_ov006_021ec888->unk8 == 9) {
            return;
        }
        func_0203cc58(0x1e000, 0, 0);
        func_0203cc58(0x1e000, 0, 1);
        self->base.subState++;
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
        self->base.state = 6;
        self->base.subState = 0;
        break;
    }
}

void func_ov006_021d33f4(ov006_TaskD1F *self) {
    int i;
    if (!VCALL(self, 28)) {
        return;
    }
    VCALL(self->unk54, 20);
    func_ov000_02162a58(self->unk58);
    VCALL(self->unk5C, 20);
    VCALL(self->unk60, 20);
    VCALL(self->unk64, 20);
    func_ov006_021e0b80(self->unk68);
    for (i = 0; i < 4; i++) {
        func_ov006_021e1180(self->gauges[i]);
    }
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

}
