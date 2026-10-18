#include "ov013/ov013.h"

extern "C" {

extern const u8 data_ov003_021f4344;
extern char data_ov013_0220ba79[];
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov013Sub48 *p);
extern void func_ov003_021cf330(void *p, const char *name, u8 a);
extern BOOL func_ov000_021950e8(Ov013Actor *self, Ov013Msg *msg);

void func_ov013_02205fa4(Ov013Actor *self) {
    Ov013Sub48 *m;
    func_ov000_02194758(self);
    switch (self->kind) {
    case 0x4808:
        FLD(u16, self, 0xd0) = 0x1555;
        break;
    case 0x4809:
        FLD(u16, self, 0xd0) = 0xeaaa;
        break;
    }
    self->unk_38->unk_c2_0 = 0;
    func_ov000_02198360(self->unk_40, 0x20, 0);
    m = self->unk_48;
    m->unk_9a_1 = 1;
    m->unk_9a_4 = 1;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    self->unk_48->unk_9a_6 = 0;
    self->unk_48->unk_30 = 0x20000000;
    func_ov003_021cf330((u8 *)self + 0xe0, data_ov013_0220ba79, data_ov003_021f4344);
}

BOOL func_ov013_02206074(Ov013Actor *self, Ov013Msg *msg) {
    BOOL r;
    if (msg->type == 0xe) {
        if (FLD(u8, msg, 8) == 1) {
            FLD(Ov013Flags8, self, 0xce).b1 = 1;
        }
        r = TRUE;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov000_021950e8(self, msg);
    }
    return r;
}

void func_ov013_022060c8(void) {
}

}
