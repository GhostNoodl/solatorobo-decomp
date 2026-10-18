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

extern void func_ov000_02172450(FieldPlayer *player, int a);

extern void func_ov000_02172518(FieldPlayer *player, u32 id, u8 *pos, BOOL flag);

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


int func_0205d83c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_02172450(data_ov000_021ccd30, 0);
    Field_PushEvent(data_ov000_021ccd54, 0x17, 0);
    return 1;
}

int func_0205d8c4(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    {
        StageRes *res = slot->res;
        u8 *pos = NULL;
        BOOL flag = slot->args[2] != 0 ? TRUE : FALSE;
        u32 id;
        switch (slot->args[0]) {
        case 0:
            id = 0x2712;
            break;
        case 1:
            id = 0x2713;
            break;
        case 2:
            id = 0x2715;
            break;
        case 3:
            id = 0x2716;
            break;
        case 4:
            id = 0x2716;
            break;
        case 5:
            id = 0x2717;
            break;
        case 6:
            id = 0x44f;
            break;
        }
        if (slot->args[1] & 0x8000) {
            pos = res->posEv->pos + (u16)(slot->args[1] & ~0x8000) * 6;
        }
        func_ov000_02172518(data_ov000_021ccd30, id, pos, flag);
    }
    Field_PushEvent(data_ov000_021ccd54, 0x17, 0);
    return 1;
}


int func_0205d9fc(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (slot->args[0] != 0) {
        if (Field_IsPlayerActing()) {
            func_ov000_02172288(data_ov000_021ccd30, 0, 0);
            Field_PushEvent(data_ov000_021ccd54, 0x19, 0);
            return -0x63;
        }
        func_ov000_02172288(data_ov000_021ccd30, 1, slot->args[1]);
        Field_PushEvent(data_ov000_021ccd54, 0x18, 0);
    } else {
        func_ov000_02172288(data_ov000_021ccd30, 0, 0);
        Field_PushEvent(data_ov000_021ccd54, 0x19, 0);
    }
    return 1;
}

int func_0205db70(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    data_02fe1534.unk_2e = slot->args[2];
    data_02fe1534.unk_30 = slot->args[3];
    func_ov000_021722c4(data_ov000_021ccd30, 1, slot->args[0], slot->args[1], data_02fe1534.unk_2e, data_02fe1534.unk_30);
    return 1;
}

int func_0205dbfc(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    data_02fe1534.unk_2e = 0;
    data_02fe1534.unk_30 = 0;
    func_ov000_021722c4(data_ov000_021ccd30, 0, 0, 0, 0, 0);
    return 1;
}

int func_0205dc74(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    Actor_SetDir(data_ov000_021ccd30->unk_11c, data_02fe1534.unk_2e, data_02fe1534.unk_30);
    return 1;
}

int func_0205dcd8(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_02172338(data_ov000_021ccd30, 1, slot->args[0], slot->args[1] * 60, slot->args[2]);
    return 1;
}

int func_0205dd4c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_02172338(data_ov000_021ccd30, 0, 0, 0x7fffffff, 0);
    return 1;
}

int func_0205dda4(StageResSlot *slot) {
    FieldActorState *st;
    if (!func_ov000_021705ec(data_ov000_021ccd30->unk_11c)) {
        return -0x63;
    }
    st = data_ov000_021ccd30->unk_11c->state;
    if (st->bits.flag9 == 1 ? TRUE : FALSE) {
        return 1;
    }
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    switch (slot->args[0]) {
    case 0:
        st->flags |= 0x80;
        break;
    case 1:
        st->flags &= ~0x80;
        break;
    case 2:
        {
            u32 f = st->flags & ~0x10000;
            st->unk_20 = st->unk_1c;
            st->flags = f | 0x120;
        }
        break;
    case 3:
        func_ov000_0216da78(st);
        break;
    }
    return 1;
}

int func_0205de88(StageResSlot *slot) {
    FieldActorState *st;
    if (slot->args[0] == 0 || slot->args[0] == 2) {
        Slot_Push(slot->res, 0x135, slot->args[0]);
        return 1;
    }
    if (!func_ov000_021705ec(data_ov000_021ccd30->unk_11c)) {
        return -0x63;
    }
    st = data_ov000_021ccd30->unk_11c->state;
    if (st->bits.flag9 == 1 ? TRUE : FALSE) {
        return 1;
    }
    switch (slot->args[0]) {
    case 1:
        st->flags &= ~0x80;
        break;
    case 3:
        st->flags &= ~0x80;
        Slot_Push(slot->res, 0x135, slot->args[0]);
        break;
    }
    return 1;
}

int func_0205e04c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    {
        u16 arg = slot->args[1];
        StageRes *res = slot->res;
        u16 hi = (arg >> 12) & 8;
        u16 id = arg & ~0x8000;
        func_ov000_02172390(data_ov000_021ccd30, slot->args[0], func_0204c0e8(hi ? data_02149ef8 : (void *)res->sub, id));
    }
    Field_PushEvent(data_ov000_021ccd54, 0x1a, 0);
    return 1;
}

int func_0205e114(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02186158(state, slot->args[0]);
    return 1;
}

int func_0205e158(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02186204(state, slot->args[0]);
    return 1;
}

int func_0205e19c(StageResSlot *slot) {
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    {
        u16 b;
        u16 id = slot->args[0];
        if (id != 0) {
            b = slot->args[1];
            Stage_FindObj(id, b);
        }
    }
    if (data_02149efc.unk_14 != NULL || data_02149efc.unk_04 != NULL) {
        data_02fe1534.unk_80 = 1;
    } else {
        data_02fe1534.unk_80 = 0;
    }
    return 1;
}



}
