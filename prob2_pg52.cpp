// Problem 2 ,1.10 pg 52 lab manual
#include <stdio.h>
#include <math.h>

float function(float x,float y) //function for caculating f(x,y)
{
	float f = 0.0;
	//begining the conditional statements
	if( abs(x) > abs(y))
		f = pow(x, 2) + pow(y, 4);
	else if(abs(x) == abs(y))
		f = pow(x, 2)*( pow(x, 2) + 1);
	else
		f = pow(y, 2) + pow(x, 4);
	
	return f;
}

void main()
{
	float a = -1.0, b = -1.0;
	while (a <= 1.0)
	{
		printf("x=%f \t y=%f \t f(x,y)=%f \n",a, b, function(a,b));
		a = a + 0.25;
		b = b + 0.25;
	}
}
