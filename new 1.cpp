//chapter 2 , program 2
#include <stdio.h>
#include <math.h>

float fx(float t) //calculating the value of function x 
{
	return (sin(t));
}

float fy(float a ,float n, float t, float del) //for function y
{
	return (a*sin(n*t + del));
}

int main()
{
	//data files are created to store plot coordinates
	
	FILE*p2_a