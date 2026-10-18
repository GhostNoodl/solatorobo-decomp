#include "ov015/ov015.h"

extern "C" {

Ov015Glyph *func_ov015_021fb25c(u8 *self, u16 *ctx, Ov015Glyph *e, u16 *count);
Ov015Glyph *func_ov015_021fb408(void *self, u16 *ctx, Ov015Glyph *e, u16 *count);
void func_0206e900(char *buf, const char *name);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_02041440(void *p, void *name, int c);
void func_020417e0(void *a, void *b);
void func_02041d9c(void *a, int b, int c);
void func_02041c34(void *a, int b, void *cb, void *arg);
void func_0201e520(void *p, void *name);
extern char data_ov015_022128ab[];
extern char data_ov015_022128b5[];
extern void *data_0208cc94;
extern void *data_0208cc88;

Ov015Glyph *func_ov015_021fb408(void *self, u16 *ctx, Ov015Glyph *e, u16 *count) {
    Ov015Glyph *last = &e[*count - 1];
    if (*ctx == 0x10) {
        e[0].w = last->w;
        e[0].x = 0;
        e[0].code = 0;
    }
    *count = 1;
    return e;
}

static inline void Ov015_LabelInit(u8 *t, void *dict, void *name) {
    func_02041440(t, dict, 0);
    func_0201e520(t + 0x2c, name);
}

s32 func_ov015_021fb474(u8 *self) {
    char buf[0x20];
    void *res;
    u8 *t;
    func_0206e900(buf, data_ov015_022128ab);
    res = func_02034d88(func_02035d5c(buf), data_ov015_022128b5);
    func_02041440(FLD(void *, self, 0x24), NULL, 0);
    func_020417e0(FLD(void *, self, 0x24), res);
    func_02041d9c(FLD(void *, self, 0x24), 0, 0xffff);
    FLD(u32, FLD(u8 *, self, 0x24), 0x6c) |= 2;
    FLD(u32, FLD(u8 *, self, 0x24), 0x6c) |= 0x80000;
    {
        void *arg = &data_ov015_0221332c;
        func_02041c34(FLD(void *, self, 0x24), 0xf, (void *)func_ov015_021fb25c, arg);
        func_02041c34(FLD(void *, self, 0x24), 0xe, (void *)func_ov015_021fb25c, arg);
    }
    res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    Ov015_LabelInit(FLD(u8 *, self, 0x28), data_0208cc88, data_0208cc94);
    func_020417e0(FLD(void *, self, 0x28), res);
    func_02041d9c(FLD(void *, self, 0x28), 0, 0x10);
    FLD(u32, FLD(u8 *, self, 0x28), 0x6c) |= 2;
    func_02041c34(FLD(void *, self, 0x28), 0x10, (void *)func_ov015_021fb408, NULL);
    return 1;
}

}
