#include "types.h"

typedef struct {
    u32 unk_00;
    u32 unk_04;
} Ov003ResInfo;

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x2c];
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u16 unk_58;
    u32 unk_5c;
    u8 unk_60[0xc];
    u32 unk_6c;
    u32 unk_70;
    u32 unk_74;
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    u32 unk_84;
    u32 unk_88;
    u8 unk_8c[0x40];
} Ov003Title;

typedef struct {
    u32 unk_00;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Ov003FlagSet;

extern "C" {

extern char data_ov003_021f78c4[];
extern void func_0206f5e4(u16 id, s32 a);
extern void *func_0206f6d4(u16 id, u32 *out);
extern void func_ov000_021c2224(void *p, void *res);
extern u32 *func_0206eed0(void *res);
extern void func_020359fc(const void *a, const void *b, s32 c, s32 d);
extern char data_ov003_021f78cd[];
extern void func_ov000_021c8408(u32 a, u32 b, u32 c, u32 d, u16 e, u32 f, u32 g, u32 h, u32 i, u32 j, u32 k);
extern void func_ov000_021c2208(void *p);
extern void func_02016cd8(u32 v, void *dst, u32 size);
extern u32 func_02035bd4(const void *a, const void *b, s32 c);

void func_ov003_021cd0f4(Ov003Title *self) {
    if (self->unk_0c != 0) {
        u16 id = self->unk_0c;
        void *res;
        self->unk_58 = id;
        func_0206f5e4(self->unk_58, 1);
        res = func_0206f6d4(id, &self->unk_5c);
        func_ov000_021c2224(self->unk_60, res);
        self->unk_50 = func_0206eed0(res)[1];
        self->unk_54 = func_0206eed0(res)[2];
    }
    func_020359fc((void *)self->unk_50, (void *)self->unk_54, 2, 0);
    func_020359fc(data_ov003_021f78c4, data_ov003_021f78cd, 2, 0);
}

BOOL func_ov003_021cd198(Ov003Title *self) {
    BOOL a = (func_02035bd4((void *)self->unk_50, (void *)self->unk_54, 2) & 1) ? TRUE : FALSE;
    return (a & func_02035bd4(data_ov003_021f78c4, data_ov003_021f78cd, 2)) ? TRUE : FALSE;
}

}
