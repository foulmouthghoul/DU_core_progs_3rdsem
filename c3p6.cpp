#include<stdio.h>
#include<math.h>
#define pi atan(1)*4
int main()
{float acc,s,t; double x;
 int k,i;
FILE *fp=NULL; fp=fopen("prb36.txt","w");
  //printf("Enter the value of accuracy desired\n");
  //scanf("%f",&acc);
  acc = 0.0001;
for (x = -10; x <= 0.0; x += 0.05)
{
    s = t = 0.35503;
    k = 1;
    do{
     t*=(pow(x,3))/(3*k*(3*k-1));
     s+=t;
     k++;
        }while(fabs(t/s)>acc);
   fprintf(fp,"%f\t %f\n",x,s);}
   }