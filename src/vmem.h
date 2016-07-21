
typedef enum {
  PAGE_4KB,
  PAGE_2MB,
  PAGE_1GB,
  PAGE_PML4E,
} page_type_t;

#define PAGE_SHIFT(page_type)            (12 + (page_type) * 9)
#define PAGE_SIZE(page_type)             (1ULL << PAGE_SHIFT(page_type))

#define KERN_BASE                        0xffff800000000000ULL

#define CANONICAL_LOWER_END              0x00007fffffffffffULL
