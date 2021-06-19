#include<stdio.h>
#include<math.h>

int main()

{long double M,m,K,x,w,P,c,pi;
int N,T;
FILE *fp=NULL;
FILE *fp1=NULL;
FILE *fp2=NULL;
FILE *fp3=NULL;
FILE *fp4=NULL;
FILE *fp5=NULL;
FILE *fp6=NULL;

fp=fopen("t.txt","w");
fp1=fopen("t1.txt","w");
fp2=fopen("t2.txt","w");
fp3=fopen("t3.txt","w");
fp4=fopen("t4.txt","w");
fp5=fopen("t5.txt","w");
fp6=fopen("t6.txt","w");


T=293;
K=1.38*pow(10,-23);
pi=4*atan(1);
N=100;
m=4.3175*pow(10,-26);

for (w=200*pi;w<=2000*pi;w+=300*pi)
{printf("w=%f \n",w);

for (x=0;x<=0.4;x+=0.01)
{M=N*m;
c=M*x*x*w*w/(2*K*T);
P=exp(c);
printf("x=%f, P=%12.5e \n",x,P);

if (w==200*pi)
{fprintf(fp,"%f \t %12.5 \n",x,P); }
else if (w==500*pi)
{fprintf(fp1,"%f \t %12.5 \n",x,P); }
else if (w==800*pi)
{fprintf(fp2,"%f \t %12.5 \n",x,P); }
else if (w==1100*pi)
{fprintf(fp3,"%f \t %12.5 \n",x,P); }
else if (w==1400*pi)
{fprintf(fp4,"%f \t %12.5 \n",x,P); }
else if (w==1700*pi)
{fprintf(fp5,"%f \t %12.5 \n",x,P); }
else if (w==2000*pi)
{fprintf(fp6,"%f \t %12.5 \n",x,P); }



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
