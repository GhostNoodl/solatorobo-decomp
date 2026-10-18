#include "ov000/VObj.h"
#include "ov000/Vec.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 r, g, b;
} Rgb8;

typedef struct {
    u16 x, y, z;
} Rot16;

typedef struct {
    u16 id;
    u16 unk_02;
    s16 unk_04[4];
    s16 unk_0c;
    Rgb8 rgb;
    Rot16 rot;
    VecFx32 pos;
} Entry0218b60c;

typedef struct {
    u8 unk_00[0xa];
    u8 mode;
    u8 count;
    Entry0218b60c entries[1];
    u16 cur_id;
    u16 cur_02;
    s16 cur_04[4];
    s16 cur_0c;
} Obj0218b60c;

extern "C" {

void func_ov000_0218b60c(Obj0218b60c *self, const Rgb8 *rgb, const VecFx32 *pos, const Rot16 *rot) {
    Entry0218b60c *e;
    s32 i;
    i = 0;
    e = NULL;
    if (self->mode == 2) {
        for (; i < self->count; i++) {
            if (self->cur_id == self->entries[i].id) {
                e = &self->entries[i];
                break;
            }
        }
        if (e == NULL) {
            return;
        }
    } else {
        self->mode = 2;
        self->count++;
        e = &self->entries[0];
        e->unk_02 = self->cur_02;
        e->id = self->cur_id;
        for (; i < 4; i++) {
            e->unk_04[i] = self->cur_04[i];
        }
        e->unk_0c = self->cur_0c;
    }
    e->pos = *pos;
    e->rot = *rot;
    e->rgb = *rgb;
}

}
