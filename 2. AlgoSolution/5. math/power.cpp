#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<iostream>
using namespace std;

// Find x raised to the y-th power modulo MOD in log  
long long modPow(long long base, int pow)
{
    long long ans=1;
    while(pow>0) 
	{
        if(pow&1) ans=(ans*base)%MOD;
        base=(base*base)%MOD;
        pow/=2;
    }
    return ans;
}

class stadardMul
{
public:
	long long power(int base, int exp) 
	{ 
		long long result=1; 
		for(int i=0; i<exp; i++) result*=base; 
		return result;
	}
};

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
	stadardMul cal1; 
	divAndConquer cal2;

	int base, n;
	cout<<"Enter Your Number: ";
	cin >> base >> n;

	cout<<"Value1:"<< cal1.power(base,n) <<endl;
	cout<<"Value2:"<< cal2.power(base,n) <<endl;
	cout<<"Value3:"<< cal2.power2(base,n) <<endl;
} 

