// gx.c's .data: sIsDispOn (the display starts on) and GXi_DmaId (the DMA channel GX uses by
// default). gx.c reaches both through one label, data_0208af54. A data-only file so the matched
// gx.c is left as it is; it links right after gx.c.

typedef unsigned short u16;
typedef unsigned long u32;

#define TRUE             1
#define GX_DEFAULT_DMAID 3

u16 data_0208af54 = TRUE; // sIsDispOn
u32 GXi_DmaId = GX_DEFAULT_DMAID;
