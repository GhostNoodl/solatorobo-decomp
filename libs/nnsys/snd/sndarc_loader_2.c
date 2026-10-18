#include "nnsys/snd/sndarc.h"

// Heap callbacks of sndarc_loader.c, which release loaded files.

extern u32 func_0201a7f0(void);
extern void func_0201a804(u32 state);
extern void func_0201c008(void *start, void *end);
extern void func_0201c028(void *start, void *end);
extern void func_0201c048(void *start, void *end);
extern void func_0201cb38(void *bank);
extern void func_0201cbd0(void *waveArc);
extern void *func_0201ce20(SndWaveArc *waveArc, int index);
extern void func_0201cdec(SndWaveArc *waveArc, int index, void *data);

void func_020310c4(void *data, void *arc, u32 fileId) {
    void *prev;
    u32 state;
    if (arc == NULL) {
        return;
    }
    state = func_0201a7f0();
    prev = func_0202fef8(arc);
    if (data == func_02030498(fileId)) {
        func_020304c0(fileId, NULL);
    }
    func_0202fef8(prev);
    func_0201a804(state);
}

void func_0203111c(void *data, u32 size, u32 arc, u32 fileId) {
    func_020310c4(data, (void *)arc, fileId);
    func_0201c008(data, (u8 *)data + size);
}

void func_02031144(void *data, u32 size, u32 arc, u32 fileId) {
    func_020310c4(data, (void *)arc, fileId);
    func_0201c028(data, (u8 *)data + size);
    func_0201cb38(data);
}

void func_02031174(void *data, u32 size, u32 arc, u32 fileId) {
    func_020310c4(data, (void *)arc, fileId);
    func_0201c048(data, (u8 *)data + size);
    func_0201cbd0(data);
}

void func_020311a4(void *data, u32 size, u32 arc, u32 fileId) {
    func_020310c4(data, (void *)arc, fileId);
    func_0201cbd0(data);
}

void func_020311c4(void *data, u32 size, u32 waveArc, u32 index) {
    if (data == func_0201ce20((SndWaveArc *)waveArc, index)) {
        func_0201cdec((SndWaveArc *)waveArc, index, NULL);
    }
    func_0201c048(data, (u8 *)data + size);
}
