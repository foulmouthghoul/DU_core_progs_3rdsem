//Program 5 , pg 53 lab manual

#include <stdio.h>

int fibonacci(int n) //recursive function to generate sequence
{
   if ( n == 0)
      return n;
   else if ( n == 1)
      return n;
   else
      return ( fibonacci(n-1) + fibonacci(n-2));
}

int main() //calling function
{
   int lim, a = 0;
   printf ("enter the limit \n");
   scanf ("%d", &lim);

   while ( fibonacci(a) <= lim)
   {
      printf("%d\n", fibonacci(a)); //calling the fibonacci function
      a++;
   }

   return 0;
}

