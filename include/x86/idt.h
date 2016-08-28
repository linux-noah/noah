typedef unsigned uint;

struct gate_desc {
  uint64_t offset_low:16;
  uint64_t selector:16;
  uint64_t ist:3;
  uint64_t zero0:5;
  uint64_t type:4;
  uint64_t zero1:3;
  uint64_t dpl:2;
  uint64_t p:1;
  uint64_t offset_high:48;
  uint64_t zero2:32;
} __attribute__ ((packed));
