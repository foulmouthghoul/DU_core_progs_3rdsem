// chapter 2 problem 5
#include <stdio.h>
#include <math.h>

float J(int n, float z) //defining Bessels function in spherical form
{
    if (z == 0)
        return 1;
    if (n==0)
        return (sin(z) / z);
    else if (n==1)
        return ((sin(z) / (z*z)) - cos(z) / z);
    else
        return ((2*n-1)*J(n-1,z)/z-J(n-2,z));
}

int main()
{
    FILE *p5;
    p5 = fopen("p5.txt", "w");

    fprintf(p5, "#z \t J0 \t J1 \t J2 \t J3 \t J4 \t J5 \n");

    for (float z = 0.0; z <= 5.0; z =z + 0.01)
    {
        fprintf(p5, "%f \t %f \t %f \t %f \t %f \t %f \t %f \n", z, J(0, z), J(1, z), J(2, z), J(3, z), J(4, z), J(5, z));
        printf("%f \t %f \t %f \t %f \t %f \t %f \t %f \n", z, J(0, z), J(1, z), J(2, z), J(3, z), J(4, z), J(5, z));
    }
}
