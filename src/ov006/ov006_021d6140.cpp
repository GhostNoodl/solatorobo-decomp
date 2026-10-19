#include "ov006/SlotManager.h"

typedef struct ov006_Color021d6140 {
    u8 c[3];
} ov006_Color021d6140;

typedef struct ov006_Game021d6140 {
    u8 unk0[0xca];
    ov006_Color021d6140 cur;
    ov006_Color021d6140 next;
    ov006_Color021d6140 prev;
} ov006_Game021d6140;

typedef struct ov006_Info021d6140 {
    u8 unk0[0xa];
    u8 lo : 4;
    u8 hi : 4;
} ov006_Info021d6140;

typedef struct ov006_Unk02097e48 {
    u16 unk0_0 : 3;
    u16 active : 1;
    u16 unk0_4 : 12;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} ov006_Unk02097e48;

typedef struct ov006_Task021d6140 {
    void *vtbl;
    int type;
    int state;
    int subState;
    u8 unk10[0x60];
    void *unk70[6];
} ov006_Task021d6140;

extern "C" {

extern char data_0214b105[];
extern char *data_0208cc94;
extern char data_ov006_021ebfe0[];
extern char data_ov006_021ec864[];
extern char data_ov006_021ebfed[];
extern char data_ov006_021ebffc[];
extern const u16 data_ov006_021eb7a8[];
extern ov006_Game021d6140 *data_ov000_021ccd54;
extern ov006_Unk02097e48 *data_02097e48;

void func_020359d0(const char *a, int b, int c);
void func_0206e900(char *dst, const char *src);
void *func_0203dd9c(u32 size);
void *func_ov000_0218e9c4(void *p);
void func_ov000_02193e5c(void *p, u16 id);
void func_0203cc58(s32 a, int b, int c);
void func_0203cd10(void);

static inline void ov006_Game_SetColor(u8 r, u8 g, u8 b) {
    // The aggregate initializer keeps c in memory; its stores are dead but still emitted.
    ov006_Color021d6140 c = {r, g, b};
    ov006_Game021d6140 *game = data_ov000_021ccd54;
    game->next = c;
    game = data_ov000_021ccd54;
    game->prev = game->cur;
    game->cur = game->next;
}

BOOL func_ov006_021d6140(ov006_Task021d6140 *self) {
    char buf[0x21];
    int i;
    func_020359d0(data_0214b105, 7, 0);
    func_020359d0(data_0208cc94, 7, 0);
    func_0206e900(buf, data_ov006_021ebfe0);
    func_020359d0(buf, 7, 0);
    func_020359d0(data_ov006_021ec864, 7, 0);
    func_020359d0(data_ov006_021ebfed, 7, 0);
    func_020359d0(data_ov006_021ebffc, 7, 0);
    for (i = 0; i < 6; i++) {
        void *p = func_0203dd9c(0x138);
        if (p != NULL) {
            p = func_ov000_0218e9c4(p);
        }
        self->unk70[i] = p;
        func_ov000_02193e5c(p, data_ov006_021eb7a8[i]);
    }
    {
        ov006_Info021d6140 *info = (ov006_Info021d6140 *)data_ov006_021ec884->unk8;
        ov006_Game_SetColor(0x12, info->lo, info->hi);
    }
    func_0203cc58(0x1000, 0, 0);
    func_0203cc58(0x1000, 0, 1);
    func_0203cd10();
    {
        ov006_Unk02097e48 *p = data_02097e48;
        if (p->active) {
            p->unk6 = 0x8000;
            p->unk8 = 0xf0;
            p->unk2 = 0;
        }
    }
    return TRUE;
}

}
