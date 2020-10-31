//chapter 3 problem 5
#include <stdio.h>
#include <math.h>

#define pi acos(-1.0)

float gamma(float a) // to calculate gamma function using recursion
{
    if (a == 0.5)
        return sqrt(pi);
    else
        return (fabs(a - 1) * gamma(fabs(a - 1)));
}

long int fact(int b) //to calculate factorial by recursion
{
    if (b >= 1)
        return (b * fact(b - 1));
    else
        return 1;
}

float F(int n, int k, float z) //to calculate tn th term of the series f(z,n)
{
    return (pow(z, k) / (pow(2, n - k) * fact(k) * gamma((0.5 + (n - k) / 2))));
}

int main()
{
    FILE *c3p5;
    c3p5 = fopen("c3p5.txt", "w");
    fprintf(c3p5, "#z \t f(z,n)");

    float s;

    for (float z = 0; z <= 5; z = z + 0.1)
    {
        s = 0;
        int k = 0;
        do
        {
            s = s + F(2, k, z);
            printf("%f \t %f \t %f\n", z, s, gamma(int((2 - k) / 2)));
            k = k + 2;
        } while (fabs(F(2,k,z)/s)<0.0001);
        fprintf(c3p5, "%.4f \t %4.4f \n", z, s);
    }
    fclose(c3p5);
}
