#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

extern void *data_02097cdc;
extern u8 *data_ov000_021ccd54;
u8 *func_0206e150(void *p);
u8 *func_0206e180(void *p);
void *func_02035d5c(void *e);
void *func_02039674(void *e);
void **func_02034f5c(void *m, void *k);
void **func_02034ec0(void *m, void *k);
void func_0203f0b4(void *p);
void func_02036838(void *a, void *e, s32 b, s32 c);
u8 *func_0206e7d0(u8 id);
void func_0206dedc(void *buf, u8 *p);
void func_0206dde4(void *buf, u8 *p);
void func_02035acc(void *a, void *buf, s32 b);

void func_ov000_021b6994(u8 *self, u8 arg) {
    u8 *e;
    s32 i;
    u8 *p;
    u8 *t;
    u8 buf[0x20];
    if (LFLD(void *, self, 0x10) == NULL) {
        return;
    }
    e = func_0206e150(LFLD(void *, self, 0x10));
    if (e != NULL) {
        for (i = 0; i < LFLD(u8 *, self, 0x10)[0xa]; i++, e += 0x18) {
            void *m = func_02035d5c(e);
            if (m != NULL) {
                void *k = func_02039674(e);
                void **r = func_02034f5c(m, k);
                if (r != NULL) {
                    func_0203f0b4(*r);
                } else {
                    r = func_02034ec0(m, k);
                    if (r != NULL) {
                        func_0203f0b4(*r);
                    }
                }
            }
            func_02036838(data_02097cdc, e, 7, 0);
        }
    }
    e = func_0206e180(LFLD(void *, self, 0x10));
    if (e != NULL) {
        for (i = 0; i < LFLD(u8 *, self, 0x10)[0xb]; i++, e += 0x18) {
            func_02036838(data_02097cdc, e, 7, 0);
        }
    }
    p = data_ov000_021ccd54 + 0xd0;
    if (arg || p[0] == 0xff || p[1] == 0xff || p[2] == 0xff) {
        p = data_ov000_021ccd54 + 0xca;
    }
    t = func_0206e7d0(p[0]);
    func_0206dedc(buf, p);
    func_02035acc(LFLD(void *, t, 8), buf, 0);
    func_0206dde4(buf, p);
    func_02035acc(LFLD(void *, t, 8), buf, 0);
    LFLD(void *, self, 0x10) = NULL;
    LFLD(void *, self, 0xc) = NULL;
}

}
