#include "nitro/os.h"

typedef void (*__signal_func_ptr)(int);

#define SIG_DFL ((__signal_func_ptr)0)
#define SIG_IGN ((__signal_func_ptr)1)

#define SIGABRT      1
#define __signal_max 7

extern OSMutex data_0208db40;
extern u32 data_0208da50[];
extern int data_0208da74[];
extern __signal_func_ptr data_0208de74[__signal_max];

void exit(int status);

#define signal_funcs_access 7

static inline void __begin_critical_region(int region) {
    if (!OS_TryLockMutex(&data_0208db40)) {
        data_0208da50[region] = OS_GetCurrentThread()->id;
        data_0208da74[region] = 1;
    } else if (data_0208da50[region] == OS_GetCurrentThread()->id) {
        data_0208da74[region]++;
    } else {
        OS_LockMutex(&data_0208db40);
        data_0208da50[region] = OS_GetCurrentThread()->id;
        data_0208da74[region] = 1;
    }
}

static inline void __end_critical_region(int region) {
    if (--data_0208da74[region] == 0) {
        OS_UnlockMutex(&data_0208db40);
    }
}

int func_020077f4(int sig) {
    __signal_func_ptr temp_r;

    if (sig < 1 || sig > __signal_max) {
        return -1;
    }

    __begin_critical_region(signal_funcs_access);

    temp_r = data_0208de74[sig - 1];
    if (temp_r != SIG_IGN) {
        data_0208de74[sig - 1] = SIG_DFL;
    }

    __end_critical_region(signal_funcs_access);

    if (temp_r == SIG_IGN || (temp_r == SIG_DFL && sig == SIGABRT)) {
        return 0;
    }

    if (temp_r == SIG_DFL) {
        exit(0);
    }

    (*temp_r)(sig);
    return 0;
}
