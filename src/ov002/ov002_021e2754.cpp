#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

extern VFunc data_0208ba70[];

void TextWin_Init(void *p);

static inline void setVec3(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline Ov002HudInfo *ov002_HudInfo_New(void) {
    Ov002HudInfo *p = (Ov002HudInfo *)Heap_Alloc(sizeof(Ov002HudInfo));
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f000c;
        p->unk_04 = NULL;
        MIi_CpuClear32(0, p->lines, 0x10);
        p->pos.x = 0;
        p->pos.y = 0;
        p->pos.z = 0;
        p->id = 0xffff;
        p->shownId = 0xffff;
        p->unk_28 = 0;
        p->delay = 0;
    }
    return p;
}

static inline Ov002Text2 *ov002_Text_New(void) {
    Ov002Text2 *q = (Ov002Text2 *)Heap_Alloc(0xb8);
    if (q != NULL) {
        *(VFunc **)q = data_0208ba70;
        TextWin_Init(q);
    }
    return q;
}

void Ov002Hud_SetInfo(Ov002Hud *self, u16 id) {
    if (self->info != NULL) {
        if (id == 0xffff) {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(self->info);
            HEAP_POP(saved);
        }
    } else if (id != 0xffff) {
        s32 i;
        Ov002HudInfo *p;
        p = ov002_HudInfo_New();
        self->info = p;
        for (i = 0; i < 4; i++) {
            p->lines[i] = ov002_Text_New();
        }
        p->unk_04 = ov002_Text_New();
        setVec3(&self->info->pos, 0, 0x88000, self->info->pos.z);
    }
    if (self->info != NULL) {
        self->info->id = id;
    }
}

}

extern "C" {
void func_02041c18(Model *m, int a);

static inline void ov002_021e28b0_SetPos(Model *m, s32 x, s32 y) {
    m->unk_10c = x;
    m->unk_110 = y;
}

static inline s8 ov002_021e28b0_Clamp(Ov002Hud *self, int i) {
    s16 v = self->unk_2c[0][i] + self->unk_2c[1][i];
    if (v < 0) {
        v = 0;
    } else if (v > 99) {
        v = 99;
    }
    return v;
}

void func_ov002_021e28b0(Ov002Hud *self) {
    ov002_021e28b0_SetPos(self->unk_10, 0x5e000, -0x4a000);
    Model_PlayPart(self->unk_10, 9);
    ov002_021e28b0_SetPos(self->unk_10, 0x66000, -0x4a000);
    func_02041c18(self->unk_10, 0);
    func_02041c20(self->unk_10, 1, (void *)ov002_021e28b0_Clamp(self, 0));
    Model_PlayPart(self->unk_10, 1);
    ov002_021e28b0_SetPos(self->unk_10, 0x5e000, -0x35000);
    Model_PlayPart(self->unk_10, 9);
    ov002_021e28b0_SetPos(self->unk_10, 0x66000, -0x35000);
    func_02041c18(self->unk_10, 0);
    func_02041c20(self->unk_10, 1, (void *)ov002_021e28b0_Clamp(self, 1));
    Model_PlayPart(self->unk_10, 1);
    ov002_021e28b0_SetPos(self->unk_10, 0x5e000, -0x20000);
    Model_PlayPart(self->unk_10, 9);
    ov002_021e28b0_SetPos(self->unk_10, 0x66000, -0x20000);
    func_02041c18(self->unk_10, 0);
    func_02041c20(self->unk_10, 1, (void *)ov002_021e28b0_Clamp(self, 2));
    Model_PlayPart(self->unk_10, 1);
    ov002_021e28b0_SetPos(self->unk_10, 0x5e000, -0xb000);
    Model_PlayPart(self->unk_10, 9);
    ov002_021e28b0_SetPos(self->unk_10, 0x66000, -0xb000);
    func_02041c18(self->unk_10, 0);
    func_02041c20(self->unk_10, 1, (void *)ov002_021e28b0_Clamp(self, 3));
    Model_PlayPart(self->unk_10, 1);
    ov002_021e28b0_SetPos(self->unk_10, 0x5e000, 0xa000);
    func_02041c18(self->unk_10, 1);
    func_02041c20(self->unk_10, 1, (void *)ov002_021e28b0_Clamp(self, 4));
    Model_PlayPart(self->unk_10, 1);
    ov002_021e28b0_SetPos(self->unk_10, 0x6e000, 0xa000);
    Model_PlayPart(self->unk_10, 10);
}
}
