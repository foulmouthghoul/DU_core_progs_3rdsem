//nanophysics tut2 - question 
// plotting fermi function for given values

#include <stdio.h>
#include <math.h>

float fd(float x, float y)                    //function to find the distribution of electrons
{
    return (1 / ((exp(x - 2.5) / 8.617 * y) + 1)); //here x is the energy and y is temperature
}

int main()
{
    FILE *plt1; 
    FILE *plt2;
    FILE *plt3;
    FILE *plt4;
    FILE *plt5;

    plt1 = fopen("plt1.txt", "w"); //for T = 0.1K
    plt2 = fopen("plt2.txt", "w"); //for T = 300K
    plt3 = fopen("plt3.txt", "w"); //for T = 600K
    plt4 = fopen("plt4.txt", "w"); //for T = 1000K
    plt5 = fopen("plt5.txt", "w"); //for T = 2000K

    /*
        Now we use a for loop to take our energy ranges 
        Energy E : 0<E<3000 eV 
        Emin = 0 & Emax = 3000eV which is near room temps ~2580eV
    */

    fprintf(plt1, "#E \t F(E) \t T = 0.1K \n");
    fprintf(plt2, "#E \t F(E) \t T = 300K \n");
    fprintf(plt3, "#E \t F(E) \t T = 600K \n");
    fprintf(plt4, "#E \t F(E) \t T = 1000K \n");
    fprintf(plt5, "#E \t F(E) \t T = 6000K \n");

    for (float E = 0; E <= 3000.0;)
    {
        fprintf(plt1, "%f \t %f \n", E, fd(E, 0.1)); //writing the values in files 
        fprintf(plt2, "%f \t %f \n", E, fd(E, 300));
        fprintf(plt3, "%f \t %f \n", E, fd(E, 600));
        fprintf(plt4, "%f \t %f \n", E, fd(E, 1000));
        fprintf(plt5, "%f \t %f \n", E, fd(E, 6000));
        E = E + 0.1; // defining the step
    }

    fclose(plt1);
    fclose(plt2);
    fclose(plt3);
    fclose(plt4);
    fclose(plt5);

    return 0;
}