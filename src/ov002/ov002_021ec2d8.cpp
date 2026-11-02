#include "ov002/ov002.h"
#include "ov002/StaffRoll.h"

extern "C" {

// Fixes up the loaded staff script: string offsets become pointers (or plain numbers when bit 31
// is set) and entry times become fx32. The walk stays in bytes from the script start (entry i's
// seq at +0x14 + i * 0x14, its time at +0x10): an Ov002StaffEntry pointer allocates differently.
void Ov002StaffLoader_Parse(Ov002StaffLoader *self) {
    u8 *p = *(u8 **)self->vfunc_10();
    u8 *base;
    u16 i;
    self->script = (Ov002StaffScript *)p;
    base = p + self->script->poolOfs;
    for (i = 0; i < self->script->count; i++) {
        s32 v;
        p += i * 0x14;
        v = FIELD(p, 0x14, s32);
        if (v != -1) {
            if (v & 0x80000000) {
                FIELD(p, 0x14, s32) = v & ~0x80000000;
            } else {
                FIELD(p, 0x14, s32) = (s32)(base + v);
            }
        } else {
            FIELD(p, 0x14, s32) = 0;
        }
        p = (u8 *)self->script + i * 0x14;
        FIELD(p, 0x10, s32) <<= 12;
        p = (u8 *)self->script;
    }
}

}
