#include "ov006/Model.h"

typedef struct ov006_Sub021e0480 {
    void *vtbl;
    u8 ready;
    u8 unk5;
    char name[8];
    u8 flag;
    u8 unkF;
    s32 x;
    s32 y;
    s32 z;
    ov006_Model *model;
} ov006_Sub021e0480;

typedef struct ov006_Pic021e0480 {
    void *vtbl;
    u8 ready;
    u8 show;
    u8 unk6[2];
    s32 x;
    s32 y;
    s32 z;
    ov006_Model *model;
    ov006_Sub021e0480 *sub;
} ov006_Pic021e0480;

typedef struct ov006_Unk021e0480 {
    void *vtbl;
    s16 state;
    u8 unk6[0x16];
    ov006_Pic021e0480 *pic;
    void *win;
} ov006_Unk021e0480;

extern "C" {

void func_02041c18(ov006_Model *model, const char *name);
void func_ov006_021df5a0(void *win);

static inline void ov006_Sub021e0480_SetPos(ov006_Sub021e0480 *self, s16 x, s16 y, s32 z) {
    self->x = x << 12;
    self->y = y << 12;
    self->z = z;
}

void func_ov006_021e0480(ov006_Unk021e0480 *self) {
    int x;
    int y;
    ov006_Pic021e0480 *pic;
    ov006_Model *m;
    ov006_Sub021e0480 *sub;
    if (self->state == 0) {
        return;
    }
    pic = self->pic;
    if (pic->ready) {
        x = (s16)(pic->x >> 12);
        y = (s16)(pic->y >> 12);
        ov006_Sub021e0480_SetPos(pic->sub, x + 6, y + 0xc, pic->sub->z);
        pic->sub->z = pic->z;
        sub = pic->sub;
        if (sub->ready) {
            func_02041c18(sub->model, sub->name);
            {
                ov006_Model *mm = sub->model;
                mm->unkFC[0].x = sub->x;
                mm->unkFC[0].y = sub->y;
            }
            sub->model->unk150 = sub->z;
            m = sub->model;
            if (sub->flag) {
                ov006_Model_PlayPart(m, 0x1e);
            } else {
                ov006_Model_PlayPart(m, 0x24);
            }
            ov006_Model_PlayPart(sub->model, 0x1f);
        }
        ov006_Model_SetPos(pic->model, 0, (s16)(x + 0x39) << 12, y << 12);
        pic->model->unk150 = pic->z;
        ov006_Model_PlayPart(pic->model, 0xd);
        if (pic->show) {
            ov006_Model_SetPos(pic->model, 0, x << 12, (s16)(y + 0x18) << 12);
            pic->model->unk150 = pic->z;
            ov006_Model_PlayPart(pic->model, 0xf);
        }
    }
    func_ov006_021df5a0(self->win);
}

}
