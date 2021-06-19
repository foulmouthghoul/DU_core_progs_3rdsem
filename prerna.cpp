#include <stdio.h>
#include <math.h>

double R(int n, int k, double x)
{
    return ((-(n - 2 * k) * (n - 2 * k - 1)) / ((2 * n - 2 * k - 1) * x*x));
}

int main()
{
    double x,t = 1, s = 0.0, t0 = 479001600 / (pow(2, 6) * 720 * 720);

    FILE *fp;
    fp = fopen("data1.txt", "w");
    fprintf(fp, "#x\t P(x) \n");

    for (x = -1.0; x <= 1.0; x = x + 0.01)
    {
        int k = 1;
        s = 0.0;

        do
        {
            t = t0 * R(6, k, x);
            s = s + t;
            k++;

            printf("%.4lf \t %lf \n", x, s);
        } while (k<=3);

        fprintf(fp, "%.4lf \t %4.4lf \n", x, s);
    }
    fclose(fp);
}