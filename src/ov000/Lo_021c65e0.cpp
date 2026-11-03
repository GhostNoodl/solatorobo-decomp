#include "ov000/TextList.h"

extern "C" {

static inline ListRow *At021c65e0(TextList *self, s32 i) {
    ListRow *n;
    s32 k = 0;
    for (n = self->rows; n != NULL; n = n->next) {
        if (k == i) {
            break;
        }
        k++;
    }
    return n;
}

static inline s32 IndexOf021c65e0(TextList *self, ListRow *node) {
    ListRow *n;
    s32 k;
    k = 0;
    for (n = self->rows; n != NULL; n = n->next) {
        if (n == node) {
            break;
        }
        k++;
    }
    if (n == NULL) {
        k = -1;
    }
    return k;
}

static inline ListRow *Find021c65e0(TextList *self, s32 key) {
    ListRow *n;
    for (n = self->rows; n != NULL; n = n->next) {
        if (key == n->index) {
            break;
        }
    }
    return n;
}

static inline void Select021c65e0(TextList *self, s32 i) {
    if (i >= self->count) {
        self->index = 0;
        return;
    }
    self->index = i;
    self->cur = At021c65e0(self, i);
}

static inline ListRow *At2_021c65e0(TextList *self, s32 i) {
    s32 k = 0;
    ListRow *n;
    for (n = self->rows; n != NULL; n = n->next) {
        if (k == i) {
            break;
        }
        k++;
    }
    return n;
}

static inline void Select2_021c65e0(TextList *self, s32 i) {
    if (i >= self->count) {
        self->index = 0;
        return;
    }
    self->index = i;
    self->cur = At2_021c65e0(self, i);
}

void func_ov000_021c65e0(TextList *self, s32 key) {
    ListRow *node = Find021c65e0(self, key);
    s32 i;
    if (node != NULL) {
        i = IndexOf021c65e0(self, node);
        if (i >= 0) {
            Select021c65e0(self, i);
        } else {
            Select021c65e0(self, 0);
        }
    } else {
        Select2_021c65e0(self, 0);
    }
}
}
