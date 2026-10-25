// The Lang TU's global resource handle, built at startup and registered for destruction.
//
// The handle is __declspec(weak): the target's static initialiser reaches it through its own pool
// word. For a plain definition MWCC stores the vtable pointer as an offset from the TU's .bss base
// (the destructor-chain node at 0x0214b0ac), which the target doesn't do.
//
// ResHandle.cpp is written C-style; its destructors keep the mangled names the compiler-generated
// code here refers to (_ZN9ResHandleD1Ev, _ZTV9ResHandle).
struct ResHandle {
    virtual ~ResHandle();
    virtual void Clear();
    virtual void Unload();
    ResHandle() { Clear(); }
    char arcName[0x20];
    char name[0x20];
    int type;
    unsigned char unk_48;
};

static asm void LangHandle_order() {}

extern "C" void *data_0214b0a8;
void *data_0214b0a8;
__declspec(weak) ResHandle data_0214b0b8;
