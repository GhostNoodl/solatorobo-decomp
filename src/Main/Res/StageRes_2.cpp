#include "Main/Res/StageRes.h"

extern "C" {

static inline void StageRes_OpenData(PosEvRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

void func_0205ae68(void) {
    data_02149efc.unk_00 = 0;
}

u16 func_0205ae7c(StageRes *res) {
    return res->value;
}

u8 func_0205ae84(StageRes *res) {
    while (res->opCount != 0) {
        res->opCount--;
        switch (res->opStack[res->opCount]) {
        case 0x10:
            if (res->condCount >= 2) {
                res->condStack[res->condCount - 2] = res->condStack[res->condCount - 2] | res->condStack[res->condCount - 1];
                res->condCount--;
            }
            break;
        case 0x11:
            if (res->condCount >= 2) {
                res->condStack[res->condCount - 2] = res->condStack[res->condCount - 2] & res->condStack[res->condCount - 1];
                res->condCount--;
            }
            break;
        case 0x12:
            if (res->condCount >= 1) {
                res->condStack[res->condCount - 1] ^= 1;
            }
            break;
        }
    }
    if (res->condCount >= 2) {
        return 0;
    }
    return res->condStack[0];
}

void func_0205af4c(StageRes *res, u16 val) {
    switch (res->op) {
    case 0x50:
        val = res->value;
        break;
    case 0x51:
        val *= res->value;
        break;
    case 0x52:
        val /= res->value;
        break;
    case 0x53:
        val %= res->value;
        break;
    case 0x54:
        val += res->value;
        break;
    case 0x55:
        val -= res->value;
        break;
    case 0x56:
        val <<= res->value;
        break;
    case 0x57:
        val >>= res->value;
        break;
    case 0x58:
        val &= res->value;
        break;
    case 0x59:
        val |= res->value;
        break;
    case 0x5a:
        val ^= res->value;
        break;
    case 0x5b:
        val &= (u16)~res->value;
        break;
    default:
        return;
    }
    res->Eval(res->varId, 1, val);
}

u16 func_0205b068(StageRes *res, u16 *cmd, u16 val) {
    u16 op = cmd[0];
    BOOL result = FALSE;
    u16 len = 1;
    len += res->Eval(cmd + len, 0, 0);
    switch (op) {
    case 0x60:
        if (val == res->value) {
            result = TRUE;
        }
        break;
    case 0x61:
        if (val != res->value) {
            result = TRUE;
        }
        break;
    case 0x62:
        if (val <= res->value) {
            result = TRUE;
        }
        break;
    case 0x63:
        if (val >= res->value) {
            result = TRUE;
        }
        break;
    case 0x64:
        if (val < res->value) {
            result = TRUE;
        }
        break;
    case 0x65:
        if (val > res->value) {
            result = TRUE;
        }
        break;
    case 0x77:
        if (val & res->value) {
            result = TRUE;
        }
        break;
    case 0x78:
        if (val || res->value) {
            result = TRUE;
        }
        break;
    case 0x79:
        if (val ^ res->value) {
            result = TRUE;
        }
        break;
    case 0x7a:
        if (!(val & res->value)) {
            result = TRUE;
        }
        break;
    default:
        return len;
    }
    res->unk_5b = result;
    return len;
}

void func_0205b1b4(void);

}
