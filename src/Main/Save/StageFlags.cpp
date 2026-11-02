#include "Main/Res/StageCmd.h"
#include "ov000/FieldMgr.h"
#include "Main/Res/ResLoader.h"

extern "C" {

extern StageFlags data_0214aa68;
extern u8 data_0214a428[0x640];
extern void func_0206ccb8(StageFlags *f, u16 a);
extern u16 StageFlags_CountItems(StageFlags *f);

extern s32 func_020591a4(DataRes *res, u8 *buf, s32 a);
extern s32 func_02062370(u8 *buf);
extern s32 SceneStage_Deserialize(u8 *dst, u8 *buf);

typedef struct StageFlagsInit {
    u32 data[5];
} StageFlagsInit;

extern const StageFlagsInit data_02082be4;

void StageFlags_Create(void) {
    StageFlags *f;
    if (data_0214a424 != NULL) {
        return;
    }
    f = (StageFlags *)Heap_AllocLo(sizeof(StageFlags), 4);
    data_0214a424 = f;
    MIi_CpuClearFast(0, f, sizeof(StageFlags));
    f->magic = STAGE_FLAGS_MAGIC;
}

BOOL StageFlags_IsValid(void) {
    return data_0214aa68.magic == STAGE_FLAGS_MAGIC;
}


static inline void StageFlags_ClearEntries(StageFlags *f) {
    s32 i;
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        f->entries[i].id = 0xffff;
        f->entries[i].info = 0;
    }
}

void StageFlags_Reset(StageFlags *f) {
    u32 i;
    MIi_CpuClearFast(0, f, sizeof(StageFlags));
    f->magic = STAGE_FLAGS_MAGIC;
    MIi_CpuClearFast(0, data_0214a428, sizeof(data_0214a428));
    MIi_CpuClearFast(0, &data_0214aa68, 0x640);
    f->unk_01a = 1;
    f->color2.r = 0xfe;
    f->color2.g = 0xfe;
    f->color2.b = 0xfe;
    f->unk_024 = 0;
    MI_CpuFill8(f->items, 0, sizeof(f->items));
    StageFlags_ClearEntries(data_0214a424);
    MI_CpuFill8(f->bits, 0, sizeof(f->bits));
    func_0206ccb8(f, 0x9000);
    MI_CpuFill8(f->unk_12c, 0, sizeof(f->unk_12c));
    StageFlags_CountItems(f);
    for (i = 0; i < 2; i++) {
        f->slots[i] = -1;
    }
    data_02fe1534.unk_58 = 1;
    {
        StageFlagsInit init = data_02082be4;
        MIi_CpuCopy32(&init, f->unk_624, sizeof(f->unk_624));
    }
    f->unk_639 = 0xff;
}


extern s32 func_020590e8(DataRes *res, u8 *buf, s32 size);
extern s32 func_020622ec(u8 *buf, s32 size);
extern s32 SceneStage_Serialize(u8 *src, u8 *buf, s32 size);
extern u16 *StageRes_FindSlot(u32 id);
extern u16 func_020600cc(u16 *obj, StageVec *pos, u16 *rot, u16 *id);
extern BOOL func_02062698(void);
extern void func_02062724(StageVec *pos);
extern u16 func_02062754(void);

void func_0206c824(StageFlags *f);

void func_0206c620(StageFlags *f) {
    u16 *p;
    func_0206c824(f);
    p = StageRes_FindSlot(0x310);
    if (p != NULL) {
        f->color2.r = p[4];
        f->color2.g = p[5];
        f->color2.b = p[6];
    }
    MI_CpuCopy8(f, data_0214a428, sizeof(StageFlags));
}

static inline void StageFlags_SaveBuf(StageFlags *f) {
    s32 n = 0;
    u16 v;
    n += func_020590e8(data_02fe152c, f->buf, sizeof(f->buf));
    n += func_020622ec(f->buf + n, sizeof(f->buf) - n);
    SceneStage_Serialize(&data_ov000_021ccd54->stageFlags, f->buf + n, sizeof(f->buf) - n);
    f->unk_518_16 = data_02fe1534.unk_04;
    v = data_02fe1534.unk_06;
    if (v >= 4) {
        v = 3;
    }
    f->unk_518_28 = v;
}

void func_0206c670(StageFlags *f) {
    StageFlags_SaveBuf(f);
    MI_CpuCopy8(f, data_0214a428, sizeof(StageFlags));
}

void func_0206c72c(StageFlags *f, StageColor *rgb) {
    u16 *p;
    func_0206c824(f);
    if (rgb != NULL) {
        f->color2.r = rgb->r;
        f->color2.g = rgb->g;
        f->color2.b = rgb->b;
    }
    {
        u8 v = data_ov000_021ccd6c->destExit;
        if (v != 0xff) {
            f->unk_138 = v;
        }
    }
    p = StageRes_FindSlot(0x350);
    if (p != NULL) {
        StageVec pos;
        u16 rot[3];
        u16 id;
        func_020600cc(p, &pos, rot, &id);
        if (id == 0xffff) {
            f->pos = pos;
            f->rotY = rot[1];
        }
        f->unk_138 = id & 0xff;
    }
    if (func_02062698()) {
        func_02062724(&f->pos);
        f->rotY = func_02062754();
    }
    MI_CpuCopy8(f, &data_0214aa68, sizeof(StageFlags));
}

void func_0206c824(StageFlags *f) {
    StagePlayer *pl;
    StageFlags_SaveBuf(f);
    pl = ActorMgr_FindPlayer();
    if (pl == NULL) {
        f->bits18.unk_0 = 1;
    } else {
        f->pos = pl->pos;
        f->rotY = pl->rot[1];
        f->target = pl->target;
        f->targetRotY = pl->targetRot[1];
        {
            StageColor *c = &pl->color;
            f->color.r = c->r;
            f->color.g = c->g;
            f->color.b = c->b;
        }
        f->bits18.unk_0 = 0;
    }
    f->unk_138 = 0xffff;
    f->color2.r = data_02fe1534.r;
    f->color2.g = data_02fe1534.g;
    f->color2.b = data_02fe1534.b;
    f->frameCount = data_02097dd0->frameCount;
}

}
