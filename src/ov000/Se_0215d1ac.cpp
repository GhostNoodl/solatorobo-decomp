#include "types.h"

typedef struct {
    u8 pad[4];
    s32 state;
    u8 pad08[4];
    u32 flags;
    u8 pad10[0x74];
    u32 kind;
} Obj0215d1ac;

extern "C" {

extern void *gSndMgr;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

static inline void Nop0215d1ac(Obj0215d1ac *self) {
}

void Lo021cad50_PreUpdate(Obj0215d1ac *self) {
    switch (self->state) {
    case 0:
        if (self->flags & 0x20000) {
            SndMgr_PlayVolume(gSndMgr, 0x28, -1, -1, -1);
        } else if (self->kind & 0x2000) {
            SndMgr_PlayVolume(gSndMgr, 0x31, -1, -1, -1);
        } else if (self->kind & 0x8000) {
            SndMgr_PlayVolume(gSndMgr, 0x21, -1, -1, -1);
        } else if (self->kind == 0x854 || self->kind == 0x4054 || self->kind == 0x857 || self->kind == 0x105b) {
            SndMgr_PlayVolume(gSndMgr, 0x21, -1, -1, -1);
        } else if (self->kind == 0x855) {
            SndMgr_PlayVolume(gSndMgr, 0x21, -1, -1, -1);
        } else if (self->kind == 0x85a) {
            SndMgr_PlayVolume(gSndMgr, 0x86, -1, -1, -1);
        } else if (self->kind == 0x859) {
            SndMgr_PlayVolume(gSndMgr, 0x89, -1, -1, -1);
        } else {
            SndMgr_PlayVolume(gSndMgr, 0x28, -1, -1, -1);
        }
        break;
    case 1:
        break;
    case 2:
        break;
    }
}

}
