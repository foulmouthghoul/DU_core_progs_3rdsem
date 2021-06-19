#include<stdio.h>
#include<math.h>
#define MAX (unsigned)!((long double)0)

int main()

{double M,m,K,x,w,c,pi;
int N,T;

//we use long double since it has range ~10^300
long double P;
FILE *fp=NULL;
FILE *fp1=NULL;
FILE *fp2=NULL;
FILE *fp3=NULL;
FILE *fp4=NULL;
FILE *fp5=NULL;
FILE *fp6=NULL;
FILE *fp7=NULL;

fp=fopen("t.txt","w");
fp1=fopen("t1.txt","w");
fp2=fopen("t2.txt","w");
fp3=fopen("t3.txt","w");
fp4=fopen("t4.txt","w");
fp5=fopen("t5.txt","w");
fp6=fopen("t6.txt","w");
fp7=fopen("t7.txt","w");

T=293;
K=1.38*pow(10,-23);
pi=4*atan(1);
N=100;
m=4.3175*pow(10,-26);

/*
    here i make some changes to ease off the load
    i ll save the constant part in the expression in var.
    it will be named const = Nm / 2KT
*/
long double cnst = (N*m)/(2*K*T);
printf("%lf\n",cnst);
/*
    now ur 'w' loop runs from 200pi to 2000pi with step as 300
    so it can be written as 2 to 20pi with step 3
*/

for (w=2*pi;w<=20*pi;w+=3*pi)
{printf("w=%f \n",w);

for (x=0;x<=0.4;x+=0.01)
{//M=N*m;
//c=M*x*x*w*w/(2*K*T);
P=exp(cnst *x*x *w*w);
printf("x=%lf, P=%12.5lf \n",x,P);

/*
    now i'll compare p with inf value and break the loop
*/
/*
if(P<=MAX)
    continue;
else
    break;
*/
//ignore these comment lines

/*
    we avoid using 12.5e notation since it creates problem while plotting wide range of values
*/
/*
if (w==2*pi)
{fprintf(fp,"%lf \t %12.5lf \n",x,P); }
else if (w==5*pi)
{fprintf(fp1,"%lf \t %12.5lf \n",x,P); }
else if (w==8*pi)
{fprintf(fp2,"%lf \t %12.5lf \n",x,P); }
else if (w==11*pi)
{fprintf(fp3,"%lf \t %12.5lf \n",x,P); }
else if (w==14*pi)
{fprintf(fp4,"%lf \t %12.5lf \n",x,P); }
else if (w==17*pi)
{fprintf(fp5,"%lf \t %12.5lf \n",x,P); }
else if (w==20*pi)
{fprintf(fp6,"%lf \t %12.5lf \n",x,P); }
*/


//this is the plot of ln P vs x
fprintf(fp7,"%.2lf \t %4.15lf \n",x,log(P));

}
}
fclose(fp);
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
fclose(fp5);
fclose(fp6);

}
