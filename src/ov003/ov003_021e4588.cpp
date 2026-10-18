#include "ov003/GmObj.h"

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 1;
} Ov003Spawned;

typedef struct {
    void *vtbl;
    u8 unk_04[0x14];
    s16 unk_18;
    u8 unk_1a[0x76];
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x3c];
    s16 res;
    u8 unk_d2[0x136];
    s16 res2;
    u8 unk_20a;
    u8 unk_20b;
    u8 unk_20c[0x84];
    u8 unk_290[0x20];
    u8 unk_2b0[0x90];
    Ov003Model sub;
    u8 unk_404[0x24];
    Ov003Vec3 unk_428[4];
    s32 unk_458[4];
    u8 unk_468[4];
    u8 unk_46c[0x6ac];
    u8 unk_b18;
} Ov003Big;

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern char data_ov003_021f8574[];
extern char data_ov003_021f858d[];
extern char data_ov003_021f8593[];
extern char data_ov003_021f859e[];
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 a);
extern BOOL func_ov000_02191120(void *model);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003Spawned *func_ov000_0218bf1c(void *mgr, Ov003SpawnInfo *info, Ov003Vec3 *pos, void *rot, u16 a);
extern void func_ov000_0219b71c(Ov003Vec3 *pos, Ov003Vec3 *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern s32 func_02040498(s32 max);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern void STD_CopyString(void *dst, const void *src);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(s16 *res);

BOOL func_ov003_021e4588(Ov003Big *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->res >= 0 && !func_ov000_0218f110(&self->res)) {
        r = FALSE;
    }
    if (self->res2 >= 0 && !func_ov000_0218f110(&self->res2)) {
        r = FALSE;
    }
    return r;
}

}
