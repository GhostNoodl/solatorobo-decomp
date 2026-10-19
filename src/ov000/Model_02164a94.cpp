#include "ov000/LoCommon.h"

extern "C" {

extern char data_0214b105[];
extern char *data_0208cca0;
extern char data_ov000_021cb8e0[];
extern char data_ov000_021cb8f1[];
extern char data_ov000_021cb8fd[];
extern char data_ov000_021cb909[];
extern u8 *data_0214a424;
extern u8 *data_02097d48;
void *func_02035d5c(const char *a);
void func_0206e900(char *dst, const char *src);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c5c(void *model, void *fn);
void func_02041c18(void *model, void *arg);
void func_ov000_021640fc(void);

static inline void *NewModel(char *nm) {
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        char *n = nm;
        if (n) {
            func_02041218(m + 0x88);
            func_02041440(m, n, 0);
        }
    }
    return m;
}

void func_ov000_02164a94(u8 *self) {
    char buf[0x20];
    void *a;
    void *b;
    s32 *pp;
    s32 saved;
    u8 *m;
    func_02035d5c(data_0214b105);
    a = func_02035d5c(data_0208cca0);
    func_0206e900(buf, data_ov000_021cb8e0);
    b = func_02035d5c(buf);
    LFLD(s32, self, 0x50) = LFLD(s32, data_0214a424, 0x20);
    pp = &LFLD(s32, data_02097d48, 0x9e4);
    saved = *pp;
    *pp = -1;
    m = (u8 *)NewModel(data_ov000_021cb8f1);
    LFLD(void *, self, 0x28) = m;
    func_020417e0(LFLD(void *, self, 0x28), func_02034d88(b, m + 0x4c));
    func_02041d9c(LFLD(void *, self, 0x28), 2, 0xffff);
    m = (u8 *)NewModel(data_ov000_021cb8fd);
    LFLD(void *, self, 0x2c) = m;
    func_020417e0(LFLD(void *, self, 0x2c), func_02034d88(b, m + 0x4c));
    func_02041d9c(LFLD(void *, self, 0x2c), 2, 0xffff);
    m = (u8 *)NewModel(data_ov000_021cb909);
    LFLD(void *, self, 0x24) = m;
    func_020417e0(LFLD(void *, self, 0x24), func_02034d88(a, m + 0x4c));
    func_02041d9c(LFLD(void *, self, 0x24), 2, 0xffff);
    func_02041c5c(LFLD(void *, self, 0x24), (void *)func_ov000_021640fc);
    func_02041c18(LFLD(void *, self, 0x24), self);
    *pp = saved;
}

}
