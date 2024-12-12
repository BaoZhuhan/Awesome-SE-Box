#include <stdio.h>
void reverse_str(char *p);
int main()
{
  char str[80];

  gets(str);
  reverse_str(str);

  return 0;
}
void reverse_str(char *p)
{
  char *q;
  q = p;
  if (*p != '\0')
  {
    q++;
    reverse_str(q);
    puts(*p);
  }
}