#include<stdio.h>
void f1(int *px, int *py)
{ int *pt;
  pt = px;
  px = py;
  py = pt;
}
void f2(int *px, int y)
{ int t;
  t = *px;
  *px = y;
  y = t;
}
int main()
{ int a=3, b=5;
  f1(&a, &b);
  printf("%d,%d\n", a, b);
  a=3; b=5;
  f2(&a, b);
  printf("%d,%d\n", a, b);
  return 0;
}