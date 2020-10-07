//Problem 3 , page 53 lab manual

#include <stdio.h>
#include <math.h>

int main()
{
	int a = 0, b = 0, c = 0;
	int sum = 0, lim;
	
	lim = 100; //taking the limit of the series
	
	printf("a \t b \t c \n");
	for(a = 0; a <= lim; a++)
	{
		for(b = 0; b <= lim; b++)
		{
			sum = a*a + b*b; // storing the sum
			for(c = 0; c <= lim; c++)
			{
				if(c == sum)
					printf("%d \t %d \t %d \n", a,b,c); //output of pythagorean integers
			}
		}
	}
	
	return 0;
}

				
	
	