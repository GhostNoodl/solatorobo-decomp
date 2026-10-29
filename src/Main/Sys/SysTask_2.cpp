#include "Main/Sys/SysTask.h"
#include "nitro/fx.h"

extern "C" {

void func_02063374(Unk0214a418 *self) {
    void *saved;
    void *p;
    SysTaskVObj *v;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    p = self->unk_14;
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        self->unk_14 = NULL;
    }
    data_02097dd0->cur = saved;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    v = self->unk_10;
    if (v != NULL) {
        if (v != NULL) {
            v->Delete();
        }
        self->unk_10 = NULL;
    }
    data_02097dd0->cur = saved;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    p = self->unk_0c;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0218fee4(p);
            func_0203de1c(p);
        }
        self->unk_0c = NULL;
    }
    data_02097dd0->cur = saved;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    p = self->unk_08;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0218ea20(p);
            func_0203de1c(p);
        }
        self->unk_08 = NULL;
    }
    data_02097dd0->cur = saved;
    self->unk_04 = 0;
}

}

typedef struct SysTaskRes {
    /* 0x00 */ s16 state;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 flags;
    /* 0x04 */ u8 unk_04[0xc];
    /* 0x10 */ char name0[0x20];
    /* 0x30 */ char path0[0x1c];
    /* 0x4c */ char name1[0x20];
    /* 0x6c */ char path1[0x20];
} SysTaskRes;

struct SysTaskLoader {
    virtual void vf00(void);
    virtual void Delete(void);
    virtual void Init(void);
    virtual void vf0c(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1c(void);
    virtual void vf20(void);
    virtual void Load(const char *name, const char *path);
    virtual void vf28(void);
    virtual BOOL IsDone(void);
    u8 unk_04[0x40];
    s32 unk_44;
};

extern "C" {

extern void func_0206e900(char *dst, const char *src);
extern char data_0208c1ac[];
extern char data_0208c1b5[];
extern char data_0208c1c1[];
extern u32 data_0208b318[];
extern void *func_ov000_0218e9c4(void *p);
extern BOOL func_ov000_0218f110(void *p);

BOOL func_02063484(Unk0214a418 *self) {
    char buf[0x20];
    BOOL cont;
    BOOL done;
    SysTaskRes *res;
    SysTaskRes *r;
    SysTaskLoader *ld;

    done = FALSE;
    func_0206e900(buf, data_0208c1ac);
    do {
        cont = FALSE;
        switch (self->unk_04) {
        case 0:
            self->unk_04 = 1;
            cont = TRUE;
            break;
        case 1:
            if (self->unk_08 == NULL) {
                res = (SysTaskRes *)func_0203dd9c(0x138);
                if (res != NULL) {
                    res = (SysTaskRes *)func_ov000_0218e9c4(res);
                }
                self->unk_08 = res;
                STD_CopyString(res->name0, buf);
                STD_CopyString(res->path0, data_0208c1b5);
                res->flags |= 2;
                r = (SysTaskRes *)self->unk_08;
                STD_CopyString(r->name1, buf);
                STD_CopyString(r->path1, data_0208c1b5);
                r->flags |= 4;
                cont = TRUE;
                ((SysTaskRes *)self->unk_08)->state = 0;
                self->unk_04 = 2;
            } else {
                self->unk_04 = 3;
                cont = TRUE;
            }
            break;
        case 2:
            if (((SysTaskRes *)self->unk_08)->state >= 0) {
                if (func_ov000_0218f110(self->unk_08)) {
                    self->unk_04 = 3;
                    cont = TRUE;
                }
            }
            break;
        case 3:
            if (self->unk_10 == NULL) {
                ld = (SysTaskLoader *)func_0203dd9c(0x4c);
                if (ld != NULL) {
                    *(u32 **)ld = data_0208b318;
                    ld->Init();
                }
                self->unk_10 = (SysTaskVObj *)ld;
                ld->unk_44 = 2;
                ((SysTaskLoader *)self->unk_10)->Load(buf, data_0208c1c1);
                self->unk_04 = 4;
                cont = TRUE;
            } else {
                self->unk_04 = 5;
                cont = TRUE;
            }
            break;
        case 4:
            if (((SysTaskLoader *)self->unk_10)->IsDone()) {
                self->unk_04 = 5;
                cont = TRUE;
            }
            break;
        case 5:
            done = TRUE;
            break;
        }
    } while (cont);
    return done;
}

}

extern "C" {

typedef struct SysG3dGlb {
    /* 0x00 */ u32 cmd0;
    /* 0x04 */ u32 mtxmode;
    /* 0x08 */ MtxFx44 projMtx;
    /* 0x48 */ u32 cmd1;
    /* 0x4c */ MtxFx43 cameraMtx;
    /* 0x7c */ u8 unk_7c[0x80];
    /* 0xfc */ u32 flag;
} SysG3dGlb;

typedef struct SysTaskModel {
    /* 0x00 */ u8 unk_00[0x78];
    /* 0x78 */ VecFx32 pos;
} SysTaskModel;

extern SysG3dGlb NNS_G3dGlb;
extern const VecFx32 data_02082b98;

extern void NNS_G3dGeFlushBuffer(void);
extern void MI_Copy64B(const void *src, void *dst);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void NNS_G3dGlbPolygonAttr(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);
extern void func_ov000_02190a80(void *a, s32 b);
extern BOOL func_ov000_021903b4(void *a);
extern BOOL func_ov000_02191120(void *a);

static inline void SysTask_SetProjectionMtx(const MtxFx44 *mtx) {
    MIi_CpuCopyFast(mtx, &NNS_G3dGlb.projMtx, sizeof(MtxFx44));
    NNS_G3dGlb.flag &= ~0x50;
}

static inline void SysTaskModel_SetPos(SysTaskModel *m, const VecFx32 *v) {
    m->pos.x = v->x;
    m->pos.y = v->y;
    m->pos.z = v->z;
}

BOOL func_02063650(Unk0214a418 *self) {
    MtxFx44 proj;
    MtxFx43 cam;
    MtxFx44 ortho;
    MtxFx43 *gc;
    NNS_G3dGeFlushBuffer();
    gc = &NNS_G3dGlb.cameraMtx;
    MI_Copy64B(&NNS_G3dGlb.projMtx, &proj);
    MI_Copy48B(gc, &cam);
    MTX_OrthoW(0xf5c, -0xf5c, -0x147b, 0x147b, 0, 0x20000, 0x400000, &ortho);
    SysTask_SetProjectionMtx(&ortho);
    MTX_Identity43_(gc);
    gc->m[3][2] = 0;
    NNS_G3dGlbPolygonAttr(0, 0, 3, 0, 0, 0);
    func_ov000_02190a80(self->unk_0c, 0x1000);
    {
        VecFx32 v = data_02082b98;
        SysTaskModel_SetPos((SysTaskModel *)self->unk_0c, &v);
    }
    func_ov000_021903b4(self->unk_0c);
    NNS_G3dGeFlushBuffer();
    SysTask_SetProjectionMtx(&proj);
    MI_Copy48B(&cam, gc);
    return func_ov000_02191120(self->unk_0c);
}

}
