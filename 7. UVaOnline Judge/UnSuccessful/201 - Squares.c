#include <stdio.h>
#include <string.h>

#define DIMEN 10

unsigned char hor[DIMEN][DIMEN], ver[DIMEN][DIMEN], square[DIMEN][DIMEN], output[DIMEN];
unsigned int count = 0, strt, end, dim, line, i,j,k;
char dir;


void find_squre(unsigned int order)
{
    unsigned int horVal,verVal;
    for(i=1;i<=(dim - order);i++)
    {       
      for(j=1;j<=(dim - order);j++)
        {
            horVal = 0;
            verVal = 0;
            
            for(k=0;k<order;k++)
            {
                 horVal += hor[i*order][j*order+k];   
                 verVal += ver[i*order+k][j*order];  

                 horVal += hor[i*order+order][j*order+k];   
                 verVal += ver[i*order+k][j*order+order];   
            }
            if((horVal == 2*order) && (verVal == 2*order))
                     output[order]++;
        }  
    } 
    
}
    
    
int main(void)
{
 
    while(scanf("%u %u", &dim, &line) == 2)
    {
    	count++;
        for(i=0;i<=dim;i++)
        {       
          for(j=0;j<=dim;j++)
            {
                hor[i][j] = 0;
                ver[i][j] = 0;
            }  
            
             output[i] = 0;
        }
    
		i=1;
		while(i++<=line)
		{
			scanf("\n%c %u %u", &dir, &strt, &end);
            if(dir == 'H')
                hor[strt][end] = 1;
            else
                ver[end][strt] = 1;
        }
        
        for(k=1;k<dim;k++)
        {
            find_squre(k);
            output[0] += output[k];
        }
        
        if(count!=1)
                printf("\n**********************************\n\n");
        printf("Problem #%u\n\n",count);
        if(output[0] == 0)
        {
             printf("No completed squares can be found.\n");
        }
        else
        {
            for(k=1;k<dim;k++)
            {
				if(output[k] != 0)
					printf("%u square (s) of size %u\n",output[k],k);
            }
        }

        
    }

    return 0;
}