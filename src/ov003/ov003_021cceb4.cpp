#include "types.h"

class Ov003Deletable {
public:
    virtual void v00();
    virtual void Delete();
};

typedef struct {
    u8 unk_00[0x88];
    u8 unk_88[1];
} Ov003Res;

typedef struct {
    void *cur;
    u32 unk_04;
    void *alt;
} Ov003HeapCtx;

typedef struct {
    u8 unk_00[0x3c];
    Ov003Deletable *unk_3c;
    Ov003Deletable *unk_40;
    Ov003Res *unk_44;
    Ov003Res *unk_48;
    Ov003Res *unk_4c;
    u32 unk_50;
    u32 unk_54;
    u16 unk_58;
    u32 unk_5c;
    u8 unk_60[0xc];
    u32 unk_6c;
    u32 unk_70;
    u32 unk_74;
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    u32 unk_84;
    u32 unk_88;
    u8 unk_8c[0x40];
} Ov003Title;

typedef struct {
    u32 unk_00;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Ov003FlagSet;

#define OV003_DELETE_V(p)                              \
    {                                                  \
        void *old = data_02097dd0->cur;                \
        data_02097dd0->cur = data_02097dd0->alt;       \
        if ((p) != NULL) {                             \
            if ((p) != NULL) {                         \
                (p)->Delete();                         \
            }                                          \
            (p) = NULL;                                \
        }                                              \
        data_02097dd0->cur = old;                      \
    }

#define OV003_DELETE_RES(p)                            \
    {                                                  \
        void *old = data_02097dd0->cur;                \
        data_02097dd0->cur = data_02097dd0->alt;       \
        if ((p) != NULL) {                             \
            Ov003Res *res = (p);                       \
            if (res != NULL) {                         \
                func_02041558(res);                    \
                func_02041278(res->unk_88);            \
                func_0203de1c(res);                    \
            }                                          \
            (p) = NULL;                                \
        }                                              \
        data_02097dd0->cur = old;                      \
    }

extern "C" {

extern char data_ov003_021f78c4[];
extern char data_ov003_021f78cd[];
extern void func_ov000_021c8408(u32 a, u32 b, u32 c, u32 d, u16 e, u32 f, u32 g, u32 h, u32 i, u32 j, u32 k);
extern void func_ov000_021c2208(void *p);
extern void MIi_CpuClear32(u32 v, void *dst, u32 size);
extern Ov003HeapCtx *data_02097dd0;
extern void func_02041558(void *p);
extern void func_02041278(void *p);
extern void func_0203de1c(void *p);
extern void func_02035acc(const void *a, const void *b, s32 c);
extern u32 func_02035bd4(const void *a, const void *b, s32 c);

void func_ov003_021cceb4(u32 a, u32 b, u32 c, u32 d, u32 unused, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j) {
    func_ov000_021c8408(a, b, c, d, j, e, f, g, h, i, j);
}

void func_ov003_021ccf00(Ov003Title *self) {
    self->unk_3c = NULL;
    self->unk_40 = NULL;
    self->unk_44 = NULL;
    self->unk_48 = NULL;
    self->unk_4c = NULL;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
    func_ov000_021c2208(self->unk_60);
    self->unk_6c = 0;
    self->unk_70 = 0;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = 0;
    self->unk_80 = 0;
    self->unk_84 = 0;
    self->unk_88 = 0;
    MIi_CpuClear32(0, self->unk_8c, 0x40);
}

void func_ov003_021ccf6c(Ov003Title *self) {
    OV003_DELETE_V(self->unk_3c);
    OV003_DELETE_V(self->unk_40);
    OV003_DELETE_RES(self->unk_44);
    OV003_DELETE_RES(self->unk_48);
    OV003_DELETE_RES(self->unk_4c);
    if (self->unk_50 != 0 && self->unk_54 != 0) {
        func_02035acc((void *)self->unk_50, (void *)self->unk_54, 2);
    }
    func_02035acc(data_ov003_021f78c4, data_ov003_021f78cd, 2);
}

}
