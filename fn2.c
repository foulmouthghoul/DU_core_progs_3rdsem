// final bessel
#include <stdio.h>
#include <math.h>


double fx(double x) //defining our given function
{
    double s = 1.0, t;
    int k = 0, n = 0;
    do
    {
        k = k + 1;
        t = t*(-(pow(x, 2) / (4 * k * (1 + k))));
        s = s + t;
    } while (fabs(t/s)>0.0001);
    return (x * s / 2);
}
int main()
{
    double x,x1,x2,xm;
    int count = 0;

    for (x = 6.0; x <= 12.0;x = x + 0.1)
    {

        if (fx(x) * fx(x+.1) <0)
        {
            x1 = x;
            x2 = x + 0.1;

            do
            {
                xm = (x1 + x2) / 2.0;
                if (fx(x1) * fx(xm) > 0)
                {
                    x1 = xm;
                }
                if (fx(x1) * fx(xm) < 0)
                {
                    x2 = xm;
                }
                count++;
                printf("xm%lf\tf(xm)%lf\n", xm, fx(xm));
            } while (fabs((x1 - x2)/(x1+x2))>0.0001);
            printf("root%lf\tf(xm)=%lfiteration%d\n", xm, fx(xm), count);
            break;
    }

}
return 0;
}
