#ifndef WSP_VORTEX_H
#define WSP_VORTEX_H

#include <stdint.h>

struct wsp_vortex_s {
  uint32_t blocks[1024];
  uint32_t blocks_selector;
  uint32_t increment;
  uint32_t increment_offset;
};

void wsp_vortex_initialize(const uint32_t seed, struct wsp_vortex_s *s);

uint32_t wsp_vortex_randomize(struct wsp_vortex_s *s);

#endif
