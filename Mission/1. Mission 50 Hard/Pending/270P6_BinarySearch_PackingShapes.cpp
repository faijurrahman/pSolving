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

#define ld long double
#define ll long long
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
#define _N 100
int dp[_N][_N];
#define DIFF 1e-9

class binSearch
{
	public:
	int X;
	int width, height;
	int tW, tH;

	binSearch(int w, int h)
	{
		width = w;
		height = h;
	}

	bool bSearchAdv()
	{
		double high=width;
		double low=width/2;
		while((high-low)>DIFF) 
		{
			double mid = low+(high-low)/2;
			if(isOkW(mid)) high=mid;
			else low=mid;
		}
		double minW = low;

		high=width/2;
		low=0;
		while((high-low)>DIFF) 
		{
			double mid = low+(high-low)/2;
			if(isOkH(mid)) high=mid;
			else low=mid;
		}

		double minW2=width-high;
		if(minW<=minW2) return true;
		return false;
	}

	int isOkW(double newW)
	{
		double newH=height*newW/width;
		double tarNewW=sqrt(pow(newW,2)+pow(newH,2));

		if((tW-tarNewW)<DIFF) return true;	
		return false;
	}

	int isOkH(double newW)
	{
		double newH=height*newW/width;
		double tarNewH=sqrt(pow(newW,2)+pow(newH,2));
		if((tH-tarNewH)<DIFF) return true;	
		return false;
	}
};

class PackingShapes 
{

	public:
	vector <string> tryToFit(int width, int height, vector <string> shapes) 
	{
		vector<string> ans;
		int X = shapes.size();
		int minLen=min(width,height)/2;
		int w=max(width,height);
		int h=min(width,height);
		int r;

		width=w; height=h;
		binSearch bs(width,height);
		string type;
		loop(i,X) 
		{
			istringstream ss(shapes[i]);
			ss>>type;
			if(type=="RECTANGLE")
			{
				ss>>w>>h;
				bs.tW=max(w,h);
				bs.tH=min(w,h);
				if(bs.tW<=width && bs.tH<=height) ans.push_back("YES");
				else if(bs.bSearchAdv()) ans.push_back("YES");
				else ans.push_back("NO");

			}
			else
			{
				ss>>r;
				if(r<=minLen) ans.push_back("YES");
				else ans.push_back("NO");
			}
		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 510; int Arg1 = 620; string Arr2[] = {"RECTANGLE 185 622", "RECTANGLE 849 200", "RECTANGLE 850 184", "RECTANGLE 841 185", "RECTANGLE 854 181", "RECTANGLE 855 193", "RECTANGLE 849 197", "RECTANGLE 844 199", "RECTANGLE 198 842", "RECTANGLE 190 853", "RECTANGLE 193 846", "RECTANGLE 183 850", "RECTANGLE 187 856", "RECTANGLE 189 843", "RECTANGLE 197 846", "RECTANGLE 198 852", "RECTANGLE 630 844", "RECTANGLE 628 846", "RECTANGLE 630 860", "RECTANGLE 620 847", "RECTANGLE 638 843", "RECTANGLE 640 855", "RECTANGLE 633 847", "RECTANGLE 627 843", "RECTANGLE 855 631", "RECTANGLE 855 638", "RECTANGLE 845 625", "RECTANGLE 840 636", "RECTANGLE 857 632", "RECTANGLE 856 627", "RECTANGLE 857 633", "RECTANGLE 857 633", "RECTANGLE 198 626", "RECTANGLE 185 622", "RECTANGLE 188 627", "RECTANGLE 190 626", "RECTANGLE 199 625", "RECTANGLE 190 627", "RECTANGLE 189 632", "RECTANGLE 180 638", "RECTANGLE 633 183", "RECTANGLE 628 193", "RECTANGLE 628 198", "RECTANGLE 629 186", "RECTANGLE 631 184", "RECTANGLE 636 184", "RECTANGLE 636 187", "RECTANGLE 634 190", "RECTANGLE 631 193", "RECTANGLE 640 199"}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"YES", "NO", "YES" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, tryToFit(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; string Arr2[] = {"RECTANGLE 100 100",
 "CIRCLE 50"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"YES", "YES" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, tryToFit(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 100; string Arr2[] = {"RECTANGLE 99 9",
 "CIRCLE 22"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"YES", "NO" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, tryToFit(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 170; int Arg1 = 900; string Arr2[] = {"RECTANGLE 200 700",
 "RECTANGLE 3 910",
 "RECTANGLE 1000 7",
 "CIRCLE 5",
 "CIRCLE 50",
 "CIRCLE 500",
 "RECTANGLE 1000 99"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NO", "YES", "NO", "YES", "YES", "NO", "NO" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, tryToFit(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    PackingShapes ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
