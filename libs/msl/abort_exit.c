#include "nitro/os.h"

typedef struct MSLExitState {
    /* 0x0 */ void (*stdio_exit)(void);
    /* 0x4 */ void (*console_exit)(void);
    /* 0x8 */ long atexit_curr_func;
    /* 0xc */ int aborting;
} MSLExitState;

extern MSLExitState data_0208d940;

extern int func_020077f4(int sig);
extern void func_02009ac8(void);
extern void func_020051dc(int status);

void exit(int status);

void abort(void) {
    func_020077f4(1);
    data_0208d940.aborting = 1;
    exit(1);
}

void exit(int status) {
    if (!data_0208d940.aborting) {
        func_02009ac8();
        if (data_0208d940.console_exit) {
            data_0208d940.console_exit();
            data_0208d940.console_exit = NULL;
        }
    }
    func_020051dc(status);
}
