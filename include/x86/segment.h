#define GSEL(s,r) (((s)<<3) | r)        /* a global selector */

#define	DESC_UNUSABLE 0x00010000

#define SEG_NULL        0x0
#define SEG_CODE        0x1
#define SEG_DATA        0x2
