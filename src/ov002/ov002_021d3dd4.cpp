#include "ov002/ov002.h"

extern "C" {

void Task021ef81c_Load(Task021ef81c *self) {
    MenuScript_Open();
}

bool Task021ef81c_IsLoaded(void) {
    bool a = MenuScript_IsLoaded() & 1;
    return a & func_ov000_02180838(gTaskHost);
}

}
