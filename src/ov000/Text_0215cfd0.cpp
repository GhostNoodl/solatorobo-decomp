#include "types.h"

typedef struct {
    u8 pad_00[0x84];
    s32 unk_84;
    u16 unk_88;
    u8 pad_8a[2];
    char *unk_8c;
    u8 pad_90[0x38];
    char unk_c8[0x100];
} Text0215cfd0;

extern "C" {
extern void *data_02149ef8;
extern char data_ov000_021cabf6[];
extern char data_ov000_021cabfb[];
extern char data_ov000_021cac00[];
char *func_0206ffa0(u16 id);
char *func_0206ec48(u16 id);
char *func_02062020(u16 id);
void func_02040a98(char *buf, u16 id);
char *func_0204c0e8(void *msg, s32 id);
void *func_0203de84(u32 size, u32 align);
void func_0203df0c(void *p);
s32 STD_GetStringLength(const char *s);
void STD_CopyString(char *dst, const char *src);
void STD_ConcatenateString(char *dst, const char *src);

char *func_ov000_0215cfd0(Text0215cfd0 *self) {
    char tmp[0x20];
    char buf[0x100];
    char *s;
    s32 len;

    switch (self->unk_84 & 0xfc00) {
    case 0x1000:
        return func_0206ffa0(self->unk_88);
    case 0x800:
        if (self->unk_88 & 0xf000) {
            s = func_0206ec48(self->unk_88);
        } else {
            s = func_02062020(self->unk_88);
        }
        len = STD_GetStringLength(s);
        if (self->unk_8c != NULL) {
            func_0203df0c(self->unk_8c);
            self->unk_8c = NULL;
        }
        self->unk_8c = (char *)func_0203de84(len + 10, 4);
        STD_CopyString(self->unk_8c, data_ov000_021cabf6);
        STD_ConcatenateString(self->unk_8c, s);
        STD_ConcatenateString(self->unk_8c, data_ov000_021cabfb);
        return self->unk_8c;
    case 0x400:
        func_02040a98(buf, self->unk_88);
        break;
    case 0x2000:
        func_02040a98(buf, self->unk_88);
        STD_ConcatenateString(buf, data_ov000_021cac00);
        STD_ConcatenateString(buf, func_0204c0e8(data_02149ef8, 0x3e));
        break;
    case 0x4000:
        STD_CopyString(buf, func_0204c0e8(data_02149ef8, 0x45));
        func_02040a98(tmp, self->unk_88);
        STD_ConcatenateString(buf, data_ov000_021cac00);
        STD_ConcatenateString(buf, tmp);
        STD_ConcatenateString(buf, data_ov000_021cac00);
        STD_ConcatenateString(buf, func_0204c0e8(data_02149ef8, 0x40));
        break;
    default:
        return NULL;
    }
    STD_CopyString(self->unk_c8, buf);
    return self->unk_c8;
}
}
