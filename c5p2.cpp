//chapter 5 priblem 2
#include<stdio.h>
#include<math.h>

#define pi acos(-1.0)

double y1(double t,double th,double z) //for y' = z
{
    return z;
}

double y2(double t,double th,double z) // y'' = -sin th
{
    return (-sin(th));
}

double rk1(double y1(double t,double th,double z),double t, double ti,double thi, double zi)
{
    //here other than y' initial values of t,theta , z are taken
    double h = 0.01, k1, k2, k3, k4,

    do
    {
        k1=h*y1(ti,thi,zi);
        
        k2=h*y1(ti+h/2.0,thi+k1/2.0,zi+m1/2.0);
        
        k3=h*y1(ti+h/2.0,thi+k2/2.0,zi+m2/2.0);
       
        k4=h*y1(ti+h,thi+k3,zi+m3);
        
        ti = ti + h;
        thi = thi + (k1 + 2 * (k2 + k3) + k4) / 6.0;
        zi = zi + (m1 + 2 * (m2 + m3) + m4) / 6.0;

    } while (fabs(t -ti)>0.0001);
    
}

double rk2(double y2(double t,double th,double z),double t, double ti,double thi, double zi)
{
    double h = 0.01, m1, m2, m3, m4;
    do
    {
        m1=h*y2(ti,thi,zi);
        m2=h*y2(ti+h/2.0,thi+k1/2.0,zi+m1/2.0);
        m3=h*y2(ti+h/2.0,thi+k2/2.0,zi+m2/2.0);
        m4=h*y2(ti+h,thi+k3,zi+m3);
        
    } while (/* condition */);
    

}