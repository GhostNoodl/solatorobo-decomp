#include "ov002/ov002.h"

extern "C" {

static inline BOOL ov002_ResReady(void) {
    return (func_02035bd4(data_ov002_021ef3e4, data_ov002_021ef3f9, 2) & 1) ? TRUE : FALSE;
}

void func_ov002_021ce204(VObject *self) {
    u32 saved;
    switch (FIELD(self, 0x8, s32)) {
    case 8:
        break;
    case 0xc:
        func_ov000_0218084c(*(void **)&data_ov000_021ccd44, 0x12, 0);
        self->v0x4c();
        break;
    }
    switch (FIELD(self, 0x4e, s8)) {
    case 0:
        func_020359fc(data_ov002_021ef3e4, data_ov002_021ef3f9, 2, 0);
        FIELD(self, 0x4f, u8) = 1;
        FIELD(self, 0x4e, s8) = 1;
    case 1:
        if (!ov002_ResReady()) {
            return;
        }
        FIELD(self, 0x4e, s8) = 2;
    case 2: {
        void *m = func_0203dd9c(0x160);
        if (m != NULL) {
            char *nm = data_ov002_021ef3f9;
            char *file = data_ov002_021ef3e4;
            if (nm) {
                func_02041218((u8 *)m + 0x88);
                func_02041440(m, nm, 0);
                STD_CopyString((u8 *)m + 0x2c, file);
            }
        }
        FIELD(self, 0x3c, void *) = m;
        func_020417e0(FIELD(self, 0x3c, void *), func_02034d88(func_02035f30(data_ov002_021ef3e4, data_ov002_021ef3f9, 2), data_ov002_021ef3f9));
        FIELD(FIELD(self, 0x3c, void *), 0x6c, u32) |= 2;
        func_02041d9c(FIELD(self, 0x3c, void *), 0, 0);
        {
            void *p = FIELD(self, 0x3c, void *);
            FIELD(p, 0xfc, s32) = 0;
            FIELD(p, 0x100, s32) = 0;
        }
        FIELD(FIELD(self, 0x3c, void *), 0x150, s32) = -0x1fe66;
        FIELD(self, 0x4e, s8) = 3;
        break;
    }
    case 3:
        if (FIELD(self, 0x4d, u8) == 0) {
            return;
        }
        FIELD(self, 0x4d, u8) = 0;
        HEAP_PUSH(saved);
        {
            void *p = FIELD(self, 0x3c, void *);
            if (p != NULL) {
                if (p != NULL) {
                    func_02041558(p);
                    func_02041278((u8 *)p + 0x88);
                    func_0203de1c(p);
                }
                FIELD(self, 0x3c, void *) = NULL;
            }
        }
        HEAP_POP(saved);
        if (FIELD(self, 0x4f, u8) != 0) {
            func_02035acc(data_ov002_021ef3e4, data_ov002_021ef3f9, 2);
        }
        FIELD(self, 0x4f, u8) = 0;
        FIELD(self, 0x4e, s8) = 4;
        break;
    case 4:
        if (FIELD(self, 0x4c, u8) != 0) {
            FIELD(self, 0x4c, u8) = 0;
            FIELD(self, 0x4e, s8) = 0;
        }
        break;
    }
}

}
