//Program 5 , pg 53 lab manual

#include <stdio.h>

int main()
{
	int a = 0, b = 1, s = 0;
	int lim = 200;
	while (s < lim)
	 {
		 printf("%d \n", s);
		 s =a + b;
		 a = b;
		 b = s;
	 }
	 return 0; //
}

/*
int main()
{
	int l;
	printf("enter the limit \n");
	scanf("%d", l);
	printf("%d", fibonacci(l));

	return 0;
}
*/
