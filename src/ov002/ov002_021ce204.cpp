#include "ov002/ov002.h"

extern "C" {

static inline BOOL ov002_ResReady(void) {
    return (func_02035bd4(data_ov002_021ef3e4, data_ov002_021ef3f9, 2) & 1) ? TRUE : FALSE;
}

void func_ov002_021ce204(Task021ef430 *self) {
    void *saved;
    switch (self->state) {
    case 8:
        break;
    case 0xc:
        func_ov000_0218084c(*(void **)&data_ov000_021ccd44, 0x12, 0);
        self->vfunc_4c();
        break;
    }
    switch (self->unk_4e) {
    case 0:
        func_020359fc(data_ov002_021ef3e4, data_ov002_021ef3f9, 2, 0);
        self->unk_4f = 1;
        self->unk_4e = 1;
    case 1:
        if (!ov002_ResReady()) {
            return;
        }
        self->unk_4e = 2;
    case 2: {
        void *m = Heap_Alloc(0x160);
        if (m != NULL) {
            char *nm = data_ov002_021ef3f9;
            char *file = data_ov002_021ef3e4;
            if (nm) {
                func_02041218((PlttRes *)((u8 *)m + 0x88));
                func_02041440((Model *)m, nm, 0);
                STD_CopyString((char *)((u8 *)m + 0x2c), file);
            }
        }
        self->unk_3c = (Model *)m;
        func_020417e0((Model *)self->unk_3c, func_02034d88(func_02035f30(data_ov002_021ef3e4, data_ov002_021ef3f9, 2), data_ov002_021ef3f9));
        self->unk_3c->flags |= 2;
        func_02041d9c((Model *)self->unk_3c, 0, 0);
        {
            void *p = self->unk_3c;
            FIELD(p, 0xfc, s32) = 0;
            FIELD(p, 0x100, s32) = 0;
        }
        self->unk_3c->unk_150 = -0x1fe66;
        self->unk_4e = 3;
        break;
    }
    case 3:
        if (self->unk_4d == 0) {
            return;
        }
        self->unk_4d = 0;
        HEAP_PUSH(saved);
        {
            void *p = self->unk_3c;
            if (p != NULL) {
                if (p != NULL) {
                    func_02041558((Model *)p);
                    func_02041278((PlttRes *)((u8 *)p + 0x88));
                    Heap_Free(p);
                }
                self->unk_3c = NULL;
            }
        }
        HEAP_POP(saved);
        if (self->unk_4f != 0) {
            func_02035acc(data_ov002_021ef3e4, data_ov002_021ef3f9, 2);
        }
        self->unk_4f = 0;
        self->unk_4e = 4;
        break;
    case 4:
        if (self->unk_4c != 0) {
            self->unk_4c = 0;
            self->unk_4e = 0;
        }
        break;
    }
}

}
