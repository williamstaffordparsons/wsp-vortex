# WSP-Vortex
© 2024 William Stafford Parsons

## About
WSP-Vortex is a 32-bit pseudorandom number generator algorithm with a library in C99 as a substantial improvement to Mersenne Twister.

Read more [here](https://williamstaffordparsons.github.io/wsp-vortex/).

## Example
``` c
#include <stdio.h>
#include "wsp_vortex.h"

int main(void) {
  struct wsp_vortex_s s;
  unsigned char i = 0;

  wsp_vortex_initialize(0, &s);

  while (i != 10) {
    i++;
    printf("Result %u is %u.\n", i, wsp_vortex_randomize(&s));
  }

  return 0;
}
```
