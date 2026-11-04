#include "ov008/ov008.h"
#include "nitro/std.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

extern "C" {
extern void *ResHandle_vtbl;
extern void *StageRes_vtbl;
extern char data_ov008_021d0462[];
extern char data_ov008_021d0470[];
extern char data_ov008_021d047c[];
extern char data_ov008_021d0487[];
extern char data_ov008_021d049b[];
extern char data_ov008_021d04a7[];
extern char data_ov008_021d04b3[];
extern char data_ov008_021d04c5[];
extern char data_ov008_021d04d1[];
extern char data_ov008_021d04d9[];
extern char data_ov008_021d04e1[];
void *ResSet_Init(void *p);
void LangData_LocalizePath(char *dst, const char *src);
void StageRes_Init(void *p);
void StageRes_Open(void *p, const char *arc, const char *name);
void SceneResSet_Open08(void);
void func_ov000_0214c1ac(void);

static inline Ov008Anim *Ov008_NewAnim(void) {
    Ov008Anim *p = (Ov008Anim *)Heap_Alloc(0x138);
    if (p != NULL) {
        p = (Ov008Anim *)ResSet_Init(p);
    }
    return p;
}

static inline void Ov008_AnimSetA(Ov008Anim *p, const char *a, const char *b) {
    STD_CopyString(p->mdlDir, a);
    STD_CopyString(p->mdlName, b);
    p->unk_03 |= 2;
}

static inline void Ov008_AnimSetB(Ov008Anim *p, const char *a, const char *b) {
    STD_CopyString(p->anmDir, a);
    STD_CopyString(p->anmName, b);
    p->unk_03 |= 4;
}

static inline Ov008Pic *Ov008_NewLoader(void) {
    Ov008Pic *p = (Ov008Pic *)Heap_Alloc(0x4c);
    if (p != NULL) {
        OV008_SET_VT(p, &ResHandle_vtbl);
        p->v08();
    }
    return p;
}

void Ov008WorldMap_LoadRes(Ov008Mgr *self) {
    char name[0x20];
    char path[0x20];
    Ov008Pic *p;
    Ov008PicC4 *q;
    ResMgr_Load(data_0208cca0, 7, 0);
    ResMgr_Load(data_0208cc94, 7, 0);

    self->unk_c4 = Ov008_NewAnim();
    {
        const char *file = data_ov008_021d0470;
        const char *nm = data_ov008_021d0462;
        if (nm) {
            Ov008_AnimSetA(self->unk_c4, nm, file);
            Ov008_AnimSetB(self->unk_c4, nm, file);
        }
    }
    self->unk_c4->unk_00 = 0;

    self->unk_cc = Ov008_NewAnim();
    {
        const char *file = data_ov008_021d047c;
        const char *nm = data_ov008_021d0487;
        if (nm) {
            Ov008_AnimSetA(self->unk_cc, nm, file);
        }
    }
    {
        const char *file = data_ov008_021d049b;
        const char *nm = data_ov008_021d0462;
        if (nm) {
            Ov008_AnimSetB(self->unk_cc, nm, file);
        }
    }
    self->unk_cc->unk_00 = 0;

    p = Ov008_NewLoader();
    self->unk_d4 = p;
    p->unk_44 = 2;
    self->unk_d4->v24(data_ov008_021d0462, data_ov008_021d04a7);

    p = Ov008_NewLoader();
    self->unk_dc = p;
    p->unk_44 = 2;
    self->unk_dc->v24(data_ov008_021d0462, data_ov008_021d04a7);

    LangData_LocalizePath(name, data_ov008_021d04b3);
    p = Ov008_NewLoader();
    self->unk_e4 = p;
    p->unk_44 = 2;
    self->unk_e4->v24(name, data_ov008_021d04c5);

    q = (Ov008PicC4 *)Heap_Alloc(0xc4);
    if (q != NULL) {
        OV008_SET_VT(q, &ResHandle_vtbl);
        q->v08();
        OV008_SET_VT(q, &StageRes_vtbl);
        StageRes_Init(q);
    }
    self->unk_fc = q;
    STD_CopyString(path, data_ov008_021d04d1);
    STD_ConcatenateString(path, data_ov008_021d04d9);
    StageRes_Open(self->unk_fc, path, data_ov008_021d04e1);
    SceneResSet_Open08();
    func_ov000_0214c1ac();
}

}
