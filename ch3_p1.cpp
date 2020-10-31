//chapter 3 problem 1
#include <stdio.h>
#include <math.h>

int main()
{
    float x, sum = 1.0;
    printf("enter the value of x \n");
    scanf("%f", &x);

    for (int i = 2; i <= 20; i++)
        sum = sum + 1 / (pow(x, i));

    printf("sum %f", sum);
}