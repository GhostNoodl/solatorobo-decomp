#include "ov002/ov002.h"

extern "C" {

void func_0201e78c(char *dst, const char *src);

void func_ov002_021d36b8(void *self, s32 n) {
    char num[4];
    char buf[0x20];
    {
        u32 saved;
        HEAP_PUSH(saved);
        {
            void *p = FIELD(self, 0xc4, void *);
            if (p != NULL) {
                if (p != NULL) {
                    func_02041558(p);
                    func_02041278((u8 *)p + 0x88);
                    func_0203de1c(p);
                }
                FIELD(self, 0xc4, void *) = NULL;
            }
        }
        HEAP_POP(saved);
    }
    if (FIELD(self, 0xc8, VObject *) == NULL) {
        VObject *p = (VObject *)func_0203dd9c(0x4c);
        if (p != NULL) {
            *(VFunc **)p = data_0208b318;
            p->v0x8();
        }
        FIELD(self, 0xc8, VObject *) = p;
    } else {
        FIELD(self, 0xc8, VObject *)->v0xc();
    }
    FIELD(FIELD(self, 0xc8, void *), 0x44, s32) = 2;
    num[0] = n / 10 + '0';
    num[1] = n % 10 + '0';
    num[2] = 0;
    func_0201e520(buf, data_ov002_021ef5ac[5]);
    func_0201e78c(buf, num);
    FIELD(self, 0xc8, VObject *)->v0x24(data_ov002_021ef5ac[2], buf);
    FIELD(self, 0xcc, s32) = n;
}

}
