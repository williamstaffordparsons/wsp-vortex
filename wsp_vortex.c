#include "wsp_vortex.h"

void wsp_vortex_initialize(uint32_t seed, struct wsp_vortex_s *s) {
  s->a[0] = seed;
  s->b = 1;

  while (s->b != 1024) {
    s->a[s->b] = s->a[s->b - 1] + (s->b << 24) + 1111111111;
    s->b++;
  }

  s->b = 0;
  s->c = 0;
  s->d = 0;
}

uint32_t wsp_vortex_randomize(struct wsp_vortex_s *s) {
  s->b = ((s->b << 14) | (s->b >> 18)) + s->c;
  s->c += 1111111111;
  s->d++;
  s->a[s->d & 1023] += s->b ^ s->c;
  return s->a[s->d & 1023] + s->c;
}
