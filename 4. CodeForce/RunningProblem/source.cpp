#include<climits>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include <sstream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))

#define vi vector<int>
#define vii vector<int,int>
#define vl vector<long>
#define vll vector<long,long>
#define vd vector<double>
#define vdd vector<double,double>
#define vs vector<string>
#define vb vector<bool>
#define mp make_pair
#define pb push_back

#define MOD 1000000007
long dp[2000];
// extract divisors of n:
vector<int> getDivisors(int n)
{
    vector<int> div;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i) {
                div.push_back(n / i);
            }
        }
    }
    sort(div.begin(), div.end());
    return div;
}
 
// Find x raised to the y-th power modulo MOD    
long modPow(long x, int y)
{
    long r = 1;
    while (y > 0) {
        if (y & 1) {
            r = (r * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return r;
}
 
int getNumber(int n, int k)
{
    vector<int> d = getDivisors(n);
    long res = 0;
	ZERO(dp);
    // for each divisor of n.
    for (int i = 0; i < d.size(); i++) {
        // find k ^ d[i]:
        long x = modPow(k , d[i]);
        // subtract the totals we found for smaller divisors of n that divide d[i]:
        for (int j = 0; j < i; j++) {
            if (d[i] % d[j] == 0) {
                x = (x - dp[j] + MOD) % MOD;
            }
        }
        dp[i] = x;
        // add the product to the result
        res += (dp[i] * d[i]) % MOD;
    }
    return (int)( res % MOD );
}