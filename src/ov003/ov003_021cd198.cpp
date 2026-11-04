#include "types.h"
#include "nitro/mi.h"

typedef struct {
    u32 unk_00;
    u32 unk_04;
} Ov003ResInfo;

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x2c];
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u16 unk_58;
    u32 unk_5c;
    u8 unk_60[0xc];
    u32 unk_6c;
    u32 unk_70;
    u32 unk_74;
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    u32 unk_84;
    u32 unk_88;
    u8 unk_8c[0x40];
} Ov003Title;

typedef struct {
    u32 unk_00;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Ov003FlagSet;

extern "C" {

extern char data_ov003_021f78c4[];
extern BOOL Item_Set_0206f5e4(u16 id, s32 a);
extern void *Item_FindPictureByChip(u16 id, u32 *out);
extern void Obj021c2208_SetPicture(void *p, void *res);
extern u32 *Param_GetPictureInfo(void *res);
extern void ResMgr_LoadArchive(const void *a, const void *b, s32 c, s32 d);
extern char data_ov003_021f78cd[];
extern void func_ov000_021c8408(u32 a, u32 b, u32 c, u32 d, u16 e, u32 f, u32 g, u32 h, u32 i, u32 j, u32 k);
extern void Obj021c2208_Init(void *p);
extern u32 ResMgr_IsArchiveLoaded(const void *a, const void *b, s32 c);

void Ov003TaskVt_021f78f4_Load(Ov003Title *self) {
    if (self->unk_0c != 0) {
        u16 id = self->unk_0c;
        void *res;
        self->unk_58 = id;
        Item_Set_0206f5e4(self->unk_58, 1);
        res = Item_FindPictureByChip(id, &self->unk_5c);
        Obj021c2208_SetPicture(self->unk_60, res);
        self->unk_50 = Param_GetPictureInfo(res)[1];
        self->unk_54 = Param_GetPictureInfo(res)[2];
    }
    ResMgr_LoadArchive((void *)self->unk_50, (void *)self->unk_54, 2, 0);
    ResMgr_LoadArchive(data_ov003_021f78c4, data_ov003_021f78cd, 2, 0);
}

BOOL Ov003TaskVt_021f78f4_IsLoaded(Ov003Title *self) {
    BOOL a = (ResMgr_IsArchiveLoaded((void *)self->unk_50, (void *)self->unk_54, 2) & 1) ? TRUE : FALSE;
    return (a & ResMgr_IsArchiveLoaded(data_ov003_021f78c4, data_ov003_021f78cd, 2)) ? TRUE : FALSE;
}

}
