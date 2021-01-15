#include<stdio.h>
#include<math.h>
#define f1(t,y,z) ((z))
#define f2(t,y,z) (-(3*z+y+2*y*y*z*z*z+1*sin(3*t)))

main()
{
    float h=0.001,t,y,z,k1,k2,k3,k4,m1,m2,m3,m4,r;
    FILE *fp=NULL;
    fp=fopen("res.txt","w");
    t=0.0;
    y=1.0;
    z=0.0;

    do
    {
        k1=h*f1(t,y,z);
        m1=h*f2(t,y,z);
        k2=h*f1(t+h/2.0,y+k1/2.0,z+m1/2.0);
        m2=h*f2(t+h/2.0,y+k1/2.0,z+m1/2.0);
        k3=h*f1(t+h/2.0,y+k2/2.0,z+m2/2.0);
        m3=h*f2(t+h/2.0,y+k2/2.0,z+m2/2.0);
        k4=h*f1(t+h,y+k3,z+m3);
        m4=h*f2(t+h,y+k3,z+m3);

        y=y+(k1+2.0*(k2+k3)+k4)/6.0;
        z=z+(m1+2.0*(m2+m3)+m4)/6.0;
        t=t+h;

        r=cos(t);
        fprintf(fp,"%f \t %f \t %f\n",t,y,r);
    }
    while(t<=0.03);
}
