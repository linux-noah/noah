typedef unsigned uint;

struct gate_desc {
  uint offset_low : 8;
  uint selector : 8;
  uint zero0 : 4;
  uint type : 4;
  uint offset_middle : 8;
  uint offset_high : 16;
  uint zero1 : 16;
};
