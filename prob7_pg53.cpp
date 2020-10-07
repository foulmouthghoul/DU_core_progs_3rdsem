//Problem 7,pg 53 lab manual

#include <stdio.h>

int fact(int a) //function to calculate factorial
{
	int temp, m = 1;
	temp = a;
	while (temp >1)
	{
		m = m * temp;
		temp--;
	}
	
	return m; //value of factorial
}

int perm(int n, int r) //to calculate permutation
{
	return ( fact(n)/ ( fact(n - r)));
}

int comb(int n, int r) //to calculate combination
{
	return ( fact(n) / ( fact(n -r) * fact(r)));
}

int main()
{
	int a, b;
	printf(" enter the value of n \n");
	scanf("%d", &a);
	printf(" enter the value og r \n");
	scanf("%d", &b);
	
	printf("Value of nCr :%d \n", comb(a, b));
	printf("Value of nPr :%d \n", perm(a, b));
	
	return 0;
}
	