#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m, n;
  
    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

/* 浣犵殑浠ｇ爜灏嗚宓屽湪杩欓噷 */
#include <math.h>
int narcissistic( int number )
{
	int a,b,c,d,e,f,m,n=0;
	f=m=number;
	if((a=m%10000)>0)n=5;
	m=m/10000;
	if((b=m%1000)>0&&n!=5)n=4;
	m=m/1000;
	if((c=m%100)>0&&n!=4)n=3;
	m=m/100;
	d=m%10;
	m=m/10;
	e=m;
	if(f==pow(a,n)+pow(b,n)+pow(c,n)+pow(d,n)+pow(e,n))return 1;
	else return 0;
}