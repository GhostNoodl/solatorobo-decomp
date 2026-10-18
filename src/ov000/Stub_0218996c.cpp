#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x99];
    u8 unk_99;
    u8 unk_9a;
    u8 unk_9b;
    u8 unk_9c_0 : 2;
    u8 unk_9c_2 : 1;
    u8 unk_9c_3 : 1;
    u8 unk_9c_4 : 1;
    u8 unk_9c_5 : 3;
} Sub0218996c;

typedef struct {
    u8 unk_00[0xf4];
    Sub0218996c sub;
} Obj0218996c;

typedef struct {
    u8 unk_00[4];
    Obj0218996c *unk_04;
} Data021ccd50;

extern "C" {

extern Data021ccd50 data_ov000_021ccd50;
void func_ov000_0218a358(Sub0218996c *s, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);

void func_ov000_0218996c(u8 a, u8 b) {
    Sub0218996c *s = &data_ov000_021ccd50.unk_04->sub;
    if (s == NULL) {
        return;
    }
    s->unk_9c_2 = 1;
    s->unk_9c_3 = 1;
    s->unk_9c_4 = 1;
    s->unk_99 = a;
    s->unk_9a = b;
    s->unk_9b = b;
}

void func_ov000_0218999c(u8 a, u8 b) {
    Sub0218996c *s = &data_ov000_021ccd50.unk_04->sub;
    if (s == NULL) {
        return;
    }
    s->unk_9c_2 = 0;
    s->unk_9c_3 = 1;
    s->unk_9c_4 = 0;
    s->unk_99 = a;
    s->unk_9a = b;
    s->unk_9b = b;
}

void func_ov000_021899d8(s32 a, s32 b, s32 c, s32 d, s16 e, s16 f) {
    Sub0218996c *s = &data_ov000_021ccd50.unk_04->sub;
    if (s == NULL) {
        return;
    }
    func_ov000_0218a358(s, a, b, c, d, e, f, 1);
}

}
