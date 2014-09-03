//http://www.geeksforgeeks.org/dfa-based-division/
#include <stdio.h>
#include <stdlib.h>
 
int (*dfa)[2];

void initdfa(int k)
{
    int trans0, trans1;
    for (int state=0; state<k; state++)
    {
        // Calculate next state for bit 0
        trans0 = state<<1;
        dfa[state][0] = (trans0 < k)? trans0: trans0-k;
 
        // Calculate next state for bit 1
        trans1 = (state<<1) + 1;
        dfa[state][1] = (trans1 < k)? trans1: trans1-k;
    }
}
 

void isDivisibleUtil(int num, int* state)
{
    if (num != 0)
    {
        isDivisibleUtil(num>>1, state);
        *state = dfa[*state][num&1];
    }
}
 
// The main function that divides ‘num’ by k and returns the remainder
int isDivisible (int num, int k)
{
    dfa = (int (*)[2])malloc(k*sizeof(*dfa));
    initdfa(k);
    int state = 0;
    isDivisibleUtil(num, &state);
	free(dfa);
    return state;
}
 
// Driver program to test above functions
int main()
{
    int num = 47; // Number to be divided
    int k = 5; // Divisor
 
    int remainder = isDivisible (num, k);
 
    if (remainder == 0)
        printf("Divisible\n");
    else
        printf("Not Divisible: Remainder is %d\n", remainder);
 
    return 0;
}