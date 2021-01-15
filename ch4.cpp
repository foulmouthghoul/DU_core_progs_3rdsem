//chapter 4 bisection try
//f(x) = sinx - xcosx

#include<stdio.h>
#include<math.h>

double fx(double x) //defining our given function
{
    return (sin(x) - x*cos(x));
}

double bisc(double x1,double x2,int lim,double tol) //function to find out root using bisection
{
    float x ,xm, xl , xr , acc =0.00001 , xinc =0.5 , z , a , b , x1 , x2 ;
int n , i ;
float f( float x ) ;
printf ( "Enter the minimum value o f xnn" ) ;
scanf ( "%f ",&a ) ;
printf ( "Enter the maximum value o f xnn" ) ;
scanf ( "%f ",&b ) ;
for ( x=a ; x<=b ; x=x+0.1){
printf ( "%f n t %f nn" , x , f ( x ) ) ;
}
printf ( " input no o f r o o t s " ) ;
scanf ( "%d",&n ) ;
for ( i =1; i<=n ; i+=1){
printf ( "n ninput x1 , x2" ) ;
scanf ( "%f ,%f ",&x1 ,&x2 ) ;
for ( x=x1 ; x<=x2 ; x+=xinc )
{
if ( f( x )* f( x+xinc )<0)
{ xl=x ; xr=x+xinc ;
do
{ xm=( xl+xr )/2.0 ;
if ( f(xm)* f( xl )>0)
{ xl=xm; }
if ( f(xm)* f( xl )<0)
{ xr=xm; }
z=fabs ( ( xl-xr ) / ( xl+xr) ) ;
printf ( "xm=%f f (xm)=%f z=%f acc=%f nn " ,xm, f (xm) , z , acc ) ;
}
while ( z>acc ) ;
printf ( "n nroot=%f f (xm)=%f z=%f acc=%f nnnn" ,xm, f (xm) , z , acc ) ;
}
}
}
}

int main()
{
    double a, b, l;
    printf("enter the initial guess a: \n");
    scanf("%f", &a);
    printf("enter the initial guess b:\n");
    scanf("%f", &b);
    printf("enter the no. of iterations\n");
    scanf("%f", &l);

    printf("the root of the given equation is %.4f", bisc(a, b, l, 0.0001));

    return 0;
}
