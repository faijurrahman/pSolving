#include<iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define ZERO(arr) memset(arr,0,sizeof(arr))

#define PRM 100
int prime[PRM];

void sieve(long long n)
{
	ZERO(prime);
	int p=2;
	while(p<n)
	{
		for(int i=p+p; i<n; i+=p) prime[i]=1;
		while(prime[++p]);
	}
}

void printPrime(long long n)
{
	LOOP(i,2,n) if(!prime[i]) cout<<" "<<i;
	cout<<endl;
}

void countPrime(long long n)
{
	int p=0, lastPrime;
	LOOP(i,2,n) 
	{
		if(!prime[i]){lastPrime=i; p++;}
		prime[i]=p;
		cout<<i<<" "<<prime[i]<<" "<<lastPrime<<endl;
	}
}


int main()
{
    sieve(PRM);
    printPrime(PRM);
	countPrime(PRM);
} 

    