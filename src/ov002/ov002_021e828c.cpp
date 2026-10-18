#include "ov002/ov002.h"

extern "C" {

extern void *data_ov002_021f0104[];
void *func_02035c9c(void *a);
void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

static inline BOOL ov002_ResReady(void *self) {
    BOOL r = FALSE;
    if (FIELD(self, 0x20, void *) != NULL) {
        if (func_02035bd4((u8 *)self + 0x24, (u8 *)self + 0x48, 0)) {
            r = TRUE;
            FIELD(self, 0x68, void *) = func_02035fe8((u8 *)self + 0x24, (u8 *)self + 0x48);
        }
    } else {
        if (func_02035b90((u8 *)self + 0x48, 0)) {
            r = TRUE;
            FIELD(self, 0x68, void *) = func_02035c9c((u8 *)self + 0x48);
        }
    }
    return r;
}

static inline void ov002_ResLoad(void *self) {
    if (FIELD(self, 0x20, void *) != NULL) {
        func_020359fc((u8 *)self + 0x24, (u8 *)self + 0x48, 0, 0);
    } else {
        func_020359d0((u8 *)self + 0x48, 0, 0);
    }
}

static inline void ov002_ResFree(void *self) {
    if (FIELD(self, 0x20, void *) != NULL) {
        func_02035acc((u8 *)self + 0x24, (u8 *)self + 0x48, 0);
    } else {
        func_02036838(data_02097cdc, (u8 *)self + 0x48, 0, 0);
    }
}

BOOL func_ov002_021e828c(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x8, s32)) {
    case 0:
        func_020359fc(data_ov002_021f0104[1], data_ov002_021f0104[2], 2, 0);
        if (FIELD(self, 0x44, void *) != NULL) {
            ov002_ResLoad(self);
            FIELD(self, 0x8, s32) = 10;
        } else {
            FIELD(self, 0x8, s32) = 0x28;
            break;
        }
    case 10:
        if (!ov002_ResReady(self)) {
            break;
        }
        if (FIELD(self, 0x68, void *) != NULL) {
            FIELD(self, 0x8, s32) = 0x28;
            break;
        }
        ov002_ResFree(self);
        FIELD(self, 0x8, s32) = 0x14;
    case 0x14:
        if (FIELD(self, 0x20, void *) != NULL) {
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, FIELD(self, 0x44, void *), 0, 1);
            func_020359fc((u8 *)self + 0x24, (u8 *)self + 0x48, 0, 0);
        } else {
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, FIELD(self, 0x44, void *), 0, 1);
            func_020359d0((u8 *)self + 0x48, 0, 0);
        }
        FIELD(self, 0x8, s32)++;
    case 0x15:
        if (!ov002_ResReady(self)) {
            break;
        }
        if (FIELD(self, 0x68, void *) != NULL) {
            FIELD(self, 0x8, s32) = 0x28;
            break;
        }
        ov002_ResFree(self);
        FIELD(self, 0x8, s32) = 0x1e;
    case 0x1e: {
        char *n = FIELD(self, 0x20, char *);
        if (n != NULL) {
            MI_CpuFill8((u8 *)self + 0x24, 0, 0x20);
            STD_CopyLString((u8 *)self + 0x24, n, 0x20);
            STD_TSNPrintf((u8 *)self + 0x24, 0x20, data_ov002_021f0647, n, data_ov002_021f0104[0x520 / 4]);
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, FIELD(self, 0x44, void *), 0, 0);
            func_020359fc((u8 *)self + 0x24, (u8 *)self + 0x48, 0, 0);
        } else {
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, FIELD(self, 0x44, void *), 0, 0);
            func_020359d0((u8 *)self + 0x48, 0, 0);
        }
        FIELD(self, 0x8, s32)++;
    }
    case 0x1f:
        if (!ov002_ResReady(self)) {
            break;
        }
        FIELD(self, 0x8, s32) = 0x28;
    case 0x28:
        if (!func_02035bd4(data_ov002_021f0104[1], data_ov002_021f0104[2], 2)) {
            break;
        }
        FIELD(self, 0x8, s32) = 0x64;
    case 0x64:
    default:
        r = TRUE;
        break;
    }
    return r;
}

}
