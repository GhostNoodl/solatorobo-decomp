#include "Main/Res/StageCmd.h"

extern "C" {

void func_0205bee4(void) {
    data_02149efc.unk_0c = 1;
}

int func_0205bef8(StageResSlot *slot) {
    u8 cmd = slot->id;
    if (Field_HasEvent(0x15)) {
        return -0x63;
    }
    return data_0208bf9c[cmd](slot);
}

int func_0205bf70(StageResSlot *slot) {
    u16 a = slot->args[0];
    if (a == 0xffff) {
        data_0214a424->unk_518_8 = 0;
    } else {
        data_0214a424->unk_518_8 = (u16)((u16)(a & ~0x8000) + 1);
    }
    return 0;
}

int func_0205bfdc(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_021865f8(state);
    return 0;
}

int func_0205c018(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02186bb0(state);
    return 0;
}

int func_0205c054(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    {
        u16 a = slot->args[1];
        StageRes *res = slot->res;
        u16 id = a & ~0x8000;
        u16 g = (a >> 12) & 8;
        func_ov000_0218547c(state, slot->args[0], g ? data_02149ef8 : (void *)res->sub, id);
    }
    return 0;
}

int func_0205c0cc(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    {
        u16 a = slot->args[0];
        StageRes *res = slot->res;
        u16 id = a & ~0x8000;
        u16 g = (a >> 12) & 8;
        func_ov000_021854d4(state, g ? data_02149ef8 : (void *)res->sub, id);
    }
    return 0;
}

int func_0205c140(StageResSlot *slot) {
    u32 v;
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    v = !slot->bits.flag9 ? data_02082a28[slot->args[0]] : slot->args[0];
    if (v & 0x8000) {
        u16 a = slot->args[1];
        StageRes *res = slot->res;
        u16 id = a & ~0x8000;
        u16 g = (a >> 12) & 8;
        func_ov000_02172264(data_ov000_021ccd30, v, id, g ? data_02149ef8 : (void *)res->sub);
    } else {
        func_ov000_02172264(data_ov000_021ccd30, v, slot->args[1], NULL);
    }
    Field_PushEvent(data_ov000_021ccd54, 0x13, 0);
    return 0;
}

void func_0205c234(u16 a, u16 b);

}
