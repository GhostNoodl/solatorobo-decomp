#include "ov006/ov006.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

extern "C" {
extern char data_ov006_021ec864[];

BOOL func_ov006_021d95a8(void) {
    BOOL a = func_02035b90(data_0208cc94, 7) != 0;
    return (a & func_02035b90(data_ov006_021ec864, 7)) ? TRUE : FALSE;
}

}
