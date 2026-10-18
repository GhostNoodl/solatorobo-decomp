#include "mobiclip/mobiclip.h"

// C interface of the Actimagine Mobiclip SDK movie player.

extern "C" {


extern const char data_02005068[];
extern const u32 data_0208b2ac[];

extern void func_02004eb0(const char *string);
extern void *func_02034818(u32 size);
extern void func_02034824(void *ptr);
extern BOOL func_02034830(MoStream *stream, void *file);
extern BOOL func_02033858(MoPlayer *player, MoStream *stream, u32 flags);
extern void *func_02043e1c(u32 size);
extern void func_02043e2c(void *ptr);


BOOL func_02033550(MoPlayer *player, MoStream *stream, u32 flags) {
    func_02004eb0(data_02005068);
    return func_02033858(player, stream, flags);
}

MoPlayer *func_02033580(void *file, u32 flags) {
    MoStream *stream = (MoStream *)func_02034818(sizeof(MoStream));
    MoPlayer *player;
    if (stream != NULL) {
        stream->unk_04 = 0;
        stream->unk_08 = 0;
        *(const u32 **)stream = data_0208b2ac;
    }
    if (stream == NULL) {
        return NULL;
    }
    if (!func_02034830(stream, file)) {
        if (stream != NULL) {
            stream->Release();
        }
        return NULL;
    }
    player = (MoPlayer *)func_020337fc(sizeof(MoPlayer));
    if (player != NULL) {
        player = func_02033814(player);
    }
    if (!func_02033550(player, stream, flags)) {
        if (player != NULL) {
            func_02033844(player);
            func_02033808(player);
        }
        return NULL;
    }
    return player;
}

void *func_02033648(void *ptr) {
    func_02034824(ptr);
    return ptr;
}

void func_0203365c(MoPlayer *player) {
    if (player != NULL && player != NULL) {
        func_02033844(player);
        func_02033808(player);
    }
}

u32 func_0203367c(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return func_02033f54(player);
}

u16 func_02033694(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return func_02033f5c(player);
}

u32 func_020336ac(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return func_02033f64(player);
}

u32 func_020336c4(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return func_02033f6c(player);
}

u32 func_020336dc(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return func_02033f7c(player);
}

u32 func_020336f4(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return func_02033f74(player);
}

BOOL func_0203370c(MoPlayer *player) {
    if (player == NULL) {
        return FALSE;
    }
    return func_02033fa0(player) == 1;
}

BOOL func_02033730(MoPlayer *player) {
    if (player == NULL) {
        return FALSE;
    }
    return func_020341ac(player) == 1;
}

BOOL func_02033754(MoPlayer *player) {
    if (player == NULL) {
        return FALSE;
    }
    return func_020341bc(player) == 1;
}

BOOL func_02033778(MoPlayer *player, void *dst, u32 stride, int mode) {
    if (player == NULL) {
        return FALSE;
    }
    return func_02034298(player, dst, stride, mode) == 1;
}

BOOL func_0203379c(MoPlayer *player) {
    if (player == NULL) {
        return FALSE;
    }
    return func_02034408(player) == 1;
}

u32 func_020337c0(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return func_02034448(player);
}

BOOL func_020337d8(MoPlayer *player, void *out) {
    if (player == NULL) {
        return FALSE;
    }
    return func_02034458(player, out) == 1;
}

void *func_020337fc(u32 size) {
    return func_02043e1c(size);
}

void func_02033808(void *ptr) {
    func_02043e2c(ptr);
}

MoPlayer *func_02033814(MoPlayer *player) {
    player->stream = NULL;
    player->framesY = NULL;
    player->framesUV = NULL;
    player->tmpY = NULL;
    player->tmpUV = NULL;
    player->chunkBuffers[0] = NULL;
    player->chunkBuffers[1] = NULL;
    player->unk_64 = NULL;
    player->audioDecoders = NULL;
    player->keyFrames = NULL;
    return player;
}

MoPlayer *func_02033844(MoPlayer *player) {
    func_02033df0(player);
    return player;
}

}
