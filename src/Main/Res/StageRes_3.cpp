#include "Main/Res/StageRes.h"

extern "C" {

static inline void StageRes_OpenData(PosEvRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

static inline BOOL StageRes_IsBusy(void) {
    return data_02149efc.unk_0c != 0;
}

BOOL func_0205b1fc(void) {
    if (StageRes_IsBusy()) {
        return FALSE;
    }
    return data_02149efc.slotStart != data_02149efc.slotEnd;
}

StageResSlot *func_0205b23c(u16 id) {
    s32 i;
    s32 end;
    StageResSlot *slot;
    end = data_02149efc.slotEnd;
    i = data_02149efc.slotStart;
    if (i == end) {
        return NULL;
    }
    do {
        slot = &data_02149f18[i];
        if (slot->id == id) {
            return slot;
        }
        i++;
        if (i >= 0x40) {
            i = 0;
        }
    } while (i != end);
    return NULL;
}

StageResSlot *func_0205b29c(u16 *ids) {
    StageResSlot *slot;
    s32 i;
    s32 end;
    u16 *p;
    end = data_02149efc.slotEnd;
    i = data_02149efc.slotStart;
    if (i == data_02149efc.slotEnd) {
        return NULL;
    }
    do {
        slot = &data_02149f18[i];
        p = ids;
        while (*p != 0) {
            if (slot->id == *p++) {
                return slot;
            }
        }
        i++;
        if (i >= 0x40) {
            i = 0;
        }
    } while (i != end);
    return NULL;
}

}
