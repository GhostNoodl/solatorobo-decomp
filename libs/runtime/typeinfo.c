#include "types.h"

void Heap_Free(void *p);

void _ZNSt9type_infoD2Ev(void *this_) {
}

void *_ZNSt9type_infoD1Ev(void *this_) {
    _ZNSt9type_infoD2Ev(this_);
    return this_;
}

void *_ZNSt9type_infoD0Ev(void *this_) {
    _ZNSt9type_infoD2Ev(this_);
    Heap_Free(this_);
    return this_;
}

void *_ZN10__cxxabiv117__class_type_infoD2Ev(void *this_) {
    _ZNSt9type_infoD2Ev(this_);
    return this_;
}

void *_ZN10__cxxabiv117__class_type_infoD1Ev(void *this_) {
    _ZN10__cxxabiv117__class_type_infoD2Ev(this_);
    return this_;
}

void *_ZN10__cxxabiv117__class_type_infoD0Ev(void *this_) {
    _ZN10__cxxabiv117__class_type_infoD2Ev(this_);
    Heap_Free(this_);
    return this_;
}
