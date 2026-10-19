#include "nitro/os.h"

typedef struct MSLExitState {
    /* 0x0 */ void (*stdio_exit)(void);
    /* 0x4 */ void (*console_exit)(void);
    /* 0x8 */ long atexit_curr_func;
    /* 0xc */ int aborting;
} MSLExitState;

extern MSLExitState data_0208d940;
extern void (*const data_0208d950[])(void);
extern OSMutex data_0208da98;
extern u32 data_0208da50[];
extern int data_0208da74[];

#define atexit_funcs_access 0

static inline void __begin_critical_region(int region) {
    if (!OS_TryLockMutex(&data_0208da98)) {
        data_0208da50[region] = OS_GetCurrentThread()->id;
        data_0208da74[region] = 1;
    } else if (data_0208da50[region] == OS_GetCurrentThread()->id) {
        data_0208da74[region]++;
    } else {
        OS_LockMutex(&data_0208da98);
        data_0208da50[region] = OS_GetCurrentThread()->id;
        data_0208da74[region] = 1;
    }
}

static inline void __end_critical_region(int region) {
    if (--data_0208da74[region] == 0) {
        OS_UnlockMutex(&data_0208da98);
    }
}

extern int func_020077f4(int sig);
extern void __destroy_global_chain(void);
extern void __exit(int status);
extern int fflush(void *file);
extern void func_020086d4(void);

void exit(int status);

void abort(void) {
    func_020077f4(1);
    data_0208d940.aborting = 1;
    exit(1);
}

void exit(int status) {
    if (!data_0208d940.aborting) {
        __destroy_global_chain();
        if (data_0208d940.console_exit) {
            data_0208d940.console_exit();
            data_0208d940.console_exit = NULL;
        }
    }
    __exit(status);
}

void __exit(int status) {
    __begin_critical_region(atexit_funcs_access);
    while (data_0208d940.atexit_curr_func > 0) {
        (*data_0208d950[--data_0208d940.atexit_curr_func])();
    }
    __end_critical_region(atexit_funcs_access);
    if (data_0208d940.stdio_exit) {
        data_0208d940.stdio_exit();
        data_0208d940.stdio_exit = NULL;
    }
    fflush(NULL);
    func_020086d4();
}
