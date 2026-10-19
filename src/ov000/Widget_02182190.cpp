#include "ov000/VObj.h"

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
void *func_0203dd9c(u32 size);
void func_0205a6a0(Widget02182190 *w);
void func_0205a840(Widget02182190 *w, char *path, char *name);
void func_0200779c(char *dst, const char *fmt, ...);
void STD_CopyString(char *dst, const char *src);
void STD_ConcatenateString(char *dst, const char *src);

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
    w = (Widget02182190 *)func_0203dd9c(0xd8);
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
