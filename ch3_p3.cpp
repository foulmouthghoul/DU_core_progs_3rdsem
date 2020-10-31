// chapter 3 problem 3
#include <stdio.h>
#include <math.h>

double Jratio(int n,int k, double x) //defining the common ratio of Bessel function series
{
    return ((-(pow(x, 2) / 4) / ((k + 1) * (n + k + 1))));
}

double fact(int a) //calculating factorial for t0 term
{
    if (a>=1)
        return (a * fact(a - 1));
    else
        return 1;
}

int main()
{
    int k;
    double t0, s0; //three terms for n = 0,1,2
    double t1, s1;
    double t2, s2;
    FILE *c3p3;
    c3p3 = fopen("c3p3.txt", "w");
    fprintf(c3p3, "#x \t J0 \t J1 \t J2 \n");

    for (double x = 0.0; x<=30.0; x = x+0.1)
    {
        k = 0;
        t0 =s0 =  1/1; // t0 term is the 1/n!
        t1 =s1 = 1/1;
        t2 =s2 =  1/2;
        do
        {
            t0 = t0 * Jratio(0, k, x);
            s0 = s0 + t0;
            t1 = t1 * Jratio(1, k, x);
            s1 = s1 + t1;
            t2 = t2 * Jratio(2, k, x);
            s2 = s2 + t2;
            printf("%lf \t %lf \t %lf \t %lf \n", x, pow(x/2,0)*s0, pow(x/2,1)*s1, pow(x/2,2)*s2);
            k++;
        } while (fabs(t0/s0)>0.0001 && fabs(t1/s1)>0.0001 && fabs(t2/s2)>0.0001);
        fprintf(c3p3, "%lf \t %lf \t %lf \t %lf \n", x, pow(x/2,0)*s0, pow(x/2,1)*s1, pow(x/2,2)*s2);
        }

    fclose(c3p3);
}
