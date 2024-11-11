#include "wsp_vortex.h"

void wsp_vortex_initialize(uint32_t seed, struct wsp_vortex_s *s) {
  unsigned short i = 1;

  s->a[0] = seed + 1111111111;

  while (i != 1024) {
    s->a[i] = s->a[i - 1] + 1;
    i++;
  }

  s->b = seed;
  s->c = s->b + seed;
  s->d = s->c + seed;
}

uint32_t wsp_vortex_randomize(struct wsp_vortex_s *s) {
  uint32_t _a = s->a[s->d & 1023];
  uint32_t _b = s->b ^ s->c;

  s->a[s->d & 1023] += _b;
  s->b = ((s->b << 14) | (s->b >> 18)) + s->c;
  s->c += 1111111111;
  s->d++;
  _a += s->c + _b;
  s->a[_a & 1023] += s->d + _a;
  return _a;
}
