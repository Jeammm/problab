#include "probelib.h"
#include <cstdio>

int n;

main()
{
  int n = probe_init();
  int mid;

  int a = 0;
  int b = n-1;

  while (b > a)
  {
    mid = a + (b-a)/2;
  
    if (probe_check(a, mid))
    {
      b = mid;
    }
    else
    {
      a = mid + 1;
    }
  }
  
  probe_answer(a);
}
