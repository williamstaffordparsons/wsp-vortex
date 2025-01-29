#ifndef ABYSS_PRNG_32_LONG_H
#define ABYSS_PRNG_32_LONG_H

#include <stdint.h>

struct abyss_prng_32_long_s {
  uint32_t blocks[1024];
  uint32_t blocks_selector;
  uint32_t increment;
  uint32_t increment_offset;
};

uint32_t abyss_prng_32_long_randomize(struct abyss_prng_32_long_s *s);

#endif
