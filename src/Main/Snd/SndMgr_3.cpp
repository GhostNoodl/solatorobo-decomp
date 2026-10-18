#include "Main/Snd/SndMgr.h"

extern "C" {

BOOL func_0204985c(SndMgr *mgr) {
    return mgr->loadType == 0 ? TRUE : FALSE;
}

void func_02049870(SndMgr *mgr, s32 seq) {
    mgr->curBgm = -1;
    if (mgr->noAutoPlay) {
        mgr->playAfterLoad = FALSE;
    } else {
        mgr->playAfterLoad = TRUE;
    }
    SndMgr_RequestLoad(mgr, 1, seq, -1);
}

void func_020498ac(SndMgr *mgr, s32 seq) {
    if (seq != mgr->loadedSeq && seq != mgr->loadedSeqEx[0] && seq != mgr->loadedSeqEx[1] && seq != mgr->loadedSeqEx[2]) {
        mgr->playAfterLoad = TRUE;
        SndMgr_RequestLoad(mgr, 1, seq, -1);
        return;
    }
    NNS_SndArcPlayerStartSeq(&mgr->bgm, seq);
    if (SndMgr_GetSeqVolume(seq) != 0) {
        NNS_SndPlayerSetVolume(&mgr->bgm, SndMgr_GetSeqVolume(seq));
    }
    mgr->curBgm = seq;
    NNS_SndPlayerSetPlayerPriority(&mgr->bgm, 0x7f);
}

void func_02049950(SndMgr *mgr, int volume, int frames) {
    NNS_SndPlayerMoveVolume(&mgr->bgm, volume, frames);
}

void func_02049960(SndMgr *mgr, int playerNo, int fadeFrames) {
    NNS_SndPlayerStopSeqBySeqNo(playerNo, fadeFrames);
}

void func_02049974(SndMgr *mgr, int fadeFrames) {
    NNS_SndPlayerStopSeqAll(fadeFrames);
}

SndHandle *func_02049984(SndMgr *mgr, s32 id, s32 *outSeqArc, s32 *outIndex) {
    SndHandle *handle;
    s32 group;
    *outIndex = id & 0xff;
    group = id >> 8;
    handle = NULL;
    *outSeqArc = -1;
    switch (group) {
        case 0:
            if (id >= 0) {
                if (id <= 0x8a) {
                    *outSeqArc = 0;
                    handle = &mgr->se;
                }
            }
            break;
        case 1:
            if (id >= 0x100) {
                if (id <= 0x101) {
                    *outSeqArc = 1;
                    handle = &mgr->se;
                }
            }
            break;
        case 2:
            if (id >= 0x200) {
                if (id <= 0x224) {
                    *outSeqArc = 2;
                    handle = &mgr->se;
                }
            }
            break;
        case 3:
            if (id < 0x300 || id >= 0x30e) {
                return NULL;
            }
            handle = &mgr->voice;
            *outSeqArc = data_0208b688[group];
            break;
        default:
            handle = &mgr->voice;
            *outSeqArc = data_0208b688[group];
            break;
    }
    return handle;
}

SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames) {
    s32 seqArc;
    s32 index;
    SndHandle *handle;
    if (id < 0) {
        return NULL;
    }
    handle = func_02049984(mgr, id, &seqArc, &index);
    if (handle == NULL) {
        return NULL;
    }
    if (!NNS_SndArcPlayerStartSeqArc(handle, seqArc, index)) {
        return NULL;
    }
    if (volume >= 0) {
        if (targetVolume >= 0 && frames >= 0) {
            NNS_SndPlayerMoveVolume(handle, volume, 0);
            NNS_SndPlayerMoveVolume(handle, targetVolume, frames);
        } else {
            NNS_SndPlayerSetVolume(handle, volume);
        }
    }
    NNS_SndPlayerSetPlayerPriority(handle, 0x40);
    return handle;
}

static inline s32 SndMgr_FindFreeSeqArc(SndMgr *mgr) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (!(mgr->seqArc[i].player != NULL ? TRUE : FALSE)) {
            return i;
        }
    }
    return -1;
}

s32 func_02049afc(SndMgr *mgr, s32 id) {
    s32 seqArc;
    s32 index;
    s32 i;
    SndHandle *handle;
    if (func_02049984(mgr, id, &seqArc, &index) == NULL) {
        return -1;
    }
    i = SndMgr_FindFreeSeqArc(mgr);
    if (i < 0) {
        return -1;
    }
    handle = &mgr->seqArc[i];
    if (!NNS_SndArcPlayerStartSeqArc(handle, seqArc, index)) {
        return -1;
    }
    NNS_SndPlayerSetPlayerPriority(handle, 0x6e);
    mgr->seqArcHandles[i] = handle;
    return i;
}

void func_02049bb4(SndMgr *mgr, s32 idx) {
    if (idx < 0 || idx >= 5) {
        return;
    }
    NNS_SndPlayerStopSeq(&mgr->seqArc[idx], 0);
}

}
