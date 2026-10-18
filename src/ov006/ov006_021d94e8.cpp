#include "ov006/ov006.h"

typedef struct ov006_Bgm021d94e8 {
    u16 active : 1;
    u16 rest : 15;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} ov006_Bgm021d94e8;

extern "C" {

extern ov006_Bgm021d94e8 *data_02097e48;
extern void *data_0208cc94;
extern u8 data_ov006_021ec864[];
void func_0204aab0(ov006_Bgm021d94e8 *a);
void func_020359d0(void *a, int b, int c);

BOOL func_ov006_021d94e8(void) {
    ov006_Bgm021d94e8 *s = data_02097e48;
    if (s->active) {
        if (s->unk6 != 0xffff || s->unk4 != 0x4b) {
            u16 v;
            if (s->unk2 != 10 && s->unk2 != 0) {
                if (s->unk6 != 0xffff) {
                    func_0204aab0(s);
                }
                v = 1;
            } else {
                v = 0;
            }
            s->unk2 = v;
            s->unk6 = 0x4b;
            s->unk8 = 10;
        }
    }
    func_020359d0(data_0208cc94, 7, 0);
    func_020359d0(data_ov006_021ec864, 7, 0);
    return TRUE;
}

}
