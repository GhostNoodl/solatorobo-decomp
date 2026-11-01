#include "ov014/ov014.h"

extern "C" {

extern s32 func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);

s32 func_ov014_022128f4(Ov014Act_0221267c *self, Ov014Msg *msg) {
    s32 r = 0;
    if (msg->type == 6) {
        self->unk_310 |= msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov003_021d1c00(self, msg);
    }
    return r;
}


extern void *data_ov000_021ccd68;
extern u8 *func_ov000_0219bf90(void);
extern Ov014Actor *func_ov000_0218d240(Ov014Obj *self);
extern Ov014Actor *func_ov000_0218e640(void *mgr, u16 id);

static inline Ov014Actor *Ov014_FindById(u16 id) {
    return data_ov000_021ccd68 != NULL ? func_ov000_0218e640(data_ov000_021ccd68, id) : NULL;
}

static inline BOOL Ov014_WaitB6(Ov014Actor *self) {
    BOOL r = FALSE;
    if (self->unk_40->state == 0xffff || self->unk_b6 == 0) {
        r = TRUE;
    } else if (self->unk_b6 != 0xffff && self->unk_b6 != 0) {
        self->unk_b6--;
    }
    return r;
}

void func_ov014_02212948(Ov014Act_0221267c *self) {
    u8 *pl;
    if (!Ov014_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = FLD(u16, pl, 0xc);
    }
    if (func_ov000_0218d240(self) == NULL) {
        return;
    }
    if (*self->unk_50 == 0 || (self->unk_40->flags & 0x200000)) {
        if (self->unk_b4 != 0x1e) {
            *self->unk_50 = 0;
            self->unk_40->flags |= 0x200000;
            self->unk_40->state = 0;
            self->unk_b4 = 0x1e;
            self->unk_b6 = 0xffff;
        }
    }
    if (self->unk_30 != 0) {
        if ((self->unk_30 & 0x200) && *self->unk_50 != 0) {
            Ov014Actor *a;
            self->unk_40->flags = 0;
            self->unk_40->flags |= 0x40000;
            self->unk_40->state = 0;
            a = Ov014_FindById(FLD(u16, self, 0xde));
            if (a != NULL) {
                a->unk_1a = 1;
            }
            self->unk_b4 = 10;
            self->unk_b6 = 0xffff;
            return;
        }
        if (self->unk_30 & 0x40) {
            if (self->unk_b4 != 0x1e) {
                u16 m = self->unk_310;
                if (m & 1) {
                    self->unk_40->state = 0xffff;
                    self->unk_b4 = 10;
                    self->unk_b6 = 0xffff;
                }
                if (m & 2) {
                    Ov014Actor *a;
                    self->unk_40->state = 0xffff;
                    a = Ov014_FindById(FLD(u16, self, 0xde));
                    if (a != NULL) {
                        a->unk_1a = 1;
                    }
                    self->unk_b4 = 0x14;
                    self->unk_b6 = 0xffff;
                }
                if (m & 4) {
                    self->unk_348 = 0;
                } else if (m & 8) {
                    self->unk_348 = 1;
                } else if (m & 0x10) {
                    self->unk_348 = 2;
                }
                if (m & 0x20) {
                    self->unk_354 = 0;
                } else if (m & 0x40) {
                    self->unk_354 = 1;
                }
            }
            self->unk_310 = 0;
        }
    }
    switch (self->unk_b4) {
    case 0:
        self->unk_40->flags |= 0x100000000ULL;
        self->unk_40->state = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 1:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        self->unk_40->flags |= 2;
        self->unk_40->state = 0;
        self->unk_b4 = 10;
        self->unk_b6 = 0xffff;
        break;
    case 10:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        self->unk_40->state = 0;
        self->unk_b6 = 0xffff;
        break;
    case 0x14:
        switch (self->unk_348) {
        case 0:
            func_ov000_02198360(self->unk_40, 0xf, 0);
            break;
        case 1:
            func_ov000_02198360(self->unk_40, 0x10, 0);
            break;
        case 2:
            func_ov000_02198360(self->unk_40, 0x11, 0);
            break;
        default:
            self->unk_40->flags |= 0x8000;
            break;
        }
        self->unk_40->state = 0;
        self->unk_b4++;
        break;
    case 0x15:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        self->unk_40->flags |= 2;
        self->unk_40->state = 0;
        self->unk_b4 = 10;
        self->unk_b6 = 0xffff;
        break;
    case 0x1e: {
        Ov014Sub44 *q = self->unk_44;
        q->unk_22_0 = 0;
        q->unk_22_1 = 0;
        break;
    }
    }
}

}
