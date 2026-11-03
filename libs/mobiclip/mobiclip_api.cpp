#include "mobiclip/mobiclip.h"

// C interface of the Actimagine Mobiclip SDK movie player.

extern "C" {


extern const char data_02005068[];
extern const u32 MoFileStream_vtbl[];

extern void OSi_ReferSymbol(const char *string);
extern void *MoMem_Alloc(u32 size);
extern void MoMem_Free(void *ptr);
extern BOOL MoFileStream_Open(MoStream *stream, void *file);
extern BOOL MoPlayer_Open(MoPlayer *player, MoStream *stream, u32 flags);
extern void *Gfx3D_AllocHi(u32 size);
extern void Gfx3D_FreeHi(void *ptr);


BOOL Mo_InitPlayer(MoPlayer *player, MoStream *stream, u32 flags) {
    OSi_ReferSymbol(data_02005068);
    return MoPlayer_Open(player, stream, flags);
}

MoPlayer *Mo_OpenFile(void *file, u32 flags) {
    MoStream *stream = (MoStream *)MoMem_Alloc(sizeof(MoStream));
    MoPlayer *player;
    if (stream != NULL) {
        stream->length = 0;
        stream->position = 0;
        *(const u32 **)stream = MoFileStream_vtbl;
    }
    if (stream == NULL) {
        return NULL;
    }
    if (!MoFileStream_Open(stream, file)) {
        if (stream != NULL) {
            stream->Release();
        }
        return NULL;
    }
    player = (MoPlayer *)Mo_Alloc(sizeof(MoPlayer));
    if (player != NULL) {
        player = MoPlayer_Ctor(player);
    }
    if (!Mo_InitPlayer(player, stream, flags)) {
        if (player != NULL) {
            MoPlayer_Dtor(player);
            Mo_Free(player);
        }
        return NULL;
    }
    return player;
}

void *MoFileStream_Release(void *ptr) {
    MoMem_Free(ptr);
    return ptr;
}

void Mo_ClosePlayer(MoPlayer *player) {
    if (player != NULL && player != NULL) {
        MoPlayer_Dtor(player);
        Mo_Free(player);
    }
}

u32 Mo_GetSampleRate(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return MoPlayer_GetSampleRate(player);
}

u16 Mo_GetAudioChannels(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return MoPlayer_GetAudioChannels(player);
}

u32 func_020336ac(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return func_02033f64(player);
}

u32 Mo_GetNumFrames(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return MoPlayer_GetNumFrames(player);
}

u32 Mo_GetBlockSize(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return MoPlayer_GetBlockSize(player);
}

u32 Mo_GetCurFrame(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return MoPlayer_GetCurFrame(player);
}

BOOL Mo_ReadFrame(MoPlayer *player) {
    if (player == NULL) {
        return FALSE;
    }
    return MoPlayer_ReadFrame(player) == 1;
}

BOOL Mo_Rewind(MoPlayer *player) {
    if (player == NULL) {
        return FALSE;
    }
    return MoPlayer_Rewind(player) == 1;
}

BOOL Mo_DecodeFrame(MoPlayer *player) {
    if (player == NULL) {
        return FALSE;
    }
    return MoPlayer_DecodeFrame(player) == 1;
}

BOOL Mo_ConvertFrame(MoPlayer *player, void *dst, u32 stride, int mode) {
    if (player == NULL) {
        return FALSE;
    }
    return MoPlayer_ConvertFrame(player, dst, stride, mode) == 1;
}

BOOL Mo_SkipFrame(MoPlayer *player) {
    if (player == NULL) {
        return FALSE;
    }
    return MoPlayer_SkipFrame(player) == 1;
}

u32 Mo_GetChunkSamples(MoPlayer *player) {
    if (player == NULL) {
        return 0;
    }
    return MoPlayer_GetChunkSamples(player);
}

BOOL Mo_DecodeAudio(MoPlayer *player, void *out) {
    if (player == NULL) {
        return FALSE;
    }
    return MoPlayer_DecodeAudio(player, out) == 1;
}

void *Mo_Alloc(u32 size) {
    return Gfx3D_AllocHi(size);
}

void Mo_Free(void *ptr) {
    Gfx3D_FreeHi(ptr);
}

MoPlayer *MoPlayer_Ctor(MoPlayer *player) {
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

MoPlayer *MoPlayer_Dtor(MoPlayer *player) {
    MoPlayer_Close(player);
    return player;
}

}
