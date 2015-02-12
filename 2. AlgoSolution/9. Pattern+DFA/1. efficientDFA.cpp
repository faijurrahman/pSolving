//http://www.geeksforgeeks.org/pattern-searching-set-5-efficient-constructtion-of-finite-automata/
//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
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

#define _N 100
#define NO_OF_CHARS 256
int dfa[_N][NO_OF_CHARS];

void computeDFA(string pat) 
{
	int lps=0, Y=pat.size();
    loop(j,NO_OF_CHARS) dfa[0][j]=0; dfa[0][pat[0]]=1;
	LOOP(i,1,Y+1)
	{
        loop(j,NO_OF_CHARS) dfa[i][j]=dfa[lps][j];
        dfa[i][pat[i]]=i+1;
		lps=dfa[lps][pat[i]];
    }
}
 
/* Driver program to test above function */
int main()
{
   string txt = "abababadfdsabbaabafd";
   string pat = "aba";
    computeDFA(pat);

	int stat=0, X=txt.size(), Y=pat.size();
	loop(i,X)
	{
       stat=dfa[stat][txt[i]];
	   if(stat==Y) cout<<"Pattern found at index "<<i-Y+1<<endl;   
    }
    return 0;
}