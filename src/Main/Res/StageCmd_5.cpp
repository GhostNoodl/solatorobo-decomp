#include "Main/Res/StageCmd.h"

extern "C" {

extern int func_0205cbf0(StageResSlot *slot);

extern void func_0205b348(void);

typedef struct StagePlayer {
    /* 0x000 */ u8 unk_000[0xb2a];
    /* 0xb2a */ u8 unk_b2a;
} StagePlayer;

extern void func_ov000_02183858(FieldState *state, u16 a);

extern void func_ov000_0218386c(FieldState *state, u16 a);

extern void func_ov000_02186dbc(FieldState *state);

extern void func_ov000_021723b4(FieldPlayer *player, u16 a);

extern void func_ov000_021723d8(FieldPlayer *player, u16 a);

extern void func_ov000_021723fc(FieldPlayer *player, u16 a, u16 b, u16 c);

extern void func_ov000_0217242c(FieldPlayer *player, int mode, u16 a);

extern void func_ov000_02185804(FieldState *state, u16 a);

extern void func_ov000_02185918(FieldState *state, u16 a);

extern void func_ov000_021b1110(StagePlayer *player, int a);

extern StagePlayer *func_ov000_0219bf90(void);

extern void func_ov000_02182590(u8 *p);

extern void func_ov000_021836d0(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e);

extern void func_ov000_0218372c(FieldState *state, u16 a);

extern void func_ov000_021837c0(FieldState *state);

extern void func_ov000_021837f8(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e, u16 f);

int func_0205d0dc(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    state->unk_18c = 0;
    state->unk_18d = 0;
    state->unk_18e = 0;
    state->unk_18f = 0;
    return 1;
}

int func_0205d124(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    data_02fe1534.unk_42 = 7;
    data_02fe1534.unk_44 = slot->args[0];
    data_02fe1534.unk_80 = slot->args[1];
    StageRes_Pop();
    {
        FieldState *state = data_ov000_021ccd54;
        state->unk_0ac = TRUE;
        func_ov000_02182590(&state->unk_0ac);
    }
    return -0x62;
}

int func_0205d1c0(StageResSlot *slot) {
    func_ov000_021836d0(data_ov000_021ccd54, slot->args[0], slot->args[1], slot->args[2], slot->args[3], slot->args[4]);
    return 1;
}

int func_0205d200(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_0218372c(state, slot->args[0]);
    return 1;
}

int func_0205d244(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_021837c0(state);
    return 1;
}

int func_0205d280(StageResSlot *slot) {
    func_ov000_021837f8(data_ov000_021ccd54, slot->args[0], slot->args[1], slot->args[2], slot->args[3], slot->args[4], slot->args[5]);
    return 1;
}

int func_0205d2c8(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02183858(state, slot->args[0]);
    return 1;
}

int func_0205d30c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_0218386c(state, slot->args[0]);
    return 1;
}

int func_0205d350(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02186dbc(state);
    return 1;
}

int func_0205d38c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021723b4(data_ov000_021ccd30, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d414(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021723d8(data_ov000_021ccd30, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d49c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021723fc(data_ov000_021ccd30, slot->args[0], slot->args[1], slot->args[2]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d52c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_0217242c(data_ov000_021ccd30, 0, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d5b8(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_0217242c(data_ov000_021ccd30, 1, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d644(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_0217242c(data_ov000_021ccd30, 2, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d6d0(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_0217242c(data_ov000_021ccd30, 3, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d75c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02185804(state, slot->args[0]);
    return 0;
}

int func_0205d7a0(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02185918(state, slot->args[0]);
    return 0;
}

int func_0205d7e4(StageResSlot *slot) {
    data_ov000_021ccd30->flag1 = slot->args[0];
    if (slot->args[0] != 0) {
        StagePlayer *player = func_ov000_0219bf90();
        if (player != NULL) {
            func_ov000_021b1110(player, 1);
            player->unk_b2a = 0;
        }
    }
    return 1;
}

}
