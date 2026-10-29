#include "ov000/LoCommon.h"
#include "nitro/std.h"

extern "C" {

extern void *data_02fe152c;
extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc158[];
extern char data_ov000_021cc121[];
extern char data_ov000_021cc111[];
extern char data_ov000_021cc130[];
void func_020592c4(void *res, u32 idx, int packed, int sub, u16 val);
void func_0205a6a0(void *p);
int func_0200779c(char *dst, const char *fmt, ...);
void func_0205a840(void *p, void *buf, const void *s);

void func_ov000_02181f54(u8 *self, u16 id, u16 a, u16 b, u16 c, u16 d) {
    char path[0x20];
    char name[0x20];
    VObj *obj;
    func_020592c4(data_02fe152c, 2, 1, id, 1);
    if (LFLD(VObj *, self, 0xc) != NULL) {
        if (LFLD(u16, LFLD(VObj *, self, 0xc), 0xc6) == id) {
            return;
        }
        LO_FREE_V(self, 0xc);
    }
    obj = (VObj *)func_0203dd9c(0xd8);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
        VOBJ_SET_VTABLE(obj, data_0208bf54);
        func_0205a6a0(obj);
        VOBJ_SET_VTABLE(obj, data_ov000_021cc158);
        LFLD(u16, obj, 0xc4) = 0;
        LFLD(u16, obj, 0xc6) = id;
        LFLD(u16, obj, 0xc8) = a;
        LFLD(u16, obj, 0xca) = b;
        LFLD(u16, obj, 0xcc) = c;
        LFLD(u16, obj, 0xce) = d;
        LFLD(s32, obj, 0xd0) = 0;
        LFLD(s32, obj, 0xd4) = 0;
    }
    LFLD(VObj *, self, 0xc) = obj;
    func_0200779c(name, data_ov000_021cc121, id);
    STD_CopyString(path, data_ov000_021cc111);
    STD_ConcatenateString(path, data_ov000_021cc130);
    func_0205a840(LFLD(VObj *, self, 0xc), path, name);
}

}
