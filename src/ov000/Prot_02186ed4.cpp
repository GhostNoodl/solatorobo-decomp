#include "types.h"

typedef BOOL (*ProtFn)(u32 addr, s32 arg);

typedef struct {
    u8 pad_00[0x22];
    u16 unk_22;
} Ov004Obj;

extern "C" {
extern u8 *data_02149ef0;
extern u32 data_ov004_021cf868;
extern ProtFn data_ov004_021cf86c[];
// Overlay ids, defined by the linker script.
extern u8 OVERLAY_4_ID[];
extern u8 OVERLAY_7_ID[];
void func_0204b270(void *p, s32 a, s32 b);
Ov004Obj *func_ov004_021cce88(void);
void func_ov004_021ccf10(void);
void func_ov002_021ccda0(void);
BOOL func_ov004_021ce2ec(u32 addr, s32 arg);
BOOL func_ov004_021ce374(u32 addr, s32 arg);
BOOL func_ov004_021ce3fc(u32 addr, s32 arg);
BOOL func_ov003_021ce484(u32 addr, s32 arg);

// Checksum of the first 0x1c words of a protected function, used to detect tampering.
static inline u32 ProtHash(const u32 *p) {
    u32 i;
    u32 h;
    for (i = 0x1c, h = 0; i != 0; i--, p++) {
        h ^= (*p >> i) | (*p << (32 - i));
    }
    return h;
}

void func_ov000_02186ed4(void) {
    Ov004Obj *obj;
    BOOL r;
    func_0204b270(data_02149ef0, (s32)OVERLAY_4_ID, 0);
    obj = func_ov004_021cce88();
    if (ProtHash((const u32 *)func_ov004_021ce2ec) == 0x786385f) {
        r = func_ov004_021ce2ec(0x2001000, 0);
    } else {
        r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001000, 0);
    }
    if (r) {
        obj->unk_22 = 1;
    } else {
        if (ProtHash((const u32 *)func_ov004_021ce374) == 0x786385f) {
            r = func_ov004_021ce374(0x2001800, 0);
        } else {
            r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001800, 0);
        }
        if (r) {
            obj->unk_22 = 2;
        } else {
            if (ProtHash((const u32 *)func_ov004_021ce3fc) == 0x786385f) {
                r = func_ov004_021ce3fc(0x2001c00, 0x2001e00);
            } else {
                r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001c00, 0x2001e00);
            }
            if (r) {
                obj->unk_22 = 3;
            } else {
                if (ProtHash((const u32 *)func_ov003_021ce484) == 0x786385f) {
                    r = func_ov003_021ce484(0x2002000, 0);
                } else {
                    r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2002000, 0);
                }
                if (r) {
                    obj->unk_22 = 4;
                }
            }
        }
    }
    func_ov004_021ccf10();
    func_0204b270(data_02149ef0, (s32)OVERLAY_7_ID, 0);
    func_ov002_021ccda0();
}
}
