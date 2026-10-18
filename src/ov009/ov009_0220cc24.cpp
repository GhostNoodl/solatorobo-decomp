#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215ee4[];
extern s32 func_ov000_0219a510(Ov009Actor *self, s32 a, const Ov009Vec *pos, s32 r, s32 b, void **out);
extern BOOL func_ov000_021985c0(void *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);

void func_ov009_0220cc24(Ov009Actor *self) {
    Ov009Vec v;
    void *list[32];
    s32 i;
    s32 n;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[0], 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        n = func_ov000_0219a510(self, 2, &self->pos, 0x1000, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (list[i] != NULL && func_ov000_021985c0(list[i])) {
                    func_ov000_02198360(self->unk_40, 0x15, 0);
                    break;
                }
            }
        }
        break;
    }
    v = func_ov000_0219bf90()->pos;
    func_ov000_0218d918(self, &v, 0x1000);
    self->unk_98 = self->rot[1];
    func_ov000_0218dbe0(self, 0);
}

}
