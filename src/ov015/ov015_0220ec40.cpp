#include "ov015/ov015.h"
#include "nitro/std.h"

extern "C" {



extern u8 *data_ov015_02213368;
extern void *data_02149ef8;
extern u8 *data_0214a424;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb3a8[];
extern u8 data_ov000_021ccbe0[];
extern u8 data_ov000_021ccb54[];
extern u8 data_ov015_022131ac[];
extern u8 data_ov000_021cca40[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cae48[];
extern char data_ov015_02213100[];
void *MsgRes_GetString(void *a, s32 b);
void func_ov000_02157c90(void *a, void *b);
const char *func_0206ffa0(u16 id);
void func_ov000_021c3af4(void *p);
void func_ov000_021c54f4(void *p);
void func_ov000_021c22d8(void *p);
void func_ov000_021c5bac(void *p);
void *func_0206ec48(u16 id);
u8 *func_0206ee20(u16 id);
void func_ov000_021c3fd4(void *a, void *b);
void func_ov000_021c55e8(void *a, void *b);
void func_ov000_021c5630(void *a, void *b);
void func_ov000_021c5678(void *a, void *b);
void func_ov000_0215d980(void *a, s32 b, s32 c);

struct Ov015ItemEnt {
    u16 id;
    s32 cnt;
};

static inline void Ov015_SetXYZ16(u8 *o, s16 x, s16 y, s16 z) {
    FLD(s16, o, 0x64) = x;
    FLD(s16, o, 0x66) = y;
    FLD(s16, o, 0x68) = z;
}

static inline void Ov015_SetXYZ32(u8 *o, s32 x, s32 y, s32 z) {
    FLD(s32, o, 0x58) = x;
    FLD(s32, o, 0x5c) = y;
    FLD(s32, o, 0x60) = z;
}

static inline void *GetRes0220e634(void) {
    return data_02149ef8;
}

void func_ov015_0220e634(Ov015ResultPanel *self, s32 mode) {
    u8 *sh;
    s32 i;
    u8 *p;
    Ov015ItemEnt *items;
    void *res;
    res = GetRes0220e634();
    sh = data_ov015_02213368;
    self->unk_60 = mode;
    p = (u8 *)Heap_Alloc(0xf0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb4a8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb3a8);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x4) = p;
    FLD(s32, p, 0x24) = 0xf8;
    self->unk_04->unk_20 = 1;
    Ov015_SetXYZ16(((u8 *)self->unk_04), 0, 0x19, -0xccd);
    FLD(u16, self->unk_04, 0x48) = 0x28;
    Ov015_SetXYZ32(((u8 *)self->unk_04), -0x100, 0, -0xccd);
    self->unk_04->unk_0c &= ~0x40000;
    self->unk_04->unk_0c &= ~0x20000;
    VCALL(self->unk_04)->v10(MsgRes_GetString(res, 0xcc));
    VCALL(self->unk_04)->v14(MsgRes_GetString(res, 0xcd));
    self->unk_04->unk_2c = 1;
    switch (mode) {
    case 0:
        STD_CopyLString(self->unk_20, (const char *)MsgRes_GetString(res, 0xcf), 0x40);
        break;
    case 1:
        func_ov000_02157c90(self->unk_04, MsgRes_GetString(res, 0xce));
        STD_CopyLString(self->unk_20, func_0206ffa0(FLD(u16, sh, 0xc)), 0x40);
        break;
    default:
        STD_CopyLString(self->unk_20, data_ov015_02213100, 0x40);
        break;
    }
    FLD(u8 *, self->unk_04, 0xe0) = (u8 *)self->unk_20;
    VCALL(self->unk_04)->v08();
    items = (Ov015ItemEnt *)(sh + 0x10);
    p = (u8 *)Heap_Alloc(0x100);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021ccbe0);
        func_ov000_021c3af4(p);
        SET_VT(p, data_ov000_021ccb54);
        func_ov000_021c54f4(p);
    }
    self->unk_08 = p;
    FLD(s32, p, 0x24) = 0xf8;
    FLD(s32, self->unk_08, 0x20) = 3;
    Ov015_SetXYZ16(self->unk_08, 2, 0x3c, -0xccd);
    Ov015_SetXYZ32(self->unk_08, -0x100, 0, -0xccd);
    FLD(s32, self->unk_08, 0x2c) = 1;
    FLD(u32, self->unk_08, 0xc) &= ~0x40000;
    FLD(u8, self->unk_08, 0xf0) = 0;
    if (mode == 1) {
        for (i = 0; i < 3; i++) {
            u16 n;
            void *name;
            u16 k;
            u8 *e;
            u8 *d;
            if (items[i].cnt == 0) {
                break;
            }
            e = (u8 *)Heap_Alloc(0x48);
            if (e != NULL) {
                SET_VT(e, data_ov015_022131ac);
                func_ov000_021c22d8(e);
                SET_VT(e, data_ov000_021cca40);
                func_ov000_021c5bac(e);
            }
            name = func_0206ec48(items[i].id);
            k = 0;
            d = func_0206ee20(items[i].id);
            if (d != NULL) {
                k = FLD(u16, d, 2);
            }
            n = items[i].cnt;
            FLD(void *, e, 0x38) = name;
            FLD(u16, e, 0x3c) = n;
            FLD(s32, e, 0x40) = k * n;
            func_ov000_021c3fd4(self->unk_08, e);
        }
    }
    func_ov000_021c55e8(self->unk_08, MsgRes_GetString(res, 0x9a));
    func_ov000_021c5630(self->unk_08, MsgRes_GetString(res, 0xd3));
    func_ov000_021c5678(self->unk_08, MsgRes_GetString(res, 0x3f));
    VCALL(self->unk_08)->v08();
    FLD(u32, self->unk_08, 0xc) |= 4;
    p = (u8 *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb5a8);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x14) = p;
    FLD(u32, p, 0xc) |= 0x4000000;
    self->unk_14->unk_2c = 1;
    self->unk_14->unk_0c |= 0x20000000;
    self->unk_14->unk_0c |= 0x80000000;
    Ov015_SetXYZ32(((u8 *)self->unk_14), 0x100, 0, -0xcd);
    VCALL(self->unk_14)->vf4(1, MsgRes_GetString(res, 0x36));
    VCALL(self->unk_14)->v08();
    self->unk_14->unk_0c |= 2;
    p = (u8 *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0xc) = p;
    Ov015_SetXYZ16(p, 0x92, 0x78, -0x99a);
    Ov015_SetXYZ32(((u8 *)self->unk_0c), 0x100, 0, -0x99a);
    self->unk_0c->unk_2c = 1;
    FLD(s32, self->unk_0c, 0x84) = 1;
    VCALL(self->unk_0c)->v08();
    if (mode == 1) {
        func_ov000_0215d980(self->unk_0c, FLD(s32, sh, 0x28), 0);
    } else {
        func_ov000_0215d980(self->unk_0c, 0, 0);
    }
    p = (u8 *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x10) = p;
    Ov015_SetXYZ16(p, 0x92, 0x8c, -0x99a);
    Ov015_SetXYZ32(((u8 *)self->unk_10), 0x100, 0, -0x99a);
    self->unk_10->unk_2c = 1;
    FLD(s32, self->unk_10, 0x84) = 1;
    VCALL(self->unk_10)->v08();
    func_ov000_0215d980(self->unk_10, FLD(s32, data_0214a424, 0x618), 0);
}

void func_ov015_0220ec40(Ov015ResultPanel *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(self->unk_04);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_08);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_0c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_14);
    HEAP_POP(saved);
}

}
