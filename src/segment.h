struct segment_descriptor {
	unsigned sd_lolimit:16;		/* segment extent (lsb) */
	unsigned sd_lobase:24;		/* segment base address (lsb) */
	unsigned sd_type:5;		/* segment type */
	unsigned sd_dpl:2;		/* segment descriptor priority level */
	unsigned sd_p:1;		/* segment descriptor present */
	unsigned sd_hilimit:4;		/* segment extent (msb) */
	unsigned sd_xx:2;		/* unused */
	unsigned sd_def32:1;		/* default 32 vs 16 bit size */
	unsigned sd_gran:1;		/* limit granularity (byte/page units)*/
	unsigned sd_hibase:8;		/* segment base address  (msb) */
} __packed;

#define GSEL(s,r) (((s)<<3) | r)        /* a global selector */

#define SDT_MEMRW 18 /* memory read write */
#define SDT_MEMRWA 19 /* memory read write accessed */
#define SDT_MEMER 26 /* memory execute read */
#define SDT_MEMERA 27 /* memory execute read accessed */

#define SDT_SYS386TSS 9 /* system 386 TSS available */
#define SDT_SYS386BSY 11 /* system 386 TSS busy */

#define	DESC_PRESENT 0x00000080
#define	DESC_DEF32 0x00004000
#define	DESC_GRAN 0x00008000
#define	DESC_UNUSABLE 0x00010000
#define	I386_TSS_SIZE 104


#define SEG_NULL        0x0
#define SEG_CODE        0x1
#define SEG_DATA        0x2
#define SEG_TSS         0x3
