#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e6fbc(void *self, s32 ch);

typedef s32 (*GetChar)(void *);

static inline s32 classifyChar(s32 ch) {
    if (ch == 0) {
        return 1;
    }
    if (ch == 10) {
        return 4;
    }
    if (((int (*)(void))func_0206e8f0)() == 0) {
        if (ch == 0x8141) {
            return 2;
        }
        if (ch == 0x8142) {
            return 3;
        }
    } else {
        if (ch == 0xfeff) {
            return 5;
        }
    }
    return 0;
}

void func_ov002_021e6e40(void *self) {
    char *s = FIELD(self, 0xc0, char *);
    if (s == NULL || s[0] == 0) {
        return;
    }
    FIELD(self, 0xb4, s32) -= FIELD(data_ov002_021f0f98[1], 0xd8, s32);
    while (FIELD(self, 0xb4, s32) < 0 && FIELD(self, 0xc0, char *)[0] != 0) {
        s32 ch = FIELD(self, 0x15c, GetChar)((u8 *)self + 0xc0);
        switch (classifyChar(ch)) {
        case 0:
        case 1:
            break;
        case 2:
            if (((int (*)(void))func_0206e8f0)() == 0) {
                ch = 0x8140;
            }
            FIELD(self, 0xb4, s32) += FIELD(self, 0xbc, s16) != 0 ? 0x5000 : 0;
            break;
        case 3:
            if (((int (*)(void))func_0206e8f0)() == 0) {
                ch = 0x8140;
            }
            FIELD(self, 0xb4, s32) += FIELD(self, 0xbc, s16) != 0 ? 0xa000 : 0;
            break;
        case 4:
            func_ov002_021e6fbc(self, ch);
            ch = FIELD(self, 0x15c, GetChar)((u8 *)self + 0xc0);
            break;
        case 5:
            ch = FIELD(self, 0x15c, GetChar)((u8 *)self + 0xc0);
            break;
        }
        func_ov002_021e6fbc(self, ch);
        FIELD(self, 0xb4, s32) += FIELD(self, 0xbc, s16) << 12;
    }
}

typedef u8 Buf80[0x80];

void func_ov002_021e6fbc(void *self, s32 ch) {
    if (FIELD(self, 0x144, u8 *) > FIELD(self, 0xc4, Buf80) + 0x7e) {
        return;
    }
    if (((int (*)(void))func_0206e8f0)() == 0) {
        if (ch == (ch & 0xff)) {
            *FIELD(self, 0x144, u8 *)++ = ch;
            *FIELD(self, 0x144, u8 *) = 0;
        } else {
            *FIELD(self, 0x144, u8 *)++ = ch >> 8;
            *FIELD(self, 0x144, u8 *)++ = ch;
            *FIELD(self, 0x144, u8 *) = 0;
        }
    } else if (ch == (ch & 0x7f)) {
        *FIELD(self, 0x144, u8 *)++ = ch;
        *FIELD(self, 0x144, u8 *) = 0;
    } else if (ch == (ch & 0x7ff)) {
        *FIELD(self, 0x144, u8 *)++ = ((ch >> 6) & 0x1f) | 0xc0;
        *FIELD(self, 0x144, u8 *)++ = (ch & 0x3f) | 0x80;
        *FIELD(self, 0x144, u8 *) = 0;
    } else {
        *FIELD(self, 0x144, u8 *)++ = ((ch >> 12) & 0xf) | 0xe0;
        *FIELD(self, 0x144, u8 *)++ = ((ch >> 6) & 0x3f) | 0x80;
        *FIELD(self, 0x144, u8 *)++ = (ch & 0x3f) | 0x80;
        *FIELD(self, 0x144, u8 *) = 0;
    }
}

}
