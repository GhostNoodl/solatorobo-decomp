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

void func_ov000_021c5028(u8 *self, s32 unused, const VecFx32 *pos) {
    VObj *p = LFLD(VObj *, self, 0x94);
    s32 i = 0;
    s32 y = pos->y + LFLD(s32, self, 0xe0);
    s32 x = pos->x;
    s32 z = LFLD(s16, self, 0x68);
    if (p == NULL) {
        return;
    }
    x += 0xc000;
    z -= 0x110;
    do {
        BOOL vis = FALSE;
        switch (self[0xdf]) {
        case 0:
            if (i >= LFLD(s32, self, 0x9c) && i <= LFLD(s32, self, 0x9c) + (LFLD(s32, self, 0x20) - 1)) {
                vis = TRUE;
            }
            break;
        case 1:
            if (i >= LFLD(s32, self, 0x9c) && i <= LFLD(s32, self, 0x9c) + LFLD(s32, self, 0x20)) {
                vis = TRUE;
            }
            break;
        case 2:
            if (i >= LFLD(s32, self, 0x9c) - 1 && i <= LFLD(s32, self, 0x9c) + LFLD(s32, self, 0x20) - 1) {
                vis = TRUE;
            }
            break;
        }
        if (vis) {
            LFLD(s32, p, 0xc) = x;
            LFLD(s32, p, 0x10) = y;
            LFLD(s32, p, 0x14) = z;
            p->vfunc_0c();
            y += LFLD(s32, p, 0x18) << 12;
        }
        p = LFLD(VObj *, p, 0x28);
        i++;
    } while (p != NULL);
}

}
