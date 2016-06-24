typedef unsigned uint;

struct gate_desc {
  uint offset_low : 16;
  uint selector : 16;
  uint zero : 8;
  uint type : 4;
  uint s : 1;                   /* storage segment */
  uint dpl : 2;
  uint p : 1;                   /* present */
  uint offset_high : 16;
};
