#include "abyss_prng_32_long.h"

uint32_t abyss_prng_32_long_randomize(struct abyss_prng_32_long_s *s) {
  uint32_t block = s->blocks[s->blocks_selector & 1023];
  const uint32_t increment_offset_capture = s->increment_offset ^ s->increment;

  s->blocks[s->blocks_selector & 1023] += increment_offset_capture;
  s->increment_offset = ((s->increment_offset << 17)
    | (s->increment_offset >> 15)) + s->increment;
  s->increment += 1111111111;
  s->blocks_selector++;
  block += s->increment + increment_offset_capture;
  s->blocks[block & 1023] += s->blocks_selector + block;
  return block;
}
