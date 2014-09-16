#include<iostream>
#include<map>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)

class testClass 
{

	public:
	void primeFactor(int n)
	{
		int N=n, fac=0;
		map<int,int> m;
		for(int i=2; i*i<=N; i++,fac=0) if(N%i==0)
		{
			while(N%i==0) N/=i, fac++;
			m[i]=fac;
		}
		if(N>1) m[N]=1;

		cout<<"Prime Factor of "<<n<<" : ";
		for(pair<int,int>t:m) cout<<"["<<t.first<<"]="<<t.second<<" ";cout<<endl;
	}

	map<int,int> primeFactorList(int n)
	{
		map<int,int> pl;
		for(int i=2; i*i<=n; i++)
			while(n%i==0){pl[i]++; n/=i;}
		if(n>1) pl[n]++;
		return pl;
	}
};

int main()
{
    testClass testObj; 
    loop(i,100) testObj.primeFactor(i); 
} 

    