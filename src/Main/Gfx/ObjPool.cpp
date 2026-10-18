#include "Main/Gfx/ObjPool.h"

extern "C" {

void func_0205983c(void) {
    ObjPool *pool;
    if (data_02149efc.pool != NULL) {
        return;
    }
    pool = (ObjPool *)func_0203dd9c(sizeof(ObjPool));
    if (pool != NULL) {
        ObjPool_Init(pool);
    }
    data_02149efc.pool = pool;
}

void func_020598a8(void) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        ObjPool *p = data_02149efc.pool;
        if (p != NULL) {
            if (p != NULL) {
                ObjPool_Reset(p);
                func_0203de1c(p);
            }
            data_02149efc.pool = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

void func_02059974(ObjPool *pool) {
    ObjPool_Reset(pool);
}

void func_020599f4(ObjPool *pool, ObjPoolEntry *entry) {
    switch (entry->kind) {
    case 3: {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            void *p = entry->obj;
            if (p != NULL) {
                if (p != NULL) {
                    func_0203f2b8(p);
                    func_0203de1c(p);
                }
                entry->obj = NULL;
            }
        }
        data_02097dd0->cur = saved;
        break;
    }
    case 4: {
        void *saved;
        if (((void **)entry->obj)[0x88 / 4] != NULL) {
            func_0203df0c(((void **)entry->obj)[0x88 / 4]);
        }
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            void *p = entry->obj;
            if (p != NULL) {
                if (p != NULL) {
                    func_0203f864(p);
                    func_0203de1c(p);
                }
                entry->obj = NULL;
            }
        }
        data_02097dd0->cur = saved;
        break;
    }
    }
    if (pool->head == entry) {
        pool->head = entry->next;
    } else {
        ObjPoolEntry *p = pool->head;
        while (p->next != entry) {
            p = p->next;
        }
        p->next = entry->next;
    }
    entry->next = NULL;
    entry->active = 0;
    entry->kind = 0;
    entry->unk_04 = 0;
    entry->unk_06 = 0xffff;
}

ObjPoolEntry *func_02059b14(ObjPool *pool, u16 id, ObjPoolParam *param) {
    ObjPoolEntry *e = pool->entries;
    int i;
    for (i = 0; i < 16; i++, e++) {
        if (e->kind == 0) {
            break;
        }
    }
    e->active = 1;
    e->id = id;
    e->unk_04 = 0;
    e->unk_06 = 0xffff;
    if (param != NULL) {
        e->x = param->x << 4;
        e->y = param->y << 4;
        e->z = param->z << 4;
        BOOL flag = FALSE;
        if (param->ry != 0 || param->rz != 0) {
            flag = TRUE;
        }
        if (flag) {
            e->kind = 2;
            e->unk_18 = ObjPool_FxMul(param->r << 4, 0x800);
            e->unk_1c = ObjPool_FxMul(param->ry << 4, 0x800);
            e->unk_20 = ObjPool_FxMul(param->rz << 4, 0x800);
        } else {
            s32 r;
            e->kind = 1;
            r = param->r << 4;
            e->unk_18 = r;
            e->unk_1c = ObjPool_FxMul(r, r);
            e->unk_20 = 0;
        }
    }
    e->r = data_02fe1534.r;
    e->g = data_02fe1534.g;
    e->b = data_02fe1534.b;
    if (pool->head == NULL) {
        e->next = NULL;
    } else {
        e->next = pool->head;
    }
    pool->head = e;
    return e;
}

}
