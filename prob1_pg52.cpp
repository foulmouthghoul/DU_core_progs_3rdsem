#include <stdio.h>
#include <math.h>

//Manual page 52 , problems 1.10
// 1. table of trigonometric functions

float trig_sin(float x) //function to calculate value of sine
{
	float s = 0.0;
	s = sin(x); //calculating value of sin
	return s;
}

float trig_cos(float x) //function for cosine
{
	float c = 0.0;
	c = cos(x); //calculating value of cosine
	return c;
}

float trig_tan(float x) //fucntion for tangent
{
	float t = 0.0;
	t = (sin(x) / cos(x));
	return t;
}

/*Sir i m facing problem in the main calling functions between the compilers
  where    */
int main() //main calling function
{
	float rad = 0.0;
	printf("x \t \t sin(x) \t cos(x) \t tan(x) \n");
	for (float a = 0.0; a < 0.26; a=a + 0.01)
	{
		rad = 3.1415*a;
		printf ("%f \t %f \t %f \t %f \n",a,trig_sin(rad), trig_cos(rad), trig_tan(rad)); //printing value of sine
	}
	return 0;
}



