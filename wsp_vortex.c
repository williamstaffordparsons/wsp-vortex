#include "wsp_vortex.h"

void wsp_vortex_initialize(uint32_t seed, struct wsp_vortex_s *s) {
  unsigned short i = 1;

  s->blocks[0] = seed + 1111111111;

  while (i != 1024) {
    s->blocks[i] = s->blocks[i - 1] + 1;
    i++;
  }

  s->blocks_selector = seed;
  s->increment = s->blocks_selector + seed;
  s->increment_offset = s->increment + seed;
}

uint32_t wsp_vortex_randomize(struct wsp_vortex_s *s) {
  uint32_t block = s->blocks[s->blocks_selector & 1023];
  uint32_t increment_offset_capture = s->increment_offset ^ s->increment;

  s->blocks[s->blocks_selector & 1023] += increment_offset_capture;
  s->increment_offset = ((s->increment_offset << 23)
    | (s->increment_offset >> 9)) + s->increment;
  s->increment += 111111111;
  s->blocks_selector++;
  block += s->increment + increment_offset_capture;
  s->blocks[block & 1023] += s->blocks_selector + block;
  return block;
}
