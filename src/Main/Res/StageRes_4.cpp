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

StageResSlot *func_0205b31c(void) {
    if (data_02149efc.slotStart == data_02149efc.slotEnd) {
        return NULL;
    }
    return &data_02149f18[data_02149efc.slotStart];
}

void func_0205b348(void) {
    if (data_02149efc.slotStart == data_02149efc.slotEnd) {
        return;
    }
    data_02149efc.slotStart++;
    if (data_02149efc.slotStart >= 0x40) {
        data_02149efc.slotStart = 0;
    }
}

StageResSlot *func_0205b378(BOOL pop) {
    s32 end = data_02149efc.slotEnd;
    if (data_02149efc.slotStart == end) {
        return NULL;
    }
    if (pop) {
        end -= pop;
        if (end < 0) {
            end += 0x40;
        }
        data_02149efc.slotEnd = end;
    } else {
        end -= 1;
        if (end < 0) {
            end += 0x40;
        }
    }
    return &data_02149f18[end];
}


u16 func_0205b3cc(StageRes *res, u16 id, u32 argc, u16 *cmd) {
    StageResSlot *slot = Slot_Alloc();
    u16 len;
    u16 i;
    slot->res = res;
    slot->unk_04 = 0;
    slot->id = id;
    len = 1;
    for (i = 0; i < argc; i++) {
        len += res->Eval(cmd + len, 0, 0);
        slot->args[i] = res->value;
    }
    return len;
}

BOOL func_0205b4ac(void) {
    s32 n;
    StageResSlot *slot = StageRes_Peek();
    if (slot == NULL) {
        return FALSE;
    }
    n = 1;
    while (n-- != 0) {
        if (data_0208bde8 != NULL) {
            int r = data_0208bde8(slot);
            if (r == -0x62) {
                n++;
            } else {
                if (r != -0x63) {
                    StageRes_Pop();
                }
                n += r;
            }
        }
        if (n < 1) {
            break;
        }
        slot = StageRes_Peek();
        if (slot == NULL) {
            break;
        }
    }
    return TRUE;
}

u16 func_0205b068(StageRes *res, u16 *cmd, u16 val);

// Reads n bits, LSB first, from bit `start` of block idx's data (an inlined func_02059454).
static inline u16 DataRes_ReadBits(DataRes *res, u32 idx, s32 n, u16 start) {
    u16 r;
    u16 i;
    u8 *bytes;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + ((SaveLayout *)res->data)->blocks[idx].offset;
    r = 0;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u16 byte = pos >> 3;
        u8 sh = pos & 7;
        u8 v = (bytes[byte] >> sh) & 1;
        r |= v << i;
    }
    return r;
}

u16 func_0205b588(StageRes *res, u16 *cmd) {
    u16 len = 2;
    switch (cmd[1]) {
    case 1:
        len++;
        return func_0205b068(res, cmd + len, ((u16 *)&data_02fe1534)[cmd[2]]) + len;
    case 2: {
        u16 val;
        u16 v = cmd[2];
        int n = v & 0xff;
        val = DataRes_ReadBits(data_02fe152c, (v & 0xff00) >> 8, n, cmd[3]);
        len += 2;
        return func_0205b068(res, cmd + len, val) + len;
    }
    }
    res->unk_5b = 0;
    return len;
}


}
