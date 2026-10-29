#include "ov000/VObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#include "ov000/HeapScope.h"

typedef void (*VoidFn)(void);

class Node021819a4 : public VObj {
public:
    u8 pad_04[0xd0];
    Node021819a4 *next;
};

typedef struct {
    u8 unk_00;
    VObj *unk_04;
    u16 unk_08;
    VObj *unk_0c;
    Node021819a4 *unk_10;
    s32 unk_14;
    u8 unk_18;
} Obj021819a4;

typedef struct {
    u8 unk_00;
    u8 *obj;
    VoidFn fn_08;
    VoidFn fn_0c;
    VoidFn fn_10;
} State021ccd50;

extern "C" {
extern State021ccd50 data_ov000_021ccd50;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd6c;
extern void *data_ov000_021ccd68;
extern void *data_0214a420;
extern void *data_ov000_021ccd70;
extern void *data_02149f0c;
extern u8 *data_02149ef0;
extern VObj *data_ov000_021ccd30;
extern u8 data_ov000_021cb9b0[];
extern u8 data_ov000_021cb980[];
void *func_0203dd9c(u32 size);
void func_0203fc1c(void);
void func_0206298c(void);
void *func_ov000_02188ba0(void *p);
void func_ov000_021b4eec(void);
void func_ov000_0218e0f0(void);
void *func_ov000_0218bb34(void *p);
void func_020654b8(void);
void func_ov000_021bc274(void);
void func_ov000_0216f360(void *p);
void func_ov000_02171464(void *p);
void func_02058d10(s32 a);
void func_02058f2c(void);
void func_0205983c(void);
void func_0204c158(void);
void func_0206f9dc(void);
void func_0206e9e8(void);
void func_0205b1b4(void);
void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_0203fc54(void);
void func_020598a8(void);
void func_02058fe4(void);
void func_02058e18(void);
void func_ov000_02180754(void);
void func_ov000_0214bc10(void);
void func_0204c214(void);
void func_ov000_021819a4(Obj021819a4 *self);
void func_0206fa70(void);
void func_0206ea7c(void);
void func_ov000_021bc2d8(void);
void func_ov000_021b4f28(void);
u16 func_ov000_0218e808(void *p, s32 a);
void func_0204b270(void *p, s32 a, s32 b);
void *func_ov000_0218bb58(void *p);
void func_ov000_0218e12c(void);
void func_02065534(void);
void *func_ov000_02189b14(void *p);
void func_02062a24(void);
s32 func_0203dbb0(void *p, s32 a);
void func_0205a358(void *p);
void func_ov000_02182590(void *p);
BOOL func_0205b4ac(void);
s32 func_ov000_021bc644(void *p);
s32 func_ov000_02189194(void *p);
void func_ov000_021b5110(void *p);
void func_ov000_0218c25c(void *p);
void func_ov000_0218be54(void *p);
void func_ov000_0218e338(void *p);
void func_02065ac0(void *p);
void func_0203cd10(void);
void func_ov000_021b53a8(void *p);
void func_ov000_0218e3d4(void *p);
void func_02065b84(void *p);
void func_ov000_021bc6c0(void *p);
void func_0205a69c(void *p);
}

#pragma force_active on
extern "C" {
void func_ov000_021814dc(void) {
    State021ccd50 *s = &data_ov000_021ccd50;
    s->unk_00 = 1;
    s->fn_0c = NULL;
    s->fn_08 = NULL;
    s->fn_10 = NULL;
    func_0203fc1c();
    func_0206298c();
    if (s->obj == NULL) {
        void *p = func_0203dd9c(0x214);
        if (p != NULL) {
            p = func_ov000_02188ba0(p);
        }
        data_ov000_021ccd50.obj = (u8 *)p;
    }
    func_ov000_021b4eec();
    func_ov000_0218e0f0();
    if (data_ov000_021ccd64 == NULL) {
        void *p = func_0203dd9c(0x48);
        if (p != NULL) {
            p = func_ov000_0218bb34(p);
        }
        data_ov000_021ccd64 = p;
    }
    func_020654b8();
    *(void **)data_0214a420 = data_ov000_021ccd50.obj + 8;
    func_ov000_021bc274();
    if (data_ov000_021ccd30 == NULL) {
        VObj *obj = (VObj *)func_0203dd9c(0x120);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_ov000_021cb9b0);
            func_ov000_0216f360(obj);
            VOBJ_SET_VTABLE(obj, data_ov000_021cb980);
            func_ov000_02171464(obj);
        }
        data_ov000_021ccd30 = obj;
    }
    func_02058d10(0);
    func_02058f2c();
    func_0205983c();
    func_0204c158();
    func_0206f9dc();
    func_0206e9e8();
    func_0205b1b4();
    func_0203c9e8(0x3f, -1);
    func_0203cc58(0, 1, -1);
}

void func_ov000_02181624(void) {
    register s32 m;
    void *saved;
    u8 *obj;
    VObj *v;
    s32 zero;
    zero = 0;
    if (data_ov000_021ccd50.unk_00 == 0) {
        return;
    }
    func_0203fc54();
    if (data_ov000_021ccd50.fn_0c != NULL) {
        data_ov000_021ccd50.fn_0c();
    }
    data_ov000_021ccd50.fn_0c = (VoidFn)zero;
    data_ov000_021ccd50.fn_08 = (VoidFn)zero;
    data_ov000_021ccd50.fn_10 = (VoidFn)zero;
    func_020598a8();
    func_02058fe4();
    func_02058e18();
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    v = data_ov000_021ccd30;
    if (v != NULL) {
        if (v != NULL) {
            v->vfunc_04();
        }
        data_ov000_021ccd30 = (VObj *)zero;
    }
    data_02097dd0->current = saved;
    func_ov000_02180754();
    func_ov000_0214bc10();
    func_0204c214();
    if (data_ov000_021ccd50.obj != NULL) {
        func_ov000_021819a4((Obj021819a4 *)(data_ov000_021ccd50.obj + 0xac));
    }
    func_0206fa70();
    func_0206ea7c();
    func_ov000_021bc2d8();
    func_ov000_021b4f28();
    {
        u8 **scene = &data_02149ef0;
        // Overlay id: a link-time symbol in the original, so it comes from the literal pool.
        asm { ldr m, =3 }
        if (m != LFLD(s32, *scene, 0x2c) && func_ov000_0218e808(data_ov000_021ccd68, 0xf000) != 0) {
            func_0204b270(*scene, m, 0);
        }
    }
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    obj = (u8 *)data_ov000_021ccd64;
    if (obj != NULL) {
        if (obj != NULL) {
            func_ov000_0218bb58(obj);
            func_0203de1c(obj);
        }
        data_ov000_021ccd64 = (void *)zero;
    }
    data_02097dd0->current = saved;
    func_ov000_0218e12c();
    func_02065534();
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    obj = data_ov000_021ccd50.obj;
    if (obj != NULL) {
        if (obj != NULL) {
            func_ov000_02189b14(obj + 0xf4);
            func_ov000_021819a4((Obj021819a4 *)(obj + 0xac));
            func_0203de1c(obj);
        }
        data_ov000_021ccd50.obj = (u8 *)zero;
    }
    data_02097dd0->current = saved;
    func_02062a24();
    data_ov000_021ccd50.unk_00 = zero;
}

void func_ov000_021817d4(void) {
    State021ccd50 *s = &data_ov000_021ccd50;
    s32 r;
    if (func_0203dbb0(s->obj + 8, 1) != 0) {
        return;
    }
    func_0205a358(data_02149f0c);
    func_ov000_02182590(s->obj + 0xac);
    func_0205b4ac();
    r = func_ov000_021bc644(data_ov000_021ccd70);
    if (func_ov000_02189194(s->obj) != 0 && r != 0) {
        s->obj[6] = 0;
        {
            VObj *v = (VObj *)(s->obj + 0xf4);
            if (v != NULL) {
                v->vfunc_00();
            }
        }
        if (data_ov000_021ccd6c != NULL) {
            func_ov000_021b5110(data_ov000_021ccd6c);
        }
        func_ov000_0218c25c(data_ov000_021ccd64);
        if (data_ov000_021ccd64 != NULL) {
            func_ov000_0218be54(data_ov000_021ccd64);
        }
        if (data_ov000_021ccd68 != NULL) {
            func_ov000_0218e338(data_ov000_021ccd68);
        }
        func_02065ac0(data_0214a420);
    } else {
        data_ov000_021ccd50.obj[6] = 1;
    }
    if (data_ov000_021ccd50.fn_08 != NULL) {
        data_ov000_021ccd50.fn_08();
    }
    data_ov000_021ccd30->vfunc_20();
    func_0203cd10();
}

void func_ov000_0218190c(void) {
    if (data_ov000_021ccd6c != NULL) {
        func_ov000_021b53a8(data_ov000_021ccd6c);
    }
    if (data_ov000_021ccd68 != NULL) {
        func_ov000_0218e3d4(data_ov000_021ccd68);
    }
    func_02065b84(data_0214a420);
    func_ov000_021bc6c0(data_ov000_021ccd70);
    func_0205a69c(data_02149f0c);
    if (data_ov000_021ccd50.fn_10 != NULL) {
        data_ov000_021ccd50.fn_10();
    }
    data_ov000_021ccd30->vfunc_24();
}

void func_ov000_021819a4(Obj021819a4 *self) {
    Node021819a4 *node;
    Node021819a4 *next;
    void *saved;
    node = self->unk_10;
    while (node != NULL) {
        next = node->next;
        saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk_08;
        if (node != NULL) {
            if (node != NULL) {
                node->vfunc_04();
            }
            node = NULL;
        }
        data_02097dd0->current = saved;
        node = next;
    }
    HEAP_DELETE_VOBJ(self->unk_0c);
    HEAP_DELETE_VOBJ(self->unk_04);
    self->unk_00 = 0;
    self->unk_04 = NULL;
    self->unk_08 = 0xffff;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = 0;
    self->unk_18 = 0;
}

}
#pragma force_active reset
