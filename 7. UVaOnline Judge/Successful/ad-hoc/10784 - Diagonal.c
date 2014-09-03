#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int data = 1;
    unsigned long long Diag;
	double side;
	 

    while(scanf("%lld\n", &Diag) == 1)
    {

		if(Diag!=0)
		{
			side = (3+pow(9+8*Diag, 0.5))/2;
			if((side - (long)side) != 0)
				side++;
			printf("Case %u: %ld\n", data++, (int)side);
		}
		else
		{
			return 0;
		}
            
    }
    return 0;
}