#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<iostream>
using namespace std;
#define MOD 1000000007

/* this function calculates (a*b)%MOD taking into account that a*b might overflow */
long long mulmod(long long a,long long b)
{
    long long ret=0,base=a%MOD;
    while(b>0)
	{
        if(b%2==1) ret=(ret+base)%MOD;
        base=(base*2)%MOD;
        b/=2;
    }
    return ret%MOD;
}

// Find x raised to the y-th power modulo MOD in log  
long long modPow(long long base, int power)
{
    long long ans=1;
    while(power>0) 
	{
        if(power&1) ans=(ans*base)%MOD;
        base=(base*base)%MOD;
        power/=2;
    }
    return ans;
}


long long power(int base, int exp) 
{ 
	long long result=1; 
	for(int i=0; i<exp; i++) result*=base; 
	return result;
}


class divAndConquer
{
	long long square(long long base) 
	{ 
		return base*base; 
	} 

public:
	long long power(long base, int exp) 
	{ 
		if (exp == 0) return 1; 
		else if (exp%2 == 0) return square(power(base,exp/2)); 
		else return( base * (power(base,exp-1)) ); 
	} 

	long long power2(long base, int exp) 
	{ 
		long long temp = 1;
		if (exp == 0) return temp; 
		else if (exp == 1) return base;
		else if (exp == 2) return base*base;
		else if (exp == 3) return base*base*base;

		if (exp%5 == 0)
		{
			temp = power2(base,exp/5);
			return(temp*temp*temp*temp*temp);
		}
		else if (exp%3 == 0)
		{
			temp = power2(base,exp/3);
			return(temp*temp*temp);
		}
		else if (exp%2 == 0)
		{
			temp = power2(base,exp/2);
			return(temp*temp);
		}
		else
		{
			return(base * power2(base,exp-1)); 
		}

		return temp;
	} 
};

int main()
{
	divAndConquer cal2;

	int base, n;
	cout<<"Enter Your Number: ";
	cin >> base >> n;

	cout<<"Value1:"<< power(base,n) <<endl;
	cout<<"Value2:"<< cal2.power(base,n)%MOD <<endl;
	cout<<"Value3:"<< modPow(base,n) <<endl;
} 

