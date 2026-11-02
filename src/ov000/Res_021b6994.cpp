#include "ov000/VObj.h"
#include "Main/Sys/FieldState.h"
#include "Main/Res/ResMgr.h"

#include "ov000/FieldMgr.h"

extern "C" {

u8 *func_0206e150(LangBlockA *p);
u8 *func_0206e180(LangBlockA *p);
void *func_02035d5c(void *e);
void *func_02039674(void *e);
void **func_02034f5c(void *m, void *k);
void **func_02034ec0(void *m, void *k);
void func_0203f0b4(void *p);
void func_02036838(void *a, void *e, s32 b, s32 c);
LangGroup *Lang_GetGroup(int id);
void func_0206dedc(void *buf, u8 *p);
void func_0206dde4(void *buf, u8 *p);
void func_02035acc(const char *name, void *buf, s32 b);

void func_ov000_021b6994(FieldMgr *self, u8 arg) {
    u8 *e;
    s32 i;
    u8 *p;
    LangGroup *t;
    u8 buf[0x20];
    if (self->blockA == NULL) {
        return;
    }
    e = func_0206e150(self->blockA);
    if (e != NULL) {
        for (i = 0; i < self->blockA->count0; i++, e += 0x18) {
            void *m = func_02035d5c(e);
            if (m != NULL) {
                void *k = func_02039674(e);
                void **r = func_02034f5c(m, k);
                if (r != NULL) {
                    func_0203f0b4(*r);
                } else {
                    r = func_02034ec0(m, k);
                    if (r != NULL) {
                        func_0203f0b4(*r);
                    }
                }
            }
            func_02036838(data_02097cdc, e, 7, 0);
        }
    }
    e = func_0206e180(self->blockA);
    if (e != NULL) {
        for (i = 0; i < self->blockA->count1; i++, e += 0x18) {
            func_02036838(data_02097cdc, e, 7, 0);
        }
    }
    p = data_ov000_021ccd54->unk_d0.c;
    if (arg || p[0] == 0xff || p[1] == 0xff || p[2] == 0xff) {
        p = data_ov000_021ccd54->unk_ca.c;
    }
    t = Lang_GetGroup(p[0]);
    func_0206dedc(buf, p);
    func_02035acc(t->unk_08, buf, 0);
    func_0206dde4(buf, p);
    func_02035acc(t->unk_08, buf, 0);
    self->blockA = NULL;
    self->unk_0c = NULL;
}

}
