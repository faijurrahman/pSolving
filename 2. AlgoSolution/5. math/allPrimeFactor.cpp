//http://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<iostream>
#include <sstream>
using namespace std;

bool isPrime(int n)
{
	if(n<2)return false;
	for(int i=2; i*i<=n; i++)
		if(n%i==0) return false;
	return true;
}

map<int,int> primeFactorList(int n)
{
	map<int,int> pl;
	for(int i=2; i*i<=n; i++)
		while(n%i==0){pl[i]++; n/=i;}
	if(n>1) pl[n]++;
	return pl;
}

// A function to print all prime factors of a given number n
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
       cout<<2<<" ";;
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt((double)n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
           cout<<i<<" ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2) cout<<n<<" ";
}
 
/* Driver program to test above function */
int main()
{
    int n = 315;
    primeFactors(n);
	cout<<endl;
    return 0;
}
    