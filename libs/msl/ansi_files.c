#include "msl/ansi_files.h"

int __flush_all(void) {
    int result = 0;
    int i = 1;
    MSLFile *p = &data_0208aa80[0];
    do {
        if (p->mode.file_kind) {
            if (fflush(p)) {
                result = -1;
            }
        }
        p = i < MSL_FILE_COUNT ? &data_0208aa80[i++] : NULL;
    } while (p);
    return result;
}
