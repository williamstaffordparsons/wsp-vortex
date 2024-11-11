#ifndef WSP_VORTEX_H
#define WSP_VORTEX_H

#include <stdint.h>

struct wsp_vortex_s {
  uint32_t a[1024];
  uint32_t b;
  uint32_t c;
  uint32_t d;
};

void wsp_vortex_initialize(uint32_t seed, struct wsp_vortex_s *s);

uint32_t wsp_vortex_randomize(struct wsp_vortex_s *s);

#endif
