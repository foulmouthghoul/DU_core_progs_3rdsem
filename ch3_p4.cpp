//chapter 3 problem 4
#include <stdio.h>
#include <math.h>

#define pi acos(-1.0)

double Fn(int n, double z) //calculating the nth term of series F(z)
{
    long int dn = 1;
    for (long int i = 0; i <= n; i++)
        dn = dn * (4 * i + 1);

    return ((pow(-1, n) * pow(pi, 2 * n) * pow(z, 4 * n + 1)) / dn);
}

int main()
{
    double s;

    FILE *c3p4;
    c3p4 = fopen("c3p4.txt", "w");
    fprintf(c3p4, "#z \t F(z)\n");

    for (double z = 0; z <= 1; z = z + 0.1)
    {
        int n = 0;
        s = 0;
        do
        {
            s = s + Fn(n, z);
            printf("%.4lf \t %.4lf \n", z, cos(pi*z*z*0.5)*s);
            n++;
        } while (fabs(Fn(n, z) / s) > 0.0001);
        fprintf(c3p4, "%.4lf \t %4.4lf \n", z, cos(pi * z * z * 0.5) * s);
    }
    fclose(c3p4);

}