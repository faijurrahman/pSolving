// http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
//Link for test: http://www.csse.monash.edu.au/~lloyd/tildeAlgDS/Dynamic/Edit/
#include<algorithm>
#include<bitset>
#include<vector>
#include<string>
#include<iostream>
#include <sstream>
#include<cstring>
#include<climits>
#include<set>
using namespace std;


#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define _N 100
int dp[_N][_N];

int editDistance(string s1, string s2)
{
    int X=s1.size(), Y=s2.size();
	ZERO(dp); loop(i,X) dp[i][0]=i; loop(j,Y) dp[0][j]=j;
    loop(i,X) loop(j,Y) dp[i+1][j+1] = min(dp[i][j]+(s1[i]!=s2[j]), min(dp[i+1][j]+1, dp[i][j+1]+1));
    return dp[X][Y];
}
 
// Recursive implementation
int editDistanceRecur(string s1, string s2, int m, int n)
{
    if(m==0 && n==0) return 0;
    if(m==0) return n;
    if(n==0) return m;

    int left = editDistanceRecur(s1,s2,m-1,n)+1;
    int right = editDistanceRecur(s1,s2,m,n-1)+1;
    int corner = editDistanceRecur(s1,s2,m-1,n-1)+(s1[m-1]!=s2[n-1]);
    return min(left, min(right,corner));
}
 
int main()
{
    string s1="dfsadjtestingteasfdtr", s2="dferteotestuhingowe" ;
	cout<<"Input: "<<s1<<" "<<s2<<endl;
    cout<<"Minimum edit distance(dp): "<< editDistance(s1,s2)<<endl;
    cout<<"Minimum edit distance(recur): "<< editDistanceRecur(s1,s2,s1.size(),s2.size())<<endl;
    return 0;
}