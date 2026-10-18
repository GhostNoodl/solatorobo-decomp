#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern char data_ov000_021cc0f8[];
extern char data_ov000_021cc105[];
extern char data_ov000_021cc111[];
extern char data_ov000_021cc119[];
void func_0205a6a0(void *p);
BOOL func_0205a9c8(void *p);
void func_0205aa30(void *p);
void *func_0206e7d0(u8 id);
int func_0200779c(char *dst, const char *fmt, ...);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);

BOOL func_ov000_02181d70(u8 *self, u16 id) {
    char path[0x20];
    char name[0x20];
    VObj *obj;
    if (id == 0xffff) {
        if (LFLD(VObj *, self, 4) == NULL) {
            return TRUE;
        }
        if (LFLD(VObj *, self, 4)->vfunc_34()) {
            return TRUE;
        }
        if (func_0205a9c8(LFLD(VObj *, self, 4))) {
            func_0205aa30(LFLD(VObj *, self, 4));
            return TRUE;
        }
    } else {
        if (LFLD(u16, self, 8) == id) {
            return TRUE;
        }
        LO_FREE_V(self, 4);
        obj = (VObj *)func_0203dd9c(0xc4);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_0208b318);
            obj->vfunc_08();
            VOBJ_SET_VTABLE(obj, data_0208bf54);
            func_0205a6a0(obj);
        }
        LFLD(VObj *, self, 4) = obj;
        LFLD(u16, self, 8) = id;
        if (id == 0xfe) {
            STD_CopyString(name, data_ov000_021cc0f8);
        } else {
            func_0200779c(name, data_ov000_021cc105, LFLD(char *, func_0206e7d0(id), 4));
        }
        STD_CopyString(path, data_ov000_021cc111);
        STD_ConcatenateString(path, data_ov000_021cc119);
        func_0205a840(LFLD(VObj *, self, 4), path, name);
    }
    return FALSE;
}

}
