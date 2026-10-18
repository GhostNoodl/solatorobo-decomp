#include "ov014/ov014.h"

struct Ov014Watch {
    u8 unk_00[4];
    u16 ids[2];
    u16 count;
    u8 unk_0a;
    u8 unk_0b;
    s32 timer;
    s32 step;
    s32 mode;
    u32 wait;
};

extern "C" {

extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern void *data_ov000_021ccd68;
extern Ov014Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0219bdb0(u16 a, u16 b, s32 c, s32 d, s32 e, u8 *f);

BOOL func_ov014_02213e18(Ov014Watch *self) {
    BOOL r = TRUE;
    switch (self->step) {
    case 0: {
        u8 a = 4;
        func_ov000_0219bd20(0x5c16, 0xffff, 6, 0, 1, &a);
        self->step++;
        break;
    }
    case 1:
        if (self->ids[0] != 0xffff) {
            u8 b = 2;
            func_ov000_0219bdb0(self->ids[0], 0xffff, 6, 0, 1, &b);
            self->wait = 90;
        }
        self->step++;
    case 2:
        if (self->wait <= 60) {
            self->step++;
        } else {
            self->wait--;
        }
        break;
    case 3:
        if (self->ids[1] != 0xffff) {
            u8 c = 2;
            func_ov000_0219bdb0(self->ids[1], 0xffff, 6, 0, 1, &c);
            self->wait = 90;
        }
        self->step++;
    case 4:
        if (self->wait == 0) {
            self->step++;
        } else {
            self->wait--;
        }
        break;
    case 5:
        r = FALSE;
        break;
    }
    return r;
}

BOOL func_ov014_02213f74(Ov014Watch *self) {
    BOOL r = TRUE;
    switch (self->step) {
    case 0: {
        u8 a = 8;
        func_ov000_0219bd20(0x5c16, 0xffff, 6, 0, 1, &a);
        self->step++;
        break;
    }
    case 1:
        if (self->ids[0] != 0xffff) {
            u8 b = 0x42;
            Ov014Actor *o;
            u16 id;
            func_ov000_0219bdb0(self->ids[0], 0xffff, 6, 0, 1, &b);
            id = self->ids[0];
            if (data_ov000_021ccd68 == NULL) {
                o = NULL;
            } else {
                o = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
            o->unk_84.x = 0;
            o->unk_84.y = 0;
            o->unk_84.z = 0xf800;
            self->wait = 120;
        }
        self->step++;
    case 2:
        if (self->wait <= 30) {
            self->step++;
        } else {
            self->wait--;
        }
        break;
    case 3:
        if (self->ids[1] != 0xffff) {
            u8 c = 2;
            Ov014Actor *o;
            u16 id;
            func_ov000_0219bdb0(self->ids[1], 0xffff, 6, 0, 1, &c);
            id = self->ids[1];
            if (data_ov000_021ccd68 == NULL) {
                o = NULL;
            } else {
                o = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
            o->unk_84.x = 0;
            o->unk_84.y = 0;
            o->unk_84.z = 0xf800;
            self->wait = 120;
        }
        self->step++;
    case 4:
        if (self->wait == 0) {
            self->step++;
        } else {
            self->wait--;
        }
        break;
    case 5:
        r = FALSE;
        break;
    }
    return r;
}

BOOL func_ov014_02214138(Ov014Watch *self) {
    BOOL r = TRUE;
    switch (self->step) {
    case 0: {
        u8 a = 16;
        func_ov000_0219bd20(0x5c16, 0xffff, 6, 0, 1, &a);
        self->step++;
        break;
    }
    case 1:
        if (self->ids[0] != 0xffff) {
            u8 b = 0x42;
            Ov014Actor *o;
            u16 id;
            func_ov000_0219bdb0(self->ids[0], 0xffff, 6, 0, 1, &b);
            id = self->ids[0];
            if (data_ov000_021ccd68 == NULL) {
                o = NULL;
            } else {
                o = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
            o->unk_84.x = 0;
            o->unk_84.y = 0;
            o->unk_84.z = 0xf800;
            self->wait = 120;
        }
        self->step++;
    case 2:
        if (self->wait <= 100) {
            self->step++;
        } else {
            self->wait--;
        }
        break;
    case 3:
        if (self->ids[1] != 0xffff) {
            u8 c = 2;
            Ov014Actor *o;
            u16 id;
            func_ov000_0219bdb0(self->ids[1], 0xffff, 6, 0, 1, &c);
            id = self->ids[1];
            if (data_ov000_021ccd68 == NULL) {
                o = NULL;
            } else {
                o = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
            o->unk_84.x = 0;
            o->unk_84.y = 0;
            o->unk_84.z = 0xf800;
            self->wait = 120;
        }
        self->step++;
    case 4:
        if (self->wait == 0) {
            self->step++;
        } else {
            self->wait--;
        }
        break;
    case 5:
        r = FALSE;
        break;
    }
    return r;
}

}
