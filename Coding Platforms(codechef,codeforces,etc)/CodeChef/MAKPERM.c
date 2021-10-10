//Link To The Problem
//https://www.codechef.com/COOK98B/problems/MAKPERM/

#include <stdio.h>
void func();
long long int cmpfunc (const void * a, const void * b) 
{
   return ( *(long long int*)a - *(long long int*)b );
}
int main()
 {
  int t;
  scanf("%d", &t);
  while(t > 0)
  {
    func();
    t--;
  }
  return 0;
}
void func()
{
  long long int n, a[1000000], i, count = 0;
  scanf("%lld", &n);
  for(i = 0; i < n; i ++)
    scanf("%lld", &a[i]);
  qsort(a, n, sizeof(long long int), cmpfunc);
  for(i = 0; i < n; i++)
  {
    if(a[i] <= n)
    {
      if(i != 0)
      {
        if(a[i - 1] != a[i])
          count ++;
      }
      else
        count++;
    }
    else
      i = n + 1;
  }
  count = n - count;
  printf("%lld\n", count);
}
