#include "Main/Res/StageCmd.h"

extern "C" {

extern void *data_ov008_021d0500;
extern void func_ov008_021cf9b8(void *m, u32 id);

void func_0205beb0(void) {
    data_ov000_021ccd54->unk_0c8 = TRUE;
}

void func_0205bec8(u16 id) {
    func_ov008_021cf9b8(data_ov008_021d0500, id);
}

}
