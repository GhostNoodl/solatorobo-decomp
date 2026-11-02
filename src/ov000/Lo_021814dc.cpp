// ov000 scene-command translation unit: .text 0x021814dc..0x0218867c and its .bss
// (0x021ccd50..0x021ccd64). The former files are kept as they were, each in its own namespace,
// so that their local typedefs, inlines and extern declarations do not clash. The TU goes on to
// 0x021899d8 in the ROM (its functions still read these objects through the 0x021ccd50 pool),
// but func_ov000_0218867c is not matched, so the files after it stay separate.
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/HeapScope.h"
#include "ov000/LoCommon.h"
#include "nitro/std.h"
#include "ov000/CmdQueue.h"
#include "ov000/CmdObj.h"
#include "ov000/Vec.h"
#include "nitro/fx.h"
#include "types.h"

extern "C" {

typedef void (*VoidFn0)(void);

// The TU's .bss, reached through the 0x021ccd50 pool literal plus an offset (other TUs name
// 021ccd54 directly). The first function already uses the pool, so the objects are defined before
// it; objects defined there are not laid out in definition order, and this order gives the ROM's.
u8 data_ov000_021ccd50;          // a scene command is running
VoidFn0 data_ov000_021ccd58;     // per-frame callbacks of the running command (0x58, 0x5c, 0x60)
void *data_ov000_021ccd54;       // the scene command object
VoidFn0 data_ov000_021ccd5c;
VoidFn0 data_ov000_021ccd60;

}

// ---- Lo_021814dc
namespace m_Lo_021814dc {

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

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

extern "C" {
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
void *Heap_Alloc(u32 size);
void Hit_ResetLists(void);
void func_0206298c(void);
void *func_ov000_02188ba0(void *p);
void func_ov000_021b4eec(void);
void ActorMgr_Create(void);
void *func_ov000_0218bb34(void *p);
void EffectMgr_Create(void);
void func_ov000_021bc274(void);
void MessageQueue_Init(void *p);
void func_ov000_02171464(void *p);
void func_02058d10(s32 a);
void func_02058f2c(void);
void func_0205983c(void);
void MsgRes_Create(void);
void LangRes2_Create(void);
void LangData_CreateRes(void);
void func_0205b1b4(void);
void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_0203fc54(void);
void func_020598a8(void);
void func_02058fe4(void);
void func_02058e18(void);
void func_ov000_02180754(void);
void func_ov000_0214bc10(void);
void MsgRes_Delete(void);
void func_ov000_021819a4(Obj021819a4 *self);
void LangRes2_Delete(void);
void LangData_DeleteRes(void);
void func_ov000_021bc2d8(void);
void func_ov000_021b4f28(void);
u16 ActorMgr_CountActors(void *p, s32 a);
void func_0204b270(void *p, s32 a, s32 b);
void *Group_Clear(void *p);
void ActorMgr_Destroy(void);
void EffectMgr_Delete(void);
void *func_ov000_02189b14(void *p);
void func_02062a24(void);
s32 PauseNode_IsUpdatePaused(void *p, s32 a);
void func_0205a358(void *p);
void func_ov000_02182590(void *p);
BOOL func_0205b4ac(void);
s32 func_ov000_021bc644(void *p);
s32 func_ov000_02189194(void *p);
void func_ov000_021b5110(void *p);
void func_ov000_0218c25c(void *p);
void func_ov000_0218be54(void *p);
void ActorMgr_Update(void *p);
void func_02065ac0(void *p);
void func_0203cd10(void);
void func_ov000_021b53a8(void *p);
void ActorMgr_Draw(void *p);
void func_02065b84(void *p);
void func_ov000_021bc6c0(void *p);
void func_0205a69c(void *p);
}

#pragma force_active on
extern "C" {
void func_ov000_021814dc(void) {
    
    data_ov000_021ccd50 = 1;
    data_ov000_021ccd5c = NULL;
    data_ov000_021ccd58 = NULL;
    data_ov000_021ccd60 = NULL;
    Hit_ResetLists();
    func_0206298c();
    if (data_ov000_021ccd54 == NULL) {
        void *p = Heap_Alloc(0x214);
        if (p != NULL) {
            p = func_ov000_02188ba0(p);
        }
        data_ov000_021ccd54 = (u8 *)p;
    }
    func_ov000_021b4eec();
    ActorMgr_Create();
    if (data_ov000_021ccd64 == NULL) {
        void *p = Heap_Alloc(0x48);
        if (p != NULL) {
            p = func_ov000_0218bb34(p);
        }
        data_ov000_021ccd64 = p;
    }
    EffectMgr_Create();
    *(void **)data_0214a420 = ((u8 *)data_ov000_021ccd54) + 8;
    func_ov000_021bc274();
    if (data_ov000_021ccd30 == NULL) {
        VObj *obj = (VObj *)Heap_Alloc(0x120);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_ov000_021cb9b0);
            MessageQueue_Init(obj);
            VOBJ_SET_VTABLE(obj, data_ov000_021cb980);
            func_ov000_02171464(obj);
        }
        data_ov000_021ccd30 = obj;
    }
    func_02058d10(0);
    func_02058f2c();
    func_0205983c();
    MsgRes_Create();
    LangRes2_Create();
    LangData_CreateRes();
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
    if (data_ov000_021ccd50 == 0) {
        return;
    }
    func_0203fc54();
    if (data_ov000_021ccd5c != NULL) {
        data_ov000_021ccd5c();
    }
    data_ov000_021ccd5c = (VoidFn)zero;
    data_ov000_021ccd58 = (VoidFn)zero;
    data_ov000_021ccd60 = (VoidFn)zero;
    func_020598a8();
    func_02058fe4();
    func_02058e18();
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    v = data_ov000_021ccd30;
    if (v != NULL) {
        if (v != NULL) {
            v->vfunc_04();
        }
        data_ov000_021ccd30 = (VObj *)zero;
    }
    data_02097dd0->cur = saved;
    func_ov000_02180754();
    func_ov000_0214bc10();
    MsgRes_Delete();
    if (data_ov000_021ccd54 != NULL) {
        func_ov000_021819a4((Obj021819a4 *)(((u8 *)data_ov000_021ccd54) + 0xac));
    }
    LangRes2_Delete();
    LangData_DeleteRes();
    func_ov000_021bc2d8();
    func_ov000_021b4f28();
    {
        u8 **scene = &data_02149ef0;
        // Overlay id: a link-time symbol in the original, so it comes from the literal pool.
        asm { ldr m, =3 }
        if (m != LFLD(s32, *scene, 0x2c) && ActorMgr_CountActors(data_ov000_021ccd68, 0xf000) != 0) {
            func_0204b270(*scene, m, 0);
        }
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    obj = (u8 *)data_ov000_021ccd64;
    if (obj != NULL) {
        if (obj != NULL) {
            Group_Clear(obj);
            Heap_Free(obj);
        }
        data_ov000_021ccd64 = (void *)zero;
    }
    data_02097dd0->cur = saved;
    ActorMgr_Destroy();
    EffectMgr_Delete();
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    obj = (u8 *)data_ov000_021ccd54;
    if (obj != NULL) {
        if (obj != NULL) {
            func_ov000_02189b14(obj + 0xf4);
            func_ov000_021819a4((Obj021819a4 *)(obj + 0xac));
            Heap_Free(obj);
        }
        data_ov000_021ccd54 = (u8 *)zero;
    }
    data_02097dd0->cur = saved;
    func_02062a24();
    data_ov000_021ccd50 = zero;
}

void func_ov000_021817d4(void) {
    
    s32 r;
    if (PauseNode_IsUpdatePaused(((u8 *)data_ov000_021ccd54) + 8, 1) != 0) {
        return;
    }
    func_0205a358(data_02149f0c);
    func_ov000_02182590(((u8 *)data_ov000_021ccd54) + 0xac);
    func_0205b4ac();
    r = func_ov000_021bc644(data_ov000_021ccd70);
    if (func_ov000_02189194(((u8 *)data_ov000_021ccd54)) != 0 && r != 0) {
        ((u8 *)data_ov000_021ccd54)[6] = 0;
        {
            VObj *v = (VObj *)(((u8 *)data_ov000_021ccd54) + 0xf4);
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
            ActorMgr_Update(data_ov000_021ccd68);
        }
        func_02065ac0(data_0214a420);
    } else {
        ((u8 *)data_ov000_021ccd54)[6] = 1;
    }
    if (data_ov000_021ccd58 != NULL) {
        data_ov000_021ccd58();
    }
    data_ov000_021ccd30->vfunc_20();
    func_0203cd10();
}

void func_ov000_0218190c(void) {
    if (data_ov000_021ccd6c != NULL) {
        func_ov000_021b53a8(data_ov000_021ccd6c);
    }
    if (data_ov000_021ccd68 != NULL) {
        ActorMgr_Draw(data_ov000_021ccd68);
    }
    func_02065b84(data_0214a420);
    func_ov000_021bc6c0(data_ov000_021ccd70);
    func_0205a69c(data_02149f0c);
    if (data_ov000_021ccd60 != NULL) {
        data_ov000_021ccd60();
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
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (node != NULL) {
            if (node != NULL) {
                node->vfunc_04();
            }
            node = NULL;
        }
        data_02097dd0->cur = saved;
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

}  // namespace m_Lo_021814dc

// ---- Dtor_02181ab0
namespace m_Dtor_02181ab0 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
void Heap_Free(void *ptr);
void func_0205a6e8(void *ptr);

VObj *Ov000Vt_021cc158_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_0208bf54);
    func_0205a6e8(self);
    VOBJ_SET_VTABLE(self, data_0208b318);
    self->vfunc_0c();
    Heap_Free(self);
    return self;
}

}

}  // namespace m_Dtor_02181ab0

// ---- Ser_02181af4
namespace m_Ser_02181af4 {

extern "C" {
void MI_CpuFill8(void *dst, u8 val, u32 size);

static inline void Put2(u8 *buf, s32 i, u8 *src) {
    u8 *d = &buf[i];
    d[0] = src[0];
    d[1] = src[1];
}

struct Ser02181af4 {
    u8 unk_00[0xc];
    u8 *unk_0c;
    u8 *unk_10;
};

s32 func_ov000_02181af4(Ser02181af4 *self, u8 *buf, u32 size) {
    s32 off = 0;
    u16 n;
    u8 *p;
    MI_CpuFill8(buf, off, size);
    buf[0] = self->unk_0c != NULL ? 1 : 0;
    n = 0;
    for (p = self->unk_10; p != NULL; p = LFLD(u8 *, p, 0xd4)) {
        n++;
    }
    buf[1] = n;
    if (self->unk_0c == NULL) {
        off += 10;
    } else {
        off += 10;
        buf[2] = LFLD(u8, self->unk_0c, 0xc6);
        buf[3] = LFLD(u8, self->unk_0c, 0xc7);
        buf[4] = LFLD(u16, self->unk_0c, 0xc8);
        buf[5] = LFLD(u16, self->unk_0c, 0xca);
        buf[6] = LFLD(u8, self->unk_0c, 0xcc);
        buf[7] = LFLD(u8, self->unk_0c, 0xcd);
        buf[8] = LFLD(u8, self->unk_0c, 0xce);
        buf[9] = LFLD(u8, self->unk_0c, 0xcf);
    }
    p = self->unk_10;
    if (p == NULL) {
        off += 10;
    } else {
        Put2(buf, off, p + 0xc6);
        Put2(buf, off + 2, p + 0xc4);
        (buf + off)[4] = LFLD(u16, p, 0xc8);
        (buf + off)[5] = LFLD(u16, p, 0xca);
        Put2(buf, off + 6, p + 0xcc);
        Put2(buf, off + 8, p + 0xce);
        off += 10;
    }
    return (off + 1) & ~1;
}
}

}  // namespace m_Ser_02181af4

// ---- Ser_02181c4c
namespace m_Ser_02181c4c {

extern "C" {
void func_ov000_02181f54(u8 *self, u16 id, u16 a, u16 b, u16 c, u16 d);
void func_ov000_02182190(u8 *self, u16 id, u16 a, u16 b, u16 c, u16 d, u16 e);

static inline void Get2(u8 *buf, s32 i, u8 *dst) {
    u8 *s = &buf[i];
    dst[0] = s[0];
    dst[1] = s[1];
}

static inline void Get2r(u8 *buf, s32 i, u8 *dst) {
    u8 *s = &buf[i];
    dst[1] = s[1];
    dst[0] = s[0];
}

static inline void Get2b(const u8 *s, u8 *dst) {
    dst[0] = s[0];
    dst[1] = s[1];
}
static inline void Get2v(const u8 *s, u8 *dst) {
    u8 a = s[0];
    u8 b = s[1];
    dst[1] = b;
    dst[0] = a;
}

s32 func_ov000_02181c4c(u8 *self, u8 *buf) {
    u16 id;
    u16 sub;
    u16 d;
    u16 c;
    s32 off = 0;
    u32 zero;
    u8 n = buf[1];
    zero = 0;
    if (buf[0] != zero) {
        u16 a_0;
        u16 b_0;
        Get2b(buf + 2, (u8 *)&id);
        a_0 = buf[4];
        b_0 = buf[5];
        Get2v(buf + 6, (u8 *)&c);
        off += 10;
        Get2v(buf + 8, (u8 *)&d);
        func_ov000_02181f54(self, id, a_0, b_0, c, d);
    } else {
        off += 10;
    }
    if (n > zero) {
        u16 a_1;
        u16 b_1;
        Get2(buf, off, (u8 *)&id);
        Get2(buf, off + 2, (u8 *)&sub);
        a_1 = (buf + off)[4];
        b_1 = (buf + off)[5];
        Get2(buf, off + 6, (u8 *)&c);
        Get2(buf, off + 8, (u8 *)&d);
        off += 10;
        func_ov000_02182190(self, id, sub, a_1, b_1, c, d);
    } else {
        off += 10;
    }
    return (off + 1) & ~1;
}
}

}  // namespace m_Ser_02181c4c

// ---- Lo_02181d70
namespace m_Lo_02181d70 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern char data_ov000_021cc0f8[];
extern char data_ov000_021cc105[];
extern char data_ov000_021cc111[];
extern char data_ov000_021cc119[];
void func_0205a6a0(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
void *Lang_GetGroup(u8 id);
int func_0200779c(char *dst, const char *fmt, ...);
void func_0205a840(void *p, void *buf, const void *s);

struct Lo02181d70 {
    u8 unk_00[0x4];
    VObj *unk_04;
    u16 unk_08;
};

BOOL func_ov000_02181d70(Lo02181d70 *self, u16 id) {
    char path[0x20];
    char name[0x20];
    VObj *obj;
    if (id == 0xffff) {
        if (self->unk_04 == NULL) {
            return TRUE;
        }
        if (self->unk_04->vfunc_34()) {
            return TRUE;
        }
        if (StageRes_IsAllLoaded(self->unk_04)) {
            func_0205aa30(self->unk_04);
            return TRUE;
        }
    } else {
        if (self->unk_08 == id) {
            return TRUE;
        }
        LO_FREE_V(self, 4);
        obj = (VObj *)Heap_Alloc(0xc4);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_0208b318);
            obj->vfunc_08();
            VOBJ_SET_VTABLE(obj, data_0208bf54);
            func_0205a6a0(obj);
        }
        self->unk_04 = obj;
        self->unk_08 = id;
        if (id == 0xfe) {
            STD_CopyString(name, data_ov000_021cc0f8);
        } else {
            func_0200779c(name, data_ov000_021cc105, LFLD(char *, Lang_GetGroup(id), 4));
        }
        STD_CopyString(path, data_ov000_021cc111);
        STD_ConcatenateString(path, data_ov000_021cc119);
        func_0205a840(self->unk_04, path, name);
    }
    return FALSE;
}

}

}  // namespace m_Lo_02181d70

// ---- Stub_02181efc
namespace m_Stub_02181efc {

typedef struct {
    u8 unk_00[0x8];
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
} Data02fe1534;

typedef struct {
    u8 unk_00[0xc8];
    u16 unk_c8;
    u16 unk_ca;
    u16 unk_cc;
    u16 unk_ce;
} Obj02181efc;

extern "C" {

extern Data02fe1534 data_02fe1534;
s32 func_0205aa98(Obj02181efc *self, s32 a);

s32 func_ov000_02181efc(Obj02181efc *self, s32 a) {
    s32 r;
    Data02fe1534 *d = &data_02fe1534;
    d->unk_08 = self->unk_c8;
    d->unk_0a = self->unk_ca;
    d->unk_0c = self->unk_cc;
    d->unk_0e = self->unk_ce;
    r = func_0205aa98(self, a);
    self->unk_c8 = d->unk_08;
    self->unk_ca = d->unk_0a;
    self->unk_cc = d->unk_0c;
    self->unk_ce = d->unk_0e;
    return r;
}

}

}  // namespace m_Stub_02181efc

// ---- Lo_02181f54
namespace m_Lo_02181f54 {

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
    obj = (VObj *)Heap_Alloc(0xd8);
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

}  // namespace m_Lo_02181f54

// ---- Widget_021820bc
namespace m_Widget_021820bc {

class Widget021820bc : public VObj {
public:
    u8 pad_04[0xc4];
    u16 unk_c8;
    u8 pad_ca[0xa];
    Widget021820bc *unk_d4;
};

typedef struct {
    u8 pad_00[0xc];
    Widget021820bc *unk_0c;
    Widget021820bc *unk_10;
} Panel021820bc;

typedef struct {
    u8 pad_00[0x44];
    u16 unk_44;
} Dtcm02fe1534;

extern "C" {

extern Dtcm02fe1534 data_02fe1534;
BOOL StageRes_IsAllLoaded(Widget021820bc *w);
BOOL func_0205aa30(Widget021820bc *w);

BOOL func_ov000_021820bc(Panel021820bc *self, BOOL notify) {
    Widget021820bc *w = self->unk_10;
    BOOL changed;
    u16 saved;

    if (w == NULL) {
        return TRUE;
    }
    saved = data_02fe1534.unk_44;
    changed = FALSE;
    data_02fe1534.unk_44 = 1;
    while (w != NULL) {
        if (!w->vfunc_34() && StageRes_IsAllLoaded(w)) {
            func_0205aa30(w);
            if (notify && w->unk_c8 == 0) {
                w->vfunc_38(1);
            }
            changed = TRUE;
        }
        w = w->unk_d4;
    }
    if (changed && self->unk_0c != NULL) {
        self->unk_0c->vfunc_38(1);
    }
    data_02fe1534.unk_44 = saved;
    return changed;
}

}

}  // namespace m_Widget_021820bc

// ---- Widget_02182190
namespace m_Widget_02182190 {

typedef void (*VFunc02182190)(void);

class Widget02182190 : public VObj {
public:
    u8 pad_04[0xc0];
    u16 order;
    u16 id;
    u16 unk_c8;
    u16 unk_ca;
    u16 unk_cc;
    u16 unk_ce;
    Widget02182190 *prev;
    Widget02182190 *next;
};

typedef struct {
    u8 pad_00[0x10];
    Widget02182190 *head;
} Panel02182190;

extern "C" {

extern void *data_02fe152c;
extern VFunc02182190 data_0208b318[];
extern VFunc02182190 data_0208bf54[];
extern VFunc02182190 data_ov000_021cc158[];
extern char data_ov000_021cc138[];
extern char data_ov000_021cc111[];
extern char data_ov000_021cc147[];
void func_020592c4(void *res, s32 a, s32 b, s32 id, s32 e);
void *Heap_Alloc(u32 size);
void func_0205a6a0(Widget02182190 *w);
void func_0205a840(Widget02182190 *w, char *path, char *name);
int func_0200779c(char *dst, const char *fmt, ...);

void func_ov000_02182190(Panel02182190 *self, u16 id, u16 order, u16 c, u16 d, u16 e, u16 f) {
    char path[0x20];
    char name[0x20];
    Widget02182190 *w;
    Widget02182190 *cur;
    Widget02182190 *prev;
    u16 count;

    func_020592c4(data_02fe152c, 1, 1, id, 0);
    func_020592c4(data_02fe152c, 1, 0x201, id, 1);
    for (w = self->head; w != NULL; w = w->next) {
        if (w->id == id) {
            return;
        }
    }
    count = 0;
    for (w = self->head; w != NULL; w = w->next) {
        count++;
    }
    if (count >= 1) {
        return;
    }
    w = (Widget02182190 *)Heap_Alloc(0xd8);
    if (w != NULL) {
        *(VFunc02182190 **)w = data_0208b318;
        w->vfunc_08();
        *(VFunc02182190 **)w = data_0208bf54;
        func_0205a6a0(w);
        *(VFunc02182190 **)w = data_ov000_021cc158;
        w->order = order;
        w->id = id;
        w->unk_c8 = c;
        w->unk_ca = d;
        w->unk_cc = e;
        w->unk_ce = f;
        w->prev = NULL;
        w->next = NULL;
    }
    cur = self->head;
    if (cur == NULL) {
        self->head = w;
    } else {
        for (; cur != NULL; cur = cur->next) {
            if (w->order >= cur->order) {
                break;
            }
            prev = cur;
        }
        if (cur != NULL) {
            w->prev = cur->prev;
            w->next = cur;
            cur->prev = w;
            if (w->prev == NULL) {
                self->head = w;
            }
        } else {
            w->prev = prev;
            prev->next = w;
        }
    }
    func_0200779c(name, data_ov000_021cc138, id);
    STD_CopyString(path, data_ov000_021cc111);
    STD_ConcatenateString(path, data_ov000_021cc147);
    func_0205a840(w, path, name);
}

}

}  // namespace m_Widget_02182190

// ---- Heap_02182374
namespace m_Heap_02182374 {

class Node02182374 : public VObj {
public:
    u8 pad_04[0xc2];
    u16 id;
    u8 pad_c8[8];
    Node02182374 *prev;
    Node02182374 *next;
};

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ctrl02182374;

typedef struct {
    u8 pad_00[0x10];
    Node02182374 *head;
} Obj02182374;

extern "C" {

extern void *data_02fe152c;
u32 func_ov000_0214bf2c(u32 id);
void func_020592c4(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02182590(u8 *p);

void func_ov000_02182374(Obj02182374 *self, u32 id, BOOL force) {
    u32 flags = func_ov000_0214bf2c(id);
    BOOL b = TRUE;
    Node02182374 *node;
    if (force) {
        b = FALSE;
        func_020592c4(data_02fe152c, 1, 1, id, 1);
        func_020592c4(data_02fe152c, 1, 0x201, id, 0);
    } else if (flags & 0x20) {
        func_020592c4(data_02fe152c, 1, 1, id, 1);
    }
    if (b) {
        func_020592c4(data_02fe152c, 1, 0x301, id, 1);
    }
    for (node = self->head; node != NULL; node = node->next) {
        if (node->id == id) {
            break;
        }
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        self->head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (node != NULL) {
            if (node != NULL) {
                node->vfunc_04();
            }
            node = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        Ctrl02182374 *c = (Ctrl02182374 *)data_ov000_021ccd54;
        c->unk_ac = 1;
        func_ov000_02182590(&c->unk_ac);
    }
}

}

}  // namespace m_Heap_02182374

// ---- Stub_021824d0
namespace m_Stub_021824d0 {

class Node021824d0 : public VObj {
public:
    u8 unk_04[0xd0];
    Node021824d0 *next;
};

extern "C" {

Node021824d0 *func_ov000_021824d0(void *self, u16 index) {
    Node021824d0 *n = *(Node021824d0 **)((u8 *)self + 0x10);
    u16 i = 0;
    while (n != NULL) {
        if (index == i) {
            break;
        }
        if (n->vfunc_34()) {
            i++;
        }
        n = n->next;
    }
    return n;
}

}

}  // namespace m_Stub_021824d0

// ---- Lo_02182524
namespace m_Lo_02182524 {

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

class VObjB {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void vfunc_38(s32 a);
};

typedef struct {
    u8 pad_00[0x14];
    VObj *unk_14;
    u8 unk_18;
} Obj02182524;

static inline BOOL IsActive(VObj *p) {
    return LFLD(u8, p, 0x5a) != 0 ? TRUE : FALSE;
}

extern "C" {
void func_0206228c(void);

void func_ov000_02182524(Obj02182524 *self) {
    if (self->unk_14 == NULL) {
        return;
    }
    if (self->unk_18 != 0) {
        self->unk_14->vfunc_38(1);
    } else {
        ((VObjB *)self->unk_14)->vfunc_38(1);
    }
    if (!IsActive(self->unk_14)) {
        self->unk_14 = NULL;
        self->unk_18 = 0;
    }
    if (self->unk_14 == NULL) {
        func_0206228c();
    }
}
}

}  // namespace m_Lo_02182524

// ---- Widget_02182590
namespace m_Widget_02182590 {

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 unk_00;
    u8 pad_01[3];
    VObj *unk_04;
    u8 pad_08[4];
    VObj *unk_0c;
    VObj *unk_10;
    VObj *unk_14;
    u8 unk_18;
} Obj02182590;

static inline BOOL IsActive(VObj *p) {
    return LFLD(u8, p, 0x5a) != 0 ? TRUE : FALSE;
}

extern "C" {
extern void *data_02149efc;
extern u8 data_02fe1534[];
BOOL func_0205b23c(s32 id);
void func_0206228c(void);

static inline BOOL CmdQueue_Has2(CmdQueue *q, s32 i, s32 end, s32 kind) {
    for (; i != end;) {
        if (q->kinds[i] == kind) {
            return TRUE;
        }
        if (++i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline BOOL IsBusy(void) {
    return data_02149efc != NULL ? TRUE : FALSE;
}

static inline CmdQueue *GetQueue02182590(void) {
    return ((CmdQueue *)data_ov000_021ccd54);
}

void func_ov000_02182590(Obj02182590 *self) {
    VObj *w;
    CmdQueue *q;
    s32 rd;
    s32 wr;
    data_02149efc = NULL;
    if (self->unk_00 == 0) {
        return;
    }
    // The getter, the reused wr and the const-view reload below give the target's registers
    // and its second load of the queue pointer.
    q = GetQueue02182590();
    wr = q->unk_90;
    rd = wr;
    wr = q->index;
    if (CmdQueue_Has2(q, rd, wr, 6)) {
        return;
    }
    if (CmdQueue_Has2(*(CmdQueue *const *)&data_ov000_021ccd54, rd, wr, 7)) {
        return;
    }
    self->unk_00 = 0;
    if (self->unk_14 != NULL) {
        return;
    }
    if (func_0205b23c(0x21b)) {
        return;
    }
    w = self->unk_10;
    if (LFLD(u16, data_02fe1534, 0x44) == 1) {
        if (self->unk_04 != NULL) {
            self->unk_04->vfunc_38(1);
            data_02149efc = NULL;
        }
        if (self->unk_0c != NULL) {
            self->unk_0c->vfunc_38(1);
            data_02149efc = NULL;
            if (IsActive(self->unk_0c)) {
                self->unk_14 = self->unk_0c;
                self->unk_18 = 1;
            }
        }
        for (; w != NULL; w = LFLD(VObj *, w, 0xd4)) {
            w->vfunc_38(1);
            if (IsActive(w)) {
                self->unk_18 = 1;
                self->unk_14 = w;
            }
        }
    } else {
        for (; w != NULL; w = LFLD(VObj *, w, 0xd4)) {
            w->vfunc_38(1);
            if (IsActive(w)) {
                self->unk_14 = w;
                self->unk_18 = 1;
            }
            if (IsBusy()) {
                break;
            }
        }
        if (self->unk_0c != NULL && w == NULL) {
            self->unk_0c->vfunc_38(1);
            if (IsActive(self->unk_0c)) {
                self->unk_14 = self->unk_0c;
                self->unk_18 = 1;
            }
        }
        if (self->unk_04 != NULL && !IsBusy()) {
            self->unk_04->vfunc_38(1);
            if (IsActive(self->unk_04)) {
                self->unk_14 = self->unk_04;
            }
        }
    }
    if (self->unk_14 == NULL) {
        func_0206228c();
    }
}
}

}  // namespace m_Widget_02182590

// ---- Cmd_0218283c
namespace m_Cmd_0218283c {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_0218283c(CmdQueue *self, s32 arg) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 2);
    CmdQueue_Push(self, 2, (arg << 16) | 1);
}

}

}  // namespace m_Cmd_0218283c

// ---- Cmd_02182920
namespace m_Cmd_02182920 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_02182920(CmdQueue *self) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 2);
    CmdQueue_Push(self, 2, 2);
}

}

}  // namespace m_Cmd_02182920

// ---- Cmd_021829f8
namespace m_Cmd_021829f8 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_021829f8(CmdQueue *self) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 2);
    CmdQueue_Push(self, 2, 3);
}

}

}  // namespace m_Cmd_021829f8

// ---- Stub_02182ad4
namespace m_Stub_02182ad4 {

extern "C" {

void func_ov000_02182ad4(void *self) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x3;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}

}  // namespace m_Stub_02182ad4

// ---- Cmd_02182b0c
namespace m_Cmd_02182b0c {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

typedef struct {
    u8 pad_00[8];
    u8 unk_08;
} Obj0214a424;

extern Obj0214a424 *data_0214a424;
BOOL StageFlags_IsValid(void);

static inline void Prelude(void) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
}

void func_ov000_02182b0c(CmdQueue *self) {
    if (StageFlags_IsValid()) {
        Prelude();
        CmdQueue_Push(self, 0x26, 2);
        CmdQueue_Push(self, 2, 4);
    } else {
        u8 v = data_0214a424->unk_08;
        Prelude();
        CmdQueue_Push(self, 0x26, 2);
        CmdQueue_Push(self, 2, (v << 16) | 1);
    }
}

}

}  // namespace m_Cmd_02182b0c

// ---- Lo_02182cb8
namespace m_Lo_02182cb8 {

typedef struct {
    u8 c[3];
} Id3;

class CmdEx : public CmdObj {
public:
    u8 unk_ac;
    u8 pad_ad[0xb];
    VObj *unk_b8;
    u8 pad_bc[0x11];
    Id3 unk_cd;
};

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    void *vtable;
    u32 unk_04;
} Task;

typedef struct {
    u8 pad_00[0x114];
    u32 b0 : 1;
    u32 b1 : 1;
    VObj *unk_118;
    VObj *unk_11c;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 pad_0a[0xe];
    u16 f18 : 1;
    u16 f18_1 : 15;
    u8 pad_1a[0x117];
    Id3 unk_131;
    u8 pad_134[4];
    u16 unk_138;
    u8 pad_13a[2];
    VecFx32 unk_13c;
    u8 pad_148[0xc];
    u16 unk_154;
} Obj0214a424;

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
} Dtcm02fe1534;

typedef struct {
    u8 pad_00[0xa];
    u8 unk_0a;
} Obj021ccd6c;

extern "C" {
extern Obj0214a424 *data_0214a424;
extern VObj *data_02fe152c;
extern Mgr021ccd30 *data_ov000_021ccd30;
extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb940[];
extern u8 data_ov000_021cb920[];
extern Obj02097e48 *data_02097e48;
extern Dtcm02fe1534 data_02fe1534;
extern void *data_02097e4c;
extern Obj021ccd6c *data_ov000_021ccd6c;

void func_02058fe4(void);
void func_02058f2c(void);
void *Heap_Alloc(u32 size);
void func_ov000_0216f144(Task *self);
void func_ov000_0216faac(Task *self);
void func_ov000_0216f828(Task *self);
void *func_ov000_0216f398(Mgr021ccd30 *mgr, Task *task, s32 a, Mgr021ccd30 *b);
void func_0206222c(void);
void func_0206cadc(Obj0214a424 *p);
void func_0206c4c4(Obj0214a424 *p);
void func_0206ca44(Obj0214a424 *p);
void func_0206c994(Obj0214a424 *p);
void func_ov000_02181f54(u8 *p, s32 a, s32 b, s32 c, s32 d, s32 e);
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_020626d4(VecFx32 *v, u16 a);
BOOL StageRes_IsAllLoaded(VObj *p);
BOOL func_0205aa30(VObj *p);
BOOL func_ov000_021820bc(u8 *p, s32 a);

static inline BOOL HasObj(void) {
    return data_02fe152c != NULL ? TRUE : FALSE;
}

static inline BOOL NotFlag(Obj0214a424 *p) {
    return p->f18 ? FALSE : TRUE;
}

static inline void Warp(const Id3 *id, s32 arg) {
    data_02097e48->b1 = 1;
    CmdObj_Push(((CmdEx *)data_ov000_021ccd54), 9, arg);
    if (id != NULL) {
        ((CmdEx *)data_ov000_021ccd54)->unk_cd = *id;
    }
}

s32 func_ov000_02182cb8(CmdEx *self) {
    u16 mode = self->unk_a4;
    switch (self->step) {
    case 0:
        if (mode == 1 || mode == 2 || !HasObj()) {
            func_02058fe4();
            func_02058f2c();
        }
        self->step++;
        return 0;
    case 1: {
        Mgr021ccd30 *mgr;
        if (!data_02fe152c->vfunc_2c()) {
            return 0;
        }
        data_02fe152c->vfunc_30();
        mgr = data_ov000_021ccd30;
        if (mgr->unk_11c == NULL) {
            Task *task = (Task *)Heap_Alloc(0x80);
            if (task != NULL) {
                task->vtable = data_ov000_021cb6d0;
                func_ov000_0216f144(task);
                task->vtable = data_ov000_021cb940;
                func_ov000_0216faac(task);
            }
            mgr->unk_11c = (VObj *)task;
            func_ov000_0216f398(mgr, task, 0x10000, mgr);
            ((Task *)mgr->unk_11c)->unk_04 |= 0x10;
        }
        mgr = data_ov000_021ccd30;
        if (mgr->unk_118 == NULL) {
            Task *task = (Task *)Heap_Alloc(0x34);
            if (task != NULL) {
                task->vtable = data_ov000_021cb6d0;
                func_ov000_0216f144(task);
                task->vtable = data_ov000_021cb920;
                func_ov000_0216f828(task);
            }
            mgr->unk_118 = (VObj *)task;
            func_ov000_0216f398(mgr, task, 0x10000, mgr);
            ((Task *)mgr->unk_118)->unk_04 |= 0x10;
        }
        self->step++;
    }
    case 2: {
        Mgr021ccd30 *mgr = data_ov000_021ccd30;
        BOOL ready;
        if (mgr->b0) {
            ready = FALSE;
        } else if (mgr->unk_118 == NULL || mgr->unk_11c == NULL) {
            ready = TRUE;
        } else {
            ready = TRUE;
            if (!mgr->unk_118->vfunc_08()) {
                ready = FALSE;
            }
            if (!mgr->unk_11c->vfunc_08()) {
                ready = FALSE;
            }
        }
        if (!ready) {
            return 0;
        }
        if ((u32)(mode - 1) <= 1) {
            if (mode == 2) {
                func_0206222c();
                func_0206cadc(data_0214a424);
                data_02097dd0->frameCount = data_0214a424->unk_04;
            } else {
                func_0206c4c4(data_0214a424);
                data_0214a424->unk_08 = self->unk_a6;
                data_02097dd0->frameCount = 0;
            }
            data_02fe1534.unk_02 = 0;
            data_02fe1534.unk_04 = 0;
            {
                CmdEx *obj = (CmdEx *)data_ov000_021ccd54;
                CmdObj_Push(obj, 6, 0);
                func_ov000_02181f54(&obj->unk_ac, 0, 0, 0, 0, 0);
            }
            {
                Id3 id = data_0214a424->unk_131;
                Warp(&id, 1);
            }
        } else if ((u32)(mode - 3) <= 1) {
            u32 kind = 0xffff;
            if (mode == 4) {
                func_0206ca44(data_0214a424);
            } else {
                func_0206c994(data_0214a424);
                data_02097dd0->frameCount = data_0214a424->unk_04;
                kind = data_0214a424->unk_09;
            }
            if (kind == 1) {
                Id3 id;
                id.c[0] = 0xfe;
                id.c[1] = 0xfe;
                id.c[2] = 0xfe;
                Warp(&id, 0);
            } else if (kind == 0) {
                SndMgr_LoadHeapState(data_02097e4c, 1, 1);
                {
                    Obj02097e48 *p = data_02097e48;
                    if (p->flag) {
                        p->unk_06 = 0x8000;
                        p->unk_08 = 0x1e;
                        p->unk_02 = 0;
                    }
                }
                {
                    Obj02097e48 *p = data_02097e48;
                    p->unk_74 = 0x8000;
                    p->unk_70 = 0;
                }
                CmdObj_Push(self, 0x26, 1);
                CmdObj_Push(self, 0x1e, 0);
            } else {
                u16 room = data_0214a424->unk_138;
                if (room != 0xffff) {
                    data_ov000_021ccd6c->unk_0a = room;
                } else if (NotFlag(data_0214a424)) {
                    Obj0214a424 *p = data_0214a424;
                    VecFx32 v;
                    v.x = p->unk_13c.x;
                    v.y = p->unk_13c.y;
                    v.z = p->unk_13c.z;
                    func_020626d4(&v, p->unk_154);
                }
                {
                    Id3 id = data_0214a424->unk_131;
                    Warp(&id, 0);
                }
            }
            self->step++;
            return 0;
        }
        CmdObj_Done(self);
        return 0;
    }
    case 3: {
        BOOL done;
        if (self->unk_b8 == NULL || self->unk_b8->vfunc_34()) {
            done = TRUE;
        } else if (!StageRes_IsAllLoaded(self->unk_b8)) {
            done = FALSE;
        } else {
            func_0205aa30(self->unk_b8);
            done = TRUE;
        }
        if (done && func_ov000_021820bc(&self->unk_ac, 0)) {
            CmdObj_Done(self);
            return 0;
        }
        break;
    }
    }
    return 1;
}
}

}  // namespace m_Lo_02182cb8

// ---- Lo_021833d8
namespace m_Lo_021833d8 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

s32 func_ov000_021833d8(CmdObj *self) {
    switch (self->step) {
    case 0:
        self->step++;
        return 0;
    case 1:
        func_0206c72c(data_0214a424, 0);
        CmdObj_Done(self);
        return 1;
    }
    return 1;
}

}

}  // namespace m_Lo_021833d8

// ---- Stub_0218348c
namespace m_Stub_0218348c {

extern "C" {

void func_ov000_0218348c(void *self, s32 arg) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x4;
    ((s32 *)((u8 *)self + 0x50))[*index] = arg;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}

}  // namespace m_Stub_0218348c

// ---- Lo_021834c4
namespace m_Lo_021834c4 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

s32 func_ov000_021834c4(CmdObj *self) {
    switch (self->step) {
    case 0: {
        if (!(LFLD(s32, &data_02097d78, 0xc) == 0 && LFLD(s32, &data_02097d78, 0) == 0 ? 1 : 0)) {
            func_0203cb78(0x8000, 0, -1);
        }
        LFLD(u8, data_0214a424, 9) = (u8)self->unk_a4;
        func_0206c620(data_0214a424);
        func_ov000_02180660(7, 0);
        self->step++;
        return 0;
    }
    case 1:
        if (MsgDone()) {
            func_ov000_02180754();
            CmdObj_Done(self);
        }
        return 1;
    }
    return 1;
}

s32 func_ov000_021835f4(CmdObj *self) {
    switch (self->step) {
    case 0:
        func_ov000_02180660(8, self->unk_a4);
        self->step++;
        return 0;
    case 1:
        if (MsgDone()) {
            func_ov000_02180754();
            CmdObj_Done(self);
        }
        return 0;
    }
    return 1;
}

}

}  // namespace m_Lo_021834c4

// ---- Stub_021836d0
namespace m_Stub_021836d0 {

extern "C" {

void func_ov000_02181f54(void *p, s32 a, s32 b, s32 c, u16 d, u16 e);

void func_ov000_021836d0(CmdQueue *self, s32 a, s32 b, s32 c, u16 d, u16 e) {
    CmdQueue_Push(self, 6, 0);
    func_ov000_02181f54((u8 *)self + 0xac, a, b, c, d, e);
}

}

}  // namespace m_Stub_021836d0

// ---- Stub_0218372c
namespace m_Stub_0218372c {

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ctrl0218372c;

typedef struct {
    u8 unk_00[0xb8];
    VObj *unk_b8;
} Obj0218372c;

extern "C" {

extern void *data_02fe152c;
void func_020592c4(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02182590(u8 *p);

void func_ov000_0218372c(Obj0218372c *self, s32 a) {
    void *saved;
    func_020592c4(data_02fe152c, 2, 0x101, a, 1);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_b8 != NULL) {
        if (self->unk_b8 != NULL) {
            self->unk_b8->vfunc_04();
        }
        self->unk_b8 = NULL;
    }
    data_02097dd0->cur = saved;
    {
        Ctrl0218372c *c = (Ctrl0218372c *)data_ov000_021ccd54;
        c->unk_ac = 1;
        func_ov000_02182590(&c->unk_ac);
    }
}

}

}  // namespace m_Stub_0218372c

// ---- Stub_021837c0
namespace m_Stub_021837c0 {

extern "C" {

void func_ov000_02182190(void *p, s32 a, s32 b, s32 c, u16 d, u16 e, u16 f);
void func_ov000_02182374(void *p, s32 a, s32 b);

void func_ov000_021837c0(void *self) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x8;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

void func_ov000_021837f8(void *self, s32 a, s32 b, s32 c, u16 d, u16 e, u16 f) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x7;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
    func_ov000_02182190((u8 *)self + 0xac, a, b, c, d, e, f);
}

void func_ov000_02183858(void *self, s32 a) {
    func_ov000_02182374((u8 *)self + 0xac, a, 0);
}

void func_ov000_0218386c(void *self, s32 a) {
    func_ov000_02182374((u8 *)self + 0xac, a, 1);
}

}

}  // namespace m_Stub_021837c0

// ---- Lo_02183880
namespace m_Lo_02183880 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

static inline BOOL WaitB8(CmdObj *self) {
    if (LFLD(VObj *, self, 0xb8) == NULL || LFLD(VObj *, self, 0xb8)->vfunc_34()) {
        return TRUE;
    }
    if (!StageRes_IsAllLoaded(LFLD(VObj *, self, 0xb8))) {
        return FALSE;
    }
    func_0205aa30(LFLD(VObj *, self, 0xb8));
    return TRUE;
}

s32 func_ov000_02183880(CmdObj *self) {
    switch (self->unk_98) {
    case 6:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (WaitB8(self)) {
                CmdObj_Done(self);
            }
            break;
        }
        break;
    case 7:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (func_ov000_021820bc((u8 *)self + 0xac, 1)) {
                CmdObj_Done(self);
            }
            break;
        }
        break;
    case 8:
        switch (self->step) {
        case 0:
            func_ov000_0214ba18();
            self->step++;
            return 0;
        case 1:
            if (func_ov000_0214bb04()) {
                func_ov000_0214bb2c();
                func_ov000_0214bb5c();
                func_ov000_0214baa8();
                CmdObj_Done(self);
            }
            break;
        }
        break;
    }
    return 0;
}

}

}  // namespace m_Lo_02183880

// ---- Lo_02183a10
namespace m_Lo_02183a10 {

typedef struct {
    u8 c[3];
} Id3;

class CmdEx : public CmdObj {
public:
    u8 unk_ac;
    u8 pad_ad[3];
    s32 unk_b0;
    u8 pad_b4[0x14];
    u8 unk_c8;
    u8 unk_c9;
    Id3 unk_ca;
    Id3 unk_cd;
};

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 14;
    u8 pad_02[0x6e];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u8 pad_00[0x114];
    u32 b0 : 1;
    u32 b1 : 1;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0xb1c];
    u16 unk_b1c;
} Obj0219bf90;

typedef struct {
    u8 pad_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
} Actor0218e640;

typedef struct {
    u8 pad_00[0xa];
    u8 unk_0a;
} Obj021ccd6c;

typedef struct {
    u8 pad_00[0x24];
    u16 unk_24;
    u16 unk_26;
    u8 pad_28[0x1e];
    u16 unk_46;
} Dtcm02fe1534;

extern "C" {
extern s32 data_02097d78[];
extern Obj02097e48 *data_02097e48;
extern void *data_ov000_021ccd68;
extern Dtcm02fe1534 data_02fe1534;
extern Obj021ccd6c *data_ov000_021ccd6c;
extern void *data_0214a424;
extern void *data_02097e4c;
extern Mgr021ccd30 *data_ov000_021ccd30;
Obj0219bf90 *func_ov000_0219bf90(void);
Actor0218e640 *ActorMgr_GetActor(void *mgr, u16 id);
void func_02062478(Id3 *id);
void func_ov000_02182590(u8 *p);
void func_020624b8(void);
void func_0206c72c(void *p, Id3 *id);
void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_02062424(Id3 *id);
BOOL func_ov000_02181d70(u8 *p);
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

static inline BOOL IsMode1(void) {
    BOOL r;
    if (data_02097d78[3] == 1) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 1;
    }
    return r;
}

static inline BOOL IsMode0(void) {
    return data_02097d78[3] == 0 && data_02097d78[0] == 0;
}

static inline BOOL IdEq(const Id3 *a, const Id3 *b) {
    BOOL r = FALSE;
    if (a->c[0] == b->c[0] && a->c[1] == b->c[1] && a->c[2] == b->c[2]) {
        r = TRUE;
    }
    return r;
}

s32 func_ov000_02183a10(CmdEx *self) {
    BOOL hasArg;
    s32 fade;
    if (self->step == 0) {
        self->step++;
        return 0;
    }
    if (IsMode1()) {
        return 0;
    }
    hasArg = TRUE;
    if (self->unk_a4 == 0) {
        hasArg = FALSE;
    }
    CmdObj_Done(self);
    data_02097e48->b1 = 0;
    if ((self->unk_b0 != 0 ? TRUE : FALSE)) {
        Obj0219bf90 *obj;
        self->unk_c8 = 0;
        obj = func_ov000_0219bf90();
        if (obj != NULL) {
            Actor0218e640 *actor = NULL;
            u16 id = obj->unk_b1c;
            if (data_ov000_021ccd68 != NULL) {
                actor = ActorMgr_GetActor(data_ov000_021ccd68, id);
            }
            if (actor != NULL) {
                data_02fe1534.unk_24 = actor->unk_0e;
                data_02fe1534.unk_26 = actor->unk_0c;
            }
        }
        func_02062478(&self->unk_cd);
        self->unk_ac = 1;
        func_ov000_02182590(&self->unk_ac);
        func_020624b8();
        if (self->unk_c8) {
            self->unk_c8 = 0;
            data_ov000_021ccd6c->unk_0a = 0xff;
            self->unk_cd.c[0] = 0xff;
            self->unk_cd.c[1] = 0xff;
            self->unk_cd.c[2] = 0xff;
            self->state = 3;
            return 0;
        }
    }
    if (hasArg) {
        func_0206c72c(data_0214a424, &self->unk_cd);
    }
    fade = 0xf000;
    if (self->unk_c9) {
        fade = 0x1000;
    }
    if (IsMode0()) {
        func_0203c9e8(0x3f, 0);
        func_0203cc58(fade, 2, 0);
    }
    if (data_02fe1534.unk_46 == self->unk_cd.c[0]) {
        if (IdEq(&((CmdEx *)data_ov000_021ccd54)->unk_ca, &self->unk_cd) && self->unk_c9 == 0) {
            if (func_ov000_0219bf90() == NULL) {
                CmdObj_Push(((CmdEx *)data_ov000_021ccd54), 0xb, 0);
            }
            data_02097e48->b1 = 1;
            CmdObj_Push(((CmdEx *)data_ov000_021ccd54), 0xa, 0);
            if (&self->unk_cd != NULL) {
                ((CmdEx *)data_ov000_021ccd54)->unk_cd = self->unk_cd;
            }
            self->state = 3;
        } else {
            func_02062424(&self->unk_cd);
            ((CmdEx *)data_ov000_021ccd54)->unk_ac = 1;
            self->unk_cd.c[0] = 0xff;
            self->unk_cd.c[1] = 0xff;
            self->unk_cd.c[2] = 0xff;
            self->state = 3;
        }
    } else {
        func_ov000_02181d70(&self->unk_ac);
        self->state = 4;
    }
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    data_ov000_021ccd30->b1 = 0;
    return 0;
}
}

}  // namespace m_Lo_02183a10

// ---- Lo_02183db8
namespace m_Lo_02183db8 {

typedef struct {
    u8 c[3];
} Id3;

typedef struct {
    u8 b0 : 2;
    u8 mode : 2;
    u8 b4 : 4;
} Bits0e;

class CmdEx : public CmdObj {
public:
    u8 unk_ac;
    u8 pad_ad[0x1b];
    u8 unk_c8;
    u8 unk_c9;
    Id3 unk_ca;
    Id3 unk_cd;
    Id3 unk_d0;
    u8 pad_d3[0xb9];
    u8 unk_18c;
    u8 unk_18d;
    u8 unk_18e;
    u8 unk_18f;
};

#define BITS0E(self) (*(Bits0e *)((u8 *)(self) + 0xe))

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
} Obj02097e48;

typedef struct {
    u8 pad_00[0x28];
    s32 unk_28;
    u8 pad_2c[4];
    s32 unk_30;
} Task118;

typedef struct {
    u8 pad_00[0x7c];
    void *unk_7c;
} Task11c;

typedef struct {
    u8 pad_00[0x118];
    Task118 *unk_118;
    Task11c *unk_11c;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0xc];
    u8 b0 : 1;
    u8 b1 : 7;
} Obj021ccd64;

typedef struct {
    u8 pad_00[0x8b0];
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
} Obj02097d48;

typedef struct {
    u8 pad_00[0x15];
    u8 unk_15;
    u8 pad_16[0xb12];
    u8 f0 : 2;
    u8 f2 : 1;
    u8 f3 : 5;
} Obj0219bf90;

class Player : public VObj {
public:
    u8 pad_04[0x8f];
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 3;
};

typedef struct {
    u8 pad_00[0x22];
    u16 unk_22;
} Ov004Obj;

typedef BOOL (*ProtFn)(u32 addr, s32 arg);

typedef struct {
    u8 pad_00[0x2c];
    s32 unk_2c;
} OvMgr;

extern "C" {
extern Mgr021ccd30 *data_ov000_021ccd30;
extern OvMgr *data_02149ef0;
extern s32 data_02097d78[];
extern Obj021ccd64 *data_ov000_021ccd64;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a420;
extern void *data_ov000_021ccd6c;
extern void *data_ov000_021ccd68;
extern Obj02097d48 *data_02097d48;
extern u32 data_ov004_021cf868;
extern ProtFn data_ov004_021cf86c[];
extern u8 OVERLAY_3_ID[];
extern u8 OVERLAY_4_ID[];

Player *func_ov000_0219bf90(void);
void func_0204b270(void *p, s32 a, s32 b);
Ov004Obj *func_ov004_021cce88(void);
void func_ov004_021ccf10(void);
BOOL func_ov004_021ce2ec(u32 addr, s32 arg);
BOOL func_ov004_021ce374(u32 addr, s32 arg);
BOOL func_ov004_021ce3fc(u32 addr, s32 arg);
bool Ov003TaskVt_021f78f4_GetFlag6(u32 addr, s32 arg);
void func_0204aa10(void *p);
void func_ov000_0216bcbc(void *p);
void func_ov000_021645a4(s32 a);
void EffectMgr_FreeAll(void *p);
void func_ov000_021b53f4(void *p);
void func_ov000_0218be9c(void *p);
void ActorMgr_DestroyAll(void *p);
void MessageQueue_RemoveAll(Mgr021ccd30 *p, s32 a, s32 b, s32 c);
BOOL func_ov000_021b5578(void *p);
void func_ov000_021b5dc0(void *p);
void func_ov000_021b628c(void *p);
void func_ov003_021cfa30(void);
void func_ov000_0218c25c(void *p);
void func_ov000_0218be54(void *p);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_0216f844(Task118 *p, s32 a);

static inline u32 ProtHash(const u32 *p) {
    u32 i;
    u32 h;
    for (i = 0x1c, h = 0; i != 0; i--, p++) {
        h ^= (*p >> i) | (*p << (32 - i));
    }
    return h;
}

static inline BOOL IsMode3(void) {
    BOOL r;
    if (data_02097d78[3] == 3) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 3;
    }
    return r;
}

static inline BOOL IdEq(const Id3 *a, const Id3 *b) {
    BOOL r = FALSE;
    if (a->c[0] == b->c[0] && a->c[1] == b->c[1] && a->c[2] == b->c[2]) {
        r = TRUE;
    }
    return r;
}

static inline s32 TaskVal(Task118 *t) {
    return t->unk_28 != 1 ? 0 : t->unk_30;
}

static inline BOOL TaskHasVal(Task118 *t) {
    return (TaskVal(t) != 0 ? TRUE : FALSE) ? TRUE : FALSE;
}

s32 func_ov000_02183db8(CmdEx *self) {
    Player *pl = func_ov000_0219bf90();
    u16 sub = self->unk_a8;
    switch (self->step) {
    case 0:
        if ((s32)OVERLAY_3_ID != data_02149ef0->unk_2c) {
            Ov004Obj *obj;
            BOOL r;
            func_0204b270(data_02149ef0, (s32)OVERLAY_4_ID, 0);
            obj = func_ov004_021cce88();
            if (ProtHash((const u32 *)func_ov004_021ce2ec) == 0x786385f) {
                r = func_ov004_021ce2ec(0x2001000, 0);
            } else {
                r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001000, 0);
            }
            if (r) {
                obj->unk_22 = 1;
            } else {
                if (ProtHash((const u32 *)func_ov004_021ce374) == 0x786385f) {
                    r = func_ov004_021ce374(0x2001800, 0);
                } else {
                    r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001800, 0);
                }
                if (r) {
                    obj->unk_22 = 2;
                } else {
                    if (ProtHash((const u32 *)func_ov004_021ce3fc) == 0x786385f) {
                        r = func_ov004_021ce3fc(0x2001c00, 0x2001e00);
                    } else {
                        r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001c00, 0x2001e00);
                    }
                    if (r) {
                        obj->unk_22 = 3;
                    } else {
                        if (ProtHash((const u32 *)Ov003TaskVt_021f78f4_GetFlag6) == 0x786385f) {
                            r = Ov003TaskVt_021f78f4_GetFlag6(0x2002000, 0);
                        } else {
                            r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2002000, 0);
                        }
                        if (r) {
                            obj->unk_22 = 4;
                        }
                    }
                }
            }
            func_ov004_021ccf10();
            func_0204b270(data_02149ef0, (s32)OVERLAY_3_ID, 0);
        }
        self->step++;
        return 0;
    case 1:
        if (IsMode3()) {
            break;
        }
        data_ov000_021ccd64->b0 = 1;
        if (self->unk_cd.c[0] != 0xff) {
            if (!IdEq(&((CmdEx *)data_ov000_021ccd54)->unk_ca, &self->unk_cd) || self->unk_c9 != 0) {
                func_0204aa10(data_02097e48);
                data_02097e48->b2 = 0;
                self->unk_d0 = self->unk_ca;
                self->unk_ca = self->unk_cd;
                BITS0E(self).mode = 2;
                if (data_ov000_021ccd30->unk_11c != NULL && data_ov000_021ccd30->unk_11c->unk_7c != NULL) {
                    func_ov000_0216bcbc(data_ov000_021ccd30->unk_11c->unk_7c);
                }
                {
                    Mgr021ccd30 *mgr = data_ov000_021ccd30;
                    BOOL has;
                    if (mgr->unk_118 == NULL) {
                        has = FALSE;
                    } else {
                        has = TaskHasVal(mgr->unk_118);
                    }
                    if (has) {
                        func_ov000_021645a4(TaskVal(mgr->unk_118));
                    }
                }
                self->unk_18c = 0;
                self->unk_18d = 0;
                self->unk_18e = 0;
                self->unk_18f = 0;
                EffectMgr_FreeAll(data_0214a420);
                func_ov000_021b53f4(data_ov000_021ccd6c);
                func_ov000_0218be9c(data_ov000_021ccd64);
                ActorMgr_DestroyAll(data_ov000_021ccd68);
            } else {
                self->unk_d0 = self->unk_ca;
                self->unk_ca = self->unk_cd;
            }
        }
        {
            Obj0219bf90 *p = (Obj0219bf90 *)func_ov000_0219bf90();
            if (p != NULL && p->f0 == 0) {
                p->unk_15 = 3;
                p->f0 = 0;
                p->f2 = 1;
            }
        }
        if (pl != NULL) {
            pl->b4 = 0;
            if (data_ov000_021ccd30 != NULL) {
                MessageQueue_RemoveAll(data_ov000_021ccd30, 0x14, 1, 0);
            }
            if (data_ov000_021ccd30 != NULL) {
                MessageQueue_RemoveAll(data_ov000_021ccd30, 0x14, 2, 0);
            }
        }
        self->step++;
    case 2: {
        self->unk_cd.c[0] = 0xff;
        self->unk_cd.c[1] = 0xff;
        self->unk_cd.c[2] = 0xff;
        if (self->unk_ca.c[0] == 0xfe) {
            Obj02097d48 *d;
            self->unk_a8 = 2;
            d = data_02097d48;
            d->b4 = 0;
            d->b5 = 1;
            *(vu16 *)0x4000060 &= 0xcfdf;
        }
        self->step++;
        break;
    }
    case 3:
        switch (sub) {
        case 0:
            if (pl == NULL || pl->vfunc_0c()) {
                self->unk_a8 = sub + 1;
            }
            break;
        case 1:
            if (func_ov000_021b5578(data_ov000_021ccd6c)) {
                func_ov000_021b5dc0(data_ov000_021ccd6c);
                func_ov000_021b628c(data_ov000_021ccd6c);
                func_ov003_021cfa30();
                func_ov000_0218c25c(data_ov000_021ccd64);
                if (data_ov000_021ccd64 != NULL) {
                    func_ov000_0218be54(data_ov000_021ccd64);
                }
                self->unk_a8 = sub + 1;
            }
            break;
        case 2:
            if (ActorMgr_IsReady(data_ov000_021ccd68)) {
                if (data_ov000_021ccd30->unk_118 != NULL) {
                    func_ov000_0216f844(data_ov000_021ccd30->unk_118, 1);
                }
                if (self->unk_ca.c[0] != 0xfe) {
                    BITS0E(self).mode = 0;
                }
                self->unk_c9 = 0;
                CmdObj_Done(self);
                data_02097e48->b1 = 0;
                return 1;
            }
            break;
        }
        break;
    }
    return 0;
}
}

}  // namespace m_Lo_02183db8
#undef BITS0E

// ---- Stub_02184498
namespace m_Stub_02184498 {

typedef struct {
    s32 unk_00;
    u8 unk_04[0x8];
    s32 unk_0c;
} Data02097d78;

extern "C" {

extern Data02097d78 data_02097d78;
void func_0203cb78(s32 a, s32 b, s32 c);

static inline BOOL IsMode(s32 mode) {
    return data_02097d78.unk_0c == mode ? TRUE : (data_02097d78.unk_00 == mode ? TRUE : FALSE);
}

static inline BOOL IsIdle(void) {
    return data_02097d78.unk_0c == 0 && data_02097d78.unk_00 == 0;
}

BOOL func_ov000_02184498(void *self) {
    if (IsMode(4)) {
        func_0203cb78(0xa000, 0, 0);
    }
    if (!IsIdle()) {
        return FALSE;
    }
    return TRUE;
}

}

}  // namespace m_Stub_02184498

// ---- Stub_02184508
namespace m_Stub_02184508 {

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0xb12];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
    u8 unk_b28_3 : 5;
} Obj0219bf90;

extern "C" {

Obj0219bf90 *func_ov000_0219bf90(void);

void func_ov000_02184508(void *self) {
    Obj0219bf90 *p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    if (p->unk_b28_0 != 0) {
        return;
    }
    p->unk_15 = 3;
    p->unk_b28_0 = 0;
    p->unk_b28_2 = 1;
}

void func_ov000_02184548(void *self) {
    Obj0219bf90 *p;
    if (*((u8 *)self + 0xca) == 0xfe) {
        return;
    }
    p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    if (p->unk_b28_0 != 0) {
        return;
    }
    p->unk_15 = 1;
    p->unk_b28_0 = 0;
    p->unk_b28_2 = 0;
}

}

}  // namespace m_Stub_02184508

// ---- Stub_02184594
namespace m_Stub_02184594 {

extern "C" {

void func_ov000_02184594(void *self) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0xb;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}

}  // namespace m_Stub_02184594

// ---- Lo_021845cc
namespace m_Lo_021845cc {

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0xb12];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
    u8 unk_b28_3 : 5;
} Obj0219bf90;

extern "C" {
extern s32 data_02097d78[];
Obj0219bf90 *func_ov000_0219bf90(void);
VObj *Robo021ca458_Ctor(void *p);
void *Heap_Alloc(u32 size);
s32 func_0206ffa0(s32 a);
void Actor_JoinGroup(void *self, u16 id, u16 kind, s32 arg);
BOOL func_ov000_0219c86c(Obj0219bf90 *self);

static inline BOOL IsMode3(void) {
    BOOL r;
    if (data_02097d78[3] == 3) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 3;
    }
    return r;
}

static inline void Wake0219bf90(void) {
    Obj0219bf90 *p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    if (p->unk_b28_0 != 0) {
        return;
    }
    p->unk_15 = 3;
    p->unk_b28_0 = 0;
    p->unk_b28_2 = 1;
}

s32 func_ov000_021845cc(CmdObj *self) {
    Obj0219bf90 *cur = func_ov000_0219bf90();
    switch (self->step) {
    case 0:
        self->step++;
        return 0;
    case 1:
        if (IsMode3()) {
            break;
        }
        if (cur == NULL) {
            VObj *obj = (VObj *)Heap_Alloc(0xbb0);
            if (obj != NULL) {
                obj = Robo021ca458_Ctor(obj);
            }
            Actor_JoinGroup(obj, 0x1000, 0x1000, func_0206ffa0(0x1000));
            obj->vfunc_04();
            Wake0219bf90();
        } else {
            Wake0219bf90();
        }
        self->step++;
        break;
    case 2:
        if (cur == NULL) {
            return 1;
        }
        if (func_ov000_0219c86c(cur) == 1 && cur->unk_b28_0 == 0) {
            if ((self->rd != self->index ? TRUE : FALSE)) {
                Wake0219bf90();
            }
            CmdObj_Done(self);
        }
        break;
    }
    return 1;
}
}

}  // namespace m_Lo_021845cc

// ---- Stub_021847d8
namespace m_Stub_021847d8 {

extern "C" {

void func_ov000_021847d8(void *self) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0xc;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}

}  // namespace m_Stub_021847d8

// ---- Lo_02184810
namespace m_Lo_02184810 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

s32 func_ov000_02184810(CmdObj *self) {
    func_ov000_0219bf90();
    switch (self->step) {
    case 0:
        self->step++;
        return 0;
    case 6:
        if (ActorMgr_IsReady(data_ov000_021ccd68)) {
            CmdObj_Done(self);
        }
        break;
    default:
        self->step++;
        break;
    }
    return 1;
}

}

}  // namespace m_Lo_02184810

// ---- Stub_021848d0
namespace m_Stub_021848d0 {

typedef struct {
    u8 unk_00[0x10];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 unk_90;
    s32 index;
    u8 unk_98[0x32];
    u8 unk_ca;
} CmdQueue;

extern "C" {

Robo021ca458 *func_ov000_0219bf90(void);

void func_ov000_021848d0(CmdQueue *self) {
    if (func_ov000_0219bf90() == NULL || self->unk_ca == 0xfe) {
        return;
    }
    self->kinds[self->index] = 0xd;
    self->args[self->index] = 0;
    if (++self->index >= 0x10) {
        self->index = 0;
    }
}

}

}  // namespace m_Stub_021848d0

// ---- Lo_02184924
namespace m_Lo_02184924 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

s32 func_ov000_02184924(CmdObj *self) {
    switch (self->step) {
    case 0:
        func_ov000_02180660(1, 0);
        self->step++;
        return 0;
    case 1:
        if (MsgDone()) {
            func_ov000_02180754();
            CmdObj_Done(self);
        }
        return 0;
    }
    return 1;
}

}

}  // namespace m_Lo_02184924

// ---- Stub_02184a04
namespace m_Stub_02184a04 {

extern "C" {

s32 func_ov000_02184a04(s32 x) {
    return x / 100;
}

}

}  // namespace m_Stub_02184a04

// ---- Lo_02184a1c
namespace m_Lo_02184a1c {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

static inline BOOL MgrBusy(void) {
    u8 *mgr = data_ov000_021ccd30;
    if (mgr == NULL) {
        return FALSE;
    }
    if (func_ov000_0216f674(mgr, 0xf)) {
        return TRUE;
    }
    if (LFLD(void *, mgr, 0x11c) == NULL) {
        return FALSE;
    }
    return func_ov000_0217060c(LFLD(void *, mgr, 0x11c));
}

s32 func_ov000_02184a1c(CmdObj *self, s32 arg) {
    switch (self->step) {
    case 0:
        func_ov000_02172390(data_ov000_021ccd30, 0, MsgRes_GetString(data_02149ef8, func_02061d54(0x25)));
        self->step++;
    case 1:
        if (MgrBusy()) {
            break;
        }
        switch (func_02062834()) {
        case 0:
            func_ov000_02180660(4, arg);
            self->step = 2;
            goto wait;
        case 1:
            func_ov000_02180660(10, arg);
            self->step = 2;
            goto wait;
        default:
            func_ov000_02180754();
            CmdObj_Done(self);
            return 0;
        }
    case 2:
    wait:
        if (MsgDone()) {
            func_ov000_02180754();
            self->step = 0;
        }
        break;
    }
    return 1;
}

}

}  // namespace m_Lo_02184a1c

// ---- Stub_02184bb0
namespace m_Stub_02184bb0 {

extern "C" {

void func_ov000_02184bb0(void *self, s32 arg) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0xe;
    ((s32 *)((u8 *)self + 0x50))[*index] = arg;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}

}  // namespace m_Stub_02184bb0

// ---- Lo_02184be8
namespace m_Lo_02184be8 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

static inline BOOL MgrBusy(void);

s32 func_ov000_02184be8(CmdObj *self) {
    switch (self->unk_a4 / 100) {
    case 0:
        func_ov000_02184a1c(self, self->unk_a4);
        break;
    case 1:
        switch (self->step) {
        case 0:
            func_ov000_02180660(4, self->unk_a4);
            self->step++;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            break;
        }
        break;
    case 2:
        switch (self->step) {
        case 0:
            func_ov000_02180660(0xb, self->unk_a4);
            self->step++;
            break;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            break;
        }
        break;
    case 3:
        switch (self->step) {
        case 0:
            func_ov000_02180660(4, self->unk_a4);
            self->step++;
            break;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            break;
        }
        break;
    default:
        CmdObj_Done(self);
        break;
    }
    return 1;
}

}

}  // namespace m_Lo_02184be8

// ---- Stub_02184d90
namespace m_Stub_02184d90 {

extern "C" {

void func_ov000_02184d90(void *self, s32 arg) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0xf;
    ((s32 *)((u8 *)self + 0x50))[*index] = arg;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}

}  // namespace m_Stub_02184d90

// ---- Lo_02184dc8
namespace m_Lo_02184dc8 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

s32 func_ov000_02184dc8(CmdObj *self) {
    u16 a = self->unk_a4;
    switch (self->step) {
    case 0:
        func_ov000_02180660(0xe, a);
        self->step++;
        return 0;
    case 1:
        if (MsgDone()) {
            func_ov000_02180754();
            CmdObj_Done(self);
        }
        return 1;
    }
    return 1;
}

}

}  // namespace m_Lo_02184dc8

// ---- Stub_02184ea4
namespace m_Stub_02184ea4 {

typedef struct {
    u8 unk_00[0x10];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 unk_90;
    s32 index;
} CmdQueue;

extern "C" {

void func_ov000_02184ea4(CmdQueue *self, s32 a) {
    self->kinds[self->index] = 0x10;
    self->args[self->index] = a << 16;
    if (++self->index >= 0x10) {
        self->index = 0;
    }
}

void func_ov000_02184ee0(CmdQueue *self, s32 a) {
    self->kinds[self->index] = 0x10;
    self->args[self->index] = (a << 16) | 1;
    if (++self->index >= 0x10) {
        self->index = 0;
    }
}

}

}  // namespace m_Stub_02184ea4

// ---- Lo_02184f20
namespace m_Lo_02184f20 {

typedef struct {
    u8 c[3];
} Id3;

class Item : public VObj {
public:
    u8 pad_04[0xc2];
    u16 unk_c6;
    u8 pad_c8[2];
    u16 unk_ca;
    u16 unk_cc;
    u8 pad_ce[6];
    Item *unk_d4;
};

class CmdEx : public CmdObj {
public:
    u8 pad_ac[0x10];
    Item *unk_bc;
    u8 pad_c0[9];
    u8 unk_c9;
    Id3 unk_ca;
    Id3 unk_cd;
};

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 14;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 31;
} Bits54;

typedef struct {
    u8 pad_00[0x54];
    Bits54 *unk_54;
} Task11c;

typedef struct {
    u8 pad_00[0x11c];
    Task11c *unk_11c;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0x60c];
    u32 unk_60c[2];
} Obj0214a424;

extern "C" {
extern Flags021ccd44 *data_ov000_021ccd44;
extern void *data_02149ef8;
extern Mgr021ccd30 *data_ov000_021ccd30;
extern Obj02097e48 *data_02097e48;
extern Obj0214a424 *data_0214a424;

void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
u16 func_02061d54(s32 a);
void *MsgRes_GetString(void *p, s32 a);
void func_ov000_02172390(void *mgr, s32 a, void *b);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
u16 func_02062834(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

static inline void Warp(const Id3 *id, s32 arg) {
    data_02097e48->b1 = 1;
    CmdObj_Push(((CmdEx *)data_ov000_021ccd54), 9, arg);
    if (id != NULL) {
        ((CmdEx *)data_ov000_021ccd54)->unk_cd = *id;
    }
}

static inline BOOL Busy(void) {
    BOOL r;
    Mgr021ccd30 *mgr = data_ov000_021ccd30;
    if (mgr == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(mgr, 0xf)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_0217060c(mgr->unk_11c);
    }
    return r;
}

s32 func_ov000_02184f20(CmdEx *self) {
    u16 mode = self->unk_a4;
    u16 arg = self->unk_a6;
    switch (mode) {
    case 0:
        switch (self->step) {
        case 0:
            func_ov000_02180660(0xc, arg);
            self->step++;
            return 0;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            return 1;
        }
        break;
    case 1:
        switch (self->step) {
        case 0:
            func_ov000_02180660(0xd, arg);
            self->step++;
            return 0;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            return 1;
        }
        break;
    case 2:
        switch (self->step) {
        case 0:
            func_ov000_02172390(data_ov000_021ccd30, 0, MsgRes_GetString(data_02149ef8, func_02061d54(0x28)));
            self->step++;
            return 0;
        case 1:
            if (!Busy()) {
                CmdObj_Done(self);
                if (func_02062834() == 1) {
                    u16 n = 0;
                    Item *p;
                    for (p = ((CmdEx *)data_ov000_021ccd54)->unk_bc; p != NULL; p = p->unk_d4) {
                        if (n == 0) {
                            break;
                        }
                        if (p->vfunc_34()) {
                            n++;
                        }
                    }
                    if (p != NULL) {
                        Bits54 *b = data_ov000_021ccd30->unk_11c->unk_54;
                        if (b != NULL) {
                            b->b0 = 1;
                        }
                        switch (p->unk_c6) {
                        case 9: {
                            Id3 id;
                            p->unk_ca = 3;
                            ((CmdEx *)data_ov000_021ccd54)->unk_c9 = 1;
                            id.c[0] = 0x11;
                            id.c[1] = 3;
                            id.c[2] = 0;
                            Warp(&id, 1);
                            break;
                        }
                        case 0x22: {
                            Id3 id;
                            p->unk_ca = 3;
                            ((CmdEx *)data_ov000_021ccd54)->unk_c9 = 1;
                            id.c[0] = 7;
                            id.c[1] = 6;
                            id.c[2] = 0;
                            Warp(&id, 1);
                            break;
                        }
                        case 0x35: {
                            Id3 id;
                            u32 i;
                            Obj0214a424 *q;
                            p->unk_ca = 3;
                            p->unk_cc = 0;
                            q = data_0214a424;
                            for (i = 0; i < 2; i++) {
                                if ((q->unk_60c[i] & ~0xff) == 0x9030c00) {
                                    q->unk_60c[i] = -1;
                                }
                            }
                            ((CmdEx *)data_ov000_021ccd54)->unk_c9 = 1;
                            id.c[0] = 0xc;
                            id.c[1] = 3;
                            id.c[2] = 0;
                            Warp(&id, 1);
                            break;
                        }
                        }
                    }
                }
            }
            return 0;
        }
        break;
    }
    return 1;
}
}

}  // namespace m_Lo_02184f20

// ---- Stub_0218547c
namespace m_Stub_0218547c {

typedef struct {
    void *vtable;
    u32 unk_04;
} Task021854d4;

typedef struct {
    u8 unk_00[0x11c];
    Task021854d4 *unk_11c;
} Mgr021854d4;

extern "C" {

extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb940[];
void *Heap_Alloc(u32 size);
void func_ov000_0216f144(Task021854d4 *self);
void func_ov000_0216faac(Task021854d4 *self);
void *func_ov000_0216f398(Mgr021854d4 *mgr, Task021854d4 *task, s32 a, Mgr021854d4 *b);
void func_ov000_02172240(void *mgr, s32 a, s32 b);

extern Mgr021854d4 *data_ov000_021ccd30;
void func_ov000_02172218(Mgr021854d4 *p);

void func_ov000_0218547c(void *state, u16 arg, void *res, u16 id) {
    func_ov000_02172218(data_ov000_021ccd30);
    CmdQueue_Push(((CmdQueue *)data_ov000_021ccd54), 0x11, 0);
}

void func_ov000_021854d4(CmdQueue *self, s32 a, s32 b) {
    Mgr021854d4 *mgr = data_ov000_021ccd30;
    if (mgr->unk_11c == NULL) {
        Task021854d4 *task = (Task021854d4 *)Heap_Alloc(0x80);
        if (task != NULL) {
            task->vtable = data_ov000_021cb6d0;
            func_ov000_0216f144(task);
            task->vtable = data_ov000_021cb940;
            func_ov000_0216faac(task);
        }
        mgr->unk_11c = task;
        func_ov000_0216f398(mgr, task, 0x10000, mgr);
        mgr->unk_11c->unk_04 |= 0x10;
    }
    func_ov000_02172240(data_ov000_021ccd30, a, b);
    CmdQueue_Push(self, 0x12, 0);
}

}

}  // namespace m_Stub_0218547c

// ---- Lo_021855a4
namespace m_Lo_021855a4 {

typedef struct {
    u8 pad_00[0x118];
    void *unk_118;
    void *unk_11c;
} Mgr021ccd30;

extern "C" {
extern Mgr021ccd30 *data_ov000_021ccd30;
void func_ov000_0216f844(void *p, s32 a);
BOOL func_ov000_0216f674(Mgr021ccd30 *mgr, s32 a);
BOOL func_ov000_021700c4(void *p);
BOOL func_ov000_021700d8(void *p);
BOOL func_ov000_021700ec(void *p);
s32 func_ov000_02170100(void *p);

static inline BOOL Busy11(void) {
    BOOL r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 6)) {
        r = TRUE;
    } else if (m->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021700c4(m->unk_11c);
    }
    return r;
}

static inline BOOL Busy12(void) {
    BOOL r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 7)) {
        r = TRUE;
    } else if (m->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021700d8(m->unk_11c);
    }
    return r;
}

static inline BOOL Busy13(void) {
    BOOL r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 8)) {
        r = TRUE;
    } else if (m->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021700ec(m->unk_11c);
    }
    return r;
}

static inline s32 State11c(void) {
    s32 r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = -1;
    } else if (m->unk_11c == NULL) {
        r = -1;
    } else {
        r = func_ov000_02170100(m->unk_11c);
    }
    return r;
}

s32 func_ov000_021855a4(CmdObj *self) {
    switch (self->unk_98) {
    case 0x11:
        switch (self->step) {
        case 0:
            if (data_ov000_021ccd30->unk_118 != NULL) {
                func_ov000_0216f844(data_ov000_021ccd30->unk_118, 1);
            }
            self->step++;
            return 0;
        case 1:
            if (Busy11()) {
                switch (State11c()) {
                case 3:
                    return 0;
                default:
                    return 1;
                }
            }
            CmdObj_Done(self);
            break;
        }
        break;
    case 0x12:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (Busy12()) {
                return 0;
            }
            CmdObj_Done(self);
            break;
        }
        break;
    case 0x13:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (Busy13()) {
                return 1;
            }
            CmdObj_Done(self);
            break;
        }
        break;
    }
    return 0;
}
}

}  // namespace m_Lo_021855a4

// ---- Stub_021857e0
namespace m_Stub_021857e0 {

extern "C" {

bool func_ov002_021e90ac();
void func_ov002_021e90dc();
void func_ov002_021e916c();

void func_ov000_021857e0(void) {
    func_ov002_021e916c();
}

void func_ov000_021857ec(void) {
    func_ov002_021e90ac();
}

void func_ov000_021857f8(void) {
    func_ov002_021e90dc();
}

}

}  // namespace m_Stub_021857e0

// ---- Cmd_02185804
namespace m_Cmd_02185804 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

typedef struct {
    u8 pad_00[0x70];
    VecFx32 pos;
    u16 rot_x;
    u16 rot_y;
} Actor02185804;

Actor02185804 *func_ov000_0219bf90(void);
void func_020626d4(VecFx32 *pos, u16 rot);

void func_ov000_02185804(CmdQueue *self, s32 arg) {
    Actor02185804 *o = func_ov000_0219bf90();
    if (o != NULL) {
        VecFx32 v;
        v.x = o->pos.x;
        v.y = o->pos.y;
        v.z = o->pos.z;
        func_020626d4(&v, o->rot_y);
    }
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x15, arg);
}

}

}  // namespace m_Cmd_02185804

// ---- Cmd_02185918
namespace m_Cmd_02185918 {

typedef struct {
    u8 pad_00[0x70];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_02185918(CmdQueue *self, s32 arg) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x16, arg);
}
}

}  // namespace m_Cmd_02185918

// ---- Lo_021859c4
namespace m_Lo_021859c4 {

typedef struct {
    u8 pad_00[0x11c];
    void *unk_11c;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0x118];
    void *unk_118;
} Mgr118;

typedef struct {
    u8 pad_00[0x149];
    u8 unk_149;
} Obj02097e3c;

typedef struct {
    u8 pad_00[0x12];
    u16 unk_12;
} Obj02097dc8;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
} Ov002Obj021f0f9c;

typedef struct {
    u8 pad_00[0x5b];
    u8 unk_5b;
} Obj02097e4c;

typedef struct {
    u8 pad_00[0x7c];
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
} Obj02097e48;

extern "C" {
extern Mgr021ccd30 *data_ov000_021ccd30;
extern void *data_02097cdc;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern char data_0214b105[];
extern Obj02097e3c *data_02097e3c;
extern Obj02097dc8 *data_02097dc8;
extern void *data_02149ef0;
extern Ov002Obj021f0f9c *data_ov002_021f0f9c;
extern Obj02097e4c *data_02097e4c;
extern Obj02097e48 *data_02097e48;
extern u8 OVERLAY_2_ID[];

void func_ov000_0216f844(void *p, s32 a);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_02170568(void *p);
BOOL func_ov000_021708d8(void *p);
BOOL func_ov000_021705a0(void *p, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_02036838(void *a, void *b, int c, int d);
void *func_020359d0(void *a, int b, int c);
int func_02035b90(void *a, int b);
void LangRes2_Delete(void);
void LangData_DeleteRes(void);
void func_0203caf8(s32 a);
void Movie_Load(void *p, s32 a, s32 b, s32 c);
void LangRes2_Create(void);
void LangData_CreateRes(void);
void Movie_RequestStop(void *p);
BOOL func_0206facc(void);
BOOL func_0206ead8(void);
void func_0206faec(void);
void func_0206eaf8(void);
void func_0204b270(void *p, s32 a, s32 b);
void func_ov000_021857e0(void);
void func_ov000_021857ec(void);
void func_ov000_021857f8(void);
void func_ov002_021e8f04(s32 a);
void func_0204a2a8(void *p, s32 a, s32 b);

static inline void ClearCallbacks(void) {
    if (data_ov000_021ccd5c != NULL) {
        data_ov000_021ccd5c();
    }
    data_ov000_021ccd5c = NULL;
    data_ov000_021ccd58 = NULL;
    data_ov000_021ccd60 = NULL;
}

static inline BOOL Busy14(void) {
    BOOL r;
    Mgr021ccd30 *mgr = data_ov000_021ccd30;
    if (mgr == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(mgr, 0x10)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0x11)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0x12)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0x13)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_02170568(mgr->unk_11c);
    }
    return r;
}

static inline BOOL Busy17(void) {
    BOOL r;
    Mgr021ccd30 *mgr = data_ov000_021ccd30;
    if (func_ov000_0216f674(mgr, 0x14)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0x15)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021708d8(mgr->unk_11c);
    }
    return r;
}

static inline BOOL Busy18(s32 a) {
    BOOL r;
    Mgr021ccd30 *mgr = data_ov000_021ccd30;
    if (mgr == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(mgr, 9)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0xa)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021705a0(mgr->unk_11c, a);
    }
    return r;
}

static inline BOOL Busy1a(void) {
    BOOL r;
    Mgr021ccd30 *mgr = data_ov000_021ccd30;
    if (mgr == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(mgr, 0xf)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_0217060c(mgr->unk_11c);
    }
    return r;
}

s32 func_ov000_021859c4(CmdObj *self) {
    switch (self->unk_98) {
    case 0x14:
        if (self->step == 0) {
            Mgr118 *m = (Mgr118 *)data_ov000_021ccd30;
            if (m->unk_118 != NULL) {
                func_ov000_0216f844(m->unk_118, 1);
            }
            self->step++;
            return 0;
        }
        if (Busy14()) {
            return 1;
        }
        CmdObj_Done(self);
        break;
    case 0x15:
        switch (self->step) {
        case 0:
            func_02036838(data_02097cdc, data_0208cc94, 7, 0);
            func_02036838(data_02097cdc, data_0208cca0, 7, 0);
            func_02036838(data_02097cdc, data_0214b105, 7, 0);
            LangRes2_Delete();
            LangData_DeleteRes();
            func_0203caf8(-1);
            Movie_Load(data_02097e3c, self->unk_a4, -1, 0);
            self->step++;
            return 0;
        case 1:
            if (data_02097e3c->unk_149 == 0) {
                func_020359d0(data_0214b105, 7, 0);
                func_020359d0(data_0208cca0, 7, 0);
                func_020359d0(data_0208cc94, 7, 0);
                LangRes2_Create();
                LangData_CreateRes();
                self->step++;
            } else if (data_02097dc8->unk_12 & 8) {
                Movie_RequestStop(data_02097e3c);
            }
            break;
        case 2: {
            BOOL ok = TRUE;
            if (!func_02035b90(data_0214b105, 7)) {
                ok = FALSE;
            }
            if (!func_02035b90(data_0208cca0, 7)) {
                ok = FALSE;
            }
            if (!func_02035b90(data_0208cc94, 7)) {
                ok = FALSE;
            }
            if (!func_0206facc()) {
                ok = FALSE;
            }
            if (!func_0206ead8()) {
                ok = FALSE;
            }
            if (ok) {
                func_0206faec();
                func_0206eaf8();
                CmdObj_Push(self, 0x26, 0);
                CmdObj_Done(self);
            }
            break;
        }
        }
        break;
    case 0x16:
        if (self->step == 0) {
            u16 id = self->unk_a4;
            func_0204b270(data_02149ef0, (s32)OVERLAY_2_ID, 0);
            data_ov000_021ccd5c = func_ov000_021857e0;
            data_ov000_021ccd58 = func_ov000_021857ec;
            data_ov000_021ccd60 = func_ov000_021857f8;
            func_ov002_021e8f04(id);
            self->step++;
            return 0;
        }
        {
        u16 mode = self->unk_a4;
        u16 t = self->unk_a8;
        if (mode == 0x5c) {
            if (t == 0x708) {
                if (data_ov002_021f0f9c->unk_04 >= 4) {
                    Obj02097e48 *p;
                    data_02097e4c->unk_5b = 1;
                    p = data_02097e48;
                    if (!(p->unk_80 == 0xffff && p->unk_7e == 0x88)) {
                        p->unk_80 = 0x88;
                        p->unk_7c = 0;
                    }
                    func_0204a2a8(data_02097e4c, 0, 0);
                    t = 1;
                }
            } else {
                t++;
            }
            self->unk_a8 = t;
        }
        }
        if (data_ov002_021f0f9c->unk_04 == 7) {
            ClearCallbacks();
            CmdObj_Push(self, 0x26, 0);
            CmdObj_Done(self);
        }
        break;
    case 0x17:
        if (self->step == 0) {
            self->step++;
            return 0;
        }
        if (!Busy17()) {
            CmdObj_Done(self);
        }
        return 1;
    case 0x18:
        if (self->step == 0) {
            self->step++;
            return 0;
        }
        if (Busy18(1)) {
            break;
        }
        CmdObj_Done(self);
        break;
    case 0x19:
        if (self->step == 0) {
            self->step++;
            return 0;
        }
        if (Busy18(0)) {
            break;
        }
        CmdObj_Done(self);
        break;
    case 0x1a:
        if (self->step == 0) {
            self->step++;
            return 0;
        }
        if (!Busy1a()) {
            CmdObj_Done(self);
        }
        return 1;
    }
    return 0;
}
}

}  // namespace m_Lo_021859c4

// ---- Stub_021860e0
namespace m_Stub_021860e0 {

extern "C" {

extern u8 data_ov006_021ec860[];
extern u8 data_ov015_02213320[];
u32 func_ov004_021cd050();
void func_ov015_021fa868();
int func_ov006_021cd0ac(void *a);
void func_ov006_021cd264(void *a);
BOOL func_ov015_021faba0(void *a);
void func_ov015_021fb088(void *a);

void func_ov000_021860e0(void) {
    func_ov015_021fa868();
}

void func_ov000_021860ec(void) {
    func_ov015_021faba0(*(void **)(data_ov015_02213320 + 0x0));
}

void func_ov000_02186104(void) {
    func_ov015_021fb088(*(void **)(data_ov015_02213320 + 0x0));
}

void func_ov000_0218611c(void) {
    func_ov004_021cd050();
}

void func_ov000_02186128(void) {
    func_ov006_021cd0ac(*(void **)(data_ov006_021ec860 + 0x0));
}

void func_ov000_02186140(void) {
    func_ov006_021cd264(*(void **)(data_ov006_021ec860 + 0x0));
}

}

}  // namespace m_Stub_021860e0

// ---- Cmd_02186158
namespace m_Cmd_02186158 {

typedef struct {
    u8 pad_00[0x70];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_02186158(CmdQueue *self, s32 arg) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x1b, arg);
}
}

}  // namespace m_Cmd_02186158

// ---- Cmd_02186204
namespace m_Cmd_02186204 {

typedef struct {
    u8 pad_00[0x70];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_02186204(CmdQueue *self, s32 arg) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x1c, arg);
}
}

}  // namespace m_Cmd_02186204

// ---- Lo_021862b0
namespace m_Lo_021862b0 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
} Ov015Obj02213320;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    u8 pad_08[0xc];
    s32 unk_14;
} Ov006Obj021ec860;

typedef struct {
    u8 pad_00[0x78];
    u16 unk_78;
} Dtcm02fe1534;

extern "C" {
extern Ov015Obj02213320 *data_ov015_02213320;
extern Ov006Obj021ec860 *data_ov006_021ec860;
extern Dtcm02fe1534 data_02fe1534;
extern u8 *data_02149ef0;
extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
// Overlay ids, defined by the linker script.
extern u8 OVERLAY_2_ID[];
extern u8 OVERLAY_6_ID[];
extern u8 OVERLAY_15_ID[];
void func_0204b270(void *p, s32 a, s32 b);
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_ov015_021fa77c(void);
void func_ov006_021ccf8c(void);
void func_ov000_021860e0(void);
void func_ov000_021860ec(void);
void func_ov000_02186104(void);
void func_ov000_0218611c(void);
void func_ov000_02186128(void);
void func_ov000_02186140(void);

static inline void ClearCallbacks(void) {
    if (data_ov000_021ccd5c != NULL) {
        data_ov000_021ccd5c();
    }
    data_ov000_021ccd5c = NULL;
    data_ov000_021ccd58 = NULL;
    data_ov000_021ccd60 = NULL;
}

s32 func_ov000_021862b0(CmdObj *self) {
    switch (self->unk_98) {
    case 0x1b:
        if (self->step == 0) {
            data_ov000_021ccd5c = func_ov000_021860e0;
            data_ov000_021ccd58 = func_ov000_021860ec;
            data_ov000_021ccd60 = func_ov000_02186104;
            func_0204b270(data_02149ef0, (s32)OVERLAY_2_ID, 0);
            func_0204b270(data_02149ef0, (s32)OVERLAY_15_ID, 1);
            func_ov015_021fa77c();
            data_ov015_02213320->unk_04 = self->unk_a4;
            self->step++;
            return 0;
        }
        if (data_ov015_02213320->unk_0c == 4) {
            data_02fe1534.unk_78 = data_ov015_02213320->unk_08;
            ClearCallbacks();
            CmdObj_Push(self, 0x26, 0);
            CmdObj_Done(self);
        }
        break;
    case 0x1c:
        if (self->step == 0) {
            data_ov000_021ccd5c = func_ov000_0218611c;
            data_ov000_021ccd58 = func_ov000_02186128;
            data_ov000_021ccd60 = func_ov000_02186140;
            func_0204b270(data_02149ef0, (s32)OVERLAY_6_ID, 0);
            func_ov006_021ccf8c();
            data_ov006_021ec860->unk_14 = self->unk_a4;
            self->step++;
            return 0;
        }
        if (data_ov006_021ec860->unk_04 == 5) {
            ClearCallbacks();
            if (self->unk_a4 == 0) {
                SndMgr_LoadHeapState(data_02097e4c, 1, 1);
                {
                    Obj02097e48 *p = data_02097e48;
                    if (p->flag) {
                        p->unk_06 = 0x8000;
                        p->unk_08 = 0x1e;
                        p->unk_02 = 0;
                    }
                }
                {
                    Obj02097e48 *p = data_02097e48;
                    p->unk_74 = 0x8000;
                    p->unk_70 = 0;
                }
                CmdObj_Push(self, 0x26, 2);
                CmdObj_Push(self, 0x21, 1);
            } else {
                CmdObj_Push(self, 0x26, 0);
            }
            CmdObj_Done(self);
        }
        break;
    }
    return 0;
}
}

}  // namespace m_Lo_021862b0

// ---- Stub_021865bc
namespace m_Stub_021865bc {

extern "C" {

extern u8 data_ov002_021f0f80[];
void func_ov002_021ccde4();
void func_ov002_021cceb4(void *a);
void func_ov002_021cd068(void *a);

void func_ov000_021865bc(void) {
    func_ov002_021ccde4();
}

void func_ov000_021865c8(void) {
    func_ov002_021cceb4(*(void **)(data_ov002_021f0f80 + 0x0));
}

void func_ov000_021865e0(void) {
    func_ov002_021cd068(*(void **)(data_ov002_021f0f80 + 0x0));
}

}

}  // namespace m_Stub_021865bc

// ---- Cmd_021865f8
namespace m_Cmd_021865f8 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_021865f8(CmdQueue *self) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x1e, 0);
}

}

}  // namespace m_Cmd_021865f8

// ---- Lo_021866d0
namespace m_Lo_021866d0 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u8 pad_00[0x118];
    void *unk_118;
    void *unk_11c;
} Mgr021ccd30;

typedef struct {
    VecFx32 base;
    u8 pad_0c[8];
    s16 x;
    s16 y;
    s16 z;
    u8 pad_1a[0xa];
} Spot021ccd6c;

typedef struct {
    u8 pad_00[0xb];
    u8 cur;
    u8 pad_0c[0xc];
    Spot021ccd6c *spots;
} Obj021ccd6c;

typedef struct {
    u8 pad_00[0x15];
    u8 unk_15;
    u8 pad_16[0xaf2];
    s32 unk_b08;
    u8 pad_b0c[4];
    VecFx32 unk_b10;
    u8 pad_b1c[0xc];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 6;
} Obj0219bf90;

typedef struct {
    u8 pad_00[0xac];
    u8 unk_ac;
    u8 pad_ad[0x1d];
    u8 unk_ca;
} CmdObj021866d0;

extern "C" {
extern void *data_02149efc;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
extern Mgr021ccd30 *data_ov000_021ccd30;
extern Obj021ccd6c *data_ov000_021ccd6c;
void func_020623e0(void);
void func_ov000_02182590(u8 *p);
u16 func_02061d54(s32 a);
void *MsgRes_GetString(void *p, s32 a);
void func_ov000_02172390(void *mgr, s32 a, void *b);
BOOL func_ov000_0216f674(Mgr021ccd30 *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
u16 func_02062834(void);
void func_02062500(u8 *p);
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
Obj0219bf90 *func_ov000_0219bf90(void);

static inline BOOL Busy0f(void) {
    BOOL r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 0xf)) {
        r = TRUE;
    } else if (m->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_0217060c(m->unk_11c);
    }
    return r;
}

s32 func_ov000_021866d0(CmdObj *self) {
    BOOL ready;
    switch (self->step) {
    case 0:
        self->step++;
        return 0;
    case 1:
        func_020623e0();
        ((CmdObj021866d0 *)self)->unk_ac = 1;
        func_ov000_02182590(&((CmdObj021866d0 *)self)->unk_ac);
        ready = TRUE;
        if (data_02149efc == NULL) {
            ready = FALSE;
        }
        if (ready) {
            CmdObj_Done(self);
            return 1;
        }
        func_ov000_02172390(data_ov000_021ccd30, 0, MsgRes_GetString(data_02149ef8, func_02061d54(0x19)));
        self->step++;
        break;
    case 2:
        if (!Busy0f()) {
            CmdObj_Done(self);
            if (!func_02062834()) {
                func_02062500(&((CmdObj021866d0 *)self)->unk_ca);
                SndMgr_LoadHeapState(data_02097e4c, 1, 1);
                {
                    Obj02097e48 *p = data_02097e48;
                    if (p->flag) {
                        p->unk_06 = 0x8000;
                        p->unk_08 = 0x1e;
                        p->unk_02 = 0;
                    }
                }
                {
                    Obj02097e48 *p = data_02097e48;
                    p->unk_74 = 0x8000;
                    p->unk_70 = 0;
                }
                CmdObj_Push(self, 0x26, 1);
                CmdObj_Push(self, 0x1e, 0);
            } else {
                Obj021ccd6c *g = data_ov000_021ccd6c;
                if (g->cur != 0xff) {
                    Spot021ccd6c *s = &g->spots[g->cur];
                    VecFx32 v;
                    Obj0219bf90 *obj;
                    v.x = s->x << 4;
                    v.y = s->y << 4;
                    v.z = s->z << 4;
                    VEC_Add(&v, &s->base, &v);
                    obj = func_ov000_0219bf90();
                    if (obj != NULL) {
                        obj->unk_15 = 3;
                        obj->unk_b28_0 = 2;
                        obj->unk_b10 = v;
                        obj->unk_b08 = 0x252;
                    }
                }
            }
            data_ov000_021ccd6c->cur = 0xff;
        }
        return 0;
    }
    return 1;
}
}

}  // namespace m_Lo_021866d0

// ---- Lo_02186a24
namespace m_Lo_02186a24 {

typedef struct {
    u32 b0 : 1;
} Ov002Obj021f0f80;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
} Ov008Obj021d0500;

extern "C" {
extern Ov002Obj021f0f80 *data_ov002_021f0f80;
extern Ov008Obj021d0500 *data_ov008_021d0500;
extern u8 *data_02149ef0;
// Overlay ids, defined by the linker script.
extern u8 OVERLAY_2_ID[];
extern u8 OVERLAY_8_ID[];
void func_0204b270(void *p, s32 a, s32 b);
void func_ov002_021ccda0(void);
void func_ov008_021cd448(void);
void func_ov000_021865bc(void);
void func_ov000_021865c8(void);
void func_ov000_021865e0(void);
void func_ov000_02186b74(void);
void func_ov000_02186b80(void);
void func_ov000_02186b98(void);

static inline BOOL Ov002Flag(Ov002Obj021f0f80 *p) {
    return p->b0 ? TRUE : FALSE;
}

static inline BOOL Ov002Done(void) {
    BOOL r;
    Ov002Obj021f0f80 *p = data_ov002_021f0f80;
    if (p != NULL) {
        r = Ov002Flag(p) ? TRUE : FALSE;
    } else {
        r = TRUE;
    }
    return r;
}

static inline void ClearCallbacks(void) {
    if (data_ov000_021ccd5c != NULL) {
        data_ov000_021ccd5c();
    }
    data_ov000_021ccd5c = NULL;
    data_ov000_021ccd58 = NULL;
    data_ov000_021ccd60 = NULL;
}

s32 func_ov000_02186a24(CmdObj *self) {
    switch (self->step) {
    case 0:
        data_ov000_021ccd5c = func_ov000_021865bc;
        data_ov000_021ccd58 = func_ov000_021865c8;
        data_ov000_021ccd60 = func_ov000_021865e0;
        func_0204b270(data_02149ef0, (s32)OVERLAY_2_ID, 0);
        func_ov002_021ccda0();
        self->step++;
        return 0;
    case 1:
        if (Ov002Done()) {
            ClearCallbacks();
            CmdObj_Done(self);
        }
        break;
    }
    return 0;
}

}

}  // namespace m_Lo_02186a24

// ---- Stub_02186b74
namespace m_Stub_02186b74 {

extern "C" {

extern u8 data_ov008_021d0500[];
void Ov008Mgr_Delete();
s32 func_ov008_021ce518(void *a);
void func_ov008_021cec20(void *a);

void func_ov000_02186b74(void) {
    Ov008Mgr_Delete();
}

void func_ov000_02186b80(void) {
    func_ov008_021ce518(*(void **)(data_ov008_021d0500 + 0x0));
}

void func_ov000_02186b98(void) {
    func_ov008_021cec20(*(void **)(data_ov008_021d0500 + 0x0));
}

}

}  // namespace m_Stub_02186b74

// ---- Cmd_02186bb0
namespace m_Cmd_02186bb0 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_02186bb0(CmdQueue *self) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x1f, 0);
}

}

}  // namespace m_Cmd_02186bb0

// ---- Lo_02186c88
namespace m_Lo_02186c88 {

typedef struct {
    u32 b0 : 1;
} Ov002Obj021f0f80;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
} Ov008Obj021d0500;

extern "C" {
extern Ov002Obj021f0f80 *data_ov002_021f0f80;
extern Ov008Obj021d0500 *data_ov008_021d0500;
extern u8 *data_02149ef0;
// Overlay ids, defined by the linker script.
extern u8 OVERLAY_2_ID[];
extern u8 OVERLAY_8_ID[];
void func_0204b270(void *p, s32 a, s32 b);
void func_ov002_021ccda0(void);
void func_ov008_021cd448(void);
void func_ov000_021865bc(void);
void func_ov000_021865c8(void);
void func_ov000_021865e0(void);
void func_ov000_02186b74(void);
void func_ov000_02186b80(void);
void func_ov000_02186b98(void);

static inline BOOL Ov002Flag(Ov002Obj021f0f80 *p) {
    return p->b0 ? TRUE : FALSE;
}

static inline BOOL Ov002Done(void) {
    BOOL r;
    Ov002Obj021f0f80 *p = data_ov002_021f0f80;
    if (p != NULL) {
        r = Ov002Flag(p) ? TRUE : FALSE;
    } else {
        r = TRUE;
    }
    return r;
}

static inline void ClearCallbacks(void) {
    if (data_ov000_021ccd5c != NULL) {
        data_ov000_021ccd5c();
    }
    data_ov000_021ccd5c = NULL;
    data_ov000_021ccd58 = NULL;
    data_ov000_021ccd60 = NULL;
}

s32 func_ov000_02186c88(CmdObj *self) {
    switch (self->step) {
    case 0:
        data_ov000_021ccd5c = func_ov000_02186b74;
        data_ov000_021ccd58 = func_ov000_02186b80;
        data_ov000_021ccd60 = func_ov000_02186b98;
        func_0204b270(data_02149ef0, (s32)OVERLAY_8_ID, 0);
        func_ov008_021cd448();
        self->step++;
        return 0;
    case 1:
        if ((data_ov008_021d0500->unk_04 == 0 ? TRUE : FALSE)) {
            ClearCallbacks();
            CmdObj_Done(self);
        }
        break;
    }
    return 0;
}
}

}  // namespace m_Lo_02186c88

// ---- Stub_02186dbc
namespace m_Stub_02186dbc {

extern "C" {

void func_ov000_02186dbc(void *self) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x20;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}

}  // namespace m_Stub_02186dbc

// ---- Lo_02186df4
namespace m_Lo_02186df4 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

s32 func_ov000_02186df4(CmdObj *self) {
    switch (self->step) {
    case 0:
        func_ov000_02180660(9, 0);
        self->step++;
        return 0;
    case 1:
        if (MsgDone()) {
            func_ov000_02180754();
            CmdObj_Done(self);
        }
        return 0;
    }
    return 1;
}

}

}  // namespace m_Lo_02186df4

// ---- Prot_02186ed4
namespace m_Prot_02186ed4 {

typedef BOOL (*ProtFn)(u32 addr, s32 arg);

typedef struct {
    u8 pad_00[0x22];
    u16 unk_22;
} Ov004Obj;

extern "C" {
extern u8 *data_02149ef0;
extern u32 data_ov004_021cf868;
extern ProtFn data_ov004_021cf86c[];
// Overlay ids, defined by the linker script.
extern u8 OVERLAY_4_ID[];
extern u8 OVERLAY_7_ID[];
void func_0204b270(void *p, s32 a, s32 b);
Ov004Obj *func_ov004_021cce88(void);
void func_ov004_021ccf10(void);
void func_ov002_021ccda0(void);
BOOL func_ov004_021ce2ec(u32 addr, s32 arg);
BOOL func_ov004_021ce374(u32 addr, s32 arg);
BOOL func_ov004_021ce3fc(u32 addr, s32 arg);
bool Ov003TaskVt_021f78f4_GetFlag6(u32 addr, s32 arg);

// Checksum of the first 0x1c words of a protected function, used to detect tampering.
static inline u32 ProtHash(const u32 *p) {
    u32 i;
    u32 h;
    for (i = 0x1c, h = 0; i != 0; i--, p++) {
        h ^= (*p >> i) | (*p << (32 - i));
    }
    return h;
}

void func_ov000_02186ed4(void) {
    Ov004Obj *obj;
    BOOL r;
    func_0204b270(data_02149ef0, (s32)OVERLAY_4_ID, 0);
    obj = func_ov004_021cce88();
    if (ProtHash((const u32 *)func_ov004_021ce2ec) == 0x786385f) {
        r = func_ov004_021ce2ec(0x2001000, 0);
    } else {
        r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001000, 0);
    }
    if (r) {
        obj->unk_22 = 1;
    } else {
        if (ProtHash((const u32 *)func_ov004_021ce374) == 0x786385f) {
            r = func_ov004_021ce374(0x2001800, 0);
        } else {
            r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001800, 0);
        }
        if (r) {
            obj->unk_22 = 2;
        } else {
            if (ProtHash((const u32 *)func_ov004_021ce3fc) == 0x786385f) {
                r = func_ov004_021ce3fc(0x2001c00, 0x2001e00);
            } else {
                r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001c00, 0x2001e00);
            }
            if (r) {
                obj->unk_22 = 3;
            } else {
                if (ProtHash((const u32 *)Ov003TaskVt_021f78f4_GetFlag6) == 0x786385f) {
                    r = Ov003TaskVt_021f78f4_GetFlag6(0x2002000, 0);
                } else {
                    r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2002000, 0);
                }
                if (r) {
                    obj->unk_22 = 4;
                }
            }
        }
    }
    func_ov004_021ccf10();
    func_0204b270(data_02149ef0, (s32)OVERLAY_7_ID, 0);
    func_ov002_021ccda0();
}
}

}  // namespace m_Prot_02186ed4

// ---- Stub_02187114
namespace m_Stub_02187114 {

extern "C" {

void *func_ov006_021ccdc8();
extern void *data_ov007_021cfc60;
s32 func_ov007_021cd270(void *p);
void func_ov007_021cf1d8(void *p);

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

static inline void Queue_Push(void *self, s32 cmd, s32 arg) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = cmd;
    ((s32 *)((u8 *)self + 0x50))[*index] = arg;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

void func_ov000_02187114(void) {
    func_ov006_021ccdc8();
}

void func_ov000_02187120(void) {
    func_ov007_021cd270(data_ov007_021cfc60);
}

void func_ov000_02187138(void) {
    func_ov007_021cf1d8(data_ov007_021cfc60);
}


void func_ov000_02187150(void *self, s32 arg) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    Queue_Push(self, 0x26, 2);
    Queue_Push(self, 0x21, arg);
}

}

}  // namespace m_Stub_02187114

// ---- Lo_0218722c
namespace m_Lo_0218722c {

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    s32 unk_08;
} Ov007Obj021cfc60;

extern "C" {
extern Ov007Obj021cfc60 *data_ov007_021cfc60;
void func_ov000_02187114(void);
void func_ov000_02187120(void);
void func_ov000_02187138(void);
void func_ov000_02186ed4(void);

s32 func_ov000_0218722c(CmdObj *self) {
    switch (self->step) {
    case 0:
        data_ov000_021ccd5c = func_ov000_02187114;
        data_ov000_021ccd58 = func_ov000_02187120;
        data_ov000_021ccd60 = func_ov000_02187138;
        func_ov000_02186ed4();
        data_ov007_021cfc60->unk_04 = self->unk_a4;
        self->step++;
        return 0;
    case 1:
        if ((data_ov007_021cfc60->unk_08 == 6 ? TRUE : FALSE)) {
            if (data_ov000_021ccd5c != NULL) {
                data_ov000_021ccd5c();
            }
            data_ov000_021ccd5c = NULL;
            data_ov000_021ccd58 = NULL;
            data_ov000_021ccd60 = NULL;
            CmdObj_Done(self);
        }
        break;
    }
    return 0;
}
}

}  // namespace m_Lo_0218722c

// ---- Stub_02187350
namespace m_Stub_02187350 {

extern "C" {

void func_ov002_021ee024();
void func_ov002_021ee1a8();
void func_ov002_021ee4d0();

void func_ov000_02187350(void) {
    func_ov002_021ee024();
}

void func_ov000_0218735c(void) {
    func_ov002_021ee1a8();
}

void func_ov000_02187368(void) {
    func_ov002_021ee4d0();
}

}

}  // namespace m_Stub_02187350

// ---- Cmd_02187374
namespace m_Cmd_02187374 {

typedef struct {
    u8 pad_00[0x70];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_02187374(CmdQueue *self, s32 arg) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x22, arg);
}
}

}  // namespace m_Cmd_02187374

// ---- Lo_02187420
namespace m_Lo_02187420 {

typedef struct {
    u8 pad_00[8];
    s32 unk_08;
} Ov002Obj021f0fa4;

extern "C" {
extern Ov002Obj021f0fa4 *data_ov002_021f0fa4;
extern u8 *data_02149ef0;
// Overlay id, defined by the linker script.
extern u8 OVERLAY_2_ID[];
extern u8 *data_02097e4c;
void func_0204b270(void *p, s32 a, s32 b);
void func_ov002_021edf98(u32 arg);
void func_ov000_02187350(void);
void func_ov000_0218735c(void);
void func_ov000_02187368(void);


s32 func_ov000_02187420(CmdObj *self) {
    switch (self->step) {
    case 0: {
        func_0204b270(data_02149ef0, (s32)OVERLAY_2_ID, 0);
        func_ov002_021edf98(self->unk_a4);
        data_ov000_021ccd5c = func_ov000_02187350;
        data_ov000_021ccd58 = func_ov000_0218735c;
        data_ov000_021ccd60 = func_ov000_02187368;
        self->step++;
        return 0;
    }
    case 1:
        if ((data_ov002_021f0fa4->unk_08 == 2 ? TRUE : FALSE)) {
            data_02097e4c[0x5b] = 0;
            if (data_ov000_021ccd5c != NULL) {
                data_ov000_021ccd5c();
            }
            data_ov000_021ccd5c = NULL;
            data_ov000_021ccd58 = NULL;
            data_ov000_021ccd60 = NULL;
            CmdObj_Done(self);
        }
        break;
    }
    return 0;
}
}

}  // namespace m_Lo_02187420

// ---- Stub_02187564
namespace m_Stub_02187564 {

extern "C" {

void func_ov000_0214b490();
BOOL func_ov000_0214b4fc();
void func_ov000_0214b520();

void func_ov000_02187564(void) {
    func_ov000_0214b490();
}

void func_ov000_02187570(void) {
    func_ov000_0214b4fc();
}

void func_ov000_0218757c(void) {
    func_ov000_0214b520();
}

}

}  // namespace m_Stub_02187564

// ---- Cmd_02187588
namespace m_Cmd_02187588 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_02187588(CmdQueue *self) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 2);
    CmdQueue_Push(self, 0x23, 0);
}

}

}  // namespace m_Cmd_02187588

// ---- Lo_02187660
namespace m_Lo_02187660 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

s32 func_ov000_02187660(CmdObj *self) {
    switch (self->step) {
    case 0:
        data_ov000_021ccd5c = func_ov000_02187564;
        data_ov000_021ccd58 = func_ov000_02187570;
        data_ov000_021ccd60 = func_ov000_0218757c;
        func_ov000_0214b438();
        self->step++;
        return 0;
    case 1:
        if (func_ov000_0214b540()) {
            if (data_ov000_021ccd5c != NULL) {
                data_ov000_021ccd5c();
            }
            data_ov000_021ccd5c = NULL;
            data_ov000_021ccd58 = NULL;
            data_ov000_021ccd60 = NULL;
            CmdObj_Done(self);
            SndMgr_LoadHeapState(data_02097e4c, 1, 1);
            {
                Obj02097e48 *p = data_02097e48;
                if (p->flag) {
                    p->unk_06 = 0x8000;
                    p->unk_08 = 0x1e;
                    p->unk_02 = 0;
                }
            }
            {
                Obj02097e48 *p = data_02097e48;
                p->unk_74 = 0x8000;
                p->unk_70 = 0;
            }
            CmdObj_Push(self, 0x26, 2);
            CmdObj_Push(self, 0x21, 2);
        }
        break;
    }
    return 0;
}

}

}  // namespace m_Lo_02187660

// ---- Cmd_0218781c
namespace m_Cmd_0218781c {

typedef struct {
    u8 pad_00[0x70];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);

void func_ov000_0218781c(CmdQueue *self, s32 arg) {
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x24, arg);
}
}

}  // namespace m_Cmd_0218781c

// ---- Cmd_021878c8
namespace m_Cmd_021878c8 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);


s32 func_ov000_021878c8(CmdObj *self) {
    if (data_ov000_021ccd5c != NULL) {
        data_ov000_021ccd5c();
    }
    data_ov000_021ccd5c = NULL;
    data_ov000_021ccd58 = 0;
    data_ov000_021ccd60 = 0;
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdObj_Push(self, 0x26, 2);
    CmdObj_Push(self, 0x21, 1);
    CmdObj_Done(self);
    return 0;
}

}

}  // namespace m_Cmd_021878c8

// ---- Stub_02187a20
namespace m_Stub_02187a20 {

extern "C" {

void func_ov000_02187a20(void *self, s32 arg) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x25;
    ((s32 *)((u8 *)self + 0x50))[*index] = arg;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}

}  // namespace m_Stub_02187a20

// ---- Lo_02187a58
namespace m_Lo_02187a58 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL StageRes_IsAllLoaded(void *p);
BOOL func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
s32 func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *MsgRes_GetString(void *p, s32 a);
u16 func_02061d54(s32 a);
u16 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL ActorMgr_IsReady(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL SndMgr_IsLoadDone(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

s32 func_ov000_02187a58(CmdObj *self) {
    switch (self->step) {
    case 0:
        self->step++;
        return 0;
    case 1:
        if (!func_02046e28(data_02097e44)) {
            func_02049678(data_02097e4c, 4, self->unk_a4, -1);
            self->step++;
        }
        break;
    case 2:
        if (SndMgr_IsLoadDone(data_02097e4c)) {
            CmdObj_Done(self);
        }
        break;
    }
    return 1;
}

}

}  // namespace m_Lo_02187a58

// ---- Stub_02187b50
namespace m_Stub_02187b50 {

extern "C" {

void func_ov000_02187b50(void *self) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x26;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}

}  // namespace m_Stub_02187b50

// ---- Lo_02187b88
namespace m_Lo_02187b88 {

typedef struct {
    u8 c[3];
} Id3;

typedef struct {
    u8 b0 : 2;
    u8 mode : 2;
    u8 b4 : 4;
} Bits0e;

class CmdEx : public CmdObj {
public:
    u8 unk_ac;
    u8 pad_ad[3];
    VObj *unk_b0;
    u16 unk_b4;
    u8 pad_b6[0x14];
    Id3 unk_ca;
    Id3 unk_cd;
    Id3 unk_d0;
    u8 pad_d3[0xb9];
    u8 unk_18c;
    u8 unk_18d;
    u8 unk_18e;
    u8 unk_18f;
};

#define BITS0E(self) (*(Bits0e *)((u8 *)(self) + 0xe))

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
} Obj02097e48;

typedef struct {
    void *vtable;
    u32 unk_04;
} Task;

typedef struct {
    u8 pad_00[0x28];
    s32 unk_28;
    u8 pad_2c[4];
    s32 unk_30;
} Task118;

typedef struct {
    u8 pad_00[0x7c];
    void *unk_7c;
} Task11c;

typedef struct {
    u8 pad_00[0x118];
    Task118 *unk_118;
    Task11c *unk_11c;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0x46];
    u16 unk_46;
    u16 unk_48;
    u16 unk_4a;
} Dtcm02fe1534;

extern "C" {
extern Mgr021ccd30 *data_ov000_021ccd30;
extern s32 data_02097d78[];
extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb940[];
extern u8 data_ov000_021cb920[];
extern void *data_ov000_021ccd68;
extern Dtcm02fe1534 data_02fe1534;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a420;
extern void *data_ov000_021ccd6c;
extern void *data_ov000_021ccd64;
extern void *data_02149f0c;
extern void *data_02149ef0;

void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void *Heap_Alloc(u32 size);
void func_ov000_0216f144(Task *self);
void func_ov000_0216faac(Task *self);
void func_ov000_0216f828(Task *self);
void *func_ov000_0216f398(Mgr021ccd30 *mgr, Task *task, s32 a, Mgr021ccd30 *b);
void ActorMgr_ClearGroup(void *p, s32 a);
void func_0204aa10(void *p);
void func_ov000_0216bcbc(void *p);
void func_ov000_021645a4(s32 a);
void EffectMgr_FreeAll(void *p);
void func_ov000_021b53f4(void *p);
void func_ov000_0218be9c(void *p);
void ActorMgr_DestroyAll(void *p);
void MessageQueue_FreeBuffer(Mgr021ccd30 *mgr, void *task);
void func_0206222c(void);
void func_ov000_021819a4(u8 *p);
void func_0205b1b4(void);
void func_02059974(void *p);
void func_0204b270(void *p, s32 a, s32 b);

static inline BOOL IsIdle(s32 i) {
    return data_02097d78[3] == 0 && data_02097d78[i] == 0;
}

static inline BOOL IsMode4(s32 i) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[i] == 4;
    }
    return r;
}

static inline s32 TaskVal(Task118 *t) {
    return t->unk_28 != 1 ? 0 : t->unk_30;
}

static inline BOOL TaskHasVal(Task118 *t) {
    return (TaskVal(t) != 0 ? TRUE : FALSE) ? TRUE : FALSE;
}

s32 func_ov000_02187b88(CmdEx *self) {
    u16 mode = self->unk_a4;
    switch (mode) {
    case 0:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (IsIdle(0)) {
                func_0203c9e8(0x3f, -1);
                func_0203cc58(0, 2, -1);
            }
            self->step++;
            break;
        case 2:
            if (IsMode4(0)) {
                Mgr021ccd30 *mgr = data_ov000_021ccd30;
                if (mgr->unk_11c == NULL) {
                    Task *task = (Task *)Heap_Alloc(0x80);
                    if (task != NULL) {
                        task->vtable = data_ov000_021cb6d0;
                        func_ov000_0216f144(task);
                        task->vtable = data_ov000_021cb940;
                        func_ov000_0216faac(task);
                    }
                    mgr->unk_11c = (Task11c *)task;
                    func_ov000_0216f398(mgr, task, 0x10000, mgr);
                    ((Task *)mgr->unk_11c)->unk_04 |= 0x10;
                }
                mgr = data_ov000_021ccd30;
                if (mgr->unk_118 == NULL) {
                    Task *task = (Task *)Heap_Alloc(0x34);
                    if (task != NULL) {
                        task->vtable = data_ov000_021cb6d0;
                        func_ov000_0216f144(task);
                        task->vtable = data_ov000_021cb920;
                        func_ov000_0216f828(task);
                    }
                    mgr->unk_118 = (Task118 *)task;
                    func_ov000_0216f398(mgr, task, 0x10000, mgr);
                    ((Task *)mgr->unk_118)->unk_04 |= 0x10;
                }
                CmdObj_Done(self);
            }
            break;
        }
        break;
    case 1:
    case 2:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (IsIdle(0)) {
                func_0203c9e8(0x3f, 0);
                func_0203cc58(0x1e000, 2, 0);
            }
            if (IsIdle(1)) {
                func_0203c9e8(0x3f, 1);
                func_0203cc58(0x1e000, 2, 1);
            }
            self->step++;
            return 1;
        case 2:
            if (!IsMode4(0)) {
                return 1;
            }
            if (!IsMode4(1)) {
                return 1;
            }
            self->step++;
            break;
        case 3: {
            Id3 id;
            id.c[0] = 0xff;
            id.c[1] = 0xff;
            id.c[2] = 0xff;
            self->unk_cd = id;
            ActorMgr_ClearGroup(data_ov000_021ccd68, 0xf000);
            data_02fe1534.unk_46 = 0xffff;
            data_02fe1534.unk_48 = 0xffff;
            data_02fe1534.unk_4a = 0xffff;
            HEAP_DELETE_VOBJ(self->unk_b0);
            self->unk_b4 = 0xffff;
            func_0204aa10(data_02097e48);
            data_02097e48->b2 = 0;
            self->unk_d0 = self->unk_ca;
            self->unk_ca = self->unk_cd;
            BITS0E(self).mode = 2;
            if (data_ov000_021ccd30->unk_11c != NULL && data_ov000_021ccd30->unk_11c->unk_7c != NULL) {
                func_ov000_0216bcbc(data_ov000_021ccd30->unk_11c->unk_7c);
            }
            {
                Mgr021ccd30 *mgr = data_ov000_021ccd30;
                BOOL has;
                if (mgr->unk_118 == NULL) {
                    has = FALSE;
                } else {
                    has = TaskHasVal(mgr->unk_118);
                }
                if (has) {
                    func_ov000_021645a4(TaskVal(mgr->unk_118));
                }
            }
            self->unk_18c = 0;
            self->unk_18d = 0;
            self->unk_18e = 0;
            self->unk_18f = 0;
            EffectMgr_FreeAll(data_0214a420);
            func_ov000_021b53f4(data_ov000_021ccd6c);
            func_ov000_0218be9c(data_ov000_021ccd64);
            ActorMgr_DestroyAll(data_ov000_021ccd68);
            {
                Mgr021ccd30 *mgr = data_ov000_021ccd30;
                MessageQueue_FreeBuffer(mgr, mgr->unk_11c);
                mgr->unk_11c = NULL;
            }
            {
                Mgr021ccd30 *mgr = data_ov000_021ccd30;
                MessageQueue_FreeBuffer(mgr, mgr->unk_118);
                mgr->unk_118 = NULL;
            }
            if (mode == 2) {
                func_0206222c();
                func_ov000_021819a4(&self->unk_ac);
                func_0205b1b4();
                func_02059974(data_02149f0c);
                func_0204b270(data_02149ef0, -1, 0);
            }
            CmdObj_Done(self);
            return 1;
        }
        }
        break;
    }
    return 0;
}
}

}  // namespace m_Lo_02187b88
#undef BITS0E

// ---- Stub_02188140
namespace m_Stub_02188140 {

static inline void CmdQueue_Push2(CmdQueue *q, s32 kind, s32 lo, u16 hi) {
    q->kinds[q->index] = kind;
    q->args[q->index] = lo | (hi << 16);
    if (++q->index >= 0x10) {
        q->index = 0;
    }
}

extern "C" {

void func_ov000_02188140(CmdQueue *self, s32 a, s32 b, s32 c) {
    u16 v;
    if (a == 0) {
        a = 1;
    }
    v = (b & 0xff) | ((c & 0xf) << 8);
    CmdQueue_Push2(self, 0x27, a, v);
}

}

}  // namespace m_Stub_02188140

// ---- Lo_0218819c
namespace m_Lo_0218819c {

typedef struct {
    u8 pad_00[0xb24];
    u32 unk_b24_0 : 1;
} Obj0219bf90;

typedef struct {
    u8 pad_00[6];
    u16 unk_06;
} Obj0205b31c;

typedef struct {
    u8 pad_00[0x12];
    u16 unk_12;
} Pad02097dc8;

extern "C" {
extern s32 data_02097d78[];
extern Pad02097dc8 *data_02097dc8;
Obj0219bf90 *func_ov000_0219bf90(void);
Obj0205b31c *func_0205b31c(void);

static inline BOOL IsMode0(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL IsMode4(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 4;
    }
    return r;
}

s32 func_ov000_0218819c(CmdObj *self) {
    u16 arg = self->unk_a6;
    u16 kind = arg & 0xff;
    u8 mode = (arg >> 8) & 0xf;
    BOOL done = FALSE;
    Obj0219bf90 *obj;
    u16 count = self->unk_a4;
    BOOL ret;
    switch (self->step) {
    case 0:
        self->step++;
        return 0;
    case 1:
        ret = (mode ^ 1) != 0;
        if (kind != 2) {
            if (!IsMode0() && !IsMode4()) {
                return ret;
            }
        } else {
            kind = 0;
        }
        if (kind == 0xff) {
            if (data_02097dc8->unk_12 & 1) {
                CmdObj_Done(self);
                CmdObj_Push(self, 0x28, 0);
            }
        } else {
            obj = func_ov000_0219bf90();
            Obj0205b31c *p = func_0205b31c();
            if ((p != NULL && p->unk_06 == 0x78) || (obj != NULL && obj->unk_b24_0)) {
                done = TRUE;
            } else if (count != 0xffff) {
                if (--count == 0) {
                    done = TRUE;
                }
            }
            if (done || ((kind == 1 || kind == 0xb) && (data_02097dc8->unk_12 & 3))) {
                CmdObj_Done(self);
                if (kind >= 10) {
                    CmdObj_Push(self, 0x28, 0);
                }
            }
            self->unk_a4 = count;
        }
        return ret;
    }
    return done;
}
}

}  // namespace m_Lo_0218819c

// ---- Lo_02188438
namespace m_Lo_02188438 {

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u8 pad_00[0x118];
    void *unk_118;
} Mgr021ccd30;

extern "C" {
extern s32 data_02097d78[];
extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
extern Mgr021ccd30 *data_ov000_021ccd30;
void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void SndMgr_LoadHeapState(void *p, s32 a, s32 b);
void func_ov000_0216f844(void *p, s32 a);

static inline BOOL IsMode0(void) {
    return data_02097d78[3] == 0 && data_02097d78[0] == 0;
}

static inline BOOL IsMode4(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 4;
    }
    return r;
}

s32 func_ov000_02188438(CmdObj *self) {
    switch (self->step) {
    case 0:
        if (IsMode0()) {
            func_0203c9e8(0x3f, -1);
            func_0203cc58(0x1e000, 1, -1);
            if (data_ov000_021ccd30->unk_118 != NULL) {
                func_ov000_0216f844(data_ov000_021ccd30->unk_118, 0);
            }
        }
        self->step++;
        return 0;
    case 1:
        if (IsMode4()) {
            CmdObj_Done(self);
            SndMgr_LoadHeapState(data_02097e4c, 1, 1);
            {
                Obj02097e48 *p = data_02097e48;
                if (p->flag) {
                    p->unk_06 = 0x8000;
                    p->unk_08 = 0x1e;
                    p->unk_02 = 0;
                }
            }
            {
                Obj02097e48 *p = data_02097e48;
                p->unk_74 = 0x8000;
                p->unk_70 = 0;
            }
            CmdObj_Push(self, 0x26, 2);
            CmdObj_Push(self, 0x21, 0);
            return 0;
        }
        return 1;
    }
    return 0;
}
}

}  // namespace m_Lo_02188438

// ---- Stub_02188634
namespace m_Stub_02188634 {

typedef struct {
    u8 unk_00[0x10];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 unk_90;
    s32 index;
} CmdQueue;

extern "C" {

void func_ov000_02188634(CmdQueue *self, s32 a, s32 b) {
    self->kinds[self->index] = 0x29;
    self->args[self->index] = a | (b << 16);
    if (++self->index >= 0x10) {
        self->index = 0;
    }
}

}

}  // namespace m_Stub_02188634

// ---- Stub_02188670
namespace m_Stub_02188670 {

extern "C" {

void func_ov000_021764c4();

void func_ov000_02188670(void) {
    func_ov000_021764c4();
}

}

#ifdef NONMATCHING
// Status (round drA): func_ov000_0218867c is 45 / 32 (raw / register-masked, dsi/1.3 with the project flags); this
// is the best clean draft. Blocker: case 1 hoists data_02fe1534 to the case head (move-constant-loads 17 -> 12,
// refused in the ROM) and the entry order of arg / 0x64. History: docs/MATCHING.md rounds rtF, qpG, raF, raH, mlA,
// cvA (search for the address); the full list is docs/UNMATCHED.md.
// func_ov000_0218867c: 28 raw / 12 register-masked, 22 / 6 with pool offsets masked (round rtF).
// Real one-argument signature (called through the CmdObj step table with only self). The
// break-at-zero check in the case-1 loop and the identical vfunc_38(1) arms are in the target
// (cmp r7, #0 with r7 starting at 0; beq / b to the same call). The 1 / 1U spelling keeps the two
// calls from being merged. Left: case 1 keeps data_02fe1534 for after the loop in a fresh scratch
// register; ours hoists it to the case head (move-constant-loads step 17->12 at pressure 10, the
// target refuses it, so its loop has one more live value), and the entry order of arg / 0x64.
// Round qpG: no gain from a Data0218867c pointer local (it also refuses the 0x64 move: 48 aligned), g_1 at the
// top of case 1 (38), five spellings of the g_1 ternary, or normal-mode scheduling of any one block (70 tried).
// Forcing only the 17->12 refusal gives 35 aligned, so the missing live value is not the whole story.
// Round bgQ2: data_02fe1534 as its struct type (Shared02fe1534, .unk_80) with direct stores and no g_n
// locals is 281: the address is then CSEd across the whole switch.

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef void (*Cb0218867c)(void);

extern "C" {

extern u8 data_02fe1534[];
extern void *data_02fe152c;
extern void *data_ov000_021ccd68;
BOOL func_ov000_0214be28(u16 id);
void func_ov000_021763c8(void);
u32 func_ov000_02176538(void);
void func_ov000_02176560(void);
void func_ov000_02176590(u16 id);
BOOL func_0206f954(void);
void *func_0205976c(void *res, u32 idx);
u32 func_0205975c(void *res, u32 idx);
u16 func_02059544(void *res, void *block, void *entries, int packed, u32 id);
VObj *ActorMgr_GetActor(void *mgr, u16 id);
void func_0206228c(void);
Robo021ca458 *func_ov000_0219bf90(void);
s32 FX_Div(s32 a, s32 b);

static inline BOOL Busy0218867c(VObj *v) {
    return LFLD(u8, v, 0x5a) ? TRUE : FALSE;
}

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} MapId0218867c;

typedef struct {
    u8 unk_00[0x772];
    MapId0218867c map;
} Plyr0218867c;

static inline VObj *Find0218867c(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
}

s32 func_ov000_0218867c(CmdObj *self) {
    s32 hit;
    s32 miss;
    u16 i;
    void *blk;
    void *ents;
    u32 n_1;
    u16 kind = self->unk_a4;
    u16 arg = self->unk_a6;
    u32 idx;
    s32 c1;
    s32 c2;
    switch (kind) {
    case 0: {
        u8 *g_0 = data_02fe1534;
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            LFLD(u16, g_0, 0x80) = func_ov000_0214be28(arg);
            self->step = 100;
            break;
        }
        break;
    }
    case 1:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1: {
            u16 n_0 = 0;
            VObj *p = LFLD(VObj *, ((u8 *)data_ov000_021ccd54), 0xbc);
            for (; p != NULL; p = LFLD(VObj *, p, 0xd4)) {
                if (n_0 == 0) {
                    break;
                }
                if (p->vfunc_34()) {
                    n_0++;
                }
            }
            {
                u8 *g_1 = data_02fe1534;
                LFLD(u16, g_1, 0x80) = p != NULL ? 1 : 0;
            }
            self->step = 100;
            break;
        }
        }
        break;
    case 2: {
        u8 *g_2 = data_02fe1534;
        switch (self->step) {
        case 0:
            func_ov000_021763c8();
            data_ov000_021ccd5c = func_ov000_02188670;
            self->step++;
            return 0;
        case 1:
            if (func_ov000_02176538()) {
                func_ov000_02176560();
                func_ov000_02176590(arg);
                LFLD(u16, g_2, 0x80) = func_0206f954();
                self->step = 100;
            }
            break;
        }
        break;
    }
    case 5:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            self->step = 0x5a;
            idx = 8;
            c1 = 0x101;
            c2 = 0x201;
            break;
        }
        break;
    case 6:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            idx = 0xb;
            c1 = 0x101;
            self->step = 0x5a;
            c2 = 0x201;
            break;
        }
        break;
    case 4: {
        u8 *g_3 = data_02fe1534;
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1: {
            Robo021ca458 *pl_0 = func_ov000_0219bf90();
            LFLD(u16, g_3, 0x80) = 0;
            if (pl_0 != NULL) {
                const u8 *y = (const u8 *)&((Plyr0218867c *)pl_0)->map;
                const u16 *x = (u16 *)(g_3 + 0x46);
                if (y[0] == x[0] && y[1] == x[1] && y[2] == x[2]) {
                    LFLD(u16, g_3, 0x80) = 1;
                }
            }
            self->step = 100;
            break;
        }
        }
        break;
    }
    case 7: {
        Robo021ca458 *pl_1 = func_ov000_0219bf90();
        if (pl_1 != NULL) {
            VObj *o_0 = Find0218867c(pl_1->unk_b1c);
            if (o_0 != NULL) {
                o_0->vfunc_08();
            }
        }
        self->step = 100;
        break;
    }
    case 8: {
        VObj *o_1 = Find0218867c(arg);
        if (o_1 != NULL) {
            o_1->vfunc_08();
        }
        self->step = 100;
        break;
    }
    }
    if (self->step == 0x5a) {
        blk = LFLD(u8 *, data_02fe152c, 0x4c) + 0x10 + idx * 0x20;
        ents = func_0205976c(data_02fe152c, idx);
        n_1 = func_0205975c(data_02fe152c, idx);
        hit = 0;
        miss = 0;
        for (i = 0; i < n_1; i++) {
            if (func_02059544(data_02fe152c, blk, ents, c2, i) == 0) {
                if (func_02059544(data_02fe152c, blk, ents, c1, i) != 0) {
                    hit++;
                }
            } else {
                miss++;
            }
        }
        LFLD(u16, data_02fe1534, 0x80) = (s32)(((s64)FX_Div(hit << 12, (n_1 - miss) << 12) * 0x64000 + 0x800) >> 12) >> 12;
        self->step = 100;
    }
    if (self->step == 100) {
        u8 *o_2;
        if (data_ov000_021ccd5c != NULL) {
            data_ov000_021ccd5c();
        }
        data_ov000_021ccd5c = NULL;
        data_ov000_021ccd58 = 0;
        data_ov000_021ccd60 = 0;
        o_2 = (u8 *)data_ov000_021ccd54;
        if (LFLD(VObj *, o_2, 0xc0) != NULL) {
            if (o_2[0xc4]) {
                LFLD(VObj *, o_2, 0xc0)->vfunc_38(1);
            } else {
                LFLD(VObj *, o_2, 0xc0)->vfunc_38(1U);
            }
            if (!Busy0218867c(LFLD(VObj *, o_2, 0xc0))) {
                LFLD(VObj *, o_2, 0xc0) = NULL;
                o_2[0xc4] = 0;
            }
            if (LFLD(VObj *, o_2, 0xc0) == NULL) {
                func_0206228c();
            }
        }
        CmdObj_Done(self);
        return 1;
    }
    return 1;
}

}
#endif

}  // namespace m_Stub_02188670
