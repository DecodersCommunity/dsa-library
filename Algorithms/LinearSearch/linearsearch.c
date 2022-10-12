#include <stdio.h>

int main()
{
   int arr[10], i;
   int num, index = -1;
   printf("Enter 10 Numbers: ");
   for (i = 0; i < 10; i++)
      scanf(" %d", &arr[i]);

   printf("\nEnter a Number to Search: ");
   scanf(" %d", &num);
   for (i = 0; i < 10; i++)
   {
      if (arr[i] == num)
      {
         index = i;
         break;
      }
   }
   if (index != -1) {
      printf("\nFound at Index No. %d\n", index);
   }
   else {
      printf("\nNumber not found in array");
   }
   return 0;
}
