#include "Main/Res/StageCmd.h"

extern "C" {

extern int func_0205cbf0(StageResSlot *slot);
extern void func_0205b348(void);

extern void func_ov000_02183858(FieldState *state, u16 a);
extern void func_ov000_0218386c(FieldState *state, u16 a);
extern void func_ov000_02186dbc(FieldState *state);
extern void func_ov000_021723b4(FieldPlayer *player, u16 a);
extern void func_ov000_021723d8(FieldPlayer *player, u16 a);
extern void func_ov000_021723fc(FieldPlayer *player, u16 a, u16 b, u16 c);
extern void func_ov000_0217242c(FieldPlayer *player, int mode, u16 a);
extern void func_ov000_02185804(FieldState *state, u16 a);
extern void func_ov000_02185918(FieldState *state, u16 a);

extern void func_ov000_02182590(u8 *p);
extern void func_ov000_021836d0(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e);
extern void func_ov000_0218372c(FieldState *state, u16 a);
extern void func_ov000_021837c0(FieldState *state);
extern void func_ov000_021837f8(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e, u16 f);

int func_0205d000(StageResSlot *slot) {
    return func_0205cbf0(slot);
}

int func_0205d00c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    state->unk_d4 = 0;
    return 1;
}

typedef struct FieldStateBits {
    /* 0x000 */ u8 unk_000[0x18c];
    /* 0x18c */ u8 unk_18c;
    /* 0x18d */ u8 unk_18d;
    /* 0x18e */ u8 unk_18e;
    /* 0x18f */ u8 unk_18f;
    /* 0x190 */ u8 flag0 : 1;
    /* 0x190 */ u8 flag1 : 1;
    /* 0x190 */ u8 flag2 : 1;
    /* 0x190 */ u8 flag3 : 1;
    /* 0x190 */ u8 flag4 : 1;
    /* 0x190 */ u8 unk_190_5 : 3;
} FieldStateBits;

int func_0205d044(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    FieldStateBits *b;
    u16 v;
    u16 a0;
    if (Field_HasEvent(10)) {
        return -0x63;
    }
    v = slot->args[1];
    a0 = slot->args[0];
    b = (FieldStateBits *)state;
    b->flag2 = 1;
    b->flag3 = 1;
    b->flag4 = 1;
    b->unk_18d = a0;
    b->unk_18e = v;
    b->unk_18f = v;
    if (slot->args[2] != 0) {
        b->unk_18c = 1;
    }
    return 1;
}

}
