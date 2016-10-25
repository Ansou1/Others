#include "string.h"

/* Compare S1 and S2, returning less than, equal to or
   greater than zero if S1 is lexiographically less than,
   equal to or greater than S2.  */
int kstrncmp(const char *p1, const char *p2, const int n)
{
  register const unsigned char *s1 = (const unsigned char *) p1;
  register const unsigned char *s2 = (const unsigned char *) p2;
  register unsigned char c1, c2;
  int i = 0;
  
  do
    {
      ++i;
      c1 = (unsigned char) *s1++;
      c2 = (unsigned char) *s2++;
      if (c1 == '\0')
	return c1 - c2;
    }
  while (c1 == c2 && i < n);

  return c1 - c2;
}
