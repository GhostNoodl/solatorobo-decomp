#include "ov006/ov006.h"

typedef struct ov006_Color021d6d3c {
    u8 c[3];
} ov006_Color021d6d3c;

typedef struct ov006_Game021d6d3c {
    u8 unk0[0xca];
    ov006_Color021d6d3c cur;
    ov006_Color021d6d3c next;
    ov006_Color021d6d3c prev;
    u8 unkD3[0xb9];
    u8 unk18C;
    u8 unk18D;
    u8 unk18E;
    u8 unk18F;
    u8 unk190[0x3c];
    u8 unk1CC_0 : 1;
    u8 unk1CC_1 : 1;
    u8 unk1CC_2 : 6;
} ov006_Game021d6d3c;

typedef struct ov006_Fade021d6d3c {
    s32 unk0[3];
    s32 unkC;
} ov006_Fade021d6d3c;

typedef struct ov006_Scene021d6d3c {
    u8 unk0[0xc];
    int unkC;
    u8 unk10[0x2c];
    int unk3C;
} ov006_Scene021d6d3c;

extern "C" {

extern void *data_02097e4c;
extern ov006_Game021d6d3c *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd6c;
extern void *data_0214a420;
extern ov006_Fade021d6d3c data_02097d78;
void func_02049974(void *a, int b);
void func_ov000_0218be9c(void *p);
void func_ov000_0218e894(void *p);
void func_ov000_021b53f4(void *p);
void func_020656b4(void *p);
void func_0203cc58(s32 a, int b, int c);
void func_0203cd10(void);
BOOL func_ov006_021cd2a8(ov006_Manager *m);
void *func_ov006_021dae90(void);
void func_ov006_021cd580(int a, void *b, int c);


static inline void ov006_Game_SetColor(u8 r, u8 g, u8 b) {
    ov006_Game021d6d3c *game = data_ov000_021ccd54;
    game->next.c[0] = r;
    game->next.c[1] = g;
    game->next.c[2] = b;
    game = data_ov000_021ccd54;
    game->prev = game->cur;
    game->cur = game->next;
}

static inline BOOL ov006_FadeIdle(void) {
    BOOL r;
    if (data_02097d78.unkC == 0 && data_02097d78.unk0[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

BOOL func_ov006_021d6d3c(ov006_Scene021d6d3c *self) {
    BOOL r = FALSE;

    switch (self->unkC) {
    case 0:
        func_02049974(data_02097e4c, 0x1e);
        ov006_Game_SetColor(0xff, 0xff, 0xff);
        func_ov000_0218be9c(data_ov000_021ccd64);
        func_ov000_0218e894(data_ov000_021ccd68);
        func_ov000_021b53f4(data_ov000_021ccd6c);
        func_020656b4(data_0214a420);
        {
            ov006_Game021d6d3c *game = data_ov000_021ccd54;
            game->unk1CC_1 = 0;
            game->unk18C = 0;
            game->unk18D = 0;
            game->unk18E = 0;
            game->unk18F = 0;
        }
        data_02097dd0->unk1C = 1;
        data_ov006_021ec888->unk15E = 2;
        if (ov006_FadeIdle()) {
            func_0203cc58(0x1000, 0, 0);
            func_0203cc58(0x1000, 0, 1);
        }
        func_0203cd10();
        if (func_ov006_021cd2a8(data_ov006_021ec860)) {
            self->unkC = 2;
        } else {
            self->unkC++;
        }
        break;
    case 1:
        self->unkC++;
        break;
    case 2:
        data_ov006_021ec860->unk18++;
        func_ov006_021cd580(8, func_ov006_021dae90(), self->unk3C);
        r = TRUE;
        break;
    }
    return r;
}

}
