extern "C" {
#include "card_private.h"
}

typedef struct CARDHookContext {
    struct CARDHookContext *next;
    void *userdata;
    void (*callback)(void *userdata, u32 event, void *arg);
} CARDHookContext;

extern "C" {
extern CARDHookContext *data_0208e420;
void CARDi_NotifyEvent(u32 event, void *arg);
}

// The target pools the hook chain head twice; this file is C++ only for this second declaration.
namespace Dup { extern "C" CARDHookContext *data_0208e420; }

void CARDi_NotifyEvent(u32 event, void *arg) {
    OSIntrMode bak_cpsr = OS_DisableInterrupts();
    CARDHookContext **pp;
    CARDHookContext *chain;

    chain = data_0208e420;
    pp = &Dup::data_0208e420;

    while (chain != NULL) {
        if (chain->callback != NULL) {
            (*chain->callback)(chain->userdata, event, arg);
        }
        if (*pp == chain) {
            pp = &(*pp)->next;
        }
        chain = *pp;
    }
    (void)OS_RestoreInterrupts(bak_cpsr);
}
