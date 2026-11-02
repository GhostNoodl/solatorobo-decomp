#include "ov002/ov002.h"

extern "C" {

void Task021ef81c_Load(Task021ef81c *self) {
    func_ov000_021763c8();
}

bool Task021ef81c_IsLoaded(void) {
    bool a = func_ov000_02176538() & 1;
    return a & func_ov000_02180838(data_ov000_021ccd44);
}

}
