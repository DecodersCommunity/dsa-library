// contributed by: AYUSH GUPTA <adhayatm@gmail.com>
#include <stdio.h>
int main()
{
  int a[5]={1,2,3,4,5};
  int c[5]={6,7,8,9,10};
  int b[10],i,j;
  for (i=0;i<5;i++)
  {
      b[i]=a[i];
  }
   for (i=0;i<5;i++)
  {
      j=5+i;
      b[j]=c[i];
  }
   for (i=0;i<10;i++)
  {
     printf("%d \n", b[i]);
   }
  return 0;
}
