//chapter 2 problem 4
#include <stdio.h>
#include <math.h>

#define pi acos(-1.0)

float theta(float t, float l, float m) //function to define theta function
{
    if (l==3.0 && m==0.0)
        return ((3 * sqrt(14.0) / 4) * (5 * (pow(cos(t), 3)) / 3 - cos(t)));
    if (l==3.0 && fabs(m)==1.0)
        return ((sqrt(42.0) / 8) * sin(t) * (5 * pow(cos(t), 2) - 1));
    if (l==3.0 && fabs(m)==2.0)
        return ((sqrt(105.0) / 4) * pow(sin(t), 2) * cos(t));
    if (l==3.0 && fabs(m)==3.0)
        return ((sqrt(70.0) / 8) * pow(sin(t), 3));
    else
        return 0;
}

int main()
{
    FILE *p4_1;
    p4_1 = fopen("p4_1.txt", "w");
    fprintf(p4_1, "#theta \t THETA(th) \t x \t y \n");

    FILE *p4_2;
    p4_2 = fopen("p4_2.txt", "w");
    fprintf(p4_2, "#theta \t THETA(th) \t x \t y \n");

    FILE *p4_3;
    p4_3 = fopen("p4_3.txt", "w");
    fprintf(p4_3, "#theta \t THETA(th) \t x \t y \n");

    FILE *p4_4;
    p4_4 = fopen("p4_4.txt", "w");
    fprintf(p4_4, "#theta \t THETA(th) \t x \t y \n");

    for (float t = 0; t < 2 * pi; t = t + .001)
    {
        fprintf(p4_1, "%f \t %f \t %f \t %f \n", t, pow(fabs(theta(t, 3.0, 0.0)), 2), ((pow(fabs(theta(t, 3.0, 0.0)), 2)) * cos(t)), ((pow(fabs(theta(t, 3.0, 0.0)), 2)) * sin(t)));
        printf("%f \t %f \t %f \t %f \n", t, pow(fabs(theta(t, 3.0, 0.0)), 2), ((pow(fabs(theta(t, 3.0, 0.0)), 2)) * cos(t)), ((pow(fabs(theta(t, 3.0, 0.0)), 2)) * sin(t)));
        fprintf(p4_2, "%f \t %f \t %f \t %f \n", t, pow(fabs(theta(t, 3.0, 1.0)), 2), ((pow(fabs(theta(t, 3.0, 1.0)), 2)) * cos(t)), ((pow(fabs(theta(t, 3.0, 1.0)), 2)) * sin(t)));
        fprintf(p4_3, "%f \t %f \t %f \t %f \n", t, pow(fabs(theta(t, 3.0, 2.0)), 2), ((pow(fabs(theta(t, 3.0, 2.0)), 2)) * cos(t)), ((pow(fabs(theta(t, 3.0, 2.0)), 2)) * sin(t)));
        fprintf(p4_4, "%f \t %f \t %f \t %f \n", t, pow(fabs(theta(t, 3.0, 3.0)), 2), ((pow(fabs(theta(t, 3.0, 3.0)), 2)) * cos(t)), ((pow(fabs(theta(t, 3.0, 3.0)), 2)) * sin(t)));
    }
}