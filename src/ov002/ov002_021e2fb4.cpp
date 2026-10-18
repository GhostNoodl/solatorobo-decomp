#include "ov002/ov002.h"

extern "C" {

extern char data_ov002_021effec[];
extern char data_ov002_021efff8[];
void *func_020360b8(void *a, void *b);
void func_02041c5c(void *m, void *fn);
void func_02041c18(void *m, u8 a);
void func_ov002_021e331c(void *self);
void *func_ov002_021e2f04(void *self, void *unused, u8 *entries, u16 *count);

typedef struct MdlFlags021e2fb4 {
    u32 b0 : 2;
    u32 alpha : 5;
    u32 rest : 25;
} MdlFlags021e2fb4;

typedef struct Lo8_021e2fb4 {
    u16 lo : 8;
    u16 hi : 8;
} Lo8_021e2fb4;

static inline BOOL ov002_021e2fb4_flag2(void *o) {
    return FIELD(o, 0x4, Bits32).b2 ? TRUE : FALSE;
}

void func_ov002_021e2fb4(void *self) {
    switch (FIELD(self, 0x48, s32)) {
    case 0:
        if (FIELD(self, 0x45, u8)) {
            void *m = func_0203dd9c(0x160);
            u8 *info;
            if (m != NULL) {
                char *nm = data_ov002_021effec;
                char *file = data_ov002_021efff8;
                if (nm) {
                    func_02041218((u8 *)m + 0x88);
                    func_02041440(m, nm, 0);
                    STD_CopyString((u8 *)m + 0x2c, file);
                }
            }
            FIELD(self, 0x30, void *) = m;
            func_020417e0(FIELD(self, 0x30, void *), func_020360b8(data_ov002_021efff8, data_ov002_021effec));
            FIELD(FIELD(self, 0x30, void *), 0x6c, u32) |= 2;
            FIELD(FIELD(self, 0x30, void *), 0x6c, u32) |= 0x80000;
            FIELD(FIELD(self, 0x30, void *), 0x6c, u32) |= 0x100000;
            FIELD(FIELD(self, 0x30, void *), 0x6c, u32) |= 0x200000;
            func_02041c5c(FIELD(self, 0x30, void *), (void *)func_ov002_021e2f04);
            info = func_0206ede8(FIELD(self, 0x38, u16));
            FIELD(self, 0x3a, u16) = FIELD(func_02070dcc(info[1]), 0x4, Lo8_021e2fb4).lo;
            func_02041c18(FIELD(self, 0x30, void *), info[0]);
            func_02041d9c(FIELD(self, 0x30, void *), 0, FIELD(self, 0x3a, u16));
            FIELD(FIELD(self, 0x30, void *), 0x6c, MdlFlags021e2fb4).alpha = 0x1e;
        }
        func_ov002_021e331c(self);
        FIELD(self, 0x48, s32) = 1;
        break;
    case 1: {
        void *o;
        if (FIELD(self, 0x20, Bits8).b0) {
            return;
        }
        o = FIELD(self, 0x34, void *);
        if (ov002_021e2fb4_flag2(o)) {
            ((VObject *)o)->v0x8();
            FIELD(FIELD(self, 0x34, void *), 0x4, u32) &= ~4;
        }
        {
            u32 saved;
            HEAP_PUSH(saved);
            {
                void *p = FIELD(self, 0x30, void *);
                if (p != NULL) {
                    if (p != NULL) {
                        func_02041558(p);
                        func_02041278((u8 *)p + 0x88);
                        func_0203de1c(p);
                    }
                    FIELD(self, 0x30, void *) = NULL;
                }
            }
            HEAP_POP(saved);
        }
        {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(FIELD(self, 0x34, VObject *));
            HEAP_POP(saved);
        }
        FIELD(self, 0x48, s32) = 2;
        break;
    }
    case 2:
        if (FIELD(self, 0x20, Bits8).b0) {
            FIELD(self, 0x48, s32) = 0;
        }
        break;
    }
}

}
