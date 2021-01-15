//chapter 4 bisection try
//f(x) = sinx - xcosx

#include<stdio.h>
#include<math.h>

double fx(double x) //defining our given function
{
    return (x*x - 2*x +1);
}

double bisc(double x1,double x2,int lim,double tol) //function to find out root using bisection
{
    double xm;
    int count = 0;
    if(fx(x1)*fx(x2)<=0)
    {
        do
        {
            xm = (x1 + x2) / 2.0;
            if(fx(x1)*fx(xm)>0)
            {
                x1 = xm;
            }
            if(fx(x1)*fx(xm)<0)
            {
                x2 = xm;
            }
            count++;
            } while (fabs(x1 - x2)>=tol && count<=lim);
        return xm;
    }
    else
    {
        
        return 0;
    }
}

int main()
{
    double a, b, l;
    printf("enter the initial guess a: \n");
    scanf("%f", &a);
    printf("enter the initial guess b:\n");
    scanf("%f", &b);
    printf("enter the no. of iterations\n");
    scanf("%f", &l);

    printf("the root of the given equation is %.4f", bisc(a, b, l, 0.0001));

    return 0;
}
