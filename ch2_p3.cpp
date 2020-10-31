//chapter 2 exercise problem 3
#include <stdio.h>
#include <math.h>

#define pi acos(-1.0) //deines the value of pi

float Y(float a) //function defining y
{
    if (a>=0.0 && a<pi)
        return (a);
    else if (a>=pi && a<(2*pi))
        return (2 * pi - a);
}

int main()
{
    FILE *p3;
    p3 = fopen("p3.txt", "w");
    fprintf(p3, "#x \t y \n");

    for (float x = -(6*pi); x <= (6*pi); x = x + 0.1)
    {
        fprintf(p3, "%f \t %f \n", x / pi, Y(x));
        printf("%f \t %f \n", x / pi, Y(x));
    }

}
