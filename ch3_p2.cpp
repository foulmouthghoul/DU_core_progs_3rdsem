// chapter 3 problem 2
#include <stdio.h>
#include <math.h>

#define pi acos(-1.0)

int main()
{
    float t, s;
    int k;

    FILE *c3p2;
    c3p2 = fopen("c3p2.txt", "w");
    fprintf(c3p2, "#x \t cos(x) \t act cos \n");

    for (float x = 0.0; x < pi; x =x+ 0.01)
    {
        k = 1;
        t = s = 1.0;
        do
        {
            t =t*(-(x * x) / ((2 * k - 1) * (2 * k + 0)));
            s =s + t;
            k++;
            printf("%f \n", s);
        } while (fabs(t/s)>0.00001);

        printf("calc = %4.4g \t std cos(%f) = %4.4g \n", s, x, cos(x));
        fprintf(c3p2, "%f \t %5g \t %5g \n", x, s, cos(x));

        }
}
