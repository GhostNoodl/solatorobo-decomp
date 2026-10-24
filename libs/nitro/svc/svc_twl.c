#include "nitro/os.h"

// TWL-only SVC wrappers (Thumb). Each one stops the program on NITRO hardware.
// func_0200c118 calls the ARM function at 0x0228cc6c with blx, so that symbol is
// an `arm` entry in abs_symbols.txt (a typed stub section, see tools/lcf_abs.py).

BOOL func_02018da4(void);
void OS_Terminate(void);

/* TWL only (absolute symbols, see config/usa/arm9/abs_symbols.txt) */
void func_0228caa0(void *context);
void func_0228caac(void *context, const void *data, u32 len);
void func_0228cab0(void *digest, void *context);
void func_0228cc6c(void *digest, const void *src, int len, const void *key, u32 keylen);

#pragma force_active on
#pragma thumb on

void func_0200c0c4(void *context)
{
    if (!func_02018da4()) {
        OS_Terminate();
    }
    func_0228caa0(context);
}

void func_0200c0dc(void *context, const void *data, u32 len)
{
    if (!func_02018da4()) {
        OS_Terminate();
    }
    func_0228caac(context, data, len);
}

void func_0200c0fc(void *digest, void *context)
{
    if (!func_02018da4()) {
        OS_Terminate();
    }
    func_0228cab0(digest, context);
}

void func_0200c118(void *digest, const void *src, int len, const void *key, u32 keylen)
{
    if (!func_02018da4()) {
        OS_Terminate();
    }
    func_0228cc6c(digest, src, len, key, keylen);
}

#pragma thumb reset
#pragma force_active reset
