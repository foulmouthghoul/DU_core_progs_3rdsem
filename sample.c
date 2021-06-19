// will this run 
// Simulating rolling without slipping on an incline

#include <stdio.h>
#include <math.h>

float accel(float d) //calculation acceleration in CM frame
{
	float a = 0.0;

	/* now we use the formula for a cyclinder rolling without slipping
	here we have a = g*sin(d) / (1 + I/mr^2 )
	now we know I = 1/2 mr^2
	so a = 2/3 g sin(d)
	with value of g = 9.806 m/s^2 & d given by user in degrees
	*/

	a = (2 * 9.806 * fabs(sin(3.141 * d/180.0)))/3;
	return a;
}


float time_cm(float s, float de) // to calculate the time taken by cylinder to go down the incline
{
	float t;

	/* now we calculate the value of time taken by the cylinder
	from the Newtons motion formula we get,
	t = sqrt( 2*S / a);
	*/

	t = sqrt( (2 * s)/ accel(de));
	return t;
}

int main()
{
	float len, deg, rts;
	printf(" enter the value of length of the incline in meters \n");
	scanf("%f", &len);

	FILE *fdat;
	fdat = fopen("datas.txt", "w");
	fprintf(fdat, "# degree \t sin(deg) \t time \t acceleration \t time^2 \t rt(sindeg)\n");
	
	printf("# degree \t sin(deg) \t time \t acceleration \t time^2 \t rt(sindeg)\n");

	for( deg = 2.0; deg <= 15; deg = deg + 1.0)
    {
        rts = sqrt(fabs(sin(3.141 * deg/180.0)));
		printf("%f \t %f \t %f \t %f \t %f \t %f \n", deg,sin(3.141 * deg/180.0), time_cm(len, deg), accel(deg), (time_cm(len, deg) * time_cm(len, deg)), rts);
		fprintf(fdat, "%f \t %f \t %f \t %f \t %f \t %f \n", deg,sin(3.141 * deg/180.0), time_cm(len, deg), accel(deg), (time_cm(len, deg) * time_cm(len, deg)), rts);
	}
	return 0;
}
