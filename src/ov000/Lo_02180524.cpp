#include "ov000/VObj.h"
#include "ov000/LoCommon.h"

typedef void (*VoidFn)(void);
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 5; } B8;
extern "C" {
extern void *data_ov000_021ccd6c;
extern void *data_ov000_021ccd68;
extern void *data_0214a420;
extern void *data_ov000_021ccd70;
extern void *data_02149f0c;
extern u8 data_ov000_021ccd50[];
extern VObj *data_ov000_021ccd30;
void func_ov000_021b53a8(void *p);
void func_ov000_0218e3d4(void *p);
void func_02065b84(void *p);
void func_ov000_021bc6c0(void *p);
void func_0205a69c(void *p);

void func_ov000_02180524(u8 *self) {
    s32 ok;
    void *p;
    if (self[0x5e] == 0) {
        return;
    }
    p = LFLD(void *, self, 0x44);
    ok = 0;
    if (LBIT(p, 0xc).b1 ? 1 : 0) {
        if (LFLD(s32, p, 4) == 5 ? 1 : 0) {
            ok = 1;
        }
    }
    if (ok == 0) {
        return;
    }
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) |= 2;
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) |= 2;
    LFLD(u32, LFLD(void *, self, 0x48), 0xc) |= 2;
}

}
