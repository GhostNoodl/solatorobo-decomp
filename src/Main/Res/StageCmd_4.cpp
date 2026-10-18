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

int func_0205d044(StageResSlot *slot);

}
