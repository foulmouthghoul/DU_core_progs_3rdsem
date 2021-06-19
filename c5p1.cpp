//chapter 5 euler & runge kutta method

#include<stdio.h>
#include<math.h>

double f(double x, double y) // defines the main diff eq
{
    //dy/dx = x + y
    return (x + y);
}
/*
    there is two functions below named euler and rk which uses the respective methods
    now euler & rk has been defined by taking values
    we initiate using
     f(x,y) , 
     the independent variable x ,
     initial & final values of x as xi & xf ,
     initial value of y as yi which is fixed here as 1 ,
     step value h ,
    
    inside both of these i ve taken the values needed to converge to the root in files
    the main logic of these programs are pretty standard ones copied from manual
    these functions when called will return the roots in the variable yi

*/


double euler(double f(double x, double t), double x,double xi,double xf, double yi, double h)
{
    FILE *f1;
    f1 = fopen("c5p1e.txt", "w");
    do
    {
        yi = yi + h * f(xi, yi);
        xi = xi + h;
    } while (fabs(x -xi)>0.0001);
    fprintf(f1, "%lf\t%lf\t%lf\n", x, yi, f(xi, yi));
    fclose(f1);
    return yi;
}

double rk4(double f(double x, double y),double x, double xi, double xf, double yi, double h)
{
    FILE *f2;
    f2 = fopen("c5p1r.txt", "w");
    double k1, k2, k3, k4;
    do
    {
        k1 = h * f(xi, yi);
        k2 = h * f(xi + h / 2.0, yi + k1 / 2.0);
        k3 = h * f(xi + h / 2.0, yi + k2 / 2.0);
        k4 = h * f(xi + h, yi + k3);
        yi = yi+(k1 + 2 * (k2 + k3) + k4) / 6.0;
        xi = xi + h;

    } while (fabs(x -xi)>0.0001);
    fprintf(f2, "%lf\t%lf\t%lf\n", x, yi, f(xi, yi));
    fclose(f2);
    return yi;
}
/*
    main function displays and tabulate the values by calling euler and rk function
    here a loop is used to take the values of x from 1 to 5
    but care should be taken to ensure the initial and final values xi,xf & yi are given correctly
    which should be xi = 0.0 , xf = 5.0 & yi = 1.0
    next the step increment h should be chosen 
    so the function calling part should be ,
    as eul(f, x, xi = 0,xf = 1,yi = 1, h = .05)

    this instruction is for problem 1 of chap 5, now for any other swap the function f(x,y)
*/

int main()
{
    double x;
    printf("x\tEuler\tRK4\n");
    FILE *f3;
    f3 = fopen("c5p1.txt", "w");
    fprintf(f3, "#x\tEuler\tRK4\n");
    for (x = 1; x <= 5;x = x + 0.1)
    {
        printf("%.2lf\t%.2lf\t%.2lf\n", x, euler(f, x, 0.0, 1.0, 1.0, 0.05), rk4(f, x, 0.0, 1.0, 1.0, 0.05));
        fprintf(f3, "%.4lf\t%.4lf\t%.4lf\n", x, euler(f, x, 0.0, 1.0, 1.0, 0.05), rk4(f, x, 0.0, 1.0, 1.0, 0.05));
    }
    fclose(f3);
    return 0;
}
