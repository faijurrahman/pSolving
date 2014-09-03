#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int gNum, sNum, sNum2;
    double len, width, row;
    double constant = pow(3, .5)/2;
    while(scanf("%lf %lf", &width, &len) == 2)
    {
        //Find number of pipe considering len x width
        row = (int)(1 + (width - 1) / constant );
        sNum = row * (int) len;

        if((len- (int)len)<0.5)
            sNum -= (int) (row /2) ;
          
        //Find number of pipe considering width x len
        row = (int)(1 + (len - 1) / constant );
        sNum2 = row * (int) width;

        if((width - (int)width)<0.5)
            sNum2 -= (int) (row /2) ;
          
        if(sNum2>sNum)
            sNum = sNum2;
        
        gNum = (int) len * (int) width;
        
        if(gNum>=sNum)
            printf("%u grid\n", gNum);
        else
            printf("%u skew\n", sNum);
            
    }
    return 0;
}