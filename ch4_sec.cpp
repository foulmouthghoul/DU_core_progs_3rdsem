//chapter 4 secant
//super tired trying my best for innovative one

#include<stdio.h>
#include<math.h>

double f(double x)
{
    return (x*x -4*x + 4);
}

int main()
{
    double x1, x2, x3;
    int nroot;

    printf("enter the number of roots \n");
    scanf("%d", &nroot);
    for (int i = 0; i < nroot; i++)
    {
        printf("enter the guesses x1 & x2 \n");
        scanf("%lf %lf", &x1, &x2);

        if (f(x1)==f(x2))
        {
            printf("wrong choice of solution");
            break;
            return 0;
        }
        int count = 1;
        do
        {
            x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
            x1 = x2;
            x2 = x3;
            printf("iteration %d root %lf with f(x) %lf \n", count, x2, f(x2));
            count++;
        } while (fabs(f(x2))>0.0001);
        printf("the root of the equation is %lf \n", x2);
    }
    return 0;
}
