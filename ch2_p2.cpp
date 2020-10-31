//chapter 2 , program 2
#include <stdio.h>
#include <math.h>

float fx(float t) //calculating the value of function x
{
	return (sin(t));
}

float fy(float A ,float n, float t, float del) //for function y
{
	return (A*sin(n*t + del));
}

int main()
{
	//data files are created to store plot coordinates

    FILE *p2_a;
    FILE *p2_b;
    FILE *p2_c;

    p2_a = fopen("p2_a.txt", "w");
    p2_b = fopen("p2_b.txt", "w");
    p2_c = fopen("p2_c.txt", "w");

    float th;

    fprintf(p2_a, "#rad \t x1 \t y1 \t y2 \t y3 \n");
    fprintf(p2_b, "#rad \t x1 \t y1 \t y2 \t y3 \n");
    fprintf(p2_c, "#rad \t x1 \t y1 \t y2 \t y3 \n");

    //for loop to take the value within a certain range
    for (th = 0.0; th <= (4*3.141); th= th + 0.001)
    {
        fprintf(p2_a, "%f \t %f \t %f \t %f \t %f \t %f \t %f \n", th, fx(th), fy(1.0, 2.0, th, 0.25), fy(1.0,2.5, th, 0.25), fy(1.0, 3.0,th,0.25));
        fprintf(p2_b, "%f \t %f \t %f \t %f \t %f \t %f \t %f \n", th, fx(th), fy(0.5, 2.0,th, 0.25), fy(1.0, 2.0, th, 0.25), fy(2.0, 2.0, th, 0.25));
        fprintf(p2_c, "%f \t %f \t %f \t %f \t %f \n", th, fx(th), fy(1.0, 2.0,th, 0.25), fy(1.0, 2.0, th, 0.5), fy(1.0, 2.0, th, 1.0));
    }

    fclose (p2_a);
    fclose (p2_b);
    fclose (p2_c);

}
