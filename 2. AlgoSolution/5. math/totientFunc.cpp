#include<iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)

class testClass 
{

	public:
	int totient(int n)
	{
		int N=n, fac=0, res=1;
		for(int i=2; i*i<=N; i++,fac=0) if(N%i==0)
		{
			while(N%i==0) N/=i, fac++;
			res*=pow(i,fac-1)*(i-1);
		}
		if(N>1) res*=N-1;
		return n-res;
	}
	


};

int main()
{
    testClass testObj; 
    loop(i,100) cout<<"Totient of "<<i<<" is "<<testObj.totient(i)<<endl; 
} 

    