#include "Main/Sys/SysTask.h"

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
                func_0201e520(res->name0, buf);
                func_0201e520(res->path0, data_0208c1b5);
                res->flags |= 2;
                r = (SysTaskRes *)self->unk_08;
                func_0201e520(r->name1, buf);
                func_0201e520(r->path1, data_0208c1b5);
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
