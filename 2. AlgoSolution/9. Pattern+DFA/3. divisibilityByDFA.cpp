//http://www.geeksforgeeks.org/dfa-based-division/
#include <string>
#include <iostream>
using namespace std;
 
int calRemainder (string number, int divisor)
{
	int X = number.size();
	int state = 0;//Init State

	for(int i=X-1; i>=0; i--)
	{	
		state <<= 1;
		if(number[i]) state += 1;
		state  %= divisor;
	}

    return state;
}
 
// Driver program to test above functions
int main()
{
    int num = 124576542;
    int k = 654654; 
 
	string binStr;
	while(num)
	{
		binStr.push_back(num&1);
		num>>=1;
	}

    int remainder = calRemainder (binStr, k);
 
    if (remainder == 0)
        cout<<"Divisible"<<endl;
    else
        cout<<"Not Divisible. " << "Remainder is " << remainder <<endl;
 
    return 0;
}