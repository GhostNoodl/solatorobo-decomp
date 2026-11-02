#include "ov008/ov008.h"
#include "nitro/std.h"

extern "C" {

extern const char *data_0208cca0;
extern const char *data_0208cc94;
extern void *data_0208b318;
extern void *data_0208bf54;
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
void *func_020359d0(const char *name, s32 type, u8 toFront);
void *func_ov000_0218e9c4(void *p);
void func_0206e900(char *dst, const char *src);
void func_0205a6a0(void *p);
void func_0205a840(void *p, const char *arc, const char *name);
void func_ov000_0214bb80(void);
void func_ov000_0214c1ac(void);

static inline Ov008Anim *Ov008_NewAnim(void) {
    Ov008Anim *p = (Ov008Anim *)Heap_Alloc(0x138);
    if (p != NULL) {
        p = (Ov008Anim *)func_ov000_0218e9c4(p);
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
        OV008_SET_VT(p, &data_0208b318);
        p->v08();
    }
    return p;
}

void func_ov008_021cdb00(Ov008Mgr *self) {
    char name[0x20];
    char path[0x20];
    Ov008Pic *p;
    Ov008PicC4 *q;
    func_020359d0(data_0208cca0, 7, 0);
    func_020359d0(data_0208cc94, 7, 0);

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

    func_0206e900(name, data_ov008_021d04b3);
    p = Ov008_NewLoader();
    self->unk_e4 = p;
    p->unk_44 = 2;
    self->unk_e4->v24(name, data_ov008_021d04c5);

    q = (Ov008PicC4 *)Heap_Alloc(0xc4);
    if (q != NULL) {
        OV008_SET_VT(q, &data_0208b318);
        q->v08();
        OV008_SET_VT(q, &data_0208bf54);
        func_0205a6a0(q);
    }
    self->unk_fc = q;
    STD_CopyString(path, data_ov008_021d04d1);
    STD_ConcatenateString(path, data_ov008_021d04d9);
    func_0205a840(self->unk_fc, path, data_ov008_021d04e1);
    func_ov000_0214bb80();
    func_ov000_0214c1ac();
}

}
