extern "C" {
#include "fs_private.h"
}

typedef struct FSiArchiveStatics {
    FSArchive *arc_list;    // 0x00
    FSDirPos current_dir_pos; // 0x04
} FSiArchiveStatics;

extern "C" {
extern FSiArchiveStatics data_0208e80c;
extern char data_0208e81c[16][16];
BOOL FS_RegisterArchiveName(FSArchive *arc, const char *name, u32 name_len);
}

#define FSiArchiveNameTable data_0208e81c

// The target pools the archive list head twice; this file is C++ only for this second declaration.
namespace Dup { extern "C" FSiArchiveStatics data_0208e80c; }

BOOL FS_RegisterArchiveName(FSArchive *arc, const char *name, u32 name_len) {
    BOOL retval = FALSE;
    OSIntrMode bak_psr = OS_DisableInterrupts();

    if (!FS_FindArchive(name, (int)name_len)) {
        FSArchive *p = data_0208e80c.arc_list;
        FSArchive **pp = &Dup::data_0208e80c.arc_list;
        while (p != NULL) {
            pp = &p->next;
            p = p->next;
        }
        *pp = arc;

        if (name_len <= 3) {
            *(u32 *)arc->name.pack = 0;
            (void)STD_CopyLString(arc->name.pack, name, (int)(name_len + 1));
        } else if (name_len <= 15) {
            int i;
            for (i = 0;; ++i) {
                if (i >= 16) {
                    OS_Terminate();
                } else if (!FSiArchiveNameTable[i][0]) {
                    (void)STD_CopyLString(FSiArchiveNameTable[i], name, (int)(name_len + 1));
                    arc->name.ptr = FSiArchiveNameTable[i];
                    break;
                }
            }
        } else {
            OS_Terminate();
        }

        arc->flag |= 1;
        retval = TRUE;
    }

    (void)OS_RestoreInterrupts(bak_psr);
    return retval;
}
