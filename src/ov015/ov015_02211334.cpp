#include "ov015/ov015.h"

extern "C" {

void MIi_CpuClear32(u32 val, void *dst, u32 size);
u8 *func_02070744(u16 id);
u8 *func_0206ee20(u16 id);
void func_ov015_022113e8(void *self, void *list, s32 n, u16 a, s32 b);

struct Ov015ItemEnt {
    u16 id;
    u16 pad;
    s32 count;
};
struct Ov015ItemList {
    u8 pad[0xc];
    u16 id;
    u16 pad2;
    Ov015ItemEnt ents[3];
    s32 total;
};
void func_ov015_02211334(Ov015ItemList *self, u16 id) {
    s32 i;
    self->id = id;
    MIi_CpuClear32(0, self->ents, 0x18);
    if (id == 0x800b) {
        return;
    }
    func_ov015_022113e8(self, self->ents, 3, FLD(u16, func_02070744(id), 0x2), 0x171);
    self->total = 0;
    for (i = 0; i < 3; i++) {
        s32 e = self->ents[i].id;
        if (e == 0) {
            return;
        }
        self->total += self->ents[i].count * FLD(u16, func_0206ee20(e), 0x2);

    }
}

}
