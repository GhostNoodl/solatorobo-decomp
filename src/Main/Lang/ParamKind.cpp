#include "types.h"

extern "C" {

extern void *ParamKind_ShapeTable[];

void *ParamKind_GetShape(int kind) {
    return ParamKind_ShapeTable[kind];
}

}
