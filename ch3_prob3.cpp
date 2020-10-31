// chapter 3 problem 3
#include <stdio.h>
#include <math.h>

int fact(int a) //calculating factorial for Ji term
{
    if (a>=1)
        return (a * fact(a - 1));
    else
        return 1;
}

double Jk(int n,int k, double x) //defining the kth of Bessel function series
{
    return ((pow(-1,k)*(pow(x*x/4,k)))/(fact(k)*fact(n +k)));
}

int main()
{
    int k;
    double s0, s1, s2; //three terms for sn where n = 0,1,2

    FILE *c3p3;
    c3p3 = fopen("c3p3n.txt", "w");
    fprintf(c3p3, "#x \t J0 \t J1 \t J2 \n");

    for (double x = 0.0; x<=20.0; x = x+0.1) //loop to generate the range of x values
    {
        k = 0;
        s0 = 0.0;
        s1 = 0.0;
        s2 = 0.0;
        do
        {
            s0 = s0 + Jk(0, k, x);
            s1 = s1 + Jk(1,k,x);
            s2 = s2 + Jk(2,k,x);
            // the term (x/2)^n is directly added to the output
            printf("%lf \t %lf \t %lf \t %lf \n", x, pow(x/2,0)*s0, pow(x/2,1)*s1, pow(x/2,2)*s2); 
            k++; 
            //in the next line the accuracy upto which each sum is calculated is checked
        } while (fabs(Jk(0, k, x)/s0)>0.0001 && fabs(Jk(1, k, x)/s1)>0.0001 && fabs(Jk(2, k, x)/s2)>0.0001);

        fprintf(c3p3, "%lf \t %lf \t %lf \t %lf \n", x, pow(x/2,0)*s0, pow(x/2,1)*s1, pow(x/2,2)*s2);

    }

    fclose(c3p3);
}
