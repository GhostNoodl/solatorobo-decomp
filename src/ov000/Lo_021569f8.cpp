#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 8;
    u32 alpha : 5;
    u32 color : 8;
    u32 rest : 11;
} TextFlags021569f8;

typedef struct {
    u8 pad_00[0xc];
    s32 id;
    u8 pad_10[0x10];
    VObj *text;
} Item021569f8;

extern "C" {
void func_02041c18(Model *m, s32 a);
void func_ov000_02153f30(VObj *self, s32 a);
void func_ov000_02153f60(VObj *self, s32 a);

static inline BOOL IsNone(s32 id) {
    return id == -1;
}

void func_ov000_021569f8(VObj *self, Item021569f8 *item, s32 x, s32 y, u8 col, u8 front) {
    Model *m;
    if (LFLD(Model *, self, 0xb4) == NULL || item->id == 0xffff) {
        return;
    }
    x += self->vfunc_94();
    if (IsNone(item->id)) {
        if (front) {
            func_ov000_02153f30(item->text, LFLD(s16, self, 0x68));
        } else {
            func_ov000_02153f60(item->text, LFLD(s16, self, 0x68));
        }
        LFLD(TextFlags021569f8, item->text, 4).color = col;
        LFLD(TextFlags021569f8, item->text, 4).alpha = 0x1e;
        item->text->vfunc_20(x, y + 2);
        item->text->vfunc_90();
        return;
    }
    if (front) {
        MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_19 = 1;
        LFLD(Model *, self, 0xb4)->unk_150 = LFLD(s16, self, 0x68) - 0x110;
        MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_20 = 1;
    } else {
        MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_19 = 1;
        LFLD(Model *, self, 0xb4)->unk_150 = LFLD(s16, self, 0x68) - 0x80;
        MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_20 = 0;
    }
    x -= 0x80;
    MODEL_FLAGS(LFLD(Model *, self, 0xb4))->polygon_id = col;
    MODEL_FLAGS(LFLD(Model *, self, 0xb4))->alpha = 0x1e;
    MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_21 = 1;
    if (LFLD(u32, self, 0xc) & 0x800000) {
        Model_SetPos(LFLD(Model *, self, 0xb4), x << 12, (y - 0x5d) << 12);
        Model_PlayPart(LFLD(Model *, self, 0xb4), 7);
        x += 10;
    }
    Model_SetPos(LFLD(Model *, self, 0xb4), x << 12, (y - 0x5e) << 12);
    func_02041c18(LFLD(Model *, self, 0xb4), item->id);
    Model_PlayPart(LFLD(Model *, self, 0xb4), 6);
}
}
