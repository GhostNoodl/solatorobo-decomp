#include "types.h"
#include "nitro/fx.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

class Mgr021b5dc0Cls;
typedef void (Mgr021b5dc0Cls::*Mgr021b5dc0Pmf)();

typedef struct {
    u8 pad_00[0x17];
    u8 unk_17;
    u8 unk_18;
    u8 unk_19;
} Rect021b5dc0;

typedef struct {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 rest : 5;
} Bits021b5dc0;

typedef struct {
    VecFx32 pos;
    u16 unk_0c;
    u16 unk_0e;
    u16 unk_10;
    u16 id;
    s16 h[4];
} Ent021b5dc0;

typedef struct {
    u16 id;
    u16 kind;
    s16 v[4];
    s16 m;
} Spawn021b5dc0;

typedef struct {
    u8 c[3];
} Rgb021b5dc0;

typedef struct Node021b5dc0 {
    u8 pad_00[4];
    struct Node021b5dc0 *next;
    u8 pad_08[0xee];
    u8 unk_f6;
} Node021b5dc0;

typedef struct {
    void *unk_00;
    u8 pad_04[0xc];
    void *unk_10;
    Rect021b5dc0 *unk_14;
    u8 pad_18[4];
    Node021b5dc0 *unk_1c;
    u8 pad_20[0x10];
    u16 unk_30[0x20];
    VecFx32 unk_70[0x20];
    u16 unk_1f0;
    s16 unk_1f2;
    u8 unk_1f4[0x98];
    Mgr021b5dc0Pmf unk_28c;
} Mgr021b5dc0;

extern "C" {

extern u8 *data_02097d48;
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern const Mgr021b5dc0Pmf data_ov000_021cc81c;
extern const Mgr021b5dc0Pmf data_ov000_021cc824;
extern char data_ov000_021cc82c[];
extern char data_ov000_021cc83d[];

void func_0206e660(void *p);
void func_0206e648(void *p);
void func_02043b20(void *p);
s32 func_0206e340(Rect021b5dc0 *r);
Ent021b5dc0 *func_0206e2ec(Rect021b5dc0 *r);
void *func_ov000_0218b9ec(Spawn021b5dc0 *s, u8 *a, u8 *b, s32 c, s32 d);
void func_ov000_0218b7c0(void *o, u16 kind, s32 mode);
u8 *func_ov000_0219bf90(void);
BOOL func_ov000_0218c040(void *mgr, s32 a, VecFx32 *out, s32 b, s32 c);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_02198d28(u8 *a, VecFx32 *v, u16 b);
void **func_02035edc(const char *a, const char *b);
void *NNS_G3dGetAnmByIdx(void *p, s32 idx);
void func_0204b8e8(u8 *cam, void *anm);
void func_ov000_021b7e60(Node021b5dc0 *n, s32 v);

static inline BOOL SameArea021b5dc0(void) {
    u8 *g = data_ov000_021ccd54;
    BOOL r = FALSE;
    if (g[0xca] == g[0xd0] && g[0xcb] == g[0xd1] && g[0xcc] == g[0xd2]) {
        r = TRUE;
    }
    return r;
}

static inline void SpawnInit021b5dc0(Spawn021b5dc0 *s, u16 id) {
    s32 k;
    s->id = id;
    s->kind = id & 0xf000;
    for (k = 0; k < 4; k++) {
        s->v[k] = 0;
    }
    s->m = -1;
}

static inline u16 Kind021b5dc0(u16 v) {
    return v >> 12;
}

void func_ov000_021b5dc0(Mgr021b5dc0 *self) {
    Spawn021b5dc0 s;
    VecFx32 base;
    VecFx32 out;
    u8 *cam;
    u8 *g;
    Ent021b5dc0 *ents;
    s32 i;
    s32 k;
    u16 id;
    u8 v;
    s32 mode;
    u8 *pl;
    u8 *a;
    Node021b5dc0 *n;

    if (self->unk_10 != NULL) {
        func_0206e660(self->unk_10);
    }
    if (self->unk_14 != NULL) {
        func_0206e648(self->unk_14);
    }
    func_02043b20(data_02097d48 + 0x8b0);
    v = self->unk_14->unk_18;
    cam = data_ov000_021ccd54 + 0xf4;
    LFLD(s32, cam, 0xc8) = func_0206e340(self->unk_14);
    LFLD(u16, cam, 0xd6) = v;
    g = data_ov000_021ccd54;
    ents = func_0206e2ec(self->unk_14);
    if (ents != NULL && (!SameArea021b5dc0() || data_ov000_021ccd54[0xc9] != 0)) {
        for (i = 0; i < self->unk_14->unk_17; i++) {
            void *o;
            u16 kind;
            id = ents[i].id;
            if (id == 0xffff) {
                if (g[0xca] != 0x12) {
                    continue;
                }
                id = 0x4f41;
            }
            SpawnInit021b5dc0(&s, id);
            for (k = 0; k < 4; k++) {
                s.v[k] = ents[i].h[k];
            }
            mode = 0;
            o = func_ov000_0218b9ec(&s, g + 0xca, g + 0xca, 0, 0);
            LFLD(VecFx32, o, 0x88) = ents[i].pos;
            LFLD(u16, o, 0x94) = ents[i].unk_0c;
            LFLD(u16, o, 0x96) = ents[i].unk_0e;
            LFLD(u16, o, 0x98) = ents[i].unk_10;
            kind = Kind021b5dc0(s.id);
            if (g[0xca] == 2 || g[0xca] == 0xd) {
                mode = 3;
            } else if (g[0xca] == 0xa || g[0xca] == 0xf || g[0xca] == 0xe || g[0xca] == 0x10 || id == 0x461a) {
                mode = 4;
            } else if (g[0xca] == 0x12) {
                mode = 5;
            }
            func_ov000_0218b7c0(o, kind, mode);
        }
    }
    if (self->unk_1f0 != 0xffff) {
        pl = func_ov000_0219bf90();
        if (func_ov000_0218c040(data_ov000_021ccd64, 1, &base, self->unk_1f0 >> 12, self->unk_1f0)) {
            for (i = 0; i < 0x20; i++) {
                id = self->unk_30[i];
                if (id == 0xffff) {
                    continue;
                }
                if (pl != NULL && id == LFLD(u16, pl, 0xc)) {
                    VEC_Add(&base, &self->unk_70[i], &out);
                    LFLD(VecFx32, pl, 0x75c) = out;
                    LFLD(Rgb021b5dc0, pl, 0x772) = LFLD(Rgb021b5dc0, data_ov000_021ccd54, 0xca);
                } else {
                    a = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
                    if (a != NULL) {
                        VEC_Add(&base, &self->unk_70[i], &out);
                        LFLD(VecFx32, a, 0x70) = out;
                        LFLD(s32, a, 0x9c) = 0;
                        LFLD(s32, a, 0xa0) = 0;
                        LFLD(s32, a, 0xa4) = 0;
                        LFLD(s32, a, 0xa8) = 0;
                        if (LFLD(void *, a, 0x48) != NULL) {
                            func_ov000_02198d28(LFLD(u8 *, a, 0x48), &out, LFLD(u16, a, 0x7e));
                        }
                    }
                }
                self->unk_30[i] = 0xffff;
            }
        }
        self->unk_1f0 = 0xffff;
    }
    self->unk_28c = NULL;
    self->unk_1f2 = 0;
    if (g[0xca] == 0x10 && g[0xcb] == 0 && (g[0xcc] == 0 || g[0xcc] == 3)) {
        void **res = func_02035edc(data_ov000_021cc82c, data_ov000_021cc83d);
        if (res != NULL && *res != NULL) {
            func_0204b8e8(cam, NNS_G3dGetAnmByIdx(*res, 0));
            self->unk_1f2 = 0x52;
            if (g[0xcc] == 3) {
                self->unk_1f2 = 0xa4;
            }
            LFLD(s16, cam, 0x9e) = self->unk_1f2;
            self->unk_28c = data_ov000_021cc81c;
        }
    }
    if (LFLD(Bits021b5dc0, self->unk_14, 0x19).b2) {
        self->unk_28c = data_ov000_021cc824;
    }
    if (g[0xca] != 0x12) {
        return;
    }
    for (n = self->unk_1c; n != NULL; n = n->next) {
        n->unk_f6 |= 8;
        func_ov000_021b7e60(n, 0x1ccd);
    }
}

}
