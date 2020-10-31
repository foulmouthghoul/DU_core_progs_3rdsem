// chapter 3 problem 6
#include <stdio.h>
#include <math.h>

int fact(int b) //to calculate factorial by recursion
{
    if (b >= 1)
        return (b * fact(b - 1));
    else
        return 1;
}

double Fn(int n, double z) //to calculate nth term of the series
{
    int extra = 1;
    for (int i= 1; i <= n; i++)
        extra = extra * (1 + 3 * (n - 1)); //calculating the part in numerator where 1*4*7*10..(1+3(n-1))

    return ((extra * pow(z, 3 * n)) / fact(3 * n));
}

int main()
{
    FILE *c3p6;
    c3p6 = fopen("c3p6.txt", "w");
    fprintf(c3p6, "#z \t f(z)\n");

    for (double z = -10; z <= 0; z = z+0.05)
    {
        double s = 1.0;
        int n = 1;
        do
        {
            s = s + Fn(n, z);
            printf("%lf \t %lf \t %lf \n", z, Fn(n,z),0.35503*s);
            n++;
        } while (fabs(Fn(n,z)/s)>0.0001);
        //printf("%lf \t %lf \t %lf \n", z, Fn(n, z), 0.35503 * s);
        fprintf(c3p6, "%lf \t %lf \t %lf \n", z, Fn(n,z),0.35503*s);
    }
    fclose(c3p6);
}
