#include "ov011/ov011.h"

extern "C" {

extern char data_ov011_02207da4[];
extern char data_ov011_02207c35[];
struct Ov011PhotoCfg {
    void *photo;
    void *photoB;
    void *photoA;
    char photo1[8];
    char photo0[8];
};
extern Ov011PhotoCfg data_ov011_02207be0;
extern void *const data_ov011_02207500[2];
void *const data_ov011_02207500[2] = { data_ov011_02207be0.photo1, data_ov011_02207be0.photo0 };
Ov011PhotoCfg data_ov011_02207be0 = {
    data_ov011_02207500[0], data_ov011_02207500[1], data_ov011_02207500[0], "photo01", "photo00",
};
extern void *data_02097cdc;
void *func_ov000_0214b598(void *p);
void *func_ov000_0214b570(void *p);
void func_ov000_0214b5e8(void *p, void *t);
s32 func_ov000_0214b6d0(void *p);
BOOL func_ov000_0214b640(void *p);
void func_ov000_0214b5bc(void *p);
void *func_ov000_0218ea20(void *p);
void *func_ov003_021d0edc(void *self);
void func_ov003_021d0fc0(void *self);
void func_ov003_021d112c(void *self);
void *func_020359d0(const char *arc, s32 b, s32 c);
BOOL func_02035b90(const char *arc, s32 b);
void func_02036838(void *mgr, const char *arc, s32 c, s32 d);
BOOL func_02036328(void);
BOOL OS_IsRunOnTwl(void);
BOOL func_ov000_0218cf5c(void *self);
void func_0203f2b8(void *p);
void func_ov000_0218e8ec(void *mgr, u16 id, s32 c);

static inline void Ov011_FreeTwl(void **slot) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (*slot != NULL) {
        void *p = *slot;
        if (p != NULL) {
            func_ov000_0214b598(p);
            func_0203de1c(p);
        }
        *slot = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov011Actor *Ov011Act7da4_Dtor(Ov011Act7da4 *self) {
    *(void **)self = data_ov011_02207da4;
    Ov011_FreeTwl(&self->unk_364);
    Ov011_FreeTwl(&self->unk_368);
    func_02036838(data_02097cdc, data_ov011_02207c35, 7, 0);
    __cxa_vec_cleanup(self->unk_f4, 2, 0x138, (void *)func_ov000_0218ea20);
    func_ov003_021d0edc(self);
    return self;
}

Ov011Actor *Ov011Act7da4_DtorDelete(Ov011Act7da4 *self) {
    *(void **)self = data_ov011_02207da4;
    Ov011_FreeTwl(&self->unk_364);
    Ov011_FreeTwl(&self->unk_368);
    func_02036838(data_02097cdc, data_ov011_02207c35, 7, 0);
    __cxa_vec_cleanup(self->unk_f4, 2, 0x138, (void *)func_ov000_0218ea20);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void Ov011Act7da4_Init(Ov011Act7da4 *self) {
    func_ov003_021d0fc0(self);
    func_020359d0(data_ov011_02207c35, 7, 0);
    if (OS_IsRunOnTwl()) {
        void *p = func_0203dd9c(0x1c);
        if (p != NULL) {
            p = func_ov000_0214b570(p);
        }
        self->unk_364 = p;
        func_ov000_0214b5e8(p, data_ov011_02207500[1]);
        p = func_0203dd9c(0x1c);
        if (p != NULL) {
            p = func_ov000_0214b570(p);
        }
        self->unk_368 = p;
        func_ov000_0214b5e8(p, data_ov011_02207500[0]);
    }
    self->unk_398 = NULL;
    self->unk_394 = 0;
}

BOOL Ov011Act7da4_IsReady(Ov011Act7da4 *self) {
    BOOL r = func_ov000_0218cf5c(self);
    r = (r & func_02035b90(data_ov011_02207c35, 7)) ? TRUE : FALSE;
    if (self->unk_364 != NULL && self->unk_394 == 0) {
        if (func_ov000_0214b6d0(self->unk_364) == 2) {
            r = FALSE;
            self->unk_394 = 1;
        }
        if (r && !func_ov000_0214b640(self->unk_364) && r && func_02036328()) {
            func_ov000_0214b5bc(self->unk_364);
            r = FALSE;
        }
    }
    if (self->unk_368 != NULL && self->unk_394 == 0) {
        if (func_ov000_0214b6d0(self->unk_368) == 2) {
            r = FALSE;
            self->unk_394 = 1;
        }
        if (r && !func_ov000_0214b640(self->unk_368) && r && func_02036328()) {
            func_ov000_0214b5bc(self->unk_368);
            r = FALSE;
        }
    }
    return r;
}

void Ov011Act7da4_Start(Ov011Act7da4 *self) {
    func_ov003_021d112c(self);
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_48 != NULL) {
            void *p = self->unk_48;
            if (p != NULL) {
                func_0203f2b8(p);
                func_0203de1c(p);
            }
            self->unk_48 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    Ov011_VecSet(&self->unk_44->unk_0c, 0, 0x5000, 0x7800);
    {
        Ov011Sub44 *s = self->unk_44;
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
    self->unk_38->unk_c2_0 = 0;
    self->unk_ea_8 = 1;
    self->unk_ea_9 = 1;
    self->unk_ea_6 = 1;
    self->unk_36c = 0xffff;
    func_ov000_0218e8ec(data_ov000_021ccd68, 0x400c, 0x15);
}

}
