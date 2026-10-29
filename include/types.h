#ifndef TYPES_H
#define TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef volatile u8 vu8;
typedef volatile u64 vu64;

typedef int BOOL;
#define TRUE 1
#define FALSE 0

// Field read through a const-qualified lvalue (FLD/LFLD cast through `u8 *`, which drops
// const). MWCC does not let a plain read in a later block reuse a const read.
#define CFLD(type, p, off) (*(type const *)((const u8 *)(p) + (off)))

#ifndef NULL
#define NULL 0
#endif

#endif
