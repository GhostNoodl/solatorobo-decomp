#include "ov006/ov006.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

extern "C" {
extern char data_ov006_021ec864[];

BOOL Ov006Vt_021ec040_IsLoaded(void) {
    BOOL a = ResMgr_IsLoaded(ArcPath_MenuBattle, 7) != 0;
    return (a & ResMgr_IsLoaded(data_ov006_021ec864, 7)) ? TRUE : FALSE;
}

}
