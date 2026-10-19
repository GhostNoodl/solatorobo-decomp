#include "Main/Res/StageRes.h"

extern "C" {

void func_0205a69c(void) {
}

void func_0205a6a0(StageRes *res) {
    res->type = 0;
    res->data = NULL;
    res->size = 0;
    res->unk_54 = 0;
    res->unk_58 = 0;
    res->unk_59 = 0;
    res->unk_5a = 0;
    res->unk_5b = 0;
    res->value = 0;
    res->condCount = 0;
    res->opCount = 0;
    res->unk_b2 = 0;
    res->varId = NULL;
    res->op = 0;
    res->sub = NULL;
    res->posEv = NULL;
}

void func_0205a6e8(StageRes *res) {
    s32 end;
    s32 i;
    i = data_02149efc.slotStart;
    end = data_02149efc.slotEnd;
    if (i != end) {
        do {
            if (data_02149f18[i].res == res) {
                data_02149f18[i].res = NULL;
            }
            i++;
            if (i >= 0x40) {
                i = 0;
            }
        } while (i != end);
    }
    func_02038520(res);
    if (res->posEv != NULL) {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            PosEvRes *p = res->posEv;
            if (p != NULL) {
                if (p != NULL) {
                    p->DeletingDtor();
                }
                res->posEv = NULL;
            }
        }
        data_02097dd0->cur = saved;
    }
    if (res->sub != NULL) {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            DataRes *p = res->sub;
            if (p != NULL) {
                if (p != NULL) {
                    p->DeletingDtor();
                }
                res->sub = NULL;
            }
        }
        data_02097dd0->cur = saved;
    }
    func_0205a6a0(res);
}

PosEvRes *func_0205a7f8(PosEvRes *res) {
    res->type = 0;
    res->posCount = 0;
    res->pos = NULL;
    res->evCount = 0;
    res->ev = NULL;
    *(const u32 **)res = data_0208b318;
    res->Unload();
    func_0203de1c(res);
    return res;
}

static inline void StageRes_OpenData(PosEvRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

void func_0205a840(StageRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    func_02038b88(res, arc, file);
    if (res->sub == NULL) {
        DataRes *sub;
        STD_CopyString(file, name);
        STD_CopyString(STD_SearchString(file, data_0208be17), data_0208be19);
        sub = (DataRes *)func_0203dd9c(0x58);
        if (sub != NULL) {
            *(const u32 **)sub = data_0208b318;
            sub->Clear();
            *(const u32 **)sub = data_0208ba30;
            func_0204bfcc(sub);
        }
        res->sub = sub;
        func_0204bfe4(sub, arcName, file);
    }
    if (res->posEv == NULL) {
        PosEvRes *posEv;
        STD_CopyString(file, name);
        STD_CopyString(STD_SearchString(file, data_0208be17), data_0208be20);
        posEv = (PosEvRes *)func_0203dd9c(0x5c);
        if (posEv != NULL) {
            *(const u32 **)posEv = data_0208b318;
            posEv->Clear();
            *(const u32 **)posEv = data_0208bed4;
            posEv->type = 0;
            posEv->posCount = 0;
            posEv->pos = NULL;
            posEv->evCount = 0;
            posEv->ev = NULL;
        }
        res->posEv = posEv;
        StageRes_OpenData(posEv, arcName, file);
    }
}

BOOL func_0205a9c8(StageRes *res) {
    BOOL loaded = TRUE;
    if (!res->IsLoaded()) {
        loaded = FALSE;
    }
    if (res->sub != NULL && !res->sub->IsLoaded()) {
        loaded = FALSE;
    }
    if (res->posEv != NULL && !res->posEv->IsLoaded()) {
        loaded = FALSE;
    }
    return loaded;
}

BOOL func_0205aa30(StageRes *res) {
    u8 *hdr;
    if (res->loaded) {
        return TRUE;
    }
    hdr = *(u8 **)res->GetData();
    res->data = hdr + *(u32 *)(hdr + 0xc);
    res->size = *(u32 *)(hdr + 8);
    if (res->sub != NULL) {
        func_0204c030(res->sub);
    }
    if (res->posEv != NULL) {
        func_02059784(res->posEv);
    }
    res->loaded = TRUE;
    return TRUE;
}

u8 func_0205ae84(StageRes *res);
void func_0205af4c(StageRes *res, u16 val);

#define STAGE_SKIP 0x8fff

BOOL func_0205aa98(StageRes *res, BOOL force) {
    if (res->data == NULL) {
        return FALSE;
    }
    if (!force && !res->unk_58) {
        return FALSE;
    }
    res->unk_58 = 0;
    res->unk_5a = 0;
    data_02149efc.unk_0c = 0;
    data_02149efc.unk_00 = 0;
    while (res->size > res->unk_54 * 2) {
        u16 *cmd = (u16 *)res->data + res->unk_54;
        u16 c = *cmd;
        switch (c & 0xff) {
        case 1:
            res->condCount = 0;
            res->opCount = 0;
            res->unk_54++;
            break;
        case 0x20:
            res->unk_54 += res->unk_vf3c(cmd);
            res->condStack[res->condCount++] = res->unk_5b;
            break;
        case 4:
            if (func_0205ae84(res)) {
                res->unk_54 += 2;
            } else {
                if (cmd[1] == 0) {
                    goto end;
                }
                res->unk_54 += cmd[1] >> 1;
            }
            res->varId = NULL;
            break;
        case 2:
            res->unk_54 += cmd[1] >> 1;
            break;
        case 3:
            res->unk_54++;
            break;
        case 5:
            res->unk_54 += res->Eval(cmd + 1, 0, 0);
            {
                u16 v = res->value;
                res->blockStack[res->unk_b2++] = v;
            }
            res->unk_54++;
            break;
        case 6: {
            u16 top = res->blockStack[res->unk_b2 - 1];
            u16 len = cmd[1];
            u16 skip;
            if (top == STAGE_SKIP) {
                skip = len / 2;
            } else {
                skip = res->Eval(cmd + 2, 0, 0) + 2;
                if (top == res->value) {
                    res->blockStack[res->unk_b2 - 1] = STAGE_SKIP;
                } else {
                    skip = len / 2;
                }
            }
            res->unk_54 += skip;
            break;
        }
        case 7: {
            u16 len = cmd[1];
            u16 skip = 2;
            if (res->blockStack[res->unk_b2 - 1] == STAGE_SKIP) {
                skip = len / 2;
            } else {
                res->blockStack[res->unk_b2 - 1] = STAGE_SKIP;
            }
            res->unk_54 += skip;
            break;
        }
        case 8:
            res->unk_b2--;
            res->unk_54++;
            break;
        case 0x10:
            res->opStack[res->opCount++] = c;
            res->unk_54++;
            break;
        case 0x11:
            res->opStack[res->opCount++] = c;
            res->unk_54++;
            break;
        case 0x12:
            res->opStack[res->opCount++] = c;
            res->unk_54++;
            break;
        case 0x30:
            res->condCount = 0;
            res->opCount = 0;
            res->varId = NULL;
            res->unk_59 = 0;
            res->unk_54 += res->unk_vf44(cmd);
            if (res->unk_59) {
                goto end;
            }
            if (res->unk_5a) {
                return TRUE;
            }
            break;
        case 0x40:
            res->condCount = 0;
            res->opCount = 0;
            if (res->varId == NULL) {
                res->unk_54 += res->Eval(cmd, 0, 0);
                res->varId = cmd;
            } else {
                u16 v = res->value;
                res->unk_54 += res->Eval(cmd, 0, 0);
                func_0205af4c(res, v);
                res->varId = NULL;
            }
            break;
        default:
            if (c >= 0x50 && c < 0x60) {
                res->op = c;
                res->unk_54++;
                break;
            }
            goto end;
        }
    }
end:
    res->unk_54 = 0;
    res->unk_b2 = 0;
    return TRUE;
}

}
