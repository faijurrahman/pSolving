#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int n;
    double k;    
    long double p;
    
    while(scanf("%d %Lf", &n, &p) == 2)
    {
        k = pow(10,log10l(p)/n);
    	printf("%.0lf\n",k);
    }
    return 0;
}