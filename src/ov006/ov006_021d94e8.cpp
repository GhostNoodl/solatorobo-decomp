#include "ov006/ov006.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

typedef struct ov006_Bgm021d94e8 {
    u16 active : 1;
    u16 rest : 15;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} ov006_Bgm021d94e8;

extern "C" {

extern ov006_Bgm021d94e8 *gSndQueue;
extern char data_ov006_021ec864[];
void SndQueue_Push_0204aab0(ov006_Bgm021d94e8 *a);

BOOL Ov006Vt_021ec040_Load(void) {
    ov006_Bgm021d94e8 *s = gSndQueue;
    if (s->active) {
        if (s->unk6 != 0xffff || s->unk4 != 0x4b) {
            u16 v;
            if (s->unk2 != 10 && s->unk2 != 0) {
                if (s->unk6 != 0xffff) {
                    SndQueue_Push_0204aab0(s);
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
    ResMgr_Load(ArcPath_MenuBattle, 7, 0);
    ResMgr_Load(data_ov006_021ec864, 7, 0);
    return TRUE;
}

}
