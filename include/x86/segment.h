#define GSEL(s,r) (((s)<<3) | r)        /* a global selector */

#define	DESC_UNUSABLE 0x00010000

#define SEG_NULL        0x0
#define SEG_CODE        0x1
#define SEG_DATA        0x2

#define SEG(type, base, lim, dpl)      \
  (struct segment_desc) {              \
    .limit_low = (lim) & 0xffff,       \
    .base_low = (base) & 0xffffff,     \
    .type = (type),                    \
    .dpl = (dpl),                      \
    .p = 1,                            \
    .limit_high = ((lim) >> 16) & 0xf, \
    .avl = 0,                          \
    .l = 1,                            \
    .db = 1,                           \
    .gran = 1,                         \
    .base_high = ((base) >> 24),       \
    .xx1 = 0,                          \
    .mbz = 0,                          \
    .xx2 = 0,                          \
  }

struct	segment_desc {
  u_int64_t offset_low:16;	/* segment extent (lsb) */
  u_int64_t base_low:24;		/* segment base address (lsb) */
  u_int64_t type:5;		/* segment type */
  u_int64_t dpl:2;		/* segment descriptor priority level */
  u_int64_t p:1;			/* segment descriptor present */
  u_int64_t limit_high:4;		/* segment extent (msb) */
  u_int64_t avl:1;		/* unused */
  u_int64_t l:1;			/* unused */
  u_int64_t db:1;			/* unused */
  u_int64_t gran:1;		/* limit granularity (byte/page units)*/
  u_int64_t base_high:40 __attribute__ ((packed));/* segment base address  (msb) */
  u_int64_t xx1:8;
  u_int64_t mbz:5;		/* MUST be zero */
  u_int64_t xx2:19;
} __attribute__ ((packed));
