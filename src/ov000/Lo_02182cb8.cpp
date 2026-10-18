#include "ov000/CmdObj.h"
#include "ov000/VObj.h"

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
    u8 pad_00[4];
    CmdEx *obj;
} State021ccd50;

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
    s32 x, y, z;
} Vec3;

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
    Vec3 unk_13c;
    u8 pad_148[0xc];
    u16 unk_154;
} Obj0214a424;

typedef struct {
    u8 pad_00[0x14];
    s32 unk_14;
} Obj02097dd0;

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
extern State021ccd50 data_ov000_021ccd50;
extern Obj0214a424 *data_0214a424;
extern VObj *data_02fe152c;
extern Mgr021ccd30 *data_ov000_021ccd30;
extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb940[];
extern u8 data_ov000_021cb920[];
extern Obj02097e48 *data_02097e48;
extern Obj02097dd0 *data_02097dd0;
extern Dtcm02fe1534 data_02fe1534;
extern void *data_02097e4c;
extern Obj021ccd6c *data_ov000_021ccd6c;

void func_02058fe4(void);
void func_02058f2c(void);
void *func_0203dd9c(u32 size);
void func_ov000_0216f144(Task *self);
void func_ov000_0216faac(Task *self);
void func_ov000_0216f828(Task *self);
void func_ov000_0216f398(Mgr021ccd30 *mgr, Task *task, s32 a, Mgr021ccd30 *b);
void func_0206222c(void);
void func_0206cadc(Obj0214a424 *p);
void func_0206c4c4(Obj0214a424 *p);
void func_0206ca44(Obj0214a424 *p);
void func_0206c994(Obj0214a424 *p);
void func_ov000_02181f54(u8 *p, s32 a, s32 b, s32 c, s32 d, s32 e);
void func_02049564(void *p, s32 a, s32 b);
void func_020626d4(Vec3 *v, u16 a);
BOOL func_0205a9c8(VObj *p);
void func_0205aa30(VObj *p);
BOOL func_ov000_021820bc(u8 *p, s32 a);

static inline BOOL HasObj(void) {
    return data_02fe152c != NULL ? TRUE : FALSE;
}

static inline BOOL NotFlag(Obj0214a424 *p) {
    return p->f18 ? FALSE : TRUE;
}

static inline void Warp(const Id3 *id, s32 arg) {
    data_02097e48->b1 = 1;
    CmdObj_Push(data_ov000_021ccd50.obj, 9, arg);
    if (id != NULL) {
        data_ov000_021ccd50.obj->unk_cd = *id;
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
            Task *task = (Task *)func_0203dd9c(0x80);
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
            Task *task = (Task *)func_0203dd9c(0x34);
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
                data_02097dd0->unk_14 = data_0214a424->unk_04;
            } else {
                func_0206c4c4(data_0214a424);
                data_0214a424->unk_08 = self->unk_a6;
                data_02097dd0->unk_14 = 0;
            }
            data_02fe1534.unk_02 = 0;
            data_02fe1534.unk_04 = 0;
            {
                CmdEx *obj = data_ov000_021ccd50.obj;
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
                data_02097dd0->unk_14 = data_0214a424->unk_04;
                kind = data_0214a424->unk_09;
            }
            if (kind == 1) {
                Id3 id;
                id.c[0] = 0xfe;
                id.c[1] = 0xfe;
                id.c[2] = 0xfe;
                Warp(&id, 0);
            } else if (kind == 0) {
                func_02049564(data_02097e4c, 1, 1);
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
                    Vec3 v;
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
        } else if (!func_0205a9c8(self->unk_b8)) {
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
