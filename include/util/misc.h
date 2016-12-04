#include <stdint.h>
#include <stdbool.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

static inline uint64_t rounddown(uint64_t x, uint64_t y) {
  return x / y * y;
}

static inline uint64_t roundup(uint64_t x, uint64_t y) {
  return (x + y - 1) / y * y;
}

static inline bool is_aligned(uint64_t x, uint64_t y) {
  return rounddown(x, y) == x;
}
