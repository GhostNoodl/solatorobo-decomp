#include "ov008/ov008.h"

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
char *STD_CopyString(char *dst, const char *src);
char *STD_ConcatenateString(char *dst, const char *src);
void func_0206e900(char *dst, const char *src);
void func_0205a6a0(void *p);
void func_0205a840(void *p, const char *arc, const char *name);
void func_ov000_0214bb80(void);
void func_ov000_0214c1ac(void);

static inline void *Ov008_NewAnim(void) {
    void *p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    return p;
}

static inline void Ov008_AnimSetA(void *p, const char *a, const char *b) {
    STD_CopyString((char *)p + 0x10, a);
    STD_CopyString((char *)p + 0x30, b);
    FLD(u8, p, 3) |= 2;
}

static inline void Ov008_AnimSetB(void *p, const char *a, const char *b) {
    STD_CopyString((char *)p + 0x4c, a);
    STD_CopyString((char *)p + 0x6c, b);
    FLD(u8, p, 3) |= 4;
}

static inline Ov008V *Ov008_NewLoader(void) {
    Ov008V *p = (Ov008V *)func_0203dd9c(0x4c);
    if (p != NULL) {
        FLD(void *, p, 0) = &data_0208b318;
        p->v08();
    }
    return p;
}

void func_ov008_021cdb00(void *self) {
    char name[0x20];
    char path[0x20];
    Ov008V *p;
    func_020359d0(data_0208cca0, 7, 0);
    func_020359d0(data_0208cc94, 7, 0);

    FLD(void *, self, 0xc4) = Ov008_NewAnim();
    {
        const char *file = data_ov008_021d0470;
        const char *nm = data_ov008_021d0462;
        if (nm) {
            Ov008_AnimSetA(FLD(void *, self, 0xc4), nm, file);
            Ov008_AnimSetB(FLD(void *, self, 0xc4), nm, file);
        }
    }
    FLD(u16, FLD(void *, self, 0xc4), 0) = 0;

    FLD(void *, self, 0xcc) = Ov008_NewAnim();
    {
        const char *file = data_ov008_021d047c;
        const char *nm = data_ov008_021d0487;
        if (nm) {
            Ov008_AnimSetA(FLD(void *, self, 0xcc), nm, file);
        }
    }
    {
        const char *file = data_ov008_021d049b;
        const char *nm = data_ov008_021d0462;
        if (nm) {
            Ov008_AnimSetB(FLD(void *, self, 0xcc), nm, file);
        }
    }
    FLD(u16, FLD(void *, self, 0xcc), 0) = 0;

    p = Ov008_NewLoader();
    FLD(Ov008V *, self, 0xd4) = p;
    FLD(s32, p, 0x44) = 2;
    FLD(Ov008V *, self, 0xd4)->v24(data_ov008_021d0462, data_ov008_021d04a7);

    p = Ov008_NewLoader();
    FLD(Ov008V *, self, 0xdc) = p;
    FLD(s32, p, 0x44) = 2;
    FLD(Ov008V *, self, 0xdc)->v24(data_ov008_021d0462, data_ov008_021d04a7);

    func_0206e900(name, data_ov008_021d04b3);
    p = Ov008_NewLoader();
    FLD(Ov008V *, self, 0xe4) = p;
    FLD(s32, p, 0x44) = 2;
    FLD(Ov008V *, self, 0xe4)->v24(name, data_ov008_021d04c5);

    p = (Ov008V *)func_0203dd9c(0xc4);
    if (p != NULL) {
        FLD(void *, p, 0) = &data_0208b318;
        p->v08();
        FLD(void *, p, 0) = &data_0208bf54;
        func_0205a6a0(p);
    }
    FLD(Ov008V *, self, 0xfc) = p;
    STD_CopyString(path, data_ov008_021d04d1);
    STD_ConcatenateString(path, data_ov008_021d04d9);
    func_0205a840(FLD(void *, self, 0xfc), path, data_ov008_021d04e1);
    func_ov000_0214bb80();
    func_ov000_0214c1ac();
}

}
