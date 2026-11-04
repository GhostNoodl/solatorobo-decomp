#include "Main/Sys/SysTask.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"

#define ST_FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))

extern "C" {

void Unk0214a418_Create(void) {
    Unk0214a418 *p;
    if (gUnk0214a418 != NULL) {
        return;
    }
    gSysState->cur = gSysState->heapLo;
    p = (Unk0214a418 *)Heap_Alloc(sizeof(Unk0214a418));
    if (p != NULL) {
        p->unk_00 = 0;
        p->unk_04 = 0;
        p->unk_08 = NULL;
        p->unk_0c = NULL;
        p->unk_10 = NULL;
        p->unk_14 = NULL;
    }
    gUnk0214a418 = p;
    gSysState->cur = gSysState->heapHi;
    gFadeFunc = Unk0214a418_FadeFunc;
    gFadeFuncArg = 0;
}

static inline void Unk0214a418_Dtor(Unk0214a418 *p) {
    Unk0214a418_Release(p);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = NULL;
    p->unk_0c = NULL;
    p->unk_10 = NULL;
    p->unk_14 = NULL;
}

void Unk0214a418_Delete(void) {
    void *saved = gSysState->cur;
    Unk0214a418 *p;
    gSysState->cur = gSysState->heapLo;
    p = gUnk0214a418;
    if (p != NULL) {
        if (p != NULL) {
            Unk0214a418_Dtor(p);
            Heap_Free(p);
        }
        gUnk0214a418 = NULL;
    }
    gSysState->cur = saved;
}

s32 Unk0214a418_FadeFunc(s32 arg) {
    if (gUnk0214a418 == NULL) {
        return 0;
    }
    return Unk0214a418_Run(gUnk0214a418, arg);
}


typedef struct SysTaskArg {
    s32 unk_00;
    s32 state;
    s32 timer;
    s32 limit;
} SysTaskArg;

struct SysTaskRes {
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0c(void);
    virtual void *vf10(void);
};

extern void *Gfx3D_PrimDLs[];
extern u32 Gfx3D_PrimDLSizes[];
extern char data_0208c1a0[];
extern char data_0208c1a4[];
extern char data_0208c1a8[];
extern BOOL Unk0214a418_LoadTitleWipe(Unk0214a418 *p);
extern BOOL Unk0214a418_Draw(Unk0214a418 *p);
extern void *Model0218fe1c_Init(void *p);
extern BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
extern BOOL Model0218fe1c_SetAnim(void *a, const char *b, s32 c, s32 d);
extern void Model0218fe1c_SetLoop(void *a);
extern void Model0218fe1c_ClearLoop(void *a);
extern void TexObj_ShrinkRes(void *a);
extern BOOL Model_IsReady(Model *a, u32 b);
extern void Gfx3D_SendDL(void *a, s32 b);
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *data, u32 count);
extern void NNS_G3dGeSendDL(const void *src, u32 size);

static inline void ST_DrawModel(Model *m) {
    ModelPart *part;
    ModelRes *res = m->res;
    void *arg;
    ModelPartRes *t;
    if (res == NULL) {
        return;
    }
    part = NULL;
    if (m->numParts > 0) {
        part = m->parts;
    }
    if (part != NULL && (t = part->res) != NULL) {
        arg = t->tex;
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0);
        arg = NNS_G2dGetCellDataByIdx(res->texRes, **(u16 **)ST_FLD(void *, e, 0xc));
    }
    TexObj_DrawCell(m, arg, part, 0);
}

static inline void ST_DrawBg(int idx, int x, int y, u32 color) {
    int scale[3];
    u32 c;
    scale[0] = x;
    scale[1] = y;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    c = color;
    NNS_G3dGeBufferOP_N(0x20, &c, 1);
    NNS_G3dGeSendDL(Gfx3D_PrimDLs[idx], Gfx3D_PrimDLSizes[idx]);
}

static inline void ST_Draw(Unk0214a418 *p, u32 size) {
    VecFx32 s;
    u32 tex;
    u32 poly;
    VecFx32 t;
    int scale[3];
    u32 c;
    u32 one;
    Gfx3D_SendDL(gGfxSys->unk_8b0, 0);
    s.x = 0x1000;
    s.y = 0x1000;
    s.z = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, &s, 3);
    tex = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &tex, 1);
    poly = 0x1f00d0;
    NNS_G3dGeBufferOP_N(0x29, &poly, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    t.z = -0x3d3;
    t.x = 0;
    t.y = 0;
    NNS_G3dGeBufferOP_N(0x1c, &t, 3);
    scale[0] = 0x100000;
    scale[1] = 0xc0000;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    c = 0;
    NNS_G3dGeBufferOP_N(0x20, &c, 1);
    NNS_G3dGeSendDL(Gfx3D_PrimDLs[1], size);
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    p->unk_14->unk_150 = -0x3b3;
    ST_DrawModel(p->unk_14);
}

static inline BOOL ST_IsReady(Unk0214a418 *p) {
    BOOL ok = TRUE;
    if (p->unk_0c == NULL) {
        ok = FALSE;
    }
    if (p->unk_14 == NULL) {
        ok = FALSE;
    }
    return ok;
}

static inline void ST_ModelCtor(Model *m, void *res, BOOL f) {
    PlttRes_Init_02041218(&m->pltt);
    TexObj_Init(m, (const char *)res + 4, f);
}
static inline Model *ST_NewModel(void *res, BOOL f) {
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        ST_ModelCtor(m, res, f);
    }
    return m;
}
static inline Model *ST_NewModel2(Unk0214a418 *p) {
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        ST_ModelCtor(m, p->unk_10, p->unk_14 != NULL);
    }
    return m;
}
s32 Unk0214a418_Run(Unk0214a418 *p, s32 argv) {
    SysTaskArg *arg = (SysTaskArg *)argv;
    u8 again;
    u32 size;
    if (!ST_IsReady(p)) {
        if (Unk0214a418_LoadTitleWipe(p)) {
            if (p->unk_0c == NULL) {
                void *o = Heap_Alloc(0xe8);
                if (o != NULL) {
                    o = Model0218fe1c_Init(o);
                }
                p->unk_0c = o;
                Model0218fe1c_SetRes(o, p->unk_08, 0, 1);
                ST_FLD(u16, p->unk_0c, 0xb4) = 0;
            }
            if (p->unk_14 == NULL) {
                void *res;
                Model *m = (Model *)Heap_Alloc(sizeof(Model));
                if (m != NULL) {
                    BOOL f;
                    res = p->unk_10;
                    f = p->unk_14 != NULL;
                    PlttRes_Init_02041218(&m->pltt);
                    TexObj_Init(m, (const char *)res + 4, f);
                }
                p->unk_14 = m;
                TexObj_SetRes(p->unk_14, ((SysTaskRes *)p->unk_10)->vf10());
                p->unk_14->flags |= 2;
                TexObj_SelectImage(p->unk_14, 0, 0xffff);
            }
        }
        return arg->state;
    }
    arg->timer += 0x1000;
    size = Gfx3D_PrimDLSizes[1];
    do {
        again = FALSE;
        switch (p->unk_00) {
        case 0:
            if (Model_IsReady(p->unk_14, 0xffff)) {
                TexObj_ShrinkRes(p->unk_14);
                Model0218fe1c_SetAnim(p->unk_0c, data_0208c1a0, 0, 1);
                Model0218fe1c_ClearLoop(p->unk_0c);
                p->unk_00 = 1;
                again = TRUE;
            }
            break;
        case 1:
            if (arg->state == 1) {
                ST_Draw(p, size);
            }
            if (Unk0214a418_Draw(p)) {
                Model0218fe1c_SetAnim(p->unk_0c, data_0208c1a4, 0, 1);
                Model0218fe1c_SetLoop(p->unk_0c);
                p->unk_00 = 2;
            }
            break;
        case 2:
            ST_Draw(p, size);
            Unk0214a418_Draw(p);
            Model0218fe1c_SetAnim(p->unk_0c, data_0208c1a8, 0, 1);
            Model0218fe1c_ClearLoop(p->unk_0c);
            p->unk_00 = 3;
            break;
        case 3:
            if (arg->state == 3) {
                ST_Draw(p, size);
            }
            if (Unk0214a418_Draw(p)) {
                if (arg->state == 3) {
                    p->unk_00 = 4;
                    if (arg->timer >= arg->limit) {
                        arg->state = 4;
                    }
                } else {
                    p->unk_00 = 5;
                    again = TRUE;
                }
            }
            break;
        case 4:
            ST_Draw(p, size);
            if (arg->state == 1) {
                p->unk_00 = 0;
            } else if (arg->timer >= arg->limit) {
                arg->state = 4;
            }
            break;
        case 5:
            Unk0214a418_Release(p);
            p->unk_00 = 0;
            arg->state = 0;
            break;
        }
    } while (again);
    return arg->state;
}

}
