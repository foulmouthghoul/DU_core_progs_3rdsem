//Problem 4, pg 53 lab manual

#include <stdio.h>

int main()
{
	int a , sum = 0, dig;

	for(int i = 50; i < 71; i++)
	{
		a = i; //storing the temp value
		while(a != 0)
		{
			dig = a%10; //extracting the digits
			sum =sum + dig;
			a =a/10;
		}
		if( i % sum == 0)
			printf("%d \n", i);
	}
	return 0;
}
