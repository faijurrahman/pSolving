#include <stdio.h>

#define MAX 10000

int height[MAX+1];

int main()
{
int i;
int li, hi, ri;

for(i=0; i<= MAX; i++)
{
height[i] = 0;
}

while (scanf("%d %d %d\n",&li, &hi, &ri)==3){
for(i=li; i < ri; i++)
{
if (height[i] < hi)
height[i] = hi;
}
}

for(i=1; i<= MAX; i++)
{
if (height[i-1] != height[i])
{
printf("%d %d ", i, height[i]);
}
}
return 0;
}
